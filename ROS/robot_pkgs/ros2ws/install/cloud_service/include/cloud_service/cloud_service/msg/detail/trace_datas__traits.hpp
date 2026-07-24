// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__TRAITS_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cloud_service/msg/detail/trace_datas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trace_array'
#include "cloud_service/msg/detail/trace_data__traits.hpp"

namespace cloud_service
{

namespace msg
{

inline void to_flow_style_yaml(
  const TraceDatas & msg,
  std::ostream & out)
{
  out << "{";
  // member: model
  {
    out << "model: ";
    rosidl_generator_traits::value_to_yaml(msg.model, out);
    out << ", ";
  }

  // member: event_name
  {
    out << "event_name: ";
    rosidl_generator_traits::value_to_yaml(msg.event_name, out);
    out << ", ";
  }

  // member: trace_array
  {
    if (msg.trace_array.size() == 0) {
      out << "trace_array: []";
    } else {
      out << "trace_array: [";
      size_t pending_items = msg.trace_array.size();
      for (auto item : msg.trace_array) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TraceDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: model
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model: ";
    rosidl_generator_traits::value_to_yaml(msg.model, out);
    out << "\n";
  }

  // member: event_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event_name: ";
    rosidl_generator_traits::value_to_yaml(msg.event_name, out);
    out << "\n";
  }

  // member: trace_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.trace_array.size() == 0) {
      out << "trace_array: []\n";
    } else {
      out << "trace_array:\n";
      for (auto item : msg.trace_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TraceDatas & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cloud_service

namespace rosidl_generator_traits
{

[[deprecated("use cloud_service::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cloud_service::msg::TraceDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  cloud_service::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cloud_service::msg::to_yaml() instead")]]
inline std::string to_yaml(const cloud_service::msg::TraceDatas & msg)
{
  return cloud_service::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cloud_service::msg::TraceDatas>()
{
  return "cloud_service::msg::TraceDatas";
}

template<>
inline const char * name<cloud_service::msg::TraceDatas>()
{
  return "cloud_service/msg/TraceDatas";
}

template<>
struct has_fixed_size<cloud_service::msg::TraceDatas>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cloud_service::msg::TraceDatas>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cloud_service::msg::TraceDatas>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__TRAITS_HPP_
