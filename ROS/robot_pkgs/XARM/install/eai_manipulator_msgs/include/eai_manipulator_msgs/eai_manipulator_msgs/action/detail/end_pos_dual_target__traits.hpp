// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:action/EndPosDualTarget.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/action/detail/end_pos_dual_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target'
#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_Goal & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_Goal>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_Goal";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_Goal>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_Goal";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Goal>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::msg::DualArmTargetPose>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Goal>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::msg::DualArmTargetPose>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: result_msg
  {
    out << "result_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.result_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_Result & msg,
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

  // member: result_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.result_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_Result & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_Result>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_Result";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_Result>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_Result";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_err
  {
    if (msg.current_err.size() == 0) {
      out << "current_err: []";
    } else {
      out << "current_err: [";
      size_t pending_items = msg.current_err.size();
      for (auto item : msg.current_err) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: feedback_msg
  {
    out << "feedback_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_err.size() == 0) {
      out << "current_err: []\n";
    } else {
      out << "current_err:\n";
      for (auto item : msg.current_err) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: feedback_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_Feedback & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_Feedback";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_Feedback";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "eai_manipulator_msgs/action/detail/end_pos_dual_target__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_SendGoal_Request";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_SendGoal_Response";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_SendGoal";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_SendGoal";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>::value &&
    has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>::value &&
    has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_GetResult_Request";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "eai_manipulator_msgs/action/detail/end_pos_dual_target__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_GetResult_Response";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Result>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Result>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_GetResult>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_GetResult";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_GetResult>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_GetResult";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>::value &&
    has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>::value &&
    has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>::value
  >
{
};

template<>
struct is_service<eai_manipulator_msgs::action::EndPosDualTarget_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "eai_manipulator_msgs/action/detail/end_pos_dual_target__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const EndPosDualTarget_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EndPosDualTarget_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EndPosDualTarget_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use eai_manipulator_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>()
{
  return "eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage";
}

template<>
inline const char * name<eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>()
{
  return "eai_manipulator_msgs/action/EndPosDualTarget_FeedbackMessage";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<eai_manipulator_msgs::action::EndPosDualTarget>
  : std::true_type
{
};

template<>
struct is_action_goal<eai_manipulator_msgs::action::EndPosDualTarget_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<eai_manipulator_msgs::action::EndPosDualTarget_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<eai_manipulator_msgs::action::EndPosDualTarget_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__TRAITS_HPP_
