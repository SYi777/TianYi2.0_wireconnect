from setuptools import find_packages, setup
import os
from glob import glob

package_name = "wire_connect_vision"

setup(
    name=package_name,
    version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
        (os.path.join("share", package_name, "config"), glob("config/*.yaml")),
        (os.path.join("share", package_name, "models"), glob("models/*.pt")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="syi777",
    maintainer_email="syi777@example.com",
    description="YOLO dual-model detection for WireConnect competition",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "detect_both = wire_connect_vision.detect_both_node:main",
            "table_detector = wire_connect_vision.table_detector:main",
        ],
    },
)
