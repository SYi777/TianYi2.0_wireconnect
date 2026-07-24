// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cloud_service:msg/TraceData.idl
// generated code does not contain a copyright notice
#include "cloud_service/msg/detail/trace_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `key`
// Member `str_val`
#include "rosidl_runtime_c/string_functions.h"

bool
cloud_service__msg__TraceData__init(cloud_service__msg__TraceData * msg)
{
  if (!msg) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__init(&msg->key)) {
    cloud_service__msg__TraceData__fini(msg);
    return false;
  }
  // data_type
  // int_val
  // str_val
  if (!rosidl_runtime_c__String__init(&msg->str_val)) {
    cloud_service__msg__TraceData__fini(msg);
    return false;
  }
  // bool_val
  // double_val
  return true;
}

void
cloud_service__msg__TraceData__fini(cloud_service__msg__TraceData * msg)
{
  if (!msg) {
    return;
  }
  // key
  rosidl_runtime_c__String__fini(&msg->key);
  // data_type
  // int_val
  // str_val
  rosidl_runtime_c__String__fini(&msg->str_val);
  // bool_val
  // double_val
}

bool
cloud_service__msg__TraceData__are_equal(const cloud_service__msg__TraceData * lhs, const cloud_service__msg__TraceData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->key), &(rhs->key)))
  {
    return false;
  }
  // data_type
  if (lhs->data_type != rhs->data_type) {
    return false;
  }
  // int_val
  if (lhs->int_val != rhs->int_val) {
    return false;
  }
  // str_val
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->str_val), &(rhs->str_val)))
  {
    return false;
  }
  // bool_val
  if (lhs->bool_val != rhs->bool_val) {
    return false;
  }
  // double_val
  if (lhs->double_val != rhs->double_val) {
    return false;
  }
  return true;
}

bool
cloud_service__msg__TraceData__copy(
  const cloud_service__msg__TraceData * input,
  cloud_service__msg__TraceData * output)
{
  if (!input || !output) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__copy(
      &(input->key), &(output->key)))
  {
    return false;
  }
  // data_type
  output->data_type = input->data_type;
  // int_val
  output->int_val = input->int_val;
  // str_val
  if (!rosidl_runtime_c__String__copy(
      &(input->str_val), &(output->str_val)))
  {
    return false;
  }
  // bool_val
  output->bool_val = input->bool_val;
  // double_val
  output->double_val = input->double_val;
  return true;
}

cloud_service__msg__TraceData *
cloud_service__msg__TraceData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceData * msg = (cloud_service__msg__TraceData *)allocator.allocate(sizeof(cloud_service__msg__TraceData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cloud_service__msg__TraceData));
  bool success = cloud_service__msg__TraceData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cloud_service__msg__TraceData__destroy(cloud_service__msg__TraceData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cloud_service__msg__TraceData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cloud_service__msg__TraceData__Sequence__init(cloud_service__msg__TraceData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceData * data = NULL;

  if (size) {
    data = (cloud_service__msg__TraceData *)allocator.zero_allocate(size, sizeof(cloud_service__msg__TraceData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cloud_service__msg__TraceData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cloud_service__msg__TraceData__fini(&data[i - 1]);
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
cloud_service__msg__TraceData__Sequence__fini(cloud_service__msg__TraceData__Sequence * array)
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
      cloud_service__msg__TraceData__fini(&array->data[i]);
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

cloud_service__msg__TraceData__Sequence *
cloud_service__msg__TraceData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceData__Sequence * array = (cloud_service__msg__TraceData__Sequence *)allocator.allocate(sizeof(cloud_service__msg__TraceData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cloud_service__msg__TraceData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cloud_service__msg__TraceData__Sequence__destroy(cloud_service__msg__TraceData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cloud_service__msg__TraceData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cloud_service__msg__TraceData__Sequence__are_equal(const cloud_service__msg__TraceData__Sequence * lhs, const cloud_service__msg__TraceData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cloud_service__msg__TraceData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cloud_service__msg__TraceData__Sequence__copy(
  const cloud_service__msg__TraceData__Sequence * input,
  cloud_service__msg__TraceData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cloud_service__msg__TraceData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cloud_service__msg__TraceData * data =
      (cloud_service__msg__TraceData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cloud_service__msg__TraceData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cloud_service__msg__TraceData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cloud_service__msg__TraceData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
