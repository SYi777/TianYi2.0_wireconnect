// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:srv/TrajectoryRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_HPP_
#define CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__TrajectoryRos2_Request __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__TrajectoryRos2_Request __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TrajectoryRos2_Request_
{
  using Type = TrajectoryRos2_Request_<ContainerAllocator>;

  explicit TrajectoryRos2_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = "";
    }
  }

  explicit TrajectoryRos2_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg_id(_alloc),
    trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = "";
    }
  }

  // field types and members
  using _msg_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_id_type msg_id;
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__msg_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg_id = _arg;
    return *this;
  }
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__TrajectoryRos2_Request
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__TrajectoryRos2_Request
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryRos2_Request_ & other) const
  {
    if (this->msg_id != other.msg_id) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryRos2_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryRos2_Request_

// alias to use template instance with default allocator
using TrajectoryRos2_Request =
  cm_msgs::srv::TrajectoryRos2_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs


#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__TrajectoryRos2_Response __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__TrajectoryRos2_Response __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TrajectoryRos2_Response_
{
  using Type = TrajectoryRos2_Response_<ContainerAllocator>;

  explicit TrajectoryRos2_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit TrajectoryRos2_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__TrajectoryRos2_Response
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__TrajectoryRos2_Response
    std::shared_ptr<cm_msgs::srv::TrajectoryRos2_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryRos2_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryRos2_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryRos2_Response_

// alias to use template instance with default allocator
using TrajectoryRos2_Response =
  cm_msgs::srv::TrajectoryRos2_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs

namespace cm_msgs
{

namespace srv
{

struct TrajectoryRos2
{
  using Request = cm_msgs::srv::TrajectoryRos2_Request;
  using Response = cm_msgs::srv::TrajectoryRos2_Response;
};

}  // namespace srv

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__TRAJECTORY_ROS2__STRUCT_HPP_
