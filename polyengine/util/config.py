import configparser
import re
import sys
from loguru import logger as logger


class Config:
    def __init__(self, config_file: str):
        self.config_file = config_file

    def check_setting(self, category: str, option: str) -> str:
        config = configparser.ConfigParser()
        config.read(self.config_file)

        selected = config[category][option]
        selected = selected.replace('"', '')
        selected = selected.replace("'", '')

        return selected

    # Remove special characters and return remainders
    @staticmethod
    def remove_special_chars(file_name: str) -> str:
        name_list = re.findall(u"[a-zA-Z0-9_+ .]", file_name)
        name_list = ''.join(name_list)

        if len(name_list) > 20:
            logger.error("Invalid file name detected.")
            sys.exit("Invalid file name processed.")

        return name_list.strip('.')
