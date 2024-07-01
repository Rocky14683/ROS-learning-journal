//
// Created by rockychen on 7/1/24.
//
#include "ros/ros.h"
#include <iostream>
#include "../../../devel/include/learn_service/IntPlus.h"
#include "../../../devel/include/learn_service/IntPlusResponse.h"


bool callback(learn_service::IntPlus::Request &req,learn_service::IntPlus::Response &res) {
    int sum = req.a + req.b;
    ROS_INFO("number 1 is:%d ,number 2 is:%d ", req.a, req.b);
    res.result = sum;
    return true;
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "IntPlus_server");
    ros::NodeHandle handle;

    auto server = handle.advertiseService("/Two_IntPlus", callback);
    ROS_INFO("Ready to caculate.");
    ros::spin();

    return 0;
}
