#include "ros/ros.h"
#include "std_msgs/Int32.h"


void integerCallback(const std_msgs::Int32::ConstPtr& int_msg)
{
  ROS_INFO("recived int number = [%d]", int_msg->data);
  //=//std::cout<<"intege_data "<<int_msg->data<<std::endl;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "int_sub_node");

  ros::NodeHandle n;

 
  ros::Subscriber int_sub = n.subscribe("integer", 1000, integerCallback);

  ros::spin();

  return 0;
}