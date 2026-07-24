// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/GetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GetVelLimit in the package hric_msgs.
typedef struct hric_msgs__msg__GetVelLimit
{
  /// 行走时x方向速度限制
  double x_vel_limit_walk;
  /// 跑步时x方向速度限制
  double x_vel_limit_run;
  /// 半身行走时x方向速度限制
  double x_vel_limit_halfwalk;
} hric_msgs__msg__GetVelLimit;

// Struct for a sequence of hric_msgs__msg__GetVelLimit.
typedef struct hric_msgs__msg__GetVelLimit__Sequence
{
  hric_msgs__msg__GetVelLimit * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__GetVelLimit__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_H_
