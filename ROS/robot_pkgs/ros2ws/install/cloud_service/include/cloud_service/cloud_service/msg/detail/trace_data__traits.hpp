// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cloud_service:msg/TraceData.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__TRAITS_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cloud_service/msg/detail/trace_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cloud_service
{

namespace msg
{

inline void to_flow_style_yaml(
  const TraceData & msg,
  std::ostream & out)
{
  out << "{";
  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: data_type
  {
    out << "data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.data_type, out);
    out << ", ";
  }

  // member: int_val
  {
    out << "int_val: ";
    rosidl_generator_traits::value_to_yaml(msg.int_val, out);
    out << ", ";
  }

  // member: str_val
  {
    out << "str_val: ";
    rosidl_generator_traits::value_to_yaml(msg.str_val, out);
    out << ", ";
  }

  // member: bool_val
  {
    out << "bool_val: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_val, out);
    out << ", ";
  }

  // member: double_val
  {
    out << "double_val: ";
    rosidl_generator_traits::value_to_yaml(msg.double_val, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TraceData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << "\n";
  }

  // member: data_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.data_type, out);
    out << "\n";
  }

  // member: int_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int_val: ";
    rosidl_generator_traits::value_to_yaml(msg.int_val, out);
    out << "\n";
  }

  // member: str_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "str_val: ";
    rosidl_generator_traits::value_to_yaml(msg.str_val, out);
    out << "\n";
  }

  // member: bool_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bool_val: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_val, out);
    out << "\n";
  }

  // member: double_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "double_val: ";
    rosidl_generator_traits::value_to_yaml(msg.double_val, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TraceData & msg, bool use_flow_style = false)
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

}  // namespace cloud_service

namespace rosidl_generator_traits
{

[[deprecated("use cloud_service::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cloud_service::msg::TraceData & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::msg::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::msg::TraceData & msg)
{
  return cloud_service::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::msg::TraceData>()
{
  return "cloud_service::msg::TraceData";
}

template<>
inline const char * name<cloud_service::msg::TraceData>()
{
  return "cloud_service/msg/TraceData";
}

template<>
struct has_fixed_size<cloud_service::msg::TraceData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::msg::TraceData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::msg::TraceData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__TRAITS_HPP_
