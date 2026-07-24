"""TienYi 2.0 Pro chassis (Knewbot) example (via station)."""

from __future__ import annotations

from xrocs.entity.robot.TienYi2Pro.knewbot_chassis_controller_http import KnewbotChassisController
import math
import numpy as np



def execute_chassis_action(chassis_ctrler, action) -> None:
        """Convert a chassis velocity command into a one-second ``move_by`` action.

        Translation and in-place rotation are separate modes in the Knewbot
        REST API. Simultaneous non-zero linear and angular velocities therefore
        cannot be represented by this endpoint and are rejected explicitly.
        """
        _CHASSIS_ACTION_DURATION_S = 1.0
        _CHASSIS_VELOCITY_EPSILON = 1e-6

        try:
            move_vel = np.asarray(action["chassis"]["move_vel"], dtype=float).reshape(-1)
        except (KeyError, TypeError, ValueError) as exc:
            raise ValueError("Chassis move_vel must be a numeric [linear_x, linear_y, angular_z] sequence.") from exc

        if move_vel.size != 3:
            raise ValueError("Chassis move_vel must contain exactly 3 values.")
        if not np.all(np.isfinite(move_vel)):
            raise ValueError("Chassis move_vel values must all be finite.")

        linear_x, linear_y, angular_z = (float(value) for value in move_vel)
        linear_speed = math.hypot(linear_x, linear_y)
        has_translation = linear_speed > _CHASSIS_VELOCITY_EPSILON
        has_rotation = abs(angular_z) > _CHASSIS_VELOCITY_EPSILON

        if has_translation and has_rotation:
            raise ValueError("Knewbot move_by cannot combine translation with in-place rotation.")

        if has_translation:
            move_mode = 0
            direction = math.atan2(linear_y, linear_x)
            distance = max(1, round(linear_speed * _CHASSIS_ACTION_DURATION_S * 1000.0))
        elif has_rotation:
            move_mode = 1
            direction = angular_z * _CHASSIS_ACTION_DURATION_S
            distance = 0
        else:
            move_mode = 0
            direction = math.atan2(linear_y, linear_x) if linear_speed > 0.0 else 0.0
            distance = 0

        chassis_ctrler.move_by(
            move_mode=move_mode,
            direction=direction,
            distance=distance,
            v=linear_speed,
            w=abs(angular_z),
            wait=True,
        )

if __name__ == "__main__":
    cfg = {
        "host": "192.168.11.10",  # Chassis IP
        "rest_port": 9090,  # REST API port
        "domain_id": 0,  # ROS 2 DOMAIN_ID
        "nav_timeout": 300,  # navigation action timeout, in seconds
        "request_timeout": 10  # REST request timeout, in seconds
    }
    chassis = KnewbotChassisController(cfg)

    # print(f"get_robot_info is {chassis.get_robot_info()}")
    # print(f"get_power_status is {chassis.get_power_status()}")
    # print(f"get_robot_health is {chassis.get_robot_health()}")
    # print(f"get_battery_pack is {chassis.get_battery_pack()}")
    # print(f"get_speed_params is {chassis.get_speed_params()}")
    # print(f"set_speed_params is {chassis.set_speed_params(1.0, 0.5)}")
    # print(f"get_speed_params is {chassis.get_speed_params()}")

    # print(f"get_mapping_enabled is {chassis.get_mapping_enabled()}")
    # print(f"set_mapping_enabled is {chassis.set_mapping_enabled(True)}")
    # print(f"set_mapping_enabled is {chassis.set_mapping_enabled(False)}")
    # print(f"get_mapping_enabled is {chassis.get_mapping_enabled()}")

    # print(f"get_action_status is {chassis.get_action_status(action_id=1)}")
    # print(f"get_timestamp is {chassis.get_timestamp()}")
    # print(f"get_odometry is {chassis.get_odometry()}")
    # print(f"get_runtime is {chassis.get_runtime()}")

    # print(f"move_to is {chassis.move_to(1., 1., 1.)}")
    # print(f"get_pose is {chassis.get_pose()}")

    # print(f"is_healthy is {chassis.is_healthy()}")
    # print(f"is_localized is {chassis.is_localized()}")

    action = {
        "chassis": {
            "move_vel": [-0.1, 0.0, 0.0]
        }
    }
    pose = chassis.get_pose()
    print(f"get_pose is {pose}")

    input("move to")
    result = chassis.move_to(x=4.00, y=-1.88, yaw=1.046, flags=1)
    print(f"move to result is {result}")
    # status = chassis.get_action_status(action_id=0)
    # print(f"get_action_status is {status}")
    # chassis.move_by(direction=math.pi/2, distance=50, v=0.5, w=0.1, wait=False)
    # input("stop")
    # input("execute chassis action")
    # chassis.move_by(move_mode=1, direction=math.pi, distance=100, theta=math.pi/2, v=0.1, w=0.1, flags=1, wait=False)
    # execute_chassis_action(chassis, action)