#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

 ros::Subscriber int_sub;
 ros::Publisher divider_pub ;
std_msgs::Float32 divided_msg;
int input_data=0;
void integerCallback(const std_msgs::Int32::ConstPtr& int_msg)
{
    input_data=int_msg->data;
 // ROS_INFO("recived int number = [%d]", input_data);
  //=//std::cout<<"intege_data "<<int_msg->data<<std::endl;
}
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "divider_node");

  ros::NodeHandle n;

 
    int_sub = n.subscribe("int_count", 1000, integerCallback);
    divider_pub = n.advertise<std_msgs::Float32>("dived_value", 1000);

ros::Rate loop_rate(10);
while (ros::ok())
  {
    divided_msg.data=float(input_data)/2;
    divider_pub.publish(divided_msg);

    ROS_INFO("recived floatnumber = [%f]", divided_msg.data);
    ros::spinOnce();

    loop_rate.sleep();
   
  }

  return 0;
}
