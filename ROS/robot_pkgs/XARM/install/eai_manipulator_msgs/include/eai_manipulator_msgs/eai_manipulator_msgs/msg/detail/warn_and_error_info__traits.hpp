// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace eai_manipulator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WarnAndErrorInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: level
  {
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
    out << ", ";
  }

  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: source
  {
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << ", ";
  }

  // member: info
  {
    out << "info: ";
    rosidl_generator_traits::value_to_yaml(msg.info, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WarnAndErrorInfo & msg,
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

  // member: level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
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

  // member: source
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << "\n";
  }

  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info: ";
    rosidl_generator_traits::value_to_yaml(msg.info, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WarnAndErrorInfo & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::msg::WarnAndErrorInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::msg::WarnAndErrorInfo & msg)
{
  return eai_manipulator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::msg::WarnAndErrorInfo>()
{
  return "eai_manipulator_msgs::msg::WarnAndErrorInfo";
}

template<>
inline const char * name<eai_manipulator_msgs::msg::WarnAndErrorInfo>()
{
  return "eai_manipulator_msgs/msg/WarnAndErrorInfo";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::msg::WarnAndErrorInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::msg::WarnAndErrorInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::msg::WarnAndErrorInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__TRAITS_HPP_
