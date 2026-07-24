"""TienYi 2.0 Pro head Orbbec camera example (via station)."""

from __future__ import annotations

from xrocs.tests.TienYi2Pro._common import build_station, shutdown_station
from xrocs.utils.camera_utils import CameraUtils
from xrocs.utils.logger.logger_loader import logger


def example_camera_read(name: str, camera) -> None:
    """Read one frame from a single camera and decode the RGB image."""
    rgb_encoded, depth_encoded = camera.read(timeout=2.0, check_interval=0.1)

    if rgb_encoded is None:
        logger.error(f"camera '{name}' returned no RGB frame. Check the camera topic.")
        return
    print("rgb encoded shape", rgb_encoded.shape)
    print("depth encoded shape", None if depth_encoded is None else depth_encoded.shape)

    rgb_decoded = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)
    print("rgb decoded shape", rgb_decoded.shape)

    import cv2
    rgb_decoded_bgr = cv2.cvtColor(rgb_decoded, cv2.COLOR_RGB2BGR)
    cv2.imwrite("camera_output_check.jpg", rgb_decoded_bgr)


def example_camera_state(station) -> None:
    """Read all cameras at once through the station aggregate API."""
    images, depths = station.get_camera_state()
    for name, img in images.items():
        print(f"[{name}] image / depth",
             f"{None if img is None else img.shape} / "
             f"{None if depths.get(name) is None else depths[name].shape}")


def main() -> None:
    station = None
    try:
        station = build_station()
        cameras = station.get_camera_handle()

        for name, camera in cameras.items():
            example_camera_read(name, camera)
        example_camera_state(station)
        logger.success("Camera examples finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
