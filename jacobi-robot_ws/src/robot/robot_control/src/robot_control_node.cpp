#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"
#include <signal.h> 

// Define a constant value for the motor speed
const float MOTOR_SPEED = 0.1;

// Define a constant value for the duration of the command
const float DURATION = 1.0;

// Define a variable to store the compute period param
int compute_period;

// Define a global variable to indicate if the program should terminate
bool terminate = false;

// Define a signal handler function that sets terminate to true
void sigintHandler(int sig) {
  terminate = true;
}

void callbackFunction(const robot_msgs::KeyboardInput::ConstPtr& msg){
    std::string input = msg->command;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",1);

    robot_msgs::HardwareCommand value;

    // Set the motor speeds based on the input using switch cases
    switch (input[0]) {
      case 'W':
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = MOTOR_SPEED;
        break;
      case 'A':
        value.motor1 = MOTOR_SPEED;
        value.motor2 = MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
        break;
      case 'S':
        value.motor1 = MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
        break;
      case 'D':
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = MOTOR_SPEED;
        value.motor4 = MOTOR_SPEED;
        break;
      case 'R':
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
        break;
      default:
        ROS_WARN("Invalid command. Please try again.");
        return; // Return without publishing
    }

  ros::Time beginTime = ros::Time::now();
  ros::Duration secondsIWantToSendMessageFor = ros::Duration(1);
  ros::Time endTime = beginTime + secondsIWantToSendMessageFor;

    // Publish the motor values and log them using rosinfo
    while(ros::Time::now() < endTime){
      pub.publish(value);
      ROS_INFO("Motor values: %f %f %f %f",value.motor1,value.motor2,value.motor3,value.motor4);
      ros::Duration(0.1).sleep();
    }
    
     // Wait for the duration of the command
    ros::Duration(DURATION).sleep();

    // Stop the motors by setting them to zero
    value.motor1 = 0.0;
    value.motor2 = 0.0;
    value.motor3 = 0.0;
    value.motor4 = 0.0;

    // Publish the stop values and log them using rosinfo
    pub.publish(value);
    ROS_INFO("Motor values: %f %f %f %f",value.motor1,value.motor2,value.motor3,value.motor4);

    // Check if terminate is true and return if so
    if (terminate) {
      return;
    }

}


int main(int argc, char **argv){
    ros::init(argc,argv,"robot_control_node");
    
    // Register the signal handler function for SIGINT
    signal(SIGINT, sigintHandler);

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",1);

    ros::Subscriber sub = nh.subscribe("/robot_keyboard_input",1,callbackFunction);

    // Get the compute period param from the parameter server
    nh.param("compute_period", compute_period, 50); // Use 50 as default value

    // Create a ros::Rate object with the compute period param
    ros::Rate loop_rate(1000 / compute_period); // Convert milliseconds to hertz

    // Log that the node is running using rosinfo
    ROS_INFO("Robot control node is running.");

while (ros::ok()) {
      // Process callbacks
      ros::spinOnce();

      // Sleep for the required time to maintain the desired rate
      loop_rate.sleep();

      // Check if terminate is true and break out of the loop if so
      if (terminate) {
        break;
      }
}

// Stop the motors before exiting by setting them to zero
robot_msgs::HardwareCommand stop_value;

stop_value.motor1 = 0.0;
stop_value.motor2 = 0.0;
stop_value.motor3 = 0.0;
stop_value.motor4 = 0.0;

pub.publish(stop_value);

ROS_INFO("Motor values: %f %f %f %f",stop_value.motor1,stop_value.motor2,stop_value.motor3,stop_value.motor4);

return 0; 
}