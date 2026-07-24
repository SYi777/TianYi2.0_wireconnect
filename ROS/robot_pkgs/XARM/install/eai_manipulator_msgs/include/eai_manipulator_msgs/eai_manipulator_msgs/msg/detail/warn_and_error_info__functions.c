// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice
#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `level`
// Member `source`
// Member `info`
#include "rosidl_runtime_c/string_functions.h"

bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__init(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(msg);
    return false;
  }
  // level
  if (!rosidl_runtime_c__String__init(&msg->level)) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(msg);
    return false;
  }
  // code
  // source
  if (!rosidl_runtime_c__String__init(&msg->source)) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(msg);
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__init(&msg->info)) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(msg);
    return false;
  }
  return true;
}

void
eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // level
  rosidl_runtime_c__String__fini(&msg->level);
  // code
  // source
  rosidl_runtime_c__String__fini(&msg->source);
  // info
  rosidl_runtime_c__String__fini(&msg->info);
}

bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__are_equal(const eai_manipulator_msgs__msg__WarnAndErrorInfo * lhs, const eai_manipulator_msgs__msg__WarnAndErrorInfo * rhs)
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
  // level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->level), &(rhs->level)))
  {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source), &(rhs->source)))
  {
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  return true;
}

bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__copy(
  const eai_manipulator_msgs__msg__WarnAndErrorInfo * input,
  eai_manipulator_msgs__msg__WarnAndErrorInfo * output)
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
  // level
  if (!rosidl_runtime_c__String__copy(
      &(input->level), &(output->level)))
  {
    return false;
  }
  // code
  output->code = input->code;
  // source
  if (!rosidl_runtime_c__String__copy(
      &(input->source), &(output->source)))
  {
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  return true;
}

eai_manipulator_msgs__msg__WarnAndErrorInfo *
eai_manipulator_msgs__msg__WarnAndErrorInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__WarnAndErrorInfo * msg = (eai_manipulator_msgs__msg__WarnAndErrorInfo *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo));
  bool success = eai_manipulator_msgs__msg__WarnAndErrorInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
eai_manipulator_msgs__msg__WarnAndErrorInfo__destroy(eai_manipulator_msgs__msg__WarnAndErrorInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__init(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__WarnAndErrorInfo * data = NULL;

  if (size) {
    data = (eai_manipulator_msgs__msg__WarnAndErrorInfo *)allocator.zero_allocate(size, sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eai_manipulator_msgs__msg__WarnAndErrorInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(&data[i - 1]);
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
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__fini(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array)
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
      eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(&array->data[i]);
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

eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence *
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array = (eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__destroy(eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__are_equal(const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * lhs, const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eai_manipulator_msgs__msg__WarnAndErrorInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence__copy(
  const eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * input,
  eai_manipulator_msgs__msg__WarnAndErrorInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    eai_manipulator_msgs__msg__WarnAndErrorInfo * data =
      (eai_manipulator_msgs__msg__WarnAndErrorInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eai_manipulator_msgs__msg__WarnAndErrorInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eai_manipulator_msgs__msg__WarnAndErrorInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
