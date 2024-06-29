//
// Created by rockychen on 6/29/24.
//
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "a_new_turtle");
    ros::NodeHandle handle;
    ros::service::waitForService("/spawn");
    ros::ServiceClient new_turtle_cmd = handle.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn new_turtle_service;
    new_turtle_service.request.name = "turtle #2";
    new_turtle_service.request.x = 10;
    new_turtle_service.request.y = 6;
    ROS_INFO("Call service to create a new turtle name is %s,at the x:%.1f,y:%.1f",
             new_turtle_service.request.name.c_str(),
             new_turtle_service.request.x, new_turtle_service.request.y);

    new_turtle_cmd.call(new_turtle_service);

    ROS_INFO("Spwan turtle successfully [name:%s]",
             new_turtle_service.response.name.c_str());

    return 0;
}
