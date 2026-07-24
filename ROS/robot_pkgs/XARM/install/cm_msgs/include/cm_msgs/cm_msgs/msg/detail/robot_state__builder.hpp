// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_head_pose
{
public:
  explicit Init_RobotState_head_pose(::cm_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::cm_msgs::msg::RobotState head_pose(::cm_msgs::msg::RobotState::_head_pose_type arg)
  {
    msg_.head_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::RobotState msg_;
};

class Init_RobotState_header
{
public:
  Init_RobotState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_head_pose header(::cm_msgs::msg::RobotState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotState_head_pose(msg_);
  }

private:
  ::cm_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::RobotState>()
{
  return cm_msgs::msg::builder::Init_RobotState_header();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
