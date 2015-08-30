/*
 * PointCloudRetriever.h
 *
 *  Created on: Jul 30, 2014
 *      Author: carrt
 */

#ifndef POINTCLOUDRETRIEVER_H_
#define POINTCLOUDRETRIEVER_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

namespace collab {

/**
 * \brief Captures XYZRGB point clouds from the Kinect
 * \note The coordinate system for the captured point clouds is as follows:
 * x-axis -> right, y-axis -> down, z-axis -> points into scene.
 *                          ________+x
 *                         |\
 *                         | \
 *                         |  \
 *                         |   \
 *                         |    \
 *                         +y    +z
 *
 * Also, a PassThrough filter is applied to the captured point cloud so that the
 * target area is within a specified range which is adjustable
 */
class PointCloudRetriever
{
public:
	PointCloudRetriever();
	~PointCloudRetriever();

	/**
	 * \brief Captures an XYZRGBA point cloud from the Kinect and stores an XYZRGB cloud
	 * \param <ptCloud> - holds the captured PointXYZRGB point cloud
	 */
	void run(pcl::PointCloud<pcl::PointXYZRGB>& ptCloud);


	/// \brief Callback function that is used to read XYZRGB point clouds from the Kinect
	void cloudCallback(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud);

private:
	pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr ptCloudPtr;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr filteredPtCloudPtr;

private:
	void convertPointCloud(const pcl::PointCloud<pcl::PointXYZRGBA>& src, pcl::PointCloud<pcl::PointXYZRGB>& tgt);

};


} /* end of namespace collab */




#endif /* POINTCLOUDRETRIEVER_H_ */
