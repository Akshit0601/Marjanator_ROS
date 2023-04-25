import rospy

from geometry_msgs.msg import Twist
rospy.init_node("remapper",anonymous=False)

pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)

msg = Twist
def cmd_vel_callback(data):
    global msg
    msg = data
    pub.publish(msg)

rospy.Subscriber("/mobile_base_controller/cmd_vel",Twist,cmd_vel_callback)



while not rospy.is_shutdown():
    rospy.spin()

    



       