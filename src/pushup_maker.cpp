#include <ros/ros.h>

bool i_am_tired = false;
ros::Timer timer;

void callback(const ros::TimerEvent& event) {
  static int counter = 0;
  counter++;

  if (counter > 10) {
    ROS_INFO_STREAM("I am exhausted");
    timer.stop();
  }
  else {
    ROS_INFO_STREAM("I am so tired:" << counter);
  }
}

 int main(int argc,char** argv) {
  ros::init(argc, argv,"pushup_maker");
  ros::NodeHandle nh;

  timer = nh.createTimer(ros::Duration(1), callback);

  ros::spin();

  return 0;
}
