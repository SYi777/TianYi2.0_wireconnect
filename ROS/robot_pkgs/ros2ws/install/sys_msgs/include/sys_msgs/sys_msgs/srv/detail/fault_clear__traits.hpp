// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sys_msgs:srv/FaultClear.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__TRAITS_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sys_msgs/srv/detail/fault_clear__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FaultClear_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: fault_array
  {
    if (msg.fault_array.size() == 0) {
      out << "fault_array: []";
    } else {
      out << "fault_array: [";
      size_t pending_items = msg.fault_array.size();
      for (auto item : msg.fault_array) {
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
  const FaultClear_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fault_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.fault_array.size() == 0) {
      out << "fault_array: []\n";
    } else {
      out << "fault_array:\n";
      for (auto item : msg.fault_array) {
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

inline std::string to_yaml(const FaultClear_Request & msg, bool use_flow_style = false)
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

}  // namespace sys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sys_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sys_msgs::srv::FaultClear_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const sys_msgs::srv::FaultClear_Request & msg)
{
  return sys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sys_msgs::srv::FaultClear_Request>()
{
  return "sys_msgs::srv::FaultClear_Request";
}

template<>
inline const char * name<sys_msgs::srv::FaultClear_Request>()
{
  return "sys_msgs/srv/FaultClear_Request";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultClear_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sys_msgs::srv::FaultClear_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sys_msgs::srv::FaultClear_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FaultClear_Response & msg,
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
  const FaultClear_Response & msg,
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

inline std::string to_yaml(const FaultClear_Response & msg, bool use_flow_style = false)
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

}  // namespace sys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sys_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sys_msgs::srv::FaultClear_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const sys_msgs::srv::FaultClear_Response & msg)
{
  return sys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sys_msgs::srv::FaultClear_Response>()
{
  return "sys_msgs::srv::FaultClear_Response";
}

template<>
inline const char * name<sys_msgs::srv::FaultClear_Response>()
{
  return "sys_msgs/srv/FaultClear_Response";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultClear_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sys_msgs::srv::FaultClear_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sys_msgs::srv::FaultClear_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sys_msgs::srv::FaultClear>()
{
  return "sys_msgs::srv::FaultClear";
}

template<>
inline const char * name<sys_msgs::srv::FaultClear>()
{
  return "sys_msgs/srv/FaultClear";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultClear>
  : std::integral_constant<
    bool,
    has_fixed_size<sys_msgs::srv::FaultClear_Request>::value &&
    has_fixed_size<sys_msgs::srv::FaultClear_Response>::value
  >
{
};

template<>
struct has_bounded_size<sys_msgs::srv::FaultClear>
  : std::integral_constant<
    bool,
    has_bounded_size<sys_msgs::srv::FaultClear_Request>::value &&
    has_bounded_size<sys_msgs::srv::FaultClear_Response>::value
  >
{
};

template<>
struct is_service<sys_msgs::srv::FaultClear>
  : std::true_type
{
};

template<>
struct is_service_request<sys_msgs::srv::FaultClear_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sys_msgs::srv::FaultClear_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__TRAITS_HPP_
