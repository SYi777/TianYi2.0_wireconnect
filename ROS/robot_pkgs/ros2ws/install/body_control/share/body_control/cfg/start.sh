SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd ${SCRIPT_DIR} || exit 1
source install/setup.bash
ros2 launch body_control body_launch.py
