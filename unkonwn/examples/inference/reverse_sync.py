"""Reverse synchronization module for robot control with teleop integration."""


import numpy as np
from xrocs.entity.tele_agent.tele_agent_loader import tele_agent_loader

from xrocs.core.app_base import RunnerBase
from xrocs.core.config_loader import ConfigLoader
from xrocs.core.fake_model import FakeModel
from xrocs.core.station_loader import StationLoader
from xrocs.utils.logger.logger_loader import logger
from xrocs.utils.input_listener.listener import InputListener
from xrocs.utils.path_manager import path_manager


class ReverseInfer:
    """Reverse inference implementation for robot control with teleop functionality."""

    def __init__(self, config_path=None, model_path=None):
        if config_path is None:
            config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        self.cfg_dict = cfg_loader.get_config()
        station_loader = StationLoader(self.cfg_dict)
        self.robot_station = station_loader.generate_station_handle()

        self.tele_agent_name = self.cfg_dict.get("basic", {}).get("tele_agent_type", "ServoTeleCore")
        self.tele_agent = tele_agent_loader.instantiate_tele_agent(name=self.tele_agent_name)

        self.runner = RunnerBase(self.tele_agent, self.robot_station)
        self.input_listener = InputListener()
        self.robot_station.connect()
        self.infer_model = FakeModel()

    def prepare(self):
        """Prepare for station initialization."""
        runner = self.runner
        runner.reset_to_home(self.cfg_dict)
        runner.check_pre_sync_status()
        runner.sync_agent_to_env()
        runner.start_keyboard_listener()
        logger.success("Prepare finished.")

    def sync(self):
        """Synchronize teleoperation with robot control and handle reverse mode switching."""
        obs = self.robot_station.get_obs()
        while not self.input_listener.btn_exit:
            if self.input_listener.btn_reverse:
                self.tele_agent.switch_reverse()
                action_pred: np.ndarray = self.infer_model.infer(obs)
                robot_targets = self.robot_station.decompose_action(action_pred)
                obs = self.robot_station.step(robot_targets)
                self.tele_agent.sync_position(action_pred)

            elif not self.input_listener.btn_reverse:
                self.tele_agent.switch_act()
                robot_targets = self.robot_station.decompose_action(self.tele_agent.act())
                obs = self.robot_station.step(robot_targets)


if __name__ == "__main__":
    data = ReverseInfer()
    data.prepare()
    data.sync()
