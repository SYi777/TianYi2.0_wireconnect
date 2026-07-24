// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cm_msgs:msg/HandPoseReq.idl
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
#include "cm_msgs/msg/detail/hand_pose_req__struct.h"
#include "cm_msgs/msg/detail/hand_pose_req__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

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
bool cm_msgs__msg__hand_pose_req__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
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
    assert(strncmp("cm_msgs.msg._hand_pose_req.HandPoseReq", full_classname_dest, 38) == 0);
  }
  cm_msgs__msg__HandPoseReq * ros_message = _ros_message;
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
  {  // hand_move_enable
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_move_enable");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->hand_move_enable = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // hand_side
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_side");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->hand_side = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // hand_reset
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_reset");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->hand_reset = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // left_hand_pose_req
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_hand_pose_req");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->left_hand_pose_req)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // right_hand_pose_req
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_hand_pose_req");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->right_hand_pose_req)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // head_move_enable
    PyObject * field = PyObject_GetAttrString(_pymsg, "head_move_enable");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->head_move_enable = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rpy
    PyObject * field = PyObject_GetAttrString(_pymsg, "rpy");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(double);
      if (!rosidl_runtime_c__double__Sequence__init(&(ros_message->rpy), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create double__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      double * dest = ros_message->rpy.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'rpy'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__double__Sequence__init(&(ros_message->rpy), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create double__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      double * dest = ros_message->rpy.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyFloat_Check(item));
        double tmp = PyFloat_AS_DOUBLE(item);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // gripper_move_enable
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_move_enable");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_move_enable = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gripper_side
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_side");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_side = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // finger_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "finger_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->finger_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // little_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "little_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->little_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ring_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "ring_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ring_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // middle_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "middle_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->middle_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // index_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "index_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->index_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // thumb_bending
    PyObject * field = PyObject_GetAttrString(_pymsg, "thumb_bending");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->thumb_bending = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // thumb_rotating
    PyObject * field = PyObject_GetAttrString(_pymsg, "thumb_rotating");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->thumb_rotating = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cm_msgs__msg__hand_pose_req__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HandPoseReq */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cm_msgs.msg._hand_pose_req");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HandPoseReq");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cm_msgs__msg__HandPoseReq * ros_message = (cm_msgs__msg__HandPoseReq *)raw_ros_message;
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
  {  // hand_move_enable
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->hand_move_enable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hand_move_enable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hand_side
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->hand_side);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hand_side", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hand_reset
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->hand_reset);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hand_reset", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_hand_pose_req
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->left_hand_pose_req);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_hand_pose_req", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_hand_pose_req
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->right_hand_pose_req);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_hand_pose_req", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // head_move_enable
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->head_move_enable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "head_move_enable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rpy
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "rpy");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "array.array") == 0);
    // ensure that itemsize matches the sizeof of the ROS message field
    PyObject * itemsize_attr = PyObject_GetAttrString(field, "itemsize");
    assert(itemsize_attr != NULL);
    size_t itemsize = PyLong_AsSize_t(itemsize_attr);
    Py_DECREF(itemsize_attr);
    if (itemsize != sizeof(double)) {
      PyErr_SetString(PyExc_RuntimeError, "itemsize doesn't match expectation");
      Py_DECREF(field);
      return NULL;
    }
    // clear the array, poor approach to remove potential default values
    Py_ssize_t length = PyObject_Length(field);
    if (-1 == length) {
      Py_DECREF(field);
      return NULL;
    }
    if (length > 0) {
      PyObject * pop = PyObject_GetAttrString(field, "pop");
      assert(pop != NULL);
      for (Py_ssize_t i = 0; i < length; ++i) {
        PyObject * ret = PyObject_CallFunctionObjArgs(pop, NULL);
        if (!ret) {
          Py_DECREF(pop);
          Py_DECREF(field);
          return NULL;
        }
        Py_DECREF(ret);
      }
      Py_DECREF(pop);
    }
    if (ros_message->rpy.size > 0) {
      // populating the array.array using the frombytes method
      PyObject * frombytes = PyObject_GetAttrString(field, "frombytes");
      assert(frombytes != NULL);
      double * src = &(ros_message->rpy.data[0]);
      PyObject * data = PyBytes_FromStringAndSize((const char *)src, ros_message->rpy.size * sizeof(double));
      assert(data != NULL);
      PyObject * ret = PyObject_CallFunctionObjArgs(frombytes, data, NULL);
      Py_DECREF(data);
      Py_DECREF(frombytes);
      if (!ret) {
        Py_DECREF(field);
        return NULL;
      }
      Py_DECREF(ret);
    }
    Py_DECREF(field);
  }
  {  // gripper_move_enable
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_move_enable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_move_enable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_side
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_side);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_side", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // finger_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->finger_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "finger_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // little_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->little_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "little_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ring_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ring_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ring_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // middle_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->middle_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "middle_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // index_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->index_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "index_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thumb_bending
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->thumb_bending);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thumb_bending", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thumb_rotating
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->thumb_rotating);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thumb_rotating", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
