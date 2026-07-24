// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/SetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/set_vel_limit__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetVelLimit & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_vel_limit_walk
  {
    out << "x_vel_limit_walk: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_walk, out);
    out << ", ";
  }

  // member: x_vel_limit_run
  {
    out << "x_vel_limit_run: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_run, out);
    out << ", ";
  }

  // member: x_vel_limit_halfwalk
  {
    out << "x_vel_limit_halfwalk: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_halfwalk, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVelLimit & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_vel_limit_walk
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_vel_limit_walk: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_walk, out);
    out << "\n";
  }

  // member: x_vel_limit_run
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_vel_limit_run: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_run, out);
    out << "\n";
  }

  // member: x_vel_limit_halfwalk
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_vel_limit_halfwalk: ";
    rosidl_generator_traits::value_to_yaml(msg.x_vel_limit_halfwalk, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVelLimit & msg, bool use_flow_style = false)
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
  const hric_msgs::msg::SetVelLimit & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::SetVelLimit & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::SetVelLimit>()
{
  return "hric_msgs::msg::SetVelLimit";
}

template<>
inline const char * name<hric_msgs::msg::SetVelLimit>()
{
  return "hric_msgs/msg/SetVelLimit";
}

template<>
struct has_fixed_size<hric_msgs::msg::SetVelLimit>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::msg::SetVelLimit>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::msg::SetVelLimit>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__SET_VEL_LIMIT__TRAITS_HPP_
