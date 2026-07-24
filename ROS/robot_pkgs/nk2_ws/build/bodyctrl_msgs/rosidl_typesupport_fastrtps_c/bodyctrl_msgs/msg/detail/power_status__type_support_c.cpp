// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bodyctrl_msgs:msg/PowerStatus.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/msg/detail/power_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bodyctrl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bodyctrl_msgs/msg/detail/power_status__struct.h"
#include "bodyctrl_msgs/msg/detail/power_status__functions.h"
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

#include "rosidl_runtime_c/string.h"  // hardware_version, software_version
#include "rosidl_runtime_c/string_functions.h"  // hardware_version, software_version
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


using _PowerStatus__ros_msg_type = bodyctrl_msgs__msg__PowerStatus;

static bool _PowerStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PowerStatus__ros_msg_type * ros_message = static_cast<const _PowerStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: waist_temp
  {
    cdr << ros_message->waist_temp;
  }

  // Field name: arm_a_temp
  {
    cdr << ros_message->arm_a_temp;
  }

  // Field name: arm_b_temp
  {
    cdr << ros_message->arm_b_temp;
  }

  // Field name: leg_a_temp
  {
    cdr << ros_message->leg_a_temp;
  }

  // Field name: leg_b_temp
  {
    cdr << ros_message->leg_b_temp;
  }

  // Field name: waist_temp_max
  {
    cdr << ros_message->waist_temp_max;
  }

  // Field name: arm_a_temp_max
  {
    cdr << ros_message->arm_a_temp_max;
  }

  // Field name: arm_b_temp_max
  {
    cdr << ros_message->arm_b_temp_max;
  }

  // Field name: leg_a_temp_max
  {
    cdr << ros_message->leg_a_temp_max;
  }

  // Field name: leg_b_temp_max
  {
    cdr << ros_message->leg_b_temp_max;
  }

  // Field name: waist_temp_min
  {
    cdr << ros_message->waist_temp_min;
  }

  // Field name: arm_a_temp_min
  {
    cdr << ros_message->arm_a_temp_min;
  }

  // Field name: arm_b_temp_min
  {
    cdr << ros_message->arm_b_temp_min;
  }

  // Field name: leg_a_temp_min
  {
    cdr << ros_message->leg_a_temp_min;
  }

  // Field name: leg_b_temp_min
  {
    cdr << ros_message->leg_b_temp_min;
  }

  // Field name: arm_a_curr
  {
    cdr << ros_message->arm_a_curr;
  }

  // Field name: arm_b_curr
  {
    cdr << ros_message->arm_b_curr;
  }

  // Field name: leg_a_curr
  {
    cdr << ros_message->leg_a_curr;
  }

  // Field name: leg_b_curr
  {
    cdr << ros_message->leg_b_curr;
  }

  // Field name: waist_curr
  {
    cdr << ros_message->waist_curr;
  }

  // Field name: head_curr
  {
    cdr << ros_message->head_curr;
  }

  // Field name: arm_a_curr_max
  {
    cdr << ros_message->arm_a_curr_max;
  }

  // Field name: arm_b_curr_max
  {
    cdr << ros_message->arm_b_curr_max;
  }

  // Field name: leg_a_curr_max
  {
    cdr << ros_message->leg_a_curr_max;
  }

  // Field name: leg_b_curr_max
  {
    cdr << ros_message->leg_b_curr_max;
  }

  // Field name: waist_curr_max
  {
    cdr << ros_message->waist_curr_max;
  }

  // Field name: head_curr_max
  {
    cdr << ros_message->head_curr_max;
  }

  // Field name: arm_a_curr_min
  {
    cdr << ros_message->arm_a_curr_min;
  }

  // Field name: arm_b_curr_min
  {
    cdr << ros_message->arm_b_curr_min;
  }

  // Field name: leg_a_curr_min
  {
    cdr << ros_message->leg_a_curr_min;
  }

  // Field name: leg_b_curr_min
  {
    cdr << ros_message->leg_b_curr_min;
  }

  // Field name: waist_curr_min
  {
    cdr << ros_message->waist_curr_min;
  }

  // Field name: head_curr_min
  {
    cdr << ros_message->head_curr_min;
  }

  // Field name: arm_a_volt
  {
    cdr << ros_message->arm_a_volt;
  }

  // Field name: arm_b_volt
  {
    cdr << ros_message->arm_b_volt;
  }

  // Field name: leg_a_volt
  {
    cdr << ros_message->leg_a_volt;
  }

  // Field name: leg_b_volt
  {
    cdr << ros_message->leg_b_volt;
  }

  // Field name: waist_volt
  {
    cdr << ros_message->waist_volt;
  }

  // Field name: bus_volt
  {
    cdr << ros_message->bus_volt;
  }

  // Field name: arm_a_volt_max
  {
    cdr << ros_message->arm_a_volt_max;
  }

  // Field name: arm_b_volt_max
  {
    cdr << ros_message->arm_b_volt_max;
  }

  // Field name: leg_a_volt_max
  {
    cdr << ros_message->leg_a_volt_max;
  }

  // Field name: leg_b_volt_max
  {
    cdr << ros_message->leg_b_volt_max;
  }

  // Field name: waist_volt_max
  {
    cdr << ros_message->waist_volt_max;
  }

  // Field name: bus_volt_max
  {
    cdr << ros_message->bus_volt_max;
  }

  // Field name: arm_a_volt_min
  {
    cdr << ros_message->arm_a_volt_min;
  }

  // Field name: arm_b_volt_min
  {
    cdr << ros_message->arm_b_volt_min;
  }

  // Field name: leg_a_volt_min
  {
    cdr << ros_message->leg_a_volt_min;
  }

  // Field name: leg_b_volt_min
  {
    cdr << ros_message->leg_b_volt_min;
  }

  // Field name: waist_volt_min
  {
    cdr << ros_message->waist_volt_min;
  }

  // Field name: bus_volt_min
  {
    cdr << ros_message->bus_volt_min;
  }

  // Field name: software_version
  {
    const rosidl_runtime_c__String * str = &ros_message->software_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: hardware_version
  {
    const rosidl_runtime_c__String * str = &ros_message->hardware_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: battery_voltage
  {
    cdr << ros_message->battery_voltage;
  }

  // Field name: battery_current
  {
    cdr << ros_message->battery_current;
  }

  // Field name: battery_power
  {
    cdr << ros_message->battery_power;
  }

  return true;
}

static bool _PowerStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PowerStatus__ros_msg_type * ros_message = static_cast<_PowerStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: waist_temp
  {
    cdr >> ros_message->waist_temp;
  }

  // Field name: arm_a_temp
  {
    cdr >> ros_message->arm_a_temp;
  }

  // Field name: arm_b_temp
  {
    cdr >> ros_message->arm_b_temp;
  }

  // Field name: leg_a_temp
  {
    cdr >> ros_message->leg_a_temp;
  }

  // Field name: leg_b_temp
  {
    cdr >> ros_message->leg_b_temp;
  }

  // Field name: waist_temp_max
  {
    cdr >> ros_message->waist_temp_max;
  }

  // Field name: arm_a_temp_max
  {
    cdr >> ros_message->arm_a_temp_max;
  }

  // Field name: arm_b_temp_max
  {
    cdr >> ros_message->arm_b_temp_max;
  }

  // Field name: leg_a_temp_max
  {
    cdr >> ros_message->leg_a_temp_max;
  }

  // Field name: leg_b_temp_max
  {
    cdr >> ros_message->leg_b_temp_max;
  }

  // Field name: waist_temp_min
  {
    cdr >> ros_message->waist_temp_min;
  }

  // Field name: arm_a_temp_min
  {
    cdr >> ros_message->arm_a_temp_min;
  }

  // Field name: arm_b_temp_min
  {
    cdr >> ros_message->arm_b_temp_min;
  }

  // Field name: leg_a_temp_min
  {
    cdr >> ros_message->leg_a_temp_min;
  }

  // Field name: leg_b_temp_min
  {
    cdr >> ros_message->leg_b_temp_min;
  }

  // Field name: arm_a_curr
  {
    cdr >> ros_message->arm_a_curr;
  }

  // Field name: arm_b_curr
  {
    cdr >> ros_message->arm_b_curr;
  }

  // Field name: leg_a_curr
  {
    cdr >> ros_message->leg_a_curr;
  }

  // Field name: leg_b_curr
  {
    cdr >> ros_message->leg_b_curr;
  }

  // Field name: waist_curr
  {
    cdr >> ros_message->waist_curr;
  }

  // Field name: head_curr
  {
    cdr >> ros_message->head_curr;
  }

  // Field name: arm_a_curr_max
  {
    cdr >> ros_message->arm_a_curr_max;
  }

  // Field name: arm_b_curr_max
  {
    cdr >> ros_message->arm_b_curr_max;
  }

  // Field name: leg_a_curr_max
  {
    cdr >> ros_message->leg_a_curr_max;
  }

  // Field name: leg_b_curr_max
  {
    cdr >> ros_message->leg_b_curr_max;
  }

  // Field name: waist_curr_max
  {
    cdr >> ros_message->waist_curr_max;
  }

  // Field name: head_curr_max
  {
    cdr >> ros_message->head_curr_max;
  }

  // Field name: arm_a_curr_min
  {
    cdr >> ros_message->arm_a_curr_min;
  }

  // Field name: arm_b_curr_min
  {
    cdr >> ros_message->arm_b_curr_min;
  }

  // Field name: leg_a_curr_min
  {
    cdr >> ros_message->leg_a_curr_min;
  }

  // Field name: leg_b_curr_min
  {
    cdr >> ros_message->leg_b_curr_min;
  }

  // Field name: waist_curr_min
  {
    cdr >> ros_message->waist_curr_min;
  }

  // Field name: head_curr_min
  {
    cdr >> ros_message->head_curr_min;
  }

  // Field name: arm_a_volt
  {
    cdr >> ros_message->arm_a_volt;
  }

  // Field name: arm_b_volt
  {
    cdr >> ros_message->arm_b_volt;
  }

  // Field name: leg_a_volt
  {
    cdr >> ros_message->leg_a_volt;
  }

  // Field name: leg_b_volt
  {
    cdr >> ros_message->leg_b_volt;
  }

  // Field name: waist_volt
  {
    cdr >> ros_message->waist_volt;
  }

  // Field name: bus_volt
  {
    cdr >> ros_message->bus_volt;
  }

  // Field name: arm_a_volt_max
  {
    cdr >> ros_message->arm_a_volt_max;
  }

  // Field name: arm_b_volt_max
  {
    cdr >> ros_message->arm_b_volt_max;
  }

  // Field name: leg_a_volt_max
  {
    cdr >> ros_message->leg_a_volt_max;
  }

  // Field name: leg_b_volt_max
  {
    cdr >> ros_message->leg_b_volt_max;
  }

  // Field name: waist_volt_max
  {
    cdr >> ros_message->waist_volt_max;
  }

  // Field name: bus_volt_max
  {
    cdr >> ros_message->bus_volt_max;
  }

  // Field name: arm_a_volt_min
  {
    cdr >> ros_message->arm_a_volt_min;
  }

  // Field name: arm_b_volt_min
  {
    cdr >> ros_message->arm_b_volt_min;
  }

  // Field name: leg_a_volt_min
  {
    cdr >> ros_message->leg_a_volt_min;
  }

  // Field name: leg_b_volt_min
  {
    cdr >> ros_message->leg_b_volt_min;
  }

  // Field name: waist_volt_min
  {
    cdr >> ros_message->waist_volt_min;
  }

  // Field name: bus_volt_min
  {
    cdr >> ros_message->bus_volt_min;
  }

  // Field name: software_version
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->software_version.data) {
      rosidl_runtime_c__String__init(&ros_message->software_version);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->software_version,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'software_version'\n");
      return false;
    }
  }

  // Field name: hardware_version
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->hardware_version.data) {
      rosidl_runtime_c__String__init(&ros_message->hardware_version);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->hardware_version,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'hardware_version'\n");
      return false;
    }
  }

  // Field name: battery_voltage
  {
    cdr >> ros_message->battery_voltage;
  }

  // Field name: battery_current
  {
    cdr >> ros_message->battery_current;
  }

  // Field name: battery_power
  {
    cdr >> ros_message->battery_power;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t get_serialized_size_bodyctrl_msgs__msg__PowerStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PowerStatus__ros_msg_type * ros_message = static_cast<const _PowerStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name waist_temp
  {
    size_t item_size = sizeof(ros_message->waist_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_temp
  {
    size_t item_size = sizeof(ros_message->arm_a_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_temp
  {
    size_t item_size = sizeof(ros_message->arm_b_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_temp
  {
    size_t item_size = sizeof(ros_message->leg_a_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_temp
  {
    size_t item_size = sizeof(ros_message->leg_b_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_temp_max
  {
    size_t item_size = sizeof(ros_message->waist_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_temp_max
  {
    size_t item_size = sizeof(ros_message->arm_a_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_temp_max
  {
    size_t item_size = sizeof(ros_message->arm_b_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_temp_max
  {
    size_t item_size = sizeof(ros_message->leg_a_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_temp_max
  {
    size_t item_size = sizeof(ros_message->leg_b_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_temp_min
  {
    size_t item_size = sizeof(ros_message->waist_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_temp_min
  {
    size_t item_size = sizeof(ros_message->arm_a_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_temp_min
  {
    size_t item_size = sizeof(ros_message->arm_b_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_temp_min
  {
    size_t item_size = sizeof(ros_message->leg_a_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_temp_min
  {
    size_t item_size = sizeof(ros_message->leg_b_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_curr
  {
    size_t item_size = sizeof(ros_message->arm_a_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_curr
  {
    size_t item_size = sizeof(ros_message->arm_b_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_curr
  {
    size_t item_size = sizeof(ros_message->leg_a_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_curr
  {
    size_t item_size = sizeof(ros_message->leg_b_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_curr
  {
    size_t item_size = sizeof(ros_message->waist_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name head_curr
  {
    size_t item_size = sizeof(ros_message->head_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_curr_max
  {
    size_t item_size = sizeof(ros_message->arm_a_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_curr_max
  {
    size_t item_size = sizeof(ros_message->arm_b_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_curr_max
  {
    size_t item_size = sizeof(ros_message->leg_a_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_curr_max
  {
    size_t item_size = sizeof(ros_message->leg_b_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_curr_max
  {
    size_t item_size = sizeof(ros_message->waist_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name head_curr_max
  {
    size_t item_size = sizeof(ros_message->head_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_curr_min
  {
    size_t item_size = sizeof(ros_message->arm_a_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_curr_min
  {
    size_t item_size = sizeof(ros_message->arm_b_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_curr_min
  {
    size_t item_size = sizeof(ros_message->leg_a_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_curr_min
  {
    size_t item_size = sizeof(ros_message->leg_b_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_curr_min
  {
    size_t item_size = sizeof(ros_message->waist_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name head_curr_min
  {
    size_t item_size = sizeof(ros_message->head_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_volt
  {
    size_t item_size = sizeof(ros_message->arm_a_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_volt
  {
    size_t item_size = sizeof(ros_message->arm_b_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_volt
  {
    size_t item_size = sizeof(ros_message->leg_a_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_volt
  {
    size_t item_size = sizeof(ros_message->leg_b_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_volt
  {
    size_t item_size = sizeof(ros_message->waist_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bus_volt
  {
    size_t item_size = sizeof(ros_message->bus_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_volt_max
  {
    size_t item_size = sizeof(ros_message->arm_a_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_volt_max
  {
    size_t item_size = sizeof(ros_message->arm_b_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_volt_max
  {
    size_t item_size = sizeof(ros_message->leg_a_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_volt_max
  {
    size_t item_size = sizeof(ros_message->leg_b_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_volt_max
  {
    size_t item_size = sizeof(ros_message->waist_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bus_volt_max
  {
    size_t item_size = sizeof(ros_message->bus_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_a_volt_min
  {
    size_t item_size = sizeof(ros_message->arm_a_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_b_volt_min
  {
    size_t item_size = sizeof(ros_message->arm_b_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_a_volt_min
  {
    size_t item_size = sizeof(ros_message->leg_a_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_b_volt_min
  {
    size_t item_size = sizeof(ros_message->leg_b_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name waist_volt_min
  {
    size_t item_size = sizeof(ros_message->waist_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bus_volt_min
  {
    size_t item_size = sizeof(ros_message->bus_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name software_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->software_version.size + 1);
  // field.name hardware_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->hardware_version.size + 1);
  // field.name battery_voltage
  {
    size_t item_size = sizeof(ros_message->battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_current
  {
    size_t item_size = sizeof(ros_message->battery_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_power
  {
    size_t item_size = sizeof(ros_message->battery_power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PowerStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bodyctrl_msgs__msg__PowerStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bodyctrl_msgs
size_t max_serialized_size_bodyctrl_msgs__msg__PowerStatus(
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
  // member: waist_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: head_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: head_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: head_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bus_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bus_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_a_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_b_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_a_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg_b_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: waist_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bus_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: software_version
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: hardware_version
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: battery_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: battery_current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: battery_power
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
    using DataType = bodyctrl_msgs__msg__PowerStatus;
    is_plain =
      (
      offsetof(DataType, battery_power) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PowerStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_bodyctrl_msgs__msg__PowerStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PowerStatus = {
  "bodyctrl_msgs::msg",
  "PowerStatus",
  _PowerStatus__cdr_serialize,
  _PowerStatus__cdr_deserialize,
  _PowerStatus__get_serialized_size,
  _PowerStatus__max_serialized_size
};

static rosidl_message_type_support_t _PowerStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PowerStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bodyctrl_msgs, msg, PowerStatus)() {
  return &_PowerStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
