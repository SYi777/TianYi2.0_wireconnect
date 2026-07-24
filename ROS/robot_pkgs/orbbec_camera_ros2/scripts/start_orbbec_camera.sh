#!/bin/bash

if [ -d /home/nvidia ];then
  home_dir=/home/nvidia
elif [ -d /home/ubuntu ];then
  home_dir=/home/ubuntu
fi

ros_home_dir=${home_dir}/orbbec_camera_ros2
cd ${ros_home_dir}
export ROS_HOME=${ros_home_dir}
source /opt/ros/humble/setup.bash
source install/setup.bash
if [ ! $CAM_FW_UPGRADED ];then
    ${ros_home_dir}/install/orbbec_camera/lib/orbbec_camera/firmware_update ${ros_home_dir}/scripts/Gemini330_Release_1.6.00.bin
    echo "CAM_FW_UPGRADED=1" >> install/setup.bash
fi

export FASTRTPS_DEFAULT_PROFILES_FILE=${home_dir}/data/param/dds_profile.xml
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp

if [ "$1" = "head" ]; then
    echo "launch head camera"
    usbreset 2bc5:0803
    ros2 launch orbbec_camera head_330_tg2.0.launch.py
elif [ "$1" = "waist" ]; then
    echo "launch waist camera"
    ros2 launch orbbec_camera waist_330_tg2.0.launch.py
elif [ "$1" = "back" ]; then
    echo "launch back camera"
    ros2 launch orbbec_camera back_330_tg2.0.launch.py
elif [ "$1" = "headty" ]; then
    echo "launch head camera"
    usbreset 2bc5:0803
    ros2 launch orbbec_camera head_330_ty.launch.py
else
    echo "unknown param, launch default camera"
    ros2 launch orbbec_camera gemini_330_series.launch.py
fi