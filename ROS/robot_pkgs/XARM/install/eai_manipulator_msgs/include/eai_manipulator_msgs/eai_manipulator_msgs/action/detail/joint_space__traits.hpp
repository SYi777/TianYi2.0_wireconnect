// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from eai_manipulator_msgs:action/JointSpace.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__TRAITS_HPP_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "eai_manipulator_msgs/action/detail/joint_space__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_positions
  {
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []";
    } else {
      out << "target_positions: [";
      size_t pending_items = msg.target_positions.size();
      for (auto item : msg.target_positions) {
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
  const JointSpace_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []\n";
    } else {
      out << "target_positions:\n";
      for (auto item : msg.target_positions) {
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

inline std::string to_yaml(const JointSpace_Goal & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_Goal & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_Goal>()
{
  return "eai_manipulator_msgs::action::JointSpace_Goal";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_Goal>()
{
  return "eai_manipulator_msgs/action/JointSpace_Goal";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_Result & msg,
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
  const JointSpace_Result & msg,
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

inline std::string to_yaml(const JointSpace_Result & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_Result & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_Result>()
{
  return "eai_manipulator_msgs::action::JointSpace_Result";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_Result>()
{
  return "eai_manipulator_msgs/action/JointSpace_Result";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_positions
  {
    if (msg.current_positions.size() == 0) {
      out << "current_positions: []";
    } else {
      out << "current_positions: [";
      size_t pending_items = msg.current_positions.size();
      for (auto item : msg.current_positions) {
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
  const JointSpace_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_positions.size() == 0) {
      out << "current_positions: []\n";
    } else {
      out << "current_positions:\n";
      for (auto item : msg.current_positions) {
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

inline std::string to_yaml(const JointSpace_Feedback & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_Feedback & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_Feedback>()
{
  return "eai_manipulator_msgs::action::JointSpace_Feedback";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_Feedback>()
{
  return "eai_manipulator_msgs/action/JointSpace_Feedback";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "eai_manipulator_msgs/action/detail/joint_space__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_SendGoal_Request & msg,
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
  const JointSpace_SendGoal_Request & msg,
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

inline std::string to_yaml(const JointSpace_SendGoal_Request & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_SendGoal_Request & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>()
{
  return "eai_manipulator_msgs::action::JointSpace_SendGoal_Request";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>()
{
  return "eai_manipulator_msgs/action/JointSpace_SendGoal_Request";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::JointSpace_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::JointSpace_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>
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
  const JointSpace_SendGoal_Response & msg,
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
  const JointSpace_SendGoal_Response & msg,
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

inline std::string to_yaml(const JointSpace_SendGoal_Response & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_SendGoal_Response & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>()
{
  return "eai_manipulator_msgs::action::JointSpace_SendGoal_Response";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>()
{
  return "eai_manipulator_msgs/action/JointSpace_SendGoal_Response";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_SendGoal>()
{
  return "eai_manipulator_msgs::action::JointSpace_SendGoal";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_SendGoal>()
{
  return "eai_manipulator_msgs/action/JointSpace_SendGoal";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>::value &&
    has_fixed_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>::value &&
    has_bounded_size<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<eai_manipulator_msgs::action::JointSpace_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<eai_manipulator_msgs::action::JointSpace_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<eai_manipulator_msgs::action::JointSpace_SendGoal_Response>
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
  const JointSpace_GetResult_Request & msg,
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
  const JointSpace_GetResult_Request & msg,
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

inline std::string to_yaml(const JointSpace_GetResult_Request & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_GetResult_Request & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_GetResult_Request>()
{
  return "eai_manipulator_msgs::action::JointSpace_GetResult_Request";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_GetResult_Request>()
{
  return "eai_manipulator_msgs/action/JointSpace_GetResult_Request";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "eai_manipulator_msgs/action/detail/joint_space__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_GetResult_Response & msg,
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
  const JointSpace_GetResult_Response & msg,
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

inline std::string to_yaml(const JointSpace_GetResult_Response & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_GetResult_Response & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_GetResult_Response>()
{
  return "eai_manipulator_msgs::action::JointSpace_GetResult_Response";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_GetResult_Response>()
{
  return "eai_manipulator_msgs/action/JointSpace_GetResult_Response";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::JointSpace_Result>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::JointSpace_Result>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_GetResult>()
{
  return "eai_manipulator_msgs::action::JointSpace_GetResult";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_GetResult>()
{
  return "eai_manipulator_msgs/action/JointSpace_GetResult";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<eai_manipulator_msgs::action::JointSpace_GetResult_Request>::value &&
    has_fixed_size<eai_manipulator_msgs::action::JointSpace_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<eai_manipulator_msgs::action::JointSpace_GetResult_Request>::value &&
    has_bounded_size<eai_manipulator_msgs::action::JointSpace_GetResult_Response>::value
  >
{
};

template<>
struct is_service<eai_manipulator_msgs::action::JointSpace_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<eai_manipulator_msgs::action::JointSpace_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<eai_manipulator_msgs::action::JointSpace_GetResult_Response>
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
// #include "eai_manipulator_msgs/action/detail/joint_space__traits.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const JointSpace_FeedbackMessage & msg,
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
  const JointSpace_FeedbackMessage & msg,
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

inline std::string to_yaml(const JointSpace_FeedbackMessage & msg, bool use_flow_style = false)
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
  const eai_manipulator_msgs::action::JointSpace_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  eai_manipulator_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use eai_manipulator_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const eai_manipulator_msgs::action::JointSpace_FeedbackMessage & msg)
{
  return eai_manipulator_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<eai_manipulator_msgs::action::JointSpace_FeedbackMessage>()
{
  return "eai_manipulator_msgs::action::JointSpace_FeedbackMessage";
}

template<>
inline const char * name<eai_manipulator_msgs::action::JointSpace_FeedbackMessage>()
{
  return "eai_manipulator_msgs/action/JointSpace_FeedbackMessage";
}

template<>
struct has_fixed_size<eai_manipulator_msgs::action::JointSpace_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<eai_manipulator_msgs::action::JointSpace_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<eai_manipulator_msgs::action::JointSpace_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<eai_manipulator_msgs::action::JointSpace_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<eai_manipulator_msgs::action::JointSpace_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<eai_manipulator_msgs::action::JointSpace>
  : std::true_type
{
};

template<>
struct is_action_goal<eai_manipulator_msgs::action::JointSpace_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<eai_manipulator_msgs::action::JointSpace_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<eai_manipulator_msgs::action::JointSpace_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__TRAITS_HPP_
