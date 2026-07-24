// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hric_msgs:msg/ActionStatus.idl
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
#include "hric_msgs/msg/detail/action_status__struct.h"
#include "hric_msgs/msg/detail/action_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hric_msgs__msg__action_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
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
    assert(strncmp("hric_msgs.msg._action_status.ActionStatus", full_classname_dest, 41) == 0);
  }
  hric_msgs__msg__ActionStatus * ros_message = _ros_message;
  {  // motion_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "motion_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->motion_number = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_motion
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_motion");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_motion = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hric_msgs__msg__action_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ActionStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hric_msgs.msg._action_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ActionStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hric_msgs__msg__ActionStatus * ros_message = (hric_msgs__msg__ActionStatus *)raw_ros_message;
  {  // motion_number
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->motion_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motion_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_motion
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_motion ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_motion", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
