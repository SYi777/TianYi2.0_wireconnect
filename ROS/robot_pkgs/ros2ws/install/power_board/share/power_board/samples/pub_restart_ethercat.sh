#!/bin/bash

workspace_dir=$(dirname $(readlink -f "$0"))

while true; do
  if [ -f "${workspace_dir}/install/setup.bash" ]; then
    source "${workspace_dir}/install/setup.bash"
    break
  fi

  workspace_dir=$(dirname "${workspace_dir}")

  if [ "${workspace_dir}" == "/" ]; then
    echo "Error: Could not find install/setup.bash in any parent directory."
    exit 1
  fi
done

ros2 topic pub -1 /restart_ec_slave bodyctrl_msgs/msg/EtherCatSlaveRestart
