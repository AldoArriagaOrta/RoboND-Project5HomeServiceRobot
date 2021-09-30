#!/bin/sh

path_catkin_ws=$(dirname $(dirname $(dirname $(realpath $0 ))))

echo $path_catkin_ws

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find map)/myworld.world " &
sleep 5

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find map)/map.yaml initial_pose_a:=-1.57079632679" &
sleep 5

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5



