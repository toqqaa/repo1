#include "ros/ros.h"
#include "std_msgs/Int32.h"


#include <sstream>



int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "int_node");

  
  ros::NodeHandle n;

  
  ros::Publisher int_pub = n.advertise<std_msgs::Int32>("int_count", 1000);

  ros::Rate loop_rate(10);


  int count = 0;
  while (ros::ok())
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
