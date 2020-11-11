#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>

// Node:
ros::NodeHandle nh;

// Publisher:
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

// Setup node:
void setup(void) {
  nh.initNode();
  nh.advertise(chatter);
}

// Loop:
void loop(void) {
  str_msg.data = "Hello world!";
  chatter.publish(&str_msg);
  nh.spinOnce();
}
