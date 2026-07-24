// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bodyctrl_msgs:msg/MotorStatusMsgPlate.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/msg/detail/motor_status_msg_plate__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bodyctrl_msgs/msg/detail/motor_status_msg_plate__struct.h"
#include "bodyctrl_msgs/msg/detail/motor_status_msg_plate__functions.h"
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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_bodyctrl_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_bodyctrl_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_bodyctrl_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _MotorStatusMsgPlate__ros_msg_type = bodyctrl_msgs__msg__MotorStatusMsgPlate;

static bool _MotorStatusMsgPlate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorStatusMsgPlate__ros_msg_type * ros_message = static_cast<const _MotorStatusMsgPlate__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: name1
  {
    cdr << ros_message->name1;
  }

  // Field name: pos1
  {
    cdr << ros_message->pos1;
  }

  // Field name: speed1
  {
    cdr << ros_message->speed1;
  }

  // Field name: current1
  {
    cdr << ros_message->current1;
  }

  // Field name: name2
  {
    cdr << ros_message->name2;
  }

  // Field name: pos2
  {
    cdr << ros_message->pos2;
  }

  // Field name: speed2
  {
    cdr << ros_message->speed2;
  }

  // Field name: current2
  {
    cdr << ros_message->current2;
  }

  // Field name: name3
  {
    cdr << ros_message->name3;
  }

  // Field name: pos3
  {
    cdr << ros_message->pos3;
  }

  // Field name: speed3
  {
    cdr << ros_message->speed3;
  }

  // Field name: current3
  {
    cdr << ros_message->current3;
  }

  // Field name: name4
  {
    cdr << ros_message->name4;
  }

  // Field name: pos4
  {
    cdr << ros_message->pos4;
  }

  // Field name: speed4
  {
    cdr << ros_message->speed4;
  }

  // Field name: current4
  {
    cdr << ros_message->current4;
  }

  // Field name: name5
  {
    cdr << ros_message->name5;
  }

  // Field name: pos5
  {
    cdr << ros_message->pos5;
  }

  // Field name: speed5
  {
    cdr << ros_message->speed5;
  }

  // Field name: current5
  {
    cdr << ros_message->current5;
  }

  // Field name: name6
  {
    cdr << ros_message->name6;
  }

  // Field name: pos6
  {
    cdr << ros_message->pos6;
  }

  // Field name: speed6
  {
    cdr << ros_message->speed6;
  }

  // Field name: current6
  {
    cdr << ros_message->current6;
  }

  // Field name: name7
  {
    cdr << ros_message->name7;
  }

  // Field name: pos7
  {
    cdr << ros_message->pos7;
  }

  // Field name: speed7
  {
    cdr << ros_message->speed7;
  }

  // Field name: current7
  {
    cdr << ros_message->current7;
  }

  // Field name: name8
  {
    cdr << ros_message->name8;
  }

  // Field name: pos8
  {
    cdr << ros_message->pos8;
  }

  // Field name: speed8
  {
    cdr << ros_message->speed8;
  }

  // Field name: current8
  {
    cdr << ros_message->current8;
  }

  // Field name: name9
  {
    cdr << ros_message->name9;
  }

  // Field name: pos9
  {
    cdr << ros_message->pos9;
  }

  // Field name: speed9
  {
    cdr << ros_message->speed9;
  }

  // Field name: current9
  {
    cdr << ros_message->current9;
  }

  // Field name: name10
  {
    cdr << ros_message->name10;
  }

  // Field name: pos10
  {
    cdr << ros_message->pos10;
  }

  // Field name: speed10
  {
    cdr << ros_message->speed10;
  }

  // Field name: current10
  {
    cdr << ros_message->current10;
  }

  // Field name: name11
  {
    cdr << ros_message->name11;
  }

  // Field name: pos11
  {
    cdr << ros_message->pos11;
  }

  // Field name: speed11
  {
    cdr << ros_message->speed11;
  }

  // Field name: current11
  {
    cdr << ros_message->current11;
  }

  // Field name: name12
  {
    cdr << ros_message->name12;
  }

  // Field name: pos12
  {
    cdr << ros_message->pos12;
  }

  // Field name: speed12
  {
    cdr << ros_message->speed12;
  }

  // Field name: current12
  {
    cdr << ros_message->current12;
  }

  return true;
}

static bool _MotorStatusMsgPlate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorStatusMsgPlate__ros_msg_type * ros_message = static_cast<_MotorStatusMsgPlate__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: name1
  {
    cdr >> ros_message->name1;
  }

  // Field name: pos1
  {
    cdr >> ros_message->pos1;
  }

  // Field name: speed1
  {
    cdr >> ros_message->speed1;
  }

  // Field name: current1
  {
    cdr >> ros_message->current1;
  }

  // Field name: name2
  {
    cdr >> ros_message->name2;
  }

  // Field name: pos2
  {
    cdr >> ros_message->pos2;
  }

  // Field name: speed2
  {
    cdr >> ros_message->speed2;
  }

  // Field name: current2
  {
    cdr >> ros_message->current2;
  }

  // Field name: name3
  {
    cdr >> ros_message->name3;
  }

  // Field name: pos3
  {
    cdr >> ros_message->pos3;
  }

  // Field name: speed3
  {
    cdr >> ros_message->speed3;
  }

  // Field name: current3
  {
    cdr >> ros_message->current3;
  }

  // Field name: name4
  {
    cdr >> ros_message->name4;
  }

  // Field name: pos4
  {
    cdr >> ros_message->pos4;
  }

  // Field name: speed4
  {
    cdr >> ros_message->speed4;
  }

  // Field name: current4
  {
    cdr >> ros_message->current4;
  }

  // Field name: name5
  {
    cdr >> ros_message->name5;
  }

  // Field name: pos5
  {
    cdr >> ros_message->pos5;
  }

  // Field name: speed5
  {
    cdr >> ros_message->speed5;
  }

  // Field name: current5
  {
    cdr >> ros_message->current5;
  }

  // Field name: name6
  {
    cdr >> ros_message->name6;
  }

  // Field name: pos6
  {
    cdr >> ros_message->pos6;
  }

  // Field name: speed6
  {
    cdr >> ros_message->speed6;
  }

  // Field name: current6
  {
    cdr >> ros_message->current6;
  }

  // Field name: name7
  {
    cdr >> ros_message->name7;
  }

  // Field name: pos7
  {
    cdr >> ros_message->pos7;
  }

  // Field name: speed7
  {
    cdr >> ros_message->speed7;
  }

  // Field name: current7
  {
    cdr >> ros_message->current7;
  }

  // Field name: name8
  {
    cdr >> ros_message->name8;
  }

  // Field name: pos8
  {
    cdr >> ros_message->pos8;
  }

  // Field name: speed8
  {
    cdr >> ros_message->speed8;
  }

  // Field name: current8
  {
    cdr >> ros_message->current8;
  }

  // Field name: name9
  {
    cdr >> ros_message->name9;
  }

  // Field name: pos9
  {
    cdr >> ros_message->pos9;
  }

  // Field name: speed9
  {
    cdr >> ros_message->speed9;
  }

  // Field name: current9
  {
    cdr >> ros_message->current9;
  }

  // Field name: name10
  {
    cdr >> ros_message->name10;
  }

  // Field name: pos10
  {
    cdr >> ros_message->pos10;
  }

  // Field name: speed10
  {
    cdr >> ros_message->speed10;
  }

  // Field name: current10
  {
    cdr >> ros_message->current10;
  }

  // Field name: name11
  {
    cdr >> ros_message->name11;
  }

  // Field name: pos11
  {
    cdr >> ros_message->pos11;
  }

  // Field name: speed11
  {
    cdr >> ros_message->speed11;
  }

  // Field name: current11
  {
    cdr >> ros_message->current11;
  }

  // Field name: name12
  {
    cdr >> ros_message->name12;
  }

  // Field name: pos12
  {
    cdr >> ros_message->pos12;
  }

  // Field name: speed12
  {
    cdr >> ros_message->speed12;
  }

  // Field name: current12
  {
    cdr >> ros_message->current12;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t get_serialized_size_bodyctrl_msgs__msg__MotorStatusMsgPlate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorStatusMsgPlate__ros_msg_type * ros_message = static_cast<const _MotorStatusMsgPlate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name name1
  {
    size_t item_size = sizeof(ros_message->name1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos1
  {
    size_t item_size = sizeof(ros_message->pos1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed1
  {
    size_t item_size = sizeof(ros_message->speed1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current1
  {
    size_t item_size = sizeof(ros_message->current1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name2
  {
    size_t item_size = sizeof(ros_message->name2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos2
  {
    size_t item_size = sizeof(ros_message->pos2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed2
  {
    size_t item_size = sizeof(ros_message->speed2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current2
  {
    size_t item_size = sizeof(ros_message->current2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name3
  {
    size_t item_size = sizeof(ros_message->name3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos3
  {
    size_t item_size = sizeof(ros_message->pos3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed3
  {
    size_t item_size = sizeof(ros_message->speed3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current3
  {
    size_t item_size = sizeof(ros_message->current3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name4
  {
    size_t item_size = sizeof(ros_message->name4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos4
  {
    size_t item_size = sizeof(ros_message->pos4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed4
  {
    size_t item_size = sizeof(ros_message->speed4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current4
  {
    size_t item_size = sizeof(ros_message->current4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name5
  {
    size_t item_size = sizeof(ros_message->name5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos5
  {
    size_t item_size = sizeof(ros_message->pos5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed5
  {
    size_t item_size = sizeof(ros_message->speed5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current5
  {
    size_t item_size = sizeof(ros_message->current5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name6
  {
    size_t item_size = sizeof(ros_message->name6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos6
  {
    size_t item_size = sizeof(ros_message->pos6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed6
  {
    size_t item_size = sizeof(ros_message->speed6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current6
  {
    size_t item_size = sizeof(ros_message->current6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name7
  {
    size_t item_size = sizeof(ros_message->name7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos7
  {
    size_t item_size = sizeof(ros_message->pos7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed7
  {
    size_t item_size = sizeof(ros_message->speed7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current7
  {
    size_t item_size = sizeof(ros_message->current7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name8
  {
    size_t item_size = sizeof(ros_message->name8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos8
  {
    size_t item_size = sizeof(ros_message->pos8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed8
  {
    size_t item_size = sizeof(ros_message->speed8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current8
  {
    size_t item_size = sizeof(ros_message->current8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name9
  {
    size_t item_size = sizeof(ros_message->name9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos9
  {
    size_t item_size = sizeof(ros_message->pos9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed9
  {
    size_t item_size = sizeof(ros_message->speed9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current9
  {
    size_t item_size = sizeof(ros_message->current9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name10
  {
    size_t item_size = sizeof(ros_message->name10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos10
  {
    size_t item_size = sizeof(ros_message->pos10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed10
  {
    size_t item_size = sizeof(ros_message->speed10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current10
  {
    size_t item_size = sizeof(ros_message->current10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name11
  {
    size_t item_size = sizeof(ros_message->name11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos11
  {
    size_t item_size = sizeof(ros_message->pos11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed11
  {
    size_t item_size = sizeof(ros_message->speed11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current11
  {
    size_t item_size = sizeof(ros_message->current11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name12
  {
    size_t item_size = sizeof(ros_message->name12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos12
  {
    size_t item_size = sizeof(ros_message->pos12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed12
  {
    size_t item_size = sizeof(ros_message->speed12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current12
  {
    size_t item_size = sizeof(ros_message->current12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorStatusMsgPlate__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bodyctrl_msgs__msg__MotorStatusMsgPlate(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t max_serialized_size_bodyctrl_msgs__msg__MotorStatusMsgPlate(
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

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: name1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name12
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pos12
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed12
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current12
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
    using DataType = bodyctrl_msgs__msg__MotorStatusMsgPlate;
    is_plain =
      (
      offsetof(DataType, current12) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MotorStatusMsgPlate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bodyctrl_msgs__msg__MotorStatusMsgPlate(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotorStatusMsgPlate = {
  "bodyctrl_msgs::msg",
  "MotorStatusMsgPlate",
  _MotorStatusMsgPlate__cdr_serialize,
  _MotorStatusMsgPlate__cdr_deserialize,
  _MotorStatusMsgPlate__get_serialized_size,
  _MotorStatusMsgPlate__max_serialized_size
};

static rosidl_message_type_support_t _MotorStatusMsgPlate__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorStatusMsgPlate,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, msg, MotorStatusMsgPlate)() {
  return &_MotorStatusMsgPlate__type_support;
}

#if defined(__cplusplus)
}
#endif
