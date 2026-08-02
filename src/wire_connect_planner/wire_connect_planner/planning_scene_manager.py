#!/usr/bin/env python3
"""planning_scene_manager — receive TableInfo, publish as CollisionObject.

Subscribes: /vision/table (TableInfo)
Publishes:  /planning_scene (PlanningScene)
"""

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Point
from shape_msgs.msg import SolidPrimitive
from moveit_msgs.msg import PlanningScene, PlanningSceneWorld, CollisionObject
from std_msgs.msg import Header

from wire_connect_msgs.msg import TableInfo


class PlanningSceneManager(Node):
    def __init__(self):
        super().__init__("planning_scene_manager")

        self.declare_parameter("table_thickness", 0.05)
        self.declare_parameter("table_z_offset", -0.02)
        self.declare_parameter("table_margin", 0.05)    # inflate table by 5cm for clearance
        self.declare_parameter("frame", "waist_yaw_link")

        self._table_h = self.get_parameter("table_thickness").value
        self._table_dz = self.get_parameter("table_z_offset").value
        self._margin = self.get_parameter("table_margin").value
        self._frame = self.get_parameter("frame").value

        self._last_info = None
        self.create_subscription(TableInfo, "/vision/table", self._cb, 10)
        self._pub = self.create_publisher(PlanningScene, "/planning_scene", 10)

        self.create_timer(2.0, self._tick)
        self.get_logger().info("planning_scene_manager ready")

    def _cb(self, msg: TableInfo):
        if msg.valid:
            self._last_info = msg

    def _tick(self):
        info = self._last_info
        if info is None:
            self.get_logger().warn("waiting for /vision/table...", throttle_duration_sec=10.0)
            return

        w = info.x_max - info.x_min
        d = info.y_max - info.y_min
        if w <= 0 or d <= 0:
            self.get_logger().warn(f"bad dims: w={w:.2f} d={d:.2f}")
            return

        m = self._margin
        gap_half = 0.5   # 1m total gap centered under table
        top_z = info.z + self._table_dz
        cx = (info.x_min + info.x_max) / 2.0
        cy = (info.y_min + info.y_max) / 2.0

        # table top box (full width, inflated)
        box_top = SolidPrimitive(type=SolidPrimitive.BOX,
                                 dimensions=[float(w + 2*m), float(d + 2*m), self._table_h + 2*m])

        # below fill: two pillars with 1m gap in center
        below_h = 2.0
        below_z = top_z - self._table_h / 2.0 - m - below_h / 2.0
        half_d = (d + 2*m) / 2.0
        pillar_w = max(0.01, half_d - gap_half)   # each pillar width, min 1cm
        pillar_dims = [float(w + 2*m), float(pillar_w), float(below_h)]
        pillar_y_l = cy - gap_half - pillar_w / 2.0
        pillar_y_r = cy + gap_half + pillar_w / 2.0

        co = CollisionObject()
        co.header = Header(frame_id=self._frame)
        co.id = "table_obstacle"
        co.operation = CollisionObject.ADD
        co.primitives = [box_top,
                         SolidPrimitive(type=SolidPrimitive.BOX, dimensions=pillar_dims),
                         SolidPrimitive(type=SolidPrimitive.BOX, dimensions=pillar_dims)]
        co.primitive_poses = [
            Pose(position=Point(x=cx, y=cy, z=top_z - self._table_h / 2.0)),
            Pose(position=Point(x=cx, y=pillar_y_l, z=below_z)),
            Pose(position=Point(x=cx, y=pillar_y_r, z=below_z)),
        ]

        scene = PlanningScene()
        scene.world = PlanningSceneWorld(collision_objects=[co])
        scene.is_diff = True
        self._pub.publish(scene)
        self.get_logger().info(
            f"table sent: {w:.2f}×{d:.2f}×{self._table_h}  "
            f"top={info.z + self._table_dz:.3f}", throttle_duration_sec=4.0)


def main():
    rclpy.init()
    node = PlanningSceneManager()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        try: rclpy.shutdown()
        except: pass


if __name__ == "__main__":
    main()
