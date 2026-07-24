# generated from rosidl_generator_py/resource/_idl.py.em
# with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DualArmTargetPose(type):
    """Metaclass of message 'DualArmTargetPose'."""

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
                'eai_manipulator_msgs.msg.DualArmTargetPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dual_arm_target_pose
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dual_arm_target_pose
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dual_arm_target_pose
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dual_arm_target_pose
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dual_arm_target_pose

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


class DualArmTargetPose(metaclass=Metaclass_DualArmTargetPose):
    """Message class 'DualArmTargetPose'."""

    __slots__ = [
        '_header',
        '_target_l',
        '_from_frame_l',
        '_to_frame_l',
        '_offset_x_l',
        '_offset_y_l',
        '_offset_z_l',
        '_target_r',
        '_from_frame_r',
        '_to_frame_r',
        '_offset_x_r',
        '_offset_y_r',
        '_offset_z_r',
        '_is_dual_arm_syn',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'target_l': 'geometry_msgs/Pose',
        'from_frame_l': 'string',
        'to_frame_l': 'string',
        'offset_x_l': 'float',
        'offset_y_l': 'float',
        'offset_z_l': 'float',
        'target_r': 'geometry_msgs/Pose',
        'from_frame_r': 'string',
        'to_frame_r': 'string',
        'offset_x_r': 'float',
        'offset_y_r': 'float',
        'offset_z_r': 'float',
        'is_dual_arm_syn': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Pose
        self.target_l = kwargs.get('target_l', Pose())
        self.from_frame_l = kwargs.get('from_frame_l', str())
        self.to_frame_l = kwargs.get('to_frame_l', str())
        self.offset_x_l = kwargs.get('offset_x_l', float())
        self.offset_y_l = kwargs.get('offset_y_l', float())
        self.offset_z_l = kwargs.get('offset_z_l', float())
        from geometry_msgs.msg import Pose
        self.target_r = kwargs.get('target_r', Pose())
        self.from_frame_r = kwargs.get('from_frame_r', str())
        self.to_frame_r = kwargs.get('to_frame_r', str())
        self.offset_x_r = kwargs.get('offset_x_r', float())
        self.offset_y_r = kwargs.get('offset_y_r', float())
        self.offset_z_r = kwargs.get('offset_z_r', float())
        self.is_dual_arm_syn = kwargs.get('is_dual_arm_syn', bool())

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
        if self.target_l != other.target_l:
            return False
        if self.from_frame_l != other.from_frame_l:
            return False
        if self.to_frame_l != other.to_frame_l:
            return False
        if self.offset_x_l != other.offset_x_l:
            return False
        if self.offset_y_l != other.offset_y_l:
            return False
        if self.offset_z_l != other.offset_z_l:
            return False
        if self.target_r != other.target_r:
            return False
        if self.from_frame_r != other.from_frame_r:
            return False
        if self.to_frame_r != other.to_frame_r:
            return False
        if self.offset_x_r != other.offset_x_r:
            return False
        if self.offset_y_r != other.offset_y_r:
            return False
        if self.offset_z_r != other.offset_z_r:
            return False
        if self.is_dual_arm_syn != other.is_dual_arm_syn:
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
    def target_l(self):
        """Message field 'target_l'."""
        return self._target_l

    @target_l.setter
    def target_l(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'target_l' field must be a sub message of type 'Pose'"
        self._target_l = value

    @builtins.property
    def from_frame_l(self):
        """Message field 'from_frame_l'."""
        return self._from_frame_l

    @from_frame_l.setter
    def from_frame_l(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'from_frame_l' field must be of type 'str'"
        self._from_frame_l = value

    @builtins.property
    def to_frame_l(self):
        """Message field 'to_frame_l'."""
        return self._to_frame_l

    @to_frame_l.setter
    def to_frame_l(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'to_frame_l' field must be of type 'str'"
        self._to_frame_l = value

    @builtins.property
    def offset_x_l(self):
        """Message field 'offset_x_l'."""
        return self._offset_x_l

    @offset_x_l.setter
    def offset_x_l(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_x_l' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_x_l' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_x_l = value

    @builtins.property
    def offset_y_l(self):
        """Message field 'offset_y_l'."""
        return self._offset_y_l

    @offset_y_l.setter
    def offset_y_l(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_y_l' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_y_l' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_y_l = value

    @builtins.property
    def offset_z_l(self):
        """Message field 'offset_z_l'."""
        return self._offset_z_l

    @offset_z_l.setter
    def offset_z_l(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_z_l' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_z_l' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_z_l = value

    @builtins.property
    def target_r(self):
        """Message field 'target_r'."""
        return self._target_r

    @target_r.setter
    def target_r(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'target_r' field must be a sub message of type 'Pose'"
        self._target_r = value

    @builtins.property
    def from_frame_r(self):
        """Message field 'from_frame_r'."""
        return self._from_frame_r

    @from_frame_r.setter
    def from_frame_r(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'from_frame_r' field must be of type 'str'"
        self._from_frame_r = value

    @builtins.property
    def to_frame_r(self):
        """Message field 'to_frame_r'."""
        return self._to_frame_r

    @to_frame_r.setter
    def to_frame_r(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'to_frame_r' field must be of type 'str'"
        self._to_frame_r = value

    @builtins.property
    def offset_x_r(self):
        """Message field 'offset_x_r'."""
        return self._offset_x_r

    @offset_x_r.setter
    def offset_x_r(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_x_r' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_x_r' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_x_r = value

    @builtins.property
    def offset_y_r(self):
        """Message field 'offset_y_r'."""
        return self._offset_y_r

    @offset_y_r.setter
    def offset_y_r(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_y_r' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_y_r' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_y_r = value

    @builtins.property
    def offset_z_r(self):
        """Message field 'offset_z_r'."""
        return self._offset_z_r

    @offset_z_r.setter
    def offset_z_r(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_z_r' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_z_r' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_z_r = value

    @builtins.property
    def is_dual_arm_syn(self):
        """Message field 'is_dual_arm_syn'."""
        return self._is_dual_arm_syn

    @is_dual_arm_syn.setter
    def is_dual_arm_syn(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_dual_arm_syn' field must be of type 'bool'"
        self._is_dual_arm_syn = value
