// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_H_
#define CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_H_

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

/// Struct defined in msg/PoseActionStatus in the package cm_msgs.
typedef struct cm_msgs__msg__PoseActionStatus
{
  std_msgs__msg__Header header;
  /// 相应的hand_pose_req msg中header的seq,表示是对该帧pose的相应
  uint32_t resp_frame_id;
  /// 0-失败， 1-成功， 2-默认值(default），其他数值暂不可用，留待后续扩展
  uint8_t hand_move_success;
  uint8_t head_move_success;
  uint8_t gripper_move_success;
} cm_msgs__msg__PoseActionStatus;

// Struct for a sequence of cm_msgs__msg__PoseActionStatus.
typedef struct cm_msgs__msg__PoseActionStatus__Sequence
{
  cm_msgs__msg__PoseActionStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__msg__PoseActionStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_H_
