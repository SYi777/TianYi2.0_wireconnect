// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__FUNCTIONS_H_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cloud_service/msg/rosidl_generator_c__visibility_control.h"

#include "cloud_service/msg/detail/trace_datas__struct.h"

/// Initialize msg/TraceDatas message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cloud_service__msg__TraceDatas
 * )) before or use
 * cloud_service__msg__TraceDatas__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__init(cloud_service__msg__TraceDatas * msg);

/// Finalize msg/TraceDatas message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
void
cloud_service__msg__TraceDatas__fini(cloud_service__msg__TraceDatas * msg);

/// Create msg/TraceDatas message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cloud_service__msg__TraceDatas__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
cloud_service__msg__TraceDatas *
cloud_service__msg__TraceDatas__create();

/// Destroy msg/TraceDatas message.
/**
 * It calls
 * cloud_service__msg__TraceDatas__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
void
cloud_service__msg__TraceDatas__destroy(cloud_service__msg__TraceDatas * msg);

/// Check for msg/TraceDatas message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__are_equal(const cloud_service__msg__TraceDatas * lhs, const cloud_service__msg__TraceDatas * rhs);

/// Copy a msg/TraceDatas message.
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
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__copy(
  const cloud_service__msg__TraceDatas * input,
  cloud_service__msg__TraceDatas * output);

/// Initialize array of msg/TraceDatas messages.
/**
 * It allocates the memory for the number of elements and calls
 * cloud_service__msg__TraceDatas__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__Sequence__init(cloud_service__msg__TraceDatas__Sequence * array, size_t size);

/// Finalize array of msg/TraceDatas messages.
/**
 * It calls
 * cloud_service__msg__TraceDatas__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
void
cloud_service__msg__TraceDatas__Sequence__fini(cloud_service__msg__TraceDatas__Sequence * array);

/// Create array of msg/TraceDatas messages.
/**
 * It allocates the memory for the array and calls
 * cloud_service__msg__TraceDatas__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
cloud_service__msg__TraceDatas__Sequence *
cloud_service__msg__TraceDatas__Sequence__create(size_t size);

/// Destroy array of msg/TraceDatas messages.
/**
 * It calls
 * cloud_service__msg__TraceDatas__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
void
cloud_service__msg__TraceDatas__Sequence__destroy(cloud_service__msg__TraceDatas__Sequence * array);

/// Check for msg/TraceDatas message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__Sequence__are_equal(const cloud_service__msg__TraceDatas__Sequence * lhs, const cloud_service__msg__TraceDatas__Sequence * rhs);

/// Copy an array of msg/TraceDatas messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cloud_service
bool
cloud_service__msg__TraceDatas__Sequence__copy(
  const cloud_service__msg__TraceDatas__Sequence * input,
  cloud_service__msg__TraceDatas__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__FUNCTIONS_H_
