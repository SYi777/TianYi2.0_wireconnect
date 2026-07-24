# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cm_msgs:srv/WaypointsRos2.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WaypointsRos2_Request(type):
    """Metaclass of message 'WaypointsRos2_Request'."""

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
                'cm_msgs.srv.WaypointsRos2_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__waypoints_ros2__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__waypoints_ros2__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__waypoints_ros2__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__waypoints_ros2__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__waypoints_ros2__request

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class WaypointsRos2_Request(metaclass=Metaclass_WaypointsRos2_Request):
    """Message class 'WaypointsRos2_Request'."""

    __slots__ = [
        '_left_waypoints',
        '_right_waypoints',
    ]

    _fields_and_field_types = {
        'left_waypoints': 'sequence<geometry_msgs/PoseStamped>',
        'right_waypoints': 'sequence<geometry_msgs/PoseStamped>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_waypoints = kwargs.get('left_waypoints', [])
        self.right_waypoints = kwargs.get('right_waypoints', [])

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
        if self.left_waypoints != other.left_waypoints:
            return False
        if self.right_waypoints != other.right_waypoints:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_waypoints(self):
        """Message field 'left_waypoints'."""
        return self._left_waypoints

    @left_waypoints.setter
    def left_waypoints(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
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
                 all(isinstance(v, PoseStamped) for v in value) and
                 True), \
                "The 'left_waypoints' field must be a set or sequence and each value of type 'PoseStamped'"
        self._left_waypoints = value

    @builtins.property
    def right_waypoints(self):
        """Message field 'right_waypoints'."""
        return self._right_waypoints

    @right_waypoints.setter
    def right_waypoints(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
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
                 all(isinstance(v, PoseStamped) for v in value) and
                 True), \
                "The 'right_waypoints' field must be a set or sequence and each value of type 'PoseStamped'"
        self._right_waypoints = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_WaypointsRos2_Response(type):
    """Metaclass of message 'WaypointsRos2_Response'."""

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
                'cm_msgs.srv.WaypointsRos2_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__waypoints_ros2__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__waypoints_ros2__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__waypoints_ros2__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__waypoints_ros2__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__waypoints_ros2__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class WaypointsRos2_Response(metaclass=Metaclass_WaypointsRos2_Response):
    """Message class 'WaypointsRos2_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
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
        if self.success != other.success:
            return False
        if self.message != other.message:
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


class Metaclass_WaypointsRos2(type):
    """Metaclass of service 'WaypointsRos2'."""

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
                'cm_msgs.srv.WaypointsRos2')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__waypoints_ros2

            from cm_msgs.srv import _waypoints_ros2
            if _waypoints_ros2.Metaclass_WaypointsRos2_Request._TYPE_SUPPORT is None:
                _waypoints_ros2.Metaclass_WaypointsRos2_Request.__import_type_support__()
            if _waypoints_ros2.Metaclass_WaypointsRos2_Response._TYPE_SUPPORT is None:
                _waypoints_ros2.Metaclass_WaypointsRos2_Response.__import_type_support__()


class WaypointsRos2(metaclass=Metaclass_WaypointsRos2):
    from cm_msgs.srv._waypoints_ros2 import WaypointsRos2_Request as Request
    from cm_msgs.srv._waypoints_ros2 import WaypointsRos2_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
