# 接口示例程序

`lyre_examples` 程序包提供了部分 `CPP` 版本的接口调用示例。程序包的目录结构如下：

```
lyre_examples/
├── bin/                            # 接口调用示例的可执行程序  
│   ├── lyre_example_play_file_srv
├── cli/                            # 接口调用示例的终端执行脚本
│   ├── call_play_file_srv.sh
│   ├── sub_play_progress_msg.sh
├── src/                            # 接口调用示例的 cpp 代码 
│   ├── play_file_srv.cpp
├── res/                            # 静态资料
│   ├── test.mp3
├── CMakeLists.txt                  # 项目 CMakeLists.txt 示例
├── package.xml                     # 项目 ROS package.xml 示例
```

对于每个开放的语音接口，`lyre_examples` 包都提供有接口调用的示例代码、编译后的可执行程序、终端调用脚本，分别放置在 `src`、`bin`、`cli` 目录。

为了避免混淆，每个演示所用的可执行程序的文件名前面都加了 `lyre_example_` 作为前缀。
每个用于订阅 Topic 的脚本的文件名都加了 `sub_` 作为前缀； 每个用于发布 Topic 的脚本的文件名都加了 `pub_` 作为前缀。
每个用于调用 Service 的脚本的文件名则都加了 `call_` 作为前缀。

对于二次开发的 CPP ROS2 项目，可以参考 `lyre_examples` 包中的方式导入 `lyre_msgs` 接口，再参考示例代码完成功能开发。

## ROS package 配置

```
<package format="3">
  <depend>lyre_msgs</depend>
</package>
```

## 项目 CMake 配置

```
find_package(lyre_msgs REQUIRED)

ament_target_dependencies(
  <your_target>
  lyre_msgs
)
```

## 编译时、运行时依赖配置

x86 的 `ros2ws` 和 orin 的 `lyre_ros2` 提供了 `lyre_msgs` 包。在构建或者运行自己的 ROS 程序之前，需要先从这两个工作空间导入 `lyre_msgs` 依赖。

```
# x86
source ros2ws/install/setup.bash

# orin 
source lyre_ros2/install/setup.bash
```
