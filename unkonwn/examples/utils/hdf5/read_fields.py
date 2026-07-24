"""Read data from specific fields in an HDF5 file.

Changelog:
    - 2026-01-05 (Chris Ren): Initial implementation.
"""

from __future__ import annotations

import cv2
import h5py
from pathlib import Path

from typing import List


def read_h5_fields(file_path: str, field_paths: List[str]):
    """Read data from specific fields in an HDF5 file.
    
    Args:
        file_path: Path to the HDF5 file.
        field_paths: List of paths to the fields.
    
    Returns:
        The data stored in the fields.
    """
    with h5py.File(file_path, 'r') as f:
        return [f[field_path][()] for field_path in field_paths]


def save_color_data(color_data, output_path: Path) -> None:
    """Save color data to images.

    Args:
        color_data: Color data to save.
        output_path: Path to save the images.
    """
    for idx, encoded_color_image in enumerate(color_data):
        decoded_bgr_color_image = cv2.imdecode(encoded_color_image, cv2.IMREAD_COLOR)
        cv2.imwrite(str(output_path / "rgb" / f"{idx:04d}.png"), decoded_bgr_color_image)

def save_depth_data(depth_data, output_path: Path) -> None:
    """Save depth data to images.

    Args:
        depth_data: Depth data to save.
        output_path: Path to save the images.
    """
    for idx, encode_depth_uint16_image in enumerate(depth_data):
        depth_uint16_image = cv2.imdecode(encode_depth_uint16_image, cv2.IMREAD_UNCHANGED)
        cv2.imwrite(str(output_path / "depth" / f"{idx:04d}.png"), depth_uint16_image)


def main() -> None:
    h5_file_path = "trajectory.hdf5"
    field_paths = ["master/arm_left_position_align/data", "camera_observations/color_images/camera_head", "camera_observations/depth_images/camera_head"]
    master_arm_left_position_align_data, camera_head_color_images, camera_head_depth_images = read_h5_fields(h5_file_path, field_paths)

    print("Master arm left position align data:")
    print(f"- Shape: {master_arm_left_position_align_data.shape}")
    print(f"- Dtype: {master_arm_left_position_align_data.dtype}")
    print(f"- Data: {master_arm_left_position_align_data[0]}")

    output_path = Path("./output_images")
    (output_path / "rgb").mkdir(parents=True, exist_ok=True)
    (output_path / "depth").mkdir(parents=True, exist_ok=True)

    save_color_data(color_data=camera_head_color_images, output_path=output_path)
    save_depth_data(depth_data=camera_head_depth_images, output_path=output_path)


if __name__ == "__main__":
    main()
