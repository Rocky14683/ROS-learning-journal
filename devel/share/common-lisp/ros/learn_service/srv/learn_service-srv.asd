
(cl:in-package :asdf)

(defsystem "learn_service-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IntPlus" :depends-on ("_package_IntPlus"))
    (:file "_package_IntPlus" :depends-on ("_package"))
  ))