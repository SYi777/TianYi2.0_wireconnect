// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define CM_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: head_pose
  {
    if (msg.head_pose.size() == 0) {
      out << "head_pose: []";
    } else {
      out << "head_pose: [";
      size_t pending_items = msg.head_pose.size();
      for (auto item : msg.head_pose) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
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

  // member: head_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.head_pose.size() == 0) {
      out << "head_pose: []\n";
    } else {
      out << "head_pose:\n";
      for (auto item : msg.head_pose) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
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
  const cm_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::msg::RobotState & msg)
{
  return cm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::msg::RobotState>()
{
  return "cm_msgs::msg::RobotState";
}

template<>
inline const char * name<cm_msgs::msg::RobotState>()
{
  return "cm_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<cm_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cm_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cm_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
