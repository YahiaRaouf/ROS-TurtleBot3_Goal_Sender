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
