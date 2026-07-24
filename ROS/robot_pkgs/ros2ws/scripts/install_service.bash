#!/bin/bash

output_dir=
dst_dir=
home_dir=

for arg in "$@";do
  key=${arg%=*}
  val=${arg#*=}
  echo "${key}: ${val}"
  if [ ${key} = "--output_dir" ];then
    output_dir=${val}
    dst_dir=${val}
  elif [ ${key} = "--home_dir" ];then
    home_dir=${val}
  fi
done

if [ "${output_dir}" = "" ];then
  echo "output dir empty, exit"
  exit 1
fi

echo 'SUBSYSTEM=="tty", ATTRS{idVendor}=="1a86", ATTRS{idProduct}=="7523", SYMLINK+="ttySBUS0"' | sudo tee /etc/udev/rules.d/50-usb_sbus.rules
echo 'SUBSYSTEM=="tty", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6015", SYMLINK+="ttyUSB10"' | sudo tee /etc/udev/rules.d/51-robotiq.rules
echo "reload udev rules"
sudo udevadm control --reload-rules && sudo udevadm trigger
echo "udev rules reload done"

if [ -f ${dst_dir}/scripts/proc_manager.service ];then
  echo "install proc_manager service"
  mkdir -p ${home_dir}/data/scripts
  #if [ ! -f ${home_dir}/data/scripts/startup_proc_manager.bash ];then
    cp ${dst_dir}/scripts/startup_proc_manager.bash ${home_dir}/data/scripts
  #fi
  chmod +x ${dst_dir}/scripts/startup_proc_manager.bash
  if [ -f ${home_dir}/data/scripts/startup_proc_manager.bash ];then
    chmod +x ${home_dir}/data/scripts/startup_proc_manager.bash
  fi
  sudo cp ${dst_dir}/scripts/proc_manager.service /etc/systemd/system/proc_manager.service
  sudo systemctl daemon-reload
  echo "install proc_manager service finish, use: "
  echo "    sudo systemctl restart proc_manager.service "
  echo "    sudo systemctl stop proc_manager.service "
  echo "    sudo systemctl start proc_manager.service "
  echo "    sudo systemctl enable proc_manager.service "
  echo "    sudo systemctl disable proc_manager.service "
fi
