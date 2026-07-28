# 2 RealSense\+1 Orbbec 设备接入适配经验（以天轶 2\.0 为例）

# 硬件连接

天轶orin板上直连1奥比336\+2realsense D405

# 软件

## 笔记本接收端配置

1. ipv4

```Bash
sudo sysctl -w net.ipv4.ipfrag_high_thresh=268435456
sudo sysctl -w net.ipv4.ipfrag_low_thresh=201326592
sudo sysctl -w net.ipv4.ipfrag_time=3
```

2. usbfs\_memory

```Bash
# 永久配置方法
sudo gedit /etc/default/grub
#把这行改为
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash usbcore"
#如下
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash usbcore.usbfs_memory_mb=1024"

# 之后
sudo update-grub
# 重启
sudo reboot

# 临时设置
sudo sh -c 'echo 1024 > /sys/module/usbcore/parameters/usbfs_memory_mb'

# 检查方法
cat /sys/module/usbcore/parameters/usbfs_memory_mb
```

## Realsense

需要设置`depth_module.color_format:=BGR8`，否则在压缩rgb图像时会遇到问题

## thor/发送端配置

1. 关闭自动省电

```Bash
# 查询
cat /sys/module/usbcore/parameters/autosuspend

# 临时关闭
for f in /sys/bus/usb/devices/*/power/control; do echo on | sudo tee $f; done
# 然后确认 Orbbec 对应设备是不是已经变成 on
cat /sys/bus/usb/devices/2-5.2/power/control

# 永久关闭
sudo nano /etc/default/grub
#找到
GRUB_CMDLINE_LINUX_DEFAULT="..."
# 改为如
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash usbcore.autosuspend=-1"
# 之后
sudo update-grub
# 重启
sudo reboot
```

# Docs

启动文档存档

```Bash
###
ssh ubuntu@192.168.41.1
sudo su
source /home/ubuntu/ros2ws/install/setup.bash
ros2 launch body_control body.launch.py

####
ssh ubuntu@192.168.41.1
export ROS_DOMAIN_ID=0
sudo chmod 777 /dev/serial/by-id/*

python3 /home/ubuntu/Dev/xrocs/xrocs/entity/hand/RobotiqUSB/robotiq_node_zmq_standalone.py\
  --server_ip 192.168.41.1 \
  --server_set_port 4242 \
  --server_get_port 4243 \
  --hand_dev_ip /dev/serial/by-id/usb-FTDI_FT231X_USB_UART_DU0E6A5T-if00-port0 \
  --hand_slave_id 9 \
  --state_read_freq 30

####
ssh ubuntu@192.168.41.1
export ROS_DOMAIN_ID=0
sudo chmod 777 /dev/serial/by-id/*

python3 /home/ubuntu/Dev/xrocs/xrocs/entity/hand/RobotiqUSB/robotiq_node_zmq_standalone.py\
  --server_ip 192.168.41.1 \
  --server_set_port 4244 \
  --server_get_port 4245 \
  --hand_dev_ip /dev/serial/by-id/usb-FTDI_FT231X_USB_UART_DU0E654I-if00-port0 \
  --hand_slave_id 9 \
  --state_read_freq 30
  
####
ssh ubuntu@192.168.41.1
source nk2_ws/install/setup.bash
ros2 launch freq_change freq_change.launch.py

####
ssh nvidia@192.168.41.2
sudo sh -c 'echo 1024 > /sys/module/usbcore/parameters/usbfs_memory_mb'

source orbbec_camera_ros2/install/setup.bash
ros2 launch orbbec_camera gemini_330_series.launch.py color_width:=640 color_height:=480 depth_width:=640 depth_height:=480 color_fps:=30 depth_fps:=30

####
ssh nvidia@192.168.41.2
source realsense_ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py serial_no:=_260322278193 camera_name:='camera1' camera_namespace:='camera1' depth_module.color_profile:=640x480x30 depth_module.depth_profile:=640x480x30 align_depth.enable:=true depth_module.color_format:=BGR8

####
ssh nvidia@192.168.41.2
source realsense_ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py serial_no:=_260322273276 camera_name:='camera2' camera_namespace:='camera2' depth_module.color_profile:=640x480x30 depth_module.depth_profile:=640x480x30 align_depth.enable:=true depth_module.color_format:=BGR8

####
sudo su
source Dev/LittleArmControl/install/setup.bash
ros2 launch little_arm_control little_arm.launch.py
```

```Java
# ~/.config/xhumanoid/xrocs/default.toml
[basic]
station_type = "TienYi2_ROS2" # "TienKung2_ROS2","TienYi2_ROS2"
tele_agent_type = "EncoderTeleAgent" # "EncoderTeleAgent","ServoTeleCore"
control_rate_hz = 100  
robot_state_reading_rate_hz = 60
camera_state_reading_rate_hz = 30

[hand]
[hand.left]
enable = true
type = "Robotiq2f85Zmq" 
hand_ip = "192.168.41.1" 
hand_set_port = "4242"
hand_get_port = "4243"
sub_hand_joints = true
[hand.right]
enable = true
type = "Robotiq2f85Zmq"
hand_ip = "192.168.41.1"
hand_set_port = "4244"
hand_get_port = "4245"
sub_hand_joints = true

[data_collect]
save_type = "hdf5"
is_display_images = true  
is_display_states = true  
save_path = "~/Data/sim_data"  
episode_length = 20000  
max_episode = 2000  
robot_state_save_rate_hz = 60
camera_state_save_rate_hz = 30
task_name = "test01"  
task_description = "test_task"  
collector = "collector_001"  

[robot]
enable = true
[robot.arm.home]
robot = [0.0, 0.08, 0.0, -0.16, 0.01, 0.0, 0.0, 0.0, -0.08, 0.0, -0.16, -0.01, 0.0, 0.0]
[robot.head]
home = [0.0, 0.4, 0.0]
[robot.basic]
[robot.controller]
enable_head_controller = true
sub_head_status = true
enable_dual_arm_controller = true  
enable_dual_arm_freq_change = true          
sub_arm_status = true  

[camera]
[camera.head]
enable = true
type = "OrbbecCameraRos2" 
camera_model = "Orbbec_Gemini336L"
camera_color_channel = "bgr"
camera_color_resolution = [640, 480]
camera_depth_resolution = [640, 480]
camera_name = "camera" 
use_compress_rgb = true  
use_compress_depth = true  
[camera.left]
enable = true
type = "RealSenseCameraRos2" 
camera_model = "Realsense_D405"
camera_color_channel = "bgr"
camera_color_resolution = [640, 480]
camera_depth_resolution = [640, 480]
camera_name = "camera1/camera1" 
use_compress_rgb = true 
use_compress_depth = true 
is_use_time_synchronizer = true 
[camera.right]
enable = true
type = "RealSenseCameraRos2" 
camera_model = "Realsense_D405"
camera_color_channel = "bgr"
camera_color_resolution = [640, 480]
camera_depth_resolution = [640, 480]
camera_name = "camera2/camera2" 
use_compress_rgb = true 
use_compress_depth = true 
is_use_time_synchronizer = false 


[input_listener]
enable_keyboard = true
enable_encoder_tele_button = true   
enable_zmq = false

[force_sensor]
[force_sensor.left]
enable = true
type = "SrisensorRos2" 
[force_sensor.right]
enable = true
type = "SrisensorRos2"
```

# More

Ref [20260424——相机掉帧系统根因问题及优化](https://zitd5je6f7j.feishu.cn/wiki/GoGawZK7YivfAhkgimzcw6QLnzh?from=from_copylink)



