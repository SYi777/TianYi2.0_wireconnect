// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cloud_service:srv/RemoteCtrl.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__TRAITS_HPP_
#define CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cloud_service/srv/detail/remote_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cloud_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const RemoteCtrl_Request & msg,
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

  // member: payload
  {
    out << "payload: ";
    rosidl_generator_traits::value_to_yaml(msg.payload, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RemoteCtrl_Request & msg,
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

  // member: payload
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "payload: ";
    rosidl_generator_traits::value_to_yaml(msg.payload, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RemoteCtrl_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cloud_service

namespace rosidl_generator_traits
{

[[deprecated("use cloud_service::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cloud_service::srv::RemoteCtrl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::srv::RemoteCtrl_Request & msg)
{
  return cloud_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::srv::RemoteCtrl_Request>()
{
  return "cloud_service::srv::RemoteCtrl_Request";
}

template<>
inline const char * name<cloud_service::srv::RemoteCtrl_Request>()
{
  return "cloud_service/srv/RemoteCtrl_Request";
}

template<>
struct has_fixed_size<cloud_service::srv::RemoteCtrl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::srv::RemoteCtrl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::srv::RemoteCtrl_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cloud_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const RemoteCtrl_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  const RemoteCtrl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const RemoteCtrl_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cloud_service

namespace rosidl_generator_traits
{

[[deprecated("use cloud_service::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cloud_service::srv::RemoteCtrl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::srv::RemoteCtrl_Response & msg)
{
  return cloud_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::srv::RemoteCtrl_Response>()
{
  return "cloud_service::srv::RemoteCtrl_Response";
}

template<>
inline const char * name<cloud_service::srv::RemoteCtrl_Response>()
{
  return "cloud_service/srv/RemoteCtrl_Response";
}

template<>
struct has_fixed_size<cloud_service::srv::RemoteCtrl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::srv::RemoteCtrl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::srv::RemoteCtrl_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cloud_service::srv::RemoteCtrl>()
{
  return "cloud_service::srv::RemoteCtrl";
}

template<>
inline const char * name<cloud_service::srv::RemoteCtrl>()
{
  return "cloud_service/srv/RemoteCtrl";
}

template<>
struct has_fixed_size<cloud_service::srv::RemoteCtrl>
  : std::integral_constant<
    bool,
    has_fixed_size<cloud_service::srv::RemoteCtrl_Request>::value &&
    has_fixed_size<cloud_service::srv::RemoteCtrl_Response>::value
  >
{
};

template<>
struct has_bounded_size<cloud_service::srv::RemoteCtrl>
  : std::integral_constant<
    bool,
    has_bounded_size<cloud_service::srv::RemoteCtrl_Request>::value &&
    has_bounded_size<cloud_service::srv::RemoteCtrl_Response>::value
  >
{
};

template<>
struct is_service<cloud_service::srv::RemoteCtrl>
  : std::true_type
{
};

template<>
struct is_service_request<cloud_service::srv::RemoteCtrl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cloud_service::srv::RemoteCtrl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__TRAITS_HPP_
