# RoboND-Project5HomeServiceRobot

The "Home Service Robot" project's purpose is to put into pratice the lessons learned as part of the RoboND Path Planning lessons and as final test for the nanodegree, according to the project [rubric](https://review.udacity.com/#!/rubrics/2396/view)

We simulate the autonomous navigation for pick-up and delivery of an object in Gazebo.

[//]: # (Image References)

[image1]: ./images/Result.gif "Result"

## Prerequisites

The gmapping and turtlebot related packages were included as submodules. After cloning the repository, please run 
```
git submodule update --init --recursive 
```
in order to pull them from their respective remote repositories.

Note: The CMakeList.txt file under the src directory points to the actual ros installation directory. Depending on the installation path it might need to be modified.

Afterwards, open a terminal and navigate to the catkin_ws directory and execute:

```
catkin_make
```
Finally, source the environment:

```
source devel/setup.bash
```

## Brief Description of the Packages Used

The project is launched via the bash script "home_servise.sh", located in the scripts directory. The following packages were used to develop this project:

The "turtlebot_simulator/turtlebot_gazebo" package is used to provide the robot model and launch the simulation world in Gazebo.

The "turtlebot_navigation" package contains the Adaptive Monte Carlo Localization (AMCL) node, used to localize the robot and navigate. It is based on the Dijkstra's, a variant of the Uniform Cost Search algorithm, to plan the robot trajectory from start to goal position. The ROS navigation stack makes possible to avoid any obstacles on the robot's path by re-planning a new trajectory once the obstacles are found.

The "pick_objects" package contains the node responsible for sending the pick-up and drop-off coordinates to the navigation stack.

The "add_markers" package contains the node responsible for simulating the objects to be picked up and delivered. It subscribes to the move_base/result topic to determine when to hide and re-assign the object coordinates.

The gmapping package was used to create the map files used for Monte-Carlo localization that the AMCL node uses to localize itself while navigating. The heart of this package is a laser-based Simultaneous Localization and Mapping ROS node. The node is capable of mapping an unknown environment while at the same time updating its own estimate of where the robot is in the map.

## Results Screenshot

![alt text][image1]

