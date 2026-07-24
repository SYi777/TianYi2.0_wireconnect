# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cloud_service:msg/TraceData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TraceData(type):
    """Metaclass of message 'TraceData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TYPE_INT': 0,
        'TYPE_STR': 1,
        'TYPE_BOOL': 2,
        'TYPE_DOUBLE': 3,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cloud_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cloud_service.msg.TraceData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__trace_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__trace_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__trace_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__trace_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__trace_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TYPE_INT': cls.__constants['TYPE_INT'],
            'TYPE_STR': cls.__constants['TYPE_STR'],
            'TYPE_BOOL': cls.__constants['TYPE_BOOL'],
            'TYPE_DOUBLE': cls.__constants['TYPE_DOUBLE'],
        }

    @property
    def TYPE_INT(self):
        """Message constant 'TYPE_INT'."""
        return Metaclass_TraceData.__constants['TYPE_INT']

    @property
    def TYPE_STR(self):
        """Message constant 'TYPE_STR'."""
        return Metaclass_TraceData.__constants['TYPE_STR']

    @property
    def TYPE_BOOL(self):
        """Message constant 'TYPE_BOOL'."""
        return Metaclass_TraceData.__constants['TYPE_BOOL']

    @property
    def TYPE_DOUBLE(self):
        """Message constant 'TYPE_DOUBLE'."""
        return Metaclass_TraceData.__constants['TYPE_DOUBLE']


class TraceData(metaclass=Metaclass_TraceData):
    """
    Message class 'TraceData'.

    Constants:
      TYPE_INT
      TYPE_STR
      TYPE_BOOL
      TYPE_DOUBLE
    """

    __slots__ = [
        '_key',
        '_data_type',
        '_int_val',
        '_str_val',
        '_bool_val',
        '_double_val',
    ]

    _fields_and_field_types = {
        'key': 'string',
        'data_type': 'uint8',
        'int_val': 'int32',
        'str_val': 'string',
        'bool_val': 'boolean',
        'double_val': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.key = kwargs.get('key', str())
        self.data_type = kwargs.get('data_type', int())
        self.int_val = kwargs.get('int_val', int())
        self.str_val = kwargs.get('str_val', str())
        self.bool_val = kwargs.get('bool_val', bool())
        self.double_val = kwargs.get('double_val', float())

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
        if self.key != other.key:
            return False
        if self.data_type != other.data_type:
            return False
        if self.int_val != other.int_val:
            return False
        if self.str_val != other.str_val:
            return False
        if self.bool_val != other.bool_val:
            return False
        if self.double_val != other.double_val:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def key(self):
        """Message field 'key'."""
        return self._key

    @key.setter
    def key(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'key' field must be of type 'str'"
        self._key = value

    @builtins.property
    def data_type(self):
        """Message field 'data_type'."""
        return self._data_type

    @data_type.setter
    def data_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'data_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'data_type' field must be an unsigned integer in [0, 255]"
        self._data_type = value

    @builtins.property
    def int_val(self):
        """Message field 'int_val'."""
        return self._int_val

    @int_val.setter
    def int_val(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'int_val' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'int_val' field must be an integer in [-2147483648, 2147483647]"
        self._int_val = value

    @builtins.property
    def str_val(self):
        """Message field 'str_val'."""
        return self._str_val

    @str_val.setter
    def str_val(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'str_val' field must be of type 'str'"
        self._str_val = value

    @builtins.property
    def bool_val(self):
        """Message field 'bool_val'."""
        return self._bool_val

    @bool_val.setter
    def bool_val(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'bool_val' field must be of type 'bool'"
        self._bool_val = value

    @builtins.property
    def double_val(self):
        """Message field 'double_val'."""
        return self._double_val

    @double_val.setter
    def double_val(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'double_val' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'double_val' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._double_val = value
