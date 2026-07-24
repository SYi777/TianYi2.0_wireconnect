"""Example script demonstrating the usage of Robotiq USB driver.

This script shows how to:
1. Initialize and connect to Robotiq USB devices
2. Read joint states (position)
3. Control hand movements (open, close, custom positions)
4. Use both single and continuous publishing modes

Changelog:
    - 2025-12-10 (Harvey Liu): Create Robotiq USB example script.
"""

from __future__ import annotations
import time

from xrocs.common.data_type import Joints
from xrocs.entity.hand.hand_loader import hand_loader
from xrocs.entity.hand.RobotiqUSB.robotiq_client_zmq import RobotiqGripperClient
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

def example_read_hand_joint_states(hand: RobotiqGripperClient):
    print(f"Hand current joints radian_ndarray: {hand.get_current_joint().get_radian_ndarray()}.")

def example_custom_hand_positions(hand: RobotiqGripperClient):
    hand.open()
    time.sleep(1)
    hand.close()
    time.sleep(1)
    hand.sync_target_joint([0.5]) # 适用于高频短距控制
    time.sleep(1)
    hand.set_target_joint(Joints([1.0],1)) # 适用于低频长距控制

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
                    "enable": True ,
                    "type": "Robotiq2f85Zmq" ,
                    "hand_ip": "192.168.41.1",
                    "hand_set_port" : "4252",
                    "hand_get_port" : "4253",
                    "sub_hand_joints " : True 
                },
                "right": {
                    "enable": True,
                    "type" : "Robotiq2f85Zmq",
                    "hand_ip" : "192.168.41.1",
                    "hand_set_port" : "4254",
                    "hand_get_port" : "4255",
                    "sub_hand_joints" : True
                }
            }

    hands = hand_loader.instantiate_hands(hand_cfgs=hand_cfgs)
    for name, hand in hands.items():
        print(f"Instantiated hand {name}")
        hand.connect()
        time.sleep(1)
        print(f"Dofs:{hand.num_dofs()}")

        example_read_hand_joint_states(hand)
        example_custom_hand_positions(hand)