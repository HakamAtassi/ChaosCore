'''
Simultaneously write log to file and console.
'''

import sys
import os
import socket
import datetime

import logging
from colorama import init
from colorama import Fore, Back, Style

#FORMAT = '%(asctime)s.%(msecs)03d - %(name)s - %(levelname)-8s - %(message)s'
FORMAT = '%(asctime)s - %(levelname)-8s - %(message)s'

INFO_FORMAT = Fore.WHITE + FORMAT
DEBUG_FORMAT = Fore.BLUE + Style.BRIGHT + FORMAT
ERROR_FORMAT = Fore.RED + Back.WHITE + FORMAT
SUCCESS_FORMAT = Fore.GREEN + Style.BRIGHT + FORMAT
CRITICAL_FORMAT = Fore.RED + Back.YELLOW + FORMAT
FAIL_FORMAT = Fore.RED + Style.BRIGHT + FORMAT
WARNING_FORMAT = Fore.YELLOW + Style.BRIGHT + FORMAT


class logger(object):
    """
    """

    def __init__(self, file_name = None):
        """
        """
        init(autoreset=True)
        self.file_name = file_name
        self.name = str(__file__)

        hostname = socket.gethostname()
        utctime = datetime.datetime.utcnow()
        self.extra_dict = {'utctime': str(utctime), 'timezone': 'UTC'}
        #print (utctime)

        self.log = logging.getLogger(self.name)
        self.log.setLevel(logging.DEBUG)

        formatter =  logging.Formatter(FORMAT)

        self.screen_handler = logging.StreamHandler()
        self.screen_handler.setFormatter(formatter)
        self.log.addHandler(self.screen_handler)

        if (file_name != None):
            file_handler = logging.FileHandler(self.file_name, mode='w')
            file_handler.setFormatter(formatter)
            self.log.addHandler(file_handler)

    def info(self, str):
        """
        """
        self._formatter(INFO_FORMAT)
        self.log.info(str, extra = self.extra_dict)

    def debug(self, str):
        """
        """
        self._formatter(DEBUG_FORMAT)
        self.log.debug(str, extra = self.extra_dict)

    def error(self, str):
        """
        """
        self._formatter(ERROR_FORMAT)
        self.log.error(str, extra = self.extra_dict)

    def success(self, str):
        """
        """
        self._formatter(SUCCESS_FORMAT)
        logging.addLevelName(logging.INFO, levelName = 'SUCCESS')
        self.log.info(str, extra = self.extra_dict)
        logging.addLevelName(logging.INFO, levelName = 'INFO')

    def critical(self, str):
        """
        """
        self._formatter(CRITICAL_FORMAT)
        logging.addLevelName(logging.ERROR, levelName = 'CRITICAL')
        self.log.error(str, extra = self.extra_dict)
        logging.addLevelName(logging.ERROR, levelName = 'ERROR')

    def fail(self, str):
        """
        """
        self._formatter(FAIL_FORMAT)
        logging.addLevelName(logging.ERROR, levelName = 'FAIL')
        self.log.error(str, extra = self.extra_dict)
        logging.addLevelName(logging.ERROR, levelName = 'ERROR')

    def warning(self, str):
        """
        """
        self._formatter(WARNING_FORMAT)
        self.log.warning(str, extra = self.extra_dict)

    def _formatter(self, format):
        """
        """
        formatter =  logging.Formatter(format)
        self.screen_handler.setFormatter(formatter)
        self.log.addHandler(self.screen_handler)
