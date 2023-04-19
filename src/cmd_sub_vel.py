#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

def callback(data):
    linear_vel = data.linear.x
    angular_vel = data.angular.z

    rospy.loginfo("Received linear velocity: %f" % linear_vel)
    rospy.loginfo("Received angular velocity: %f" % angular_vel)

def listener():
    rospy.init_node('cmd_vel_subscriber', anonymous=True)

    rospy.Subscriber("/mobile_base_controller/cmd_vel", Twist, callback)

    rospy.spin()
while(1):
    try:
        listener()
    except rospy.ROSInterruptException:
        pass

