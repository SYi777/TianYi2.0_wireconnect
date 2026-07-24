// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from eai_manipulator_msgs:action/JointSpace.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_HPP_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Goal __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Goal __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_Goal_
{
  using Type = JointSpace_Goal_<ContainerAllocator>;

  explicit JointSpace_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit JointSpace_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _target_positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _target_positions_type target_positions;

  // setters for named parameter idiom
  Type & set__target_positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->target_positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Goal
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Goal
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_Goal_ & other) const
  {
    if (this->target_positions != other.target_positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_Goal_

// alias to use template instance with default allocator
using JointSpace_Goal =
  eai_manipulator_msgs::action::JointSpace_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs


#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Result __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Result __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_Result_
{
  using Type = JointSpace_Result_<ContainerAllocator>;

  explicit JointSpace_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->result_msg = "";
    }
  }

  explicit JointSpace_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result_msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->result_msg = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _result_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_msg_type result_msg;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__result_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Result
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Result
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->result_msg != other.result_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_Result_

// alias to use template instance with default allocator
using JointSpace_Result =
  eai_manipulator_msgs::action::JointSpace_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs


#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_Feedback __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_Feedback_
{
  using Type = JointSpace_Feedback_<ContainerAllocator>;

  explicit JointSpace_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_msg = "";
    }
  }

  explicit JointSpace_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feedback_msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_msg = "";
    }
  }

  // field types and members
  using _current_positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _current_positions_type current_positions;
  using _feedback_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feedback_msg_type feedback_msg;

  // setters for named parameter idiom
  Type & set__current_positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->current_positions = _arg;
    return *this;
  }
  Type & set__feedback_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feedback_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Feedback
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_Feedback
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_Feedback_ & other) const
  {
    if (this->current_positions != other.current_positions) {
      return false;
    }
    if (this->feedback_msg != other.feedback_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_Feedback_

// alias to use template instance with default allocator
using JointSpace_Feedback =
  eai_manipulator_msgs::action::JointSpace_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "eai_manipulator_msgs/action/detail/joint_space__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Request __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_SendGoal_Request_
{
  using Type = JointSpace_SendGoal_Request_<ContainerAllocator>;

  explicit JointSpace_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit JointSpace_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const eai_manipulator_msgs::action::JointSpace_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Request
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Request
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_SendGoal_Request_

// alias to use template instance with default allocator
using JointSpace_SendGoal_Request =
  eai_manipulator_msgs::action::JointSpace_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Response __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_SendGoal_Response_
{
  using Type = JointSpace_SendGoal_Response_<ContainerAllocator>;

  explicit JointSpace_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit JointSpace_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Response
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_SendGoal_Response
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_SendGoal_Response_

// alias to use template instance with default allocator
using JointSpace_SendGoal_Response =
  eai_manipulator_msgs::action::JointSpace_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace eai_manipulator_msgs
{

namespace action
{

struct JointSpace_SendGoal
{
  using Request = eai_manipulator_msgs::action::JointSpace_SendGoal_Request;
  using Response = eai_manipulator_msgs::action::JointSpace_SendGoal_Response;
};

}  // namespace action

}  // namespace eai_manipulator_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Request __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_GetResult_Request_
{
  using Type = JointSpace_GetResult_Request_<ContainerAllocator>;

  explicit JointSpace_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit JointSpace_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Request
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Request
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_GetResult_Request_

// alias to use template instance with default allocator
using JointSpace_GetResult_Request =
  eai_manipulator_msgs::action::JointSpace_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "eai_manipulator_msgs/action/detail/joint_space__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Response __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_GetResult_Response_
{
  using Type = JointSpace_GetResult_Response_<ContainerAllocator>;

  explicit JointSpace_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit JointSpace_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const eai_manipulator_msgs::action::JointSpace_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Response
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_GetResult_Response
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_GetResult_Response_

// alias to use template instance with default allocator
using JointSpace_GetResult_Response =
  eai_manipulator_msgs::action::JointSpace_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs

namespace eai_manipulator_msgs
{

namespace action
{

struct JointSpace_GetResult
{
  using Request = eai_manipulator_msgs::action::JointSpace_GetResult_Request;
  using Response = eai_manipulator_msgs::action::JointSpace_GetResult_Response;
};

}  // namespace action

}  // namespace eai_manipulator_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "eai_manipulator_msgs/action/detail/joint_space__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__action__JointSpace_FeedbackMessage __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointSpace_FeedbackMessage_
{
  using Type = JointSpace_FeedbackMessage_<ContainerAllocator>;

  explicit JointSpace_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit JointSpace_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const eai_manipulator_msgs::action::JointSpace_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_FeedbackMessage
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__action__JointSpace_FeedbackMessage
    std::shared_ptr<eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_FeedbackMessage_

// alias to use template instance with default allocator
using JointSpace_FeedbackMessage =
  eai_manipulator_msgs::action::JointSpace_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace eai_manipulator_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace eai_manipulator_msgs
{

namespace action
{

struct JointSpace
{
  /// The goal message defined in the action definition.
  using Goal = eai_manipulator_msgs::action::JointSpace_Goal;
  /// The result message defined in the action definition.
  using Result = eai_manipulator_msgs::action::JointSpace_Result;
  /// The feedback message defined in the action definition.
  using Feedback = eai_manipulator_msgs::action::JointSpace_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = eai_manipulator_msgs::action::JointSpace_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = eai_manipulator_msgs::action::JointSpace_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = eai_manipulator_msgs::action::JointSpace_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct JointSpace JointSpace;

}  // namespace action

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__STRUCT_HPP_
