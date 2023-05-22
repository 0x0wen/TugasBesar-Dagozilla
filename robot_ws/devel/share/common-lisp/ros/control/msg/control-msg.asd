
(cl:in-package :asdf)

(defsystem "control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "keyboardinput" :depends-on ("_package_keyboardinput"))
    (:file "_package_keyboardinput" :depends-on ("_package"))
    (:file "motor" :depends-on ("_package_motor"))
    (:file "_package_motor" :depends-on ("_package"))
  ))