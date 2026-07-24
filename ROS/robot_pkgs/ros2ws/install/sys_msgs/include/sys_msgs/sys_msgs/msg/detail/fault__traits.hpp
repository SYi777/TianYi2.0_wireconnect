// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT__TRAITS_HPP_
#define SYS_MSGS__MSG__DETAIL__FAULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sys_msgs/msg/detail/fault__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Fault & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_stamp_ms
  {
    out << "time_stamp_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_stamp_ms, out);
    out << ", ";
  }

  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Fault & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time_stamp_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_stamp_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_stamp_ms, out);
    out << "\n";
  }

  // member: code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Fault & msg, bool use_flow_style = false)
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

}  // namespace sys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sys_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sys_msgs::msg::Fault & msg,
  std::ostream & out, size_t indentation = 0)
{
  sys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const sys_msgs::msg::Fault & msg)
{
  return sys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sys_msgs::msg::Fault>()
{
  return "sys_msgs::msg::Fault";
}

template<>
inline const char * name<sys_msgs::msg::Fault>()
{
  return "sys_msgs/msg/Fault";
}

template<>
struct has_fixed_size<sys_msgs::msg::Fault>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sys_msgs::msg::Fault>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sys_msgs::msg::Fault>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SYS_MSGS__MSG__DETAIL__FAULT__TRAITS_HPP_
