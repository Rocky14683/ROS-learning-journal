//
// Created by rockychen on 6/30/24.
//
#include "ros/ros.h"
#include "../../../devel/include/learn_action/DoDishesAction.h"
#include "../../../devel/include/learn_action/DoDishesResult.h"
#include "../../../devel/include/learn_action/DoDishesFeedback.h"
#include "../../../devel/include/learn_action/DoDishesGoal.h"
#include "actionlib/client/simple_action_client.h"

using Client = actionlib::SimpleActionClient<learn_action::DoDishesAction>;

void doneCb(const actionlib::SimpleClientGoalState& state,
        const learn_action::DoDishesResultConstPtr& result)
{
    ROS_INFO("Yay! The dishes are now clean");
    ros::shutdown();
}

void activeCb()
{
    ROS_INFO("Goal just went active");
}

void feedbackCb(const learn_action::DoDishesFeedbackConstPtr& feedback)
{
    ROS_INFO("percent_complete : %f ", feedback->percent_complete);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "do_dishes_client");
    Client client("do_dishes", true);

    ROS_INFO("Waiting for action server to start.");
    client.waitForServer();
    ROS_INFO("Action server started, sending goal.");


    learn_action::DoDishesGoal goal;
    goal.dishwasher_id = 1;

    client.sendGoal(goal,  &doneCb, &activeCb, &feedbackCb);

    ros::spin();

    return 0;
}