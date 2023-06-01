#include "iostream"
#include "ros/ros.h"
#include "robot_msgs/KeyboardInput.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "robot_keyboard_input_node");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<robot_msgs::KeyboardInput>("/robot_keyboard_input",1);

  char input;
  while (ros::ok()) {
    std::cout << "Enter a command (W, A, S, D, R): \n";
    std::cin >> input;

    // Check if the input is valid before publishing
    if (input == 'W' || input == 'A' || input == 'S' || input == 'D' || input == 'R') {
      robot_msgs::KeyboardInput msg;
      msg.command = input;
      pub.publish(msg);

      // Log the command using rosinfo
      ROS_INFO("Command: %c",input);
    }
    else {
      std::cout << "Invalid command. Please try again.\n";
    }

    // Use ros::spinOnce() only when there are callbacks to process
    ros::spinOnce();
  }

  // Log that the node is exiting using rosinfo
  ROS_INFO("Robot keyboard input node is exiting.");

  return 0;
}