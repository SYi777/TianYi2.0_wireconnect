// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:srv/WaypointsRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_H_
#define CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'left_waypoints'
// Member 'right_waypoints'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/WaypointsRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__WaypointsRos2_Request
{
  geometry_msgs__msg__PoseStamped__Sequence left_waypoints;
  geometry_msgs__msg__PoseStamped__Sequence right_waypoints;
} cm_msgs__srv__WaypointsRos2_Request;

// Struct for a sequence of cm_msgs__srv__WaypointsRos2_Request.
typedef struct cm_msgs__srv__WaypointsRos2_Request__Sequence
{
  cm_msgs__srv__WaypointsRos2_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__WaypointsRos2_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/WaypointsRos2 in the package cm_msgs.
typedef struct cm_msgs__srv__WaypointsRos2_Response
{
  bool success;
  rosidl_runtime_c__String message;
} cm_msgs__srv__WaypointsRos2_Response;

// Struct for a sequence of cm_msgs__srv__WaypointsRos2_Response.
typedef struct cm_msgs__srv__WaypointsRos2_Response__Sequence
{
  cm_msgs__srv__WaypointsRos2_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__srv__WaypointsRos2_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_H_
