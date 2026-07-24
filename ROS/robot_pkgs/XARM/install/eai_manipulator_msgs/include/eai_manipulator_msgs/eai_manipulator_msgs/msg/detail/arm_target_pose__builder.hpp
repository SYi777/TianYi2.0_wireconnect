// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/msg/detail/arm_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace msg
{

namespace builder
{

class Init_ArmTargetPose_offset_z
{
public:
  explicit Init_ArmTargetPose_offset_z(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::msg::ArmTargetPose offset_z(::eai_manipulator_msgs::msg::ArmTargetPose::_offset_z_type arg)
  {
    msg_.offset_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_offset_y
{
public:
  explicit Init_ArmTargetPose_offset_y(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_ArmTargetPose_offset_z offset_y(::eai_manipulator_msgs::msg::ArmTargetPose::_offset_y_type arg)
  {
    msg_.offset_y = std::move(arg);
    return Init_ArmTargetPose_offset_z(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_offset_x
{
public:
  explicit Init_ArmTargetPose_offset_x(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_ArmTargetPose_offset_y offset_x(::eai_manipulator_msgs::msg::ArmTargetPose::_offset_x_type arg)
  {
    msg_.offset_x = std::move(arg);
    return Init_ArmTargetPose_offset_y(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_to_frame
{
public:
  explicit Init_ArmTargetPose_to_frame(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_ArmTargetPose_offset_x to_frame(::eai_manipulator_msgs::msg::ArmTargetPose::_to_frame_type arg)
  {
    msg_.to_frame = std::move(arg);
    return Init_ArmTargetPose_offset_x(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_from_frame
{
public:
  explicit Init_ArmTargetPose_from_frame(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_ArmTargetPose_to_frame from_frame(::eai_manipulator_msgs::msg::ArmTargetPose::_from_frame_type arg)
  {
    msg_.from_frame = std::move(arg);
    return Init_ArmTargetPose_to_frame(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_target
{
public:
  explicit Init_ArmTargetPose_target(::eai_manipulator_msgs::msg::ArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_ArmTargetPose_from_frame target(::eai_manipulator_msgs::msg::ArmTargetPose::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_ArmTargetPose_from_frame(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

class Init_ArmTargetPose_header
{
public:
  Init_ArmTargetPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmTargetPose_target header(::eai_manipulator_msgs::msg::ArmTargetPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArmTargetPose_target(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::ArmTargetPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::msg::ArmTargetPose>()
{
  return eai_manipulator_msgs::msg::builder::Init_ArmTargetPose_header();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__BUILDER_HPP_
