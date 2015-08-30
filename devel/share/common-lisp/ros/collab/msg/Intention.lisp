; Auto-generated. Do not edit!


(cl:in-package collab-msg)


;//! \htmlinclude Intention.msg.html

(cl:defclass <Intention> (roslisp-msg-protocol:ros-message)
  ((objectName
    :reader objectName
    :initarg :objectName
    :type cl:string
    :initform "")
   (actionName
    :reader actionName
    :initarg :actionName
    :type cl:string
    :initform "")
   (objectProperties
    :reader objectProperties
    :initarg :objectProperties
    :type collab-msg:ObjectProperties
    :initform (cl:make-instance 'collab-msg:ObjectProperties)))
)

(cl:defclass Intention (<Intention>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Intention>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Intention)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name collab-msg:<Intention> is deprecated: use collab-msg:Intention instead.")))

(cl:ensure-generic-function 'objectName-val :lambda-list '(m))
(cl:defmethod objectName-val ((m <Intention>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader collab-msg:objectName-val is deprecated.  Use collab-msg:objectName instead.")
  (objectName m))

(cl:ensure-generic-function 'actionName-val :lambda-list '(m))
(cl:defmethod actionName-val ((m <Intention>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader collab-msg:actionName-val is deprecated.  Use collab-msg:actionName instead.")
  (actionName m))

(cl:ensure-generic-function 'objectProperties-val :lambda-list '(m))
(cl:defmethod objectProperties-val ((m <Intention>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader collab-msg:objectProperties-val is deprecated.  Use collab-msg:objectProperties instead.")
  (objectProperties m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Intention>) ostream)
  "Serializes a message object of type '<Intention>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'objectName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'objectName))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'actionName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'actionName))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'objectProperties) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Intention>) istream)
  "Deserializes a message object of type '<Intention>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'objectName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'objectName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'actionName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'actionName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'objectProperties) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Intention>)))
  "Returns string type for a message object of type '<Intention>"
  "collab/Intention")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Intention)))
  "Returns string type for a message object of type 'Intention"
  "collab/Intention")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Intention>)))
  "Returns md5sum for a message object of type '<Intention>"
  "8b7253dcc2556d1a8f3e26a7e2fc6350")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Intention)))
  "Returns md5sum for a message object of type 'Intention"
  "8b7253dcc2556d1a8f3e26a7e2fc6350")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Intention>)))
  "Returns full string definition for message of type '<Intention>"
  (cl:format cl:nil "######################~%# Object-Action Pair #~%######################~%string objectName~%string actionName~%~%#####################~%# Object Properties #~%#####################~%ObjectProperties objectProperties~%~%================================================================================~%MSG: collab/ObjectProperties~%# (c) K. Duncan, 2015~%# Represents an object in terms of its associated superquadric parameters~%# and the object's category identity.~%~%############~%# Identity #~%############~%string objectName~%~%~%########################~%# Geometric Properties #~%########################~%# The shape dimension for the x-axis~%float64 a1~%~%# The shape dimension for the y-axis~%float64 a2~%~%# The shape dimension for the z-axis~%float64 a3~%~%# The x-axis location of the centroid of this superquadric~%float64 px~%~%# The y-axis location of the centroid of this superquadric~%float64 py~%~%# The z-axis location of the centroid of this superquadric~%float64 pz~%~%# Euler rotation angle along the x-axis~%float64 phi~%~%# Euler rotation angle along the y-axis~%float64 theta~%~%# Euler rotation angle along the x-axis~%float64 psi~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Intention)))
  "Returns full string definition for message of type 'Intention"
  (cl:format cl:nil "######################~%# Object-Action Pair #~%######################~%string objectName~%string actionName~%~%#####################~%# Object Properties #~%#####################~%ObjectProperties objectProperties~%~%================================================================================~%MSG: collab/ObjectProperties~%# (c) K. Duncan, 2015~%# Represents an object in terms of its associated superquadric parameters~%# and the object's category identity.~%~%############~%# Identity #~%############~%string objectName~%~%~%########################~%# Geometric Properties #~%########################~%# The shape dimension for the x-axis~%float64 a1~%~%# The shape dimension for the y-axis~%float64 a2~%~%# The shape dimension for the z-axis~%float64 a3~%~%# The x-axis location of the centroid of this superquadric~%float64 px~%~%# The y-axis location of the centroid of this superquadric~%float64 py~%~%# The z-axis location of the centroid of this superquadric~%float64 pz~%~%# Euler rotation angle along the x-axis~%float64 phi~%~%# Euler rotation angle along the y-axis~%float64 theta~%~%# Euler rotation angle along the x-axis~%float64 psi~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Intention>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'objectName))
     4 (cl:length (cl:slot-value msg 'actionName))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'objectProperties))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Intention>))
  "Converts a ROS message object to a list"
  (cl:list 'Intention
    (cl:cons ':objectName (objectName msg))
    (cl:cons ':actionName (actionName msg))
    (cl:cons ':objectProperties (objectProperties msg))
))
