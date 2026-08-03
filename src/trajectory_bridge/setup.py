from setuptools import setup
import os
from glob import glob

package_name = 'trajectory_bridge'

setup(
    name=package_name, version="0.1.0",
    packages=[package_name],
    install_requires=["setuptools"], zip_safe=True,
    entry_points={
        "console_scripts": [
            "trajectory_bridge = trajectory_bridge.bridge_node:main",
            "record_trajectory = trajectory_bridge.record_trajectory:main",
            "replay_trajectory = trajectory_bridge.replay_trajectory:main",
            "save_waypoint = trajectory_bridge.waypoint_tools:save_waypoints_main",
            "goto_waypoint = trajectory_bridge.waypoint_tools:goto_waypoints_main",
        ],
    },
    data_files=[
        (os.path.join('share', 'ament_index', 'resource_index', 'packages'),
            [os.path.join('resource', package_name)]),
        (os.path.join('share', package_name), ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),
    ],
)
