// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:action/EndPosSingleTarget.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_SINGLE_TARGET__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_SINGLE_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
#include "eai_manipulator_msgs/msg/detail/arm_target_pose__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Goal
{
  eai_manipulator_msgs__msg__ArmTargetPose target;
} eai_manipulator_msgs__action__EndPosSingleTarget_Goal;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_Goal.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Goal__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Result
{
  bool success;
  rosidl_runtime_c__String result_msg;
} eai_manipulator_msgs__action__EndPosSingleTarget_Result;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_Result.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Result__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_err'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'feedback_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Feedback
{
  rosidl_runtime_c__double__Sequence current_err;
  rosidl_runtime_c__String feedback_msg;
} eai_manipulator_msgs__action__EndPosSingleTarget_Feedback;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_Feedback.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_Feedback__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "eai_manipulator_msgs/action/detail/end_pos_single_target__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  eai_manipulator_msgs__action__EndPosSingleTarget_Goal goal;
} eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "eai_manipulator_msgs/action/detail/end_pos_single_target__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response
{
  int8_t status;
  eai_manipulator_msgs__action__EndPosSingleTarget_Result result;
} eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "eai_manipulator_msgs/action/detail/end_pos_single_target__struct.h"

/// Struct defined in action/EndPosSingleTarget in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  eai_manipulator_msgs__action__EndPosSingleTarget_Feedback feedback;
} eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage;

// Struct for a sequence of eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage.
typedef struct eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage__Sequence
{
  eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__EndPosSingleTarget_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_SINGLE_TARGET__STRUCT_H_
