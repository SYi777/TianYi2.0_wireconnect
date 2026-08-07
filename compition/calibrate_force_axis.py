#!/usr/bin/env python3
"""力控轴向标定 — 不依赖 TF，通过人工轻推确定插入轴向单位向量。

用法:
    python3 calibrate_force_axis.py

流程:
    1. 左臂摆到预插入姿态 → 静止 0.5s → 采集基线 F₀
    2. 沿插入方向 (base -Z) 轻推 TCP，约 1–3N
    3. 松手，确认力回到基线
    4. 计算 u = normalize(F_push - F₀)，保存到文件

输出:
    force_axis_cal.json  →  {"u": [ux, uy, uz], "f0": [fx, fy, fz, tx, ty, tz], ...}
"""

import json, math, os, sys, time, signal
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import WrenchStamped

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
OUTPUT_FILE = os.path.join(SCRIPT_DIR, "force_axis_cal.json")


class Calibrator(Node):
    def __init__(self):
        super().__init__("calibrate_force_axis")
        self._wrench = None
        self._wrench_at = 0.0
        self.create_subscription(WrenchStamped, "/arm_6dof_left", self._cb, 10)
        print("⏳ 等待 /arm_6dof_left 数据...")
        while rclpy.ok() and self._wrench is None:
            rclpy.spin_once(self, timeout_sec=0.1)
        print("✅ 六维力数据到达\n")

    def _cb(self, msg):
        w = msg.wrench
        self._wrench = [w.force.x, w.force.y, w.force.z,
                        w.torque.x, w.torque.y, w.torque.z]
        self._wrench_at = time.monotonic()

    def get_wrench(self, fresh=False):
        if self._wrench is None:
            return None
        if fresh and time.monotonic() - self._wrench_at > 0.1:
            return None
        return list(self._wrench)

    def _sample(self, label, duration, stable=False):
        """采集 duration 秒数据，返回平均力/力矩。

        stable=True 时要求力变化不超过阈值（确认静止），否则提示用户。"""
        samples = []
        t0 = time.monotonic()
        prev = self.get_wrench(fresh=True)
        stable_ok = False

        while time.monotonic() - t0 < duration:
            rclpy.spin_once(self, timeout_sec=0.02)
            w = self.get_wrench(fresh=True)
            if w is None:
                continue
            samples.append(w)

            if stable and len(samples) > 10:
                # 检查最近 0.2s 的力幅值抖动
                recent = samples[-10:]
                mags = [math.sqrt(s[0]**2 + s[1]**2 + s[2]**2) for s in recent]
                if max(mags) - min(mags) < 0.5:
                    stable_ok = True

            # 实时显示
            elapsed = time.monotonic() - t0
            fmag = math.sqrt(w[0]**2 + w[1]**2 + w[2]**2)
            bar = "█" * int(elapsed / duration * 20)
            print(f"\r  {label} [{bar:<20}] {elapsed:.1f}s  |F|={fmag:.2f}N  "
                  f"({'稳定' if stable_ok else '等待静止...'})",
                  end="", flush=True)

        print()
        if not samples:
            return None

        avg = [sum(s[i] for s in samples) / len(samples) for i in range(6)]
        std = [
            math.sqrt(sum((s[i] - avg[i])**2 for s in samples) / len(samples))
            for i in range(3)
        ]
        return avg, std


def main():
    rclpy.init()
    node = Calibrator()

    # ═══ 步骤 1: 采集基线 F₀ ═══
    print("━" * 50)
    print("步骤 1/3: 采集基线 F₀")
    print("  把左臂摆到预插入姿态，保持静止 0.5 秒")
    print("  按 Enter 开始采集...")
    input()
    print("  采集中，请保持静止...")
    result = node._sample("采集基线 F₀", 0.5, stable=True)
    if result is None:
        print("❌ 采集失败，无数据"); sys.exit(1)
    f0, std0 = result
    fmag0 = math.sqrt(f0[0]**2 + f0[1]**2 + f0[2]**2)
    print(f"  F₀ = [{f0[0]:.2f}, {f0[1]:.2f}, {f0[2]:.2f}] N  "
          f"|F₀|={fmag0:.2f}N  σ=[{std0[0]:.2f},{std0[1]:.2f},{std0[2]:.2f}]")

    # ═══ 步骤 2: 轻推采集 F_push ═══
    print("\n" + "━" * 50)
    print("步骤 2/3: 沿插入方向轻推 TCP")
    print("  保持 TCP 姿态不变，沿实际插入方向 (base -Z) 轻推")
    print("  目标力: 1–3N (不要超过 5N)")
    print("  推稳后按 Enter 开始采集 (采集 0.5 秒)...")
    input()
    result = node._sample("采集 F_push", 0.5)
    if result is None:
        print("❌ 采集失败"); sys.exit(1)
    f_push, _ = result
    fmag_push = math.sqrt(f_push[0]**2 + f_push[1]**2 + f_push[2]**2)

    # ═══ 验证推力 ═══
    d = [f_push[i] - f0[i] for i in range(3)]
    dmag = math.sqrt(d[0]**2 + d[1]**2 + d[2]**2)
    print(f"  F_push = [{f_push[0]:.2f}, {f_push[1]:.2f}, {f_push[2]:.2f}] N  "
          f"|F_push|={fmag_push:.2f}N")
    print(f"  ΔF = [{d[0]:.2f}, {d[1]:.2f}, {d[2]:.2f}] N  "
          f"|ΔF|={dmag:.2f}N")
    if dmag < 0.5:
        print(f"  ⚠ ΔF 仅 {dmag:.2f}N，推力太轻，建议重来 (目标 1–3N)")
    elif dmag > 5.0:
        print(f"  ⚠ ΔF 达 {dmag:.2f}N，推力太重，建议重来 (目标 1–3N)")
    else:
        print(f"  ✅ 推力范围正常")

    # ═══ 步骤 3: 松手确认 ═══
    print("\n" + "━" * 50)
    print("步骤 3/3: 松手确认")
    print("  轻轻松手，不要移动 TCP")
    print("  按 Enter 开始采集...")
    input()
    result = node._sample("松手确认", 0.5, stable=True)
    if result is None:
        print("❌ 采集失败"); sys.exit(1)
    f_rel, _ = result
    fmag_rel = math.sqrt(f_rel[0]**2 + f_rel[1]**2 + f_rel[2]**2)
    d_rel = math.sqrt((f_rel[0]-f0[0])**2 + (f_rel[1]-f0[1])**2 + (f_rel[2]-f0[2])**2)
    print(f"  F_rel = [{f_rel[0]:.2f}, {f_rel[1]:.2f}, {f_rel[2]:.2f}] N  "
          f"|F|={fmag_rel:.2f}N  距基线={d_rel:.2f}N")
    if d_rel < 0.5:
        print("  ✅ 力已回到基线附近")
    else:
        print(f"  ⚠ 松手后力距基线 {d_rel:.2f}N，可能 TCP 还有接触，建议重试")

    # ═══ 计算 u ═══
    u = [d[0] / dmag, d[1] / dmag, d[2] / dmag] if dmag > 1e-6 else [0, 0, -1]

    # 保存
    data = {
        "f0": f0,
        "f_push": f_push,
        "u": u,
        "delta_mag": dmag,
        "comment": "u = normalize(F_push - F0)，在传感器坐标系下的插入轴向单位向量",
    }
    with open(OUTPUT_FILE, "w") as fh:
        json.dump(data, fh, indent=2)
    print(f"\n{'━' * 50}")
    print(f"✅ 标定完成")
    print(f"  轴向单位向量 u = [{u[0]:.4f}, {u[1]:.4f}, {u[2]:.4f}]")
    print(f"  已保存到: {OUTPUT_FILE}")
    print(f"\n  使用时: F_axial = (F_current - F₀) · u")
    print(f"  F_axial > 0 = 压紧方向, F_axial < 0 = 松脱方向")

    node.destroy_node()
    rclpy.try_shutdown()


if __name__ == "__main__":
    main()
