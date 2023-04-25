import rospy
import geometry_msgs
from sensor_msgs.msg import Imu
import time 
import tf



def imu_callback(data):
    orientation = data.orientation
    orientation_list = [orientation.x, orientation.y, orientation.z, orientation.w]
    (roll, pitch, yaw) = tf.transformations.euler_from_quaternion(orientation_list)
    heading = round(-1 * yaw, 2) # Negate yaw to match convention where positive yaw is to the left
    if heading < 0:
        heading += 360.0 # Convert to 0-360 degrees range
    rospy.loginfo("IMU Heading Angle: %s degrees", heading)
    

while(1):
    try:
        rospy.init_node('imu_listener',anonymous= True)
        rospy.Subscriber("/imu",Imu,imu_callback)

        rospy.spin()
    except rospy.ROSInterruptException:
        break


