#!/bin/bash

################
## script_dir ##
################

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
echo "script_dir: ${script_dir}"

cd "${script_dir}"
if [ $? != 0 ]; then
  echo "退出：进入脚本目录失败"
  exit 1
fi

###############
## workspace ##
###############

workspace_dir=${script_dir}
while [ "${workspace_dir}" != "/" ]; do
  if [ -f "${workspace_dir}/install/setup.bash" ]; then
    break
  fi

  workspace_dir=$(dirname "${workspace_dir}")
done

if [ "${workspace_dir}" = "/" ]; then
  echo "退出：需要一个 ROS2 工作空间"
  exit 1
fi

workspace_name=$(basename "${workspace_dir}")
echo "workspace_dir: ${workspace_dir}"
echo "workspace_name: ${workspace_name}"

install_dir="${workspace_dir}/install"

#################
## data folder ##
#################

user_home="/home/ubuntu"
user_data_dir="${user_home}/data"
user_param_dir="${user_data_dir}/param"
mkdir -p "${user_param_dir}"

#################
## param files ##
#################

if [ -d "${install_dir}" ]; then
  for _param_file_ in audio_config.txt u2c_sn.yaml
  do
    if [ ! -f "${user_param_dir}/${_param_file_}" ]; then
      find "${install_dir}" \
        -name ${_param_file_} \
	      -exec sh -c '
          dest_dir="$1"
          shift 1

          for file in "$@"; do
            echo -n "copying "
            cp -vn "$file" "$dest_dir" || {
              echo "copying failed $file"
              exit 1
            }
          done
        ' sh "${user_param_dir}" {} +
    else
      echo "跳过已经存在的配置文件 ${user_param_dir}/${_param_file_}"
    fi
  done
else
  echo "目录不存在 ${install_dir}"
fi

#####################
## ssh known_hosts ##
#####################

try_to_resume_ssh_known_hosts() {
  ssh-keygen -f "/home/ubuntu/.ssh/known_hosts" \
    -R "192.168.41.2" \
    > /dev/null 2>&1
}

try_to_resume_ssh_known_hosts

######################
## systemd services ##
######################

enable_systemd_service() {
  local service=${1:?请提供服务名称}
  local status=$(systemctl is-enabled $service)
  if [ "$status" = "enabled" ]; then
    echo "服务已经启动"
  else
    sudo systemctl enable $service
    systemctl is-enabled $service
  fi
}

echo "配置进程管理器程序自启动..."
enable_systemd_service proc_manager

if command -v sshpass &> /dev/null; then
  echo "配置语音交互程序自启动..."
  sshpass -p "nvidia" \
    ssh -o StrictHostKeyChecking=no \
      nvidia@192.168.41.2 "echo nvidia | sudo -S systemctl enable lyre && systemctl is-enabled lyre"
fi
