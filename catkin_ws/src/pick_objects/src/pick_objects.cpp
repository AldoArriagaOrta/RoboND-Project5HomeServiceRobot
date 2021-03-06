#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define the pick-up position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.3;
  goal.target_pose.pose.position.y = 3.0;
  goal.target_pose.pose.orientation.w = -2.6;

   // Send the pick-up position and orientation for the robot to reach
  ROS_INFO("Sending pick-up position");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base reached the pick-up region");

    // Wait 5 sec to simulate object pick-up
     ROS_INFO("Picking up object");
    ros::Duration(5.0).sleep();

    // Define the drop off position and orientation for the robot to reach
    goal.target_pose.pose.position.x = 10.5;
    goal.target_pose.pose.position.y = 0.015;
    goal.target_pose.pose.orientation.w = 0.65;

    // Send the pick-up position and orientation for the robot to reach
    ROS_INFO("Sending drop-off position");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Hooray, the base reached the drop-off region");
    else
      ROS_INFO("The base failed to reach the drop-off region for some reason");
  }
  else
    ROS_INFO("The base failed to reach the pick-up region for some reason");

  ros::spin();
  
  return 0;
}