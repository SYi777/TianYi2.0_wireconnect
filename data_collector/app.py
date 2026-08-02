#!/usr/bin/env python3
"""相机预览 Web 后端 — UDP 接收三路相机 JPEG, 浏览器查看"""
import argparse
import os
import socket
import struct
import threading
import time
import webbrowser
from collections import deque

import cv2
import numpy as np
from flask import Flask, Response, send_from_directory

UDP_HEAD  = 9998
UDP_LEFT  = 9996
UDP_RIGHT = 9995
CAMS = ("head", "left", "right")
BASE_DIR = os.path.dirname(os.path.abspath(__file__))


class CameraReceiver(threading.Thread):
    def __init__(self, port, max_buffer=30):
        super().__init__(daemon=True)
        self.buffer = deque(maxlen=max_buffer)
        self._lock = threading.Lock()
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.bind(("0.0.0.0", port))
        self.sock.settimeout(0.3)
        self.running = True

    def run(self):
        while self.running:
            try:
                data, _ = self.sock.recvfrom(65535)
            except socket.timeout:
                continue
            except OSError:
                break
            if len(data) < 13:
                continue
            try:
                ts = struct.unpack(">d", data[:8])[0]
                (n,) = struct.unpack(">I", data[8:12])
                jpeg = data[12:12 + n]
                img = cv2.imdecode(np.frombuffer(jpeg, np.uint8), cv2.IMREAD_COLOR)
                if img is not None:
                    with self._lock:
                        self.buffer.append((ts, img))
            except Exception:
                try:
                    (n,) = struct.unpack(">I", data[:4])
                    jpeg = data[4:4 + n]
                    img = cv2.imdecode(np.frombuffer(jpeg, np.uint8), cv2.IMREAD_COLOR)
                    if img is not None:
                        with self._lock:
                            self.buffer.append((time.time(), img))
                except Exception:
                    pass

    def latest_jpeg(self):
        with self._lock:
            if self.buffer:
                img = self.buffer[-1][1]
                return cv2.imencode(".jpg", img, [cv2.IMWRITE_JPEG_QUALITY, 70])[1].tobytes()
        return None

    def stop(self):
        self.running = False
        try:
            self.sock.close()
        except OSError:
            pass


def make_no_signal():
    img = np.zeros((480, 640, 3), np.uint8)
    img[:] = (24, 24, 37)
    cv2.putText(img, "NO SIGNAL", (200, 250), cv2.FONT_HERSHEY_SIMPLEX, 1.2, (120, 120, 150), 2)
    return cv2.imencode(".jpg", img, [cv2.IMWRITE_JPEG_QUALITY, 70])[1].tobytes()


rx = {}

app = Flask(__name__)

@app.get("/")
def index():
    return send_from_directory(BASE_DIR, "index.html")

@app.get("/stream/<cam>")
def stream(cam):
    if cam not in CAMS:
        return "unknown camera", 404
    def gen():
        while True:
            jpeg = rx[cam].latest_jpeg() if cam in rx else None
            yield (b"--frame\r\nContent-Type: image/jpeg\r\n\r\n"
                   + (jpeg if jpeg is not None else make_no_signal()) + b"\r\n")
            time.sleep(1 / 15)
    return Response(gen(), mimetype="multipart/x-mixed-replace; boundary=frame")


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--host", default="127.0.0.1")
    p.add_argument("--port", type=int, default=8000)
    p.add_argument("--no-browser", action="store_true")
    args = p.parse_args()

    for name, port in [("head", UDP_HEAD), ("left", UDP_LEFT), ("right", UDP_RIGHT)]:
        rx[name] = CameraReceiver(port)
        rx[name].start()

    url = f"http://{args.host}:{args.port}"
    print(f"相机预览: {url}\nCtrl+C 退出")
    if not args.no_browser:
        threading.Timer(1.0, lambda: webbrowser.open(url)).start()
    try:
        app.run(host=args.host, port=args.port, threaded=True)
    finally:
        for r in rx.values():
            r.stop()


if __name__ == "__main__":
    main()
