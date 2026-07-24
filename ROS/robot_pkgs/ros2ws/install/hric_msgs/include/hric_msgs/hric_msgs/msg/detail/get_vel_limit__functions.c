// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hric_msgs:msg/GetVelLimit.idl
// generated code does not contain a copyright notice
#include "hric_msgs/msg/detail/get_vel_limit__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hric_msgs__msg__GetVelLimit__init(hric_msgs__msg__GetVelLimit * msg)
{
  if (!msg) {
    return false;
  }
  // x_vel_limit_walk
  // x_vel_limit_run
  // x_vel_limit_halfwalk
  return true;
}

void
hric_msgs__msg__GetVelLimit__fini(hric_msgs__msg__GetVelLimit * msg)
{
  if (!msg) {
    return;
  }
  // x_vel_limit_walk
  // x_vel_limit_run
  // x_vel_limit_halfwalk
}

bool
hric_msgs__msg__GetVelLimit__are_equal(const hric_msgs__msg__GetVelLimit * lhs, const hric_msgs__msg__GetVelLimit * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_vel_limit_walk
  if (lhs->x_vel_limit_walk != rhs->x_vel_limit_walk) {
    return false;
  }
  // x_vel_limit_run
  if (lhs->x_vel_limit_run != rhs->x_vel_limit_run) {
    return false;
  }
  // x_vel_limit_halfwalk
  if (lhs->x_vel_limit_halfwalk != rhs->x_vel_limit_halfwalk) {
    return false;
  }
  return true;
}

bool
hric_msgs__msg__GetVelLimit__copy(
  const hric_msgs__msg__GetVelLimit * input,
  hric_msgs__msg__GetVelLimit * output)
{
  if (!input || !output) {
    return false;
  }
  // x_vel_limit_walk
  output->x_vel_limit_walk = input->x_vel_limit_walk;
  // x_vel_limit_run
  output->x_vel_limit_run = input->x_vel_limit_run;
  // x_vel_limit_halfwalk
  output->x_vel_limit_halfwalk = input->x_vel_limit_halfwalk;
  return true;
}

hric_msgs__msg__GetVelLimit *
hric_msgs__msg__GetVelLimit__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__GetVelLimit * msg = (hric_msgs__msg__GetVelLimit *)allocator.allocate(sizeof(hric_msgs__msg__GetVelLimit), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__msg__GetVelLimit));
  bool success = hric_msgs__msg__GetVelLimit__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__msg__GetVelLimit__destroy(hric_msgs__msg__GetVelLimit * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__msg__GetVelLimit__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__msg__GetVelLimit__Sequence__init(hric_msgs__msg__GetVelLimit__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__GetVelLimit * data = NULL;

  if (size) {
    data = (hric_msgs__msg__GetVelLimit *)allocator.zero_allocate(size, sizeof(hric_msgs__msg__GetVelLimit), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__msg__GetVelLimit__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__msg__GetVelLimit__fini(&data[i - 1]);
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
hric_msgs__msg__GetVelLimit__Sequence__fini(hric_msgs__msg__GetVelLimit__Sequence * array)
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
      hric_msgs__msg__GetVelLimit__fini(&array->data[i]);
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

hric_msgs__msg__GetVelLimit__Sequence *
hric_msgs__msg__GetVelLimit__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__GetVelLimit__Sequence * array = (hric_msgs__msg__GetVelLimit__Sequence *)allocator.allocate(sizeof(hric_msgs__msg__GetVelLimit__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__msg__GetVelLimit__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__msg__GetVelLimit__Sequence__destroy(hric_msgs__msg__GetVelLimit__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__msg__GetVelLimit__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__msg__GetVelLimit__Sequence__are_equal(const hric_msgs__msg__GetVelLimit__Sequence * lhs, const hric_msgs__msg__GetVelLimit__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__msg__GetVelLimit__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__msg__GetVelLimit__Sequence__copy(
  const hric_msgs__msg__GetVelLimit__Sequence * input,
  hric_msgs__msg__GetVelLimit__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__msg__GetVelLimit);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__msg__GetVelLimit * data =
      (hric_msgs__msg__GetVelLimit *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__msg__GetVelLimit__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__msg__GetVelLimit__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__msg__GetVelLimit__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
