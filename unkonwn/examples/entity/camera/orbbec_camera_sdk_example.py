from __future__ import annotations

import time
import cv2

from xrocs.core.config_loader import ConfigLoader
from xrocs.entity.camera.Orbbec.orbbec_camera_sdk import OrbbecCameraSdk
from xrocs.utils.path_manager import path_manager
from xrocs.entity.camera.camera_loader import camera_loader
from xrocs.utils.camera_utils import CameraUtils

def examples_read_orbbec_camera(name: str, camera:OrbbecCameraSdk):
    # for name, camera in camera_dict.items():
    color_frame, depth_frame = camera.read()
    if color_frame is None or depth_frame is None:
        print(f"{name} 读取失败：未获得 RGB 或 Depth。")
        return False
    else:
        print(
            f"RGB shape: {color_frame.shape}, "
            f"Depth shape: {depth_frame.shape}, "
            f"FPS: {camera.fps:.2f}"
        )
        print(f"Camera Intrinsic: fx:{camera.fx}, fy:{camera.fy}, cx:{camera.cx}, cy:{camera.cy}")
    for _ in range(30):
        # Show img
        rgb_encoded, depth_encoded = camera.read(timeout=1.0, check_interval=0.1)
        decoded_color_image = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)
        cv2.imshow("Decoded Color Image", decoded_color_image)
        cv2.waitKey(1)
        time.sleep(0.1)
        
    return True

if __name__ == "__main__":
    auto_read_config = True
    if auto_read_config:
        cfg_loader = ConfigLoader(path_manager.config_toml_path)
        config = cfg_loader.get_config()
        camera_cfgs = config.get("camera", {})
    else:

        camera_cfgs= {
            "left_camera":{
                "enable": True,
                "type": "OrbbecCameraSdk",
                "camera_name": "left_camera",
                "serial": "CP7694500095"
            },
            "right_camera":{
                "enable": True,
                "type": "OrbbecCameraSdk",
                "camera_name": "right_camera",
                "serial": "CP728410002P"
            },
        }
    camera_dict = camera_loader.instantiate_cameras(camera_cfgs)

    success_list = []
    fail_list = []
    for name, camera in camera_dict.items():
        if name != "top":
            print(f"Camera Name: {name}")
            time.sleep(1)
            success = examples_read_orbbec_camera(name, camera)
            if success:
                success_list.append(name)
            else:
                fail_list.append(name)
    print(f"success:{success_list}")
    print(f"fail:{fail_list}")
