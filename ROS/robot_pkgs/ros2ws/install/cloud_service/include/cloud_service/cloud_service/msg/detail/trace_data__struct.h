// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cloud_service:msg/TraceData.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_H_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TYPE_INT'.
enum
{
  cloud_service__msg__TraceData__TYPE_INT = 0
};

/// Constant 'TYPE_STR'.
enum
{
  cloud_service__msg__TraceData__TYPE_STR = 1
};

/// Constant 'TYPE_BOOL'.
enum
{
  cloud_service__msg__TraceData__TYPE_BOOL = 2
};

/// Constant 'TYPE_DOUBLE'.
enum
{
  cloud_service__msg__TraceData__TYPE_DOUBLE = 3
};

// Include directives for member types
// Member 'key'
// Member 'str_val'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TraceData in the package cloud_service.
typedef struct cloud_service__msg__TraceData
{
  rosidl_runtime_c__String key;
  uint8_t data_type;
  int32_t int_val;
  rosidl_runtime_c__String str_val;
  bool bool_val;
  double double_val;
} cloud_service__msg__TraceData;

// Struct for a sequence of cloud_service__msg__TraceData.
typedef struct cloud_service__msg__TraceData__Sequence
{
  cloud_service__msg__TraceData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__msg__TraceData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_H_
