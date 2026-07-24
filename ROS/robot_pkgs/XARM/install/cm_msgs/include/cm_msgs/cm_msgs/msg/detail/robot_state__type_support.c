// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cm_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cm_msgs/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"
#include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cm_msgs/msg/detail/robot_state__functions.h"
#include "cm_msgs/msg/detail/robot_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `head_pose`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cm_msgs__msg__RobotState__init(message_memory);
}

void cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_fini_function(void * message_memory)
{
  cm_msgs__msg__RobotState__fini(message_memory);
}

size_t cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__head_pose(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__head_pose(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__head_pose(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__head_pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__head_pose(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__head_pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__head_pose(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__head_pose(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__RobotState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__RobotState, head_pose),  // bytes offset in struct
    NULL,  // default value
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__head_pose,  // size() function pointer
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__head_pose,  // get_const(index) function pointer
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__head_pose,  // get(index) function pointer
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__head_pose,  // fetch(index, &value) function pointer
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__head_pose,  // assign(index, value) function pointer
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__head_pose  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_members = {
  "cm_msgs__msg",  // message namespace
  "RobotState",  // message name
  2,  // number of fields
  sizeof(cm_msgs__msg__RobotState),
  cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_member_array,  // message members
  cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_init_function,  // function to initialize message memory (memory has to be allocated)
  cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle = {
  0,
  &cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, msg, RobotState)() {
  cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle.typesupport_identifier) {
    cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cm_msgs__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
