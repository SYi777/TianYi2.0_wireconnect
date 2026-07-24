// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cm_msgs/msg/detail/pose_action_status__struct.h"
#include "cm_msgs/msg/detail/pose_action_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cm_msgs__msg__pose_action_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cm_msgs.msg._pose_action_status.PoseActionStatus", full_classname_dest, 48) == 0);
  }
  cm_msgs__msg__PoseActionStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // resp_frame_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "resp_frame_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->resp_frame_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // hand_move_success
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_move_success");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->hand_move_success = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // head_move_success
    PyObject * field = PyObject_GetAttrString(_pymsg, "head_move_success");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->head_move_success = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gripper_move_success
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_move_success");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_move_success = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cm_msgs__msg__pose_action_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PoseActionStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cm_msgs.msg._pose_action_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PoseActionStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cm_msgs__msg__PoseActionStatus * ros_message = (cm_msgs__msg__PoseActionStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // resp_frame_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->resp_frame_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "resp_frame_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hand_move_success
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->hand_move_success);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hand_move_success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // head_move_success
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->head_move_success);
    {
      int rc = PyObject_SetAttrString(_pymessage, "head_move_success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_move_success
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_move_success);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_move_success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
