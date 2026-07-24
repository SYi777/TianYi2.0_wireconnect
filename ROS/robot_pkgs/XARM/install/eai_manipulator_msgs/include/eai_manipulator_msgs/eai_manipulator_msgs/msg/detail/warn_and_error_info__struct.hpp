// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__msg__WarnAndErrorInfo __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__msg__WarnAndErrorInfo __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WarnAndErrorInfo_
{
  using Type = WarnAndErrorInfo_<ContainerAllocator>;

  explicit WarnAndErrorInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->level = "";
      this->code = 0ul;
      this->source = "";
      this->info = "";
    }
  }

  explicit WarnAndErrorInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    level(_alloc),
    source(_alloc),
    info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->level = "";
      this->code = 0ul;
      this->source = "";
      this->info = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _level_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _level_type level;
  using _code_type =
    uint32_t;
  _code_type code;
  using _source_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type source;
  using _info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_type info;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__level(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->level = _arg;
    return *this;
  }
  Type & set__code(
    const uint32_t & _arg)
  {
    this->code = _arg;
    return *this;
  }
  Type & set__source(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source = _arg;
    return *this;
  }
  Type & set__info(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__msg__WarnAndErrorInfo
    std::shared_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__msg__WarnAndErrorInfo
    std::shared_ptr<eai_manipulator_msgs::msg::WarnAndErrorInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WarnAndErrorInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->level != other.level) {
      return false;
    }
    if (this->code != other.code) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const WarnAndErrorInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WarnAndErrorInfo_

// alias to use template instance with default allocator
using WarnAndErrorInfo =
  eai_manipulator_msgs::msg::WarnAndErrorInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__STRUCT_HPP_
