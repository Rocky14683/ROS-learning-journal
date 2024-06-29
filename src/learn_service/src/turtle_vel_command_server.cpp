//
// Created by rockychen on 6/29/24.
//

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <std_srvs/Trigger.h>
#include <memory>

int main(int argc, char *argv[]) {
    bool pub_vel = false;
    ros::init(argc, argv, "turtle_vel_command_server");


    ros::NodeHandle handle;

    ros::ServiceServer cmd_service = handle.advertiseService<std_srvs::Trigger::Request, std_srvs::Trigger::Response>(
        "/turtle_vel_command", [&pub_vel](
    std_srvs::Trigger::Request &req,
    std_srvs::Trigger::Response &res) -> bool {
            pub_vel = !pub_vel;
            ROS_INFO("Do you want to publish the vel?: [%s]",
                     pub_vel == true ? "Yes" : "No");
            res.success = true;
            res.message = "The status is changed!";

            return true;
        });

    ros::Publisher publisher = handle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 8);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        ros::spinOnce();

        if (pub_vel) {
            geometry_msgs::Twist msg;
            msg.linear.x = 0.6;
            msg.angular.z = 0.8;
            publisher.publish(msg);
        }

        loop_rate.sleep();
    }
    return 0;
}
