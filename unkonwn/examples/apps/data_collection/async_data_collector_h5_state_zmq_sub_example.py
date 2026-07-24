from __future__ import annotations

import pickle
import threading
import time
from typing import Dict, Optional

import cv2
import zmq


class StateZmqSubscription:
    def __init__(self):
        self._host = "192.168.41.1"
        self._port = 5566
        self.context = zmq.Context()

        self.get_socket = self.context.socket(zmq.SUB)
        self.get_socket.setsockopt(zmq.RCVTIMEO, 1000)
        self.get_socket.setsockopt(zmq.RCVHWM, 1)  # Only keep the latest message
        self.get_socket.setsockopt_string(zmq.SUBSCRIBE, "")  # Subscribe to all messages
        self.get_socket.connect(f"tcp://{self._host}:{self._port}")
        print(F"Connected to tcp://{self._host}:{self._port}")

        self.latest_data = None
        self._state_lock = threading.Lock()

        self._state_sub_thread = threading.Thread(
            target=self._update_state, 
            daemon=True,
            name="robot_state_zmq_sub_tread"
        )
        self._state_sub_thread.start()

    def _update_state(self) -> None:
        while True:
            try:
                msg = self.get_socket.recv_multipart(flags=zmq.NOBLOCK)
                
                if len(msg) >= 2:
                    topic = msg[0]
                    if topic == b"state":
                        data = pickle.loads(msg[1])
                        with self._state_lock:
                            self.latest_data = data
            except zmq.Again:
                time.sleep(0.005)
            except pickle.UnpicklingError as e:
                print(f"Pickle decode error: {e}")
            except Exception as e:
                print(f"Error receiving state: {e}")
                time.sleep(0.01)

    def get_current_states(self) -> Optional[Dict]:
        try:
            with self._state_lock:

                if self.latest_data is None:
                    print("No state received yet.")
                
                return self.latest_data

        except Exception as e:
            print(f"Failed to get current robot state {e}")
            return None


def main() -> None:
    client = StateZmqSubscription()
    time.sleep(1)  # warm up
    
    while True:
        states = client.get_current_states()
        print(states.keys())
        print(states["robot_state"])
        print(states["tele_state"])
        encoded_color_image = states["camera_state"]["images"]["head"]
        encode_depth_uint16_image = states["camera_state"]["depths"]["head"]
        print(encoded_color_image)
        print(encode_depth_uint16_image)

        decoded_bgr_color_image = cv2.imdecode(encoded_color_image, cv2.IMREAD_COLOR)
        depth_uint16_image = cv2.imdecode(encode_depth_uint16_image, cv2.IMREAD_UNCHANGED)
        print(decoded_bgr_color_image)
        print(depth_uint16_image)
        time.sleep(0.1)

if __name__ == "__main__":
    main()
