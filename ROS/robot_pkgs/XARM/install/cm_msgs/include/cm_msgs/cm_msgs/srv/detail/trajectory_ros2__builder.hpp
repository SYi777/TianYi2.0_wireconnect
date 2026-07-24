// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:srv/TrajectoryRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__BUILDER_HPP_
#define CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/srv/detail/trajectory_ros2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_TrajectoryRos2_Request_trajectory
{
public:
  explicit Init_TrajectoryRos2_Request_trajectory(::cm_msgs::srv::TrajectoryRos2_Request & msg)
  : msg_(msg)
  {}
  ::cm_msgs::srv::TrajectoryRos2_Request trajectory(::cm_msgs::srv::TrajectoryRos2_Request::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::TrajectoryRos2_Request msg_;
};

class Init_TrajectoryRos2_Request_msg_id
{
public:
  Init_TrajectoryRos2_Request_msg_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryRos2_Request_trajectory msg_id(::cm_msgs::srv::TrajectoryRos2_Request::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_TrajectoryRos2_Request_trajectory(msg_);
  }

private:
  ::cm_msgs::srv::TrajectoryRos2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::TrajectoryRos2_Request>()
{
  return cm_msgs::srv::builder::Init_TrajectoryRos2_Request_msg_id();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_TrajectoryRos2_Response_result
{
public:
  Init_TrajectoryRos2_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cm_msgs::srv::TrajectoryRos2_Response result(::cm_msgs::srv::TrajectoryRos2_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::TrajectoryRos2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::TrajectoryRos2_Response>()
{
  return cm_msgs::srv::builder::Init_TrajectoryRos2_Response_result();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__BUILDER_HPP_
