import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/syi777/WireConnect_ws/ROS/control_debug_ws/install/xarm_debug'
