# ROS-Turtlebot3_Goal_Sender
This repository contains a ROS package with a node that sends goal positions to the move_base_simple/goal topic, enabling TurtleBot3 to autonomously navigate in the Gazebo simulation. The node allows you to specify target positions, and TurtleBot3 moves to those goals using the ROS navigation stack.

TurtleBot3 Goal Sender Package
==============================

Overview
--------

This package provides a ROS node that sends goal positions to the /move\_base\_simple/goal topic, allowing you to control **TurtleBot3** in the **Gazebo** simulation. Instead of manually using the **2D Nav Goal** tool in **RViz**, you can send goals by entering values for the robot's position and orientation directly from the terminal.

Requirements
------------

1.  **ROS** (Noetic recommended)
    
2.  **Gazebo** (installed with TurtleBot3)
    
3.  **TurtleBot3 Simulation**: Install and set up **TurtleBot3** by following the instructions [here](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/#pc-setup).
    
Make sure to set the TURTLEBOT3\_MODEL environment variable according to your TurtleBot3 model (e.g., burger, waffle, or waffle\_pi):

```bash
export TURTLEBOT3_MODEL=burger
```
## usage
1. launch turtlebot3 in gazebo (for Example: turtlebot3_world.launch)

```bash
roslaunch turtlebot3_gaazebo turtlebot3_world.launch
```
2. launch turtlebot3_navigation
```bash
roslaunch turtlebot3_navigation turtlebot3_navigation.launch
```
This will start the TurtleBot3 navigation system, and TurtleBot3 will use its LiDAR to map the environment. The map will be visualized in RViz as a 2D map.\

you'll need to set the currrent location of the robot in RVIZ according to its location and orientation in gazebo using the 2D Pose estimate tool.

3. running send_goal_node
After launching the navigation stack, you can now use the node from this package to send goals to TurtleBot3 via the terminal. Instead of using the 2D Nav Goal tool in RViz, enter the position (x, y) and orientation (z)

```bash
rosrun send_goal_node send_goal
```

The node will send the goal to the /move_base_simple/goal topic, and TurtleBot3 will navigate to the specified position and orientation.
