// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/msg/detail/arm_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'target'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace eai_manipulator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmTargetPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
    out << ", ";
  }

  // member: from_frame
  {
    out << "from_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame, out);
    out << ", ";
  }

  // member: to_frame
  {
    out << "to_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame, out);
    out << ", ";
  }

  // member: offset_x
  {
    out << "offset_x: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x, out);
    out << ", ";
  }

  // member: offset_y
  {
    out << "offset_y: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y, out);
    out << ", ";
  }

  // member: offset_z
  {
    out << "offset_z: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmTargetPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }

  // member: from_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame, out);
    out << "\n";
  }

  // member: to_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame, out);
    out << "\n";
  }

  // member: offset_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_x: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x, out);
    out << "\n";
  }

  // member: offset_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_y: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y, out);
    out << "\n";
  }

  // member: offset_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_z: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmTargetPose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::msg::ArmTargetPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::msg::ArmTargetPose & msg)
{
  return eai_manipulator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::msg::ArmTargetPose>()
{
  return "eai_manipulator_msgs::msg::ArmTargetPose";
}

template<>
inline const char * name<eai_manipulator_msgs::msg::ArmTargetPose>()
{
  return "eai_manipulator_msgs/msg/ArmTargetPose";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::msg::ArmTargetPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::msg::ArmTargetPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::msg::ArmTargetPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__TRAITS_HPP_
