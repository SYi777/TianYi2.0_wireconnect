// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cloud_service:srv/Register.idl
// generated code does not contain a copyright notice
#include "cloud_service/srv/detail/register__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `handler_service_name`
#include "rosidl_runtime_c/string_functions.h"

bool
cloud_service__srv__Register_Request__init(cloud_service__srv__Register_Request * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_id
  // handler_service_name
  if (!rosidl_runtime_c__String__init(&msg->handler_service_name)) {
    cloud_service__srv__Register_Request__fini(msg);
    return false;
  }
  return true;
}

void
cloud_service__srv__Register_Request__fini(cloud_service__srv__Register_Request * msg)
{
  if (!msg) {
    return;
  }
  // cmd_id
  // handler_service_name
  rosidl_runtime_c__String__fini(&msg->handler_service_name);
}

bool
cloud_service__srv__Register_Request__are_equal(const cloud_service__srv__Register_Request * lhs, const cloud_service__srv__Register_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_id
  if (lhs->cmd_id != rhs->cmd_id) {
    return false;
  }
  // handler_service_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->handler_service_name), &(rhs->handler_service_name)))
  {
    return false;
  }
  return true;
}

bool
cloud_service__srv__Register_Request__copy(
  const cloud_service__srv__Register_Request * input,
  cloud_service__srv__Register_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_id
  output->cmd_id = input->cmd_id;
  // handler_service_name
  if (!rosidl_runtime_c__String__copy(
      &(input->handler_service_name), &(output->handler_service_name)))
  {
    return false;
  }
  return true;
}

cloud_service__srv__Register_Request *
cloud_service__srv__Register_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Request * msg = (cloud_service__srv__Register_Request *)allocator.allocate(sizeof(cloud_service__srv__Register_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cloud_service__srv__Register_Request));
  bool success = cloud_service__srv__Register_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cloud_service__srv__Register_Request__destroy(cloud_service__srv__Register_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cloud_service__srv__Register_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cloud_service__srv__Register_Request__Sequence__init(cloud_service__srv__Register_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Request * data = NULL;

  if (size) {
    data = (cloud_service__srv__Register_Request *)allocator.zero_allocate(size, sizeof(cloud_service__srv__Register_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cloud_service__srv__Register_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cloud_service__srv__Register_Request__fini(&data[i - 1]);
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
cloud_service__srv__Register_Request__Sequence__fini(cloud_service__srv__Register_Request__Sequence * array)
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
      cloud_service__srv__Register_Request__fini(&array->data[i]);
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

cloud_service__srv__Register_Request__Sequence *
cloud_service__srv__Register_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Request__Sequence * array = (cloud_service__srv__Register_Request__Sequence *)allocator.allocate(sizeof(cloud_service__srv__Register_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cloud_service__srv__Register_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cloud_service__srv__Register_Request__Sequence__destroy(cloud_service__srv__Register_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cloud_service__srv__Register_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cloud_service__srv__Register_Request__Sequence__are_equal(const cloud_service__srv__Register_Request__Sequence * lhs, const cloud_service__srv__Register_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cloud_service__srv__Register_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cloud_service__srv__Register_Request__Sequence__copy(
  const cloud_service__srv__Register_Request__Sequence * input,
  cloud_service__srv__Register_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cloud_service__srv__Register_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cloud_service__srv__Register_Request * data =
      (cloud_service__srv__Register_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cloud_service__srv__Register_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cloud_service__srv__Register_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cloud_service__srv__Register_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cloud_service__srv__Register_Response__init(cloud_service__srv__Register_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
cloud_service__srv__Register_Response__fini(cloud_service__srv__Register_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
cloud_service__srv__Register_Response__are_equal(const cloud_service__srv__Register_Response * lhs, const cloud_service__srv__Register_Response * rhs)
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
cloud_service__srv__Register_Response__copy(
  const cloud_service__srv__Register_Response * input,
  cloud_service__srv__Register_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

cloud_service__srv__Register_Response *
cloud_service__srv__Register_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Response * msg = (cloud_service__srv__Register_Response *)allocator.allocate(sizeof(cloud_service__srv__Register_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cloud_service__srv__Register_Response));
  bool success = cloud_service__srv__Register_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cloud_service__srv__Register_Response__destroy(cloud_service__srv__Register_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cloud_service__srv__Register_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cloud_service__srv__Register_Response__Sequence__init(cloud_service__srv__Register_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Response * data = NULL;

  if (size) {
    data = (cloud_service__srv__Register_Response *)allocator.zero_allocate(size, sizeof(cloud_service__srv__Register_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cloud_service__srv__Register_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cloud_service__srv__Register_Response__fini(&data[i - 1]);
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
cloud_service__srv__Register_Response__Sequence__fini(cloud_service__srv__Register_Response__Sequence * array)
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
      cloud_service__srv__Register_Response__fini(&array->data[i]);
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

cloud_service__srv__Register_Response__Sequence *
cloud_service__srv__Register_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__srv__Register_Response__Sequence * array = (cloud_service__srv__Register_Response__Sequence *)allocator.allocate(sizeof(cloud_service__srv__Register_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cloud_service__srv__Register_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cloud_service__srv__Register_Response__Sequence__destroy(cloud_service__srv__Register_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cloud_service__srv__Register_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cloud_service__srv__Register_Response__Sequence__are_equal(const cloud_service__srv__Register_Response__Sequence * lhs, const cloud_service__srv__Register_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cloud_service__srv__Register_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cloud_service__srv__Register_Response__Sequence__copy(
  const cloud_service__srv__Register_Response__Sequence * input,
  cloud_service__srv__Register_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cloud_service__srv__Register_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cloud_service__srv__Register_Response * data =
      (cloud_service__srv__Register_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cloud_service__srv__Register_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cloud_service__srv__Register_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cloud_service__srv__Register_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
