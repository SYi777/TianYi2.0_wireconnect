# RealSense ROS 2 部署及接入

|**时间**|**变更内容**|**人员**|
|---|---|---|
|2026年1月23日|1. 文档创建（测试机型：天工 Dex ？？？？？）<br>> 内容参考自[Realsense D400系列安装文档](https://zitd5je6f7j.feishu.cn/wiki/ORvAw3dpxiMmMlkF4G4cV1agn7b)<br>> <br>> |@Sunny Gao|





## 1\.安装依赖

1）更新软件包索引

```Plain Text
sudo apt-get update 
```

2）安装依赖

```Plain Text
sudo apt-get install libssl-dev libusb-1.0-0-dev libudev-dev pkg-config libgtk-3-dev
```

3）安装编译工具

```Plain Text
sudo apt-get install git wget cmake build-essential
```

4）拔掉所有realsense相机，安装依赖

```Plain Text
sudo apt-get install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev at
```



## 2\.安装librealsense2

1）Clone/Download the latest stable version of *librealsense2* in one of the following ways:

方法一：从官方仓库下载

```Plain Text
git clone https://github.com/IntelRealSense/librealsense.git
```

方法二：从我的gitlab下载

```Bash
wget --user "gitlab+deploy-token-7" --ask-password   "http://10.0.3.101/api/v4/projects/1293/packages/generic/sunnygao_file/260123/librealsense-master.zip"
 （password: gldt-7G1fVQpz6Dzn4v65k9Hc ）
```

方法三：从文档底部下载资源包

2）Run Intel Realsense permissions script from *librealsense2* root directory:

```Plain Text
cd librealsense
./scripts/setup_udev_rules.sh
```

Notice: You can always remove permissions by running: `./scripts/setup_udev_rules.sh --uninstall`

3）Build and apply patched kernel modules for:（仅ubuntu）

```Plain Text
./scripts/patch-realsense-ubuntu-lts-hwe.sh
```

- thor：

    ```Plain Text
    sudo apt update
    sudo apt install -y git cmake build-essential libusb-1.0-0-dev pkg-config libgtk-3-dev
    cd ~/librealsense
    mkdir -p build
    cd build
    cmake .. -DFORCE_RSUSB_BACKEND=ON -DBUILD_EXAMPLES=true -DBUILD_GRAPHICAL_EXAMPLES=true
    make -j$(nproc)
    sudo make install
    ```

4）Navigate to *librealsense2* root directory and run:

```Plain Text
mkdir build && cd build
```

Run cmake configure step, here are some cmake configure examples:

```Plain Text
cmake ../
```

5）Recompile and install *librealsense2* binaries:

```Plain Text
sudo make uninstall && make clean && make && sudo make install
```

编译慢可以改下面这个多核编译，$\(nproc\)为自动获取的cpu核数量，如果爆内存了请手动减少

**Note:** Only relevant to CPUs with more than 1 core: use `make -j$(($(nproc)-1)) install` allow parallel compilation\.

**Note:** The shared object will be installed in `/usr/local/lib`, header files in `/usr/local/include`\.
 The binary demos, tutorials and test files will be copied into `/usr/local/bin`



## 3:安装ROS2 Wrapper for RealSense

1）：Create a ROS2 workspace

```Plain Text
mkdir -p ~/realsense_ros2_ws/src
cd ~/realsense_ros2_ws/src/
```

2）：Clone the latest ROS Wrapper for RealSense（也可以直接从下方拿资源包）\(若刚才安装librealsense时从官方下载，这次也从官方下载；若刚才安装librealsense时从我的gitlab下载，这次也从我的gitlab下载，以免出现版本不匹配的情况\)

方法一：从官方下载

```Plain Text
git clone https://github.com/IntelRealSense/realsense-ros.git -b ros2-master
cd ~/realsense_ros2_ws
```

方法二：从我的gitlab下载

```Bash
wget --user "gitlab+deploy-token-7" --ask-password   "http://10.0.3.101/api/v4/projects/1293/packages/generic/sunnygao_file/260123/realsense-ros.zip"
（password: gldt-7G1fVQpz6Dzn4v65k9Hc ）
cd ~/realsense_ros2_ws
```

方法三：从文档底部下载资源包，之后

```Bash
cd ~/realsense_ros2_ws
```

3）：Install dependencies

```Plain Text
sudo apt-get install python3-rosdep -y
sudo rosdep init 
rosdep update 
rosdep install -i --from-path src --rosdistro $ROS_DISTRO --skip-keys=librealsense2 -y
```

4）：Build

```Plain Text
colcon build
```



4：运行ros节点

（1）单相机

```Bash
ros2 launch realsense2_camera rs_launch.py
# or with param,example:
ros2 launch realsense2_camera rs_launch.py depth_module.depth_profile:=1280x720x30 pointcloud.enable:=true
ros2 launch realsense2_camera rs_launch.py camera_namespace:=robot1 camera_name:=D455_1    
```

（2）多相机

如果有两个相机用同一个节点启动，需要先查看相机串口号：

```Plain Text
rs-enumerate-devices -s     
```

![Image](https://internal-api-drive-stream.feishu.cn/space/api/box/stream/download/authcode/?code=Y2U4NGJkZWMzMWFkZTJmMzdiZmQ2MWIwNzZkMTg0YmRfNTVlNGJjOTUxZWFhZWZjZWRjMjkwOWFlMTExMjhlNjhfSUQ6NzY2NDg2MjA0OTYwODE1ODE3N18xNzg1MTU4NDkxOjE3ODUyNDQ4OTFfVjM)

这两个即分别为左右相机的序列号，将其替代下面命令中的serial\_no

Terminal 1:

```Plain Text
source ~/realsense_ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py serial_no:="'207322251310'" camera_name:='camera1' camera_namespace:='camera1'
```

Terminal 2:

```Plain Text
source ~/realsense_ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py serial_no:="'234422060144'" camera_name:='camera2' camera_namespace:='camera2'
```



## 4：相关资源包

\[librealsense\-master\.zip\]

\[realsense\-ros\.zip\]



