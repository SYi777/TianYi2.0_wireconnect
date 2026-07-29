#!/usr/bin/env python3
"""
Load hand gesture presets and convert to MoveIt joint targets or inspire SDK commands.

Usage:
    from hand_gestures import load_gesture, list_gestures
    joints = load_gesture("cable_grasp", side="left")
    # joints = {"left_thumb_1_joint": 0.50, "left_thumb_2_joint": 0.19, ...}
"""

import os
import yaml

_PKG_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
_CONFIG_PATH = os.path.join(_PKG_DIR, "config", "hand_gestures.yaml")

# URDF joint names in gesture array order
_JOINT_ORDER = ["thumb_1", "thumb_2", "index_1", "middle_1", "ring_1", "little_1"]


def _load():
    with open(_CONFIG_PATH) as f:
        return yaml.safe_load(f)["gestures"]


def list_gestures():
    """Return list of available gesture names."""
    return list(_load().keys())


def gesture_info(name: str) -> dict:
    """Return raw gesture dict with description, left, right."""
    g = _load()
    if name not in g:
        raise KeyError(f"Unknown gesture '{name}'. Available: {list(g.keys())}")
    return g[name]


def load_gesture(name: str, side: str = "left") -> dict:
    """
    Return a {joint_name: value_rad} dict for MoveIt setJointValueTarget.

    Args:
        name: gesture name (open, cable_grasp, usb_grasp, fist)
        side: 'left' or 'right'

    Returns:
        dict mapping full URDF joint names to radian values
    """
    g = gesture_info(name)
    values = g[side]
    prefix = f"{side}_"
    return {f"{prefix}{j}": v for j, v in zip(_JOINT_ORDER, values)}


def load_gesture_array(name: str, side: str = "left") -> list:
    """
    Return gesture as a flat list of radian values in SDK order:
    [little, ring, middle, index, thumb_bend, thumb_rotate]

    This matches inspire SDK finger IDs (1-6).
    """
    g = gesture_info(name)
    values = g[side]
    # Gesture array order: [thumb_1, thumb_2, index_1, middle_1, ring_1, little_1]
    # SDK order:   [1=little, 2=ring, 3=middle, 4=index, 5=thumb_bend, 6=thumb_rotate]
    return [
        values[5],  # little_1  → SDK ID 1
        values[4],  # ring_1    → SDK ID 2
        values[3],  # middle_1  → SDK ID 3
        values[2],  # index_1   → SDK ID 4
        values[0],  # thumb_1   → SDK ID 5
        values[1],  # thumb_2   → SDK ID 6
    ]
