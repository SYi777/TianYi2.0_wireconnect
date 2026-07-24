# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cm_msgs:msg/HandPoseReq.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'rpy'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HandPoseReq(type):
    """Metaclass of message 'HandPoseReq'."""

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
                'cm_msgs.msg.HandPoseReq')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hand_pose_req
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hand_pose_req
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hand_pose_req
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hand_pose_req
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hand_pose_req

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


class HandPoseReq(metaclass=Metaclass_HandPoseReq):
    """Message class 'HandPoseReq'."""

    __slots__ = [
        '_header',
        '_hand_move_enable',
        '_hand_side',
        '_hand_reset',
        '_left_hand_pose_req',
        '_right_hand_pose_req',
        '_head_move_enable',
        '_rpy',
        '_gripper_move_enable',
        '_gripper_side',
        '_finger_status',
        '_little_finger',
        '_ring_finger',
        '_middle_finger',
        '_index_finger',
        '_thumb_bending',
        '_thumb_rotating',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'hand_move_enable': 'uint8',
        'hand_side': 'uint8',
        'hand_reset': 'uint8',
        'left_hand_pose_req': 'geometry_msgs/Pose',
        'right_hand_pose_req': 'geometry_msgs/Pose',
        'head_move_enable': 'uint8',
        'rpy': 'sequence<double>',
        'gripper_move_enable': 'uint8',
        'gripper_side': 'uint8',
        'finger_status': 'uint8',
        'little_finger': 'float',
        'ring_finger': 'float',
        'middle_finger': 'float',
        'index_finger': 'float',
        'thumb_bending': 'float',
        'thumb_rotating': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.hand_move_enable = kwargs.get('hand_move_enable', int())
        self.hand_side = kwargs.get('hand_side', int())
        self.hand_reset = kwargs.get('hand_reset', int())
        from geometry_msgs.msg import Pose
        self.left_hand_pose_req = kwargs.get('left_hand_pose_req', Pose())
        from geometry_msgs.msg import Pose
        self.right_hand_pose_req = kwargs.get('right_hand_pose_req', Pose())
        self.head_move_enable = kwargs.get('head_move_enable', int())
        self.rpy = array.array('d', kwargs.get('rpy', []))
        self.gripper_move_enable = kwargs.get('gripper_move_enable', int())
        self.gripper_side = kwargs.get('gripper_side', int())
        self.finger_status = kwargs.get('finger_status', int())
        self.little_finger = kwargs.get('little_finger', float())
        self.ring_finger = kwargs.get('ring_finger', float())
        self.middle_finger = kwargs.get('middle_finger', float())
        self.index_finger = kwargs.get('index_finger', float())
        self.thumb_bending = kwargs.get('thumb_bending', float())
        self.thumb_rotating = kwargs.get('thumb_rotating', float())

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
        if self.hand_move_enable != other.hand_move_enable:
            return False
        if self.hand_side != other.hand_side:
            return False
        if self.hand_reset != other.hand_reset:
            return False
        if self.left_hand_pose_req != other.left_hand_pose_req:
            return False
        if self.right_hand_pose_req != other.right_hand_pose_req:
            return False
        if self.head_move_enable != other.head_move_enable:
            return False
        if self.rpy != other.rpy:
            return False
        if self.gripper_move_enable != other.gripper_move_enable:
            return False
        if self.gripper_side != other.gripper_side:
            return False
        if self.finger_status != other.finger_status:
            return False
        if self.little_finger != other.little_finger:
            return False
        if self.ring_finger != other.ring_finger:
            return False
        if self.middle_finger != other.middle_finger:
            return False
        if self.index_finger != other.index_finger:
            return False
        if self.thumb_bending != other.thumb_bending:
            return False
        if self.thumb_rotating != other.thumb_rotating:
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
    def hand_move_enable(self):
        """Message field 'hand_move_enable'."""
        return self._hand_move_enable

    @hand_move_enable.setter
    def hand_move_enable(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hand_move_enable' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hand_move_enable' field must be an unsigned integer in [0, 255]"
        self._hand_move_enable = value

    @builtins.property
    def hand_side(self):
        """Message field 'hand_side'."""
        return self._hand_side

    @hand_side.setter
    def hand_side(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hand_side' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hand_side' field must be an unsigned integer in [0, 255]"
        self._hand_side = value

    @builtins.property
    def hand_reset(self):
        """Message field 'hand_reset'."""
        return self._hand_reset

    @hand_reset.setter
    def hand_reset(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hand_reset' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hand_reset' field must be an unsigned integer in [0, 255]"
        self._hand_reset = value

    @builtins.property
    def left_hand_pose_req(self):
        """Message field 'left_hand_pose_req'."""
        return self._left_hand_pose_req

    @left_hand_pose_req.setter
    def left_hand_pose_req(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'left_hand_pose_req' field must be a sub message of type 'Pose'"
        self._left_hand_pose_req = value

    @builtins.property
    def right_hand_pose_req(self):
        """Message field 'right_hand_pose_req'."""
        return self._right_hand_pose_req

    @right_hand_pose_req.setter
    def right_hand_pose_req(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'right_hand_pose_req' field must be a sub message of type 'Pose'"
        self._right_hand_pose_req = value

    @builtins.property
    def head_move_enable(self):
        """Message field 'head_move_enable'."""
        return self._head_move_enable

    @head_move_enable.setter
    def head_move_enable(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'head_move_enable' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'head_move_enable' field must be an unsigned integer in [0, 255]"
        self._head_move_enable = value

    @builtins.property
    def rpy(self):
        """Message field 'rpy'."""
        return self._rpy

    @rpy.setter
    def rpy(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'rpy' array.array() must have the type code of 'd'"
            self._rpy = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'rpy' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._rpy = array.array('d', value)

    @builtins.property
    def gripper_move_enable(self):
        """Message field 'gripper_move_enable'."""
        return self._gripper_move_enable

    @gripper_move_enable.setter
    def gripper_move_enable(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_move_enable' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gripper_move_enable' field must be an unsigned integer in [0, 255]"
        self._gripper_move_enable = value

    @builtins.property
    def gripper_side(self):
        """Message field 'gripper_side'."""
        return self._gripper_side

    @gripper_side.setter
    def gripper_side(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_side' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gripper_side' field must be an unsigned integer in [0, 255]"
        self._gripper_side = value

    @builtins.property
    def finger_status(self):
        """Message field 'finger_status'."""
        return self._finger_status

    @finger_status.setter
    def finger_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'finger_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'finger_status' field must be an unsigned integer in [0, 255]"
        self._finger_status = value

    @builtins.property
    def little_finger(self):
        """Message field 'little_finger'."""
        return self._little_finger

    @little_finger.setter
    def little_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'little_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'little_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._little_finger = value

    @builtins.property
    def ring_finger(self):
        """Message field 'ring_finger'."""
        return self._ring_finger

    @ring_finger.setter
    def ring_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ring_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ring_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ring_finger = value

    @builtins.property
    def middle_finger(self):
        """Message field 'middle_finger'."""
        return self._middle_finger

    @middle_finger.setter
    def middle_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'middle_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'middle_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._middle_finger = value

    @builtins.property
    def index_finger(self):
        """Message field 'index_finger'."""
        return self._index_finger

    @index_finger.setter
    def index_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'index_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'index_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._index_finger = value

    @builtins.property
    def thumb_bending(self):
        """Message field 'thumb_bending'."""
        return self._thumb_bending

    @thumb_bending.setter
    def thumb_bending(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'thumb_bending' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'thumb_bending' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._thumb_bending = value

    @builtins.property
    def thumb_rotating(self):
        """Message field 'thumb_rotating'."""
        return self._thumb_rotating

    @thumb_rotating.setter
    def thumb_rotating(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'thumb_rotating' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'thumb_rotating' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._thumb_rotating = value
