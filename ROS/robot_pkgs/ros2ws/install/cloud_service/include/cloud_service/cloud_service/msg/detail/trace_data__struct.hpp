// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cloud_service:msg/TraceData.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cloud_service__msg__TraceData __attribute__((deprecated))
#else
# define DEPRECATED__cloud_service__msg__TraceData __declspec(deprecated)
#endif

namespace cloud_service
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TraceData_
{
  using Type = TraceData_<ContainerAllocator>;

  explicit TraceData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->data_type = 0;
      this->int_val = 0l;
      this->str_val = "";
      this->bool_val = false;
      this->double_val = 0.0;
    }
  }

  explicit TraceData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : key(_alloc),
    str_val(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->data_type = 0;
      this->int_val = 0l;
      this->str_val = "";
      this->bool_val = false;
      this->double_val = 0.0;
    }
  }

  // field types and members
  using _key_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _key_type key;
  using _data_type_type =
    uint8_t;
  _data_type_type data_type;
  using _int_val_type =
    int32_t;
  _int_val_type int_val;
  using _str_val_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _str_val_type str_val;
  using _bool_val_type =
    bool;
  _bool_val_type bool_val;
  using _double_val_type =
    double;
  _double_val_type double_val;

  // setters for named parameter idiom
  Type & set__key(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__data_type(
    const uint8_t & _arg)
  {
    this->data_type = _arg;
    return *this;
  }
  Type & set__int_val(
    const int32_t & _arg)
  {
    this->int_val = _arg;
    return *this;
  }
  Type & set__str_val(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->str_val = _arg;
    return *this;
  }
  Type & set__bool_val(
    const bool & _arg)
  {
    this->bool_val = _arg;
    return *this;
  }
  Type & set__double_val(
    const double & _arg)
  {
    this->double_val = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TYPE_INT =
    0u;
  static constexpr uint8_t TYPE_STR =
    1u;
  static constexpr uint8_t TYPE_BOOL =
    2u;
  static constexpr uint8_t TYPE_DOUBLE =
    3u;

  // pointer types
  using RawPtr =
    cloud_service::msg::TraceData_<ContainerAllocator> *;
  using ConstRawPtr =
    const cloud_service::msg::TraceData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cloud_service::msg::TraceData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cloud_service::msg::TraceData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::TraceData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::TraceData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::TraceData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::TraceData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cloud_service::msg::TraceData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cloud_service::msg::TraceData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cloud_service__msg__TraceData
    std::shared_ptr<cloud_service::msg::TraceData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cloud_service__msg__TraceData
    std::shared_ptr<cloud_service::msg::TraceData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TraceData_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->data_type != other.data_type) {
      return false;
    }
    if (this->int_val != other.int_val) {
      return false;
    }
    if (this->str_val != other.str_val) {
      return false;
    }
    if (this->bool_val != other.bool_val) {
      return false;
    }
    if (this->double_val != other.double_val) {
      return false;
    }
    return true;
  }
  bool operator!=(const TraceData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TraceData_

// alias to use template instance with default allocator
using TraceData =
  cloud_service::msg::TraceData_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TraceData_<ContainerAllocator>::TYPE_INT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TraceData_<ContainerAllocator>::TYPE_STR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TraceData_<ContainerAllocator>::TYPE_BOOL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TraceData_<ContainerAllocator>::TYPE_DOUBLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__STRUCT_HPP_
