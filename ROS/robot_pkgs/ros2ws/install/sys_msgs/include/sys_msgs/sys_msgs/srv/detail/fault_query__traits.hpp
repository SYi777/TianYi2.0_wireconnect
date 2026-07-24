// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sys_msgs:srv/FaultQuery.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_QUERY__TRAITS_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_QUERY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sys_msgs/srv/detail/fault_query__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FaultQuery_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FaultQuery_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FaultQuery_Request & msg, bool use_flow_style = false)
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
  const sys_msgs::srv::FaultQuery_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const sys_msgs::srv::FaultQuery_Request & msg)
{
  return sys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sys_msgs::srv::FaultQuery_Request>()
{
  return "sys_msgs::srv::FaultQuery_Request";
}

template<>
inline const char * name<sys_msgs::srv::FaultQuery_Request>()
{
  return "sys_msgs/srv/FaultQuery_Request";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultQuery_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sys_msgs::srv::FaultQuery_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sys_msgs::srv::FaultQuery_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'fault_array'
#include "sys_msgs/msg/detail/fault__traits.hpp"

namespace sys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FaultQuery_Response & msg,
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
        to_flow_style_yaml(item, out);
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
  const FaultQuery_Response & msg,
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
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FaultQuery_Response & msg, bool use_flow_style = false)
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
  const sys_msgs::srv::FaultQuery_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const sys_msgs::srv::FaultQuery_Response & msg)
{
  return sys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sys_msgs::srv::FaultQuery_Response>()
{
  return "sys_msgs::srv::FaultQuery_Response";
}

template<>
inline const char * name<sys_msgs::srv::FaultQuery_Response>()
{
  return "sys_msgs/srv/FaultQuery_Response";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultQuery_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sys_msgs::srv::FaultQuery_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sys_msgs::srv::FaultQuery_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sys_msgs::srv::FaultQuery>()
{
  return "sys_msgs::srv::FaultQuery";
}

template<>
inline const char * name<sys_msgs::srv::FaultQuery>()
{
  return "sys_msgs/srv/FaultQuery";
}

template<>
struct has_fixed_size<sys_msgs::srv::FaultQuery>
  : std::integral_constant<
    bool,
    has_fixed_size<sys_msgs::srv::FaultQuery_Request>::value &&
    has_fixed_size<sys_msgs::srv::FaultQuery_Response>::value
  >
{
};

template<>
struct has_bounded_size<sys_msgs::srv::FaultQuery>
  : std::integral_constant<
    bool,
    has_bounded_size<sys_msgs::srv::FaultQuery_Request>::value &&
    has_bounded_size<sys_msgs::srv::FaultQuery_Response>::value
  >
{
};

template<>
struct is_service<sys_msgs::srv::FaultQuery>
  : std::true_type
{
};

template<>
struct is_service_request<sys_msgs::srv::FaultQuery_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sys_msgs::srv::FaultQuery_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_QUERY__TRAITS_HPP_
