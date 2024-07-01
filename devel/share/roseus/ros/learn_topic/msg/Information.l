;; Auto-generated. Do not edit!


(when (boundp 'learn_topic::Information)
  (if (not (find-package "LEARN_TOPIC"))
    (make-package "LEARN_TOPIC"))
  (shadow 'Information (find-package "LEARN_TOPIC")))
(unless (find-package "LEARN_TOPIC::INFORMATION")
  (make-package "LEARN_TOPIC::INFORMATION"))

(in-package "ROS")
;;//! \htmlinclude Information.msg.html


(defclass learn_topic::Information
  :super ros::object
  :slots (_company _year ))

(defmethod learn_topic::Information
  (:init
   (&key
    ((:company __company) "")
    ((:year __year) "")
    )
   (send-super :init)
   (setq _company (string __company))
   (setq _year (string __year))
   self)
  (:company
   (&optional __company)
   (if __company (setq _company __company)) _company)
  (:year
   (&optional __year)
   (if __year (setq _year __year)) _year)
  (:serialization-length
   ()
   (+
    ;; string _company
    4 (length _company)
    ;; string _year
    4 (length _year)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _company
       (write-long (length _company) s) (princ _company s)
     ;; string _year
       (write-long (length _year) s) (princ _year s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _company
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _company (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _year
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _year (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get learn_topic::Information :md5sum-) "4092f70730c2545e71ae30dda7615194")
(setf (get learn_topic::Information :datatype-) "learn_topic/Information")
(setf (get learn_topic::Information :definition-)
      "string company
string year
")



(provide :learn_topic/Information "4092f70730c2545e71ae30dda7615194")


