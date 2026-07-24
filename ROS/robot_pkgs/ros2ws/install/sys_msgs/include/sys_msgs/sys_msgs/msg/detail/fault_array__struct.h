// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_H_
#define SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'fault_array'
#include "sys_msgs/msg/detail/fault__struct.h"

/// Struct defined in msg/FaultArray in the package sys_msgs.
/**
  * 支持单次上报故障数组
 */
typedef struct sys_msgs__msg__FaultArray
{
  sys_msgs__msg__Fault__Sequence fault_array;
} sys_msgs__msg__FaultArray;

// Struct for a sequence of sys_msgs__msg__FaultArray.
typedef struct sys_msgs__msg__FaultArray__Sequence
{
  sys_msgs__msg__FaultArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__msg__FaultArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_H_
