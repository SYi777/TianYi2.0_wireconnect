from eai_manipulator_msgs.action._end_pos_dual_target import EndPosDualTarget  # noqa: F401
from eai_manipulator_msgs.action._end_pos_single_target import EndPosSingleTarget  # noqa: F401
from eai_manipulator_msgs.action._joint_space import JointSpace  # noqa: F401

import sys as _sys
_MetaAct = type(JointSpace)

class _StubBase:
    pass

def __getattr__(name):
    if name.startswith("_"):
        raise AttributeError(name)
    act = _MetaAct(name, (_StubBase,), {"__module__": __name__})
    setattr(_sys.modules[__name__], name, act)
    return act
