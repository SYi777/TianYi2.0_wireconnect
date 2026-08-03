#!/usr/bin/env python3
"""Convert rosbag → LeRobot v2 format.

Output structure:
  {output_dir}/
    meta/info.json
    meta/stats.json
    data/chunk-000/
      episode_000000.parquet        (state + action tensors)
      observation.images.head/episode_000000/000001.jpg
      observation.images.wrist_r/episode_000000/000001.jpg
      observation.images.wrist_l/episode_000000/000001.jpg

Each row in parquet:
  observation.state      — [tcp(7) + wrench(6)] = 13 dims, repeated obs_window times
  action                 — [tcp(7)] target TCP pose
  episode_index          — 0
  frame_index            — 0, 1, 2, ...
  timestamp              — nanoseconds

Usage:
    python3 bag_to_lerobot.py ~/bags/ep_0001 --output ~/lerobot_data --obs-window 5
"""

import os, sys, json, math, argparse
import numpy as np
from collections import defaultdict

import cv2
from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions
from rclpy.serialization import deserialize_message

from sensor_msgs.msg import Image as ImageMsg
from geometry_msgs.msg import WrenchStamped, PoseStamped


TOPIC_HEAD  = "/ob_camera_head/color/image_raw"
TOPIC_WRIST_R = "/camera_wrist/camera_wrist/color/image_rect_raw"
TOPIC_WRIST_L = "/camera_wrist_left/camera_wrist_left/color/image_rect_raw"
TOPIC_FT     = "/arm_6dof_left"
TOPIC_TCP    = "/tcp_pose"

CAMERA_KEYS = ["head", "wrist_r", "wrist_l"]


def read_bag(bag_dir: str) -> dict:
    """Read all frames from bag, return dict of {topic: [(stamp_ns, data), ...]}."""
    reader = SequentialReader()
    reader.open(StorageOptions(uri=bag_dir, storage_id="sqlite3"),
                ConverterOptions(input_serialization_format="cdr",
                                 output_serialization_format="cdr"))

    streams = defaultdict(list)
    while reader.has_next():
        topic, msg, stamp = reader.read_next()
        streams[topic].append((stamp, msg))

    return streams


def decode_image(topic: str, msg_bytes: bytes):
    """Decode raw Image msg bytes to BGR numpy array."""
    img_msg = deserialize_message(msg_bytes, ImageMsg)
    data = bytes(img_msg.data)
    if img_msg.encoding == "rgb8":
        frame = np.frombuffer(data, np.uint8).reshape(img_msg.height, img_msg.width, 3)
        return cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
    elif img_msg.encoding == "bgr8":
        return np.frombuffer(data, np.uint8).reshape(img_msg.height, img_msg.width, 3)
    else:
        return np.frombuffer(data, np.uint8).reshape(img_msg.height, img_msg.width, -1)

def parse_tcp(msg_bytes: bytes) -> list:
    """Parse PoseStamped → [x, y, z, qx, qy, qz, qw]."""
    msg = deserialize_message(msg_bytes, PoseStamped)
    p, o = msg.pose.position, msg.pose.orientation
    return [p.x, p.y, p.z, o.x, o.y, o.z, o.w]


def parse_ft(msg_bytes: bytes) -> list:
    """Parse WrenchStamped → [fx, fy, fz, tx, ty, tz]."""
    msg = deserialize_message(msg_bytes, WrenchStamped)
    f, t = msg.wrench.force, msg.wrench.torque
    return [f.x, f.y, f.z, t.x, t.y, t.z]


def align_frames(streams: dict) -> list:
    """Align all topics by timestamp, return sorted list of frames."""
    # Use head camera as master (30Hz). For each head frame, find closest
    # wrist/ft/hand/tcp measurement.
    head_frames = streams.get(TOPIC_HEAD, [])
    wrist_r = streams.get(TOPIC_WRIST_R, [])
    wrist_l = streams.get(TOPIC_WRIST_L, [])
    ft = streams.get(TOPIC_FT, [])
    tcp = streams.get(TOPIC_TCP, [])

    frames = []
    for h_stamp, h_msg in head_frames:
        frame = {"stamp": h_stamp, "head": h_msg}
        # closest match within 50ms
        for key, stream in [("wrist_r", wrist_r), ("wrist_l", wrist_l),
                            ("ft", ft), ("tcp", tcp)]:
            best = None
            for s, m in stream:
                if abs(s - h_stamp) < 50_000_000:  # 50ms
                    if best is None or abs(s - h_stamp) < abs(best[0] - h_stamp):
                        best = (s, m)
            if best:
                frame[key] = best[1]
        frames.append(frame)
    return frames


def build_episode(frames: list, obs_window: int, output_dir: str, ep_idx: int):
    """Build LeRobot episode from aligned frames."""
    import pandas as pd

    # directories
    ep_dir = os.path.join(output_dir, f"episode_{ep_idx:06d}")
    img_dirs = {
        "head":    os.path.join(ep_dir, "observation.images.head", f"episode_{ep_idx:06d}"),
        "wrist_r": os.path.join(ep_dir, "observation.images.wrist_r", f"episode_{ep_idx:06d}"),
        "wrist_l": os.path.join(ep_dir, "observation.images.wrist_l", f"episode_{ep_idx:06d}"),
    }
    for d in img_dirs.values():
        os.makedirs(d, exist_ok=True)

    rows = []
    for i in range(obs_window, len(frames)):
        obs_frames = frames[i - obs_window:i]
        act_frame = frames[i]

        # save images for obs frames
        for j, f in enumerate(obs_frames):
            idx = i - obs_window + j
            for cam_key in CAMERA_KEYS:
                if cam_key in f:
                    img = decode_image(
                        TOPIC_HEAD if cam_key == "head" else
                        TOPIC_WRIST_R if cam_key == "wrist_r" else TOPIC_WRIST_L,
                        f[cam_key])
                    img_path = os.path.join(img_dirs[cam_key], f"{idx:06d}.jpg")
                    cv2.imwrite(img_path, img, [cv2.IMWRITE_JPEG_QUALITY, 90])

        # state vector: obs_window × [tcp(7) + ft(6)] = obs_window × 13
        state = []
        for f in obs_frames:
            tcp_vec = parse_tcp(f.get("tcp", b"")) if "tcp" in f else [0.0]*7
            ft_vec  = parse_ft(f.get("ft", b"")) if "ft" in f else [0.0]*6
            state.extend(tcp_vec + ft_vec)

        # action: target TCP pose
        action = parse_tcp(act_frame.get("tcp", b"")) if "tcp" in act_frame else [0.0]*7

        rows.append({
            "observation.state": state,
            "action": action,
            "episode_index": ep_idx,
            "frame_index": i - obs_window,
            "timestamp": act_frame["stamp"],
        })

    # save parquet
    df = pd.DataFrame(rows)
    os.makedirs(os.path.join(ep_dir, "data"), exist_ok=True)
    df.to_parquet(os.path.join(ep_dir, "data", "episode_data.parquet"))

    return len(rows)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("bag_dir")
    parser.add_argument("--output", default="./lerobot_data")
    parser.add_argument("--obs-window", type=int, default=5)
    parser.add_argument("--fps", type=int, default=30)
    args = parser.parse_args()

    print(f"Reading {args.bag_dir}...")
    streams = read_bag(args.bag_dir)
    print(f"  topics: {list(streams.keys())}")

    head_count = len(streams.get(TOPIC_HEAD, []))
    print(f"  head frames: {head_count}")

    print("Aligning frames...")
    frames = align_frames(streams)
    print(f"  aligned: {len(frames)} frames")

    if len(frames) <= args.obs_window:
        print(f"ERROR: need > {args.obs_window} frames, got {len(frames)}")
        sys.exit(1)

    print("Building episode...")
    n = build_episode(frames, args.obs_window, args.output, 0)
    print(f"  samples: {n}")

    # meta
    os.makedirs(os.path.join(args.output, "meta"), exist_ok=True)
    with open(os.path.join(args.output, "meta", "info.json"), "w") as f:
        json.dump({
            "fps": args.fps,
            "obs_window": args.obs_window,
            "state_dim": args.obs_window * 13,  # tcp(7) + ft(6) per obs frame
            "action_dim": 7,
            "camera_keys": CAMERA_KEYS,
        }, f, indent=2)

    print(f"\nDone → {args.output}")


if __name__ == "__main__":
    main()
