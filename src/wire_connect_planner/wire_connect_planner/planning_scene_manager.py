#!/usr/bin/env python3
"""planning_scene_manager — 持续更新桌面碰撞物体，独立于规划节点。

Subscribes:
  /vision/table        (TableInfo)    绿色桌面检测
  /vision/left_target  (ArmTarget)    兜底: cable_z 推算桌子

Publishes:
  /planning_scene       (PlanningScene)
"""

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Point
from shape_msgs.msg import SolidPrimitive
from moveit_msgs.msg import PlanningScene, PlanningSceneWorld, CollisionObject
from std_msgs.msg import Header

from wire_connect_msgs.msg import TableInfo, ArmTarget


class PlanningSceneManager(Node):
    def __init__(self):
        super().__init__("planning_scene_manager")

        self.declare_parameter("table_thickness", 0.05)
        self.declare_parameter("table_z_offset", -0.02)   # top below surface
        self.declare_parameter("fallback_xy", [1.0, 0.6]) # fallback box when no TableInfo
        self.declare_parameter("update_threshold", 0.02)   # 2cm min move to update
        self.declare_parameter("fallback_timeout", 30.0)   # wait 30s for TableInfo
        self.declare_parameter("frame", "waist_yaw_link")

        self._table_h = self.get_parameter("table_thickness").value
        self._table_dz = self.get_parameter("table_z_offset").value
        self._fallback_xy = self.get_parameter("fallback_xy").value
        self._threshold = self.get_parameter("update_threshold").value
        self._frame = self.get_parameter("frame").value

        # subscribers
        self._table_info = None
        self._last_cable = None
        self.create_subscription(TableInfo, "/vision/table", self._cb_table, 10)
        self.create_subscription(ArmTarget, "/vision/left_target", self._cb_target, 10)

        # publisher
        self._pub = self.create_publisher(PlanningScene, "/planning_scene", 10)

        # state
        self._last_center = None
        self._last_size = None

        # timer: check for table info and publish
        self.create_timer(2.0, self._tick)

        self.get_logger().info("planning_scene_manager ready")

    def _cb_table(self, msg: TableInfo):
        if msg.valid:
            self._table_info = msg

    def _cb_target(self, msg: ArmTarget):
        self._last_cable = msg

    def _tick(self):
        if self._table_info is not None:
            self._publish_from_table(self._table_info)
        else:
            self.get_logger().warn("no TableInfo, waiting...", throttle_duration_sec=10.0)

    def _publish_from_table(self, info: TableInfo):
        w = info.x_max - info.x_min
        d = info.y_max - info.y_min
        if w <= 0 or d <= 0:
            return

        cx = (info.x_min + info.x_max) / 2.0
        cy = (info.y_min + info.y_max) / 2.0
        cz = info.z + self._table_dz - self._table_h / 2.0

        # skip if barely changed
        new_center = (cx, cy, cz)
        new_size = (w, d, self._table_h)
        if self._last_center is not None:
            dx = abs(new_center[0] - self._last_center[0])
            dy = abs(new_center[1] - self._last_center[1])
            dz = abs(new_center[2] - self._last_center[2])
            if max(dx, dy, dz) < self._threshold:
                return

        self._last_center = new_center
        self._last_size = new_size

        box = SolidPrimitive(type=SolidPrimitive.BOX,
                             dimensions=[float(w), float(d), float(self._table_h)])
        co = CollisionObject()
        co.header = Header(frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        co.id = "table_obstacle"
        co.operation = CollisionObject.ADD
        co.primitives = [box]
        co.primitive_poses = [Pose(position=Point(x=cx, y=cy, z=cz))]

        scene = PlanningScene()
        scene.world = PlanningSceneWorld(collision_objects=[co])
        scene.is_diff = True
        self._pub.publish(scene)
        self.get_logger().info(
            f"table updated: {w:.2f}×{d:.2f}×{self._table_h}  "
            f"center=[{cx:.2f},{cy:.2f},{cz:.2f}]")


def main():
    rclpy.init()
    node = PlanningSceneManager()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
