// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_H_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'model'
// Member 'event_name'
#include "rosidl_runtime_c/string.h"
// Member 'trace_array'
#include "cloud_service/msg/detail/trace_data__struct.h"

/// Struct defined in msg/TraceDatas in the package cloud_service.
typedef struct cloud_service__msg__TraceDatas
{
  rosidl_runtime_c__String model;
  rosidl_runtime_c__String event_name;
  cloud_service__msg__TraceData__Sequence trace_array;
} cloud_service__msg__TraceDatas;

// Struct for a sequence of cloud_service__msg__TraceDatas.
typedef struct cloud_service__msg__TraceDatas__Sequence
{
  cloud_service__msg__TraceDatas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__msg__TraceDatas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_H_
