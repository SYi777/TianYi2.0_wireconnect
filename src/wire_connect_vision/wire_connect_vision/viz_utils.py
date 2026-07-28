"""RViz MarkerArray helper constructors."""

from geometry_msgs.msg import Point, Vector3
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray


def _rgba(r: float, g: float, b: float, a: float = 1.0) -> ColorRGBA:
    return ColorRGBA(r=float(r), g=float(g), b=float(b), a=float(a))


def make_delete_all() -> Marker:
    """Return a DELETEALL marker — publish first to clear previous frame."""
    m = Marker()
    m.action = Marker.DELETEALL
    return m


def make_sphere(x: float, y: float, z: float, frame_id: str,
                idx: int, namespace: str, color: tuple[float, float, float],
                diameter: float = 0.01, lifetime_sec: float = 0.0) -> Marker:
    """Sphere marker at a 3D point.

    Args:
        lifetime_sec: 0 = permanent (until next DELETEALL)
    """
    m = Marker()
    m.header.frame_id = frame_id
    m.header.stamp.sec = 0
    m.header.stamp.nanosec = 0
    m.ns = namespace
    m.id = idx
    m.type = Marker.SPHERE
    m.action = Marker.ADD
    m.pose.position = Point(x=float(x), y=float(y), z=float(z))
    m.scale = Vector3(x=diameter, y=diameter, z=diameter)
    m.color = _rgba(*color)
    m.lifetime.sec = int(lifetime_sec)
    return m


def make_arrow(origin: tuple[float, float, float],
               direction: tuple[float, float, float],
               frame_id: str, idx: int, namespace: str,
               color: tuple[float, float, float],
               shaft_diameter: float = 0.003,
               head_diameter: float = 0.006,
               head_length: float = 0.008) -> Marker:
    """Arrow marker from origin along direction vector.

    Args:
        origin: (x, y, z) start point
        direction: (dx, dy, dz) NOT normalized — magnitude sets arrow length
    """
    import math
    import numpy as np

    m = Marker()
    m.header.frame_id = frame_id
    m.header.stamp.sec = 0
    m.header.stamp.nanosec = 0
    m.ns = namespace
    m.id = idx
    m.type = Marker.ARROW
    m.action = Marker.ADD

    start = Point(x=float(origin[0]), y=float(origin[1]), z=float(origin[2]))
    end = Point(
        x=float(origin[0] + direction[0]),
        y=float(origin[1] + direction[1]),
        z=float(origin[2] + direction[2]),
    )
    m.points = [start, end]
    m.scale = Vector3(x=shaft_diameter, y=head_diameter, z=head_length)
    m.color = _rgba(*color)
    return m


def publish_markers(publisher, markers: list[Marker]) -> None:
    """Publish a MarkerArray with automatic DELETEALL prefix.

    Usage:
        markers = [make_sphere(...), make_arrow(...)]
        publish_markers(self._marker_pub, markers)
    """
    valid = [m for m in markers if m is not None]
    msg = MarkerArray(markers=[make_delete_all()] + valid)
    publisher.publish(msg)
