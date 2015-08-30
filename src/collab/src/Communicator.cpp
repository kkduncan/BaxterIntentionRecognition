/*
 * Communicator.cpp
 *
 *  Created on: January 28, 2015
 *      Author: KDuncan
 */
#include <cstdlib>
#include <sstream>
#include <boost/thread.hpp>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "collab/Intention.h"


/// Lock for mutating the query type
static boost::mutex queryTypeMutex;

/// Flag to proceed to perform action and stop processing
static bool performAction = false;

/// User's response to proposed query
static std::string userChoice = "NO";

/// Flag to publish selected intention for the action to be performed
static bool publishIntention = false;

/// Flag to publish a user's response
static bool publishResponse = false;

/// Current intention
static collab::Intention userIntention;



/**
 * \brief Intention callback
 */
void intentionCallback(const collab::IntentionConstPtr& intention) {
	std::string msgToUser = "";

	if (!intention->objectName.empty() && !intention->actionName.empty()) {
		msgToUser = "Do you want to perform " + intention->actionName
				+ " on " + intention->objectName + "?";

		queryTypeMutex.lock();
		{
			userIntention = *intention;
			performAction  = true;
			publishIntention = true;
		}
		queryTypeMutex.unlock();

	} else if (!intention->actionName.empty()) {
		msgToUser = "Do you want to perform " + intention->actionName + " on something?";

		queryTypeMutex.lock();
		{
			publishResponse = true;
		}
		queryTypeMutex.unlock();

	} else if (!intention->objectName.empty()) {
		msgToUser = "Do you want to use " + intention->objectName + "?";

		queryTypeMutex.lock();
		{
			publishResponse = true;
		}
		queryTypeMutex.unlock();


	} else {
		msgToUser = "REDO";

		queryTypeMutex.lock();
		{
			publishResponse = true;
		}
		queryTypeMutex.unlock();

	}

	std::string speechCommand = "espeak --stdout -p 40 -s 120 \"" + msgToUser + "\" | paplay";
	system(speechCommand.c_str());

	int response = -1;

	std::cin >> response;

	queryTypeMutex.lock();
	{
		(response == 1) ? userChoice = "YES" : userChoice = "NO";
	}
	queryTypeMutex.unlock();

}



/**
 * \brief Main entry point
 */
int main (int argc, char *argv[]) {
	ros::init(argc, argv, "Communicator");
	ros::NodeHandle communicator;
	ros::Publisher processLifetimePublisher = communicator.advertise<std_msgs::String>("process_lifetime", 10);
	ros::Publisher userResponsePublisher = communicator.advertise<std_msgs::String>("user_response", 10);
	ros::Publisher actionPublisher = communicator.advertise<collab::Intention>("action", 10);
	ros::Rate sleepRate (0.25);

	ROS_INFO("Communicator >> [ STARTED ]");
	ROS_INFO("Communicator >> Press enter to issue cloud publishing message...");
	std::cin.get();

	std_msgs::String processLifetimeMsg;
	processLifetimeMsg.data = "START";

	ros::spinOnce();
	sleepRate.sleep();

	ROS_INFO("Communicator >> Issuing message to start point cloud publishing");
	processLifetimePublisher.publish(processLifetimeMsg);

	/*
	 * At this point, the Communicator should wait for commands from the
	 * Intention topic and interact with the user to determine their desired
	 * intention.
	 */
	while (communicator.ok() && !performAction) {
		ros::spinOnce();
		sleepRate.sleep();

		if (publishResponse) {
			userResponsePublisher.publish(userIntention);
			publishResponse = false;
		}
		ROS_INFO("Communicator >> [ WAITING ON INTENTION ]...");
	}

	/*
	 * To get to this point, the user had to have selected a desired
	 * intention (object-action pair) and a message must be issued
	 * for the desired action to be performed on the desired object
	 */
	if (performAction && publishIntention) {
		actionPublisher.publish(userIntention);
	}

	ROS_INFO("Communicator >> Press enter to stop execution");
	std::cin.get();

	processLifetimeMsg.data = "STOP";
	processLifetimePublisher.publish(processLifetimeMsg);

	ROS_INFO("Communicator >> Shutting down");

	return 0;
}







