#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "std_msgs/Float32.h"
// Message Definition
// float32 x
//float32 y
//float32 theta
//float32 linear_velocity
//float32 angular_velocity

ros::Subscriber float_sub;
//ros::Publisher float_pose;

void poseCallback(const turtlesim::Pose::ConstPtr& float_msg)
{
        ROS_INFO("Robot pose (x) : %f, (y): %f , (theta) : %f ", float_msg->x  , float_msg->y, float_msg->theta) ;



 
}
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "pose_sub_node");

  ros::NodeHandle n;


    float_sub = n.subscribe("/turtle1/pose", 100, poseCallback);
    //float_pose=n.advertise<std_msgs::Float32>("int_count", 1000);
   

ros::Rate loop_rate(10);
while (ros::ok())
  {

    

    ros::spinOnce();

    loop_rate.sleep();
   
  }

  return 0;
}
