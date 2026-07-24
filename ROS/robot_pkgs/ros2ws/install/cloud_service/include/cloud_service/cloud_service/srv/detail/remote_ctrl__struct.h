// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cloud_service:srv/RemoteCtrl.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__STRUCT_H_
#define CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'payload'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RemoteCtrl in the package cloud_service.
typedef struct cloud_service__srv__RemoteCtrl_Request
{
  /// MQTT 数据包的 id。
  int64_t msg_id;
  /// 云端传来的远控 id。
  int32_t cmd_id;
  /// 云端传来的远控数据。
  rosidl_runtime_c__String payload;
} cloud_service__srv__RemoteCtrl_Request;

// Struct for a sequence of cloud_service__srv__RemoteCtrl_Request.
typedef struct cloud_service__srv__RemoteCtrl_Request__Sequence
{
  cloud_service__srv__RemoteCtrl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__srv__RemoteCtrl_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RemoteCtrl in the package cloud_service.
typedef struct cloud_service__srv__RemoteCtrl_Response
{
  int32_t code;
  /// 业务方的响应消息。
  rosidl_runtime_c__String message;
} cloud_service__srv__RemoteCtrl_Response;

// Struct for a sequence of cloud_service__srv__RemoteCtrl_Response.
typedef struct cloud_service__srv__RemoteCtrl_Response__Sequence
{
  cloud_service__srv__RemoteCtrl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cloud_service__srv__RemoteCtrl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__STRUCT_H_
