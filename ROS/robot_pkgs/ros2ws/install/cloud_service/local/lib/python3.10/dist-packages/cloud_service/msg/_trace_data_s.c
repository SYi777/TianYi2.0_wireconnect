// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cloud_service:msg/TraceData.idl
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
#include "cloud_service/msg/detail/trace_data__struct.h"
#include "cloud_service/msg/detail/trace_data__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cloud_service__msg__trace_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("cloud_service.msg._trace_data.TraceData", full_classname_dest, 39) == 0);
  }
  cloud_service__msg__TraceData * ros_message = _ros_message;
  {  // key
    PyObject * field = PyObject_GetAttrString(_pymsg, "key");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->key, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // data_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "data_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->data_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // int_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "int_val");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->int_val = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // str_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "str_val");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->str_val, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // bool_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "bool_val");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->bool_val = (Py_True == field);
    Py_DECREF(field);
  }
  {  // double_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "double_val");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->double_val = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cloud_service__msg__trace_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TraceData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cloud_service.msg._trace_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TraceData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cloud_service__msg__TraceData * ros_message = (cloud_service__msg__TraceData *)raw_ros_message;
  {  // key
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->key.data,
      strlen(ros_message->key.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "key", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->data_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "data_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // int_val
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->int_val);
    {
      int rc = PyObject_SetAttrString(_pymessage, "int_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // str_val
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->str_val.data,
      strlen(ros_message->str_val.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "str_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bool_val
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->bool_val ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bool_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // double_val
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->double_val);
    {
      int rc = PyObject_SetAttrString(_pymessage, "double_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
