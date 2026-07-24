# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cloud_service:msg/TraceDatas.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TraceDatas(type):
    """Metaclass of message 'TraceDatas'."""

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
            module = import_type_support('cloud_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cloud_service.msg.TraceDatas')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__trace_datas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__trace_datas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__trace_datas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__trace_datas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__trace_datas

            from cloud_service.msg import TraceData
            if TraceData.__class__._TYPE_SUPPORT is None:
                TraceData.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TraceDatas(metaclass=Metaclass_TraceDatas):
    """Message class 'TraceDatas'."""

    __slots__ = [
        '_model',
        '_event_name',
        '_trace_array',
    ]

    _fields_and_field_types = {
        'model': 'string',
        'event_name': 'string',
        'trace_array': 'sequence<cloud_service/TraceData>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['cloud_service', 'msg'], 'TraceData')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.model = kwargs.get('model', str())
        self.event_name = kwargs.get('event_name', str())
        self.trace_array = kwargs.get('trace_array', [])

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
        if self.model != other.model:
            return False
        if self.event_name != other.event_name:
            return False
        if self.trace_array != other.trace_array:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def model(self):
        """Message field 'model'."""
        return self._model

    @model.setter
    def model(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model' field must be of type 'str'"
        self._model = value

    @builtins.property
    def event_name(self):
        """Message field 'event_name'."""
        return self._event_name

    @event_name.setter
    def event_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'event_name' field must be of type 'str'"
        self._event_name = value

    @builtins.property
    def trace_array(self):
        """Message field 'trace_array'."""
        return self._trace_array

    @trace_array.setter
    def trace_array(self, value):
        if __debug__:
            from cloud_service.msg import TraceData
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, TraceData) for v in value) and
                 True), \
                "The 'trace_array' field must be a set or sequence and each value of type 'TraceData'"
        self._trace_array = value
