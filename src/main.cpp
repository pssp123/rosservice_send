//
// Created by pierre on 18-5-10.
//

#include "main.hpp"
int main(int argc,char* argv[]){
	ros::init(argc, argv, "rosservice_send");
	ros::NodeHandle	nh_;
	motor_ctrl_ = nh_.serviceClient<rosservice_send::motor>("/motor_ctrl");
	rosservice_send::motor motor;
	while(ros::ok()){
		motor.request.isOpen = true;
		if(motor_ctrl_.call(motor))
		{
			ROS_INFO("%s",motor.response.reply.c_str());
		}else{
			ROS_INFO("not one received or return false");
		}
	}
	ros::spin();
	return 0;
}
