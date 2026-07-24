// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_H_

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
// Member 'target_l'
// Member 'target_r'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'from_frame_l'
// Member 'to_frame_l'
// Member 'from_frame_r'
// Member 'to_frame_r'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DualArmTargetPose in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__msg__DualArmTargetPose
{
  /// 双臂目标位姿消息，包含左臂、右臂的目标信息及同步控制标志
  std_msgs__msg__Header header;
  /// 左臂目标位姿信息
  /// 目标位姿 T_A_B（从A系到B系的变换）
  geometry_msgs__msg__Pose target_l;
  /// A系名称（参考系）
  rosidl_runtime_c__String from_frame_l;
  /// B系名称（目标系）
  rosidl_runtime_c__String to_frame_l;
  /// 末端参考点X方向偏移量
  float offset_x_l;
  /// 末端参考点Y方向偏移量
  float offset_y_l;
  /// 末端参考点Z方向偏移量
  float offset_z_l;
  /// 右臂目标位姿信息
  /// 目标位姿 T_A_B（从A系到B系的变换）
  geometry_msgs__msg__Pose target_r;
  /// A系名称（参考系）
  rosidl_runtime_c__String from_frame_r;
  /// B系名称（目标系）
  rosidl_runtime_c__String to_frame_r;
  /// 末端参考点X方向偏移量
  float offset_x_r;
  /// 末端参考点Y方向偏移量
  float offset_y_r;
  /// 末端参考点Z方向偏移量
  float offset_z_r;
  /// 是否启用双臂同步运动（true=同步，false=独立）
  bool is_dual_arm_syn;
} eai_manipulator_msgs__msg__DualArmTargetPose;

// Struct for a sequence of eai_manipulator_msgs__msg__DualArmTargetPose.
typedef struct eai_manipulator_msgs__msg__DualArmTargetPose__Sequence
{
  eai_manipulator_msgs__msg__DualArmTargetPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__msg__DualArmTargetPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_H_
