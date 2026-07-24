// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bodyctrl_msgs:srv/SetAngle.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/srv/detail/set_angle__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bodyctrl_msgs/srv/detail/set_angle__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace bodyctrl_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_serialize(
  const bodyctrl_msgs::srv::SetAngle_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: angle0_ratio
  cdr << ros_message.angle0_ratio;
  // Member: angle1_ratio
  cdr << ros_message.angle1_ratio;
  // Member: angle2_ratio
  cdr << ros_message.angle2_ratio;
  // Member: angle3_ratio
  cdr << ros_message.angle3_ratio;
  // Member: angle4_ratio
  cdr << ros_message.angle4_ratio;
  // Member: angle5_ratio
  cdr << ros_message.angle5_ratio;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bodyctrl_msgs::srv::SetAngle_Request & ros_message)
{
  // Member: angle0_ratio
  cdr >> ros_message.angle0_ratio;

  // Member: angle1_ratio
  cdr >> ros_message.angle1_ratio;

  // Member: angle2_ratio
  cdr >> ros_message.angle2_ratio;

  // Member: angle3_ratio
  cdr >> ros_message.angle3_ratio;

  // Member: angle4_ratio
  cdr >> ros_message.angle4_ratio;

  // Member: angle5_ratio
  cdr >> ros_message.angle5_ratio;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
get_serialized_size(
  const bodyctrl_msgs::srv::SetAngle_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: angle0_ratio
  {
    size_t item_size = sizeof(ros_message.angle0_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle1_ratio
  {
    size_t item_size = sizeof(ros_message.angle1_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle2_ratio
  {
    size_t item_size = sizeof(ros_message.angle2_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle3_ratio
  {
    size_t item_size = sizeof(ros_message.angle3_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle4_ratio
  {
    size_t item_size = sizeof(ros_message.angle4_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle5_ratio
  {
    size_t item_size = sizeof(ros_message.angle5_ratio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
max_serialized_size_SetAngle_Request(
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


  // Member: angle0_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle1_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle2_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle3_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle4_ratio
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle5_ratio
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
    using DataType = bodyctrl_msgs::srv::SetAngle_Request;
    is_plain =
      (
      offsetof(DataType, angle5_ratio) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SetAngle_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::srv::SetAngle_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetAngle_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bodyctrl_msgs::srv::SetAngle_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetAngle_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::srv::SetAngle_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetAngle_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetAngle_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetAngle_Request__callbacks = {
  "bodyctrl_msgs::srv",
  "SetAngle_Request",
  _SetAngle_Request__cdr_serialize,
  _SetAngle_Request__cdr_deserialize,
  _SetAngle_Request__get_serialized_size,
  _SetAngle_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetAngle_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetAngle_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace bodyctrl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bodyctrl_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<bodyctrl_msgs::srv::SetAngle_Request>()
{
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, srv, SetAngle_Request)() {
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace bodyctrl_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_serialize(
  const bodyctrl_msgs::srv::SetAngle_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: angle_accepted
  cdr << (ros_message.angle_accepted ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bodyctrl_msgs::srv::SetAngle_Response & ros_message)
{
  // Member: angle_accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.angle_accepted = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
get_serialized_size(
  const bodyctrl_msgs::srv::SetAngle_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: angle_accepted
  {
    size_t item_size = sizeof(ros_message.angle_accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
max_serialized_size_SetAngle_Response(
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


  // Member: angle_accepted
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
    using DataType = bodyctrl_msgs::srv::SetAngle_Response;
    is_plain =
      (
      offsetof(DataType, angle_accepted) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SetAngle_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::srv::SetAngle_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetAngle_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bodyctrl_msgs::srv::SetAngle_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetAngle_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::srv::SetAngle_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetAngle_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetAngle_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetAngle_Response__callbacks = {
  "bodyctrl_msgs::srv",
  "SetAngle_Response",
  _SetAngle_Response__cdr_serialize,
  _SetAngle_Response__cdr_deserialize,
  _SetAngle_Response__get_serialized_size,
  _SetAngle_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetAngle_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetAngle_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace bodyctrl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bodyctrl_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<bodyctrl_msgs::srv::SetAngle_Response>()
{
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, srv, SetAngle_Response)() {
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace bodyctrl_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SetAngle__callbacks = {
  "bodyctrl_msgs::srv",
  "SetAngle",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, srv, SetAngle_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, srv, SetAngle_Response)(),
};

static rosidl_service_type_support_t _SetAngle__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetAngle__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace bodyctrl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bodyctrl_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<bodyctrl_msgs::srv::SetAngle>()
{
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, srv, SetAngle)() {
  return &bodyctrl_msgs::srv::typesupport_fastrtps_cpp::_SetAngle__handle;
}

#ifdef __cplusplus
}
#endif
