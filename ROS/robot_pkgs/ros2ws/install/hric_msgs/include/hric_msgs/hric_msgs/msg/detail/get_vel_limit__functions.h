// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hric_msgs:msg/GetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__FUNCTIONS_H_
#define HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hric_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hric_msgs/msg/detail/get_vel_limit__struct.h"

/// Initialize msg/GetVelLimit message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__msg__GetVelLimit
 * )) before or use
 * hric_msgs__msg__GetVelLimit__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__init(hric_msgs__msg__GetVelLimit * msg);

/// Finalize msg/GetVelLimit message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__GetVelLimit__fini(hric_msgs__msg__GetVelLimit * msg);

/// Create msg/GetVelLimit message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__msg__GetVelLimit__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__msg__GetVelLimit *
hric_msgs__msg__GetVelLimit__create();

/// Destroy msg/GetVelLimit message.
/**
 * It calls
 * hric_msgs__msg__GetVelLimit__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__GetVelLimit__destroy(hric_msgs__msg__GetVelLimit * msg);

/// Check for msg/GetVelLimit message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__are_equal(const hric_msgs__msg__GetVelLimit * lhs, const hric_msgs__msg__GetVelLimit * rhs);

/// Copy a msg/GetVelLimit message.
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
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__copy(
  const hric_msgs__msg__GetVelLimit * input,
  hric_msgs__msg__GetVelLimit * output);

/// Initialize array of msg/GetVelLimit messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__msg__GetVelLimit__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__Sequence__init(hric_msgs__msg__GetVelLimit__Sequence * array, size_t size);

/// Finalize array of msg/GetVelLimit messages.
/**
 * It calls
 * hric_msgs__msg__GetVelLimit__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__GetVelLimit__Sequence__fini(hric_msgs__msg__GetVelLimit__Sequence * array);

/// Create array of msg/GetVelLimit messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__msg__GetVelLimit__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__msg__GetVelLimit__Sequence *
hric_msgs__msg__GetVelLimit__Sequence__create(size_t size);

/// Destroy array of msg/GetVelLimit messages.
/**
 * It calls
 * hric_msgs__msg__GetVelLimit__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__GetVelLimit__Sequence__destroy(hric_msgs__msg__GetVelLimit__Sequence * array);

/// Check for msg/GetVelLimit message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__Sequence__are_equal(const hric_msgs__msg__GetVelLimit__Sequence * lhs, const hric_msgs__msg__GetVelLimit__Sequence * rhs);

/// Copy an array of msg/GetVelLimit messages.
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
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__GetVelLimit__Sequence__copy(
  const hric_msgs__msg__GetVelLimit__Sequence * input,
  hric_msgs__msg__GetVelLimit__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__FUNCTIONS_H_
