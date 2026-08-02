from setuptools import find_packages, setup
import os
from glob import glob

package_name = "data_collect"
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
    description="Imitation learning data collection",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "record_episode = data_collect.record_episode:main",
            "check_dataset = data_collect.check_dataset:main",
            "bag_to_lerobot = data_collect.bag_to_lerobot:main",
        ],
    },
)
