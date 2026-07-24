// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_H_
#define SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'STATUS_CLEAR'.
/**
  * 故障状态，故障产生|故障消除
 */
enum
{
  sys_msgs__msg__Fault__STATUS_CLEAR = 0
};

/// Constant 'STATUS_ACTIVE'.
enum
{
  sys_msgs__msg__Fault__STATUS_ACTIVE = 1
};

/// Struct defined in msg/Fault in the package sys_msgs.
/**
  * 故障产生时间，毫秒时间戳
 */
typedef struct sys_msgs__msg__Fault
{
  uint64_t time_stamp_ms;
  /// 故障码
  uint64_t code;
  uint16_t status;
} sys_msgs__msg__Fault;

// Struct for a sequence of sys_msgs__msg__Fault.
typedef struct sys_msgs__msg__Fault__Sequence
{
  sys_msgs__msg__Fault * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__msg__Fault__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_H_
