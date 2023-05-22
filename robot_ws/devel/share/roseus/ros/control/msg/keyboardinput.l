;; Auto-generated. Do not edit!


(when (boundp 'control::keyboardinput)
  (if (not (find-package "CONTROL"))
    (make-package "CONTROL"))
  (shadow 'keyboardinput (find-package "CONTROL")))
(unless (find-package "CONTROL::KEYBOARDINPUT")
  (make-package "CONTROL::KEYBOARDINPUT"))

(in-package "ROS")
;;//! \htmlinclude keyboardinput.msg.html


(defclass control::keyboardinput
  :super ros::object
  :slots (_command ))

(defmethod control::keyboardinput
  (:init
   (&key
    ((:command __command) 0)
    )
   (send-super :init)
   (setq _command (round __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; char _command
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; char _command
       (write-byte _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; char _command
     (setq _command (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get control::keyboardinput :md5sum-) "cf31d8a7def4ce3bca7e2b1b06a5b2a6")
(setf (get control::keyboardinput :datatype-) "control/keyboardinput")
(setf (get control::keyboardinput :definition-)
      "char command
")



(provide :control/keyboardinput "cf31d8a7def4ce3bca7e2b1b06a5b2a6")


