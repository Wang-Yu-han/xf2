import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Odometry
from sensor_msgs.msg import Imu
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import MagneticField
def odometry_callback(data):
    rospy.loginfo("Received Odometry message: %s",data)
def imu_callback(data):
    rospy.loginfo("Receive Imu message: %s",data)
def laserscan_callback(data):
    rospy.loginfo("Received LaserScan message: %s", data)
def magfield_callback(data):
    rospy.loginfo("Received MagneticField message: %s", data)
def listener():
    rospy.init_node('listener_node', anonymous=True)
    rospy.Subscriber("/driver/encoder", Odometry, odometry_callback)
    rospy.Subscriber("/driver/eul", Imu, imu_callback)
    rospy.Subscriber("/driver/imu", Imu, imu_callback)
    rospy.Subscriber("/driver/scan", LaserScan, laserscan_callback)
    rospy.Subscriber("/driver/mag", MagneticField, magfield_callback)
    rospy.spin()
if __name__=='__main__':
    listener()
