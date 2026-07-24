// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from eai_manipulator_msgs:action/JointSpace.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_H_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_Goal
{
  rosidl_runtime_c__double__Sequence target_positions;
} eai_manipulator_msgs__action__JointSpace_Goal;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_Goal.
typedef struct eai_manipulator_msgs__action__JointSpace_Goal__Sequence
{
  eai_manipulator_msgs__action__JointSpace_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_Result
{
  bool success;
  rosidl_runtime_c__String result_msg;
} eai_manipulator_msgs__action__JointSpace_Result;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_Result.
typedef struct eai_manipulator_msgs__action__JointSpace_Result__Sequence
{
  eai_manipulator_msgs__action__JointSpace_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_positions'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'feedback_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_Feedback
{
  rosidl_runtime_c__double__Sequence current_positions;
  rosidl_runtime_c__String feedback_msg;
} eai_manipulator_msgs__action__JointSpace_Feedback;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_Feedback.
typedef struct eai_manipulator_msgs__action__JointSpace_Feedback__Sequence
{
  eai_manipulator_msgs__action__JointSpace_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "eai_manipulator_msgs/action/detail/joint_space__struct.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  eai_manipulator_msgs__action__JointSpace_Goal goal;
} eai_manipulator_msgs__action__JointSpace_SendGoal_Request;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_SendGoal_Request.
typedef struct eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence
{
  eai_manipulator_msgs__action__JointSpace_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} eai_manipulator_msgs__action__JointSpace_SendGoal_Response;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_SendGoal_Response.
typedef struct eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence
{
  eai_manipulator_msgs__action__JointSpace_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} eai_manipulator_msgs__action__JointSpace_GetResult_Request;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_GetResult_Request.
typedef struct eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence
{
  eai_manipulator_msgs__action__JointSpace_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "eai_manipulator_msgs/action/detail/joint_space__struct.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_GetResult_Response
{
  int8_t status;
  eai_manipulator_msgs__action__JointSpace_Result result;
} eai_manipulator_msgs__action__JointSpace_GetResult_Response;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_GetResult_Response.
typedef struct eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence
{
  eai_manipulator_msgs__action__JointSpace_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "eai_manipulator_msgs/action/detail/joint_space__struct.h"

/// Struct defined in action/JointSpace in the package eai_manipulator_msgs.
typedef struct eai_manipulator_msgs__action__JointSpace_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  eai_manipulator_msgs__action__JointSpace_Feedback feedback;
} eai_manipulator_msgs__action__JointSpace_FeedbackMessage;

// Struct for a sequence of eai_manipulator_msgs__action__JointSpace_FeedbackMessage.
typedef struct eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence
{
  eai_manipulator_msgs__action__JointSpace_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_H_
