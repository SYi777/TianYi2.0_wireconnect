// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
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
#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__struct.h"
#include "eai_manipulator_msgs/msg/detail/dual_arm_target_pose__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool eai_manipulator_msgs__msg__dual_arm_target_pose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("eai_manipulator_msgs.msg._dual_arm_target_pose.DualArmTargetPose", full_classname_dest, 64) == 0);
  }
  eai_manipulator_msgs__msg__DualArmTargetPose * ros_message = _ros_message;
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
  {  // target_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_l");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->target_l)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // from_frame_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "from_frame_l");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->from_frame_l, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // to_frame_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "to_frame_l");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->to_frame_l, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // offset_x_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_x_l");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_x_l = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // offset_y_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_y_l");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_y_l = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // offset_z_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_z_l");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_z_l = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_r");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->target_r)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // from_frame_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "from_frame_r");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->from_frame_r, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // to_frame_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "to_frame_r");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->to_frame_r, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // offset_x_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_x_r");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_x_r = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // offset_y_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_y_r");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_y_r = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // offset_z_r
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_z_r");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_z_r = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_dual_arm_syn
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_dual_arm_syn");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_dual_arm_syn = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * eai_manipulator_msgs__msg__dual_arm_target_pose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DualArmTargetPose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("eai_manipulator_msgs.msg._dual_arm_target_pose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DualArmTargetPose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  eai_manipulator_msgs__msg__DualArmTargetPose * ros_message = (eai_manipulator_msgs__msg__DualArmTargetPose *)raw_ros_message;
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
  {  // target_l
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->target_l);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // from_frame_l
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->from_frame_l.data,
      strlen(ros_message->from_frame_l.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "from_frame_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // to_frame_l
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->to_frame_l.data,
      strlen(ros_message->to_frame_l.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "to_frame_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_x_l
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_x_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_x_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_y_l
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_y_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_y_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_z_l
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_z_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_z_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_r
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->target_r);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // from_frame_r
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->from_frame_r.data,
      strlen(ros_message->from_frame_r.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "from_frame_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // to_frame_r
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->to_frame_r.data,
      strlen(ros_message->to_frame_r.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "to_frame_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_x_r
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_x_r);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_x_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_y_r
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_y_r);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_y_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_z_r
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_z_r);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_z_r", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_dual_arm_syn
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_dual_arm_syn ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_dual_arm_syn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
