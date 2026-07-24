import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/syi777/WireConnect_ws/ROS/moveit_ws/install/trajectory_bridge'
