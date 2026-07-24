// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace msg
{

namespace builder
{

class Init_DualArmTargetPose_is_dual_arm_syn
{
public:
  explicit Init_DualArmTargetPose_is_dual_arm_syn(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::msg::DualArmTargetPose is_dual_arm_syn(::eai_manipulator_msgs::msg::DualArmTargetPose::_is_dual_arm_syn_type arg)
  {
    msg_.is_dual_arm_syn = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_z_r
{
public:
  explicit Init_DualArmTargetPose_offset_z_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_is_dual_arm_syn offset_z_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_z_r_type arg)
  {
    msg_.offset_z_r = std::move(arg);
    return Init_DualArmTargetPose_is_dual_arm_syn(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_y_r
{
public:
  explicit Init_DualArmTargetPose_offset_y_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_z_r offset_y_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_y_r_type arg)
  {
    msg_.offset_y_r = std::move(arg);
    return Init_DualArmTargetPose_offset_z_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_x_r
{
public:
  explicit Init_DualArmTargetPose_offset_x_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_y_r offset_x_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_x_r_type arg)
  {
    msg_.offset_x_r = std::move(arg);
    return Init_DualArmTargetPose_offset_y_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_to_frame_r
{
public:
  explicit Init_DualArmTargetPose_to_frame_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_x_r to_frame_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_to_frame_r_type arg)
  {
    msg_.to_frame_r = std::move(arg);
    return Init_DualArmTargetPose_offset_x_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_from_frame_r
{
public:
  explicit Init_DualArmTargetPose_from_frame_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_to_frame_r from_frame_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_from_frame_r_type arg)
  {
    msg_.from_frame_r = std::move(arg);
    return Init_DualArmTargetPose_to_frame_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_target_r
{
public:
  explicit Init_DualArmTargetPose_target_r(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_from_frame_r target_r(::eai_manipulator_msgs::msg::DualArmTargetPose::_target_r_type arg)
  {
    msg_.target_r = std::move(arg);
    return Init_DualArmTargetPose_from_frame_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_z_l
{
public:
  explicit Init_DualArmTargetPose_offset_z_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_target_r offset_z_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_z_l_type arg)
  {
    msg_.offset_z_l = std::move(arg);
    return Init_DualArmTargetPose_target_r(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_y_l
{
public:
  explicit Init_DualArmTargetPose_offset_y_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_z_l offset_y_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_y_l_type arg)
  {
    msg_.offset_y_l = std::move(arg);
    return Init_DualArmTargetPose_offset_z_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_offset_x_l
{
public:
  explicit Init_DualArmTargetPose_offset_x_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_y_l offset_x_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_offset_x_l_type arg)
  {
    msg_.offset_x_l = std::move(arg);
    return Init_DualArmTargetPose_offset_y_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_to_frame_l
{
public:
  explicit Init_DualArmTargetPose_to_frame_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_offset_x_l to_frame_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_to_frame_l_type arg)
  {
    msg_.to_frame_l = std::move(arg);
    return Init_DualArmTargetPose_offset_x_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_from_frame_l
{
public:
  explicit Init_DualArmTargetPose_from_frame_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_to_frame_l from_frame_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_from_frame_l_type arg)
  {
    msg_.from_frame_l = std::move(arg);
    return Init_DualArmTargetPose_to_frame_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_target_l
{
public:
  explicit Init_DualArmTargetPose_target_l(::eai_manipulator_msgs::msg::DualArmTargetPose & msg)
  : msg_(msg)
  {}
  Init_DualArmTargetPose_from_frame_l target_l(::eai_manipulator_msgs::msg::DualArmTargetPose::_target_l_type arg)
  {
    msg_.target_l = std::move(arg);
    return Init_DualArmTargetPose_from_frame_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

class Init_DualArmTargetPose_header
{
public:
  Init_DualArmTargetPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DualArmTargetPose_target_l header(::eai_manipulator_msgs::msg::DualArmTargetPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DualArmTargetPose_target_l(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::DualArmTargetPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::msg::DualArmTargetPose>()
{
  return eai_manipulator_msgs::msg::builder::Init_DualArmTargetPose_header();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__BUILDER_HPP_
