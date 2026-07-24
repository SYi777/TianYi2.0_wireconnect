# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cm_msgs:srv/CommonRespRos2.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'data'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CommonRespRos2_Request(type):
    """Metaclass of message 'CommonRespRos2_Request'."""

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
            module = import_type_support('cm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cm_msgs.srv.CommonRespRos2_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__common_resp_ros2__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__common_resp_ros2__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__common_resp_ros2__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__common_resp_ros2__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__common_resp_ros2__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CommonRespRos2_Request(metaclass=Metaclass_CommonRespRos2_Request):
    """Message class 'CommonRespRos2_Request'."""

    __slots__ = [
        '_msg_id',
        '_json_data',
        '_data',
    ]

    _fields_and_field_types = {
        'msg_id': 'string',
        'json_data': 'string',
        'data': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.msg_id = kwargs.get('msg_id', str())
        self.json_data = kwargs.get('json_data', str())
        self.data = array.array('B', kwargs.get('data', []))

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
        if self.msg_id != other.msg_id:
            return False
        if self.json_data != other.json_data:
            return False
        if self.data != other.data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def msg_id(self):
        """Message field 'msg_id'."""
        return self._msg_id

    @msg_id.setter
    def msg_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'msg_id' field must be of type 'str'"
        self._msg_id = value

    @builtins.property
    def json_data(self):
        """Message field 'json_data'."""
        return self._json_data

    @json_data.setter
    def json_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'json_data' field must be of type 'str'"
        self._json_data = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'data' array.array() must have the type code of 'B'"
            self._data = value
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data = array.array('B', value)


# Import statements for member types

# Member 'data'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CommonRespRos2_Response(type):
    """Metaclass of message 'CommonRespRos2_Response'."""

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
            module = import_type_support('cm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cm_msgs.srv.CommonRespRos2_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__common_resp_ros2__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__common_resp_ros2__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__common_resp_ros2__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__common_resp_ros2__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__common_resp_ros2__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CommonRespRos2_Response(metaclass=Metaclass_CommonRespRos2_Response):
    """Message class 'CommonRespRos2_Response'."""

    __slots__ = [
        '_result',
        '_msg_id',
        '_json_data',
        '_data',
    ]

    _fields_and_field_types = {
        'result': 'boolean',
        'msg_id': 'string',
        'json_data': 'string',
        'data': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', bool())
        self.msg_id = kwargs.get('msg_id', str())
        self.json_data = kwargs.get('json_data', str())
        self.data = array.array('B', kwargs.get('data', []))

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
        if self.result != other.result:
            return False
        if self.msg_id != other.msg_id:
            return False
        if self.json_data != other.json_data:
            return False
        if self.data != other.data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'result' field must be of type 'bool'"
        self._result = value

    @builtins.property
    def msg_id(self):
        """Message field 'msg_id'."""
        return self._msg_id

    @msg_id.setter
    def msg_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'msg_id' field must be of type 'str'"
        self._msg_id = value

    @builtins.property
    def json_data(self):
        """Message field 'json_data'."""
        return self._json_data

    @json_data.setter
    def json_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'json_data' field must be of type 'str'"
        self._json_data = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'data' array.array() must have the type code of 'B'"
            self._data = value
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data = array.array('B', value)


class Metaclass_CommonRespRos2(type):
    """Metaclass of service 'CommonRespRos2'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cm_msgs.srv.CommonRespRos2')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__common_resp_ros2

            from cm_msgs.srv import _common_resp_ros2
            if _common_resp_ros2.Metaclass_CommonRespRos2_Request._TYPE_SUPPORT is None:
                _common_resp_ros2.Metaclass_CommonRespRos2_Request.__import_type_support__()
            if _common_resp_ros2.Metaclass_CommonRespRos2_Response._TYPE_SUPPORT is None:
                _common_resp_ros2.Metaclass_CommonRespRos2_Response.__import_type_support__()


class CommonRespRos2(metaclass=Metaclass_CommonRespRos2):
    from cm_msgs.srv._common_resp_ros2 import CommonRespRos2_Request as Request
    from cm_msgs.srv._common_resp_ros2 import CommonRespRos2_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
