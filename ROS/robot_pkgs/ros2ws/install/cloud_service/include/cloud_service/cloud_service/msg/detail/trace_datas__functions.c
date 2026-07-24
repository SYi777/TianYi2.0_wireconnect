// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice
#include "cloud_service/msg/detail/trace_datas__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `model`
// Member `event_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `trace_array`
#include "cloud_service/msg/detail/trace_data__functions.h"

bool
cloud_service__msg__TraceDatas__init(cloud_service__msg__TraceDatas * msg)
{
  if (!msg) {
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__init(&msg->model)) {
    cloud_service__msg__TraceDatas__fini(msg);
    return false;
  }
  // event_name
  if (!rosidl_runtime_c__String__init(&msg->event_name)) {
    cloud_service__msg__TraceDatas__fini(msg);
    return false;
  }
  // trace_array
  if (!cloud_service__msg__TraceData__Sequence__init(&msg->trace_array, 0)) {
    cloud_service__msg__TraceDatas__fini(msg);
    return false;
  }
  return true;
}

void
cloud_service__msg__TraceDatas__fini(cloud_service__msg__TraceDatas * msg)
{
  if (!msg) {
    return;
  }
  // model
  rosidl_runtime_c__String__fini(&msg->model);
  // event_name
  rosidl_runtime_c__String__fini(&msg->event_name);
  // trace_array
  cloud_service__msg__TraceData__Sequence__fini(&msg->trace_array);
}

bool
cloud_service__msg__TraceDatas__are_equal(const cloud_service__msg__TraceDatas * lhs, const cloud_service__msg__TraceDatas * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model), &(rhs->model)))
  {
    return false;
  }
  // event_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->event_name), &(rhs->event_name)))
  {
    return false;
  }
  // trace_array
  if (!cloud_service__msg__TraceData__Sequence__are_equal(
      &(lhs->trace_array), &(rhs->trace_array)))
  {
    return false;
  }
  return true;
}

bool
cloud_service__msg__TraceDatas__copy(
  const cloud_service__msg__TraceDatas * input,
  cloud_service__msg__TraceDatas * output)
{
  if (!input || !output) {
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__copy(
      &(input->model), &(output->model)))
  {
    return false;
  }
  // event_name
  if (!rosidl_runtime_c__String__copy(
      &(input->event_name), &(output->event_name)))
  {
    return false;
  }
  // trace_array
  if (!cloud_service__msg__TraceData__Sequence__copy(
      &(input->trace_array), &(output->trace_array)))
  {
    return false;
  }
  return true;
}

cloud_service__msg__TraceDatas *
cloud_service__msg__TraceDatas__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceDatas * msg = (cloud_service__msg__TraceDatas *)allocator.allocate(sizeof(cloud_service__msg__TraceDatas), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cloud_service__msg__TraceDatas));
  bool success = cloud_service__msg__TraceDatas__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cloud_service__msg__TraceDatas__destroy(cloud_service__msg__TraceDatas * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cloud_service__msg__TraceDatas__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cloud_service__msg__TraceDatas__Sequence__init(cloud_service__msg__TraceDatas__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceDatas * data = NULL;

  if (size) {
    data = (cloud_service__msg__TraceDatas *)allocator.zero_allocate(size, sizeof(cloud_service__msg__TraceDatas), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cloud_service__msg__TraceDatas__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cloud_service__msg__TraceDatas__fini(&data[i - 1]);
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
cloud_service__msg__TraceDatas__Sequence__fini(cloud_service__msg__TraceDatas__Sequence * array)
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
      cloud_service__msg__TraceDatas__fini(&array->data[i]);
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

cloud_service__msg__TraceDatas__Sequence *
cloud_service__msg__TraceDatas__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__TraceDatas__Sequence * array = (cloud_service__msg__TraceDatas__Sequence *)allocator.allocate(sizeof(cloud_service__msg__TraceDatas__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cloud_service__msg__TraceDatas__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cloud_service__msg__TraceDatas__Sequence__destroy(cloud_service__msg__TraceDatas__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cloud_service__msg__TraceDatas__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cloud_service__msg__TraceDatas__Sequence__are_equal(const cloud_service__msg__TraceDatas__Sequence * lhs, const cloud_service__msg__TraceDatas__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cloud_service__msg__TraceDatas__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cloud_service__msg__TraceDatas__Sequence__copy(
  const cloud_service__msg__TraceDatas__Sequence * input,
  cloud_service__msg__TraceDatas__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cloud_service__msg__TraceDatas);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cloud_service__msg__TraceDatas * data =
      (cloud_service__msg__TraceDatas *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cloud_service__msg__TraceDatas__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cloud_service__msg__TraceDatas__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cloud_service__msg__TraceDatas__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
