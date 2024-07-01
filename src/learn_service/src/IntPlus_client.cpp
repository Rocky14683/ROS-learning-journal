//
// Created by rockychen on 7/1/24.
//
#include "ros/ros.h"
#include <iostream>
#include "../../../devel/include/learn_service/IntPlus.h"
#include "../../../devel/include/learn_service/IntPlusRequest.h"

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "IntPlus_client");
    int i, k;
    std::cin >> i;
    std::cin >> k;
    ros::NodeHandle handle;

    ros::service::waitForService("/Two_IntPlus");

    ros::ServiceClient client = handle.serviceClient<learn_service::IntPlus>("/Two_IntPlus");

    learn_service::IntPlus service;
    service.request.a = i;
    service.request.b = k;


    ROS_INFO("Call service to plus %d and %d", service.request.a, service.request.b);
    client.call(service); //request

    ROS_INFO("Show the result : %d", service.response.result);
    return 0;
}