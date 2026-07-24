// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from eai_manipulator_msgs:action/JointSpace.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__FUNCTIONS_H_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "eai_manipulator_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "eai_manipulator_msgs/action/detail/joint_space__struct.h"

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_Goal
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Goal__init(eai_manipulator_msgs__action__JointSpace_Goal * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Goal__fini(eai_manipulator_msgs__action__JointSpace_Goal * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Goal *
eai_manipulator_msgs__action__JointSpace_Goal__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Goal__destroy(eai_manipulator_msgs__action__JointSpace_Goal * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Goal__are_equal(const eai_manipulator_msgs__action__JointSpace_Goal * lhs, const eai_manipulator_msgs__action__JointSpace_Goal * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_Goal__copy(
  const eai_manipulator_msgs__action__JointSpace_Goal * input,
  eai_manipulator_msgs__action__JointSpace_Goal * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__init(eai_manipulator_msgs__action__JointSpace_Goal__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__fini(eai_manipulator_msgs__action__JointSpace_Goal__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Goal__Sequence *
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_Goal__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_Goal__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_Goal__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_Goal__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_Goal__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_Goal__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_Result
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Result__init(eai_manipulator_msgs__action__JointSpace_Result * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Result__fini(eai_manipulator_msgs__action__JointSpace_Result * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Result *
eai_manipulator_msgs__action__JointSpace_Result__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Result__destroy(eai_manipulator_msgs__action__JointSpace_Result * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Result__are_equal(const eai_manipulator_msgs__action__JointSpace_Result * lhs, const eai_manipulator_msgs__action__JointSpace_Result * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_Result__copy(
  const eai_manipulator_msgs__action__JointSpace_Result * input,
  eai_manipulator_msgs__action__JointSpace_Result * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Result__Sequence__init(eai_manipulator_msgs__action__JointSpace_Result__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Result__Sequence__fini(eai_manipulator_msgs__action__JointSpace_Result__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Result__Sequence *
eai_manipulator_msgs__action__JointSpace_Result__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Result__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_Result__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Result__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_Result__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_Result__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_Result__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_Result__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_Result__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_Feedback
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Feedback__init(eai_manipulator_msgs__action__JointSpace_Feedback * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Feedback__fini(eai_manipulator_msgs__action__JointSpace_Feedback * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Feedback *
eai_manipulator_msgs__action__JointSpace_Feedback__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Feedback__destroy(eai_manipulator_msgs__action__JointSpace_Feedback * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Feedback__are_equal(const eai_manipulator_msgs__action__JointSpace_Feedback * lhs, const eai_manipulator_msgs__action__JointSpace_Feedback * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_Feedback__copy(
  const eai_manipulator_msgs__action__JointSpace_Feedback * input,
  eai_manipulator_msgs__action__JointSpace_Feedback * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__init(eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__fini(eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence *
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_Feedback__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_Feedback__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__init(eai_manipulator_msgs__action__JointSpace_SendGoal_Request * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__fini(eai_manipulator_msgs__action__JointSpace_SendGoal_Request * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_SendGoal_Request *
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__destroy(eai_manipulator_msgs__action__JointSpace_SendGoal_Request * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__are_equal(const eai_manipulator_msgs__action__JointSpace_SendGoal_Request * lhs, const eai_manipulator_msgs__action__JointSpace_SendGoal_Request * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__copy(
  const eai_manipulator_msgs__action__JointSpace_SendGoal_Request * input,
  eai_manipulator_msgs__action__JointSpace_SendGoal_Request * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__init(eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__fini(eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence *
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_SendGoal_Request__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__init(eai_manipulator_msgs__action__JointSpace_SendGoal_Response * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__fini(eai_manipulator_msgs__action__JointSpace_SendGoal_Response * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_SendGoal_Response *
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__destroy(eai_manipulator_msgs__action__JointSpace_SendGoal_Response * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__are_equal(const eai_manipulator_msgs__action__JointSpace_SendGoal_Response * lhs, const eai_manipulator_msgs__action__JointSpace_SendGoal_Response * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__copy(
  const eai_manipulator_msgs__action__JointSpace_SendGoal_Response * input,
  eai_manipulator_msgs__action__JointSpace_SendGoal_Response * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__init(eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__fini(eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence *
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_SendGoal_Response__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Request__init(eai_manipulator_msgs__action__JointSpace_GetResult_Request * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Request__fini(eai_manipulator_msgs__action__JointSpace_GetResult_Request * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_GetResult_Request *
eai_manipulator_msgs__action__JointSpace_GetResult_Request__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Request__destroy(eai_manipulator_msgs__action__JointSpace_GetResult_Request * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Request__are_equal(const eai_manipulator_msgs__action__JointSpace_GetResult_Request * lhs, const eai_manipulator_msgs__action__JointSpace_GetResult_Request * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_GetResult_Request__copy(
  const eai_manipulator_msgs__action__JointSpace_GetResult_Request * input,
  eai_manipulator_msgs__action__JointSpace_GetResult_Request * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__init(eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__fini(eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence *
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_GetResult_Request__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Response__init(eai_manipulator_msgs__action__JointSpace_GetResult_Response * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Response__fini(eai_manipulator_msgs__action__JointSpace_GetResult_Response * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_GetResult_Response *
eai_manipulator_msgs__action__JointSpace_GetResult_Response__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Response__destroy(eai_manipulator_msgs__action__JointSpace_GetResult_Response * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Response__are_equal(const eai_manipulator_msgs__action__JointSpace_GetResult_Response * lhs, const eai_manipulator_msgs__action__JointSpace_GetResult_Response * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_GetResult_Response__copy(
  const eai_manipulator_msgs__action__JointSpace_GetResult_Response * input,
  eai_manipulator_msgs__action__JointSpace_GetResult_Response * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__init(eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__fini(eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence *
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_GetResult_Response__Sequence * output);

/// Initialize action/JointSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage
 * )) before or use
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__init(eai_manipulator_msgs__action__JointSpace_FeedbackMessage * msg);

/// Finalize action/JointSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__fini(eai_manipulator_msgs__action__JointSpace_FeedbackMessage * msg);

/// Create action/JointSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_FeedbackMessage *
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__create();

/// Destroy action/JointSpace message.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__destroy(eai_manipulator_msgs__action__JointSpace_FeedbackMessage * msg);

/// Check for action/JointSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__are_equal(const eai_manipulator_msgs__action__JointSpace_FeedbackMessage * lhs, const eai_manipulator_msgs__action__JointSpace_FeedbackMessage * rhs);

/// Copy a action/JointSpace message.
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
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__copy(
  const eai_manipulator_msgs__action__JointSpace_FeedbackMessage * input,
  eai_manipulator_msgs__action__JointSpace_FeedbackMessage * output);

/// Initialize array of action/JointSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__init(eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__fini(eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * array);

/// Create array of action/JointSpace messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence *
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/JointSpace messages.
/**
 * It calls
 * eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__destroy(eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * array);

/// Check for action/JointSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__are_equal(const eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * lhs, const eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/JointSpace messages.
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
eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence__copy(
  const eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * input,
  eai_manipulator_msgs__action__JointSpace_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__JOINT_SPACE__FUNCTIONS_H_
