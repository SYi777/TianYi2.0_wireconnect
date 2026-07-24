// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice
#include "cm_msgs/msg/detail/pose_action_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cm_msgs__msg__PoseActionStatus__init(cm_msgs__msg__PoseActionStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cm_msgs__msg__PoseActionStatus__fini(msg);
    return false;
  }
  // resp_frame_id
  // hand_move_success
  // head_move_success
  // gripper_move_success
  return true;
}

void
cm_msgs__msg__PoseActionStatus__fini(cm_msgs__msg__PoseActionStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // resp_frame_id
  // hand_move_success
  // head_move_success
  // gripper_move_success
}

bool
cm_msgs__msg__PoseActionStatus__are_equal(const cm_msgs__msg__PoseActionStatus * lhs, const cm_msgs__msg__PoseActionStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // resp_frame_id
  if (lhs->resp_frame_id != rhs->resp_frame_id) {
    return false;
  }
  // hand_move_success
  if (lhs->hand_move_success != rhs->hand_move_success) {
    return false;
  }
  // head_move_success
  if (lhs->head_move_success != rhs->head_move_success) {
    return false;
  }
  // gripper_move_success
  if (lhs->gripper_move_success != rhs->gripper_move_success) {
    return false;
  }
  return true;
}

bool
cm_msgs__msg__PoseActionStatus__copy(
  const cm_msgs__msg__PoseActionStatus * input,
  cm_msgs__msg__PoseActionStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // resp_frame_id
  output->resp_frame_id = input->resp_frame_id;
  // hand_move_success
  output->hand_move_success = input->hand_move_success;
  // head_move_success
  output->head_move_success = input->head_move_success;
  // gripper_move_success
  output->gripper_move_success = input->gripper_move_success;
  return true;
}

cm_msgs__msg__PoseActionStatus *
cm_msgs__msg__PoseActionStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__PoseActionStatus * msg = (cm_msgs__msg__PoseActionStatus *)allocator.allocate(sizeof(cm_msgs__msg__PoseActionStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cm_msgs__msg__PoseActionStatus));
  bool success = cm_msgs__msg__PoseActionStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cm_msgs__msg__PoseActionStatus__destroy(cm_msgs__msg__PoseActionStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cm_msgs__msg__PoseActionStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cm_msgs__msg__PoseActionStatus__Sequence__init(cm_msgs__msg__PoseActionStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__PoseActionStatus * data = NULL;

  if (size) {
    data = (cm_msgs__msg__PoseActionStatus *)allocator.zero_allocate(size, sizeof(cm_msgs__msg__PoseActionStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cm_msgs__msg__PoseActionStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cm_msgs__msg__PoseActionStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cm_msgs__msg__PoseActionStatus__Sequence__fini(cm_msgs__msg__PoseActionStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cm_msgs__msg__PoseActionStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cm_msgs__msg__PoseActionStatus__Sequence *
cm_msgs__msg__PoseActionStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__PoseActionStatus__Sequence * array = (cm_msgs__msg__PoseActionStatus__Sequence *)allocator.allocate(sizeof(cm_msgs__msg__PoseActionStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cm_msgs__msg__PoseActionStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cm_msgs__msg__PoseActionStatus__Sequence__destroy(cm_msgs__msg__PoseActionStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cm_msgs__msg__PoseActionStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cm_msgs__msg__PoseActionStatus__Sequence__are_equal(const cm_msgs__msg__PoseActionStatus__Sequence * lhs, const cm_msgs__msg__PoseActionStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cm_msgs__msg__PoseActionStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cm_msgs__msg__PoseActionStatus__Sequence__copy(
  const cm_msgs__msg__PoseActionStatus__Sequence * input,
  cm_msgs__msg__PoseActionStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cm_msgs__msg__PoseActionStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cm_msgs__msg__PoseActionStatus * data =
      (cm_msgs__msg__PoseActionStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cm_msgs__msg__PoseActionStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cm_msgs__msg__PoseActionStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cm_msgs__msg__PoseActionStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
