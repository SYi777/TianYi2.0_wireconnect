// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cm_msgs:srv/CommonRespRos2.idl
// generated code does not contain a copyright notice
#include "cm_msgs/srv/detail/common_resp_ros2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `msg_id`
// Member `json_data`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cm_msgs__srv__CommonRespRos2_Request__init(cm_msgs__srv__CommonRespRos2_Request * msg)
{
  if (!msg) {
    return false;
  }
  // msg_id
  if (!rosidl_runtime_c__String__init(&msg->msg_id)) {
    cm_msgs__srv__CommonRespRos2_Request__fini(msg);
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__init(&msg->json_data)) {
    cm_msgs__srv__CommonRespRos2_Request__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    cm_msgs__srv__CommonRespRos2_Request__fini(msg);
    return false;
  }
  return true;
}

void
cm_msgs__srv__CommonRespRos2_Request__fini(cm_msgs__srv__CommonRespRos2_Request * msg)
{
  if (!msg) {
    return;
  }
  // msg_id
  rosidl_runtime_c__String__fini(&msg->msg_id);
  // json_data
  rosidl_runtime_c__String__fini(&msg->json_data);
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
cm_msgs__srv__CommonRespRos2_Request__are_equal(const cm_msgs__srv__CommonRespRos2_Request * lhs, const cm_msgs__srv__CommonRespRos2_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg_id), &(rhs->msg_id)))
  {
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->json_data), &(rhs->json_data)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
cm_msgs__srv__CommonRespRos2_Request__copy(
  const cm_msgs__srv__CommonRespRos2_Request * input,
  cm_msgs__srv__CommonRespRos2_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // msg_id
  if (!rosidl_runtime_c__String__copy(
      &(input->msg_id), &(output->msg_id)))
  {
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__copy(
      &(input->json_data), &(output->json_data)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

cm_msgs__srv__CommonRespRos2_Request *
cm_msgs__srv__CommonRespRos2_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Request * msg = (cm_msgs__srv__CommonRespRos2_Request *)allocator.allocate(sizeof(cm_msgs__srv__CommonRespRos2_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cm_msgs__srv__CommonRespRos2_Request));
  bool success = cm_msgs__srv__CommonRespRos2_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cm_msgs__srv__CommonRespRos2_Request__destroy(cm_msgs__srv__CommonRespRos2_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cm_msgs__srv__CommonRespRos2_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cm_msgs__srv__CommonRespRos2_Request__Sequence__init(cm_msgs__srv__CommonRespRos2_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Request * data = NULL;

  if (size) {
    data = (cm_msgs__srv__CommonRespRos2_Request *)allocator.zero_allocate(size, sizeof(cm_msgs__srv__CommonRespRos2_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cm_msgs__srv__CommonRespRos2_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cm_msgs__srv__CommonRespRos2_Request__fini(&data[i - 1]);
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
cm_msgs__srv__CommonRespRos2_Request__Sequence__fini(cm_msgs__srv__CommonRespRos2_Request__Sequence * array)
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
      cm_msgs__srv__CommonRespRos2_Request__fini(&array->data[i]);
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

cm_msgs__srv__CommonRespRos2_Request__Sequence *
cm_msgs__srv__CommonRespRos2_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Request__Sequence * array = (cm_msgs__srv__CommonRespRos2_Request__Sequence *)allocator.allocate(sizeof(cm_msgs__srv__CommonRespRos2_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cm_msgs__srv__CommonRespRos2_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cm_msgs__srv__CommonRespRos2_Request__Sequence__destroy(cm_msgs__srv__CommonRespRos2_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cm_msgs__srv__CommonRespRos2_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cm_msgs__srv__CommonRespRos2_Request__Sequence__are_equal(const cm_msgs__srv__CommonRespRos2_Request__Sequence * lhs, const cm_msgs__srv__CommonRespRos2_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cm_msgs__srv__CommonRespRos2_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cm_msgs__srv__CommonRespRos2_Request__Sequence__copy(
  const cm_msgs__srv__CommonRespRos2_Request__Sequence * input,
  cm_msgs__srv__CommonRespRos2_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cm_msgs__srv__CommonRespRos2_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cm_msgs__srv__CommonRespRos2_Request * data =
      (cm_msgs__srv__CommonRespRos2_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cm_msgs__srv__CommonRespRos2_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cm_msgs__srv__CommonRespRos2_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cm_msgs__srv__CommonRespRos2_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `msg_id`
// Member `json_data`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `data`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cm_msgs__srv__CommonRespRos2_Response__init(cm_msgs__srv__CommonRespRos2_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  // msg_id
  if (!rosidl_runtime_c__String__init(&msg->msg_id)) {
    cm_msgs__srv__CommonRespRos2_Response__fini(msg);
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__init(&msg->json_data)) {
    cm_msgs__srv__CommonRespRos2_Response__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    cm_msgs__srv__CommonRespRos2_Response__fini(msg);
    return false;
  }
  return true;
}

void
cm_msgs__srv__CommonRespRos2_Response__fini(cm_msgs__srv__CommonRespRos2_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  // msg_id
  rosidl_runtime_c__String__fini(&msg->msg_id);
  // json_data
  rosidl_runtime_c__String__fini(&msg->json_data);
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
cm_msgs__srv__CommonRespRos2_Response__are_equal(const cm_msgs__srv__CommonRespRos2_Response * lhs, const cm_msgs__srv__CommonRespRos2_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  // msg_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg_id), &(rhs->msg_id)))
  {
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->json_data), &(rhs->json_data)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
cm_msgs__srv__CommonRespRos2_Response__copy(
  const cm_msgs__srv__CommonRespRos2_Response * input,
  cm_msgs__srv__CommonRespRos2_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  // msg_id
  if (!rosidl_runtime_c__String__copy(
      &(input->msg_id), &(output->msg_id)))
  {
    return false;
  }
  // json_data
  if (!rosidl_runtime_c__String__copy(
      &(input->json_data), &(output->json_data)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

cm_msgs__srv__CommonRespRos2_Response *
cm_msgs__srv__CommonRespRos2_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Response * msg = (cm_msgs__srv__CommonRespRos2_Response *)allocator.allocate(sizeof(cm_msgs__srv__CommonRespRos2_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cm_msgs__srv__CommonRespRos2_Response));
  bool success = cm_msgs__srv__CommonRespRos2_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cm_msgs__srv__CommonRespRos2_Response__destroy(cm_msgs__srv__CommonRespRos2_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cm_msgs__srv__CommonRespRos2_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cm_msgs__srv__CommonRespRos2_Response__Sequence__init(cm_msgs__srv__CommonRespRos2_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Response * data = NULL;

  if (size) {
    data = (cm_msgs__srv__CommonRespRos2_Response *)allocator.zero_allocate(size, sizeof(cm_msgs__srv__CommonRespRos2_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cm_msgs__srv__CommonRespRos2_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cm_msgs__srv__CommonRespRos2_Response__fini(&data[i - 1]);
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
cm_msgs__srv__CommonRespRos2_Response__Sequence__fini(cm_msgs__srv__CommonRespRos2_Response__Sequence * array)
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
      cm_msgs__srv__CommonRespRos2_Response__fini(&array->data[i]);
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

cm_msgs__srv__CommonRespRos2_Response__Sequence *
cm_msgs__srv__CommonRespRos2_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__srv__CommonRespRos2_Response__Sequence * array = (cm_msgs__srv__CommonRespRos2_Response__Sequence *)allocator.allocate(sizeof(cm_msgs__srv__CommonRespRos2_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cm_msgs__srv__CommonRespRos2_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cm_msgs__srv__CommonRespRos2_Response__Sequence__destroy(cm_msgs__srv__CommonRespRos2_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cm_msgs__srv__CommonRespRos2_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cm_msgs__srv__CommonRespRos2_Response__Sequence__are_equal(const cm_msgs__srv__CommonRespRos2_Response__Sequence * lhs, const cm_msgs__srv__CommonRespRos2_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cm_msgs__srv__CommonRespRos2_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cm_msgs__srv__CommonRespRos2_Response__Sequence__copy(
  const cm_msgs__srv__CommonRespRos2_Response__Sequence * input,
  cm_msgs__srv__CommonRespRos2_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cm_msgs__srv__CommonRespRos2_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cm_msgs__srv__CommonRespRos2_Response * data =
      (cm_msgs__srv__CommonRespRos2_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cm_msgs__srv__CommonRespRos2_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cm_msgs__srv__CommonRespRos2_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cm_msgs__srv__CommonRespRos2_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
