// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:srv/EndPoseOffSet.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/srv/detail/end_pose_off_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace srv
{

namespace builder
{

class Init_EndPoseOffSet_Request_pose
{
public:
  Init_EndPoseOffSet_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::eai_manipulator_msgs::srv::EndPoseOffSet_Request pose(::eai_manipulator_msgs::srv::EndPoseOffSet_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::EndPoseOffSet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::EndPoseOffSet_Request>()
{
  return eai_manipulator_msgs::srv::builder::Init_EndPoseOffSet_Request_pose();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace srv
{

namespace builder
{

class Init_EndPoseOffSet_Response_message
{
public:
  explicit Init_EndPoseOffSet_Response_message(::eai_manipulator_msgs::srv::EndPoseOffSet_Response & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::srv::EndPoseOffSet_Response message(::eai_manipulator_msgs::srv::EndPoseOffSet_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::EndPoseOffSet_Response msg_;
};

class Init_EndPoseOffSet_Response_success
{
public:
  Init_EndPoseOffSet_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPoseOffSet_Response_message success(::eai_manipulator_msgs::srv::EndPoseOffSet_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_EndPoseOffSet_Response_message(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::EndPoseOffSet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::EndPoseOffSet_Response>()
{
  return eai_manipulator_msgs::srv::builder::Init_EndPoseOffSet_Response_success();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__BUILDER_HPP_
