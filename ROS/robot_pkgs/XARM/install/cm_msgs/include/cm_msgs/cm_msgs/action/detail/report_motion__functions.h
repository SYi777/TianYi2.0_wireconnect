// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cm_msgs:action/ReportMotion.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__ACTION__DETAIL__REPORT_MOTION__FUNCTIONS_H_
#define CM_MSGS__ACTION__DETAIL__REPORT_MOTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cm_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cm_msgs/action/detail/report_motion__struct.h"

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_Goal
 * )) before or use
 * cm_msgs__action__ReportMotion_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Goal__init(cm_msgs__action__ReportMotion_Goal * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Goal__fini(cm_msgs__action__ReportMotion_Goal * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Goal *
cm_msgs__action__ReportMotion_Goal__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Goal__destroy(cm_msgs__action__ReportMotion_Goal * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Goal__are_equal(const cm_msgs__action__ReportMotion_Goal * lhs, const cm_msgs__action__ReportMotion_Goal * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_Goal__copy(
  const cm_msgs__action__ReportMotion_Goal * input,
  cm_msgs__action__ReportMotion_Goal * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Goal__Sequence__init(cm_msgs__action__ReportMotion_Goal__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Goal__Sequence__fini(cm_msgs__action__ReportMotion_Goal__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Goal__Sequence *
cm_msgs__action__ReportMotion_Goal__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Goal__Sequence__destroy(cm_msgs__action__ReportMotion_Goal__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Goal__Sequence__are_equal(const cm_msgs__action__ReportMotion_Goal__Sequence * lhs, const cm_msgs__action__ReportMotion_Goal__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_Goal__Sequence__copy(
  const cm_msgs__action__ReportMotion_Goal__Sequence * input,
  cm_msgs__action__ReportMotion_Goal__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_Result
 * )) before or use
 * cm_msgs__action__ReportMotion_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Result__init(cm_msgs__action__ReportMotion_Result * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Result__fini(cm_msgs__action__ReportMotion_Result * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Result *
cm_msgs__action__ReportMotion_Result__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Result__destroy(cm_msgs__action__ReportMotion_Result * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Result__are_equal(const cm_msgs__action__ReportMotion_Result * lhs, const cm_msgs__action__ReportMotion_Result * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_Result__copy(
  const cm_msgs__action__ReportMotion_Result * input,
  cm_msgs__action__ReportMotion_Result * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Result__Sequence__init(cm_msgs__action__ReportMotion_Result__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Result__Sequence__fini(cm_msgs__action__ReportMotion_Result__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Result__Sequence *
cm_msgs__action__ReportMotion_Result__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Result__Sequence__destroy(cm_msgs__action__ReportMotion_Result__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Result__Sequence__are_equal(const cm_msgs__action__ReportMotion_Result__Sequence * lhs, const cm_msgs__action__ReportMotion_Result__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_Result__Sequence__copy(
  const cm_msgs__action__ReportMotion_Result__Sequence * input,
  cm_msgs__action__ReportMotion_Result__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_Feedback
 * )) before or use
 * cm_msgs__action__ReportMotion_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Feedback__init(cm_msgs__action__ReportMotion_Feedback * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Feedback__fini(cm_msgs__action__ReportMotion_Feedback * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Feedback *
cm_msgs__action__ReportMotion_Feedback__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Feedback__destroy(cm_msgs__action__ReportMotion_Feedback * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Feedback__are_equal(const cm_msgs__action__ReportMotion_Feedback * lhs, const cm_msgs__action__ReportMotion_Feedback * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_Feedback__copy(
  const cm_msgs__action__ReportMotion_Feedback * input,
  cm_msgs__action__ReportMotion_Feedback * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Feedback__Sequence__init(cm_msgs__action__ReportMotion_Feedback__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Feedback__Sequence__fini(cm_msgs__action__ReportMotion_Feedback__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_Feedback__Sequence *
cm_msgs__action__ReportMotion_Feedback__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_Feedback__Sequence__destroy(cm_msgs__action__ReportMotion_Feedback__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_Feedback__Sequence__are_equal(const cm_msgs__action__ReportMotion_Feedback__Sequence * lhs, const cm_msgs__action__ReportMotion_Feedback__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_Feedback__Sequence__copy(
  const cm_msgs__action__ReportMotion_Feedback__Sequence * input,
  cm_msgs__action__ReportMotion_Feedback__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_SendGoal_Request
 * )) before or use
 * cm_msgs__action__ReportMotion_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Request__init(cm_msgs__action__ReportMotion_SendGoal_Request * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Request__fini(cm_msgs__action__ReportMotion_SendGoal_Request * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_SendGoal_Request *
cm_msgs__action__ReportMotion_SendGoal_Request__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Request__destroy(cm_msgs__action__ReportMotion_SendGoal_Request * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Request__are_equal(const cm_msgs__action__ReportMotion_SendGoal_Request * lhs, const cm_msgs__action__ReportMotion_SendGoal_Request * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_SendGoal_Request__copy(
  const cm_msgs__action__ReportMotion_SendGoal_Request * input,
  cm_msgs__action__ReportMotion_SendGoal_Request * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__init(cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__fini(cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence *
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__destroy(cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__are_equal(const cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * lhs, const cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_SendGoal_Request__Sequence__copy(
  const cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * input,
  cm_msgs__action__ReportMotion_SendGoal_Request__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_SendGoal_Response
 * )) before or use
 * cm_msgs__action__ReportMotion_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Response__init(cm_msgs__action__ReportMotion_SendGoal_Response * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Response__fini(cm_msgs__action__ReportMotion_SendGoal_Response * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_SendGoal_Response *
cm_msgs__action__ReportMotion_SendGoal_Response__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Response__destroy(cm_msgs__action__ReportMotion_SendGoal_Response * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Response__are_equal(const cm_msgs__action__ReportMotion_SendGoal_Response * lhs, const cm_msgs__action__ReportMotion_SendGoal_Response * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_SendGoal_Response__copy(
  const cm_msgs__action__ReportMotion_SendGoal_Response * input,
  cm_msgs__action__ReportMotion_SendGoal_Response * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__init(cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__fini(cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence *
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__destroy(cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__are_equal(const cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * lhs, const cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_SendGoal_Response__Sequence__copy(
  const cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * input,
  cm_msgs__action__ReportMotion_SendGoal_Response__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_GetResult_Request
 * )) before or use
 * cm_msgs__action__ReportMotion_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Request__init(cm_msgs__action__ReportMotion_GetResult_Request * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Request__fini(cm_msgs__action__ReportMotion_GetResult_Request * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_GetResult_Request *
cm_msgs__action__ReportMotion_GetResult_Request__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Request__destroy(cm_msgs__action__ReportMotion_GetResult_Request * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Request__are_equal(const cm_msgs__action__ReportMotion_GetResult_Request * lhs, const cm_msgs__action__ReportMotion_GetResult_Request * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_GetResult_Request__copy(
  const cm_msgs__action__ReportMotion_GetResult_Request * input,
  cm_msgs__action__ReportMotion_GetResult_Request * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__init(cm_msgs__action__ReportMotion_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__fini(cm_msgs__action__ReportMotion_GetResult_Request__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_GetResult_Request__Sequence *
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__destroy(cm_msgs__action__ReportMotion_GetResult_Request__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__are_equal(const cm_msgs__action__ReportMotion_GetResult_Request__Sequence * lhs, const cm_msgs__action__ReportMotion_GetResult_Request__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_GetResult_Request__Sequence__copy(
  const cm_msgs__action__ReportMotion_GetResult_Request__Sequence * input,
  cm_msgs__action__ReportMotion_GetResult_Request__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_GetResult_Response
 * )) before or use
 * cm_msgs__action__ReportMotion_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Response__init(cm_msgs__action__ReportMotion_GetResult_Response * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Response__fini(cm_msgs__action__ReportMotion_GetResult_Response * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_GetResult_Response *
cm_msgs__action__ReportMotion_GetResult_Response__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Response__destroy(cm_msgs__action__ReportMotion_GetResult_Response * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Response__are_equal(const cm_msgs__action__ReportMotion_GetResult_Response * lhs, const cm_msgs__action__ReportMotion_GetResult_Response * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_GetResult_Response__copy(
  const cm_msgs__action__ReportMotion_GetResult_Response * input,
  cm_msgs__action__ReportMotion_GetResult_Response * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__init(cm_msgs__action__ReportMotion_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__fini(cm_msgs__action__ReportMotion_GetResult_Response__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_GetResult_Response__Sequence *
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__destroy(cm_msgs__action__ReportMotion_GetResult_Response__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__are_equal(const cm_msgs__action__ReportMotion_GetResult_Response__Sequence * lhs, const cm_msgs__action__ReportMotion_GetResult_Response__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_GetResult_Response__Sequence__copy(
  const cm_msgs__action__ReportMotion_GetResult_Response__Sequence * input,
  cm_msgs__action__ReportMotion_GetResult_Response__Sequence * output);

/// Initialize action/ReportMotion message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cm_msgs__action__ReportMotion_FeedbackMessage
 * )) before or use
 * cm_msgs__action__ReportMotion_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_FeedbackMessage__init(cm_msgs__action__ReportMotion_FeedbackMessage * msg);

/// Finalize action/ReportMotion message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_FeedbackMessage__fini(cm_msgs__action__ReportMotion_FeedbackMessage * msg);

/// Create action/ReportMotion message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_FeedbackMessage *
cm_msgs__action__ReportMotion_FeedbackMessage__create();

/// Destroy action/ReportMotion message.
/**
 * It calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_FeedbackMessage__destroy(cm_msgs__action__ReportMotion_FeedbackMessage * msg);

/// Check for action/ReportMotion message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_FeedbackMessage__are_equal(const cm_msgs__action__ReportMotion_FeedbackMessage * lhs, const cm_msgs__action__ReportMotion_FeedbackMessage * rhs);

/// Copy a action/ReportMotion message.
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
cm_msgs__action__ReportMotion_FeedbackMessage__copy(
  const cm_msgs__action__ReportMotion_FeedbackMessage * input,
  cm_msgs__action__ReportMotion_FeedbackMessage * output);

/// Initialize array of action/ReportMotion messages.
/**
 * It allocates the memory for the number of elements and calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__init(cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__fini(cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * array);

/// Create array of action/ReportMotion messages.
/**
 * It allocates the memory for the array and calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence *
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/ReportMotion messages.
/**
 * It calls
 * cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
void
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__destroy(cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * array);

/// Check for action/ReportMotion message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cm_msgs
bool
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__are_equal(const cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * lhs, const cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/ReportMotion messages.
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
cm_msgs__action__ReportMotion_FeedbackMessage__Sequence__copy(
  const cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * input,
  cm_msgs__action__ReportMotion_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__ACTION__DETAIL__REPORT_MOTION__FUNCTIONS_H_
