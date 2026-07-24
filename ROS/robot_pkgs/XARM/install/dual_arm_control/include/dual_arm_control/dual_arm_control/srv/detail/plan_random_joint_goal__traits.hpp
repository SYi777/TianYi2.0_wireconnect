// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#ifndef DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__TRAITS_HPP_
#define DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dual_arm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const PlanRandomJointGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: group_name
  {
    out << "group_name: ";
    rosidl_generator_traits::value_to_yaml(msg.group_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlanRandomJointGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: group_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "group_name: ";
    rosidl_generator_traits::value_to_yaml(msg.group_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlanRandomJointGoal_Request & msg, bool use_flow_style = false)
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

}  // namespace dual_arm_control

namespace rosidl_generator_traits
{

[[deprecated("use dual_arm_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dual_arm_control::srv::PlanRandomJointGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dual_arm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dual_arm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const dual_arm_control::srv::PlanRandomJointGoal_Request & msg)
{
  return dual_arm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dual_arm_control::srv::PlanRandomJointGoal_Request>()
{
  return "dual_arm_control::srv::PlanRandomJointGoal_Request";
}

template<>
inline const char * name<dual_arm_control::srv::PlanRandomJointGoal_Request>()
{
  return "dual_arm_control/srv/PlanRandomJointGoal_Request";
}

template<>
struct has_fixed_size<dual_arm_control::srv::PlanRandomJointGoal_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dual_arm_control::srv::PlanRandomJointGoal_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dual_arm_control::srv::PlanRandomJointGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"

namespace dual_arm_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const PlanRandomJointGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: joint_values
  {
    if (msg.joint_values.size() == 0) {
      out << "joint_values: []";
    } else {
      out << "joint_values: [";
      size_t pending_items = msg.joint_values.size();
      for (auto item : msg.joint_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
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
  const PlanRandomJointGoal_Response & msg,
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

  // member: joint_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_values.size() == 0) {
      out << "joint_values: []\n";
    } else {
      out << "joint_values:\n";
      for (auto item : msg.joint_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
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

inline std::string to_yaml(const PlanRandomJointGoal_Response & msg, bool use_flow_style = false)
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

}  // namespace dual_arm_control

namespace rosidl_generator_traits
{

[[deprecated("use dual_arm_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dual_arm_control::srv::PlanRandomJointGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dual_arm_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dual_arm_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const dual_arm_control::srv::PlanRandomJointGoal_Response & msg)
{
  return dual_arm_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dual_arm_control::srv::PlanRandomJointGoal_Response>()
{
  return "dual_arm_control::srv::PlanRandomJointGoal_Response";
}

template<>
inline const char * name<dual_arm_control::srv::PlanRandomJointGoal_Response>()
{
  return "dual_arm_control/srv/PlanRandomJointGoal_Response";
}

template<>
struct has_fixed_size<dual_arm_control::srv::PlanRandomJointGoal_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dual_arm_control::srv::PlanRandomJointGoal_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dual_arm_control::srv::PlanRandomJointGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dual_arm_control::srv::PlanRandomJointGoal>()
{
  return "dual_arm_control::srv::PlanRandomJointGoal";
}

template<>
inline const char * name<dual_arm_control::srv::PlanRandomJointGoal>()
{
  return "dual_arm_control/srv/PlanRandomJointGoal";
}

template<>
struct has_fixed_size<dual_arm_control::srv::PlanRandomJointGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<dual_arm_control::srv::PlanRandomJointGoal_Request>::value &&
    has_fixed_size<dual_arm_control::srv::PlanRandomJointGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<dual_arm_control::srv::PlanRandomJointGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<dual_arm_control::srv::PlanRandomJointGoal_Request>::value &&
    has_bounded_size<dual_arm_control::srv::PlanRandomJointGoal_Response>::value
  >
{
};

template<>
struct is_service<dual_arm_control::srv::PlanRandomJointGoal>
  : std::true_type
{
};

template<>
struct is_service_request<dual_arm_control::srv::PlanRandomJointGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dual_arm_control::srv::PlanRandomJointGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__TRAITS_HPP_
