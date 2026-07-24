// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bodyctrl_msgs:srv/SetSpeed.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/srv/detail/set_speed__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bodyctrl_msgs/srv/detail/set_speed__struct.h"
#include "bodyctrl_msgs/srv/detail/set_speed__functions.h"
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


// forward declare type support functions


using _SetSpeed_Request__ros_msg_type = bodyctrl_msgs__srv__SetSpeed_Request;

static bool _SetSpeed_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetSpeed_Request__ros_msg_type * ros_message = static_cast<const _SetSpeed_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: speed0_ratio
  {
    cdr << ros_message->speed0_ratio;
  }

  // Field name: speed1_ratio
  {
    cdr << ros_message->speed1_ratio;
  }

  // Field name: speed2_ratio
  {
    cdr << ros_message->speed2_ratio;
  }

  // Field name: speed3_ratio
  {
    cdr << ros_message->speed3_ratio;
  }

  // Field name: speed4_ratio
  {
    cdr << ros_message->speed4_ratio;
  }

  // Field name: speed5_ratio
  {
    cdr << ros_message->speed5_ratio;
  }

  return true;
}

static bool _SetSpeed_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetSpeed_Request__ros_msg_type * ros_message = static_cast<_SetSpeed_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: speed0_ratio
  {
    cdr >> ros_message->speed0_ratio;
  }

  // Field name: speed1_ratio
  {
    cdr >> ros_message->speed1_ratio;
  }

  // Field name: speed2_ratio
  {
    cdr >> ros_message->speed2_ratio;
  }

  // Field name: speed3_ratio
  {
    cdr >> ros_message->speed3_ratio;
  }

  // Field name: speed4_ratio
  {
    cdr >> ros_message->speed4_ratio;
  }

  // Field name: speed5_ratio
  {
    cdr >> ros_message->speed5_ratio;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t get_serialized_size_bodyctrl_msgs__srv__SetSpeed_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetSpeed_Request__ros_msg_type * ros_message = static_cast<const _SetSpeed_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name speed0_ratio
  {
    size_t item_size = sizeof(ros_message->speed0_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed1_ratio
  {
    size_t item_size = sizeof(ros_message->speed1_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed2_ratio
  {
    size_t item_size = sizeof(ros_message->speed2_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed3_ratio
  {
    size_t item_size = sizeof(ros_message->speed3_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed4_ratio
  {
    size_t item_size = sizeof(ros_message->speed4_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed5_ratio
  {
    size_t item_size = sizeof(ros_message->speed5_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SetSpeed_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bodyctrl_msgs__srv__SetSpeed_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t max_serialized_size_bodyctrl_msgs__srv__SetSpeed_Request(
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

  // member: speed0_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed1_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed2_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed3_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed4_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed5_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = bodyctrl_msgs__srv__SetSpeed_Request;
    is_plain =
      (
      offsetof(DataType, speed5_ratio) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SetSpeed_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bodyctrl_msgs__srv__SetSpeed_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetSpeed_Request = {
  "bodyctrl_msgs::srv",
  "SetSpeed_Request",
  _SetSpeed_Request__cdr_serialize,
  _SetSpeed_Request__cdr_deserialize,
  _SetSpeed_Request__get_serialized_size,
  _SetSpeed_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetSpeed_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetSpeed_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, srv, SetSpeed_Request)() {
  return &_SetSpeed_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "bodyctrl_msgs/srv/detail/set_speed__struct.h"
// already included above
// #include "bodyctrl_msgs/srv/detail/set_speed__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


// forward declare type support functions


using _SetSpeed_Response__ros_msg_type = bodyctrl_msgs__srv__SetSpeed_Response;

static bool _SetSpeed_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetSpeed_Response__ros_msg_type * ros_message = static_cast<const _SetSpeed_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: speed_accepted
  {
    cdr << (ros_message->speed_accepted ? true : false);
  }

  return true;
}

static bool _SetSpeed_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetSpeed_Response__ros_msg_type * ros_message = static_cast<_SetSpeed_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: speed_accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->speed_accepted = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t get_serialized_size_bodyctrl_msgs__srv__SetSpeed_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetSpeed_Response__ros_msg_type * ros_message = static_cast<const _SetSpeed_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name speed_accepted
  {
    size_t item_size = sizeof(ros_message->speed_accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SetSpeed_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bodyctrl_msgs__srv__SetSpeed_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t max_serialized_size_bodyctrl_msgs__srv__SetSpeed_Response(
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

  // member: speed_accepted
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = bodyctrl_msgs__srv__SetSpeed_Response;
    is_plain =
      (
      offsetof(DataType, speed_accepted) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SetSpeed_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bodyctrl_msgs__srv__SetSpeed_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetSpeed_Response = {
  "bodyctrl_msgs::srv",
  "SetSpeed_Response",
  _SetSpeed_Response__cdr_serialize,
  _SetSpeed_Response__cdr_deserialize,
  _SetSpeed_Response__get_serialized_size,
  _SetSpeed_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetSpeed_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetSpeed_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, srv, SetSpeed_Response)() {
  return &_SetSpeed_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bodyctrl_msgs/srv/set_speed.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SetSpeed__callbacks = {
  "bodyctrl_msgs::srv",
  "SetSpeed",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, srv, SetSpeed_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, srv, SetSpeed_Response)(),
};

static rosidl_service_type_support_t SetSpeed__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SetSpeed__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, srv, SetSpeed)() {
  return &SetSpeed__handle;
}

#if defined(__cplusplus)
}
#endif
