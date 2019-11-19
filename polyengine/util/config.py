import configparser


class Config:
    def __init__(self, config_file: str):
        self.config_file = config_file

    def check_setting(self, category: str, option: str) -> str:
        config = configparser.ConfigParser()
        config.read(self.config_file)

        return config[category][option].strip('"')


