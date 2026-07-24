#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import re
import shutil
import subprocess

import yaml

import introspect_proc
import introspect_utils
from introspect_utils import logger

config_file = "u2c_sn.yaml"

data_dir = os.path.join("/home/ubuntu", "data")
param_dir = os.path.join(data_dir, "param")
config_path = os.path.join(param_dir, config_file)


def copy_config_file_if_absent():
    dst_config_path = config_path
    if os.path.exists(dst_config_path):
        logger.info("-" * 64)
        logger.info("配置文件已经存在:%s", dst_config_path)
        logger.info("-" * 64)
        introspect_utils.cat_file(dst_config_path)
        logger.info("-" * 64)
        return

    script_dir = os.path.dirname(__file__)
    workspace_dir = script_dir
    while workspace_dir != "/":
        if os.path.basename(workspace_dir) == "ros2ws":
            break
        workspace_dir = os.path.dirname(workspace_dir)

    if workspace_dir == "/":
        logger.info("配置文件未找到")
        exit(1)

    body_control_dir = os.path.join(workspace_dir, "install", "body_control")

    logger.info("从 ROS 包目录中查找配置文件，ROS 包目录:%s", body_control_dir)

    for dir_path, dir_names, file_names in os.walk(body_control_dir):
        if config_file in file_names:
            src_config_path = os.path.join(dir_path, config_file)
            if not os.path.exists(param_dir):
                os.makedirs(param_dir)
                introspect_utils.modify_file_owner(data_dir)
                introspect_utils.modify_file_owner(param_dir)
            shutil.copy2(src_config_path, dst_config_path)
            introspect_utils.modify_file_owner(dst_config_path)
            logger.info("-" * 64)
            logger.info("配置文件拷贝完成")
            logger.info(">> src:%s", src_config_path)
            logger.info(">> dst:%s", dst_config_path)
            logger.info("-" * 64)
            introspect_utils.cat_file(dst_config_path)
            logger.info("-" * 64)
            return
    logger.info("配置文件未找到")
    exit(1)


def load_config_file(file_path) -> dict | None:
    try:
        # 以只读模式打开文件并解析
        with open(file_path, "r", encoding="utf-8") as file:
            # safe_load 方法会将YAML数据转换为对应的Python数据结构
            data = yaml.safe_load(file)

            # 检查解析结果是否为字典
            if isinstance(data, dict):
                return data
            else:
                logger.warning(f"警告：YAML文件内容不是字典类型")
                logger.warning(f"警告：实际类型为 {type(data)}")
                return data

    except yaml.YAMLError as e:
        logger.error(f"YAML解析错误：{e}")
    except Exception as e:
        logger.error(f"读取文件时出错：{e}")

    return None


def parse_serial_nums(file_path: str) -> list[str] | None:
    config = load_config_file(file_path)
    if config is None:
        return None
    if "u2c_sn" not in config:
        return None
    return config["u2c_sn"]


def update_serial_nums(file_path: str, data: list[str]) -> None:
    with open(file_path, "r", encoding="utf-8") as in_file:
        lines = in_file.readlines()

        cursor = -1
        for index, line in enumerate(lines):
            if "u2c_sn:" in line:
                cursor = index + 1
                break
        if cursor == -1:
            return

        for i in range(len(data)):
            lines[cursor + i] = f"  - {data[i]}\n"

        with open(file_path, "w", encoding="utf-8") as out_file:
            out_file.writelines(lines)

        logger.info("-" * 64)
        introspect_utils.cat_file(file_path)
        logger.info("-" * 64)


def check_and_update_config():
    # 序列号的顺序定义如下
    # 头，腰，腿
    # 左臂
    # 右臂
    # 手，六维力，电源板

    bash_cmd = """
        source "/home/ubuntu/ros2ws/install/setup.bash" && 
        stdbuf -oL ros2 launch body_control body.launch.py
        """
    command = ["sudo", "bash", "-c", bash_cmd]

    keyword_serial_num = ">>Serial_Num:"

    ##
    # 先运行一次程序，读取序列号
    ##

    # 从固件中读取到的序列号
    firmware_serial_nums = []

    process = None
    try:
        # 启动进程，重定向标准输出和标准错误
        process = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,  # 将 stderr 合并到 stdout
            bufsize=1,  # 启用行缓冲模式
            universal_newlines=True,  # 文本模式，将输出转换为字符串而非字节
            text=True,
        )

        logger.info(f"正在运行命令: {' '.join(command)}")
        logger.info("输出内容:")
        logger.info("-" * 64)

        # 按行读取输出
        for line in process.stdout:
            # 去除行尾的换行符，但保留其他空白字符
            line = line.rstrip("\n")
            logger.info(f"[输出] {line}")

            if keyword_serial_num in line:
                striped_line = introspect_utils.remove_all_whitespace(line)
                r_idx_comma = striped_line.rfind(":")
                sn = striped_line[r_idx_comma + 1: r_idx_comma + 12]
                firmware_serial_nums.append(sn)

                if len(firmware_serial_nums) >= 4:
                    break

    except FileNotFoundError:
        logger.error(f"错误: 未找到命令 {' '.join(command)}")
        return
    except Exception as e:
        logger.error(f"执行命令时发生错误: {str(e)}")
        return
    finally:
        introspect_proc.kill_body_process()
        if process is not None and process.poll() is None:
            introspect_proc.kill_process(process.pid)

    if len(firmware_serial_nums) < 4:
        logger.error("读取序列号失败")
        logger.error("读取序列号失败")
        logger.error("读取序列号失败")
        return

    ##
    # 测试每一个组合
    ##

    all_nums = introspect_utils.get_all_permutations(firmware_serial_nums)
    nums_count = len(all_nums)

    logger.info("=" * 64)
    logger.info("读取到的序列号:%s", firmware_serial_nums)
    logger.info("所有组合的个数:%d", nums_count)
    logger.info("=" * 64)

    introspect_utils.countdown(10)

    keyword_all_devices_ready = "All devices ready"
    keyword_some_devices_not_ready = "Some devices not ready, devices state:"

    error_keywords = [
        "enable motor failed, error:",
        "disable motor failed, error:",
        "6dof lost connection, id:",
    ]
    error_patterns = [
        r"motor \d+ error:",
        r"motor \d+ unknow error:",
    ]

    for nums in all_nums:
        logger.info("~" * 64)
        logger.info("测试序列号组合:%s", nums)
        logger.info("~" * 64)

        update_serial_nums(config_path, nums)

        all_devices_ready = False
        parsed_errors = []  # 抓捕到的需要终止程序的错误信息
        motor_states = []

        met_device_state = False
        lines_after_device_state = 0

        process = None
        try:
            introspect_utils.countdown(10)

            # 启动进程，重定向标准输出和标准错误
            process = subprocess.Popen(
                command,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,  # 将 stderr 合并到 stdout
                bufsize=1,  # 启用行缓冲模式
                universal_newlines=True,  # 文本模式，将输出转换为字符串而非字节
                text=True,
            )

            logger.info(f"正在运行命令: {' '.join(command)}")
            logger.info("输出内容:")
            logger.info("-" * 64)

            # 按行读取输出
            for line in process.stdout:
                # 去除行尾的换行符，但保留其他空白字符
                line = line.rstrip("\n")
                logger.info(f"[输出] {line}")

                if met_device_state:
                    lines_after_device_state += 1
                    if lines_after_device_state > 10:
                        break

                if keyword_some_devices_not_ready in line:
                    met_device_state = True
                    all_devices_ready = False
                elif keyword_all_devices_ready in line:
                    all_devices_ready = True
                    break

                for __keyword__ in error_keywords:
                    if __keyword__ in line:
                        parsed_errors.append(line)
                for __pattern__ in error_patterns:
                    if re.search(__pattern__, line):
                        parsed_errors.append(line)

                if line.endswith("state:ok") or line.endswith("state:not"):
                    motor_states.append(line)

            if all_devices_ready:
                logger.info("配置完成")
                logger.info("配置完成")
                logger.info("配置完成")
                break

            if len(parsed_errors) > 0:
                logger.error("配置失败")
                logger.error("配置失败")
                logger.error("配置失败")
                logger.error("-" * 64)
                for err in parsed_errors:
                    logger.error(err)
                logger.error("-" * 64)
                break

            if len(motor_states) > 0:
                logger.info("-" * 64)
                for state in motor_states:
                    logger.info(state)
                logger.info("-" * 64)

        except FileNotFoundError:
            logger.error(f"错误: 未找到命令 {' '.join(command)}")
            return
        except Exception as e:
            logger.error(f"执行命令时发生错误: {str(e)}")
            return
        finally:
            introspect_proc.kill_body_process()
            if process is not None and process.poll() is None:
                introspect_proc.kill_process(process.pid)

        # 进入下一次循环
    # 程序结束


def perform_introspection():
    pid = introspect_proc.get_body_process()
    if pid > 0:
        logger.warning(f"其它 body 进程正在运行 PID: {pid}")
        logger.warning(f"其它 body 进程正在运行 PID: {pid}")
        logger.warning(f"其它 body 进程正在运行 PID: {pid}")
        return

    logger.info("perform introspection ...")
    copy_config_file_if_absent()
    check_and_update_config()


if __name__ == "__main__":
    if not introspect_utils.is_running_as_root():
        logger.error("需要以 root 身份运行")
        logger.error("需要以 root 身份运行")
        logger.error("需要以 root 身份运行")

        logger.info("")
        logger.info("请使用下面的命令执行脚本程序")
        logger.info("")
        logger.info(f"  sudo python3 {os.path.basename(__file__)}")
        logger.info("")

        exit(0)

    perform_introspection()
