#!/usr/bin/python

# polyengine.py
# Main class for PolyEngine library
# Authors: Akansh Divker
# Usage: python polyengine.py

import sys
import shutil
import binascii
from workspace import Workspace
from cleanup import Cleanup
from util.encryption import Encryption
from util.compile import Compile
from util.config import Config
from processing import Processing

class PolyEngine:
    def start(self):
        # Script statup steps
        print('PolyEngine v1.0\n')
        config = Config('config.ini')

        project_name = config.check_setting('PolyEngine', 'Name')
        print('Starting project ' + project_name)

        message = config.check_setting('PolyEngine', 'Message')
        print(message)

        # Test processing
        p = Processing('../tests/c_project/c_program.c')
        p.processing()

        # Source directory of project based on config file
        source_directory = config.check_setting('Compile', 'SourceDirectory')

        # Create the temporary code modification workspace
        workspace = Workspace(source_directory)
        workspace.create_workspace()

        output_file = config.check_setting('Compile', 'Output')
        commands = config.check_setting('Compile', 'Commands')

        # Initialize the compiler once information has been loaded
        compiler = Compile(workspace.source_files, commands, output_file)
        compiler.compile()

        # Cleanup workspace and exit
        Cleanup.clean_exit(workspace.work_path)


def main():
    poly_engine = PolyEngine()
    poly_engine.start()


if __name__ == '__main__':
    main()
