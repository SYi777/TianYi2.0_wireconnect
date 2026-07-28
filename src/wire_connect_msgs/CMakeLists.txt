cmake_minimum_required(VERSION 3.8)
project(wire_connect_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PlugDetect.msg"
  "msg/PlugDetectArray.msg"
  "msg/PortDetect.msg"
  "msg/PortDetectArray.msg"
  "msg/ArmTarget.msg"
  DEPENDENCIES geometry_msgs std_msgs
)

ament_package()
