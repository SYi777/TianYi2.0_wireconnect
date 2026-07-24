// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cm_msgs:srv/WaypointsRos2.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cm_msgs/srv/detail/waypoints_ros2__rosidl_typesupport_introspection_c.h"
#include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cm_msgs/srv/detail/waypoints_ros2__functions.h"
#include "cm_msgs/srv/detail/waypoints_ros2__struct.h"


// Include directives for member types
// Member `left_waypoints`
// Member `right_waypoints`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `left_waypoints`
// Member `right_waypoints`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cm_msgs__srv__WaypointsRos2_Request__init(message_memory);
}

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_fini_function(void * message_memory)
{
  cm_msgs__srv__WaypointsRos2_Request__fini(message_memory);
}

size_t cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__size_function__WaypointsRos2_Request__left_waypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__left_waypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__left_waypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__fetch_function__WaypointsRos2_Request__left_waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__PoseStamped * item =
    ((const geometry_msgs__msg__PoseStamped *)
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__left_waypoints(untyped_member, index));
  geometry_msgs__msg__PoseStamped * value =
    (geometry_msgs__msg__PoseStamped *)(untyped_value);
  *value = *item;
}

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__assign_function__WaypointsRos2_Request__left_waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__PoseStamped * item =
    ((geometry_msgs__msg__PoseStamped *)
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__left_waypoints(untyped_member, index));
  const geometry_msgs__msg__PoseStamped * value =
    (const geometry_msgs__msg__PoseStamped *)(untyped_value);
  *item = *value;
}

bool cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__resize_function__WaypointsRos2_Request__left_waypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__PoseStamped__Sequence__fini(member);
  return geometry_msgs__msg__PoseStamped__Sequence__init(member, size);
}

size_t cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__size_function__WaypointsRos2_Request__right_waypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__right_waypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__right_waypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__fetch_function__WaypointsRos2_Request__right_waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__PoseStamped * item =
    ((const geometry_msgs__msg__PoseStamped *)
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__right_waypoints(untyped_member, index));
  geometry_msgs__msg__PoseStamped * value =
    (geometry_msgs__msg__PoseStamped *)(untyped_value);
  *value = *item;
}

void cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__assign_function__WaypointsRos2_Request__right_waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__PoseStamped * item =
    ((geometry_msgs__msg__PoseStamped *)
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__right_waypoints(untyped_member, index));
  const geometry_msgs__msg__PoseStamped * value =
    (const geometry_msgs__msg__PoseStamped *)(untyped_value);
  *item = *value;
}

bool cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__resize_function__WaypointsRos2_Request__right_waypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__PoseStamped__Sequence__fini(member);
  return geometry_msgs__msg__PoseStamped__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_member_array[2] = {
  {
    "left_waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__srv__WaypointsRos2_Request, left_waypoints),  // bytes offset in struct
    NULL,  // default value
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__size_function__WaypointsRos2_Request__left_waypoints,  // size() function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__left_waypoints,  // get_const(index) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__left_waypoints,  // get(index) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__fetch_function__WaypointsRos2_Request__left_waypoints,  // fetch(index, &value) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__assign_function__WaypointsRos2_Request__left_waypoints,  // assign(index, value) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__resize_function__WaypointsRos2_Request__left_waypoints  // resize(index) function pointer
  },
  {
    "right_waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__srv__WaypointsRos2_Request, right_waypoints),  // bytes offset in struct
    NULL,  // default value
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__size_function__WaypointsRos2_Request__right_waypoints,  // size() function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_const_function__WaypointsRos2_Request__right_waypoints,  // get_const(index) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__get_function__WaypointsRos2_Request__right_waypoints,  // get(index) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__fetch_function__WaypointsRos2_Request__right_waypoints,  // fetch(index, &value) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__assign_function__WaypointsRos2_Request__right_waypoints,  // assign(index, value) function pointer
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__resize_function__WaypointsRos2_Request__right_waypoints  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_members = {
  "cm_msgs__srv",  // message namespace
  "WaypointsRos2_Request",  // message name
  2,  // number of fields
  sizeof(cm_msgs__srv__WaypointsRos2_Request),
  cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_member_array,  // message members
  cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_type_support_handle = {
  0,
  &cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Request)() {
  cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_type_support_handle.typesupport_identifier) {
    cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cm_msgs__srv__WaypointsRos2_Request__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__functions.h"
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cm_msgs__srv__WaypointsRos2_Response__init(message_memory);
}

void cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_fini_function(void * message_memory)
{
  cm_msgs__srv__WaypointsRos2_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__srv__WaypointsRos2_Response, success),  // bytes offset in struct
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
    offsetof(cm_msgs__srv__WaypointsRos2_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_members = {
  "cm_msgs__srv",  // message namespace
  "WaypointsRos2_Response",  // message name
  2,  // number of fields
  sizeof(cm_msgs__srv__WaypointsRos2_Response),
  cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_member_array,  // message members
  cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_type_support_handle = {
  0,
  &cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Response)() {
  if (!cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_type_support_handle.typesupport_identifier) {
    cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cm_msgs__srv__WaypointsRos2_Response__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_members = {
  "cm_msgs__srv",  // service namespace
  "WaypointsRos2",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_Request_message_type_support_handle,
  NULL  // response message
  // cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_Response_message_type_support_handle
};

static rosidl_service_type_support_t cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_type_support_handle = {
  0,
  &cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2)() {
  if (!cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_type_support_handle.typesupport_identifier) {
    cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, srv, WaypointsRos2_Response)()->data;
  }

  return &cm_msgs__srv__detail__waypoints_ros2__rosidl_typesupport_introspection_c__WaypointsRos2_service_type_support_handle;
}
