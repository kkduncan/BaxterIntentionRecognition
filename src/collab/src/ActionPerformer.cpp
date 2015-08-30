/*
 * ActionPerformer.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: KDuncan
 */
#include <cstdlib>
#include <sstream>
#include <boost/thread.hpp>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "collab/Intention.h"


/// Flag to stop execution
static bool performActions = true;

/// Mutex for accessing performActions flag
static boost::mutex performActionsMutex;


/**
 * \brief Callback function to listen to the processing_lifetime topic
 */
void processingCallback(const std_msgs::String::ConstPtr& msg) {
	if (msg->data == "STOP") {
		performActionsMutex.lock();
		performActions = false;
		performActionsMutex.unlock();
	}
}


/**
 * \brief Callback function to get the user's desired intention from the action topic
 */
void actionCallback(const collab::Intention::ConstPtr& desiredIntention) {
	/*
	 * Baxter should perform the specified actions on an object given by desiredIntention->objectProperties.
	 * The properties are as follows (can be found in the ROS message ObjectProperties):
	 *
	 * (1) desiredIntention->objectProperties.a1, desiredIntention->objectProperties.a2, desiredIntention->objectProperties.a3;
	 *     The shape dimension for the x, y, and z axies (the distance from the centroid to the object's boundary)
	 *     Therefore, the length of an object would be 2 * a1;
	 *
	 * (2) desiredIntention->objectProperties.px, desiredIntention->objectProperties.py, desiredIntention->objectProperties.pz;
	 * 	   The centroid location of the object in xyz coordinates.
	 *
	 * (3) desiredIntention->objectProperties.phi, desiredIntention->objectProperties.theta, desiredIntention->objectProperties.psi;
	 *     The Euler rotation angles along the x, y, and z axes respectively.
	 *
	 */
	if (desiredIntention->actionName == "PickUp") {
		ROS_INFO("ActionPerformer >> Performing the PickUp action on %s", desiredIntention->objectName.c_str());

		// TODO: Insert code to perform pickup action here
		// Perform the pickup action e.g BaxterActionPerformer::pickup(desiredIntention)

	} else if (desiredIntention->actionName == "Pour") {
		ROS_INFO("ActionPerformer >> Performing the Pour action on %s", desiredIntention->objectName.c_str());

		// TODO: Insert code to perform pouring action here
		// Perform the pour action e.g BaxterActionPerformer::pour(desiredIntention)

	} else {
		// Do nothing or just pick up the object

	}
}


/**
 * \brief Main entry point
 */
int main (int argc, char *argv[]) {
	ros::init(argc, argv, "ActionPerformer");
	ros::NodeHandle actionPerformer;
	ros::Subscriber actionListener = actionPerformer.subscribe("action", 10, actionCallback);
	ros::Subscriber processLifetimeListener = actionPerformer.subscribe("process_lifetime", 10, processingCallback);
	ros::Rate sleepRate(0.25);

	ROS_INFO("ActionPerformer >> [ STARTED ]");

	while (actionPerformer.ok() && performActions) {
		ROS_INFO("ActionPerformer >> [ WAITING TO PERFORM AN ACTION ]");

		ros::spinOnce();
		sleepRate.sleep();
	}

	ROS_INFO("ActionPerformer >> [ STOPPING ]");

	return 0;
}

