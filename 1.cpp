#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/MagneticField.h"
void odometryCallback(const nav_msgs::Odometry::ConstPtr& msg) {
    ROS_INFO("Received Odometry message:[%f, %f, %f]",msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.position.z);
}
void imuCallback(const sensor_msgs::Imu::ConstPtr&msg) {
    ROS_INFO("Received Imu message:[%f, %f, %f]",msg->orientation.x,msg->orientation.y,msg->orientation.z);
}
void laserScanCallback(const sensor_msgs::LaserScan::ConstPtr&msg) {
    ROS_INFO("Received LaserScan message:[%f, %f]",msg->range_min,msg->range_max);
}
void magneticFieldCallback(const sensor_msgs::MagneticField::ConstPtr& msg) {
    ROS_INFO("Received MagneticField message:[%f, %f, %f]",msg->magnetic_field.x,msg->magnetic_field.y,msg->magnetic_field.z);
}
int main(int argc,char **argv) {
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber odometry_sub=n.subscribe("driver/encoder",1000,odometryCallback);
    ros::Subscriber imu_sub=n.subscribe("driver/eul",1000,imuCallback);
    ros::Subscriber imu_sub2=n.subscribe("driver/imu",1000,imuCallback);
    ros::Subscriber laser_scan_sub=n.subscribe("driver/scan",1000,laserScanCallback);
    ros::Subscriber magnetic_field_sub=n.subscribe("driver/mag",1000,magneticFieldCallback);
    ros::spin();
    return 0;
}
