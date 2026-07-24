// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sys_msgs:srv/FaultClear.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_H_
#define SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_H_

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
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/FaultClear in the package sys_msgs.
typedef struct sys_msgs__srv__FaultClear_Request
{
  /// 需要清空的故障码数组
  rosidl_runtime_c__uint64__Sequence fault_array;
} sys_msgs__srv__FaultClear_Request;

// Struct for a sequence of sys_msgs__srv__FaultClear_Request.
typedef struct sys_msgs__srv__FaultClear_Request__Sequence
{
  sys_msgs__srv__FaultClear_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__srv__FaultClear_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FaultClear in the package sys_msgs.
typedef struct sys_msgs__srv__FaultClear_Response
{
  bool success;
} sys_msgs__srv__FaultClear_Response;

// Struct for a sequence of sys_msgs__srv__FaultClear_Response.
typedef struct sys_msgs__srv__FaultClear_Response__Sequence
{
  sys_msgs__srv__FaultClear_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__srv__FaultClear_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_H_
