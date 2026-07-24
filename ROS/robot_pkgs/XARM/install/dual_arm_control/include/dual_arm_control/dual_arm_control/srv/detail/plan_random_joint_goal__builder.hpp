// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#ifndef DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__BUILDER_HPP_
#define DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dual_arm_control
{

namespace srv
{

namespace builder
{

class Init_PlanRandomJointGoal_Request_group_name
{
public:
  Init_PlanRandomJointGoal_Request_group_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dual_arm_control::srv::PlanRandomJointGoal_Request group_name(::dual_arm_control::srv::PlanRandomJointGoal_Request::_group_name_type arg)
  {
    msg_.group_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dual_arm_control::srv::PlanRandomJointGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dual_arm_control::srv::PlanRandomJointGoal_Request>()
{
  return dual_arm_control::srv::builder::Init_PlanRandomJointGoal_Request_group_name();
}

}  // namespace dual_arm_control


namespace dual_arm_control
{

namespace srv
{

namespace builder
{

class Init_PlanRandomJointGoal_Response_message
{
public:
  explicit Init_PlanRandomJointGoal_Response_message(::dual_arm_control::srv::PlanRandomJointGoal_Response & msg)
  : msg_(msg)
  {}
  ::dual_arm_control::srv::PlanRandomJointGoal_Response message(::dual_arm_control::srv::PlanRandomJointGoal_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dual_arm_control::srv::PlanRandomJointGoal_Response msg_;
};

class Init_PlanRandomJointGoal_Response_trajectory
{
public:
  explicit Init_PlanRandomJointGoal_Response_trajectory(::dual_arm_control::srv::PlanRandomJointGoal_Response & msg)
  : msg_(msg)
  {}
  Init_PlanRandomJointGoal_Response_message trajectory(::dual_arm_control::srv::PlanRandomJointGoal_Response::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_PlanRandomJointGoal_Response_message(msg_);
  }

private:
  ::dual_arm_control::srv::PlanRandomJointGoal_Response msg_;
};

class Init_PlanRandomJointGoal_Response_joint_values
{
public:
  explicit Init_PlanRandomJointGoal_Response_joint_values(::dual_arm_control::srv::PlanRandomJointGoal_Response & msg)
  : msg_(msg)
  {}
  Init_PlanRandomJointGoal_Response_trajectory joint_values(::dual_arm_control::srv::PlanRandomJointGoal_Response::_joint_values_type arg)
  {
    msg_.joint_values = std::move(arg);
    return Init_PlanRandomJointGoal_Response_trajectory(msg_);
  }

private:
  ::dual_arm_control::srv::PlanRandomJointGoal_Response msg_;
};

class Init_PlanRandomJointGoal_Response_success
{
public:
  Init_PlanRandomJointGoal_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRandomJointGoal_Response_joint_values success(::dual_arm_control::srv::PlanRandomJointGoal_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PlanRandomJointGoal_Response_joint_values(msg_);
  }

private:
  ::dual_arm_control::srv::PlanRandomJointGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dual_arm_control::srv::PlanRandomJointGoal_Response>()
{
  return dual_arm_control::srv::builder::Init_PlanRandomJointGoal_Response_success();
}

}  // namespace dual_arm_control

#endif  // DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__BUILDER_HPP_
