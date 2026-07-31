#!/usr/bin/env python3
"""↑↓pitch ←→yaw a/d roll  z=zero x=step q=quit"""

import sys, os, time, termios, tty, select, threading, logging
import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
from std_msgs.msg import Header

PITCH, YAW, ROLL = 2, 3, 1
L_P, L_Y, L_R = 0.436, 1.570, 0.436
STEP = 0.005
RATE = 0.05

class Head(Node):
    def __init__(self):
        super().__init__('head_kb')
        self._pub = self.create_publisher(CmdSetMotorPosition, '/head/cmd_pos', 10)
        self.p = 0.0
        self.y = 0.0
        self.r = 0.0

    def pub(self):
        m = CmdSetMotorPosition()
        m.header = Header()
        m.header.stamp = self.get_clock().now().to_msg()
        m.cmds = [SetMotorPosition(name=n, pos=v, spd=2.0, cur=1.0)
                  for n, v in [(ROLL, self.r), (PITCH, self.p), (YAW, self.y)]]
        self._pub.publish(m)

def clamp(v, lim):
    return max(-lim, min(lim, v))

def main():
    logging.getLogger().setLevel(logging.ERROR)
    rclpy.init()
    h = Head()
    ex = rclpy.executors.SingleThreadedExecutor()
    ex.add_node(h)
    threading.Thread(target=ex.spin, daemon=True).start()

    # raw terminal, non-blocking reads
    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    tty.setraw(fd)
    fl = termios.tcgetattr(fd)
    fl[6][termios.VMIN] = 0
    fl[6][termios.VTIME] = 0
    termios.tcsetattr(fd, termios.TCSANOW, fl)

    step = STEP
    h.pub()
    print("ready")

    try:
        while rclpy.ok():
            # read whatever is available
            data = b''
            while select.select([fd], [], [], 0)[0]:
                try:
                    b = os.read(fd, 1)
                    if not b:
                        break
                    data += b
                except:
                    break

            if data:
                # parse arrow keys: \x1b[A etc
                i = 0
                while i < len(data):
                    b = data[i:i+1]
                    if b == b'\x03':
                        raise KeyboardInterrupt
                    if b == b'\x1b' and i+2 < len(data) and data[i+1:i+2] == b'[':
                        seq = data[i:i+3]
                        i += 3
                        if seq == b'\x1b[A':    h.p = clamp(h.p - step, L_P)
                        elif seq == b'\x1b[B':  h.p = clamp(h.p + step, L_P)
                        elif seq == b'\x1b[C':  h.y = clamp(h.y - step, L_Y)
                        elif seq == b'\x1b[D':  h.y = clamp(h.y + step, L_Y)
                    else:
                        i += 1
                        if b in (b'q', b'Q'):
                            raise StopIteration
                        elif b in (b'z', b'Z'):
                            h.p = h.y = h.r = 0.0
                        elif b in (b'x', b'X'):
                            step = 0.001 if step == 0.005 else 0.005
                        elif b in (b'a', b'A'):
                            h.r = clamp(h.r - step, L_R)
                        elif b in (b'd', b'D'):
                            h.r = clamp(h.r + step, L_R)

                sys.stdout.write(
                    f"\r  p:{h.p:+.3f}  y:{h.y:+.3f}  r:{h.r:+.3f}   ")
                sys.stdout.flush()

            h.pub()
            time.sleep(RATE)

    except (KeyboardInterrupt, StopIteration):
        pass
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
        ex.shutdown()
        h.destroy_node()
        rclpy.shutdown()
        print("\ndone")

if __name__ == '__main__':
    main()
