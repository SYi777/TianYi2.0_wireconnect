// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:srv/Info.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/srv/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace eai_manipulator_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Info_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Info_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Info_Request & msg, bool use_flow_style = false)
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

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::srv::Info_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::srv::Info_Request & msg)
{
  return eai_manipulator_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::srv::Info_Request>()
{
  return "eai_manipulator_msgs::srv::Info_Request";
}

template<>
inline const char * name<eai_manipulator_msgs::srv::Info_Request>()
{
  return "eai_manipulator_msgs/srv/Info_Request";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::srv::Info_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::srv::Info_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<eai_manipulator_msgs::srv::Info_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace eai_manipulator_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Info_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    rosidl_generator_traits::value_to_yaml(msg.info, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Info_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const Info_Response & msg, bool use_flow_style = false)
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

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::srv::Info_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::srv::Info_Response & msg)
{
  return eai_manipulator_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::srv::Info_Response>()
{
  return "eai_manipulator_msgs::srv::Info_Response";
}

template<>
inline const char * name<eai_manipulator_msgs::srv::Info_Response>()
{
  return "eai_manipulator_msgs/srv/Info_Response";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::srv::Info_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::srv::Info_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::srv::Info_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<eai_manipulator_msgs::srv::Info>()
{
  return "eai_manipulator_msgs::srv::Info";
}

template<>
inline const char * name<eai_manipulator_msgs::srv::Info>()
{
  return "eai_manipulator_msgs/srv/Info";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::srv::Info>
  : std::integral_constant<
    bool,
    has_fixed_size<eai_manipulator_msgs::srv::Info_Request>::value &&
    has_fixed_size<eai_manipulator_msgs::srv::Info_Response>::value
  >
{
};

template<>
struct has_bounded_size<eai_manipulator_msgs::srv::Info>
  : std::integral_constant<
    bool,
    has_bounded_size<eai_manipulator_msgs::srv::Info_Request>::value &&
    has_bounded_size<eai_manipulator_msgs::srv::Info_Response>::value
  >
{
};

template<>
struct is_service<eai_manipulator_msgs::srv::Info>
  : std::true_type
{
};

template<>
struct is_service_request<eai_manipulator_msgs::srv::Info_Request>
  : std::true_type
{
};

template<>
struct is_service_response<eai_manipulator_msgs::srv::Info_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__TRAITS_HPP_
