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
![26 09 2024_13 45 03_REC](https://github.com/user-attachments/assets/dbd850fe-c6b8-42f9-a467-80f560f4cac8)

!remember to unpause the simulation of its paused by default

2. launch turtlebot3_navigation
```bash
roslaunch turtlebot3_navigation turtlebot3_navigation.launch
```
This will start the TurtleBot3 navigation system, and TurtleBot3 will use its LiDAR to map the environment. The map will be visualized in RViz as a 2D map.\

you'll need to set the currrent location of the robot in RVIZ according to its location and orientation in gazebo using the 2D Pose estimate tool.
![26 09 2024_13 47 35_REC](https://github.com/user-attachments/assets/e8051836-ea72-4c4e-ab8a-0635d7c27a70)

3. running send_goal_node
   
After launching the navigation stack, you can now use the node from this package to send goals to TurtleBot3 via the terminal. Instead of using the 2D Nav Goal tool in RViz, enter the position (x, y) and orientation (z)

```bash
rosrun send_goal_node send_goal
```
The node will send the goal to the /move_base_simple/goal topic, and TurtleBot3 will navigate to the specified position and orientation.

![26 09 2024_13 51 11_REC](https://github.com/user-attachments/assets/ba367ad1-cb96-4072-9e87-4daafd8fb594)
for these values entered

![26 09 2024_13 50 55_REC](https://github.com/user-attachments/assets/a7bbb0be-f040-4def-b454-18af6fef27f0)

as you can see the Robot starts to plan a path for itself to reach to the goal sent by the send_goal_node using a TimeStamped Pose message

```bash
Header
    uint32 seq
    time stamp
    String frame_id
Pose
    position
        float64 x
        float64 y
        float64 z
    orientation
        float64 x
        float64 y
        float64 z
        float64 w
```
## Future enhancments
add support for a sequence of waypoints



