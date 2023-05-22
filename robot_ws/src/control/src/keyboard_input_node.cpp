#include "iostream"
#include "ros/ros.h"
#include "control/keyboardinput.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "keyboard_input_node");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<control::keyboardinput>("/keyboard_input",1000);

  char input;
  while (ros::ok()) {
    std::cout << "Enter a command (W, A, S, D, R): ";
    std::cin >> input;

    control::keyboardinput msg;
    msg.command = input;
    pub.publish(msg);

    ros::spinOnce();
  }

  return 0;
}


