// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/GetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/get_vel_limit__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_GetVelLimit_x_vel_limit_halfwalk
{
public:
  explicit Init_GetVelLimit_x_vel_limit_halfwalk(::hric_msgs::msg::GetVelLimit & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::GetVelLimit x_vel_limit_halfwalk(::hric_msgs::msg::GetVelLimit::_x_vel_limit_halfwalk_type arg)
  {
    msg_.x_vel_limit_halfwalk = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::GetVelLimit msg_;
};

class Init_GetVelLimit_x_vel_limit_run
{
public:
  explicit Init_GetVelLimit_x_vel_limit_run(::hric_msgs::msg::GetVelLimit & msg)
  : msg_(msg)
  {}
  Init_GetVelLimit_x_vel_limit_halfwalk x_vel_limit_run(::hric_msgs::msg::GetVelLimit::_x_vel_limit_run_type arg)
  {
    msg_.x_vel_limit_run = std::move(arg);
    return Init_GetVelLimit_x_vel_limit_halfwalk(msg_);
  }

private:
  ::hric_msgs::msg::GetVelLimit msg_;
};

class Init_GetVelLimit_x_vel_limit_walk
{
public:
  Init_GetVelLimit_x_vel_limit_walk()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetVelLimit_x_vel_limit_run x_vel_limit_walk(::hric_msgs::msg::GetVelLimit::_x_vel_limit_walk_type arg)
  {
    msg_.x_vel_limit_walk = std::move(arg);
    return Init_GetVelLimit_x_vel_limit_run(msg_);
  }

private:
  ::hric_msgs::msg::GetVelLimit msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::GetVelLimit>()
{
  return hric_msgs::msg::builder::Init_GetVelLimit_x_vel_limit_walk();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__BUILDER_HPP_
