#include <termios.h>
#include <signal.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>

#include <boost/thread/thread.hpp>
#include <ros/ros.h>
#include "robot_msgs/KeyboardInput.h"
#include "robot_msgs/HardwareCommand.h"
#include "keyboard_teleop.hpp"

#define KEYCODE_W 0x77
#define KEYCODE_A 0x61
#define KEYCODE_S 0x73
#define KEYCODE_D 0x64

#define KEYCODE_A_CAP 0x41
#define KEYCODE_D_CAP 0x44
#define KEYCODE_S_CAP 0x53
#define KEYCODE_W_CAP 0x57

KeyboardTeleop::KeyboardTeleop()
{
    pub = nh.advertise<robot_msgs::KeyboardInput>("/robot_keyboard_input",1000);
}

KeyboardTeleop::~KeyboardTeleop() {}

void
KeyboardTeleop::keyboardLoop()
{
    char ch;
    bool dirty = true;

    // get the console in raw mode
    tcgetattr(this->kfd, &this->cooked);
    memcpy(&this->raw, &this->cooked, sizeof(struct termios));
    this->raw.c_lflag &=~ (ICANON | ECHO);
    this->raw.c_cc[VEOL] = 1;
    this->raw.c_cc[VEOF] = 2;
    tcsetattr(this->kfd, TCSANOW, &this->raw);
    
    ROS_INFO("Reading from keyboard");
    ROS_INFO("Use WASD keys to control the robot");
    ROS_INFO("Press Shift to move faster");
    
    struct pollfd ufd;
    ufd.fd = this->kfd;
    ufd.events = POLLIN;
    
    for(;;)
    {
        boost::this_thread::interruption_point();
        
        // get the next event from the keyboard
        int num;
        
        if ((num = poll(&ufd, 1, 250)) < 0)
        {
            perror("poll():");
            return;
        }
        else if(num > 0)
        {
            if(read(this->kfd, &ch, 1) < 0)
            {
                perror("read():");
                return;
            }
        }
        else
        {
            if (dirty == true)
            {
                dirty = false;
                msg.command = "No Input";
            }
            pub.publish(msg);
            continue;
        }
        
        switch(ch)
        {
            case KEYCODE_W:
                msg.command = "W";
                dirty = true;
                break;
            case KEYCODE_S:
                msg.command = "S";
                dirty = true;
                break;
            case KEYCODE_A:
                msg.command = "A";
                dirty = true;
                break;
            case KEYCODE_D:
                msg.command = "D";
                dirty = true;
                break;
                
            case KEYCODE_W_CAP:
                msg.command = "W";
                dirty = true;
                break;
            case KEYCODE_S_CAP:
                msg.command = "S";
                dirty = true;
                break;
            case KEYCODE_A_CAP:
                msg.command = "A";
                dirty = true;
                break;
            case KEYCODE_D_CAP:
                msg.command = "D";
                dirty = true;
                break;
                
            default:
                msg.command = "Invalid Input";
                dirty = true;
        }
        if (msg.command != "Invalid Input") {
            ROS_INFO("Command: %c",ch);
        }
        pub.publish(msg);
        
    }
}

struct termios 
KeyboardTeleop::getCooked()
{
    return this->cooked;
}

void
KeyboardTeleop::setKfd(int &newKfd)
{
    this->kfd = newKfd;
}