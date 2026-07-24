// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dual_arm_control/srv/detail/plan_random_joint_goal__rosidl_typesupport_introspection_c.h"
#include "dual_arm_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dual_arm_control/srv/detail/plan_random_joint_goal__functions.h"
#include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.h"


// Include directives for member types
// Member `group_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dual_arm_control__srv__PlanRandomJointGoal_Request__init(message_memory);
}

void dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_fini_function(void * message_memory)
{
  dual_arm_control__srv__PlanRandomJointGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_member_array[1] = {
  {
    "group_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control__srv__PlanRandomJointGoal_Request, group_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_members = {
  "dual_arm_control__srv",  // message namespace
  "PlanRandomJointGoal_Request",  // message name
  1,  // number of fields
  sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request),
  dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_member_array,  // message members
  dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_type_support_handle = {
  0,
  &dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dual_arm_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Request)() {
  if (!dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_type_support_handle.typesupport_identifier) {
    dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dual_arm_control__srv__PlanRandomJointGoal_Request__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "dual_arm_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__functions.h"
// already included above
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.h"


// Include directives for member types
// Member `joint_values`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `trajectory`
#include "trajectory_msgs/msg/joint_trajectory.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__rosidl_typesupport_introspection_c.h"
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dual_arm_control__srv__PlanRandomJointGoal_Response__init(message_memory);
}

void dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_fini_function(void * message_memory)
{
  dual_arm_control__srv__PlanRandomJointGoal_Response__fini(message_memory);
}

size_t dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__size_function__PlanRandomJointGoal_Response__joint_values(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_const_function__PlanRandomJointGoal_Response__joint_values(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_function__PlanRandomJointGoal_Response__joint_values(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__fetch_function__PlanRandomJointGoal_Response__joint_values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_const_function__PlanRandomJointGoal_Response__joint_values(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__assign_function__PlanRandomJointGoal_Response__joint_values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_function__PlanRandomJointGoal_Response__joint_values(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__resize_function__PlanRandomJointGoal_Response__joint_values(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_member_array[4] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control__srv__PlanRandomJointGoal_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_values",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control__srv__PlanRandomJointGoal_Response, joint_values),  // bytes offset in struct
    NULL,  // default value
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__size_function__PlanRandomJointGoal_Response__joint_values,  // size() function pointer
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_const_function__PlanRandomJointGoal_Response__joint_values,  // get_const(index) function pointer
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__get_function__PlanRandomJointGoal_Response__joint_values,  // get(index) function pointer
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__fetch_function__PlanRandomJointGoal_Response__joint_values,  // fetch(index, &value) function pointer
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__assign_function__PlanRandomJointGoal_Response__joint_values,  // assign(index, value) function pointer
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__resize_function__PlanRandomJointGoal_Response__joint_values  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control__srv__PlanRandomJointGoal_Response, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control__srv__PlanRandomJointGoal_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_members = {
  "dual_arm_control__srv",  // message namespace
  "PlanRandomJointGoal_Response",  // message name
  4,  // number of fields
  sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response),
  dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_member_array,  // message members
  dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_type_support_handle = {
  0,
  &dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dual_arm_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Response)() {
  dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_msgs, msg, JointTrajectory)();
  if (!dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_type_support_handle.typesupport_identifier) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dual_arm_control__srv__PlanRandomJointGoal_Response__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "dual_arm_control/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_members = {
  "dual_arm_control__srv",  // service namespace
  "PlanRandomJointGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Request_message_type_support_handle,
  NULL  // response message
  // dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_type_support_handle = {
  0,
  &dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dual_arm_control
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal)() {
  if (!dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_type_support_handle.typesupport_identifier) {
    dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dual_arm_control, srv, PlanRandomJointGoal_Response)()->data;
  }

  return &dual_arm_control__srv__detail__plan_random_joint_goal__rosidl_typesupport_introspection_c__PlanRandomJointGoal_service_type_support_handle;
}
