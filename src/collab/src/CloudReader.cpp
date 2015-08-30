/*
 * CloudReader.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: KDuncan
 */
#include <sstream>
#include <exception>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "boost/thread.hpp"
#include "pcl_ros/point_cloud.h"
#include "pcl/point_types.h"
#include "pcl/io/ply_io.h"


/// Convenience definitions
typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud;
typedef pcl::PointXYZRGB PointType;


/// Global flag to indicate whether publishing is performed
static bool publishClouds = false;

/// Global flag to indicate whether to continue execution
static bool stopExecution = false;

/// Mutex for accessing publishClouds flag
static boost::mutex publishMutex;


/**
 * \brief Callback function to listen to the processing_lifetime topic
 */
void processingCallback(const std_msgs::String::ConstPtr& msg) {
	if (msg->data == "START") {
		publishMutex.lock();
		publishClouds = true;
		publishMutex.unlock();

		ROS_INFO("CloudReader >> Turned on publishing");

	} else if (msg->data == "STOP") {
		publishMutex.lock();
		publishClouds = false;
		publishMutex.unlock();

		stopExecution = true;
		ROS_INFO("CloudReader >> Stopping publishing");

	}
}


/**
 * \brief Main entry point
 */
int main (int argc, char *argv[]) {
	ros::init(argc, argv, "CloudReader");
	ros::NodeHandle cloudReader;
	ros::Publisher pointCloudPublisher = cloudReader.advertise<PointCloud>("scene_cloud", 1);
	ros::Subscriber commListener = cloudReader.subscribe("process_lifetime", 10, processingCallback);
	ros::Rate sleepRate(0.5);

	ROS_INFO("CloudReader >> [ STARTED ]");

	int count = 0;
	while (ros::ok() && !stopExecution) {
		if (publishClouds) {
			try {
				++count;
				std::string ptCloudName = "/home/carrt/ros-hydro/carrt_ws/HorizonCloud.ply";
				PointCloud::Ptr ptCloud (new PointCloud);
				pcl::PLYReader reader;
				reader.read<PointType>(ptCloudName, *ptCloud);

				std::stringstream ss;
				ss << "CloudReader >> Read a point cloud with dimensions (" << ptCloud->width << ", " << ptCloud->height << ")";
				ROS_INFO("%s", ss.str().c_str());

				pointCloudPublisher.publish(ptCloud);
				std::stringstream msg;
				msg << "CloudReader >> Published point cloud number " << count;
				ROS_INFO("%s", msg.str().c_str());

				// Stop publishing, only allow one cloud to be published at a time
				publishMutex.lock();
				publishClouds = false;
				publishMutex.unlock();

			} catch (std::exception &ex) {
				std::string msg = "CloudReader >> Cannot capture point cloud due to internal error: "
						+ std::string(ex.what());
				ROS_ERROR("%s", msg.c_str());

			} catch (...) {
				std::string msg = "CloudReader >> Cannot capture point cloud due to unknown error";
				ROS_ERROR("%s", msg.c_str());
			}
		}

		ros::spinOnce();
		sleepRate.sleep();
	}

	ROS_INFO("CloudReader >> Shutting down");

	return 0;
}







