#include "ros/ros.h"
#include <iostream>
#include <sstream>
#include "ros_service/service.h"

using namespace std;

int main (int argc, char** argv) {
  int ind;
  int len;
//while
  ros::init(argc,argv, "client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_service::service>("service");

  ros_service::service srv;

  cout<<"Insert index:";
  cin>>ind;
  cout<<"Insert length:";
  cin>>len;

  srv.request.index = ind;
  srv.request.lenght = len;

  if (client.call(srv)) {
    cout << "Server says [ " << srv.response.sequence << " ]" << endl;
  }
  else {
  ROS_ERROR ("Failed to call service");
    return 1;
  }
  ros::spinOnce();

  return 0;
}

