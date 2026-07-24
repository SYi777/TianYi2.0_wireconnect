#!/usr/bin/python3
# -*- coding: utf-8 -*-

import datetime
import grp
import logging
import os
import pwd
import sys
from logging.handlers import RotatingFileHandler
from time import sleep


def is_running_as_root():
    """检查当前进程是否以 root 身份运行。

    返回:
        bool: 如果是 root 用户则返回 True，否则返回 False。
    """
    try:
        return os.geteuid() == 0
    except AttributeError:
        return False


def countdown(secs, predict=None):
    for _t_ in range(secs, 0, -1):
        if predict and predict():
            print("", flush=True)
            return
        print(_t_, end=".", flush=True)
        sleep(1)
    print(0, flush=True)


def modify_file_owner(file_path, user="ubuntu", group="ubuntu"):
    try:
        # 获取用户ID和群组ID
        uid = pwd.getpwnam(user).pw_uid if user else -1
        gid = grp.getgrnam(group).gr_gid if group else -1

        # 更改所有者和群组（-1表示不修改对应项）
        os.chown(file_path, uid, gid)

        msg = []
        if user:
            msg.append(f"所有者改为 {user}")
        if group:
            msg.append(f"群组改为 {group}")
        print(f"已成功修改文件 {file_path} 的: {', '.join(msg)}")

    except KeyError as e:
        raise ValueError(f"用户或群组不存在: {e}")
    except PermissionError:
        raise PermissionError("没有权限修改文件所有者/群组，请以root身份运行")
    except Exception as e:
        raise Exception(f"修改文件所有者/群组失败: {str(e)}")


def remove_all_whitespace(s):
    # 移除所有空格
    no_spaces = s.replace(' ', '')
    # 移除制表符
    no_tabs = no_spaces.replace('\t', '')
    # 移除换行符
    no_newlines = no_tabs.replace('\n', '')
    # 移除回车符
    no_carriage = no_newlines.replace('\r', '')
    return no_carriage


def setup_logger(name: str, log_dir: str = "/home/ubuntu/logs", level=logging.INFO) -> logging.Logger:
    """配置日志记录器，同时输出到终端和文件。

    参数:
        name: 日志记录器名称
        log_file: 日志文件路径
        level: 日志级别（默认INFO）

    返回:
        配置好的日志记录器
    """
    # 确保日志目录存在
    if log_dir and not os.path.exists(log_dir):
        os.makedirs(log_dir, exist_ok=True)
        modify_file_owner(log_dir)

    # 获取当前时间并格式化（年月日时分秒）
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    # 生成包含时间的日志文件名
    log_file = os.path.join(log_dir, f"body_introspection_{timestamp}.log")

    # 日志格式
    formatter = logging.Formatter(
        '%(asctime)s - %(levelname)s - %(module)s:%(lineno)d - %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S'
    )

    __logger = logging.getLogger(name)
    __logger.setLevel(level)
    __logger.propagate = False

    # 自定义文件处理器，支持设置权限
    class PermissionsRotatingFileHandler(RotatingFileHandler):
        def __init__(self, *args, **kwargs):
            self.file_permissions = kwargs.pop('file_permissions', 0o644)
            super().__init__(*args, **kwargs)

        def _open(self):
            # 打开文件后设置权限
            stream = super()._open()
            os.chmod(self.baseFilename, self.file_permissions)
            # 设置所有者和群组
            modify_file_owner(self.baseFilename)
            return stream

    # 配置文件处理器
    file_handler = PermissionsRotatingFileHandler(
        log_file,
        mode="a",
        maxBytes=10 * 1024 * 1024,
        backupCount=5,
        encoding='utf-8',
        file_permissions=0o644
    )
    file_handler.setFormatter(formatter)
    file_handler.setLevel(level)

    # 配置控制台处理器
    console_handler = logging.StreamHandler()
    console_handler.setFormatter(formatter)
    console_handler.setLevel(logging.DEBUG)

    __logger.addHandler(file_handler)
    __logger.addHandler(console_handler)

    return __logger


logger = setup_logger(
    name="body_introspection",
)


def cat_file(file_path):
    """模拟 cat 命令读取文件内容并输出。

    参数:
        file_path (str): 要读取的文件路径。
    """
    try:
        logger.info(file_path)
        logger.info("-" * 64)
        # 以只读模式打开文件，使用 utf-8 编码
        with open(file_path, 'r', encoding='utf-8') as file:
            # 读取并输出文件内容
            content = file.read()
            logger.info(content)  # 使用 end='' 避免额外添加换行符

    except FileNotFoundError:
        logger.error(f"错误: 无法打开文件 '{file_path}' (没有那个文件或目录)")
        sys.exit(1)
    except PermissionError:
        logger.error(f"错误: 无法打开文件 '{file_path}' (权限不够)")
        sys.exit(1)
    except UnicodeDecodeError:
        # 处理二进制文件或非utf-8编码文件
        try:
            with open(file_path, 'rb') as file:
                content = file.read()
                sys.stdout.buffer.write(content)  # 直接输出二进制内容
        except Exception as e:
            logger.error(f"错误: 读取文件 '{file_path}' 失败: {str(e)}")
            sys.exit(1)
    except Exception as e:
        logger.error(f"错误: 读取文件 '{file_path}' 失败: {str(e)}")
        sys.exit(1)


def swap_list(nums: list[str], i: int, j: int) -> list[str]:
    rst = [x for x in nums]
    tmp = rst[i]
    rst[i] = rst[j]
    rst[j] = tmp
    return rst


def get_all_permutations(nums: list[str]):
    n = len(nums)
    result = []  # 存储所有全排列结果
    used = [False] * n  # 标记元素是否已使用

    def backtrack(current):
        # 终止条件：当前排列长度等于数组长度，加入结果
        if len(current) == n:
            result.append(current.copy())  # 注意用 copy() 避免引用问题
            return
        # 遍历所有元素，选择未使用的元素
        for i in range(n):
            if not used[i]:
                used[i] = True  # 标记为已使用
                current.append(nums[i])  # 加入当前排列
                backtrack(current)  # 递归构建下一位
                current.pop()  # 回溯：移除最后一个元素
                used[i] = False  # 回溯：标记为未使用

    backtrack([])  # 从空排列开始递归
    return result
