// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sys_msgs:srv/FaultQuery.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_H_
#define SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/FaultQuery in the package sys_msgs.
typedef struct sys_msgs__srv__FaultQuery_Request
{
  uint8_t structure_needs_at_least_one_member;
} sys_msgs__srv__FaultQuery_Request;

// Struct for a sequence of sys_msgs__srv__FaultQuery_Request.
typedef struct sys_msgs__srv__FaultQuery_Request__Sequence
{
  sys_msgs__srv__FaultQuery_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__srv__FaultQuery_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'fault_array'
#include "sys_msgs/msg/detail/fault__struct.h"

/// Struct defined in srv/FaultQuery in the package sys_msgs.
typedef struct sys_msgs__srv__FaultQuery_Response
{
  sys_msgs__msg__Fault__Sequence fault_array;
} sys_msgs__srv__FaultQuery_Response;

// Struct for a sequence of sys_msgs__srv__FaultQuery_Response.
typedef struct sys_msgs__srv__FaultQuery_Response__Sequence
{
  sys_msgs__srv__FaultQuery_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sys_msgs__srv__FaultQuery_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_H_
