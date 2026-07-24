#!/bin/bash

audio_url="https://cdn.pixabay.com/download/audio/2022/03/24/audio_090b7abf24.mp3?filename=shaker5-in-5s-8ths-103930.mp3"

ros2 service call /audio_play/play_url lyre_msgs/srv/PlayUrl "{url: '${audio_url}'}"
