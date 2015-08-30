/*
 * TableObjectDetector.hpp
 *
 *  Created on: Jul 31, 2014
 *      Author: carrt
 */

#ifndef TABLEOBJECTDETECTOR_HPP_
#define TABLEOBJECTDETECTOR_HPP_

#include "pcl/filters/voxel_grid.h"
#include "pcl/filters/passthrough.h"
#include "pcl/filters/extract_indices.h"
#include "pcl/features/normal_3d.h"
#include "pcl/kdtree/kdtree.h"
#include "pcl/kdtree/kdtree_flann.h"
#include "pcl/sample_consensus/method_types.h"
#include "pcl/sample_consensus/model_types.h"
#include "pcl/segmentation/sac_segmentation.h"
#include "pcl/filters/project_inliers.h"
#include "pcl/surface/convex_hull.h"
#include "pcl/segmentation/extract_polygonal_prism_data.h"
#include "pcl/segmentation/extract_clusters.h"

#include "Plane.h"



namespace collab {

/**
 * \brief Detects clusters lying on a flat table
 * \note This class is adapted from ntk's TableObjectDetector
 * \warning Ensure that the table is large enough to be distinguished from the ground plane
 */
template <class PointType = pcl::PointXYZRGB>
class TableObjectDetector {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    typedef PointType Point;
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;
	typedef typename pcl::search::KdTree<PointType>::Ptr KdTreePtr; // Only if pcl version > 1.2.0
	typedef typename std::vector<PointType, Eigen::aligned_allocator<PointType> > PointVector;

public:
	/// Constructor
	TableObjectDetector ();

	/// Initialize the properties of the TableObjectDetector
	void initialize();

public:
	/// Gets the voxel size used for downsampling
    float voxelSize() const { return downsample_leaf_objects_; }


	/// Sets the voxel size used for object downsampling. Default size is 0.3 cm.
    void setObjectVoxelSize(float s = 0.003f) { downsample_leaf_objects_ = s; }


	/// Sets the voxel size used for background downsampling. Default size is 1.0 cm.
    void setBackgroundVoxelSize(float s = 0.01) { downsample_leaf_ = s; }


	/// Sets the depth limits for processing
    void setDepthLimits(float min_z = 0.2f, float max_z = 1.8f) { min_z_bounds_ = min_z; max_z_bounds_ = max_z; }


	/// Sets the height limits for detected objects.
	void setObjectHeightLimits(float min_h = 0.01f, float max_h = 0.50f) { object_min_height_ = min_h;  object_max_height_ = max_h; }


	/// Sets the threshold for an object's distance from the plane (table)
    void setMaxDistToPlane(float d) { m_max_dist_to_plane = d; }

public:
    /*
	 * \brief Detects the objects located on a flat table.
	 * \return true if at least one object and plane are detected
	 * \param <cloud> - the point cloud that is used for detection
	 */
    bool detect(PointCloudConstPtr cloud);

public:
	/// Gets a constant reference to the plane properties
	const Plane& plane() const { return m_plane; };

	/// Gets a constant reference to the list of objects detected on the table
	const std::vector < PointVector >& objectClusters() const { return m_object_clusters; }

	/// Gets a constant pointer to the table points
	PointCloudConstPtr tableInliers() const { return table_projected_; }

private:
    // PCL objects used for detection
    KdTreePtr normals_tree_;
	KdTreePtr clusters_tree_;
    pcl::PassThrough<Point> pass_;
    pcl::VoxelGrid<Point> grid_;
	pcl::VoxelGrid<Point> grid_objects_;
    pcl::NormalEstimation<Point, pcl::Normal> n3d_;
    pcl::SACSegmentationFromNormals<Point, pcl::Normal> seg_;
    pcl::ProjectInliers<Point> proj_;
    pcl::ConvexHull<Point> hull_;
    pcl::ExtractPolygonalPrismData<Point> prism_;
    pcl::EuclideanClusterExtraction<Point> cluster_;

    double downsample_leaf_;
	double downsample_leaf_objects_;
    int k_;
    double min_z_bounds_;
	double max_z_bounds_;
    double sac_distance_threshold_;
    double normal_distance_weight_;

    // Min / Max height from the table plane object points will be considered from/to
    double object_min_height_, object_max_height_;
    // Object cluster tolerance and minimum cluster size
    double object_cluster_tolerance_, object_cluster_min_size_;
    // Maximal distance between the object and the plane.
    double m_max_dist_to_plane;

    // The raw, input point cloud data
    PointCloudConstPtr cloud_;

    // The filtered and downsampled point cloud data
    PointCloudConstPtr cloud_filtered_, cloud_downsampled_;

    // The resultant estimated point cloud normals for \a cloud_filtered_
    pcl::PointCloud<pcl::Normal>::ConstPtr cloud_normals_;

    // The vector of indices from cloud_filtered_ that represent the planar table component
    pcl::PointIndices::ConstPtr table_inliers_;

    // The model coefficients of the planar table component
    pcl::ModelCoefficients::ConstPtr table_coefficients_;

    // The set of point inliers projected on the planar table component from \a cloud_filtered_
    PointCloudConstPtr table_projected_;

    // The convex hull of \a table_projected_
    PointCloudConstPtr table_hull_;

    // The remaining of the \a cloud_filtered_ which lies inside the \a table_hull_ polygon
    PointCloudConstPtr cloud_objects_, cloud_objects_downsampled_;

	/// Represents the table plane
    Plane m_plane;

	/// The object cluster which are found after detection
    std::vector< PointVector > m_object_clusters;

};



} /* collab */


/*
 * Necessary for template implementations to be found with the declarations
 * by the compiler when creating a template instance.
 */
#include "TableObjectDetector.hpp"




#endif /* TABLEOBJECTDETECTOR_HPP_ */
