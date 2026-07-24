// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bodyctrl_msgs:msg/PowerStatus.idl
// generated code does not contain a copyright notice
#include "bodyctrl_msgs/msg/detail/power_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bodyctrl_msgs/msg/detail/power_status__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace bodyctrl_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_serialize(
  const bodyctrl_msgs::msg::PowerStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: waist_temp
  cdr << ros_message.waist_temp;
  // Member: arm_a_temp
  cdr << ros_message.arm_a_temp;
  // Member: arm_b_temp
  cdr << ros_message.arm_b_temp;
  // Member: leg_a_temp
  cdr << ros_message.leg_a_temp;
  // Member: leg_b_temp
  cdr << ros_message.leg_b_temp;
  // Member: waist_temp_max
  cdr << ros_message.waist_temp_max;
  // Member: arm_a_temp_max
  cdr << ros_message.arm_a_temp_max;
  // Member: arm_b_temp_max
  cdr << ros_message.arm_b_temp_max;
  // Member: leg_a_temp_max
  cdr << ros_message.leg_a_temp_max;
  // Member: leg_b_temp_max
  cdr << ros_message.leg_b_temp_max;
  // Member: waist_temp_min
  cdr << ros_message.waist_temp_min;
  // Member: arm_a_temp_min
  cdr << ros_message.arm_a_temp_min;
  // Member: arm_b_temp_min
  cdr << ros_message.arm_b_temp_min;
  // Member: leg_a_temp_min
  cdr << ros_message.leg_a_temp_min;
  // Member: leg_b_temp_min
  cdr << ros_message.leg_b_temp_min;
  // Member: arm_a_curr
  cdr << ros_message.arm_a_curr;
  // Member: arm_b_curr
  cdr << ros_message.arm_b_curr;
  // Member: leg_a_curr
  cdr << ros_message.leg_a_curr;
  // Member: leg_b_curr
  cdr << ros_message.leg_b_curr;
  // Member: waist_curr
  cdr << ros_message.waist_curr;
  // Member: head_curr
  cdr << ros_message.head_curr;
  // Member: arm_a_curr_max
  cdr << ros_message.arm_a_curr_max;
  // Member: arm_b_curr_max
  cdr << ros_message.arm_b_curr_max;
  // Member: leg_a_curr_max
  cdr << ros_message.leg_a_curr_max;
  // Member: leg_b_curr_max
  cdr << ros_message.leg_b_curr_max;
  // Member: waist_curr_max
  cdr << ros_message.waist_curr_max;
  // Member: head_curr_max
  cdr << ros_message.head_curr_max;
  // Member: arm_a_curr_min
  cdr << ros_message.arm_a_curr_min;
  // Member: arm_b_curr_min
  cdr << ros_message.arm_b_curr_min;
  // Member: leg_a_curr_min
  cdr << ros_message.leg_a_curr_min;
  // Member: leg_b_curr_min
  cdr << ros_message.leg_b_curr_min;
  // Member: waist_curr_min
  cdr << ros_message.waist_curr_min;
  // Member: head_curr_min
  cdr << ros_message.head_curr_min;
  // Member: arm_a_volt
  cdr << ros_message.arm_a_volt;
  // Member: arm_b_volt
  cdr << ros_message.arm_b_volt;
  // Member: leg_a_volt
  cdr << ros_message.leg_a_volt;
  // Member: leg_b_volt
  cdr << ros_message.leg_b_volt;
  // Member: waist_volt
  cdr << ros_message.waist_volt;
  // Member: bus_volt
  cdr << ros_message.bus_volt;
  // Member: arm_a_volt_max
  cdr << ros_message.arm_a_volt_max;
  // Member: arm_b_volt_max
  cdr << ros_message.arm_b_volt_max;
  // Member: leg_a_volt_max
  cdr << ros_message.leg_a_volt_max;
  // Member: leg_b_volt_max
  cdr << ros_message.leg_b_volt_max;
  // Member: waist_volt_max
  cdr << ros_message.waist_volt_max;
  // Member: bus_volt_max
  cdr << ros_message.bus_volt_max;
  // Member: arm_a_volt_min
  cdr << ros_message.arm_a_volt_min;
  // Member: arm_b_volt_min
  cdr << ros_message.arm_b_volt_min;
  // Member: leg_a_volt_min
  cdr << ros_message.leg_a_volt_min;
  // Member: leg_b_volt_min
  cdr << ros_message.leg_b_volt_min;
  // Member: waist_volt_min
  cdr << ros_message.waist_volt_min;
  // Member: bus_volt_min
  cdr << ros_message.bus_volt_min;
  // Member: software_version
  cdr << ros_message.software_version;
  // Member: hardware_version
  cdr << ros_message.hardware_version;
  // Member: battery_voltage
  cdr << ros_message.battery_voltage;
  // Member: battery_current
  cdr << ros_message.battery_current;
  // Member: battery_power
  cdr << ros_message.battery_power;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bodyctrl_msgs::msg::PowerStatus & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: waist_temp
  cdr >> ros_message.waist_temp;

  // Member: arm_a_temp
  cdr >> ros_message.arm_a_temp;

  // Member: arm_b_temp
  cdr >> ros_message.arm_b_temp;

  // Member: leg_a_temp
  cdr >> ros_message.leg_a_temp;

  // Member: leg_b_temp
  cdr >> ros_message.leg_b_temp;

  // Member: waist_temp_max
  cdr >> ros_message.waist_temp_max;

  // Member: arm_a_temp_max
  cdr >> ros_message.arm_a_temp_max;

  // Member: arm_b_temp_max
  cdr >> ros_message.arm_b_temp_max;

  // Member: leg_a_temp_max
  cdr >> ros_message.leg_a_temp_max;

  // Member: leg_b_temp_max
  cdr >> ros_message.leg_b_temp_max;

  // Member: waist_temp_min
  cdr >> ros_message.waist_temp_min;

  // Member: arm_a_temp_min
  cdr >> ros_message.arm_a_temp_min;

  // Member: arm_b_temp_min
  cdr >> ros_message.arm_b_temp_min;

  // Member: leg_a_temp_min
  cdr >> ros_message.leg_a_temp_min;

  // Member: leg_b_temp_min
  cdr >> ros_message.leg_b_temp_min;

  // Member: arm_a_curr
  cdr >> ros_message.arm_a_curr;

  // Member: arm_b_curr
  cdr >> ros_message.arm_b_curr;

  // Member: leg_a_curr
  cdr >> ros_message.leg_a_curr;

  // Member: leg_b_curr
  cdr >> ros_message.leg_b_curr;

  // Member: waist_curr
  cdr >> ros_message.waist_curr;

  // Member: head_curr
  cdr >> ros_message.head_curr;

  // Member: arm_a_curr_max
  cdr >> ros_message.arm_a_curr_max;

  // Member: arm_b_curr_max
  cdr >> ros_message.arm_b_curr_max;

  // Member: leg_a_curr_max
  cdr >> ros_message.leg_a_curr_max;

  // Member: leg_b_curr_max
  cdr >> ros_message.leg_b_curr_max;

  // Member: waist_curr_max
  cdr >> ros_message.waist_curr_max;

  // Member: head_curr_max
  cdr >> ros_message.head_curr_max;

  // Member: arm_a_curr_min
  cdr >> ros_message.arm_a_curr_min;

  // Member: arm_b_curr_min
  cdr >> ros_message.arm_b_curr_min;

  // Member: leg_a_curr_min
  cdr >> ros_message.leg_a_curr_min;

  // Member: leg_b_curr_min
  cdr >> ros_message.leg_b_curr_min;

  // Member: waist_curr_min
  cdr >> ros_message.waist_curr_min;

  // Member: head_curr_min
  cdr >> ros_message.head_curr_min;

  // Member: arm_a_volt
  cdr >> ros_message.arm_a_volt;

  // Member: arm_b_volt
  cdr >> ros_message.arm_b_volt;

  // Member: leg_a_volt
  cdr >> ros_message.leg_a_volt;

  // Member: leg_b_volt
  cdr >> ros_message.leg_b_volt;

  // Member: waist_volt
  cdr >> ros_message.waist_volt;

  // Member: bus_volt
  cdr >> ros_message.bus_volt;

  // Member: arm_a_volt_max
  cdr >> ros_message.arm_a_volt_max;

  // Member: arm_b_volt_max
  cdr >> ros_message.arm_b_volt_max;

  // Member: leg_a_volt_max
  cdr >> ros_message.leg_a_volt_max;

  // Member: leg_b_volt_max
  cdr >> ros_message.leg_b_volt_max;

  // Member: waist_volt_max
  cdr >> ros_message.waist_volt_max;

  // Member: bus_volt_max
  cdr >> ros_message.bus_volt_max;

  // Member: arm_a_volt_min
  cdr >> ros_message.arm_a_volt_min;

  // Member: arm_b_volt_min
  cdr >> ros_message.arm_b_volt_min;

  // Member: leg_a_volt_min
  cdr >> ros_message.leg_a_volt_min;

  // Member: leg_b_volt_min
  cdr >> ros_message.leg_b_volt_min;

  // Member: waist_volt_min
  cdr >> ros_message.waist_volt_min;

  // Member: bus_volt_min
  cdr >> ros_message.bus_volt_min;

  // Member: software_version
  cdr >> ros_message.software_version;

  // Member: hardware_version
  cdr >> ros_message.hardware_version;

  // Member: battery_voltage
  cdr >> ros_message.battery_voltage;

  // Member: battery_current
  cdr >> ros_message.battery_current;

  // Member: battery_power
  cdr >> ros_message.battery_power;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
get_serialized_size(
  const bodyctrl_msgs::msg::PowerStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: waist_temp
  {
    size_t item_size = sizeof(ros_message.waist_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_temp
  {
    size_t item_size = sizeof(ros_message.arm_a_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_temp
  {
    size_t item_size = sizeof(ros_message.arm_b_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_temp
  {
    size_t item_size = sizeof(ros_message.leg_a_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_temp
  {
    size_t item_size = sizeof(ros_message.leg_b_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_temp_max
  {
    size_t item_size = sizeof(ros_message.waist_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_temp_max
  {
    size_t item_size = sizeof(ros_message.arm_a_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_temp_max
  {
    size_t item_size = sizeof(ros_message.arm_b_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_temp_max
  {
    size_t item_size = sizeof(ros_message.leg_a_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_temp_max
  {
    size_t item_size = sizeof(ros_message.leg_b_temp_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_temp_min
  {
    size_t item_size = sizeof(ros_message.waist_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_temp_min
  {
    size_t item_size = sizeof(ros_message.arm_a_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_temp_min
  {
    size_t item_size = sizeof(ros_message.arm_b_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_temp_min
  {
    size_t item_size = sizeof(ros_message.leg_a_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_temp_min
  {
    size_t item_size = sizeof(ros_message.leg_b_temp_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_curr
  {
    size_t item_size = sizeof(ros_message.arm_a_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_curr
  {
    size_t item_size = sizeof(ros_message.arm_b_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_curr
  {
    size_t item_size = sizeof(ros_message.leg_a_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_curr
  {
    size_t item_size = sizeof(ros_message.leg_b_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_curr
  {
    size_t item_size = sizeof(ros_message.waist_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: head_curr
  {
    size_t item_size = sizeof(ros_message.head_curr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_curr_max
  {
    size_t item_size = sizeof(ros_message.arm_a_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_curr_max
  {
    size_t item_size = sizeof(ros_message.arm_b_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_curr_max
  {
    size_t item_size = sizeof(ros_message.leg_a_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_curr_max
  {
    size_t item_size = sizeof(ros_message.leg_b_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_curr_max
  {
    size_t item_size = sizeof(ros_message.waist_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: head_curr_max
  {
    size_t item_size = sizeof(ros_message.head_curr_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_curr_min
  {
    size_t item_size = sizeof(ros_message.arm_a_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_curr_min
  {
    size_t item_size = sizeof(ros_message.arm_b_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_curr_min
  {
    size_t item_size = sizeof(ros_message.leg_a_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_curr_min
  {
    size_t item_size = sizeof(ros_message.leg_b_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_curr_min
  {
    size_t item_size = sizeof(ros_message.waist_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: head_curr_min
  {
    size_t item_size = sizeof(ros_message.head_curr_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_volt
  {
    size_t item_size = sizeof(ros_message.arm_a_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_volt
  {
    size_t item_size = sizeof(ros_message.arm_b_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_volt
  {
    size_t item_size = sizeof(ros_message.leg_a_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_volt
  {
    size_t item_size = sizeof(ros_message.leg_b_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_volt
  {
    size_t item_size = sizeof(ros_message.waist_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bus_volt
  {
    size_t item_size = sizeof(ros_message.bus_volt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_volt_max
  {
    size_t item_size = sizeof(ros_message.arm_a_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_volt_max
  {
    size_t item_size = sizeof(ros_message.arm_b_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_volt_max
  {
    size_t item_size = sizeof(ros_message.leg_a_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_volt_max
  {
    size_t item_size = sizeof(ros_message.leg_b_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_volt_max
  {
    size_t item_size = sizeof(ros_message.waist_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bus_volt_max
  {
    size_t item_size = sizeof(ros_message.bus_volt_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_a_volt_min
  {
    size_t item_size = sizeof(ros_message.arm_a_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arm_b_volt_min
  {
    size_t item_size = sizeof(ros_message.arm_b_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_a_volt_min
  {
    size_t item_size = sizeof(ros_message.leg_a_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg_b_volt_min
  {
    size_t item_size = sizeof(ros_message.leg_b_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: waist_volt_min
  {
    size_t item_size = sizeof(ros_message.waist_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bus_volt_min
  {
    size_t item_size = sizeof(ros_message.bus_volt_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: software_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.software_version.size() + 1);
  // Member: hardware_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.hardware_version.size() + 1);
  // Member: battery_voltage
  {
    size_t item_size = sizeof(ros_message.battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_current
  {
    size_t item_size = sizeof(ros_message.battery_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_power
  {
    size_t item_size = sizeof(ros_message.battery_power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bodyctrl_msgs
max_serialized_size_PowerStatus(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: waist_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_temp_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_temp_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: head_curr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: head_curr_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: head_curr_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bus_volt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bus_volt_max
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_a_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arm_b_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_a_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg_b_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: waist_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bus_volt_min
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: software_version
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

  // Member: hardware_version
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

  // Member: battery_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: battery_current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: battery_power
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
    using DataType = bodyctrl_msgs::msg::PowerStatus;
    is_plain =
      (
      offsetof(DataType, battery_power) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PowerStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::msg::PowerStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PowerStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bodyctrl_msgs::msg::PowerStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PowerStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bodyctrl_msgs::msg::PowerStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PowerStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PowerStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PowerStatus__callbacks = {
  "bodyctrl_msgs::msg",
  "PowerStatus",
  _PowerStatus__cdr_serialize,
  _PowerStatus__cdr_deserialize,
  _PowerStatus__get_serialized_size,
  _PowerStatus__max_serialized_size
};

static rosidl_message_type_support_t _PowerStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PowerStatus__callbacks,
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
get_message_type_support_handle<bodyctrl_msgs::msg::PowerStatus>()
{
  return &bodyctrl_msgs::msg::typesupport_fastrtps_cpp::_PowerStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bodyctrl_msgs, msg, PowerStatus)() {
  return &bodyctrl_msgs::msg::typesupport_fastrtps_cpp::_PowerStatus__handle;
}

#ifdef __cplusplus
}
#endif
