#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"

bool dirty = false;

void callbackFunction(const robot_msgs::KeyboardInput::ConstPtr& msg){

    std::string input = msg->command;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<robot_msgs::HardwareCommand>("/control/command/hardware",10);

    robot_msgs::HardwareCommand value;

    // Set the motor speeds based on the input
    if (input == "W"){
        nh.param("/movements/move_forward/motor1", value.motor1, float(0.0));
        nh.param("/movements/move_forward/motor2", value.motor2, float(0.0));
        nh.param("/movements/move_forward/motor3", value.motor3, float(0.0));
        nh.param("/movements/move_forward/motor4", value.motor4, float(0.0));
        dirty = true;
    }
    else if (input == "A"){
        nh.param("/movements/slide_left/motor1", value.motor1, float(0.0));
        nh.param("/movements/slide_left/motor2", value.motor2, float(0.0));
        nh.param("/movements/slide_left/motor3", value.motor3, float(0.0));
        nh.param("/movements/slide_left/motor4", value.motor4, float(0.0));
        dirty = true;
    }
    else if (input == "S"){
        nh.param("/movements/move_backward/motor1", value.motor1, float(0.0));
        nh.param("/movements/move_backward/motor2", value.motor2, float(0.0));
        nh.param("/movements/move_backward/motor3", value.motor3, float(0.0));
        nh.param("/movements/move_backward/motor4", value.motor4, float(0.0));
        dirty = true;
    }
    else if (input == "D"){
        nh.param("/movements/slide_right/motor1", value.motor1, float(0.0));
        nh.param("/movements/slide_right/motor2", value.motor2, float(0.0));
        nh.param("/movements/slide_right/motor3", value.motor3, float(0.0));
        nh.param("/movements/slide_right/motor4", value.motor4, float(0.0));
        dirty = true;
    }
    else if (input == "R"){
        nh.param("/movements/rotate_clockwise/motor1", value.motor1, float(0.0));
        nh.param("/movements/rotate_clockwise/motor2", value.motor2, float(0.0));
        nh.param("/movements/rotate_clockwise/motor3", value.motor3, float(0.0));
        nh.param("/movements/rotate_clockwise/motor4", value.motor4, float(0.0));
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