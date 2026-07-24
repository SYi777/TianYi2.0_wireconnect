cmake_minimum_required(VERSION 3.8)
project(freq_change)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 查找ROS 2依赖（添加sensor_msgs）
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(bodyctrl_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)  # 添加sensor_msgs依赖

# 包含目录
include_directories(
  include
  rtlink/include
  ${CMAKE_SOURCE_DIR}/include/freq_change/
  src
)

# 链接目录
link_directories(
  rtlink/lib
)

# 创建可执行文件
add_executable(freq_change_node
  src/freq_change.cpp
)

# 依赖项设置（添加sensor_msgs）
ament_target_dependencies(freq_change_node
  rclcpp
  std_msgs
  bodyctrl_msgs
  sensor_msgs  # 关联sensor_msgs依赖
)

# 链接线程库
target_link_libraries(freq_change_node
  pthread  # 线程库
)

# 安装可执行文件
install(TARGETS
  freq_change_node
  DESTINATION lib/${PROJECT_NAME}
)

# 安装param和launch目录
install(DIRECTORY
  param
  launch
  DESTINATION share/${PROJECT_NAME}
)

# 安装头文件（如果有）
install(DIRECTORY include/
  DESTINATION include/
)

# 测试配置
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_dependencies(rclcpp)
ament_export_dependencies(std_msgs)
ament_export_dependencies(sensor_msgs)  # 导出sensor_msgs依赖

ament_package()
    