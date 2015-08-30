# (c) K. Duncan, 2015
# Represents an object in terms of its associated superquadric parameters
# and the object's category identity.

############
# Identity #
############
string objectName


########################
# Geometric Properties #
########################
# The shape dimension for the x-axis
float64 a1

# The shape dimension for the y-axis
float64 a2

# The shape dimension for the z-axis
float64 a3

# The x-axis location of the centroid of this superquadric
float64 px

# The y-axis location of the centroid of this superquadric
float64 py

# The z-axis location of the centroid of this superquadric
float64 pz

# Euler rotation angle along the x-axis
float64 phi

# Euler rotation angle along the y-axis
float64 theta

# Euler rotation angle along the x-axis
float64 psi