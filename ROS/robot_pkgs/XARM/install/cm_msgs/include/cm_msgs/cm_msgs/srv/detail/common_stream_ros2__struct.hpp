// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:srv/CommonStreamRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__STRUCT_HPP_
#define CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__CommonStreamRos2_Request __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__CommonStreamRos2_Request __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CommonStreamRos2_Request_
{
  using Type = CommonStreamRos2_Request_<ContainerAllocator>;

  explicit CommonStreamRos2_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = "";
      this->json_data = "";
    }
  }

  explicit CommonStreamRos2_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg_id(_alloc),
    json_data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = "";
      this->json_data = "";
    }
  }

  // field types and members
  using _msg_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_id_type msg_id;
  using _json_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _json_data_type json_data;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__msg_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg_id = _arg;
    return *this;
  }
  Type & set__json_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->json_data = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__CommonStreamRos2_Request
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__CommonStreamRos2_Request
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CommonStreamRos2_Request_ & other) const
  {
    if (this->msg_id != other.msg_id) {
      return false;
    }
    if (this->json_data != other.json_data) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CommonStreamRos2_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CommonStreamRos2_Request_

// alias to use template instance with default allocator
using CommonStreamRos2_Request =
  cm_msgs::srv::CommonStreamRos2_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs


#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__CommonStreamRos2_Response __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__CommonStreamRos2_Response __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CommonStreamRos2_Response_
{
  using Type = CommonStreamRos2_Response_<ContainerAllocator>;

  explicit CommonStreamRos2_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->info = "";
    }
  }

  explicit CommonStreamRos2_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->info = "";
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;
  using _info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_type info;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
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
    cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__CommonStreamRos2_Response
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__CommonStreamRos2_Response
    std::shared_ptr<cm_msgs::srv::CommonStreamRos2_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CommonStreamRos2_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const CommonStreamRos2_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CommonStreamRos2_Response_

// alias to use template instance with default allocator
using CommonStreamRos2_Response =
  cm_msgs::srv::CommonStreamRos2_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs

namespace cm_msgs
{

namespace srv
{

struct CommonStreamRos2
{
  using Request = cm_msgs::srv::CommonStreamRos2_Request;
  using Response = cm_msgs::srv::CommonStreamRos2_Response;
};

}  // namespace srv

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__STRUCT_HPP_
