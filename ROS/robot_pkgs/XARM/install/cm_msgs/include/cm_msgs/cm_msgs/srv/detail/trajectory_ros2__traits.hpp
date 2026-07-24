// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:srv/TrajectoryRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__TRAITS_HPP_
#define CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/srv/detail/trajectory_ros2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"

namespace cm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TrajectoryRos2_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_id
  {
    out << "msg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_id, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryRos2_Request & msg,
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

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryRos2_Request & msg, bool use_flow_style = false)
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
  const cm_msgs::srv::TrajectoryRos2_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::srv::TrajectoryRos2_Request & msg)
{
  return cm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::srv::TrajectoryRos2_Request>()
{
  return "cm_msgs::srv::TrajectoryRos2_Request";
}

template<>
inline const char * name<cm_msgs::srv::TrajectoryRos2_Request>()
{
  return "cm_msgs/srv/TrajectoryRos2_Request";
}

template<>
struct has_fixed_size<cm_msgs::srv::TrajectoryRos2_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cm_msgs::srv::TrajectoryRos2_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cm_msgs::srv::TrajectoryRos2_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TrajectoryRos2_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryRos2_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryRos2_Response & msg, bool use_flow_style = false)
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
  const cm_msgs::srv::TrajectoryRos2_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::srv::TrajectoryRos2_Response & msg)
{
  return cm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::srv::TrajectoryRos2_Response>()
{
  return "cm_msgs::srv::TrajectoryRos2_Response";
}

template<>
inline const char * name<cm_msgs::srv::TrajectoryRos2_Response>()
{
  return "cm_msgs/srv/TrajectoryRos2_Response";
}

template<>
struct has_fixed_size<cm_msgs::srv::TrajectoryRos2_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cm_msgs::srv::TrajectoryRos2_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cm_msgs::srv::TrajectoryRos2_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cm_msgs::srv::TrajectoryRos2>()
{
  return "cm_msgs::srv::TrajectoryRos2";
}

template<>
inline const char * name<cm_msgs::srv::TrajectoryRos2>()
{
  return "cm_msgs/srv/TrajectoryRos2";
}

template<>
struct has_fixed_size<cm_msgs::srv::TrajectoryRos2>
  : std::integral_constant<
    bool,
    has_fixed_size<cm_msgs::srv::TrajectoryRos2_Request>::value &&
    has_fixed_size<cm_msgs::srv::TrajectoryRos2_Response>::value
  >
{
};

template<>
struct has_bounded_size<cm_msgs::srv::TrajectoryRos2>
  : std::integral_constant<
    bool,
    has_bounded_size<cm_msgs::srv::TrajectoryRos2_Request>::value &&
    has_bounded_size<cm_msgs::srv::TrajectoryRos2_Response>::value
  >
{
};

template<>
struct is_service<cm_msgs::srv::TrajectoryRos2>
  : std::true_type
{
};

template<>
struct is_service_request<cm_msgs::srv::TrajectoryRos2_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cm_msgs::srv::TrajectoryRos2_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__TRAITS_HPP_
