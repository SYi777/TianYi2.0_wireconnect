// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:srv/WaypointsRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_HPP_
#define CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'left_waypoints'
// Member 'right_waypoints'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__WaypointsRos2_Request __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__WaypointsRos2_Request __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct WaypointsRos2_Request_
{
  using Type = WaypointsRos2_Request_<ContainerAllocator>;

  explicit WaypointsRos2_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit WaypointsRos2_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _left_waypoints_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _left_waypoints_type left_waypoints;
  using _right_waypoints_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _right_waypoints_type right_waypoints;

  // setters for named parameter idiom
  Type & set__left_waypoints(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->left_waypoints = _arg;
    return *this;
  }
  Type & set__right_waypoints(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->right_waypoints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__WaypointsRos2_Request
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__WaypointsRos2_Request
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WaypointsRos2_Request_ & other) const
  {
    if (this->left_waypoints != other.left_waypoints) {
      return false;
    }
    if (this->right_waypoints != other.right_waypoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const WaypointsRos2_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WaypointsRos2_Request_

// alias to use template instance with default allocator
using WaypointsRos2_Request =
  cm_msgs::srv::WaypointsRos2_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs


#ifndef _WIN32
# define DEPRECATED__cm_msgs__srv__WaypointsRos2_Response __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__srv__WaypointsRos2_Response __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct WaypointsRos2_Response_
{
  using Type = WaypointsRos2_Response_<ContainerAllocator>;

  explicit WaypointsRos2_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit WaypointsRos2_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__srv__WaypointsRos2_Response
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__srv__WaypointsRos2_Response
    std::shared_ptr<cm_msgs::srv::WaypointsRos2_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WaypointsRos2_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const WaypointsRos2_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WaypointsRos2_Response_

// alias to use template instance with default allocator
using WaypointsRos2_Response =
  cm_msgs::srv::WaypointsRos2_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cm_msgs

namespace cm_msgs
{

namespace srv
{

struct WaypointsRos2
{
  using Request = cm_msgs::srv::WaypointsRos2_Request;
  using Response = cm_msgs::srv::WaypointsRos2_Response;
};

}  // namespace srv

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__WAYPOINTS_ROS2__STRUCT_HPP_
