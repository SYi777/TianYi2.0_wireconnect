#!/usr/bin/env python3
"""ZMQ 数据监听调试 — 打印同构臂手柄发来的原始数据。

Usage:
    python3 zmq_debug.py [-p PORT] [-i IP]

部署在机器人 (ssh ubuntu@192.168.41.1):
    python3 zmq_debug.py

或在笔记本测试连通性:
    python3 zmq_debug.py -i 192.168.41.100
"""

import argparse
import json
import sys
import time
import zmq


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--ip", default="192.168.41.100")
    parser.add_argument("-p", "--port", type=int, default=5003)
    args = parser.parse_args()

    ctx = zmq.Context()
    sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1)
    sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{args.ip}:{args.port}")
    sock.setsockopt(zmq.RCVTIMEO, 200)

    print(f"📡 监听 ZMQ: tcp://{args.ip}:{args.port}")
    print("   等待数据... (Ctrl+C 退出)")
    print("-" * 60)

    msg_count = 0
    last_print_t = 0.0
    try:
        while True:
            try:
                messages = sock.recv_multipart(zmq.NOBLOCK)
                for msg in messages:
                    msg_count += 1
                    now = time.time()
                    if now - last_print_t < 0.5:   # 2Hz rate limit
                        continue
                    last_print_t = now

                    raw = msg.decode("utf-8", errors="replace")
                    print(f"\n[{msg_count}] {time.strftime('%H:%M:%S')}  len={len(raw)}")
                    try:
                        data = json.loads(raw)
                        btn = data.get("button", {})
                        right = btn.get("right", [])
                        left  = btn.get("left", [])
                        if right:
                            print(f"  button.right: {right}")
                        if left:
                            print(f"  button.left:  {left}")
                        for k in data:
                            if k not in ("button",):
                                v = data[k]
                                if isinstance(v, (list, dict)):
                                    print(f"  {k}: {json.dumps(v)[:200]}")
                                else:
                                    print(f"  {k}: {v}")
                    except (json.JSONDecodeError, UnicodeDecodeError):
                        print(f"  [非JSON] {raw[:200]}")
            except zmq.Again:
                time.sleep(0.01)
            except zmq.ZMQError:
                pass
    except KeyboardInterrupt:
        pass
    finally:
        sock.close()
        ctx.destroy()
        print(f"\n✅ 共接收 {msg_count} 条消息")


if __name__ == "__main__":
    main()
