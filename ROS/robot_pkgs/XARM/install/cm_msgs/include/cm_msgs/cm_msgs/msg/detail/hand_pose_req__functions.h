// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__FUNCTIONS_H_
#define CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cm_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cm_msgs/msg/detail/hand_pose_req__struct.h"

/// Initialize msg/HandPoseReq message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__msg__HandPoseReq
 * )) before or use
 * cm_msgs__msg__HandPoseReq__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__init(cm_msgs__msg__HandPoseReq * msg);

/// Finalize msg/HandPoseReq message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__msg__HandPoseReq__fini(cm_msgs__msg__HandPoseReq * msg);

/// Create msg/HandPoseReq message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__msg__HandPoseReq__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__msg__HandPoseReq *
cm_msgs__msg__HandPoseReq__create();

/// Destroy msg/HandPoseReq message.
/**
 * It calls
 * cm_msgs__msg__HandPoseReq__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__msg__HandPoseReq__destroy(cm_msgs__msg__HandPoseReq * msg);

/// Check for msg/HandPoseReq message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__are_equal(const cm_msgs__msg__HandPoseReq * lhs, const cm_msgs__msg__HandPoseReq * rhs);

/// Copy a msg/HandPoseReq message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__copy(
  const cm_msgs__msg__HandPoseReq * input,
  cm_msgs__msg__HandPoseReq * output);

/// Initialize array of msg/HandPoseReq messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__msg__HandPoseReq__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__Sequence__init(cm_msgs__msg__HandPoseReq__Sequence * array, size_t size);

/// Finalize array of msg/HandPoseReq messages.
/**
 * It calls
 * cm_msgs__msg__HandPoseReq__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__msg__HandPoseReq__Sequence__fini(cm_msgs__msg__HandPoseReq__Sequence * array);

/// Create array of msg/HandPoseReq messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__msg__HandPoseReq__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__msg__HandPoseReq__Sequence *
cm_msgs__msg__HandPoseReq__Sequence__create(size_t size);

/// Destroy array of msg/HandPoseReq messages.
/**
 * It calls
 * cm_msgs__msg__HandPoseReq__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__msg__HandPoseReq__Sequence__destroy(cm_msgs__msg__HandPoseReq__Sequence * array);

/// Check for msg/HandPoseReq message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__Sequence__are_equal(const cm_msgs__msg__HandPoseReq__Sequence * lhs, const cm_msgs__msg__HandPoseReq__Sequence * rhs);

/// Copy an array of msg/HandPoseReq messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__msg__HandPoseReq__Sequence__copy(
  const cm_msgs__msg__HandPoseReq__Sequence * input,
  cm_msgs__msg__HandPoseReq__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__FUNCTIONS_H_
