#ifndef KEYBOARD_TELEOP_HPP
#define KEYBOARD_TELEOP_HPP

#include "ros/ros.h"
#include <termios.h>
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"

class KeyboardTeleop
{
    private:

        ros::NodeHandle nh;
        ros::Publisher pub;
        robot_msgs::KeyboardInput msg;
        struct termios cooked,raw;
        int kfd;

    public:

        KeyboardTeleop();
        ~KeyboardTeleop();
        void keyboardLoop();
        struct termios getCooked();
        void setKfd(int&);
};

#endif