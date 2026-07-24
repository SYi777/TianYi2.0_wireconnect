#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import signal

import introspect_utils
from introspect_utils import logger


def get_children_processes(ppid) -> list[int]:
    children = []
    for entry in os.listdir("/proc"):
        if not entry.isdigit():
            continue
        pid = int(entry)
        if pid <= ppid:
            continue
        with open(f"/proc/{pid}/stat", "r") as f:
            stat_info = f.read().split()
            if int(stat_info[3]) == ppid:
                children.append(pid)
    return children


def kill_process(pid):
    try:
        # 尝试发送SIGINT信号（类似Ctrl+C）
        os.kill(pid, signal.SIGINT)
        logger.info(f"已向进程 {pid} 发送 SIGINT 信号")

        # 如果SIGINT无法终止，可尝试更强的SIGTERM（默认终止信号）
        # os.kill(pid, signal.SIGTERM)

        # 极端情况可使用SIGKILL（强制终止，无法被进程捕获）
        # os.kill(pid, signal.SIGKILL)

    except PermissionError:
        logger.error(f"错误：没有权限终止进程 {pid}（可能需要root权限）")
        return
    except ProcessLookupError:
        logger.error(f"错误：进程 {pid} 不存在")
        return
    except Exception as e:
        logger.error(f"杀死进程失败：{str(e)}")
        return

    def predict_killed() -> bool:
        try:
            # 向进程发送0信号（不做任何操作，仅用于检查进程是否存在）
            os.kill(pid, 0)
            return False
        except OSError:
            print("", flush=True)
            return True

    introspect_utils.countdown(30, predict_killed)


def get_body_process() -> int:
    for entry in os.listdir("/proc"):
        if not entry.isdigit():
            continue

        pid = int(entry)
        # print(f"Checking PID {pid}")

        if pid < 1000:
            continue

        with open(f"/proc/{pid}/stat", "r") as f:
            stat_info = f.read().split()
            ppid = int(stat_info[3])
            if ppid < 3:
                continue

        try:
            with open(f"/proc/{pid}/cmdline", "rb") as f:
                content = f.read()

            cmdline = content.replace(b"\x00", b" ").decode("utf-8").rstrip()
            # print(f"Checking PID {pid} with cmdline: {cmdline}")

            if "/opt/ros/humble/bin/ros2 launch body_control" in cmdline:
                return pid

        except FileNotFoundError:
            continue
        except Exception as e:
            logger.error(f"Error reading /proc/{pid}/cmdline: {e}")
            continue

    return 0


def has_body_process() -> bool:
    pid = get_body_process()
    return pid > 0


def kill_body_process():
    pid = get_body_process()
    if pid <= 0:
        return

    logger.info("尝试杀死进程:%d", pid)
    kill_process(pid)
