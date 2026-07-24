// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from eai_manipulator_msgs:srv/EndPoseOffSet.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__FUNCTIONS_H_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "eai_manipulator_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "eai_manipulator_msgs/srv/detail/end_pose_off_set__struct.h"

/// Initialize srv/EndPoseOffSet message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request
 * )) before or use
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Request__init(eai_manipulator_msgs__srv__EndPoseOffSet_Request * msg);

/// Finalize srv/EndPoseOffSet message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Request__fini(eai_manipulator_msgs__srv__EndPoseOffSet_Request * msg);

/// Create srv/EndPoseOffSet message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__srv__EndPoseOffSet_Request *
eai_manipulator_msgs__srv__EndPoseOffSet_Request__create();

/// Destroy srv/EndPoseOffSet message.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Request__destroy(eai_manipulator_msgs__srv__EndPoseOffSet_Request * msg);

/// Check for srv/EndPoseOffSet message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Request__are_equal(const eai_manipulator_msgs__srv__EndPoseOffSet_Request * lhs, const eai_manipulator_msgs__srv__EndPoseOffSet_Request * rhs);

/// Copy a srv/EndPoseOffSet message.
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
eai_manipulator_msgs__srv__EndPoseOffSet_Request__copy(
  const eai_manipulator_msgs__srv__EndPoseOffSet_Request * input,
  eai_manipulator_msgs__srv__EndPoseOffSet_Request * output);

/// Initialize array of srv/EndPoseOffSet messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__init(eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * array, size_t size);

/// Finalize array of srv/EndPoseOffSet messages.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__fini(eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * array);

/// Create array of srv/EndPoseOffSet messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence *
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__create(size_t size);

/// Destroy array of srv/EndPoseOffSet messages.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__destroy(eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * array);

/// Check for srv/EndPoseOffSet message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__are_equal(const eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * lhs, const eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * rhs);

/// Copy an array of srv/EndPoseOffSet messages.
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
eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence__copy(
  const eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * input,
  eai_manipulator_msgs__srv__EndPoseOffSet_Request__Sequence * output);

/// Initialize srv/EndPoseOffSet message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response
 * )) before or use
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Response__init(eai_manipulator_msgs__srv__EndPoseOffSet_Response * msg);

/// Finalize srv/EndPoseOffSet message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Response__fini(eai_manipulator_msgs__srv__EndPoseOffSet_Response * msg);

/// Create srv/EndPoseOffSet message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__srv__EndPoseOffSet_Response *
eai_manipulator_msgs__srv__EndPoseOffSet_Response__create();

/// Destroy srv/EndPoseOffSet message.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Response__destroy(eai_manipulator_msgs__srv__EndPoseOffSet_Response * msg);

/// Check for srv/EndPoseOffSet message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Response__are_equal(const eai_manipulator_msgs__srv__EndPoseOffSet_Response * lhs, const eai_manipulator_msgs__srv__EndPoseOffSet_Response * rhs);

/// Copy a srv/EndPoseOffSet message.
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
eai_manipulator_msgs__srv__EndPoseOffSet_Response__copy(
  const eai_manipulator_msgs__srv__EndPoseOffSet_Response * input,
  eai_manipulator_msgs__srv__EndPoseOffSet_Response * output);

/// Initialize array of srv/EndPoseOffSet messages.
/**
 * It allocates the memory for the number of elements and calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__init(eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * array, size_t size);

/// Finalize array of srv/EndPoseOffSet messages.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__fini(eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * array);

/// Create array of srv/EndPoseOffSet messages.
/**
 * It allocates the memory for the array and calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence *
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__create(size_t size);

/// Destroy array of srv/EndPoseOffSet messages.
/**
 * It calls
 * eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
void
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__destroy(eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * array);

/// Check for srv/EndPoseOffSet message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_eai_manipulator_msgs
bool
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__are_equal(const eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * lhs, const eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * rhs);

/// Copy an array of srv/EndPoseOffSet messages.
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
eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence__copy(
  const eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * input,
  eai_manipulator_msgs__srv__EndPoseOffSet_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__END_POSE_OFF_SET__FUNCTIONS_H_
