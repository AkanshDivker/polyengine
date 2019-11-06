# cleanup.py
# Class to handle the cleaning up and winding down after an execution attempt
# Authors: Akansh Divker

import sys
import logging
import shutil


class Cleanup:
    @staticmethod
    def clean_exit(workspace_path):
        logging.info('Removing temporary workspace.')

        shutil.rmtree(workspace_path)
        sys.exit()
