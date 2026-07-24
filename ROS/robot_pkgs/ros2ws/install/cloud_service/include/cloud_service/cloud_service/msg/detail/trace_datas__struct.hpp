// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trace_array'
#include "cloud_service/msg/detail/trace_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cloud_service__msg__TraceDatas __attribute__((deprecated))
#else
# define DEPRECATED__cloud_service__msg__TraceDatas __declspec(deprecated)
#endif

namespace cloud_service
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TraceDatas_
{
  using Type = TraceDatas_<ContainerAllocator>;

  explicit TraceDatas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model = "";
      this->event_name = "";
    }
  }

  explicit TraceDatas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : model(_alloc),
    event_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model = "";
      this->event_name = "";
    }
  }

  // field types and members
  using _model_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_type model;
  using _event_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _event_name_type event_name;
  using _trace_array_type =
    std::vector<cloud_service::msg::TraceData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cloud_service::msg::TraceData_<ContainerAllocator>>>;
  _trace_array_type trace_array;

  // setters for named parameter idiom
  Type & set__model(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model = _arg;
    return *this;
  }
  Type & set__event_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->event_name = _arg;
    return *this;
  }
  Type & set__trace_array(
    const std::vector<cloud_service::msg::TraceData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cloud_service::msg::TraceData_<ContainerAllocator>>> & _arg)
  {
    this->trace_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cloud_service::msg::TraceDatas_<ContainerAllocator> *;
  using ConstRawPtr =
    const cloud_service::msg::TraceDatas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::TraceDatas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::TraceDatas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cloud_service__msg__TraceDatas
    std::shared_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cloud_service__msg__TraceDatas
    std::shared_ptr<cloud_service::msg::TraceDatas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TraceDatas_ & other) const
  {
    if (this->model != other.model) {
      return false;
    }
    if (this->event_name != other.event_name) {
      return false;
    }
    if (this->trace_array != other.trace_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const TraceDatas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TraceDatas_

// alias to use template instance with default allocator
using TraceDatas =
  cloud_service::msg::TraceDatas_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__STRUCT_HPP_
