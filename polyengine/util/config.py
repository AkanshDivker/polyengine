import configparser
import re
import sys

class Config:
    def __init__(self, config_file: str):
        self.config_file = config_file

    def check_setting(self, category: str, option: str) -> str:
        config = configparser.ConfigParser()
        config.read(self.config_file)

        return config[category][option].strip('"')

    # Remove special characters and return remainders
    def remove_sc(self, file_name: str):
    	name_list = re.findall(u"[a-zA-Z0-9_+ ]", file_name)
    	name_list = ''.join(name_list)
        if len(name_list) > 20:
            sys.exit()
    	return name_list