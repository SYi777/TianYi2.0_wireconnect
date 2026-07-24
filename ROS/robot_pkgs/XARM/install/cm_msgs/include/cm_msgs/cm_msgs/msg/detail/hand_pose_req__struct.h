// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_H_
#define CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'left_hand_pose_req'
// Member 'right_hand_pose_req'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'rpy'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/HandPoseReq in the package cm_msgs.
typedef struct cm_msgs__msg__HandPoseReq
{
  std_msgs__msg__Header header;
  /// 以下分别为手臂、头部、手指对应的控制数据，相应数据仅当对应使能位有效时才有意义
  /// 例如: 当hand_move_enable为1(enable状态)时, pose_req的数据才需要被执行，才有意义
  /// 手臂移动使能位-hand_move_enable, 手臂目标位姿-pose_req, 手臂复位-hand_reset(0-非复位位姿，1-复位位姿)
  uint8_t hand_move_enable;
  uint8_t hand_side;
  uint8_t hand_reset;
  geometry_msgs__msg__Pose left_hand_pose_req;
  geometry_msgs__msg__Pose right_hand_pose_req;
  /// 头部移动使能位-move_enable, 头部目标位姿-(R, P, Y）
  uint8_t head_move_enable;
  rosidl_runtime_c__double__Sequence rpy;
  /// 手部手指移动使能位-gripper_move_enable, 手指开度-[figure_1, figure_2, figure_3, figure_4, figure_5]
  uint8_t gripper_move_enable;
  uint8_t gripper_side;
  uint8_t finger_status;
  float little_finger;
  float ring_finger;
  float middle_finger;
  float index_finger;
  float thumb_bending;
  float thumb_rotating;
} cm_msgs__msg__HandPoseReq;

// Struct for a sequence of cm_msgs__msg__HandPoseReq.
typedef struct cm_msgs__msg__HandPoseReq__Sequence
{
  cm_msgs__msg__HandPoseReq * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__msg__HandPoseReq__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_H_
