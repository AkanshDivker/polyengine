#!/usr/bin/python

# polyengine.py
# Main class for PolyEngine library
# Authors: Akansh Divker
# Usage: python polyengine.py

import sys
import shutil
from compile import Compile
from workspace import Workspace
from cleanup import Cleanup


def main():
    print('PolyEngine v1.0\n')

    # Temporary definition for test C project to compile
    source_directory = '../tests/c_project/'

    # Create the temporary code modification workspace
    workspace = Workspace(source_directory)
    workspace.create_workspace()

    # Initialize the compiler once information has been loaded
    compiler = Compile('gcc', workspace.source_files, 'c_program')
    compiler.compile()

    # Cleanup workspace and exit
    Cleanup.clean_exit(workspace.work_path)


if __name__ == '__main__':
    main()
