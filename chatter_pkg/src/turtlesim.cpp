#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "turtlesim");


  ros::NodeHandle n;

  ros::Publisher twist_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);
 

  int count = 0;
  while (ros::ok())
  {
    
    geometry_msgs::Twist msg;
    msg.angular.z=0;
    msg.linear.x=0.5;
     ROS_INFO("Linear Velocity x = %f m/s\n Angular Velocity z = %frad/s", msg.linear.x, msg.angular.z);

    twist_pub.publish(msg); 

    
    ros::spinOnce();

    loop_rate.sleep();
   
  }


  return 0;
}