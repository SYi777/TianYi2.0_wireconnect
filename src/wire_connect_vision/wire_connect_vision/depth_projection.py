"""Depth back-projection and TF coordinate transform utilities."""

from geometry_msgs.msg import Point, PointStamped
import tf2_geometry_msgs as tfg
import rclpy


def back_project(uc: float, vc: float, depth_mm: int, fx: float, fy: float,
                 cx: float, cy: float) -> tuple[float, float, float]:
    """Pixel + depth (mm) → 3D coordinates in camera optical frame (metres).

    Args:
        uc, vc: pixel coordinates (0-indexed)
        depth_mm: depth value in millimetres (16UC1)
        fx, fy, cx, cy: camera intrinsic parameters

    Returns:
        (X, Y, Z) in metres, optical frame convention (Z forward)
    """
    Z = depth_mm / 1000.0
    X = (uc - cx) * Z / fx
    Y = (vc - cy) * Z / fy
    return (X, Y, Z)


def project_to_frame(x: float, y: float, z: float,
                     from_frame: str, to_frame: str,
                     tf_buffer, timeout_sec: float = 1.0) -> Point:
    """Transform a 3D point from one TF frame to another.

    Args:
        x, y, z: point in from_frame (metres)
        from_frame: source TF frame (e.g. 'ob_camera_head_color_optical_frame')
        to_frame: target TF frame (e.g. 'waist_yaw_link')
        tf_buffer: tf2_ros.Buffer instance
        timeout_sec: max wait for TF lookup

    Returns:
        geometry_msgs/Point in to_frame

    Raises:
        tf2_ros.TransformException: if TF lookup fails
    """
    ps = PointStamped()
    ps.header.frame_id = from_frame
    ps.header.stamp = rclpy.time.Time().to_msg()
    ps.point = Point(x=x, y=y, z=z)

    transform = tf_buffer.lookup_transform(
        to_frame, from_frame,
        rclpy.time.Time(),
        timeout=rclpy.duration.Duration(seconds=timeout_sec),
    )
    transformed = tfg.do_transform_point(ps, transform)
    return transformed.point
