
(cl:in-package :asdf)

(defsystem "Msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "HardwareCommand" :depends-on ("_package_HardwareCommand"))
    (:file "_package_HardwareCommand" :depends-on ("_package"))
    (:file "keyboardinput" :depends-on ("_package_keyboardinput"))
    (:file "_package_keyboardinput" :depends-on ("_package"))
  ))