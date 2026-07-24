// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from eai_manipulator_msgs:srv/Mode.idl
// generated code does not contain a copyright notice
#include "eai_manipulator_msgs/srv/detail/mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
eai_manipulator_msgs__srv__Mode_Request__init(eai_manipulator_msgs__srv__Mode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  return true;
}

void
eai_manipulator_msgs__srv__Mode_Request__fini(eai_manipulator_msgs__srv__Mode_Request * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
eai_manipulator_msgs__srv__Mode_Request__are_equal(const eai_manipulator_msgs__srv__Mode_Request * lhs, const eai_manipulator_msgs__srv__Mode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
eai_manipulator_msgs__srv__Mode_Request__copy(
  const eai_manipulator_msgs__srv__Mode_Request * input,
  eai_manipulator_msgs__srv__Mode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

eai_manipulator_msgs__srv__Mode_Request *
eai_manipulator_msgs__srv__Mode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Request * msg = (eai_manipulator_msgs__srv__Mode_Request *)allocator.allocate(sizeof(eai_manipulator_msgs__srv__Mode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eai_manipulator_msgs__srv__Mode_Request));
  bool success = eai_manipulator_msgs__srv__Mode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
eai_manipulator_msgs__srv__Mode_Request__destroy(eai_manipulator_msgs__srv__Mode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    eai_manipulator_msgs__srv__Mode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
eai_manipulator_msgs__srv__Mode_Request__Sequence__init(eai_manipulator_msgs__srv__Mode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Request * data = NULL;

  if (size) {
    data = (eai_manipulator_msgs__srv__Mode_Request *)allocator.zero_allocate(size, sizeof(eai_manipulator_msgs__srv__Mode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eai_manipulator_msgs__srv__Mode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eai_manipulator_msgs__srv__Mode_Request__fini(&data[i - 1]);
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
eai_manipulator_msgs__srv__Mode_Request__Sequence__fini(eai_manipulator_msgs__srv__Mode_Request__Sequence * array)
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
      eai_manipulator_msgs__srv__Mode_Request__fini(&array->data[i]);
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

eai_manipulator_msgs__srv__Mode_Request__Sequence *
eai_manipulator_msgs__srv__Mode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Request__Sequence * array = (eai_manipulator_msgs__srv__Mode_Request__Sequence *)allocator.allocate(sizeof(eai_manipulator_msgs__srv__Mode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = eai_manipulator_msgs__srv__Mode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
eai_manipulator_msgs__srv__Mode_Request__Sequence__destroy(eai_manipulator_msgs__srv__Mode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    eai_manipulator_msgs__srv__Mode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
eai_manipulator_msgs__srv__Mode_Request__Sequence__are_equal(const eai_manipulator_msgs__srv__Mode_Request__Sequence * lhs, const eai_manipulator_msgs__srv__Mode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eai_manipulator_msgs__srv__Mode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eai_manipulator_msgs__srv__Mode_Request__Sequence__copy(
  const eai_manipulator_msgs__srv__Mode_Request__Sequence * input,
  eai_manipulator_msgs__srv__Mode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eai_manipulator_msgs__srv__Mode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    eai_manipulator_msgs__srv__Mode_Request * data =
      (eai_manipulator_msgs__srv__Mode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eai_manipulator_msgs__srv__Mode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          eai_manipulator_msgs__srv__Mode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eai_manipulator_msgs__srv__Mode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "rosidl_runtime_c/string_functions.h"

bool
eai_manipulator_msgs__srv__Mode_Response__init(eai_manipulator_msgs__srv__Mode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  // info
  if (!rosidl_runtime_c__String__init(&msg->info)) {
    eai_manipulator_msgs__srv__Mode_Response__fini(msg);
    return false;
  }
  return true;
}

void
eai_manipulator_msgs__srv__Mode_Response__fini(eai_manipulator_msgs__srv__Mode_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  // info
  rosidl_runtime_c__String__fini(&msg->info);
}

bool
eai_manipulator_msgs__srv__Mode_Response__are_equal(const eai_manipulator_msgs__srv__Mode_Response * lhs, const eai_manipulator_msgs__srv__Mode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
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
eai_manipulator_msgs__srv__Mode_Response__copy(
  const eai_manipulator_msgs__srv__Mode_Response * input,
  eai_manipulator_msgs__srv__Mode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  // info
  if (!rosidl_runtime_c__String__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  return true;
}

eai_manipulator_msgs__srv__Mode_Response *
eai_manipulator_msgs__srv__Mode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Response * msg = (eai_manipulator_msgs__srv__Mode_Response *)allocator.allocate(sizeof(eai_manipulator_msgs__srv__Mode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eai_manipulator_msgs__srv__Mode_Response));
  bool success = eai_manipulator_msgs__srv__Mode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
eai_manipulator_msgs__srv__Mode_Response__destroy(eai_manipulator_msgs__srv__Mode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    eai_manipulator_msgs__srv__Mode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
eai_manipulator_msgs__srv__Mode_Response__Sequence__init(eai_manipulator_msgs__srv__Mode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Response * data = NULL;

  if (size) {
    data = (eai_manipulator_msgs__srv__Mode_Response *)allocator.zero_allocate(size, sizeof(eai_manipulator_msgs__srv__Mode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eai_manipulator_msgs__srv__Mode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eai_manipulator_msgs__srv__Mode_Response__fini(&data[i - 1]);
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
eai_manipulator_msgs__srv__Mode_Response__Sequence__fini(eai_manipulator_msgs__srv__Mode_Response__Sequence * array)
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
      eai_manipulator_msgs__srv__Mode_Response__fini(&array->data[i]);
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

eai_manipulator_msgs__srv__Mode_Response__Sequence *
eai_manipulator_msgs__srv__Mode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__srv__Mode_Response__Sequence * array = (eai_manipulator_msgs__srv__Mode_Response__Sequence *)allocator.allocate(sizeof(eai_manipulator_msgs__srv__Mode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = eai_manipulator_msgs__srv__Mode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
eai_manipulator_msgs__srv__Mode_Response__Sequence__destroy(eai_manipulator_msgs__srv__Mode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    eai_manipulator_msgs__srv__Mode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
eai_manipulator_msgs__srv__Mode_Response__Sequence__are_equal(const eai_manipulator_msgs__srv__Mode_Response__Sequence * lhs, const eai_manipulator_msgs__srv__Mode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eai_manipulator_msgs__srv__Mode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eai_manipulator_msgs__srv__Mode_Response__Sequence__copy(
  const eai_manipulator_msgs__srv__Mode_Response__Sequence * input,
  eai_manipulator_msgs__srv__Mode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eai_manipulator_msgs__srv__Mode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    eai_manipulator_msgs__srv__Mode_Response * data =
      (eai_manipulator_msgs__srv__Mode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eai_manipulator_msgs__srv__Mode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          eai_manipulator_msgs__srv__Mode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eai_manipulator_msgs__srv__Mode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
