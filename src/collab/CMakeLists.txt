cmake_minimum_required(VERSION 2.8.3)
project(collab)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  #pcl_ros  
  #pcl  
)

# PCL Package include
find_package(PCL 1.7 REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
# Boost
#find_package(Boost REQUIRED COMPONENTS 
#  system
#  filesystem
#  thread
#  date_time
#  iostreams
#)

# Eigen
#find_package(eigen REQUIRED)

# FLANN
#find_package(flann REQUIRED)

# VTK
#find_package(VTK REQUIRED COMPONENTS
#  vtkCommon
#  vtkHybrid
#  vtkRendering
#  vtkGraphics
#  vtkImaging
#  vtkIO
#  vtkFiltering 
#)

# PCL
#find_package(PCL 1.7 REQUIRED COMPONENTS
#  common 			
#  io 			
#  filters 
#  visualization 
#  search 
#  segmentation 
#  registration
#  surface
#  kdtree
#  sample_consensus
#  features
#  octree
#  keypoints
#  tracking
#  apps
#)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   Intention.msg
   ObjectProperties.msg
   SceneComposition.msg   
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need

catkin_package(
  INCLUDE_DIRS include 
#  LIBRARIES collab
  CATKIN_DEPENDS roscpp std_msgs message_runtime pcl_ros pcl
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)

#include_directories(include
#  ${catkin_INCLUDE_DIRS}
#  ${collab_INCLUDE_DIRS}
#  ${BOOST_INCLUDE}
#  ${EIGEN_INCLUDE}
#  ${OPENNI_INCLUDE}
#  ${VTK_INCLUDE}
#  ${QHULL_INCLUDE}
#  ${PCL_INCLUDE_DIRS}
#)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(collab_node collab_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(collab
#   ${catkin_LIBRARIES}
# )


#---------------#
## Executables ##
#---------------#
MESSAGE( STATUS "PCL_INCLUDE_DIRS: " ${PCL_INCLUDE_DIRS} )
MESSAGE( STATUS "PCL_LIBRARIES: " ${PCL_LIBRARIES} )
MESSAGE( STATUS "COLLAB_INCLUDES: " ${collab_INCLUDE_DIRS} )

include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
include_directories(${collab_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


# Communicator node
add_executable(Communicator src/Communicator.cpp ${collab_INCLUDE_DIRS}/collab/Intention.h)
target_link_libraries(Communicator ${catkin_LIBRARIES})
add_dependencies(Communicator collab_generate_messages_cpp)

# CloudReader node
add_executable(CloudReader src/CloudReader.cpp)
target_link_libraries(CloudReader ${catkin_LIBRARIES} ${PCL_LIBRARIES})

# ActionPerformer node
add_executable(ActionPerformer src/ActionPerformer.cpp)
target_link_libraries(ActionPerformer ${catkin_LIBRARIES})

# IntentionRecognizer Process
#add_executable(collab src/IntentionRecognizer.cpp src/PointCloudRetriever.cpp src/Plane.cpp)
#target_link_libraries(collab ${catkin_LIBRARIES} ${PCL_LIBRARIES})

