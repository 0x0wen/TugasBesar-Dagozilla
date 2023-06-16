#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "string"
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"

bool dirty = false;

void callbackFunction(const robot_msgs::KeyboardInput::ConstPtr& msg){

    std::string input = msg->command;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",10);

    robot_msgs::HardwareCommand value;

    float pwm;
    float DEFAULT = 0.0;

    nh.param("/movements/pwm", pwm, DEFAULT);

    // Set the motor speeds based on the input
    if (input == "W"){
        value.motor1 = -pwm;
        value.motor2 = pwm;
        value.motor3 = -pwm;
        value.motor4 = pwm;
        dirty = true;
    }
    else if (input == "A"){
        value.motor1 = pwm;
        value.motor2 = pwm;
        value.motor3 = -pwm;
        value.motor4 = -pwm;
        dirty = true;
    }
    else if (input == "S"){
        value.motor1 = pwm;
        value.motor2 = -pwm;
        value.motor3 = pwm;
        value.motor4 = -pwm;
        dirty = true;
    }
    else if (input == "D"){
        value.motor1 = -pwm;
        value.motor2 = -pwm;
        value.motor3 = pwm;
        value.motor4 = pwm;
        dirty = true;
    }
    else if (input == "R"){
        value.motor1 = -pwm;
        value.motor2 = -pwm;
        value.motor3 = -pwm;
        value.motor4 = -pwm;
        dirty = true;
    }
    else {
        value.motor1 = 0.0;
        value.motor2 = 0.0;
        value.motor3 = 0.0;
        value.motor4 = 0.0;
    }

    pub.publish(value);

    if (dirty == true) {
        ROS_INFO("Motor values: %f %f %f %f",value.motor1,value.motor2,value.motor3,value.motor4);
        dirty = false;
    }
    else {
        if (input == "Invalid Input") {
            ROS_WARN("Invalid command. Please try again...");
        }
    }
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