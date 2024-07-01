//
// Created by rockychen on 6/30/24.
//
#include "ros/ros.h"
#include "../../../devel/include/learn_topic/Information.h"

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "company_infomation_publisher");

    ros::NodeHandle handle;

    ros::Publisher publisher = handle.advertise<learn_topic::Information>("/company_info", 10);

    ros::Rate loop_rate(1);

    while (ros::ok()) {
        learn_topic::Information msg;
        msg.company = "amazon robotics";
        msg.year = "2025";
        publisher.publish(msg);

        ROS_INFO("Information: company:%s city:%s ", msg.company.c_str(), msg.year.c_str());

        loop_rate.sleep();
    }

    return 0;
}
