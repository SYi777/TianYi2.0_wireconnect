// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__TRAITS_HPP_
#define CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/msg/detail/pose_action_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PoseActionStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: resp_frame_id
  {
    out << "resp_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.resp_frame_id, out);
    out << ", ";
  }

  // member: hand_move_success
  {
    out << "hand_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_move_success, out);
    out << ", ";
  }

  // member: head_move_success
  {
    out << "head_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.head_move_success, out);
    out << ", ";
  }

  // member: gripper_move_success
  {
    out << "gripper_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_move_success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseActionStatus & msg,
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

  // member: resp_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resp_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.resp_frame_id, out);
    out << "\n";
  }

  // member: hand_move_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_move_success, out);
    out << "\n";
  }

  // member: head_move_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.head_move_success, out);
    out << "\n";
  }

  // member: gripper_move_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_move_success: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_move_success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseActionStatus & msg, bool use_flow_style = false)
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

}  // namespace cm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cm_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cm_msgs::msg::PoseActionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::msg::PoseActionStatus & msg)
{
  return cm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::msg::PoseActionStatus>()
{
  return "cm_msgs::msg::PoseActionStatus";
}

template<>
inline const char * name<cm_msgs::msg::PoseActionStatus>()
{
  return "cm_msgs/msg/PoseActionStatus";
}

template<>
struct has_fixed_size<cm_msgs::msg::PoseActionStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cm_msgs::msg::PoseActionStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cm_msgs::msg::PoseActionStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__TRAITS_HPP_
