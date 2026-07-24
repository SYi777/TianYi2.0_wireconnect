#!/bin/bash

ros2 service call /audio_play/play_text lyre_msgs/srv/PlayText "{text: 'Hello Robot'}"
