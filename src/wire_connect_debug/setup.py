from setuptools import find_packages, setup
import os; from glob import glob

package_name = "wire_connect_debug"
setup(
    name=package_name, version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
    ],
    install_requires=["setuptools"], zip_safe=True,
    maintainer="syi777", maintainer_email="syi777@example.com",
    description="Debug tools for WireConnect",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "camera_view = wire_connect_debug.camera_view:main",
            "joint_relay = wire_connect_debug.joint_state_relay:main",
            "keyboard_teleop = wire_connect_debug.keyboard_teleop:main",
            "cartesian_debug = wire_connect_debug.cartesian_debug:main",
            "gripper_tf = wire_connect_debug.gripper_tf_publisher:main",
            "multi_camera_view = wire_connect_debug.multi_camera_view:main",
        ],
    },
)
