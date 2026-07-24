import time

import rclpy

from bodyctrl_msgs.msg import LightCtrl
from publisher import LightCtrlPublisher


class CustomNode(LightCtrlPublisher):

  def __init__(self):
    super().__init__()


def main(args=None):
  rclpy.init(args=args)

  node = CustomNode()
  if not rclpy.ok():
    return

  time.sleep(1)

  node.publish_message(LightCtrl.CMD_CHAT_QUIT, "quit")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_CHAT_NET_ONLINE, "network resumed")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_CHAT_NET_OFFLINE, "network lost")
  time.sleep(1)

  node.publish_message(LightCtrl.CMD_CHAT_WAKEUP, "wakeup")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_NET_ONLINE, "network resumed")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_CHAT_ASR, "asr")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_LLM, "llm")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_TTS, "tts")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_PLAY, "play")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_QUIT, "quit")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_CHAT_WAKEUP, "wakeup")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_NET_OFFLINE, "network lost")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_CHAT_ASR, "asr")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_LLM, "llm")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_TTS, "tts")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_PLAY, "play")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_CHAT_WAKEUP, "wakeup")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_NET_ONLINE, "network resumed")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_CHAT_QUIT, "quit")
  time.sleep(3)

  node.quit()


if __name__ == '__main__':
  main()
