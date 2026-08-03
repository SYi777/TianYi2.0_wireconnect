#!/usr/bin/env python3
"""Validate recorded dataset — timestamp alignment & frame consistency.

Raw bag contains: 3 cameras, wrench, hand, TCP — no pre-assembled obs/act.
Checks: topic presence, frame count, timestamp drift, 30Hz sync health.
"""

import sys
import os
from collections import defaultdict

EXPECTED = {
    "/ob_camera_head/color/image_raw":
        "sensor_msgs/msg/Image",
    "/camera_wrist_left/camera_wrist_left/color/image_rect_raw":
        "sensor_msgs/msg/Image",
    "/camera_wrist/camera_wrist/color/image_rect_raw":
        "sensor_msgs/msg/Image",
    "/arm_6dof_left":
        "geometry_msgs/msg/WrenchStamped",
    "/tcp_pose":
        "geometry_msgs/msg/PoseStamped",
}


def check_bag(bag_dir: str, obs_window: int = 5) -> dict:
    from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions

    reader = SequentialReader()
    storage = StorageOptions(uri=bag_dir, storage_id="sqlite3")
    reader.open(storage, ConverterOptions(
        input_serialization_format="cdr", output_serialization_format="cdr"))

    metadata = reader.get_all_topics_and_types()
    topics_in_bag = {m.name: m.type for m in metadata}

    report = {"ok": True, "issues": [], "stats": {}}

    # ── check topics ──────────────────────────────────────────────
    for exp_topic, exp_type in EXPECTED.items():
        if exp_topic not in topics_in_bag:
            report["issues"].append(f"MISSING: {exp_topic}")
            report["ok"] = False
        elif topics_in_bag[exp_topic] != exp_type:
            report["issues"].append(
                f"TYPE mismatch: {exp_topic}  {topics_in_bag[exp_topic]} ≠ {exp_type}")

    # ── count messages ────────────────────────────────────────────
    counts = defaultdict(int)
    timestamps = defaultdict(list)
    sizes = defaultdict(int)

    while reader.has_next():
        topic, msg, stamp = reader.read_next()
        counts[topic] += 1
        timestamps[topic].append(stamp)

    report["stats"]["message_counts"] = dict(counts)

    # ── timestamp alignment ───────────────────────────────────────
    # head camera is the 30Hz sync master
    head_stamps = timestamps.get("/ob_camera_head/color/image_raw", [])
    wrist_r_stamps = timestamps.get("/camera_wrist/camera_wrist/color/image_rect_raw", [])
    wrist_l_stamps = timestamps.get("/camera_wrist_left/camera_wrist_left/color/image_rect_raw", [])
    ft_stamps = timestamps.get("/arm_6dof_left", [])
    tcp_stamps = timestamps.get("/tcp_pose", [])

    report["stats"]["head_frames"] = len(head_stamps)
    report["stats"]["wrist_r_frames"] = len(wrist_r_stamps)
    report["stats"]["wrist_l_frames"] = len(wrist_l_stamps)
    report["stats"]["ft_samples"] = len(ft_stamps)
    report["stats"]["tcp_samples"] = len(tcp_stamps)

    # overall duration
    all_stamps = [s for s_list in timestamps.values() for s in s_list]
    if all_stamps:
        min_ns, max_ns = min(all_stamps), max(all_stamps)
        report["stats"]["duration_s"] = round((max_ns - min_ns) / 1e9, 2)
        report["stats"]["head_fps"] = round(len(head_stamps) / report["stats"]["duration_s"], 1) \
            if report["stats"]["duration_s"] > 0 else 0

    # frame rate sanity (camera should be ~30fps)
    if report["stats"]["duration_s"] > 0:
        for name, stamps in [("head", head_stamps), ("wrist_r", wrist_r_stamps),
                             ("wrist_l", wrist_l_stamps)]:
            if stamps:
                fps = round(len(stamps) / report["stats"]["duration_s"], 1)
                report["stats"][f"{name}_fps"] = fps
                if fps < 25:
                    report["issues"].append(f"{name} camera low FPS: {fps} (expected ~30)")

    # timestamp drift between cameras
    if head_stamps and wrist_r_stamps:
        drift_start = abs(head_stamps[0] - wrist_r_stamps[0]) / 1e6
        drift_end = abs(head_stamps[-1] - wrist_r_stamps[-1]) / 1e6
        report["stats"]["head_vs_wrist_r_drift_ms"] = round(max(drift_start, drift_end), 2)

    if head_stamps and wrist_l_stamps:
        drift_start = abs(head_stamps[0] - wrist_l_stamps[0]) / 1e6
        drift_end = abs(head_stamps[-1] - wrist_l_stamps[-1]) / 1e6
        report["stats"]["head_vs_wrist_l_drift_ms"] = round(max(drift_start, drift_end), 2)

    # obs capacity check
    report["stats"]["obs_window"] = obs_window
    if head_stamps:
        report["stats"]["usable_samples"] = max(0, len(head_stamps) - obs_window)
        if report["stats"]["usable_samples"] < 10:
            report["issues"].append(
                f"Only {report['stats']['usable_samples']} usable samples "
                f"(need obs_window={obs_window}+1 — record longer)")

    return report


def print_report(report: dict):
    GREEN = "\033[32m"; RED = "\033[31m"; RESET = "\033[0m"

    print(f"\n{'='*60}")
    status = f"{GREEN}PASS{RESET}" if report["ok"] else f"{RED}FAIL{RESET}"
    print(f"  Dataset check: {status}")
    print(f"{'='*60}")

    print(f"\n  ── Stats ──")
    for k, v in sorted(report.get("stats", {}).items()):
        print(f"  {k}: {v}")

    if report["issues"]:
        print(f"\n  ── Issues ({len(report['issues'])}) ──")
        for issue in report["issues"]:
            print(f"  {RED}✗{RESET} {issue}")
    else:
        print(f"\n  {GREEN}✓ All checks passed{RESET}")

    print()
    return report["ok"]


def main():
    if len(sys.argv) < 2:
        print(f"Usage: ros2 run data_collect check_dataset <bag_dir> [--obs-window N]")
        sys.exit(1)

    bag_dir = sys.argv[1]
    obs_window = 5
    for i, arg in enumerate(sys.argv):
        if arg == "--obs-window" and i + 1 < len(sys.argv):
            obs_window = int(sys.argv[i + 1])

    if not os.path.isdir(bag_dir):
        print(f"Error: {bag_dir} not found")
        sys.exit(1)

    report = check_bag(bag_dir, obs_window)
    ok = print_report(report)
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
