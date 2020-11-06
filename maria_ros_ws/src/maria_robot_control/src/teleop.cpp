#include <sstream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>

//ROS
#include "ros/ros.h"

// Include here the ".h" files corresponding to the topic types you use.
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <tf/transform_broadcaster.h>

int main (int argc, char** argv) {
  //ROS Initialization
  ros::init(argc, argv, "master");
  ros::NodeHandle nh_glob ;

  double y = 0, dy = 0.01;

  ros::Rate rate(250);
  ros::Time currentTime, prevTime = ros::Time::now() ;

  static tf::TransformBroadcaster br;
  tf::Transform transform;
  tf::Quaternion q;

  double speed      = 2.0 ;
  double radius     = 3.0 ;
  double polarAngle = 0.0 ;

  while (ros::ok()){
    ros::spinOnce();
    currentTime = ros::Time::now() ;
    ros::Duration timeElapsed = currentTime - prevTime ;
    prevTime = currentTime ;
    polarAngle += (speed/radius)*timeElapsed.toSec() ;

    transform.setOrigin( tf::Vector3(radius*cos(polarAngle), radius*sin(polarAngle), 0) );
    q.setRPY(0, 0, 0);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "link_chassis"));
  }

  return 0;
}
