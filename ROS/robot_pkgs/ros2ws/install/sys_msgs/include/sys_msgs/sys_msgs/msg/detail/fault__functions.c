// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice
#include "sys_msgs/msg/detail/fault__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sys_msgs__msg__Fault__init(sys_msgs__msg__Fault * msg)
{
  if (!msg) {
    return false;
  }
  // time_stamp_ms
  // code
  // status
  return true;
}

void
sys_msgs__msg__Fault__fini(sys_msgs__msg__Fault * msg)
{
  if (!msg) {
    return;
  }
  // time_stamp_ms
  // code
  // status
}

bool
sys_msgs__msg__Fault__are_equal(const sys_msgs__msg__Fault * lhs, const sys_msgs__msg__Fault * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_stamp_ms
  if (lhs->time_stamp_ms != rhs->time_stamp_ms) {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
sys_msgs__msg__Fault__copy(
  const sys_msgs__msg__Fault * input,
  sys_msgs__msg__Fault * output)
{
  if (!input || !output) {
    return false;
  }
  // time_stamp_ms
  output->time_stamp_ms = input->time_stamp_ms;
  // code
  output->code = input->code;
  // status
  output->status = input->status;
  return true;
}

sys_msgs__msg__Fault *
sys_msgs__msg__Fault__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__msg__Fault * msg = (sys_msgs__msg__Fault *)allocator.allocate(sizeof(sys_msgs__msg__Fault), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sys_msgs__msg__Fault));
  bool success = sys_msgs__msg__Fault__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sys_msgs__msg__Fault__destroy(sys_msgs__msg__Fault * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sys_msgs__msg__Fault__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sys_msgs__msg__Fault__Sequence__init(sys_msgs__msg__Fault__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__msg__Fault * data = NULL;

  if (size) {
    data = (sys_msgs__msg__Fault *)allocator.zero_allocate(size, sizeof(sys_msgs__msg__Fault), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sys_msgs__msg__Fault__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sys_msgs__msg__Fault__fini(&data[i - 1]);
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
sys_msgs__msg__Fault__Sequence__fini(sys_msgs__msg__Fault__Sequence * array)
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
      sys_msgs__msg__Fault__fini(&array->data[i]);
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

sys_msgs__msg__Fault__Sequence *
sys_msgs__msg__Fault__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__msg__Fault__Sequence * array = (sys_msgs__msg__Fault__Sequence *)allocator.allocate(sizeof(sys_msgs__msg__Fault__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sys_msgs__msg__Fault__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sys_msgs__msg__Fault__Sequence__destroy(sys_msgs__msg__Fault__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sys_msgs__msg__Fault__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sys_msgs__msg__Fault__Sequence__are_equal(const sys_msgs__msg__Fault__Sequence * lhs, const sys_msgs__msg__Fault__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sys_msgs__msg__Fault__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sys_msgs__msg__Fault__Sequence__copy(
  const sys_msgs__msg__Fault__Sequence * input,
  sys_msgs__msg__Fault__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sys_msgs__msg__Fault);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sys_msgs__msg__Fault * data =
      (sys_msgs__msg__Fault *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sys_msgs__msg__Fault__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sys_msgs__msg__Fault__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sys_msgs__msg__Fault__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
