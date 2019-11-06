# compile.py
# Class to handle the compile process for C/C++ source files
# Authors: Minh Duc Nguyen, Akansh Divker

import sys
import os
import logging


class Compile:
    def __init__(self, compiler: str, source_files: list, outfile: str):
        self.compiler = compiler
        self.source_files = source_files
        self.outfile = outfile

    def compile(self):
        source_list = './temp/'.join(self.source_files)

        print('Starting project compile.')

        if os.system(self.compiler + ' ' + source_list + ' -o ' + self.outfile) == 0:
            print('Project compile finished successfully.')
            print('Running compiled binary ' + self.outfile)
            print('------------------------------' + '\n\n')

            os.system('./' + self.outfile)
        else:
            logging.error("Project compile failed.")
            sys.exit("Failed to compile project.")
