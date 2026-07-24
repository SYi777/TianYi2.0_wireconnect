// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:srv/CommonStreamRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__TRAITS_HPP_
#define CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/srv/detail/common_stream_ros2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CommonStreamRos2_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_id
  {
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
    out << ", ";
  }

  // member: json_data
  {
    out << "json_data: ";
    rosidl_generator_traits::value_to_yaml(msg.json_data, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
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
  const CommonStreamRos2_Request & msg,
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

  // member: json_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "json_data: ";
    rosidl_generator_traits::value_to_yaml(msg.json_data, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const CommonStreamRos2_Request & msg, bool use_flow_style = false)
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

}  // namespace cm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cm_msgs::srv::CommonStreamRos2_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::srv::CommonStreamRos2_Request & msg)
{
  return cm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::srv::CommonStreamRos2_Request>()
{
  return "cm_msgs::srv::CommonStreamRos2_Request";
}

template<>
inline const char * name<cm_msgs::srv::CommonStreamRos2_Request>()
{
  return "cm_msgs/srv/CommonStreamRos2_Request";
}

template<>
struct has_fixed_size<cm_msgs::srv::CommonStreamRos2_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cm_msgs::srv::CommonStreamRos2_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cm_msgs::srv::CommonStreamRos2_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CommonStreamRos2_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
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
  const CommonStreamRos2_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
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

inline std::string to_yaml(const CommonStreamRos2_Response & msg, bool use_flow_style = false)
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

}  // namespace cm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cm_msgs::srv::CommonStreamRos2_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::srv::CommonStreamRos2_Response & msg)
{
  return cm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::srv::CommonStreamRos2_Response>()
{
  return "cm_msgs::srv::CommonStreamRos2_Response";
}

template<>
inline const char * name<cm_msgs::srv::CommonStreamRos2_Response>()
{
  return "cm_msgs/srv/CommonStreamRos2_Response";
}

template<>
struct has_fixed_size<cm_msgs::srv::CommonStreamRos2_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cm_msgs::srv::CommonStreamRos2_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cm_msgs::srv::CommonStreamRos2_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cm_msgs::srv::CommonStreamRos2>()
{
  return "cm_msgs::srv::CommonStreamRos2";
}

template<>
inline const char * name<cm_msgs::srv::CommonStreamRos2>()
{
  return "cm_msgs/srv/CommonStreamRos2";
}

template<>
struct has_fixed_size<cm_msgs::srv::CommonStreamRos2>
  : std::integral_constant<
    bool,
    has_fixed_size<cm_msgs::srv::CommonStreamRos2_Request>::value &&
    has_fixed_size<cm_msgs::srv::CommonStreamRos2_Response>::value
  >
{
};

template<>
struct has_bounded_size<cm_msgs::srv::CommonStreamRos2>
  : std::integral_constant<
    bool,
    has_bounded_size<cm_msgs::srv::CommonStreamRos2_Request>::value &&
    has_bounded_size<cm_msgs::srv::CommonStreamRos2_Response>::value
  >
{
};

template<>
struct is_service<cm_msgs::srv::CommonStreamRos2>
  : std::true_type
{
};

template<>
struct is_service_request<cm_msgs::srv::CommonStreamRos2_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cm_msgs::srv::CommonStreamRos2_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__TRAITS_HPP_
