// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'target_l'
// Member 'target_r'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace eai_manipulator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DualArmTargetPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: target_l
  {
    out << "target_l: ";
    to_flow_style_yaml(msg.target_l, out);
    out << ", ";
  }

  // member: from_frame_l
  {
    out << "from_frame_l: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame_l, out);
    out << ", ";
  }

  // member: to_frame_l
  {
    out << "to_frame_l: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame_l, out);
    out << ", ";
  }

  // member: offset_x_l
  {
    out << "offset_x_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x_l, out);
    out << ", ";
  }

  // member: offset_y_l
  {
    out << "offset_y_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y_l, out);
    out << ", ";
  }

  // member: offset_z_l
  {
    out << "offset_z_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z_l, out);
    out << ", ";
  }

  // member: target_r
  {
    out << "target_r: ";
    to_flow_style_yaml(msg.target_r, out);
    out << ", ";
  }

  // member: from_frame_r
  {
    out << "from_frame_r: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame_r, out);
    out << ", ";
  }

  // member: to_frame_r
  {
    out << "to_frame_r: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame_r, out);
    out << ", ";
  }

  // member: offset_x_r
  {
    out << "offset_x_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x_r, out);
    out << ", ";
  }

  // member: offset_y_r
  {
    out << "offset_y_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y_r, out);
    out << ", ";
  }

  // member: offset_z_r
  {
    out << "offset_z_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z_r, out);
    out << ", ";
  }

  // member: is_dual_arm_syn
  {
    out << "is_dual_arm_syn: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dual_arm_syn, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DualArmTargetPose & msg,
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

  // member: target_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_l:\n";
    to_block_style_yaml(msg.target_l, out, indentation + 2);
  }

  // member: from_frame_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_frame_l: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame_l, out);
    out << "\n";
  }

  // member: to_frame_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to_frame_l: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame_l, out);
    out << "\n";
  }

  // member: offset_x_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_x_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x_l, out);
    out << "\n";
  }

  // member: offset_y_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_y_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y_l, out);
    out << "\n";
  }

  // member: offset_z_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_z_l: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z_l, out);
    out << "\n";
  }

  // member: target_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_r:\n";
    to_block_style_yaml(msg.target_r, out, indentation + 2);
  }

  // member: from_frame_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_frame_r: ";
    rosidl_generator_traits::value_to_yaml(msg.from_frame_r, out);
    out << "\n";
  }

  // member: to_frame_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to_frame_r: ";
    rosidl_generator_traits::value_to_yaml(msg.to_frame_r, out);
    out << "\n";
  }

  // member: offset_x_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_x_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_x_r, out);
    out << "\n";
  }

  // member: offset_y_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_y_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_y_r, out);
    out << "\n";
  }

  // member: offset_z_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_z_r: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_z_r, out);
    out << "\n";
  }

  // member: is_dual_arm_syn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_dual_arm_syn: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dual_arm_syn, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DualArmTargetPose & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::msg::DualArmTargetPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::msg::DualArmTargetPose & msg)
{
  return eai_manipulator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::msg::DualArmTargetPose>()
{
  return "eai_manipulator_msgs::msg::DualArmTargetPose";
}

template<>
inline const char * name<eai_manipulator_msgs::msg::DualArmTargetPose>()
{
  return "eai_manipulator_msgs/msg/DualArmTargetPose";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::msg::DualArmTargetPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::msg::DualArmTargetPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::msg::DualArmTargetPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__TRAITS_HPP_
