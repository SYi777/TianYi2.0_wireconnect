#!/bin/bash

# 按照 shell 的使用习惯 —— 0 为 真。
# 缺省值为 1，任何非 0 的值都看作假值。
enable=${1:-1}

if [ $enable = 0 ]; then

  ros2 topic pub -1 /audio_chat/enable std_msgs/msg/Bool "data: true"

else

  ros2 topic pub -1 /audio_chat/enable std_msgs/msg/Bool "data: false"

fi
