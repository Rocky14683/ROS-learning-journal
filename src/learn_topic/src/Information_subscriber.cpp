//
// Created by rockychen on 6/30/24.
//

#include "../../../devel/include/learn_topic/Information.h"
#include "ros/ros.h"

void callback(const learn_topic::InformationConstPtr& msg) {
    ROS_INFO("Get in %s in %s", msg->company.c_str(), msg->year.c_str());
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "Information_subscriber");

    ros::NodeHandle handle;
    ros::Subscriber subscriber = handle.subscribe<learn_topic::Information>("/company_info", 10, callback);

    ros::spin();

    return 0;
}
