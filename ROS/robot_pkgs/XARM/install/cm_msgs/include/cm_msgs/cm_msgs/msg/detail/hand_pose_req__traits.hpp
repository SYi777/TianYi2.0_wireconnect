// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__TRAITS_HPP_
#define CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/msg/detail/hand_pose_req__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left_hand_pose_req'
// Member 'right_hand_pose_req'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace cm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HandPoseReq & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: hand_move_enable
  {
    out << "hand_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_move_enable, out);
    out << ", ";
  }

  // member: hand_side
  {
    out << "hand_side: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_side, out);
    out << ", ";
  }

  // member: hand_reset
  {
    out << "hand_reset: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_reset, out);
    out << ", ";
  }

  // member: left_hand_pose_req
  {
    out << "left_hand_pose_req: ";
    to_flow_style_yaml(msg.left_hand_pose_req, out);
    out << ", ";
  }

  // member: right_hand_pose_req
  {
    out << "right_hand_pose_req: ";
    to_flow_style_yaml(msg.right_hand_pose_req, out);
    out << ", ";
  }

  // member: head_move_enable
  {
    out << "head_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.head_move_enable, out);
    out << ", ";
  }

  // member: rpy
  {
    if (msg.rpy.size() == 0) {
      out << "rpy: []";
    } else {
      out << "rpy: [";
      size_t pending_items = msg.rpy.size();
      for (auto item : msg.rpy) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gripper_move_enable
  {
    out << "gripper_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_move_enable, out);
    out << ", ";
  }

  // member: gripper_side
  {
    out << "gripper_side: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_side, out);
    out << ", ";
  }

  // member: finger_status
  {
    out << "finger_status: ";
    rosidl_generator_traits::value_to_yaml(msg.finger_status, out);
    out << ", ";
  }

  // member: little_finger
  {
    out << "little_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.little_finger, out);
    out << ", ";
  }

  // member: ring_finger
  {
    out << "ring_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.ring_finger, out);
    out << ", ";
  }

  // member: middle_finger
  {
    out << "middle_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.middle_finger, out);
    out << ", ";
  }

  // member: index_finger
  {
    out << "index_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.index_finger, out);
    out << ", ";
  }

  // member: thumb_bending
  {
    out << "thumb_bending: ";
    rosidl_generator_traits::value_to_yaml(msg.thumb_bending, out);
    out << ", ";
  }

  // member: thumb_rotating
  {
    out << "thumb_rotating: ";
    rosidl_generator_traits::value_to_yaml(msg.thumb_rotating, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HandPoseReq & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: hand_move_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_move_enable, out);
    out << "\n";
  }

  // member: hand_side
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_side: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_side, out);
    out << "\n";
  }

  // member: hand_reset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_reset: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_reset, out);
    out << "\n";
  }

  // member: left_hand_pose_req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_hand_pose_req:\n";
    to_block_style_yaml(msg.left_hand_pose_req, out, indentation + 2);
  }

  // member: right_hand_pose_req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_hand_pose_req:\n";
    to_block_style_yaml(msg.right_hand_pose_req, out, indentation + 2);
  }

  // member: head_move_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.head_move_enable, out);
    out << "\n";
  }

  // member: rpy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rpy.size() == 0) {
      out << "rpy: []\n";
    } else {
      out << "rpy:\n";
      for (auto item : msg.rpy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gripper_move_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_move_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_move_enable, out);
    out << "\n";
  }

  // member: gripper_side
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_side: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_side, out);
    out << "\n";
  }

  // member: finger_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finger_status: ";
    rosidl_generator_traits::value_to_yaml(msg.finger_status, out);
    out << "\n";
  }

  // member: little_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "little_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.little_finger, out);
    out << "\n";
  }

  // member: ring_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ring_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.ring_finger, out);
    out << "\n";
  }

  // member: middle_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "middle_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.middle_finger, out);
    out << "\n";
  }

  // member: index_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.index_finger, out);
    out << "\n";
  }

  // member: thumb_bending
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thumb_bending: ";
    rosidl_generator_traits::value_to_yaml(msg.thumb_bending, out);
    out << "\n";
  }

  // member: thumb_rotating
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thumb_rotating: ";
    rosidl_generator_traits::value_to_yaml(msg.thumb_rotating, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandPoseReq & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cm_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cm_msgs::msg::HandPoseReq & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::msg::HandPoseReq & msg)
{
  return cm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::msg::HandPoseReq>()
{
  return "cm_msgs::msg::HandPoseReq";
}

template<>
inline const char * name<cm_msgs::msg::HandPoseReq>()
{
  return "cm_msgs/msg/HandPoseReq";
}

template<>
struct has_fixed_size<cm_msgs::msg::HandPoseReq>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cm_msgs::msg::HandPoseReq>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cm_msgs::msg::HandPoseReq>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__TRAITS_HPP_
