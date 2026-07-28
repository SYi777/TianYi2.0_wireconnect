from eai_manipulator_msgs.srv._end_pose_off_set import EndPoseOffSet  # noqa: F401
from eai_manipulator_msgs.srv._info import Info  # noqa: F401
from eai_manipulator_msgs.srv._mode import Mode  # noqa: F401

import sys as _sys
_MetaSrv = type(Mode)
_MetaReq = type(Mode.Request)
_MetaRes = type(Mode.Response)

def __getattr__(name):
    if name.startswith("_"):
        raise AttributeError(name)
    Req = _MetaReq(name + "_Request", (), {"__module__": __name__})
    Res = _MetaRes(name + "_Response", (), {"__module__": __name__})
    srv = _MetaSrv(name, (), {"__module__": __name__, "Request": Req, "Response": Res})
    setattr(_sys.modules[__name__], name, srv)
    return srv
