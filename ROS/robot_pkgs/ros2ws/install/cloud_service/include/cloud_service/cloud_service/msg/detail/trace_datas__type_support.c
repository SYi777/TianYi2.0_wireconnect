// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cloud_service/msg/detail/trace_datas__rosidl_typesupport_introspection_c.h"
#include "cloud_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cloud_service/msg/detail/trace_datas__functions.h"
#include "cloud_service/msg/detail/trace_datas__struct.h"


// Include directives for member types
// Member `model`
// Member `event_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `trace_array`
#include "cloud_service/msg/trace_data.h"
// Member `trace_array`
#include "cloud_service/msg/detail/trace_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cloud_service__msg__TraceDatas__init(message_memory);
}

void cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_fini_function(void * message_memory)
{
  cloud_service__msg__TraceDatas__fini(message_memory);
}

size_t cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__size_function__TraceDatas__trace_array(
  const void * untyped_member)
{
  const cloud_service__msg__TraceData__Sequence * member =
    (const cloud_service__msg__TraceData__Sequence *)(untyped_member);
  return member->size;
}

const void * cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_const_function__TraceDatas__trace_array(
  const void * untyped_member, size_t index)
{
  const cloud_service__msg__TraceData__Sequence * member =
    (const cloud_service__msg__TraceData__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_function__TraceDatas__trace_array(
  void * untyped_member, size_t index)
{
  cloud_service__msg__TraceData__Sequence * member =
    (cloud_service__msg__TraceData__Sequence *)(untyped_member);
  return &member->data[index];
}

void cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__fetch_function__TraceDatas__trace_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const cloud_service__msg__TraceData * item =
    ((const cloud_service__msg__TraceData *)
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_const_function__TraceDatas__trace_array(untyped_member, index));
  cloud_service__msg__TraceData * value =
    (cloud_service__msg__TraceData *)(untyped_value);
  *value = *item;
}

void cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__assign_function__TraceDatas__trace_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  cloud_service__msg__TraceData * item =
    ((cloud_service__msg__TraceData *)
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_function__TraceDatas__trace_array(untyped_member, index));
  const cloud_service__msg__TraceData * value =
    (const cloud_service__msg__TraceData *)(untyped_value);
  *item = *value;
}

bool cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__resize_function__TraceDatas__trace_array(
  void * untyped_member, size_t size)
{
  cloud_service__msg__TraceData__Sequence * member =
    (cloud_service__msg__TraceData__Sequence *)(untyped_member);
  cloud_service__msg__TraceData__Sequence__fini(member);
  return cloud_service__msg__TraceData__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_member_array[3] = {
  {
    "model",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__TraceDatas, model),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "event_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__TraceDatas, event_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trace_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__TraceDatas, trace_array),  // bytes offset in struct
    NULL,  // default value
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__size_function__TraceDatas__trace_array,  // size() function pointer
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_const_function__TraceDatas__trace_array,  // get_const(index) function pointer
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__get_function__TraceDatas__trace_array,  // get(index) function pointer
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__fetch_function__TraceDatas__trace_array,  // fetch(index, &value) function pointer
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__assign_function__TraceDatas__trace_array,  // assign(index, value) function pointer
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__resize_function__TraceDatas__trace_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_members = {
  "cloud_service__msg",  // message namespace
  "TraceDatas",  // message name
  3,  // number of fields
  sizeof(cloud_service__msg__TraceDatas),
  cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_member_array,  // message members
  cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_init_function,  // function to initialize message memory (memory has to be allocated)
  cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_type_support_handle = {
  0,
  &cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cloud_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, msg, TraceDatas)() {
  cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, msg, TraceData)();
  if (!cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_type_support_handle.typesupport_identifier) {
    cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cloud_service__msg__TraceDatas__rosidl_typesupport_introspection_c__TraceDatas_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
