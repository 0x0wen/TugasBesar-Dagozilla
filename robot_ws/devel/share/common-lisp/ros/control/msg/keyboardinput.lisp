; Auto-generated. Do not edit!


(cl:in-package control-msg)


;//! \htmlinclude keyboardinput.msg.html

(cl:defclass <keyboardinput> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:integer
    :initform 0))
)

(cl:defclass keyboardinput (<keyboardinput>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <keyboardinput>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'keyboardinput)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control-msg:<keyboardinput> is deprecated: use control-msg:keyboardinput instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <keyboardinput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control-msg:command-val is deprecated.  Use control-msg:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <keyboardinput>) ostream)
  "Serializes a message object of type '<keyboardinput>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'command)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <keyboardinput>) istream)
  "Deserializes a message object of type '<keyboardinput>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'command)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<keyboardinput>)))
  "Returns string type for a message object of type '<keyboardinput>"
  "control/keyboardinput")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'keyboardinput)))
  "Returns string type for a message object of type 'keyboardinput"
  "control/keyboardinput")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<keyboardinput>)))
  "Returns md5sum for a message object of type '<keyboardinput>"
  "cf31d8a7def4ce3bca7e2b1b06a5b2a6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'keyboardinput)))
  "Returns md5sum for a message object of type 'keyboardinput"
  "cf31d8a7def4ce3bca7e2b1b06a5b2a6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<keyboardinput>)))
  "Returns full string definition for message of type '<keyboardinput>"
  (cl:format cl:nil "char command~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'keyboardinput)))
  "Returns full string definition for message of type 'keyboardinput"
  (cl:format cl:nil "char command~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <keyboardinput>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <keyboardinput>))
  "Converts a ROS message object to a list"
  (cl:list 'keyboardinput
    (cl:cons ':command (command msg))
))
