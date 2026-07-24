// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define CM_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

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
// Member 'head_pose'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RobotState in the package cm_msgs.
typedef struct cm_msgs__msg__RobotState
{
  std_msgs__msg__Header header;
  ///  头部姿态数据
  /// X, Y, Z, R, P, Y
  rosidl_runtime_c__double__Sequence head_pose;
} cm_msgs__msg__RobotState;

// Struct for a sequence of cm_msgs__msg__RobotState.
typedef struct cm_msgs__msg__RobotState__Sequence
{
  cm_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
