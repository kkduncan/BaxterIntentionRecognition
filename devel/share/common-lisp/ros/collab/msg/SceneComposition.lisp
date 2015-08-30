; Auto-generated. Do not edit!


(cl:in-package collab-msg)


;//! \htmlinclude SceneComposition.msg.html

(cl:defclass <SceneComposition> (roslisp-msg-protocol:ros-message)
  ((sceneComposition
    :reader sceneComposition
    :initarg :sceneComposition
    :type (cl:vector collab-msg:ObjectProperties)
   :initform (cl:make-array 0 :element-type 'collab-msg:ObjectProperties :initial-element (cl:make-instance 'collab-msg:ObjectProperties))))
)

(cl:defclass SceneComposition (<SceneComposition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SceneComposition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SceneComposition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name collab-msg:<SceneComposition> is deprecated: use collab-msg:SceneComposition instead.")))

(cl:ensure-generic-function 'sceneComposition-val :lambda-list '(m))
(cl:defmethod sceneComposition-val ((m <SceneComposition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader collab-msg:sceneComposition-val is deprecated.  Use collab-msg:sceneComposition instead.")
  (sceneComposition m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SceneComposition>) ostream)
  "Serializes a message object of type '<SceneComposition>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sceneComposition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'sceneComposition))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SceneComposition>) istream)
  "Deserializes a message object of type '<SceneComposition>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'sceneComposition) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'sceneComposition)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'collab-msg:ObjectProperties))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SceneComposition>)))
  "Returns string type for a message object of type '<SceneComposition>"
  "collab/SceneComposition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SceneComposition)))
  "Returns string type for a message object of type 'SceneComposition"
  "collab/SceneComposition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SceneComposition>)))
  "Returns md5sum for a message object of type '<SceneComposition>"
  "fcfa93db164857c0fe4d73defd9c033c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SceneComposition)))
  "Returns md5sum for a message object of type 'SceneComposition"
  "fcfa93db164857c0fe4d73defd9c033c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SceneComposition>)))
  "Returns full string definition for message of type '<SceneComposition>"
  (cl:format cl:nil "collab/ObjectProperties[] sceneComposition~%================================================================================~%MSG: collab/ObjectProperties~%# (c) K. Duncan, 2015~%# Represents an object in terms of its associated superquadric parameters~%# and the object's category identity.~%~%############~%# Identity #~%############~%string objectName~%~%~%########################~%# Geometric Properties #~%########################~%# The shape dimension for the x-axis~%float64 a1~%~%# The shape dimension for the y-axis~%float64 a2~%~%# The shape dimension for the z-axis~%float64 a3~%~%# The x-axis location of the centroid of this superquadric~%float64 px~%~%# The y-axis location of the centroid of this superquadric~%float64 py~%~%# The z-axis location of the centroid of this superquadric~%float64 pz~%~%# Euler rotation angle along the x-axis~%float64 phi~%~%# Euler rotation angle along the y-axis~%float64 theta~%~%# Euler rotation angle along the x-axis~%float64 psi~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SceneComposition)))
  "Returns full string definition for message of type 'SceneComposition"
  (cl:format cl:nil "collab/ObjectProperties[] sceneComposition~%================================================================================~%MSG: collab/ObjectProperties~%# (c) K. Duncan, 2015~%# Represents an object in terms of its associated superquadric parameters~%# and the object's category identity.~%~%############~%# Identity #~%############~%string objectName~%~%~%########################~%# Geometric Properties #~%########################~%# The shape dimension for the x-axis~%float64 a1~%~%# The shape dimension for the y-axis~%float64 a2~%~%# The shape dimension for the z-axis~%float64 a3~%~%# The x-axis location of the centroid of this superquadric~%float64 px~%~%# The y-axis location of the centroid of this superquadric~%float64 py~%~%# The z-axis location of the centroid of this superquadric~%float64 pz~%~%# Euler rotation angle along the x-axis~%float64 phi~%~%# Euler rotation angle along the y-axis~%float64 theta~%~%# Euler rotation angle along the x-axis~%float64 psi~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SceneComposition>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sceneComposition) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SceneComposition>))
  "Converts a ROS message object to a list"
  (cl:list 'SceneComposition
    (cl:cons ':sceneComposition (sceneComposition msg))
))
