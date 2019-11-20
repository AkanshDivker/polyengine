# workspace.py
# Class to gather and load the necessary source information about a project
# Authors: Hyeon Jong Park, Akansh Divker

import sys
import os
import shutil
from loguru import logger as logger


class Workspace:
    header_files = list()
    source_files = list()
    work_path = './temp/'

    def __init__(self, path: str):
        self.path = path
        #self.verify()

    def verify(self):
        if (len(self.path) is not os.path.isdir(self.path)):
            logger.error(self.path)
            logger.error('Invalid directory path entered.')
            sys.exit("Invalid path.")

    def create_workspace(self):
        os.makedirs(self.work_path)
        files = os.listdir(self.path)

        for file in files:
            current_path = os.path.join(self.path, file)
            shutil.copy(current_path, self.work_path)

            if (file.endswith('.h') or file.endswith('.hpp')):
                self.header_files.append(self.work_path + file)
            elif file.endswith('.c') or file.endswith('.cpp'):
                self.source_files.append(self.work_path + file)
