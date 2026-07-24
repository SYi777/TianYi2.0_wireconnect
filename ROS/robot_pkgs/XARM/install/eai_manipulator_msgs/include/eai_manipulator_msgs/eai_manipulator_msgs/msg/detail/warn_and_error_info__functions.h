// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__FUNCTIONS_H_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "eai_manipulator_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__struct.h"

/// Initialize msg/WarnAndErrorInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__msg__WarnAndErrorInfo
 * )) before or use
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__init(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg);

/// Finalize msg/WarnAndErrorInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg);

/// Create msg/WarnAndErrorInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__msg__WarnAndErrorInfo *
eai_manipulator_msgs__msg__WarnAndErrorInfo__create();

/// Destroy msg/WarnAndErrorInfo message.
/**
 * It calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__msg__WarnAndErrorInfo__destroy(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg);

/// Check for msg/WarnAndErrorInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__are_equal(const eai_manipulator_msgs__msg__WarnAndErrorInfo * lhs, const eai_manipulator_msgs__msg__WarnAndErrorInfo * rhs);

/// Copy a msg/WarnAndErrorInfo message.
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
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__copy(
  const eai_manipulator_msgs__msg__WarnAndErrorInfo * input,
  eai_manipulator_msgs__msg__WarnAndErrorInfo * output);

/// Initialize array of msg/WarnAndErrorInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__init(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array, size_t size);

/// Finalize array of msg/WarnAndErrorInfo messages.
/**
 * It calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__fini(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array);

/// Create array of msg/WarnAndErrorInfo messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence *
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__create(size_t size);

/// Destroy array of msg/WarnAndErrorInfo messages.
/**
 * It calls
 * eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__destroy(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array);

/// Check for msg/WarnAndErrorInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__are_equal(const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * lhs, const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * rhs);

/// Copy an array of msg/WarnAndErrorInfo messages.
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
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__copy(
  const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * input,
  eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__FUNCTIONS_H_
