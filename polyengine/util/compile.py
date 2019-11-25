# compile.py
# Class to handle the compile process for C/C++ source files
# Authors: Minh Duc Nguyen, Akansh Divker

import sys
import os
from loguru import logger as logger
import config

class Compile:
    def __init__(self, compiler: str, source_files: list, commands: str, outfile: str):
        self.compiler = compiler
        self.source_files = source_files
        self.outfile = outfile
        self.commands = commands

    def compile(self):
        source_list = './temp/'.join(self.source_files)
        
        logger.info('Starting project compile.')

        check = config()
        change_filename = check.remove_sc(self.outfile)

        if os.system(self.compiler + ' ' + source_list + ' ' + self.commands + ' ' + change_filename) == 0:
            logger.info('Project compile finished successfully.')
            logger.info('Running compiled binary {}', self.outfile)
            logger.info('\n')

            os.system('./' + self.outfile)
        else:
            logger.error("Project compile failed.")
            sys.exit("Failed to compile project.")
