"""Example script demonstrating the usage of RealSense camera driver.

This script shows how to:
1. Initialize and connect to RealSense cameras
2. Read RGB and depth images
3. Decode and display images
4. Use both single and continuous publishing modes

Changelog:
    - 2025-12-13 (Harvey Liu): Create RealSense camera example script.
"""

from __future__ import annotations

import time
import cv2

from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.utils.camera.camera_zmq_client import CameraZmqClient
from xrocs.utils.camera_utils import CameraUtils




def examples_read_realsense_camera(name: str, camera: CameraZmqClient):
    rgb_encoded, depth_encoded = camera.read()
    if rgb_encoded is None or depth_encoded is None:
        print(f"{name}读取失败：未获得 RGB 或 Depth。")
        return False

    print(
        f"RGB shape: {rgb_encoded.shape}, "
        f"Depth shape: {depth_encoded.shape}, "
    )

    decoded_color_image = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)
    print(
        f"RGB decoded shape: {decoded_color_image.shape}, "
    )
    print(decoded_color_image)
    cv2.imshow("Decoded Color Image", decoded_color_image)
    cv2.waitKey(5)
    cv2.imwrite("/home/ubuntu/Data/camera_output_check.jpg", decoded_color_image)
    
    return True
    

if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        cfg_loader = ConfigLoader(path_manager.config_toml_path)
        config = cfg_loader.get_config()
        camera_cfgs = config.get("camera", {})
    else:
        camera_cfgs= {
            "wrist_left":{
                "enable": True,
                "type": "RealSenseCameraRos2",
                "port": 4281,
                "host": "127.0.0.1",
            }
        }
    
    success_list = []
    fail_list = []
    for name, camera_cfg in camera_cfgs.items():
        print(f"Camera Name: {name}")
        camera = CameraZmqClient(host=camera_cfg["host"], port=int(camera_cfg["port"]))
        time.sleep(1)
        success = examples_read_realsense_camera(name, camera)
        if success:
            success_list.append(name)
        else:
            fail_list.append(name)
    print(f"success:{success_list}")
    print(f"fail:{fail_list}")