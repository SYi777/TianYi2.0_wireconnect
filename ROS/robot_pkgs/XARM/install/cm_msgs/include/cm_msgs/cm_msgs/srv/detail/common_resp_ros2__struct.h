// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:srv/CommonRespRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__COMMON_RESP_ROS2__STRUCT_H_
#define CM_MSGS__SRV__DETAIL__COMMON_RESP_ROS2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'msg_id'
// Member 'json_data'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/CommonRespRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__CommonRespRos2_Request
{
  rosidl_runtime_c__String msg_id;
  rosidl_runtime_c__String json_data;
  rosidl_runtime_c__uint8__Sequence data;
} cm_msgs__srv__CommonRespRos2_Request;

// Struct for a sequence of cm_msgs__srv__CommonRespRos2_Request.
typedef struct cm_msgs__srv__CommonRespRos2_Request__Sequence
{
  cm_msgs__srv__CommonRespRos2_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__CommonRespRos2_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg_id'
// Member 'json_data'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'data'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/CommonRespRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__CommonRespRos2_Response
{
  bool result;
  rosidl_runtime_c__String msg_id;
  rosidl_runtime_c__String json_data;
  rosidl_runtime_c__uint8__Sequence data;
} cm_msgs__srv__CommonRespRos2_Response;

// Struct for a sequence of cm_msgs__srv__CommonRespRos2_Response.
typedef struct cm_msgs__srv__CommonRespRos2_Response__Sequence
{
  cm_msgs__srv__CommonRespRos2_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__CommonRespRos2_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__SRV__DETAIL__COMMON_RESP_ROS2__STRUCT_H_
