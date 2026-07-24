"""Example script demonstrating the usage of Brainco Hand 2 ROS 2 driver.

This script shows how to:
1. Initialize and connect to Brainco Hand 2 devices
2. Read joint states (position, force)
3. Control hand movements (open, close, custom positions)
4. Use both single and continuous publishing modes

Changelog:
    - 2025-12-13 (Harvey Liu): Create Brainco Hand 2 ROS 2 example script.
"""

from __future__ import annotations

from xrocs.common.data_type import Joints
from xrocs.entity.hand.hand_loader import hand_loader
from xrocs.entity.hand.Brainco.brainco_hand_2_ros2 import BraincoHand2Ros2
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

def example_read_hand_joint_states(hand: BraincoHand2Ros2):
    print(f"Hand current force: {hand.get_current_force()}.")
    print(f"Hand current joints radian_ndarray: {hand.get_current_joint().get_radian_ndarray()}.")

def example_custom_hand_positions(hand: BraincoHand2Ros2):
    input("press enter to open")
    hand.open()
    input("press enter to close")
    hand.close()
    input("press enter to move")
    hand.sync_target_joint([100, 100, 100, 100, 100, 0.]) # 适用于高频短距控制
    input("press enter to move")
    hand.sync_target_joint([0.5]) # 适用于高频短距控制
    input("press enter to move")
    hand.set_target_joint(Joints([100, 100, 100, 100, 100, 0.], 6)) # 适用于低频长距控制


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
                    "type": "BraincoHand2Ros2",
                    "hand_name": "left",
                    "sub_hand_joints": True,
                    "sub_hand_touch": True,
                },
                "right": {
                    "enable": True,
                    "type": "BraincoHand2Ros2",
                    "hand_name": "right",
                    "sub_hand_joints": True,
                    "sub_hand_touch": True,
                }
            }

    hands = hand_loader.instantiate_hands(hand_cfgs=hand_cfgs)
    for name, hand in hands.items():
        print(f"Instantiated hand {name}")
        hand.connect()
        print(f"Dofs: {hand.num_dofs()}")

        example_read_hand_joint_states(hand)
        example_custom_hand_positions(hand)
    