// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#ifndef DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_H_
#define DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'group_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PlanRandomJointGoal in the package dual_arm_control.
typedef struct dual_arm_control__srv__PlanRandomJointGoal_Request
{
  rosidl_runtime_c__String group_name;
} dual_arm_control__srv__PlanRandomJointGoal_Request;

// Struct for a sequence of dual_arm_control__srv__PlanRandomJointGoal_Request.
typedef struct dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence
{
  dual_arm_control__srv__PlanRandomJointGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'joint_values'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PlanRandomJointGoal in the package dual_arm_control.
typedef struct dual_arm_control__srv__PlanRandomJointGoal_Response
{
  bool success;
  rosidl_runtime_c__double__Sequence joint_values;
  trajectory_msgs__msg__JointTrajectory trajectory;
  rosidl_runtime_c__String message;
} dual_arm_control__srv__PlanRandomJointGoal_Response;

// Struct for a sequence of dual_arm_control__srv__PlanRandomJointGoal_Response.
typedef struct dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence
{
  dual_arm_control__srv__PlanRandomJointGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_H_
