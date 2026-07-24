// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice
#include "cm_msgs/msg/detail/hand_pose_req__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `left_hand_pose_req`
// Member `right_hand_pose_req`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `rpy`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cm_msgs__msg__HandPoseReq__init(cm_msgs__msg__HandPoseReq * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cm_msgs__msg__HandPoseReq__fini(msg);
    return false;
  }
  // hand_move_enable
  // hand_side
  // hand_reset
  // left_hand_pose_req
  if (!geometry_msgs__msg__Pose__init(&msg->left_hand_pose_req)) {
    cm_msgs__msg__HandPoseReq__fini(msg);
    return false;
  }
  // right_hand_pose_req
  if (!geometry_msgs__msg__Pose__init(&msg->right_hand_pose_req)) {
    cm_msgs__msg__HandPoseReq__fini(msg);
    return false;
  }
  // head_move_enable
  // rpy
  if (!rosidl_runtime_c__double__Sequence__init(&msg->rpy, 0)) {
    cm_msgs__msg__HandPoseReq__fini(msg);
    return false;
  }
  // gripper_move_enable
  // gripper_side
  // finger_status
  // little_finger
  // ring_finger
  // middle_finger
  // index_finger
  // thumb_bending
  // thumb_rotating
  return true;
}

void
cm_msgs__msg__HandPoseReq__fini(cm_msgs__msg__HandPoseReq * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // hand_move_enable
  // hand_side
  // hand_reset
  // left_hand_pose_req
  geometry_msgs__msg__Pose__fini(&msg->left_hand_pose_req);
  // right_hand_pose_req
  geometry_msgs__msg__Pose__fini(&msg->right_hand_pose_req);
  // head_move_enable
  // rpy
  rosidl_runtime_c__double__Sequence__fini(&msg->rpy);
  // gripper_move_enable
  // gripper_side
  // finger_status
  // little_finger
  // ring_finger
  // middle_finger
  // index_finger
  // thumb_bending
  // thumb_rotating
}

bool
cm_msgs__msg__HandPoseReq__are_equal(const cm_msgs__msg__HandPoseReq * lhs, const cm_msgs__msg__HandPoseReq * rhs)
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
  // hand_move_enable
  if (lhs->hand_move_enable != rhs->hand_move_enable) {
    return false;
  }
  // hand_side
  if (lhs->hand_side != rhs->hand_side) {
    return false;
  }
  // hand_reset
  if (lhs->hand_reset != rhs->hand_reset) {
    return false;
  }
  // left_hand_pose_req
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->left_hand_pose_req), &(rhs->left_hand_pose_req)))
  {
    return false;
  }
  // right_hand_pose_req
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->right_hand_pose_req), &(rhs->right_hand_pose_req)))
  {
    return false;
  }
  // head_move_enable
  if (lhs->head_move_enable != rhs->head_move_enable) {
    return false;
  }
  // rpy
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->rpy), &(rhs->rpy)))
  {
    return false;
  }
  // gripper_move_enable
  if (lhs->gripper_move_enable != rhs->gripper_move_enable) {
    return false;
  }
  // gripper_side
  if (lhs->gripper_side != rhs->gripper_side) {
    return false;
  }
  // finger_status
  if (lhs->finger_status != rhs->finger_status) {
    return false;
  }
  // little_finger
  if (lhs->little_finger != rhs->little_finger) {
    return false;
  }
  // ring_finger
  if (lhs->ring_finger != rhs->ring_finger) {
    return false;
  }
  // middle_finger
  if (lhs->middle_finger != rhs->middle_finger) {
    return false;
  }
  // index_finger
  if (lhs->index_finger != rhs->index_finger) {
    return false;
  }
  // thumb_bending
  if (lhs->thumb_bending != rhs->thumb_bending) {
    return false;
  }
  // thumb_rotating
  if (lhs->thumb_rotating != rhs->thumb_rotating) {
    return false;
  }
  return true;
}

bool
cm_msgs__msg__HandPoseReq__copy(
  const cm_msgs__msg__HandPoseReq * input,
  cm_msgs__msg__HandPoseReq * output)
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
  // hand_move_enable
  output->hand_move_enable = input->hand_move_enable;
  // hand_side
  output->hand_side = input->hand_side;
  // hand_reset
  output->hand_reset = input->hand_reset;
  // left_hand_pose_req
  if (!geometry_msgs__msg__Pose__copy(
      &(input->left_hand_pose_req), &(output->left_hand_pose_req)))
  {
    return false;
  }
  // right_hand_pose_req
  if (!geometry_msgs__msg__Pose__copy(
      &(input->right_hand_pose_req), &(output->right_hand_pose_req)))
  {
    return false;
  }
  // head_move_enable
  output->head_move_enable = input->head_move_enable;
  // rpy
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->rpy), &(output->rpy)))
  {
    return false;
  }
  // gripper_move_enable
  output->gripper_move_enable = input->gripper_move_enable;
  // gripper_side
  output->gripper_side = input->gripper_side;
  // finger_status
  output->finger_status = input->finger_status;
  // little_finger
  output->little_finger = input->little_finger;
  // ring_finger
  output->ring_finger = input->ring_finger;
  // middle_finger
  output->middle_finger = input->middle_finger;
  // index_finger
  output->index_finger = input->index_finger;
  // thumb_bending
  output->thumb_bending = input->thumb_bending;
  // thumb_rotating
  output->thumb_rotating = input->thumb_rotating;
  return true;
}

cm_msgs__msg__HandPoseReq *
cm_msgs__msg__HandPoseReq__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__HandPoseReq * msg = (cm_msgs__msg__HandPoseReq *)allocator.allocate(sizeof(cm_msgs__msg__HandPoseReq), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cm_msgs__msg__HandPoseReq));
  bool success = cm_msgs__msg__HandPoseReq__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cm_msgs__msg__HandPoseReq__destroy(cm_msgs__msg__HandPoseReq * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cm_msgs__msg__HandPoseReq__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cm_msgs__msg__HandPoseReq__Sequence__init(cm_msgs__msg__HandPoseReq__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__HandPoseReq * data = NULL;

  if (size) {
    data = (cm_msgs__msg__HandPoseReq *)allocator.zero_allocate(size, sizeof(cm_msgs__msg__HandPoseReq), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cm_msgs__msg__HandPoseReq__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cm_msgs__msg__HandPoseReq__fini(&data[i - 1]);
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
cm_msgs__msg__HandPoseReq__Sequence__fini(cm_msgs__msg__HandPoseReq__Sequence * array)
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
      cm_msgs__msg__HandPoseReq__fini(&array->data[i]);
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

cm_msgs__msg__HandPoseReq__Sequence *
cm_msgs__msg__HandPoseReq__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cm_msgs__msg__HandPoseReq__Sequence * array = (cm_msgs__msg__HandPoseReq__Sequence *)allocator.allocate(sizeof(cm_msgs__msg__HandPoseReq__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cm_msgs__msg__HandPoseReq__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cm_msgs__msg__HandPoseReq__Sequence__destroy(cm_msgs__msg__HandPoseReq__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cm_msgs__msg__HandPoseReq__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cm_msgs__msg__HandPoseReq__Sequence__are_equal(const cm_msgs__msg__HandPoseReq__Sequence * lhs, const cm_msgs__msg__HandPoseReq__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cm_msgs__msg__HandPoseReq__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cm_msgs__msg__HandPoseReq__Sequence__copy(
  const cm_msgs__msg__HandPoseReq__Sequence * input,
  cm_msgs__msg__HandPoseReq__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cm_msgs__msg__HandPoseReq);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cm_msgs__msg__HandPoseReq * data =
      (cm_msgs__msg__HandPoseReq *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cm_msgs__msg__HandPoseReq__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cm_msgs__msg__HandPoseReq__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cm_msgs__msg__HandPoseReq__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
