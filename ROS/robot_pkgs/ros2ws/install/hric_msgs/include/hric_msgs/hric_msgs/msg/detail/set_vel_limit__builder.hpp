// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/SetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/set_vel_limit__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_SetVelLimit_x_vel_limit_halfwalk
{
public:
  explicit Init_SetVelLimit_x_vel_limit_halfwalk(::hric_msgs::msg::SetVelLimit & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::SetVelLimit x_vel_limit_halfwalk(::hric_msgs::msg::SetVelLimit::_x_vel_limit_halfwalk_type arg)
  {
    msg_.x_vel_limit_halfwalk = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::SetVelLimit msg_;
};

class Init_SetVelLimit_x_vel_limit_run
{
public:
  explicit Init_SetVelLimit_x_vel_limit_run(::hric_msgs::msg::SetVelLimit & msg)
  : msg_(msg)
  {}
  Init_SetVelLimit_x_vel_limit_halfwalk x_vel_limit_run(::hric_msgs::msg::SetVelLimit::_x_vel_limit_run_type arg)
  {
    msg_.x_vel_limit_run = std::move(arg);
    return Init_SetVelLimit_x_vel_limit_halfwalk(msg_);
  }

private:
  ::hric_msgs::msg::SetVelLimit msg_;
};

class Init_SetVelLimit_x_vel_limit_walk
{
public:
  Init_SetVelLimit_x_vel_limit_walk()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetVelLimit_x_vel_limit_run x_vel_limit_walk(::hric_msgs::msg::SetVelLimit::_x_vel_limit_walk_type arg)
  {
    msg_.x_vel_limit_walk = std::move(arg);
    return Init_SetVelLimit_x_vel_limit_run(msg_);
  }

private:
  ::hric_msgs::msg::SetVelLimit msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::SetVelLimit>()
{
  return hric_msgs::msg::builder::Init_SetVelLimit_x_vel_limit_walk();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__BUILDER_HPP_
