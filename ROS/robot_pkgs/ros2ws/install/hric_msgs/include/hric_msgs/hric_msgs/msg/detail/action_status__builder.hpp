// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/ActionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/action_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_ActionStatus_is_motion
{
public:
  explicit Init_ActionStatus_is_motion(::hric_msgs::msg::ActionStatus & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::ActionStatus is_motion(::hric_msgs::msg::ActionStatus::_is_motion_type arg)
  {
    msg_.is_motion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::ActionStatus msg_;
};

class Init_ActionStatus_motion_number
{
public:
  Init_ActionStatus_motion_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionStatus_is_motion motion_number(::hric_msgs::msg::ActionStatus::_motion_number_type arg)
  {
    msg_.motion_number = std::move(arg);
    return Init_ActionStatus_is_motion(msg_);
  }

private:
  ::hric_msgs::msg::ActionStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::ActionStatus>()
{
  return hric_msgs::msg::builder::Init_ActionStatus_motion_number();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__BUILDER_HPP_
