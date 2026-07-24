# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:msg/SetVelLimit.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetVelLimit(type):
    """Metaclass of message 'SetVelLimit'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hric_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hric_msgs.msg.SetVelLimit')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__set_vel_limit
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__set_vel_limit
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__set_vel_limit
            cls._TYPE_SUPPORT = module.type_support_msg__msg__set_vel_limit
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__set_vel_limit

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetVelLimit(metaclass=Metaclass_SetVelLimit):
    """Message class 'SetVelLimit'."""

    __slots__ = [
        '_x_vel_limit_walk',
        '_x_vel_limit_run',
        '_x_vel_limit_halfwalk',
    ]

    _fields_and_field_types = {
        'x_vel_limit_walk': 'double',
        'x_vel_limit_run': 'double',
        'x_vel_limit_halfwalk': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_vel_limit_walk = kwargs.get('x_vel_limit_walk', float())
        self.x_vel_limit_run = kwargs.get('x_vel_limit_run', float())
        self.x_vel_limit_halfwalk = kwargs.get('x_vel_limit_halfwalk', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x_vel_limit_walk != other.x_vel_limit_walk:
            return False
        if self.x_vel_limit_run != other.x_vel_limit_run:
            return False
        if self.x_vel_limit_halfwalk != other.x_vel_limit_halfwalk:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_vel_limit_walk(self):
        """Message field 'x_vel_limit_walk'."""
        return self._x_vel_limit_walk

    @x_vel_limit_walk.setter
    def x_vel_limit_walk(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_vel_limit_walk' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_vel_limit_walk' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_vel_limit_walk = value

    @builtins.property
    def x_vel_limit_run(self):
        """Message field 'x_vel_limit_run'."""
        return self._x_vel_limit_run

    @x_vel_limit_run.setter
    def x_vel_limit_run(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_vel_limit_run' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_vel_limit_run' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_vel_limit_run = value

    @builtins.property
    def x_vel_limit_halfwalk(self):
        """Message field 'x_vel_limit_halfwalk'."""
        return self._x_vel_limit_halfwalk

    @x_vel_limit_halfwalk.setter
    def x_vel_limit_halfwalk(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_vel_limit_halfwalk' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_vel_limit_halfwalk' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_vel_limit_halfwalk = value
