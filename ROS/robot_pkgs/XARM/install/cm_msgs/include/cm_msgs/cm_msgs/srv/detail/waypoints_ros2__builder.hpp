// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:srv/WaypointsRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__BUILDER_HPP_
#define CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/srv/detail/waypoints_ros2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_WaypointsRos2_Request_right_waypoints
{
public:
  explicit Init_WaypointsRos2_Request_right_waypoints(::cm_msgs::srv::WaypointsRos2_Request & msg)
  : msg_(msg)
  {}
  ::cm_msgs::srv::WaypointsRos2_Request right_waypoints(::cm_msgs::srv::WaypointsRos2_Request::_right_waypoints_type arg)
  {
    msg_.right_waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::WaypointsRos2_Request msg_;
};

class Init_WaypointsRos2_Request_left_waypoints
{
public:
  Init_WaypointsRos2_Request_left_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointsRos2_Request_right_waypoints left_waypoints(::cm_msgs::srv::WaypointsRos2_Request::_left_waypoints_type arg)
  {
    msg_.left_waypoints = std::move(arg);
    return Init_WaypointsRos2_Request_right_waypoints(msg_);
  }

private:
  ::cm_msgs::srv::WaypointsRos2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::WaypointsRos2_Request>()
{
  return cm_msgs::srv::builder::Init_WaypointsRos2_Request_left_waypoints();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_WaypointsRos2_Response_message
{
public:
  explicit Init_WaypointsRos2_Response_message(::cm_msgs::srv::WaypointsRos2_Response & msg)
  : msg_(msg)
  {}
  ::cm_msgs::srv::WaypointsRos2_Response message(::cm_msgs::srv::WaypointsRos2_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::WaypointsRos2_Response msg_;
};

class Init_WaypointsRos2_Response_success
{
public:
  Init_WaypointsRos2_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointsRos2_Response_message success(::cm_msgs::srv::WaypointsRos2_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_WaypointsRos2_Response_message(msg_);
  }

private:
  ::cm_msgs::srv::WaypointsRos2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::WaypointsRos2_Response>()
{
  return cm_msgs::srv::builder::Init_WaypointsRos2_Response_success();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__BUILDER_HPP_
