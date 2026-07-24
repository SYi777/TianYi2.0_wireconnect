// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bodyctrl_msgs:msg/SetTsHandCtrl.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/msg/detail/set_ts_hand_ctrl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bodyctrl_msgs/msg/detail/set_ts_hand_ctrl__struct.hpp"

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
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const bodyctrl_msgs::msg::SetTsHandCtrlItem &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  bodyctrl_msgs::msg::SetTsHandCtrlItem &);
size_t get_serialized_size(
  const bodyctrl_msgs::msg::SetTsHandCtrlItem &,
  size_t current_alignment);
size_t
max_serialized_size_SetTsHandCtrlItem(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace bodyctrl_msgs

// functions for bodyctrl_msgs::msg::SetTsHandCtrlItem already declared above


namespace bodyctrl_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_serialize(
  const bodyctrl_msgs::msg::SetTsHandCtrl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: rotation
  bodyctrl_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.rotation,
    cdr);
  // Member: bend
  {
    size_t size = ros_message.bend.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      bodyctrl_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.bend[i],
        cdr);
    }
  }
  // Member: threshold
  {
    cdr << ros_message.threshold;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bodyctrl_msgs::msg::SetTsHandCtrl & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: rotation
  bodyctrl_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.rotation);

  // Member: bend
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.bend.resize(size);
    for (size_t i = 0; i < size; i++) {
      bodyctrl_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.bend[i]);
    }
  }

  // Member: threshold
  {
    cdr >> ros_message.threshold;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
get_serialized_size(
  const bodyctrl_msgs::msg::SetTsHandCtrl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  {
    size_t item_size = sizeof(ros_message.name);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rotation

  current_alignment +=
    bodyctrl_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.rotation, current_alignment);
  // Member: bend
  {
    size_t array_size = ros_message.bend.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        bodyctrl_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.bend[index], current_alignment);
    }
  }
  // Member: threshold
  {
    size_t array_size = ros_message.threshold.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.threshold[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
max_serialized_size_SetTsHandCtrl(
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


  // Member: name
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rotation
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        bodyctrl_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_SetTsHandCtrlItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: bend
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        bodyctrl_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_SetTsHandCtrlItem(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: threshold
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
    using DataType = bodyctrl_msgs::msg::SetTsHandCtrl;
    is_plain =
      (
      offsetof(DataType, threshold) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SetTsHandCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::msg::SetTsHandCtrl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetTsHandCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bodyctrl_msgs::msg::SetTsHandCtrl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetTsHandCtrl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::msg::SetTsHandCtrl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetTsHandCtrl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetTsHandCtrl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetTsHandCtrl__callbacks = {
  "bodyctrl_msgs::msg",
  "SetTsHandCtrl",
  _SetTsHandCtrl__cdr_serialize,
  _SetTsHandCtrl__cdr_deserialize,
  _SetTsHandCtrl__get_serialized_size,
  _SetTsHandCtrl__max_serialized_size
};

static rosidl_message_type_support_t _SetTsHandCtrl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetTsHandCtrl__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace bodyctrl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bodyctrl_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<bodyctrl_msgs::msg::SetTsHandCtrl>()
{
  return &bodyctrl_msgs::msg::typesupport_fastrtps_cpp::_SetTsHandCtrl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, msg, SetTsHandCtrl)() {
  return &bodyctrl_msgs::msg::typesupport_fastrtps_cpp::_SetTsHandCtrl__handle;
}

#ifdef __cplusplus
}
#endif
