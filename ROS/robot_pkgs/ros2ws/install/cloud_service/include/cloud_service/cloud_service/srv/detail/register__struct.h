// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cloud_service:srv/Register.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REGISTER__STRUCT_H_
#define CLOUD_SERVICE__SRV__DETAIL__REGISTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'handler_service_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Register in the package cloud_service.
typedef struct cloud_service__srv__Register_Request
{
  /// 云端传来的远控 id。
  int32_t cmd_id;
  /// 业务接收指定 cmd_id 的 ROS 服务的名称。
  rosidl_runtime_c__String handler_service_name;
} cloud_service__srv__Register_Request;

// Struct for a sequence of cloud_service__srv__Register_Request.
typedef struct cloud_service__srv__Register_Request__Sequence
{
  cloud_service__srv__Register_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__srv__Register_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Register in the package cloud_service.
typedef struct cloud_service__srv__Register_Response
{
  bool success;
} cloud_service__srv__Register_Response;

// Struct for a sequence of cloud_service__srv__Register_Response.
typedef struct cloud_service__srv__Register_Response__Sequence
{
  cloud_service__srv__Register_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__srv__Register_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__SRV__DETAIL__REGISTER__STRUCT_H_
