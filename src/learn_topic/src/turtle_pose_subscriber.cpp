//
// Created by rockychen on 6/29/24.
//

#include "ros/ros.h"
#include "turtlesim/Pose.h"


void turtle_pose_callback(const turtlesim::Pose::ConstPtr& msg) {
    ROS_INFO("Turtle pose: x:%0.3f, y:%0.3f, theta:%.3f", msg->x, msg->y, msg->theta);
}

int main(int argv, char **argc) {
    ros::init(argv, argc, "turtle_pose_subscriber");
    ros::NodeHandle handle;
    ros::Subscriber subscriber = handle.subscribe("/turtle1/pose", 10, turtle_pose_callback);


    ros::spin();
    return 0;
}