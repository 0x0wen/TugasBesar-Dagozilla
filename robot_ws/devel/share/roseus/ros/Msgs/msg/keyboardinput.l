;; Auto-generated. Do not edit!


(when (boundp 'Msgs::keyboardinput)
  (if (not (find-package "MSGS"))
    (make-package "MSGS"))
  (shadow 'keyboardinput (find-package "MSGS")))
(unless (find-package "MSGS::KEYBOARDINPUT")
  (make-package "MSGS::KEYBOARDINPUT"))

(in-package "ROS")
;;//! \htmlinclude keyboardinput.msg.html


(defclass Msgs::keyboardinput
  :super ros::object
  :slots (_command ))

(defmethod Msgs::keyboardinput
  (:init
   (&key
    ((:command __command) "")
    )
   (send-super :init)
   (setq _command (string __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get Msgs::keyboardinput :md5sum-) "cba5e21e920a3a2b7b375cb65b64cdea")
(setf (get Msgs::keyboardinput :datatype-) "Msgs/keyboardinput")
(setf (get Msgs::keyboardinput :definition-)
      "string command
")



(provide :Msgs/keyboardinput "cba5e21e920a3a2b7b375cb65b64cdea")


