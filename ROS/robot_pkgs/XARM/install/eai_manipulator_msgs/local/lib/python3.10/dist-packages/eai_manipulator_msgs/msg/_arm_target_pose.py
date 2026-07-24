# generated from rosidl_generator_py/resource/_idl.py.em
# with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArmTargetPose(type):
    """Metaclass of message 'ArmTargetPose'."""

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
            module = import_type_support('eai_manipulator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'eai_manipulator_msgs.msg.ArmTargetPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__arm_target_pose
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__arm_target_pose
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__arm_target_pose
            cls._TYPE_SUPPORT = module.type_support_msg__msg__arm_target_pose
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__arm_target_pose

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArmTargetPose(metaclass=Metaclass_ArmTargetPose):
    """Message class 'ArmTargetPose'."""

    __slots__ = [
        '_header',
        '_target',
        '_from_frame',
        '_to_frame',
        '_offset_x',
        '_offset_y',
        '_offset_z',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'target': 'geometry_msgs/Pose',
        'from_frame': 'string',
        'to_frame': 'string',
        'offset_x': 'float',
        'offset_y': 'float',
        'offset_z': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Pose
        self.target = kwargs.get('target', Pose())
        self.from_frame = kwargs.get('from_frame', str())
        self.to_frame = kwargs.get('to_frame', str())
        self.offset_x = kwargs.get('offset_x', float())
        self.offset_y = kwargs.get('offset_y', float())
        self.offset_z = kwargs.get('offset_z', float())

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
        if self.header != other.header:
            return False
        if self.target != other.target:
            return False
        if self.from_frame != other.from_frame:
            return False
        if self.to_frame != other.to_frame:
            return False
        if self.offset_x != other.offset_x:
            return False
        if self.offset_y != other.offset_y:
            return False
        if self.offset_z != other.offset_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def target(self):
        """Message field 'target'."""
        return self._target

    @target.setter
    def target(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'target' field must be a sub message of type 'Pose'"
        self._target = value

    @builtins.property
    def from_frame(self):
        """Message field 'from_frame'."""
        return self._from_frame

    @from_frame.setter
    def from_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'from_frame' field must be of type 'str'"
        self._from_frame = value

    @builtins.property
    def to_frame(self):
        """Message field 'to_frame'."""
        return self._to_frame

    @to_frame.setter
    def to_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'to_frame' field must be of type 'str'"
        self._to_frame = value

    @builtins.property
    def offset_x(self):
        """Message field 'offset_x'."""
        return self._offset_x

    @offset_x.setter
    def offset_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_x = value

    @builtins.property
    def offset_y(self):
        """Message field 'offset_y'."""
        return self._offset_y

    @offset_y.setter
    def offset_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_y = value

    @builtins.property
    def offset_z(self):
        """Message field 'offset_z'."""
        return self._offset_z

    @offset_z.setter
    def offset_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_z = value
