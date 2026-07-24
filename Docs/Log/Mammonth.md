本文档是天轶2.0机器人的系统架构描述和快速开发指南，取名猛犸象
author:景宇航 email:jyh1621839418@163.com

机器人控制部分---------------------------------------------------------

机器人一共三个按钮，从下到上挨个启动，启动后等待播放音效，胸口蓝绿灯呼吸闪烁，遥控器按下A，启动自建，音效结束常亮自检结束，未自检的机器无法使用ROS2（原因暂时不明）

启动后可以采用有线/路由器的方式让机器和自己电脑存在于同网段，有线方式要修改自身电脑以太网配置为手动，建议192.168.41.5，掩码255.255.255.0，运行ping 192.168.41.1（x86主机）和ping 192.168.41.2（orin主机）以验证，此时你可以选择ssh任一主机

机器人自带AGX和x86双主机，二者之间通过DDS协议共享了ROS2系统，将机器和你的电脑配置于同一网段一是为了便于远程，二是让你的电脑和机器的ROS2共通，在电脑环境上可以直接订阅得到机器的数据，DDS协议白名单配置文件修改参考官方文档，ROS2节点（暂时列出我知道和大家比赛要用的）分布为x86上是机器人所有关节控制，Orin上是摄像头节点和语音模块（后续模型推理也要到AGX上）

DDS互通后通过ros2 topic list验证是否成功（Orin上的奥比中光节点不一定自启，需要ssh过去运行sudo systemctl start ...自己看官方文档）

ROS2的消息格式这些基础知识就不详细说了，很多底层的控制代码已经被编译后删除了，能参考的只有cmakelist和一些编译过程文件

如果自检不通过或者无法连接机器，关掉遥控器，将机器恢复为胸前呼吸灯待自检状态，手动启动关闭本体程序启动器
ssh : 
sudo systemctl stop proc_manager.service 
重启机器人bodyctrl
ssh : 
sudo su 
cd ros2ws 
source install/setup.bash 
ros2 launch body_control body.launch.py
如果需要跳过手的自检:
cd /home/ubuntu/data/param/u2c_sn.yaml
给enablehands改成false

bodyctl是整机的核心控制节点
静态tf已经根据urdf给出，动态tf已经通过urdf转化的moveit节点pub
xrocs是机器人控制的sdk：通过中间层呢个xarm将不同机器人的bodyctrl进行封装，通过import可以调用，等价于rclpy
具体见文档
xrocs是对xarm的进一步封装，调用xrocs等价于给xarm发东西等价于给bodyctrl发东西

entry是OTA升级的和云服务内容，我也不知道干嘛的先不管
其他的文件夹看到了再说

python环境报错了再安装

所以整机的系统包含的内容其实就是ros2_ws,nk2_ws,xrocs,XARM,Documents/configuration.toml,/home/ubuntu/inspire_hand

数采/遥操部分-------------------------------------------------------

数采的系统设计是这样:工控机启动fastsync走zmq去机器人，笔记本电脑启动manus收集手套数据重定向走zmq广播，，机器人启动dataconnect来录制主端数据和转发控制指令给bodyctrl，录制配置在机器人~/Documents/configuration.toml

同构臂安装，工控机，电脑，机器人接入交换机，ping工控机12.168.41.100,通了之后ssh eai（eai231102!），上去之后运行sudo systemctl status xtele-monitor.service，保证active，运行candump can0和candump can1，检查同构臂是否连接，访问http://192.168.41.100:9001，查看数据是否正常

如果需要数采建议自己写
具体架构和启动见遥操数采仓库文档

遥操方案-------------------------------------------
我们不可能使用像现在机器一样的好几个设备连在交换机上进行websocket通信的打法，需要自己把手套和灵巧手适配
所以优化方向是把dev和手套接收器装在机器人身上zmq自回环给collect控制灵巧手，工控机暂时保留，同构臂走的是can

数采要换手总共要改三处文件，装manus手套的设备要改数据维度，机器人上面的数采脚本/home/ubuntu/Documents/configuration.toml配置文件要把手型号修改，~/.config/xhumanoid/xtele/default.toml机器人的这个文件数据维度也要改，同时启动的时候需要单独启动13自由度因时手~/inspire_sdk$ ./start_rh5dg2_both.sh
因时G2手控制

自主打法--------------------------------------------



基于本地urdf接收xarm的moveit可视化规划控制---------------------
