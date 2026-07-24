// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_H_

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
// Member 'level'
// Member 'source'
// Member 'info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/WarnAndErrorInfo in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__msg__WarnAndErrorInfo
{
  std_msgs__msg__Header header;
  /// 信息级别
  rosidl_runtime_c__String level;
  /// 信息代码
  uint32_t code;
  /// 发布源头
  rosidl_runtime_c__String source;
  /// 信息内容
  rosidl_runtime_c__String info;
} eai_manipulator_msgs__msg__WarnAndErrorInfo;

// Struct for a sequence of eai_manipulator_msgs__msg__WarnAndErrorInfo.
typedef struct eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence
{
  eai_manipulator_msgs__msg__WarnAndErrorInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_H_
