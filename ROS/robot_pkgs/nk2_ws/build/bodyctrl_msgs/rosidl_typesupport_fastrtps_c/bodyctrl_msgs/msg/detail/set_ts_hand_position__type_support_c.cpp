// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bodyctrl_msgs:msg/SetTsHandPosition.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/msg/detail/set_ts_hand_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bodyctrl_msgs/msg/detail/set_ts_hand_position__struct.h"
#include "bodyctrl_msgs/msg/detail/set_ts_hand_position__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // bend_angle
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // bend_angle

// forward declare type support functions


using _SetTsHandPosition__ros_msg_type = bodyctrl_msgs__msg__SetTsHandPosition;

static bool _SetTsHandPosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetTsHandPosition__ros_msg_type * ros_message = static_cast<const _SetTsHandPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    cdr << ros_message->name;
  }

  // Field name: rotation_angle
  {
    cdr << ros_message->rotation_angle;
  }

  // Field name: bend_angle
  {
    size_t size = ros_message->bend_angle.size;
    auto array_ptr = ros_message->bend_angle.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _SetTsHandPosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetTsHandPosition__ros_msg_type * ros_message = static_cast<_SetTsHandPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    cdr >> ros_message->name;
  }

  // Field name: rotation_angle
  {
    cdr >> ros_message->rotation_angle;
  }

  // Field name: bend_angle
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->bend_angle.data) {
      rosidl_runtime_c__uint16__Sequence__fini(&ros_message->bend_angle);
    }
    if (!rosidl_runtime_c__uint16__Sequence__init(&ros_message->bend_angle, size)) {
      fprintf(stderr, "failed to create array for field 'bend_angle'");
      return false;
    }
    auto array_ptr = ros_message->bend_angle.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t get_serialized_size_bodyctrl_msgs__msg__SetTsHandPosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetTsHandPosition__ros_msg_type * ros_message = static_cast<const _SetTsHandPosition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  {
    size_t item_size = sizeof(ros_message->name);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rotation_angle
  {
    size_t item_size = sizeof(ros_message->rotation_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bend_angle
  {
    size_t array_size = ros_message->bend_angle.size;
    auto array_ptr = ros_message->bend_angle.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SetTsHandPosition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bodyctrl_msgs__msg__SetTsHandPosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t max_serialized_size_bodyctrl_msgs__msg__SetTsHandPosition(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: name
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rotation_angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: bend_angle
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = bodyctrl_msgs__msg__SetTsHandPosition;
    is_plain =
      (
      offsetof(DataType, bend_angle) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SetTsHandPosition__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bodyctrl_msgs__msg__SetTsHandPosition(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetTsHandPosition = {
  "bodyctrl_msgs::msg",
  "SetTsHandPosition",
  _SetTsHandPosition__cdr_serialize,
  _SetTsHandPosition__cdr_deserialize,
  _SetTsHandPosition__get_serialized_size,
  _SetTsHandPosition__max_serialized_size
};

static rosidl_message_type_support_t _SetTsHandPosition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetTsHandPosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, msg, SetTsHandPosition)() {
  return &_SetTsHandPosition__type_support;
}

#if defined(__cplusplus)
}
#endif
