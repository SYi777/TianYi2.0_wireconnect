"""Example script demonstrating the usage of Orbbec camera driver.

This script shows how to:
1. Initialize and connect to Orbbec cameras
2. Read RGB and depth images
3. Decode and display images
4. Use both single and continuous publishing modes

Changelog:
    - 2025-12-12 (Harvey Liu): Create Orbbec camera example script.
"""

from __future__ import annotations

import time
import cv2

from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.entity.camera.camera_loader import camera_loader
from xrocs.entity.camera.Orbbec.orbbec_camera_ros2 import OrbbecCameraRos2
from xrocs.utils.camera_utils import CameraUtils



def examples_read_orbbec_camera(name: str, camera:OrbbecCameraRos2):
    rgb_encoded, depth_encoded = camera.read(timeout=1.0,check_interval=0.1)
    if rgb_encoded is None or depth_encoded is None:
        print(f"{name} 读取失败：未获得 RGB 或 Depth。")
        return False

    else:
        print(
            f"RGB shape: {rgb_encoded.shape}, "
            f"Depth shape: {depth_encoded.shape}, "
        )

        decoded_color_image = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)
        print(
            f"RGB decoded shape: {decoded_color_image.shape}, "
        )

    for _ in range(30):
        rgb_encoded, depth_encoded = camera.read(timeout=1.0,check_interval=0.1)
        decoded_color_image = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)
        cv2.imshow("Decoded Color Image", decoded_color_image)
        cv2.waitKey(1)
        # cv2.imwrite(os.path.expanduser(f"~/Data/camera_{name}_output_check.jpg"), decoded_color_image)
        time.sleep(0.1)

    return True
    

if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        cfg_loader = ConfigLoader(path_manager.config_toml_path)
        config = cfg_loader.get_config()
        camera_cfgs = config.get("camera", {})
    else:
        camera_cfgs= {
            "top_left_camera":{
                "enable": True,
                "type": "OrbbecCameraRos2",
                "camera_name": "top_left_camera",
                "use_compress_rgb": True,
                "use_compress_depth": True,
            },
            "top_right_camera":{
                "enable": True,
                "type": "OrbbecCameraRos2",
                "camera_name": "top_right_camera",
                "use_compress_rgb": True,
                "use_compress_depth": True,
            },
            "left_camera":{
                "enable": True,
                "type": "OrbbecCameraRos2",
                "camera_name": "left_camera",
                "use_compress_rgb": True,
                "use_compress_depth": True,
            },
            "right_camera":{
                "enable": True,
                "type": "OrbbecCameraRos2",
                "camera_name": "right_camera",
                "use_compress_rgb": True,
                "use_compress_depth": True,
            },
            "wrist_camera":{
                "enable": True,
                "type": "OrbbecCameraRos2",
                "camera_name": "wrist_camera",
                "use_compress_rgb": True,
                "use_compress_depth": True,
            }
        }
    camera_dict = camera_loader.instantiate_cameras(camera_cfgs)
    time.sleep(1)
    success_list = []
    fail_list = []
    for name, camera in camera_dict.items():
        print(f"Camera Name: {name}")
        time.sleep(1)
        success = examples_read_orbbec_camera(name, camera)
        if success:
            success_list.append(name)
        else:
            fail_list.append(name)
    print(f"success:{success_list}")
    print(f"fail:{fail_list}")