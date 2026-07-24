"""Example script demonstrating the usage of Inspire Hand 3 ROS 2 driver.

This script shows how to:
1. Initialize and connect to Inspire Hand 3 devices
2. Read joint states (position, velocity, effort)
3. Control hand movements (open, custom positions)
4. Use both single and continuous publishing modes

Changelog:
    - 2025-12-10 (Chris Ren): Create Inspire Hand 3 ROS 2 example script.
"""

from __future__ import annotations
import time

from xrocs.entity.hand.hand_loader import hand_loader
from xrocs.entity.hand.InspireHand.inspire_hand_3_ros2 import InspireHand3Ros2
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

def example_read_hand_joint_states(hand: InspireHand3Ros2):
    print(f"Hand joint positions: {hand.get_position()}.")
    print(f"Hand joint velocity: {hand.get_velocity()}.")
    print(f"Hand joint effort: {hand.get_effort()}.")
    print(f"Hand current joints radian_ndarray: {hand.get_current_joint().get_radian_ndarray()}.")

def example_custom_hand_positions(hand: InspireHand3Ros2):
    hand.open()
    time.sleep(1)

    for joint_idx in range(hand.num_dofs()):
        target_joint = [1.0] * hand.num_dofs()
        target_joint[joint_idx] = 0.0
        print(f"Testing joint index {joint_idx}: {target_joint}")
        hand.sync_target_joint(target_joint)  # 逐维置 0，排查手部关节顺序。
        input("Press Enter to continue...")


if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
        hand_cfgs = config.get("hand", {})
    else:
        hand_cfgs = {
                "left": {
                    "enable": True,
                    "type": "InspireHand3Ros2",
                    "hand_name": "left",
                    "sub_hand_joints": True
                },
                "right": {
                    "enable": True,
                    "type": "InspireHand3Ros2",
                    "hand_name": "right",
                    "sub_hand_joints": True
                }
            }

    hands = hand_loader.instantiate_hands(hand_cfgs=hand_cfgs)
    for name, hand in hands.items():
        print(f"Instantiated hand {name}")
        hand.connect()
        print(f"Dofs:{hand.num_dofs()}")

        example_read_hand_joint_states(hand)
        example_custom_hand_positions(hand)
    