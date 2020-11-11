#include <mainpp.h>
#include <ros.h>
#include <std_msg/Empty.h>

// Node:
ros::NodeHandle nh;

// Publisher:
std_msg::String str_msg;
ros::Publisher chatter("chatter", &std_msg);
chatter hello[] = "Hello world!";

// Setup node:
void setup(void) {
  nh.initNode();
  nh.advertise(chatter);
}

// Loop:
void loop(void) {
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  HAL_DELAY(500);
}
