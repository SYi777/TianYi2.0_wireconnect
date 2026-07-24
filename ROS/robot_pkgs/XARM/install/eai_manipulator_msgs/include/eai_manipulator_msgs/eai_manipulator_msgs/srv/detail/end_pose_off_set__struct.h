// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:srv/EndPoseOffSet.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/EndPoseOffSet in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__srv__EndPoseOffSet_Request
{
  geometry_msgs__msg__Pose pose;
} eai_manipulator_msgs__srv__EndPoseOffSet_Request;

// Struct for a sequence of eai_manipulator_msgs__srv__EndPoseOffSet_Request.
typedef struct eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence
{
  eai_manipulator_msgs__srv__EndPoseOffSet_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/EndPoseOffSet in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__srv__EndPoseOffSet_Response
{
  bool success;
  rosidl_runtime_c__String message;
} eai_manipulator_msgs__srv__EndPoseOffSet_Response;

// Struct for a sequence of eai_manipulator_msgs__srv__EndPoseOffSet_Response.
typedef struct eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence
{
  eai_manipulator_msgs__srv__EndPoseOffSet_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__STRUCT_H_
