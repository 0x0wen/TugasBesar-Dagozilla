#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"

// Define a constant value for the motor speed
const float MOTOR_SPEED = 0.1;

// Define a constant value for the duration of the command
const float DURATION = 1.0;

void callbackFunction(const robot_msgs::KeyboardInput::ConstPtr& msg){
    std::string input = msg->command;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",10);

    robot_msgs::HardwareCommand value;

    // Set the motor speeds based on the input
    if (input == "W"){
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = MOTOR_SPEED;
    }
    else if (input == "A"){
        value.motor1 = MOTOR_SPEED;
        value.motor2 = MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
    }
    else if (input == "S"){
        value.motor1 = MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
    }
    else if (input == "D"){
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = MOTOR_SPEED;
        value.motor4 = MOTOR_SPEED;
    }
    else if (input == "R"){
        value.motor1 = -MOTOR_SPEED;
        value.motor2 = -MOTOR_SPEED;
        value.motor3 = -MOTOR_SPEED;
        value.motor4 = -MOTOR_SPEED;
    }
    else {
        ROS_WARN("Invalid command. Please try again.");
        return; // Return without publishing
    }

    // Publish the motor values
    pub.publish(value);

    // Log the motor values using rosinfo
    ROS_INFO("Motor values: %f %f %f %f",value.motor1,value.motor2,value.motor3,value.motor4);

    // Wait for the duration of the command
    ros::Duration(DURATION).sleep();

    // Stop the motors
    value.motor1 = 0.0;
    value.motor2 = 0.0;
    value.motor3 = 0.0;
    value.motor4 = 0.0;

    // Publish the stop values
    pub.publish(value);

    // Log the stop values using rosinfo
    ROS_INFO("Motor values: %f %f %f %f",value.motor1,value.motor2,value.motor3,value.motor4);
}


int main(int argc, char **argv){
    ros::init(argc,argv,"robot_control_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",10);

    ros::Subscriber sub = nh.subscribe("/robot_keyboard_input",1000,callbackFunction);

    // Log that the node is running using rosinfo
    ROS_INFO("Robot control node is running.");

    ros::spin();

    return 0;
}