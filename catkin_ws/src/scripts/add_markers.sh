#!/bin/sh

pip install rospkg

path_catkin_ws=$(dirname $(dirname $(dirname $(realpath $0 ))))

echo $path_catkin_ws

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find map)/myworld.world " &

sleep 5


xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find map)/map.yaml" &
sleep 5

rosparam set /move_base/global_costmap/inflation_layer/inflation_radius 0.5 
rosparam set /move_base/local_costmap/inflation_layer/inflation_radius 0.5

sleep 5

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

xterm  -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers " &
sleep 5