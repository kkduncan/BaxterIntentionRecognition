/*
 * IntentionRecognizer.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: Kester Duncan
 */

#include <pcl/point_types.h>
#include "ros/ros.h"

#include "collab/PointCloudRetriever.h"
#include "collab/TableObjectModeler.h"


int main (int argc, char *argv[]) {
	ros::init(argc, argv, "IntentionRecognizer");
//	ros::NodeHandle recognizerHandle;
//	ros::Publisher speechPublisher = recognizerHandle.advertise<collab::Query>("CollabSpeechProcess", 2);
//	ros::Publisher actionPublisher = recognizerHandle.advertise<collab::ObjectActionInfo>("CollabActionProcess", 2);
//	ros::Rate loopRate(1);

//	int limit = 5;
//	int count = 0;
//	while (count < limit) {
//		collab::Query query;
//		collab::ObjectActionInfo objActionInfo;
//
//		if ((count + 1) == limit) {
//			query.query = "STOP";
//
//		} else {
//			query.query = "Do you want to do something?";
//
//		}
//
//		ROS_INFO("%s", query.query.c_str());
//		//ROS_INFO("%s", objActionInfo);
//
//		speechPublisher.publish(query);
//
//		ros::spinOnce();
//		loopRate.sleep();
//
//		++count;
//	}

	/// Capture the point cloud
	collab::PointCloudRetriever cap;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudPtr (new pcl::PointCloud<pcl::PointXYZRGB>);
	cap.run(*cloudPtr);


	/// Segment the point cloud to determine candidate objects
	collab::ObjectModelGenerator<pcl::PointXYZRGB> generator(cloudPtr);
	bool foundObjects = generator.generateObjectModels();

	if (foundObjects) {

	} else {
		ROS_ERROR("No objects found!");
	}

	return 0;
}
