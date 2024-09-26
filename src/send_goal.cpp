#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "send_goal_node");
    ros::NodeHandle nh; //creating a node handeler object

    ros::Publisher goal_pub = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 10); //creating a publisher to /move_base_simple/goal and casting it to PoseStamped message

    ros::Duration(1.0).sleep();     //giving time for connection

    geometry_msgs::PoseStamped goal;        //creating a PoseStamped object

    goal.header.frame_id = "map";           //assigning the frame_id of the to be the same as of the map
    goal.header.stamp = ros::Time::now();   //and adjusting the Time stamp to the current time

    //initializing position values
    goal.pose.position.x = 0.0;
    goal.pose.position.y = 0.0;
    goal.pose.position.z = 0.0;

    //initializing Quaternion values
    goal.pose.orientation.x = 0.0;
    goal.pose.orientation.y = 0.0;
    goal.pose.orientation.z = 0.0;
    goal.pose.orientation.w = 1.0;

    while (ros::ok())
    {   
        //getting goal position and robot orientation from the user
        cout << "X: ";
        cin >> goal.pose.position.x;
        cout << "Y: ";
        cin >> goal.pose.position.y;
        cout << "Orinetation around Z: ";
        cin >> goal.pose.orientation.z;

        //publishing the message to move_base node
        ROS_INFO("Sending goal to /move_base_simple/goal...");
        goal_pub.publish(goal);
        ros::spinOnce();
        ros::Duration(1.0).sleep();
    }
    return 0;
}