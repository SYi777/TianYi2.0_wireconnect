// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:srv/TrajectoryRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_H_
#define CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"

/// Struct defined in srv/TrajectoryRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__TrajectoryRos2_Request
{
  rosidl_runtime_c__String msg_id;
  trajectory_msgs__msg__JointTrajectory trajectory;
} cm_msgs__srv__TrajectoryRos2_Request;

// Struct for a sequence of cm_msgs__srv__TrajectoryRos2_Request.
typedef struct cm_msgs__srv__TrajectoryRos2_Request__Sequence
{
  cm_msgs__srv__TrajectoryRos2_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__TrajectoryRos2_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TrajectoryRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__TrajectoryRos2_Response
{
  bool result;
} cm_msgs__srv__TrajectoryRos2_Response;

// Struct for a sequence of cm_msgs__srv__TrajectoryRos2_Response.
typedef struct cm_msgs__srv__TrajectoryRos2_Response__Sequence
{
  cm_msgs__srv__TrajectoryRos2_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__TrajectoryRos2_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_H_
