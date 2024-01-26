#include "ros/ros.h"
#include "std_msgs/Int32.h"





int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "int_pub_node");

  
  ros::NodeHandle n;

  
  ros::Publisher int_pub = n.advertise<std_msgs::Int32>("integer", 1000);

  ros::Rate loop_rate(10);


  int count = 20;
  while (ros::ok()&& count<=100)
  {
    
    std_msgs::Int32 int_msg;
   int_msg.data = count;

    ROS_INFO("%i", int_msg.data);


   int_pub.publish(int_msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}