// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hric_msgs:msg/ActionStatus.idl
// generated code does not contain a copyright notice
#include "hric_msgs/msg/detail/action_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hric_msgs__msg__ActionStatus__init(hric_msgs__msg__ActionStatus * msg)
{
  if (!msg) {
    return false;
  }
  // motion_number
  // is_motion
  return true;
}

void
hric_msgs__msg__ActionStatus__fini(hric_msgs__msg__ActionStatus * msg)
{
  if (!msg) {
    return;
  }
  // motion_number
  // is_motion
}

bool
hric_msgs__msg__ActionStatus__are_equal(const hric_msgs__msg__ActionStatus * lhs, const hric_msgs__msg__ActionStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motion_number
  if (lhs->motion_number != rhs->motion_number) {
    return false;
  }
  // is_motion
  if (lhs->is_motion != rhs->is_motion) {
    return false;
  }
  return true;
}

bool
hric_msgs__msg__ActionStatus__copy(
  const hric_msgs__msg__ActionStatus * input,
  hric_msgs__msg__ActionStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // motion_number
  output->motion_number = input->motion_number;
  // is_motion
  output->is_motion = input->is_motion;
  return true;
}

hric_msgs__msg__ActionStatus *
hric_msgs__msg__ActionStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__ActionStatus * msg = (hric_msgs__msg__ActionStatus *)allocator.allocate(sizeof(hric_msgs__msg__ActionStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__msg__ActionStatus));
  bool success = hric_msgs__msg__ActionStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__msg__ActionStatus__destroy(hric_msgs__msg__ActionStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__msg__ActionStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__msg__ActionStatus__Sequence__init(hric_msgs__msg__ActionStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__ActionStatus * data = NULL;

  if (size) {
    data = (hric_msgs__msg__ActionStatus *)allocator.zero_allocate(size, sizeof(hric_msgs__msg__ActionStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__msg__ActionStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__msg__ActionStatus__fini(&data[i - 1]);
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
hric_msgs__msg__ActionStatus__Sequence__fini(hric_msgs__msg__ActionStatus__Sequence * array)
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
      hric_msgs__msg__ActionStatus__fini(&array->data[i]);
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

hric_msgs__msg__ActionStatus__Sequence *
hric_msgs__msg__ActionStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__ActionStatus__Sequence * array = (hric_msgs__msg__ActionStatus__Sequence *)allocator.allocate(sizeof(hric_msgs__msg__ActionStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__msg__ActionStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__msg__ActionStatus__Sequence__destroy(hric_msgs__msg__ActionStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__msg__ActionStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__msg__ActionStatus__Sequence__are_equal(const hric_msgs__msg__ActionStatus__Sequence * lhs, const hric_msgs__msg__ActionStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__msg__ActionStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__msg__ActionStatus__Sequence__copy(
  const hric_msgs__msg__ActionStatus__Sequence * input,
  hric_msgs__msg__ActionStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__msg__ActionStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__msg__ActionStatus * data =
      (hric_msgs__msg__ActionStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__msg__ActionStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__msg__ActionStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__msg__ActionStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
