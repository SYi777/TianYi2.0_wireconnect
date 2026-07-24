// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/FloatBaseRPYZCommandFeedback.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ_COMMAND_FEEDBACK__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ_COMMAND_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/float_base_rpyz_command_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_FloatBaseRPYZCommandFeedback_z
{
public:
  explicit Init_FloatBaseRPYZCommandFeedback_z(::hric_msgs::msg::FloatBaseRPYZCommandFeedback & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::FloatBaseRPYZCommandFeedback z(::hric_msgs::msg::FloatBaseRPYZCommandFeedback::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZCommandFeedback msg_;
};

class Init_FloatBaseRPYZCommandFeedback_yaw
{
public:
  explicit Init_FloatBaseRPYZCommandFeedback_yaw(::hric_msgs::msg::FloatBaseRPYZCommandFeedback & msg)
  : msg_(msg)
  {}
  Init_FloatBaseRPYZCommandFeedback_z yaw(::hric_msgs::msg::FloatBaseRPYZCommandFeedback::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_FloatBaseRPYZCommandFeedback_z(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZCommandFeedback msg_;
};

class Init_FloatBaseRPYZCommandFeedback_pitch
{
public:
  explicit Init_FloatBaseRPYZCommandFeedback_pitch(::hric_msgs::msg::FloatBaseRPYZCommandFeedback & msg)
  : msg_(msg)
  {}
  Init_FloatBaseRPYZCommandFeedback_yaw pitch(::hric_msgs::msg::FloatBaseRPYZCommandFeedback::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_FloatBaseRPYZCommandFeedback_yaw(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZCommandFeedback msg_;
};

class Init_FloatBaseRPYZCommandFeedback_roll
{
public:
  Init_FloatBaseRPYZCommandFeedback_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FloatBaseRPYZCommandFeedback_pitch roll(::hric_msgs::msg::FloatBaseRPYZCommandFeedback::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_FloatBaseRPYZCommandFeedback_pitch(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZCommandFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::FloatBaseRPYZCommandFeedback>()
{
  return hric_msgs::msg::builder::Init_FloatBaseRPYZCommandFeedback_roll();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ_COMMAND_FEEDBACK__BUILDER_HPP_
