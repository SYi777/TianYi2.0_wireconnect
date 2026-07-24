# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sys_msgs:msg/Fault.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Fault(type):
    """Metaclass of message 'Fault'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'STATUS_CLEAR': 0,
        'STATUS_ACTIVE': 1,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sys_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sys_msgs.msg.Fault')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fault
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fault
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fault
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fault
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fault

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STATUS_CLEAR': cls.__constants['STATUS_CLEAR'],
            'STATUS_ACTIVE': cls.__constants['STATUS_ACTIVE'],
        }

    @property
    def STATUS_CLEAR(self):
        """Message constant 'STATUS_CLEAR'."""
        return Metaclass_Fault.__constants['STATUS_CLEAR']

    @property
    def STATUS_ACTIVE(self):
        """Message constant 'STATUS_ACTIVE'."""
        return Metaclass_Fault.__constants['STATUS_ACTIVE']


class Fault(metaclass=Metaclass_Fault):
    """
    Message class 'Fault'.

    Constants:
      STATUS_CLEAR
      STATUS_ACTIVE
    """

    __slots__ = [
        '_time_stamp_ms',
        '_code',
        '_status',
    ]

    _fields_and_field_types = {
        'time_stamp_ms': 'uint64',
        'code': 'uint64',
        'status': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.time_stamp_ms = kwargs.get('time_stamp_ms', int())
        self.code = kwargs.get('code', int())
        self.status = kwargs.get('status', int())

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
        if self.time_stamp_ms != other.time_stamp_ms:
            return False
        if self.code != other.code:
            return False
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def time_stamp_ms(self):
        """Message field 'time_stamp_ms'."""
        return self._time_stamp_ms

    @time_stamp_ms.setter
    def time_stamp_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_stamp_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'time_stamp_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._time_stamp_ms = value

    @builtins.property
    def code(self):
        """Message field 'code'."""
        return self._code

    @code.setter
    def code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'code' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'code' field must be an unsigned integer in [0, 18446744073709551615]"
        self._code = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'status' field must be an unsigned integer in [0, 65535]"
        self._status = value
