"""End-effector inference module for robot control using diffusion policy models."""

import time

# 导入模型class
from delpoyment.inference_frank_neil_diffusion_test import DiffusionPolicyInference
import numpy as np

from xrocs.common.data_type import Joints
from xrocs.core.config_loader import ConfigLoader
from xrocs.core.station_loader import StationLoader
from xrocs.utils.logger.logger_loader import logger
from xrocs.utils.path_manager import path_manager


class EEInference:
    """End-effector inference implementation for robot control using diffusion policy models."""

    def __init__(self, config_path=None, model_path=None):
        if config_path is None:
            config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        self.cfg_dict = cfg_loader.get_config()
        station_loader = StationLoader(self.cfg_dict)
        self.robot_station = station_loader.get_station_handle()
        self.robot_station.connect()
        self.infer_model = DiffusionPolicyInference(model_path)

    def prepare(self):
        """Prepare the robot for inference by moving to home position and initializing grippers."""
        for name, _robot in self.robot_station.get_robot_handle().items():
            home = Joints(
                self.cfg_dict["robot"]["arm"]["home"][name],
                num_of_dofs=len(self.cfg_dict["robot"]["arm"]["home"][name]),
            )
            _robot.reach_target_joint(home)
        for gripper in self.robot_station.get_gripper_handle().values():
            gripper.open()
        time.sleep(2)
        logger.success("Resetting to home success!")

    def inference(self, data_dir: str, task_name: str):
        """Run continuous inference using the loaded model and control robot end-effector.

        Args:
            data_dir: Directory containing the inference data
            task_name: Name of the task to perform
        """
        obs = self.robot_station.get_obs()
        while True:
            action_pred: np.ndarray = self.infer_model.infer(obs)
            action_pred = action_pred[0].cpu().numpy()

            robot_targets = self.robot_station.decompose_action(action_pred)
            obs = self.robot_station.step_ee(robot_targets)


if __name__ == "__main__":
    config_path = path_manager.config_toml_path
    data = EEInference("/home/eai/ckpt/pretrained_model")
    data.prepare()
    data.inference("/home/eai/data/example_dir", "example_task")
