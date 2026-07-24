// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:srv/Info.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Info in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__srv__Info_Request
{
  uint8_t structure_needs_at_least_one_member;
} eai_manipulator_msgs__srv__Info_Request;

// Struct for a sequence of eai_manipulator_msgs__srv__Info_Request.
typedef struct eai_manipulator_msgs__srv__Info_Request__Sequence
{
  eai_manipulator_msgs__srv__Info_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__srv__Info_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Info in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__srv__Info_Response
{
  rosidl_runtime_c__String info;
} eai_manipulator_msgs__srv__Info_Response;

// Struct for a sequence of eai_manipulator_msgs__srv__Info_Response.
typedef struct eai_manipulator_msgs__srv__Info_Response__Sequence
{
  eai_manipulator_msgs__srv__Info_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__srv__Info_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__STRUCT_H_
