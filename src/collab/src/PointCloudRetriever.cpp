/*
 * PointCloudRetriever.cpp
 *
 *  Created on: Jul 30, 2014
 *      Author: carrt
 */
// This header is included because of template errors with make

#include <boost/thread.hpp>
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>

#include "collab/PointCloudRetriever.h"

// collab workspace
namespace collab {

PointCloudRetriever::PointCloudRetriever() : ptCloudPtr(new pcl::PointCloud<pcl::PointXYZRGBA>),
	filteredPtCloudPtr(new pcl::PointCloud<pcl::PointXYZRGBA>) {

}


PointCloudRetriever::~PointCloudRetriever() {

}


void PointCloudRetriever::cloudCallback(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud) {
	ptCloudPtr = cloud;
}


void PointCloudRetriever::convertPointCloud(const pcl::PointCloud<pcl::PointXYZRGBA>& src, pcl::PointCloud<pcl::PointXYZRGB>& tgt) {
	pcl::PointXYZRGB nanPoint;
	nanPoint.x = std::numeric_limits<float>::quiet_NaN();
	nanPoint.y = std::numeric_limits<float>::quiet_NaN();
	nanPoint.z = std::numeric_limits<float>::quiet_NaN();
	tgt.points.resize((int) (src.width * src.height), nanPoint);
	tgt.is_dense = src.is_dense;
	tgt.width = src.width;
	tgt.height = src.height;
	tgt.header = src.header;

	for (size_t i = 0; i < src.points.size(); i++) {
		pcl::PointXYZRGB pt;
		pt.x = src.points[i].x;
		pt.y = src.points[i].y;
		pt.z = src.points[i].z;
		pt.r = src.points[i].r;
		pt.g = src.points[i].g;
		pt.b = src.points[i].b;

		tgt.points.push_back(pt);
	}
}


void PointCloudRetriever::run(pcl::PointCloud<pcl::PointXYZRGB>& ptCloud) {
	using namespace pcl;

	pcl::OpenNIGrabber* grabber = new pcl::OpenNIGrabber();
//	boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f = boost::bind (&PointCloudRetriever::cloudCallback, this, _1);
//
//	grabber->registerCallback (f);
//	grabber->start ();
//
//	// Pause for 30 milliseconds to ensure that a point cloud is captured
//	boost::this_thread::sleep (boost::posix_time::millisec (30));
//
//	grabber->stop ();
//
//	pcl::PassThrough<pcl::PointXYZRGBA> pass;
//	pass.setInputCloud (ptCloudPtr);
//	pass.setFilterFieldName ("z");
//	pass.setFilterLimits (0.5, 3.0);
//	pass.filter (*filteredPtCloudPtr);
//
//	convertPointCloud(*filteredPtCloudPtr, ptCloud);
//
//	// Only for debugging purposes
//#ifdef COLLAB_DEBUG
//	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("Debugging Viewer"));
//	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGBA> rgb(filteredPtCloudPtr);
//	viewer->setBackgroundColor(0, 0, 0);
//	viewer->addPointCloud<pcl::PointXYZRGBA> (filteredPtCloudPtr, rgb, "FilteredCloud");
//	viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "Filtered Cloud");
//	viewer->initCameraParameters();
//	viewer->resetCameraViewpoint("FilteredCloud");
//
//	while (!viewer->wasStopped()) {
//		viewer->spinOnce(100);
//		boost::this_thread::sleep (boost::posix_time::microseconds(10));
//
//	}
//#endif

}


} // end of namespace collab



