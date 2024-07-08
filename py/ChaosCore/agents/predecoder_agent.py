from cocotb_utils import *
import logging

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class predecoder_agent:
    def __init__(self, dut):
        self.dut = dut
        self.model = predecoder_model()

    def start(self):
        pass

    def stop(self):
        pass

    async def run(self):
        while True:
            pass