#!/bin/bash

LOG_FILE="camera_install_$(date +%Y%m%d_%H%M%S).log"
exec > >(tee -a "$LOG_FILE") 2>&1

sudo apt install -y libv4l-dev ros-humble-backward-ros sshpass

if [ -d /home/nvidia ];then
  home_dir=/home/nvidia
  dst_dir=/home/nvidia/orbbec_camera_ros2
  password=nvidia
  sn=$(timeout 5 sshpass -p "123" ssh -o StrictHostKeyChecking=no "ubuntu@192.168.41.1" "cat /etc/xhumanoid/xsn" 2>&1)
  type=${sn:2:2}
elif [ -d /home/ubuntu ];then
  home_dir=/home/ubuntu
  dst_dir=/home/ubuntu/orbbec_camera_ros2
  password=123
  sn=$(xsn)
  type=${sn:2:2}
fi
echo "robot type ${type}"

store_dir=/opt/orbbec_camera_ros2

for arg in "$@";do
  key=${arg%=*}
  val=${arg#*=}
  echo "${key}: ${val}"
  if [ "${key}" = "--dst" ];then
    store_dir=${val}
    break
  fi
done
echo "install orbbec camera to path ${store_dir}"

mkdir -p ${home_dir}/data/scripts/
cp scripts/start_orbbec_camera.sh ${home_dir}/data/scripts/
chmod +x ${home_dir}/data/scripts/start_orbbec_camera.sh

current_time=`date '+%Y%m%d_%H%M%S'`
if [ -L ${dst_dir} ] || [ -e ${dst_dir} ];then
  echo "mv ${dst_dir} to ${dst_dir}.bk.${current_time}"
  sudo mv ${dst_dir} ${dst_dir}.bk.${current_time}
fi

mkdir -p ${store_dir}
cp -r . ${store_dir}
rm -rf ${store_dir}/install.sh
ln -s ${store_dir} ${dst_dir}

if [ "$type" = "TG" ]; then
  sudo cp ${store_dir}/scripts/*service /etc/systemd/system/
  sudo rm /etc/systemd/system/orbbec_head_ty.service
elif [ "$type" = "TY" ]; then
  sudo rm /home/nvidia/.config/systemd/user/orbbec-camera.service
  sudo cp ${store_dir}/scripts/orbbec_head_ty.service /etc/systemd/system/orbbec_head.service
else
  sudo cp ${store_dir}/scripts/*service /etc/systemd/system/
fi
sudo systemctl daemon-reload
