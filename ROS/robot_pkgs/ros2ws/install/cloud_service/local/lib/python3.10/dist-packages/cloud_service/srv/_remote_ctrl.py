# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cloud_service:srv/RemoteCtrl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RemoteCtrl_Request(type):
    """Metaclass of message 'RemoteCtrl_Request'."""

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
                'cloud_service.srv.RemoteCtrl_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__remote_ctrl__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__remote_ctrl__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__remote_ctrl__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__remote_ctrl__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__remote_ctrl__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RemoteCtrl_Request(metaclass=Metaclass_RemoteCtrl_Request):
    """Message class 'RemoteCtrl_Request'."""

    __slots__ = [
        '_msg_id',
        '_cmd_id',
        '_payload',
    ]

    _fields_and_field_types = {
        'msg_id': 'int64',
        'cmd_id': 'int32',
        'payload': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.msg_id = kwargs.get('msg_id', int())
        self.cmd_id = kwargs.get('cmd_id', int())
        self.payload = kwargs.get('payload', str())

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
        if self.cmd_id != other.cmd_id:
            return False
        if self.payload != other.payload:
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
                isinstance(value, int), \
                "The 'msg_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'msg_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._msg_id = value

    @builtins.property
    def cmd_id(self):
        """Message field 'cmd_id'."""
        return self._cmd_id

    @cmd_id.setter
    def cmd_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'cmd_id' field must be an integer in [-2147483648, 2147483647]"
        self._cmd_id = value

    @builtins.property
    def payload(self):
        """Message field 'payload'."""
        return self._payload

    @payload.setter
    def payload(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'payload' field must be of type 'str'"
        self._payload = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RemoteCtrl_Response(type):
    """Metaclass of message 'RemoteCtrl_Response'."""

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
                'cloud_service.srv.RemoteCtrl_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__remote_ctrl__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__remote_ctrl__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__remote_ctrl__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__remote_ctrl__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__remote_ctrl__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RemoteCtrl_Response(metaclass=Metaclass_RemoteCtrl_Response):
    """Message class 'RemoteCtrl_Response'."""

    __slots__ = [
        '_code',
        '_message',
    ]

    _fields_and_field_types = {
        'code': 'int32',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.code = kwargs.get('code', int())
        self.message = kwargs.get('message', str())

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
        if self.code != other.code:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
            assert value >= -2147483648 and value < 2147483648, \
                "The 'code' field must be an integer in [-2147483648, 2147483647]"
        self._code = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_RemoteCtrl(type):
    """Metaclass of service 'RemoteCtrl'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cloud_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cloud_service.srv.RemoteCtrl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__remote_ctrl

            from cloud_service.srv import _remote_ctrl
            if _remote_ctrl.Metaclass_RemoteCtrl_Request._TYPE_SUPPORT is None:
                _remote_ctrl.Metaclass_RemoteCtrl_Request.__import_type_support__()
            if _remote_ctrl.Metaclass_RemoteCtrl_Response._TYPE_SUPPORT is None:
                _remote_ctrl.Metaclass_RemoteCtrl_Response.__import_type_support__()


class RemoteCtrl(metaclass=Metaclass_RemoteCtrl):
    from cloud_service.srv._remote_ctrl import RemoteCtrl_Request as Request
    from cloud_service.srv._remote_ctrl import RemoteCtrl_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
