# compile.py
# Class to handle the compile process for C/C++ source files
# Authors: Minh Duc Nguyen, Akansh Divker
import sys
import subprocess
from loguru import logger as logger

class Compile:
    def __init__(self, compiler: str, source_files: list, commands: str, outfile: str):
        self.compiler = compiler
        self.source_files = source_files
        self.outfile = outfile
        self.commands = commands

    def compile(self):
        source_list = './temp/'.join(self.source_files)
        
        logger.info('Starting project compile.')

        if subprocess.call([self.compiler, source_list, self.commands, self.outfile]) == 0:
            logger.info('Project compile finished successfully.')
            logger.info('Output file {} saved in directory.', self.outfile)
        else:
            logger.error("Project compile failed.")
            sys.exit("Failed to compile project.")
