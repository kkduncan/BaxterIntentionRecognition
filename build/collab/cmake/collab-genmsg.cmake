# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "collab: 3 messages, 0 services")

set(MSG_I_FLAGS "-Icollab:/home/carrt/ros-hydro/carrt_ws/src/collab/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(collab_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/Intention.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab
)
_generate_msg_cpp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab
)
_generate_msg_cpp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/SceneComposition.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab
)

### Generating Services

### Generating Module File
_generate_module_cpp(collab
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(collab_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(collab_generate_messages collab_generate_messages_cpp)

# target for backward compatibility
add_custom_target(collab_gencpp)
add_dependencies(collab_gencpp collab_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS collab_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/Intention.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab
)
_generate_msg_lisp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab
)
_generate_msg_lisp(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/SceneComposition.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab
)

### Generating Services

### Generating Module File
_generate_module_lisp(collab
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(collab_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(collab_generate_messages collab_generate_messages_lisp)

# target for backward compatibility
add_custom_target(collab_genlisp)
add_dependencies(collab_genlisp collab_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS collab_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/Intention.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab
)
_generate_msg_py(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab
)
_generate_msg_py(collab
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/SceneComposition.msg"
  "${MSG_I_FLAGS}"
  "/home/carrt/ros-hydro/carrt_ws/src/collab/msg/ObjectProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab
)

### Generating Services

### Generating Module File
_generate_module_py(collab
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(collab_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(collab_generate_messages collab_generate_messages_py)

# target for backward compatibility
add_custom_target(collab_genpy)
add_dependencies(collab_genpy collab_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS collab_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/collab
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(collab_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/collab
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(collab_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/collab
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(collab_generate_messages_py std_msgs_generate_messages_py)
