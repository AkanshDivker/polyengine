#!/usr/bin/python

# polyengine.py
# Main class for PolyEngine library
# Authors: Akansh Divker
# Usage: python polyengine.py

import sys
import shutil
import binascii
from loguru import logger as logger
from workspace import Workspace
from cleanup import Cleanup
from util.encryption import Encryption
from util.compile import Compile
from util.config import Config
from processing import Processing


class PolyEngine:
    def start(self):
        # Script statup steps
        logger.info('PolyEngine v1.0')
        config = Config('config.ini')

        project_name = config.check_setting('PolyEngine', 'Name')
        logger.info('Starting project {}', project_name)

        message = config.check_setting('PolyEngine', 'Message')
        logger.info(message)

        # Source directory of project based on config file
        source_directory = config.check_setting('Compile', 'SourceDirectory')

        # Create the temporary code modification workspace
        workspace = Workspace(source_directory)
        workspace.create_workspace()

        # Process the files
        for f in workspace.source_files:
            if f is not None:
                processor = Processing(f)
                processor.process()

        for f in workspace.header_files:
            if f is not None:
                processor = Processing(f)
                processor.process()

        # Initialize the compiler once information has been loaded
        output_file = config.check_setting('Compile', 'Output')
        commands = config.check_setting('Compile', 'Commands')
        compiler_option = config.check_setting('Compile', 'Compiler')

        if compiler_option == 'gcc' or compiler_option == 'g++':
            compiler = Compile(
                compiler_option, workspace.source_files, commands, output_file)
            compiler.compile()
        else:
            logger.error('Invalid compiler option selected.')
            exit('Invalid compiler.')

        # Cleanup workspace and exit
        print()
        Cleanup.clean_exit(workspace.work_path)


def main():
    poly_engine = PolyEngine()
    poly_engine.start()


if __name__ == '__main__':
    main()
