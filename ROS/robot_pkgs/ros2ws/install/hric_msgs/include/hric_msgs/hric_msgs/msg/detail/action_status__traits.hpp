// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/ActionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/action_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ActionStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: motion_number
  {
    out << "motion_number: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_number, out);
    out << ", ";
  }

  // member: is_motion
  {
    out << "is_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ActionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motion_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motion_number: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_number, out);
    out << "\n";
  }

  // member: is_motion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motion, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ActionStatus & msg, bool use_flow_style = false)
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

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::msg::ActionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::ActionStatus & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::ActionStatus>()
{
  return "hric_msgs::msg::ActionStatus";
}

template<>
inline const char * name<hric_msgs::msg::ActionStatus>()
{
  return "hric_msgs/msg/ActionStatus";
}

template<>
struct has_fixed_size<hric_msgs::msg::ActionStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::msg::ActionStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::msg::ActionStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__TRAITS_HPP_
