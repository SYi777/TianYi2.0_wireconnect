// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:action/ReportMotion.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_HPP_
#define CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_Goal __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_Goal __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_Goal_
{
  using Type = ReportMotion_Goal_<ContainerAllocator>;

  explicit ReportMotion_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = "";
      this->json_data = "";
    }
  }

  explicit ReportMotion_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;
  using _json_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _json_data_type json_data;

  // setters for named parameter idiom
  Type & set__msg_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg_id = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__json_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->json_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Goal
    std::shared_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Goal
    std::shared_ptr<cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_Goal_ & other) const
  {
    if (this->msg_id != other.msg_id) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    if (this->json_data != other.json_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_Goal_

// alias to use template instance with default allocator
using ReportMotion_Goal =
  cm_msgs::action::ReportMotion_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs


#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_Result __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_Result __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_Result_
{
  using Type = ReportMotion_Result_<ContainerAllocator>;

  explicit ReportMotion_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->info = "";
    }
  }

  explicit ReportMotion_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    cm_msgs::action::ReportMotion_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Result
    std::shared_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Result
    std::shared_ptr<cm_msgs::action::ReportMotion_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_Result_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_Result_

// alias to use template instance with default allocator
using ReportMotion_Result =
  cm_msgs::action::ReportMotion_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs


#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_Feedback __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_Feedback_
{
  using Type = ReportMotion_Feedback_<ContainerAllocator>;

  explicit ReportMotion_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit ReportMotion_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Feedback
    std::shared_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_Feedback
    std::shared_ptr<cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_Feedback_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_Feedback_

// alias to use template instance with default allocator
using ReportMotion_Feedback =
  cm_msgs::action::ReportMotion_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "cm_msgs/action/detail/report_motion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Request __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_SendGoal_Request_
{
  using Type = ReportMotion_SendGoal_Request_<ContainerAllocator>;

  explicit ReportMotion_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit ReportMotion_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    cm_msgs::action::ReportMotion_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const cm_msgs::action::ReportMotion_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Request
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Request
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_SendGoal_Request_

// alias to use template instance with default allocator
using ReportMotion_SendGoal_Request =
  cm_msgs::action::ReportMotion_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Response __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_SendGoal_Response_
{
  using Type = ReportMotion_SendGoal_Response_<ContainerAllocator>;

  explicit ReportMotion_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit ReportMotion_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Response
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_SendGoal_Response
    std::shared_ptr<cm_msgs::action::ReportMotion_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_SendGoal_Response_

// alias to use template instance with default allocator
using ReportMotion_SendGoal_Response =
  cm_msgs::action::ReportMotion_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs

namespace cm_msgs
{

namespace action
{

struct ReportMotion_SendGoal
{
  using Request = cm_msgs::action::ReportMotion_SendGoal_Request;
  using Response = cm_msgs::action::ReportMotion_SendGoal_Response;
};

}  // namespace action

}  // namespace cm_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Request __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_GetResult_Request_
{
  using Type = ReportMotion_GetResult_Request_<ContainerAllocator>;

  explicit ReportMotion_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit ReportMotion_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Request
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Request
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_GetResult_Request_

// alias to use template instance with default allocator
using ReportMotion_GetResult_Request =
  cm_msgs::action::ReportMotion_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "cm_msgs/action/detail/report_motion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Response __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_GetResult_Response_
{
  using Type = ReportMotion_GetResult_Response_<ContainerAllocator>;

  explicit ReportMotion_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit ReportMotion_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    cm_msgs::action::ReportMotion_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const cm_msgs::action::ReportMotion_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Response
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_GetResult_Response
    std::shared_ptr<cm_msgs::action::ReportMotion_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_GetResult_Response_

// alias to use template instance with default allocator
using ReportMotion_GetResult_Response =
  cm_msgs::action::ReportMotion_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs

namespace cm_msgs
{

namespace action
{

struct ReportMotion_GetResult
{
  using Request = cm_msgs::action::ReportMotion_GetResult_Request;
  using Response = cm_msgs::action::ReportMotion_GetResult_Response;
};

}  // namespace action

}  // namespace cm_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "cm_msgs/action/detail/report_motion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__action__ReportMotion_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__action__ReportMotion_FeedbackMessage __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ReportMotion_FeedbackMessage_
{
  using Type = ReportMotion_FeedbackMessage_<ContainerAllocator>;

  explicit ReportMotion_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit ReportMotion_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const cm_msgs::action::ReportMotion_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__action__ReportMotion_FeedbackMessage
    std::shared_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__action__ReportMotion_FeedbackMessage
    std::shared_ptr<cm_msgs::action::ReportMotion_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReportMotion_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReportMotion_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReportMotion_FeedbackMessage_

// alias to use template instance with default allocator
using ReportMotion_FeedbackMessage =
  cm_msgs::action::ReportMotion_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cm_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace cm_msgs
{

namespace action
{

struct ReportMotion
{
  /// The goal message defined in the action definition.
  using Goal = cm_msgs::action::ReportMotion_Goal;
  /// The result message defined in the action definition.
  using Result = cm_msgs::action::ReportMotion_Result;
  /// The feedback message defined in the action definition.
  using Feedback = cm_msgs::action::ReportMotion_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = cm_msgs::action::ReportMotion_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = cm_msgs::action::ReportMotion_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = cm_msgs::action::ReportMotion_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct ReportMotion ReportMotion;

}  // namespace action

}  // namespace cm_msgs

#endif  // CM_MSGS__ACTION__DETAIL__REPORT_MOTION__STRUCT_HPP_
