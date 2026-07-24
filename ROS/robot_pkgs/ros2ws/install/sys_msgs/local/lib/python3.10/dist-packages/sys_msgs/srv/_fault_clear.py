# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sys_msgs:srv/FaultClear.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'fault_array'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FaultClear_Request(type):
    """Metaclass of message 'FaultClear_Request'."""

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
            module = import_type_support('sys_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sys_msgs.srv.FaultClear_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__fault_clear__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__fault_clear__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__fault_clear__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__fault_clear__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__fault_clear__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FaultClear_Request(metaclass=Metaclass_FaultClear_Request):
    """Message class 'FaultClear_Request'."""

    __slots__ = [
        '_fault_array',
    ]

    _fields_and_field_types = {
        'fault_array': 'sequence<uint64>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint64')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.fault_array = array.array('Q', kwargs.get('fault_array', []))

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
        if self.fault_array != other.fault_array:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fault_array(self):
        """Message field 'fault_array'."""
        return self._fault_array

    @fault_array.setter
    def fault_array(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'Q', \
                "The 'fault_array' array.array() must have the type code of 'Q'"
            self._fault_array = value
            return
        if __debug__:
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 18446744073709551616 for val in value)), \
                "The 'fault_array' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 18446744073709551615]"
        self._fault_array = array.array('Q', value)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FaultClear_Response(type):
    """Metaclass of message 'FaultClear_Response'."""

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
            module = import_type_support('sys_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sys_msgs.srv.FaultClear_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__fault_clear__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__fault_clear__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__fault_clear__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__fault_clear__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__fault_clear__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FaultClear_Response(metaclass=Metaclass_FaultClear_Response):
    """Message class 'FaultClear_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_FaultClear(type):
    """Metaclass of service 'FaultClear'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sys_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sys_msgs.srv.FaultClear')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__fault_clear

            from sys_msgs.srv import _fault_clear
            if _fault_clear.Metaclass_FaultClear_Request._TYPE_SUPPORT is None:
                _fault_clear.Metaclass_FaultClear_Request.__import_type_support__()
            if _fault_clear.Metaclass_FaultClear_Response._TYPE_SUPPORT is None:
                _fault_clear.Metaclass_FaultClear_Response.__import_type_support__()


class FaultClear(metaclass=Metaclass_FaultClear):
    from sys_msgs.srv._fault_clear import FaultClear_Request as Request
    from sys_msgs.srv._fault_clear import FaultClear_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
