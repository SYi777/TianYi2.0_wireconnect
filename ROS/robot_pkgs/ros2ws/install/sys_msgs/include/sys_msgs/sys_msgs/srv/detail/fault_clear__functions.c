// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sys_msgs:srv/FaultClear.idl
// generated code does not contain a copyright notice
#include "sys_msgs/srv/detail/fault_clear__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `fault_array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
sys_msgs__srv__FaultClear_Request__init(sys_msgs__srv__FaultClear_Request * msg)
{
  if (!msg) {
    return false;
  }
  // fault_array
  if (!rosidl_runtime_c__uint64__Sequence__init(&msg->fault_array, 0)) {
    sys_msgs__srv__FaultClear_Request__fini(msg);
    return false;
  }
  return true;
}

void
sys_msgs__srv__FaultClear_Request__fini(sys_msgs__srv__FaultClear_Request * msg)
{
  if (!msg) {
    return;
  }
  // fault_array
  rosidl_runtime_c__uint64__Sequence__fini(&msg->fault_array);
}

bool
sys_msgs__srv__FaultClear_Request__are_equal(const sys_msgs__srv__FaultClear_Request * lhs, const sys_msgs__srv__FaultClear_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fault_array
  if (!rosidl_runtime_c__uint64__Sequence__are_equal(
      &(lhs->fault_array), &(rhs->fault_array)))
  {
    return false;
  }
  return true;
}

bool
sys_msgs__srv__FaultClear_Request__copy(
  const sys_msgs__srv__FaultClear_Request * input,
  sys_msgs__srv__FaultClear_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // fault_array
  if (!rosidl_runtime_c__uint64__Sequence__copy(
      &(input->fault_array), &(output->fault_array)))
  {
    return false;
  }
  return true;
}

sys_msgs__srv__FaultClear_Request *
sys_msgs__srv__FaultClear_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Request * msg = (sys_msgs__srv__FaultClear_Request *)allocator.allocate(sizeof(sys_msgs__srv__FaultClear_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sys_msgs__srv__FaultClear_Request));
  bool success = sys_msgs__srv__FaultClear_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sys_msgs__srv__FaultClear_Request__destroy(sys_msgs__srv__FaultClear_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sys_msgs__srv__FaultClear_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sys_msgs__srv__FaultClear_Request__Sequence__init(sys_msgs__srv__FaultClear_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Request * data = NULL;

  if (size) {
    data = (sys_msgs__srv__FaultClear_Request *)allocator.zero_allocate(size, sizeof(sys_msgs__srv__FaultClear_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sys_msgs__srv__FaultClear_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sys_msgs__srv__FaultClear_Request__fini(&data[i - 1]);
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
sys_msgs__srv__FaultClear_Request__Sequence__fini(sys_msgs__srv__FaultClear_Request__Sequence * array)
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
      sys_msgs__srv__FaultClear_Request__fini(&array->data[i]);
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

sys_msgs__srv__FaultClear_Request__Sequence *
sys_msgs__srv__FaultClear_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Request__Sequence * array = (sys_msgs__srv__FaultClear_Request__Sequence *)allocator.allocate(sizeof(sys_msgs__srv__FaultClear_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sys_msgs__srv__FaultClear_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sys_msgs__srv__FaultClear_Request__Sequence__destroy(sys_msgs__srv__FaultClear_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sys_msgs__srv__FaultClear_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sys_msgs__srv__FaultClear_Request__Sequence__are_equal(const sys_msgs__srv__FaultClear_Request__Sequence * lhs, const sys_msgs__srv__FaultClear_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sys_msgs__srv__FaultClear_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sys_msgs__srv__FaultClear_Request__Sequence__copy(
  const sys_msgs__srv__FaultClear_Request__Sequence * input,
  sys_msgs__srv__FaultClear_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sys_msgs__srv__FaultClear_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sys_msgs__srv__FaultClear_Request * data =
      (sys_msgs__srv__FaultClear_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sys_msgs__srv__FaultClear_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sys_msgs__srv__FaultClear_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sys_msgs__srv__FaultClear_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
sys_msgs__srv__FaultClear_Response__init(sys_msgs__srv__FaultClear_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
sys_msgs__srv__FaultClear_Response__fini(sys_msgs__srv__FaultClear_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
sys_msgs__srv__FaultClear_Response__are_equal(const sys_msgs__srv__FaultClear_Response * lhs, const sys_msgs__srv__FaultClear_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
sys_msgs__srv__FaultClear_Response__copy(
  const sys_msgs__srv__FaultClear_Response * input,
  sys_msgs__srv__FaultClear_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

sys_msgs__srv__FaultClear_Response *
sys_msgs__srv__FaultClear_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Response * msg = (sys_msgs__srv__FaultClear_Response *)allocator.allocate(sizeof(sys_msgs__srv__FaultClear_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sys_msgs__srv__FaultClear_Response));
  bool success = sys_msgs__srv__FaultClear_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sys_msgs__srv__FaultClear_Response__destroy(sys_msgs__srv__FaultClear_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sys_msgs__srv__FaultClear_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sys_msgs__srv__FaultClear_Response__Sequence__init(sys_msgs__srv__FaultClear_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Response * data = NULL;

  if (size) {
    data = (sys_msgs__srv__FaultClear_Response *)allocator.zero_allocate(size, sizeof(sys_msgs__srv__FaultClear_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sys_msgs__srv__FaultClear_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sys_msgs__srv__FaultClear_Response__fini(&data[i - 1]);
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
sys_msgs__srv__FaultClear_Response__Sequence__fini(sys_msgs__srv__FaultClear_Response__Sequence * array)
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
      sys_msgs__srv__FaultClear_Response__fini(&array->data[i]);
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

sys_msgs__srv__FaultClear_Response__Sequence *
sys_msgs__srv__FaultClear_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sys_msgs__srv__FaultClear_Response__Sequence * array = (sys_msgs__srv__FaultClear_Response__Sequence *)allocator.allocate(sizeof(sys_msgs__srv__FaultClear_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sys_msgs__srv__FaultClear_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sys_msgs__srv__FaultClear_Response__Sequence__destroy(sys_msgs__srv__FaultClear_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sys_msgs__srv__FaultClear_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sys_msgs__srv__FaultClear_Response__Sequence__are_equal(const sys_msgs__srv__FaultClear_Response__Sequence * lhs, const sys_msgs__srv__FaultClear_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sys_msgs__srv__FaultClear_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sys_msgs__srv__FaultClear_Response__Sequence__copy(
  const sys_msgs__srv__FaultClear_Response__Sequence * input,
  sys_msgs__srv__FaultClear_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sys_msgs__srv__FaultClear_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sys_msgs__srv__FaultClear_Response * data =
      (sys_msgs__srv__FaultClear_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sys_msgs__srv__FaultClear_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sys_msgs__srv__FaultClear_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sys_msgs__srv__FaultClear_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
