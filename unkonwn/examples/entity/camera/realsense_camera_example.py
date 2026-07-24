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
from xrocs.entity.camera.camera_loader import camera_loader
from xrocs.entity.camera.RealSense.realsense_camera_ros2 import RealSenseCameraRos2
from xrocs.utils.camera_utils import CameraUtils


def examples_read_realsense_camera(camera:RealSenseCameraRos2):
    rgb_encoded, depth_encoded = camera.read(timeout=1.0, check_interval=0.1)
    if rgb_encoded is None or depth_encoded is None:
        print(f"读取失败：未获得 RGB 或 Depth。")
        return

    print(
        f"RGB shape: {rgb_encoded.shape}, "
        f"Depth shape: {depth_encoded.shape}, "
    )

    decoded_color_image = CameraUtils.decode_color_image(rgb_encoded)
    decoded_depth_image = CameraUtils.decode_depth_image(depth_encoded)
    print(
        f"RGB decoded shape: {decoded_color_image.shape}, "
        f"Depth decoded shape: {decoded_depth_image.shape}, "
    )
    print(decoded_color_image)
    print(decoded_depth_image)

    depth_colormap = CameraUtils.apply_depth_colormap(depth_image=decoded_depth_image, color_map=cv2.COLORMAP_JET, normalize=True)

    cv2.imshow("Decoded Color Image", decoded_color_image)
    cv2.imshow("Depth Image", decoded_depth_image)
    cv2.imshow("Depth Colormap", depth_colormap)
    cv2.waitKey(5)
    cv2.imwrite("/home/eai/Data/camera_output_check.jpg", decoded_color_image)
    cv2.imwrite("/home/eai/Data/depth_check.png", decoded_depth_image)
    cv2.imwrite("/home/eai/Data/depth_colormap_check.jpg", depth_colormap)
    

if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        cfg_loader = ConfigLoader(path_manager.config_toml_path)
        config = cfg_loader.get_config()
        camera_cfgs = config.get("camera", {})
    else:
        camera_cfgs= {
            "head":{
                "enable": True,
                "type": "RealSenseCameraRos2",
                "camera_name": "camera1/camera1",
                # check 最少参数
                "port": 4278,
                "host": "127.0.0.1",
                "serial": 230422271167, # 替换为你的 RealSense 相机序列号
                "use_compress_rgb": True,
                "use_compress_depth": False,
            }
        }
    camera_dict = camera_loader.instantiate_cameras(camera_cfgs)
    time.sleep(1)
    for name, camera in camera_dict.items():
        print(f"Camera Name: {name}")
        examples_read_realsense_camera(camera)
        time.sleep(1)