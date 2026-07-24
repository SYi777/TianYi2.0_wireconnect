// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice
#include "cloud_service/msg/detail/command_ack__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
cloud_service__msg__CommandAck__init(cloud_service__msg__CommandAck * msg)
{
  if (!msg) {
    return false;
  }
  // msg_id
  // cmd_id
  // code
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    cloud_service__msg__CommandAck__fini(msg);
    return false;
  }
  return true;
}

void
cloud_service__msg__CommandAck__fini(cloud_service__msg__CommandAck * msg)
{
  if (!msg) {
    return;
  }
  // msg_id
  // cmd_id
  // code
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
cloud_service__msg__CommandAck__are_equal(const cloud_service__msg__CommandAck * lhs, const cloud_service__msg__CommandAck * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg_id
  if (lhs->msg_id != rhs->msg_id) {
    return false;
  }
  // cmd_id
  if (lhs->cmd_id != rhs->cmd_id) {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
cloud_service__msg__CommandAck__copy(
  const cloud_service__msg__CommandAck * input,
  cloud_service__msg__CommandAck * output)
{
  if (!input || !output) {
    return false;
  }
  // msg_id
  output->msg_id = input->msg_id;
  // cmd_id
  output->cmd_id = input->cmd_id;
  // code
  output->code = input->code;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

cloud_service__msg__CommandAck *
cloud_service__msg__CommandAck__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__CommandAck * msg = (cloud_service__msg__CommandAck *)allocator.allocate(sizeof(cloud_service__msg__CommandAck), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cloud_service__msg__CommandAck));
  bool success = cloud_service__msg__CommandAck__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cloud_service__msg__CommandAck__destroy(cloud_service__msg__CommandAck * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cloud_service__msg__CommandAck__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cloud_service__msg__CommandAck__Sequence__init(cloud_service__msg__CommandAck__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__CommandAck * data = NULL;

  if (size) {
    data = (cloud_service__msg__CommandAck *)allocator.zero_allocate(size, sizeof(cloud_service__msg__CommandAck), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cloud_service__msg__CommandAck__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cloud_service__msg__CommandAck__fini(&data[i - 1]);
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
cloud_service__msg__CommandAck__Sequence__fini(cloud_service__msg__CommandAck__Sequence * array)
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
      cloud_service__msg__CommandAck__fini(&array->data[i]);
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

cloud_service__msg__CommandAck__Sequence *
cloud_service__msg__CommandAck__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cloud_service__msg__CommandAck__Sequence * array = (cloud_service__msg__CommandAck__Sequence *)allocator.allocate(sizeof(cloud_service__msg__CommandAck__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cloud_service__msg__CommandAck__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cloud_service__msg__CommandAck__Sequence__destroy(cloud_service__msg__CommandAck__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cloud_service__msg__CommandAck__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cloud_service__msg__CommandAck__Sequence__are_equal(const cloud_service__msg__CommandAck__Sequence * lhs, const cloud_service__msg__CommandAck__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cloud_service__msg__CommandAck__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cloud_service__msg__CommandAck__Sequence__copy(
  const cloud_service__msg__CommandAck__Sequence * input,
  cloud_service__msg__CommandAck__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cloud_service__msg__CommandAck);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cloud_service__msg__CommandAck * data =
      (cloud_service__msg__CommandAck *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cloud_service__msg__CommandAck__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cloud_service__msg__CommandAck__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cloud_service__msg__CommandAck__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
