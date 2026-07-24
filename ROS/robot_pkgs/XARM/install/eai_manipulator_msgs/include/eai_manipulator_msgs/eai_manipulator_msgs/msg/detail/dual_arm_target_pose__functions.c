// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
// generated code does not contain a copyright notice
#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `target_l`
// Member `target_r`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `from_frame_l`
// Member `to_frame_l`
// Member `from_frame_r`
// Member `to_frame_r`
#include "rosidl_runtime_c/string_functions.h"

bool
eai_manipulator_msgs__msg__DualArmTargetPose__init(eai_manipulator_msgs__msg__DualArmTargetPose * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // target_l
  if (!geometry_msgs__msg__Pose__init(&msg->target_l)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // from_frame_l
  if (!rosidl_runtime_c__String__init(&msg->from_frame_l)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // to_frame_l
  if (!rosidl_runtime_c__String__init(&msg->to_frame_l)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // offset_x_l
  // offset_y_l
  // offset_z_l
  // target_r
  if (!geometry_msgs__msg__Pose__init(&msg->target_r)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // from_frame_r
  if (!rosidl_runtime_c__String__init(&msg->from_frame_r)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // to_frame_r
  if (!rosidl_runtime_c__String__init(&msg->to_frame_r)) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
    return false;
  }
  // offset_x_r
  // offset_y_r
  // offset_z_r
  // is_dual_arm_syn
  return true;
}

void
eai_manipulator_msgs__msg__DualArmTargetPose__fini(eai_manipulator_msgs__msg__DualArmTargetPose * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // target_l
  geometry_msgs__msg__Pose__fini(&msg->target_l);
  // from_frame_l
  rosidl_runtime_c__String__fini(&msg->from_frame_l);
  // to_frame_l
  rosidl_runtime_c__String__fini(&msg->to_frame_l);
  // offset_x_l
  // offset_y_l
  // offset_z_l
  // target_r
  geometry_msgs__msg__Pose__fini(&msg->target_r);
  // from_frame_r
  rosidl_runtime_c__String__fini(&msg->from_frame_r);
  // to_frame_r
  rosidl_runtime_c__String__fini(&msg->to_frame_r);
  // offset_x_r
  // offset_y_r
  // offset_z_r
  // is_dual_arm_syn
}

bool
eai_manipulator_msgs__msg__DualArmTargetPose__are_equal(const eai_manipulator_msgs__msg__DualArmTargetPose * lhs, const eai_manipulator_msgs__msg__DualArmTargetPose * rhs)
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
  // target_l
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target_l), &(rhs->target_l)))
  {
    return false;
  }
  // from_frame_l
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->from_frame_l), &(rhs->from_frame_l)))
  {
    return false;
  }
  // to_frame_l
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to_frame_l), &(rhs->to_frame_l)))
  {
    return false;
  }
  // offset_x_l
  if (lhs->offset_x_l != rhs->offset_x_l) {
    return false;
  }
  // offset_y_l
  if (lhs->offset_y_l != rhs->offset_y_l) {
    return false;
  }
  // offset_z_l
  if (lhs->offset_z_l != rhs->offset_z_l) {
    return false;
  }
  // target_r
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target_r), &(rhs->target_r)))
  {
    return false;
  }
  // from_frame_r
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->from_frame_r), &(rhs->from_frame_r)))
  {
    return false;
  }
  // to_frame_r
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to_frame_r), &(rhs->to_frame_r)))
  {
    return false;
  }
  // offset_x_r
  if (lhs->offset_x_r != rhs->offset_x_r) {
    return false;
  }
  // offset_y_r
  if (lhs->offset_y_r != rhs->offset_y_r) {
    return false;
  }
  // offset_z_r
  if (lhs->offset_z_r != rhs->offset_z_r) {
    return false;
  }
  // is_dual_arm_syn
  if (lhs->is_dual_arm_syn != rhs->is_dual_arm_syn) {
    return false;
  }
  return true;
}

bool
eai_manipulator_msgs__msg__DualArmTargetPose__copy(
  const eai_manipulator_msgs__msg__DualArmTargetPose * input,
  eai_manipulator_msgs__msg__DualArmTargetPose * output)
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
  // target_l
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target_l), &(output->target_l)))
  {
    return false;
  }
  // from_frame_l
  if (!rosidl_runtime_c__String__copy(
      &(input->from_frame_l), &(output->from_frame_l)))
  {
    return false;
  }
  // to_frame_l
  if (!rosidl_runtime_c__String__copy(
      &(input->to_frame_l), &(output->to_frame_l)))
  {
    return false;
  }
  // offset_x_l
  output->offset_x_l = input->offset_x_l;
  // offset_y_l
  output->offset_y_l = input->offset_y_l;
  // offset_z_l
  output->offset_z_l = input->offset_z_l;
  // target_r
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target_r), &(output->target_r)))
  {
    return false;
  }
  // from_frame_r
  if (!rosidl_runtime_c__String__copy(
      &(input->from_frame_r), &(output->from_frame_r)))
  {
    return false;
  }
  // to_frame_r
  if (!rosidl_runtime_c__String__copy(
      &(input->to_frame_r), &(output->to_frame_r)))
  {
    return false;
  }
  // offset_x_r
  output->offset_x_r = input->offset_x_r;
  // offset_y_r
  output->offset_y_r = input->offset_y_r;
  // offset_z_r
  output->offset_z_r = input->offset_z_r;
  // is_dual_arm_syn
  output->is_dual_arm_syn = input->is_dual_arm_syn;
  return true;
}

eai_manipulator_msgs__msg__DualArmTargetPose *
eai_manipulator_msgs__msg__DualArmTargetPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__DualArmTargetPose * msg = (eai_manipulator_msgs__msg__DualArmTargetPose *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__DualArmTargetPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eai_manipulator_msgs__msg__DualArmTargetPose));
  bool success = eai_manipulator_msgs__msg__DualArmTargetPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
eai_manipulator_msgs__msg__DualArmTargetPose__destroy(eai_manipulator_msgs__msg__DualArmTargetPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    eai_manipulator_msgs__msg__DualArmTargetPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__init(eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__DualArmTargetPose * data = NULL;

  if (size) {
    data = (eai_manipulator_msgs__msg__DualArmTargetPose *)allocator.zero_allocate(size, sizeof(eai_manipulator_msgs__msg__DualArmTargetPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eai_manipulator_msgs__msg__DualArmTargetPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eai_manipulator_msgs__msg__DualArmTargetPose__fini(&data[i - 1]);
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
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__fini(eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * array)
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
      eai_manipulator_msgs__msg__DualArmTargetPose__fini(&array->data[i]);
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

eai_manipulator_msgs__msg__DualArmTargetPose__Sequence *
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * array = (eai_manipulator_msgs__msg__DualArmTargetPose__Sequence *)allocator.allocate(sizeof(eai_manipulator_msgs__msg__DualArmTargetPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__destroy(eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__are_equal(const eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * lhs, const eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eai_manipulator_msgs__msg__DualArmTargetPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eai_manipulator_msgs__msg__DualArmTargetPose__Sequence__copy(
  const eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * input,
  eai_manipulator_msgs__msg__DualArmTargetPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eai_manipulator_msgs__msg__DualArmTargetPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    eai_manipulator_msgs__msg__DualArmTargetPose * data =
      (eai_manipulator_msgs__msg__DualArmTargetPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eai_manipulator_msgs__msg__DualArmTargetPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          eai_manipulator_msgs__msg__DualArmTargetPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eai_manipulator_msgs__msg__DualArmTargetPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
