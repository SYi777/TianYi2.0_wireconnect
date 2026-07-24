// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_H_
#define CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CommandAck in the package cloud_service.
typedef struct cloud_service__msg__CommandAck
{
  int64_t msg_id;
  int32_t cmd_id;
  int32_t code;
  rosidl_runtime_c__String message;
} cloud_service__msg__CommandAck;

// Struct for a sequence of cloud_service__msg__CommandAck.
typedef struct cloud_service__msg__CommandAck__Sequence
{
  cloud_service__msg__CommandAck * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__msg__CommandAck__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_H_
