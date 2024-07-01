//
// Created by rockychen on 6/30/24.
//
#include "ros/ros.h"
#include <actionlib/server/simple_action_server.h>
#include "../../../devel/include/learn_action/DoDishesAction.h"
#include "../../../devel/include/learn_action/DoDishesFeedback.h"
#include "../../../devel/include/learn_action/DoDishesGoal.h"
#include "boost/bind/bind.hpp"


using Server = actionlib::SimpleActionServer<learn_action::DoDishesAction>;

void execute(const learn_action::DoDishesGoalConstPtr &goal, Server *as) {
    ros::Rate loop_rate(1);
    learn_action::DoDishesFeedback feedback;

    ROS_INFO("Dishwasher %d is working.", goal->dishwasher_id);

    for (int i = 0; i < 10; i++) {
        feedback.percent_complete = static_cast<float>(i * 10);
        as->publishFeedback(feedback);
        loop_rate.sleep();
    }

    ROS_INFO("Dishwasher %d finish working.", goal->dishwasher_id);
    as->setSucceeded();
}


int main(int argc, char *argv[]) {
    ros::init(argc, argv, "do_dishes_server");
    ros::NodeHandle handle;

    Server server(handle, "do_dishes", boost::bind(&execute, _1, &server), false);
    server.start();


    ros::spin();

    return 0;
}
