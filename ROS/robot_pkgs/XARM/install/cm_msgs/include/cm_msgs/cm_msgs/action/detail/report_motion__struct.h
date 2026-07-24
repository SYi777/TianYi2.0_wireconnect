// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:action/ReportMotion.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_H_
#define CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_H_

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

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_Goal
{
  rosidl_runtime_c__String msg_id;
  rosidl_runtime_c__uint8__Sequence data;
  rosidl_runtime_c__String json_data;
} cm_msgs__action__ReportMotion_Goal;

// Struct for a sequence of cm_msgs__action__ReportMotion_Goal.
typedef struct cm_msgs__action__ReportMotion_Goal__Sequence
{
  cm_msgs__action__ReportMotion_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_Result
{
  bool result;
  rosidl_runtime_c__String info;
} cm_msgs__action__ReportMotion_Result;

// Struct for a sequence of cm_msgs__action__ReportMotion_Result.
typedef struct cm_msgs__action__ReportMotion_Result__Sequence
{
  cm_msgs__action__ReportMotion_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_Feedback
{
  rosidl_runtime_c__String status;
} cm_msgs__action__ReportMotion_Feedback;

// Struct for a sequence of cm_msgs__action__ReportMotion_Feedback.
typedef struct cm_msgs__action__ReportMotion_Feedback__Sequence
{
  cm_msgs__action__ReportMotion_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "cm_msgs/action/detail/report_motion__struct.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  cm_msgs__action__ReportMotion_Goal goal;
} cm_msgs__action__ReportMotion_SendGoal_Request;

// Struct for a sequence of cm_msgs__action__ReportMotion_SendGoal_Request.
typedef struct cm_msgs__action__ReportMotion_SendGoal_Request__Sequence
{
  cm_msgs__action__ReportMotion_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} cm_msgs__action__ReportMotion_SendGoal_Response;

// Struct for a sequence of cm_msgs__action__ReportMotion_SendGoal_Response.
typedef struct cm_msgs__action__ReportMotion_SendGoal_Response__Sequence
{
  cm_msgs__action__ReportMotion_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} cm_msgs__action__ReportMotion_GetResult_Request;

// Struct for a sequence of cm_msgs__action__ReportMotion_GetResult_Request.
typedef struct cm_msgs__action__ReportMotion_GetResult_Request__Sequence
{
  cm_msgs__action__ReportMotion_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "cm_msgs/action/detail/report_motion__struct.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_GetResult_Response
{
  int8_t status;
  cm_msgs__action__ReportMotion_Result result;
} cm_msgs__action__ReportMotion_GetResult_Response;

// Struct for a sequence of cm_msgs__action__ReportMotion_GetResult_Response.
typedef struct cm_msgs__action__ReportMotion_GetResult_Response__Sequence
{
  cm_msgs__action__ReportMotion_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "cm_msgs/action/detail/report_motion__struct.h"

/// Struct defined in action/ReportMotion in the package cm_msgs.
typedef struct cm_msgs__action__ReportMotion_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  cm_msgs__action__ReportMotion_Feedback feedback;
} cm_msgs__action__ReportMotion_FeedbackMessage;

// Struct for a sequence of cm_msgs__action__ReportMotion_FeedbackMessage.
typedef struct cm_msgs__action__ReportMotion_FeedbackMessage__Sequence
{
  cm_msgs__action__ReportMotion_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__action__ReportMotion_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_H_
