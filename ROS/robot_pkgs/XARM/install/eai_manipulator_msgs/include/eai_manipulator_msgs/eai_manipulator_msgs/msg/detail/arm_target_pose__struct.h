// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_H_

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
// Member 'target'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'from_frame'
// Member 'to_frame'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ArmTargetPose in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__msg__ArmTargetPose
{
  std_msgs__msg__Header header;
  /// 目标位姿 T_A_B 从A系的B系
  geometry_msgs__msg__Pose target;
  /// A系名称
  rosidl_runtime_c__String from_frame;
  /// B系名称
  rosidl_runtime_c__String to_frame;
  /// 末端参考偏移量
  float offset_x;
  float offset_y;
  float offset_z;
} eai_manipulator_msgs__msg__ArmTargetPose;

// Struct for a sequence of eai_manipulator_msgs__msg__ArmTargetPose.
typedef struct eai_manipulator_msgs__msg__ArmTargetPose__Sequence
{
  eai_manipulator_msgs__msg__ArmTargetPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__msg__ArmTargetPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_H_
