#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){
    ros::init(argc,argv,"Publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("topic",1000);
    ros::Rate loop_rate(1);

    while (ros::ok){
        std_msgs::String msg;
        msg.data = "W";

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}