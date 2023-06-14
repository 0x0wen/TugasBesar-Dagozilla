#include "iostream"
#include <termios.h>
#include <boost/thread/thread.hpp>
#include "ros/ros.h"
#include "robot_msgs/KeyboardInput.h"
#include "../include/libs/keyboard_teleop.hpp"

int main(int argc, char** argv)
{
    int kfd = 0;
    ros::init(argc, argv, "new_robot_keyboard_input_node", ros::init_options::AnonymousName);
    KeyboardTeleop tbk;
    tbk.setKfd(kfd);
    struct termios cooked = tbk.getCooked();

    boost::thread t = boost::thread(boost::bind(&KeyboardTeleop::keyboardLoop, &tbk));
    
    ros::spin();
    
    t.interrupt();
    t.join();
    tcsetattr(kfd, TCSANOW, &cooked);
    
    return 0;
}