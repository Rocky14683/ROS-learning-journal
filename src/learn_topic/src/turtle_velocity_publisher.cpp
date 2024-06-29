#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_velocity_publisher");
    ros::NodeHandle handle;

    auto turtle_vel_publisher = handle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        geometry_msgs::Twist turtle_vel_msg;
        turtle_vel_msg.linear.x = 0.8;
        turtle_vel_msg.angular.z = 0.6;

        turtle_vel_publisher.publish(turtle_vel_msg);

        ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",
                 turtle_vel_msg.linear.x, turtle_vel_msg.angular.z);

        loop_rate.sleep();
    }
    return 0;
}
