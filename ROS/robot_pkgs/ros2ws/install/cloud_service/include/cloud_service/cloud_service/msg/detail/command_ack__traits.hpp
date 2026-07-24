// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__TRAITS_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cloud_service/msg/detail/command_ack__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cloud_service
{

namespace msg
{

inline void to_flow_style_yaml(
  const CommandAck & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_id
  {
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
    out << ", ";
  }

  // member: cmd_id
  {
    out << "cmd_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_id, out);
    out << ", ";
  }

  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CommandAck & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
    out << "\n";
  }

  // member: cmd_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_id, out);
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CommandAck & msg, bool use_flow_style = false)
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
  const cloud_service::msg::CommandAck & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::msg::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::msg::CommandAck & msg)
{
  return cloud_service::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::msg::CommandAck>()
{
  return "cloud_service::msg::CommandAck";
}

template<>
inline const char * name<cloud_service::msg::CommandAck>()
{
  return "cloud_service/msg/CommandAck";
}

template<>
struct has_fixed_size<cloud_service::msg::CommandAck>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::msg::CommandAck>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::msg::CommandAck>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__TRAITS_HPP_
