// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
// generated code does not contain a copyright notice
#include "eai_manipulator_msgs/msg/detail/arm_target_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `target`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `from_frame`
// Member `to_frame`
#include "rosidl_runtime_c/string_functions.h"

bool
eai_manipulator_msgs__msg__ArmTargetPose__init(eai_manipulator_msgs__msg__ArmTargetPose * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    eai_manipulator_msgs__msg__ArmTargetPose__fini(msg);
    return false;
  }
  // target
  if (!geometry_msgs__msg__Pose__init(&msg->target)) {
    eai_manipulator_msgs__msg__ArmTargetPose__fini(msg);
    return false;
  }
  // from_frame
  if (!rosidl_runtime_c__String__init(&msg->from_frame)) {
    eai_manipulator_msgs__msg__ArmTargetPose__fini(msg);
    return false;
  }
  // to_frame
  if (!rosidl_runtime_c__String__init(&msg->to_frame)) {
    eai_manipulator_msgs__msg__ArmTargetPose__fini(msg);
    return false;
  }
  // offset_x
  // offset_y
  // offset_z
  return true;
}

void
eai_manipulator_msgs__msg__ArmTargetPose__fini(eai_manipulator_msgs__msg__ArmTargetPose * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // target
  geometry_msgs__msg__Pose__fini(&msg->target);
  // from_frame
  rosidl_runtime_c__String__fini(&msg->from_frame);
  // to_frame
  rosidl_runtime_c__String__fini(&msg->to_frame);
  // offset_x
  // offset_y
  // offset_z
}

bool
eai_manipulator_msgs__msg__ArmTargetPose__are_equal(const eai_manipulator_msgs__msg__ArmTargetPose * lhs, const eai_manipulator_msgs__msg__ArmTargetPose * rhs)
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
  // target
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  // from_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->from_frame), &(rhs->from_frame)))
  {
    return false;
  }
  // to_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to_frame), &(rhs->to_frame)))
  {
    return false;
  }
  // offset_x
  if (lhs->offset_x != rhs->offset_x) {
    return false;
  }
  // offset_y
  if (lhs->offset_y != rhs->offset_y) {
    return false;
  }
  // offset_z
  if (lhs->offset_z != rhs->offset_z) {
    return false;
  }
  return true;
}

bool
eai_manipulator_msgs__msg__ArmTargetPose__copy(
  const eai_manipulator_msgs__msg__ArmTargetPose * input,
  eai_manipulator_msgs__msg__ArmTargetPose * output)
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
  // target
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  // from_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->from_frame), &(output->from_frame)))
  {
    return false;
  }
  // to_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->to_frame), &(output->to_frame)))
  {
    return false;
  }
  // offset_x
  output->offset_x = input->offset_x;
  // offset_y
  output->offset_y = input->offset_y;
  // offset_z
  output->offset_z = input->offset_z;
  return true;
}

eai_manipulator_msgs__msg__ArmTargetPose *
eai_manipulator_msgs__msg__ArmTargetPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__ArmTargetPose * msg = (eai_manipulator_msgs__msg__ArmTargetPose *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__ArmTargetPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eai_manipulator_msgs__msg__ArmTargetPose));
  bool success = eai_manipulator_msgs__msg__ArmTargetPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
eai_manipulator_msgs__msg__ArmTargetPose__destroy(eai_manipulator_msgs__msg__ArmTargetPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    eai_manipulator_msgs__msg__ArmTargetPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__init(eai_manipulator_msgs__msg__ArmTargetPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__ArmTargetPose * data = NULL;

  if (size) {
    data = (eai_manipulator_msgs__msg__ArmTargetPose *)allocator.zero_allocate(size, sizeof(eai_manipulator_msgs__msg__ArmTargetPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eai_manipulator_msgs__msg__ArmTargetPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eai_manipulator_msgs__msg__ArmTargetPose__fini(&data[i - 1]);
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
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__fini(eai_manipulator_msgs__msg__ArmTargetPose__Sequence * array)
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
      eai_manipulator_msgs__msg__ArmTargetPose__fini(&array->data[i]);
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

eai_manipulator_msgs__msg__ArmTargetPose__Sequence *
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__ArmTargetPose__Sequence * array = (eai_manipulator_msgs__msg__ArmTargetPose__Sequence *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__ArmTargetPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = eai_manipulator_msgs__msg__ArmTargetPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__destroy(eai_manipulator_msgs__msg__ArmTargetPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    eai_manipulator_msgs__msg__ArmTargetPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__are_equal(const eai_manipulator_msgs__msg__ArmTargetPose__Sequence * lhs, const eai_manipulator_msgs__msg__ArmTargetPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eai_manipulator_msgs__msg__ArmTargetPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eai_manipulator_msgs__msg__ArmTargetPose__Sequence__copy(
  const eai_manipulator_msgs__msg__ArmTargetPose__Sequence * input,
  eai_manipulator_msgs__msg__ArmTargetPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eai_manipulator_msgs__msg__ArmTargetPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    eai_manipulator_msgs__msg__ArmTargetPose * data =
      (eai_manipulator_msgs__msg__ArmTargetPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eai_manipulator_msgs__msg__ArmTargetPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          eai_manipulator_msgs__msg__ArmTargetPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eai_manipulator_msgs__msg__ArmTargetPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
