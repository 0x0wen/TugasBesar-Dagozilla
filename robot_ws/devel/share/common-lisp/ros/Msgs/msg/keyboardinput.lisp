; Auto-generated. Do not edit!


(cl:in-package Msgs-msg)


;//! \htmlinclude keyboardinput.msg.html

(cl:defclass <keyboardinput> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass keyboardinput (<keyboardinput>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <keyboardinput>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'keyboardinput)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Msgs-msg:<keyboardinput> is deprecated: use Msgs-msg:keyboardinput instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <keyboardinput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msgs-msg:command-val is deprecated.  Use Msgs-msg:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <keyboardinput>) ostream)
  "Serializes a message object of type '<keyboardinput>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <keyboardinput>) istream)
  "Deserializes a message object of type '<keyboardinput>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<keyboardinput>)))
  "Returns string type for a message object of type '<keyboardinput>"
  "Msgs/keyboardinput")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'keyboardinput)))
  "Returns string type for a message object of type 'keyboardinput"
  "Msgs/keyboardinput")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<keyboardinput>)))
  "Returns md5sum for a message object of type '<keyboardinput>"
  "cba5e21e920a3a2b7b375cb65b64cdea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'keyboardinput)))
  "Returns md5sum for a message object of type 'keyboardinput"
  "cba5e21e920a3a2b7b375cb65b64cdea")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<keyboardinput>)))
  "Returns full string definition for message of type '<keyboardinput>"
  (cl:format cl:nil "string command~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'keyboardinput)))
  "Returns full string definition for message of type 'keyboardinput"
  (cl:format cl:nil "string command~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <keyboardinput>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <keyboardinput>))
  "Converts a ROS message object to a list"
  (cl:list 'keyboardinput
    (cl:cons ':command (command msg))
))
