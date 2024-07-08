import math
import os
import sys
from pathlib import Path
from random import getrandbits
from typing import Any, Dict, List

import cocotb
import cocotb.queue
import cocotb.utils
import pytest
from cocotb.clock import Clock
from cocotb.handle import SimHandleBase
from cocotb.queue import Queue
from cocotb.triggers import RisingEdge
from cocotb.types import LogicArray, Range

from cocotb_utils import *
from model_utils import *


#######################
# IMPORT DUT WRAPPERS #
#######################

#import PC_gen_dut
#import predecoder_dut
#import rename_dut
from ChaosCore import ChaosCore_dut
from fetch_packet_decoder import *
from predecoder import *
from FU import *
from ROB import *
from rename import *

from SimpleDRAM import *

#################
# IMPORT AGENTS #
#################

from agents import fetch_packet_decoder_agent
from agents import FU_agent
from agents import predecoder_agent
from agents import ROB_agent
from agents import rename_agent
