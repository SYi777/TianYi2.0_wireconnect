// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cm_msgs/msg/detail/hand_pose_req__rosidl_typesupport_introspection_c.h"
#include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cm_msgs/msg/detail/hand_pose_req__functions.h"
#include "cm_msgs/msg/detail/hand_pose_req__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `left_hand_pose_req`
// Member `right_hand_pose_req`
#include "geometry_msgs/msg/pose.h"
// Member `left_hand_pose_req`
// Member `right_hand_pose_req`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `rpy`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cm_msgs__msg__HandPoseReq__init(message_memory);
}

void cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_fini_function(void * message_memory)
{
  cm_msgs__msg__HandPoseReq__fini(message_memory);
}

size_t cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__size_function__HandPoseReq__rpy(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_const_function__HandPoseReq__rpy(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_function__HandPoseReq__rpy(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__fetch_function__HandPoseReq__rpy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_const_function__HandPoseReq__rpy(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__assign_function__HandPoseReq__rpy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_function__HandPoseReq__rpy(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__resize_function__HandPoseReq__rpy(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_member_array[17] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_move_enable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, hand_move_enable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_side",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, hand_side),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_reset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, hand_reset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_hand_pose_req",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, left_hand_pose_req),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_hand_pose_req",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, right_hand_pose_req),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_move_enable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, head_move_enable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rpy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, rpy),  // bytes offset in struct
    NULL,  // default value
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__size_function__HandPoseReq__rpy,  // size() function pointer
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_const_function__HandPoseReq__rpy,  // get_const(index) function pointer
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__get_function__HandPoseReq__rpy,  // get(index) function pointer
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__fetch_function__HandPoseReq__rpy,  // fetch(index, &value) function pointer
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__assign_function__HandPoseReq__rpy,  // assign(index, value) function pointer
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__resize_function__HandPoseReq__rpy  // resize(index) function pointer
  },
  {
    "gripper_move_enable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, gripper_move_enable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_side",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, gripper_side),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "finger_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, finger_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "little_finger",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, little_finger),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ring_finger",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, ring_finger),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "middle_finger",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, middle_finger),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "index_finger",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, index_finger),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thumb_bending",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, thumb_bending),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thumb_rotating",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__HandPoseReq, thumb_rotating),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_members = {
  "cm_msgs__msg",  // message namespace
  "HandPoseReq",  // message name
  17,  // number of fields
  sizeof(cm_msgs__msg__HandPoseReq),
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_member_array,  // message members
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_init_function,  // function to initialize message memory (memory has to be allocated)
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_type_support_handle = {
  0,
  &cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, msg, HandPoseReq)() {
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_type_support_handle.typesupport_identifier) {
    cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cm_msgs__msg__HandPoseReq__rosidl_typesupport_introspection_c__HandPoseReq_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
