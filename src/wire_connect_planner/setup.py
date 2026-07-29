from setuptools import find_packages, setup
import os
from glob import glob

package_name = "wire_connect_planner"

setup(
    name=package_name,
    version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="syi777",
    maintainer_email="syi777@example.com",
    description="Cable tracker planner for WireConnect",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "cable_tracker = wire_connect_planner.cable_tracker:main",
        ],
    },
)
