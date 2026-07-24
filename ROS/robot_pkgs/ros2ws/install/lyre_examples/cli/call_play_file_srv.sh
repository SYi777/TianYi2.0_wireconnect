#!/bin/bash

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
echo "SCRIPT_DIR: ${SCRIPT_DIR}"

audio_file="$(dirname "${SCRIPT_DIR}")/res/test.mp3"

ros2 service call /audio_play/play_file lyre_msgs/srv/PlayFile "{path: '${audio_file}'}"
