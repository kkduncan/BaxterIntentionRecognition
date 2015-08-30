/*
 * Plane.h
 *
 *  Created on: Jul 31, 2014
 *      Author: carrt
 */

#ifndef PLANE_H_
#define PLANE_H_

// Forward declaration
namespace pcl {
	class PointXYZ;

}


namespace collab
{


/**
 * \brief Defines the properties of a plane
 */
class Plane {
	/// Plane parameters
	double a, b, c, d;

public:
	Plane(double a, double b, double c, double d)
		: a(a), b(b), c(c), d(d)
	{}

	/**
	 * \brief Construct a plane from a normal vector and a point.
	 */
	Plane(const pcl::PointXYZ& normal, const pcl::PointXYZ& p);

	/**
	 * \brief Default Constructor
	 */
	Plane() : a(0), b(0), c(0), d(0)
	{}

	/**
	 * \brief Determines whether or not this is a valid plane
	 * \return true if it is valid
	 */
	bool isValid() const;

	/**
	 * \brief Gets the normal vector that defines this plane
	 * \returns the x, y, & z values of the plane's normal
	 */
	pcl::PointXYZ normal() const;

	/**
	 * \brief Sets the parameters of the plane
	 */
	void set (double a_, double b_, double c_, double d_) {
		a = a_;
		b = b_;
		c = c_;
		d = d_;
	}

	/**
	 * \brief Determines whether this plane intersects with the specified line given by the parameters
	 * \param <p1> the first point that defines the line
	 * \param <p2> the second point that defines the line
	 */
	pcl::PointXYZ intersectionWithLine (const pcl::PointXYZ& p1, const pcl::PointXYZ& p2) const;


	/**
	 * \brief Determines a point's distance from the plane
	 * \return Distance from the plane
	 */
	float distanceToPlane(const pcl::PointXYZ& p) const;


};


} // collab



#endif /* PLANE_H_ */
