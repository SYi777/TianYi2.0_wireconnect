// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cloud_service:srv/Register.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REGISTER__TRAITS_HPP_
#define CLOUD_SERVICE__SRV__DETAIL__REGISTER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cloud_service/srv/detail/register__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cloud_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const Register_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_id
  {
    out << "cmd_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_id, out);
    out << ", ";
  }

  // member: handler_service_name
  {
    out << "handler_service_name: ";
    rosidl_generator_traits::value_to_yaml(msg.handler_service_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Register_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_id, out);
    out << "\n";
  }

  // member: handler_service_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "handler_service_name: ";
    rosidl_generator_traits::value_to_yaml(msg.handler_service_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Register_Request & msg, bool use_flow_style = false)
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
  const cloud_service::srv::Register_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::srv::Register_Request & msg)
{
  return cloud_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::srv::Register_Request>()
{
  return "cloud_service::srv::Register_Request";
}

template<>
inline const char * name<cloud_service::srv::Register_Request>()
{
  return "cloud_service/srv/Register_Request";
}

template<>
struct has_fixed_size<cloud_service::srv::Register_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::srv::Register_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::srv::Register_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cloud_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const Register_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Register_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Register_Response & msg, bool use_flow_style = false)
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
  const cloud_service::srv::Register_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::srv::Register_Response & msg)
{
  return cloud_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::srv::Register_Response>()
{
  return "cloud_service::srv::Register_Response";
}

template<>
inline const char * name<cloud_service::srv::Register_Response>()
{
  return "cloud_service/srv/Register_Response";
}

template<>
struct has_fixed_size<cloud_service::srv::Register_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cloud_service::srv::Register_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cloud_service::srv::Register_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cloud_service::srv::Register>()
{
  return "cloud_service::srv::Register";
}

template<>
inline const char * name<cloud_service::srv::Register>()
{
  return "cloud_service/srv/Register";
}

template<>
struct has_fixed_size<cloud_service::srv::Register>
  : std::integral_constant<
    bool,
    has_fixed_size<cloud_service::srv::Register_Request>::value &&
    has_fixed_size<cloud_service::srv::Register_Response>::value
  >
{
};

template<>
struct has_bounded_size<cloud_service::srv::Register>
  : std::integral_constant<
    bool,
    has_bounded_size<cloud_service::srv::Register_Request>::value &&
    has_bounded_size<cloud_service::srv::Register_Response>::value
  >
{
};

template<>
struct is_service<cloud_service::srv::Register>
  : std::true_type
{
};

template<>
struct is_service_request<cloud_service::srv::Register_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cloud_service::srv::Register_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CLOUD_SERVICE__SRV__DETAIL__REGISTER__TRAITS_HPP_
