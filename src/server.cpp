#include "ros/ros.h"
#include "ros_service/service.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool service_callback (ros_service::service::Request &req, ros_service::service::Response &res) {
  int ind = req.index;
  int len = req.lenght;
	int next=1;
  int t1=0;
  int t2=1;

for (int i=2; i<(ind+len); i++) {
      	next = t1+t2;
      if (i>=ind){
        char f[10];
        sprintf(f,"f[%d]=%d ", i ,next);
        res.sequence += f;
      }
      t1=t2;
      t2=next;
}
  
  
ROS_INFO("From Client [%d] and [%d] received.\nServer replied with: [%s]", req.index, req.lenght, res.sequence.c_str());
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("service",service_callback);
  ROS_INFO("Ready to receive from Client.");
  ros::spin();
  return 0;
}


