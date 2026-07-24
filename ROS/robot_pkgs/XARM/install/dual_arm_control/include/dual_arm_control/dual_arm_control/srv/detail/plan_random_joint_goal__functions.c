// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice
#include "dual_arm_control/srv/detail/plan_random_joint_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `group_name`
#include "rosidl_runtime_c/string_functions.h"

bool
dual_arm_control__srv__PlanRandomJointGoal_Request__init(dual_arm_control__srv__PlanRandomJointGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__init(&msg->group_name)) {
    dual_arm_control__srv__PlanRandomJointGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Request__fini(dual_arm_control__srv__PlanRandomJointGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // group_name
  rosidl_runtime_c__String__fini(&msg->group_name);
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Request__are_equal(const dual_arm_control__srv__PlanRandomJointGoal_Request * lhs, const dual_arm_control__srv__PlanRandomJointGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->group_name), &(rhs->group_name)))
  {
    return false;
  }
  return true;
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Request__copy(
  const dual_arm_control__srv__PlanRandomJointGoal_Request * input,
  dual_arm_control__srv__PlanRandomJointGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__copy(
      &(input->group_name), &(output->group_name)))
  {
    return false;
  }
  return true;
}

dual_arm_control__srv__PlanRandomJointGoal_Request *
dual_arm_control__srv__PlanRandomJointGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Request * msg = (dual_arm_control__srv__PlanRandomJointGoal_Request *)allocator.allocate(sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request));
  bool success = dual_arm_control__srv__PlanRandomJointGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Request__destroy(dual_arm_control__srv__PlanRandomJointGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dual_arm_control__srv__PlanRandomJointGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__init(dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Request * data = NULL;

  if (size) {
    data = (dual_arm_control__srv__PlanRandomJointGoal_Request *)allocator.zero_allocate(size, sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dual_arm_control__srv__PlanRandomJointGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dual_arm_control__srv__PlanRandomJointGoal_Request__fini(&data[i - 1]);
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
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__fini(dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * array)
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
      dual_arm_control__srv__PlanRandomJointGoal_Request__fini(&array->data[i]);
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

dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence *
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * array = (dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence *)allocator.allocate(sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__destroy(dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__are_equal(const dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * lhs, const dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dual_arm_control__srv__PlanRandomJointGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence__copy(
  const dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * input,
  dual_arm_control__srv__PlanRandomJointGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dual_arm_control__srv__PlanRandomJointGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dual_arm_control__srv__PlanRandomJointGoal_Request * data =
      (dual_arm_control__srv__PlanRandomJointGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dual_arm_control__srv__PlanRandomJointGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dual_arm_control__srv__PlanRandomJointGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dual_arm_control__srv__PlanRandomJointGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `joint_values`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
dual_arm_control__srv__PlanRandomJointGoal_Response__init(dual_arm_control__srv__PlanRandomJointGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // joint_values
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_values, 0)) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__fini(msg);
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__init(&msg->trajectory)) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__fini(msg);
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Response__fini(dual_arm_control__srv__PlanRandomJointGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // joint_values
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_values);
  // trajectory
  trajectory_msgs__msg__JointTrajectory__fini(&msg->trajectory);
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Response__are_equal(const dual_arm_control__srv__PlanRandomJointGoal_Response * lhs, const dual_arm_control__srv__PlanRandomJointGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // joint_values
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_values), &(rhs->joint_values)))
  {
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
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
dual_arm_control__srv__PlanRandomJointGoal_Response__copy(
  const dual_arm_control__srv__PlanRandomJointGoal_Response * input,
  dual_arm_control__srv__PlanRandomJointGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // joint_values
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_values), &(output->joint_values)))
  {
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

dual_arm_control__srv__PlanRandomJointGoal_Response *
dual_arm_control__srv__PlanRandomJointGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Response * msg = (dual_arm_control__srv__PlanRandomJointGoal_Response *)allocator.allocate(sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response));
  bool success = dual_arm_control__srv__PlanRandomJointGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Response__destroy(dual_arm_control__srv__PlanRandomJointGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__init(dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Response * data = NULL;

  if (size) {
    data = (dual_arm_control__srv__PlanRandomJointGoal_Response *)allocator.zero_allocate(size, sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dual_arm_control__srv__PlanRandomJointGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dual_arm_control__srv__PlanRandomJointGoal_Response__fini(&data[i - 1]);
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
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__fini(dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * array)
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
      dual_arm_control__srv__PlanRandomJointGoal_Response__fini(&array->data[i]);
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

dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence *
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * array = (dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence *)allocator.allocate(sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__destroy(dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__are_equal(const dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * lhs, const dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dual_arm_control__srv__PlanRandomJointGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence__copy(
  const dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * input,
  dual_arm_control__srv__PlanRandomJointGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dual_arm_control__srv__PlanRandomJointGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dual_arm_control__srv__PlanRandomJointGoal_Response * data =
      (dual_arm_control__srv__PlanRandomJointGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dual_arm_control__srv__PlanRandomJointGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dual_arm_control__srv__PlanRandomJointGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dual_arm_control__srv__PlanRandomJointGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
