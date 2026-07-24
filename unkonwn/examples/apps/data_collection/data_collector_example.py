from __future__ import annotations

from xrocs.apps.data_collection.data_collector import data_collector_loader
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager


if __name__ == "__main__":
    try:
        # path_manager.config_toml_path = "test.toml"
        config_path = str(path_manager.config_toml_path)
        cfg_loader = ConfigLoader(config_path)
        cfg_dict = cfg_loader.get_config()

        collector = data_collector_loader(config_path=config_path, save_type=cfg_dict["data_collect"]["save_type"])
        collector.prepare()
        collector.start_collect(
            data_dir=cfg_dict["data_collect"]["save_path"],
            task_name=cfg_dict["data_collect"]["task_name"],
            task_description=cfg_dict["data_collect"]["task_description"])
    except KeyboardInterrupt:
        print("The data collection process is interrupted by the user.")
