#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"
#include "Msgs/keyboardinput.h"
#include "Msgs/HardwareCommand.h"



void callbackFunction(const Msgs::keyboardinput::ConstPtr& msg){
    std::string input = msg->command;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<Msgs::HardwareCommand>("PWM",10);

    Msgs::HardwareCommand value;

    
    if (input == "W"){
        value.motor1 = 0.3;
        value.motor2 = 0.3;
        value.motor3 = 0.3;
        value.motor4 = 0.3;
        pub.publish(value);
        }
    else if (input == "A"){
        value.motor1 = 0.3;
        value.motor2 = 0.3;
        value.motor3 = 0.3;
        value.motor4 = 0.3;
        pub.publish(value);
        }
    else if (input == "S"){
        value.motor1 = 0.3;
        value.motor2 = 0.3;
        value.motor3 = 0.3;
        value.motor4 = 0.3;
        pub.publish(value);
        }
    else if (input == "D"){
        value.motor1 = 0.3;
        value.motor2 = 0.3;
        value.motor3 = 0.3;
        value.motor4 = 0.3;
        pub.publish(value);
        }
    else if (input == "R"){
        value.motor1 = 0.3;
        value.motor2 = 0.3;
        value.motor3 = 0.3;
        value.motor4 = 0.3;
        pub.publish(value);
        }
    

}


int main(int argc, char **argv){
    ros::init(argc,argv,"control_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<Msgs::HardwareCommand>("PWM",10);


    ros::Subscriber sub = nh.subscribe("/keyboard_input",1000,callbackFunction);



    ros::spin();

    return 0;
}
