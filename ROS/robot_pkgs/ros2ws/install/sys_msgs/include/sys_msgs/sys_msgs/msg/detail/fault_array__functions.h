// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__FUNCTIONS_H_
#define SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sys_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "sys_msgs/msg/detail/fault_array__struct.h"

/// Initialize msg/FaultArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sys_msgs__msg__FaultArray
 * )) before or use
 * sys_msgs__msg__FaultArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__init(sys_msgs__msg__FaultArray * msg);

/// Finalize msg/FaultArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
void
sys_msgs__msg__FaultArray__fini(sys_msgs__msg__FaultArray * msg);

/// Create msg/FaultArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sys_msgs__msg__FaultArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
sys_msgs__msg__FaultArray *
sys_msgs__msg__FaultArray__create();

/// Destroy msg/FaultArray message.
/**
 * It calls
 * sys_msgs__msg__FaultArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
void
sys_msgs__msg__FaultArray__destroy(sys_msgs__msg__FaultArray * msg);

/// Check for msg/FaultArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__are_equal(const sys_msgs__msg__FaultArray * lhs, const sys_msgs__msg__FaultArray * rhs);

/// Copy a msg/FaultArray message.
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
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__copy(
  const sys_msgs__msg__FaultArray * input,
  sys_msgs__msg__FaultArray * output);

/// Initialize array of msg/FaultArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * sys_msgs__msg__FaultArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__Sequence__init(sys_msgs__msg__FaultArray__Sequence * array, size_t size);

/// Finalize array of msg/FaultArray messages.
/**
 * It calls
 * sys_msgs__msg__FaultArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
void
sys_msgs__msg__FaultArray__Sequence__fini(sys_msgs__msg__FaultArray__Sequence * array);

/// Create array of msg/FaultArray messages.
/**
 * It allocates the memory for the array and calls
 * sys_msgs__msg__FaultArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
sys_msgs__msg__FaultArray__Sequence *
sys_msgs__msg__FaultArray__Sequence__create(size_t size);

/// Destroy array of msg/FaultArray messages.
/**
 * It calls
 * sys_msgs__msg__FaultArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
void
sys_msgs__msg__FaultArray__Sequence__destroy(sys_msgs__msg__FaultArray__Sequence * array);

/// Check for msg/FaultArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__Sequence__are_equal(const sys_msgs__msg__FaultArray__Sequence * lhs, const sys_msgs__msg__FaultArray__Sequence * rhs);

/// Copy an array of msg/FaultArray messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sys_msgs
bool
sys_msgs__msg__FaultArray__Sequence__copy(
  const sys_msgs__msg__FaultArray__Sequence * input,
  sys_msgs__msg__FaultArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__FUNCTIONS_H_
