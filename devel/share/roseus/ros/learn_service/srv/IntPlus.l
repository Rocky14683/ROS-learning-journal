;; Auto-generated. Do not edit!


(when (boundp 'learn_service::IntPlus)
  (if (not (find-package "LEARN_SERVICE"))
    (make-package "LEARN_SERVICE"))
  (shadow 'IntPlus (find-package "LEARN_SERVICE")))
(unless (find-package "LEARN_SERVICE::INTPLUS")
  (make-package "LEARN_SERVICE::INTPLUS"))
(unless (find-package "LEARN_SERVICE::INTPLUSREQUEST")
  (make-package "LEARN_SERVICE::INTPLUSREQUEST"))
(unless (find-package "LEARN_SERVICE::INTPLUSRESPONSE")
  (make-package "LEARN_SERVICE::INTPLUSRESPONSE"))

(in-package "ROS")





(defclass learn_service::IntPlusRequest
  :super ros::object
  :slots (_a _b ))

(defmethod learn_service::IntPlusRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; uint8 _a
    1
    ;; uint8 _b
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _a
       (write-byte _a s)
     ;; uint8 _b
       (write-byte _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _a
     (setq _a (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _b
     (setq _b (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass learn_service::IntPlusResponse
  :super ros::object
  :slots (_result ))

(defmethod learn_service::IntPlusResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; uint8 _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _result
       (write-byte _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _result
     (setq _result (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass learn_service::IntPlus
  :super ros::object
  :slots ())

(setf (get learn_service::IntPlus :md5sum-) "32f3e69fccd784eebfbfc5b37be0e2f0")
(setf (get learn_service::IntPlus :datatype-) "learn_service/IntPlus")
(setf (get learn_service::IntPlus :request) learn_service::IntPlusRequest)
(setf (get learn_service::IntPlus :response) learn_service::IntPlusResponse)

(defmethod learn_service::IntPlusRequest
  (:response () (instance learn_service::IntPlusResponse :init)))

(setf (get learn_service::IntPlusRequest :md5sum-) "32f3e69fccd784eebfbfc5b37be0e2f0")
(setf (get learn_service::IntPlusRequest :datatype-) "learn_service/IntPlusRequest")
(setf (get learn_service::IntPlusRequest :definition-)
      "uint8 a
uint8 b
---
uint8 result
")

(setf (get learn_service::IntPlusResponse :md5sum-) "32f3e69fccd784eebfbfc5b37be0e2f0")
(setf (get learn_service::IntPlusResponse :datatype-) "learn_service/IntPlusResponse")
(setf (get learn_service::IntPlusResponse :definition-)
      "uint8 a
uint8 b
---
uint8 result
")



(provide :learn_service/IntPlus "32f3e69fccd784eebfbfc5b37be0e2f0")


