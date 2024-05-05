import cocotb
from cocotb.triggers import RisingEdge, RisingEdge, ReadOnly
from cocotb.queue import QueueEmpty, Queue
import enum
import logging
from pyuvm import utility_classes

from cocotb_utils import *
from model_utils import *
from BPDut import *
from BP import *

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class BPBFM(metaclass=utility_classes.Singleton):  # make instances of this class static
    def __init__(self):
        self.dut = BPDut(cocotb.top)       # extend dut
        self.driverQ   = Queue(maxsize=1)
        self.inputQ    = Queue(maxsize=0)  # Max queue size inf
        self.resultQ   = Queue(maxsize=0)  # ...
        ## TODO: add state Qs

    ################################
    ## PUBLIC INTERFACE FUNCTIONS ## 
    ################################

    # We need a function to write to the input queue
    async def sendOp(self, full_transaction):       # this places all signals on the dut, including commit, predict, etc...
        await self.driverQ.put(full_transaction)    # blocking write
    
    # We also need functions to read inputs/outputs
    async def getInput(self):
        # Get inputs 
        inputs = await self.inputQ.get()       # blocking read
        return inputs

    async def getResult(self):
        # Get results
        result = await self.resultQ.get()      # blocking read
        return result

    async def reset(self):
        # Set all inputs low...
        self.dut.commit(commit.null())
        self.dut.predict(predict.null())
        self.dut.RAS_revert(revert.null())

        await reset(cocotb.top)


    def startBFM(self):
        cocotb.start_soon(self.driverBFM())
        cocotb.start_soon(self.inputBFM())
        cocotb.start_soon(self.resultBFM())


    #######################
    ## PRIVATE FUNCTIONS ##
    #######################

    async def driverBFM(self):
        # empty driverQ and write to dut
        
        self.dut.commit(commit.null())
        self.dut.predict(predict.null())
        self.dut.RAS_revert(revert.null())

        self.dut.set_prediction_read(1)  # would normally be driven by !full of an output queue...

        while True:
            await ReadOnly()
            ready = self.dut.is_predict_ready()
            await RisingEdge(self.dut.clock())
            if ready:
                try:
                    full_transaction = self.driverQ.get_nowait()

                    predict_msg = full_transaction.predict
                    commit_msg = full_transaction.commit
                    revert_msg = full_transaction.revert
                    RAS_update_msg = full_transaction.RAS_update

                    self.dut.predict(predict_msg)
                    self.dut.commit(commit_msg)
                    self.dut.RAS_revert(revert_msg)
                    self.dut.RAS_update(RAS_update_msg)
                except QueueEmpty:
                    pass
            else:
                self.dut.commit(commit.null())
                self.dut.predict(predict.null())
                self.dut.RAS_revert(revert.null())

    async def resultBFM(self):

        while True:
            await RisingEdge(self.dut.clock())
            await ReadOnly()
            resultPacket = self.dut.get_prediction()
            if(self.dut.is_prediction_valid()):
                self.resultQ.put_nowait(resultPacket)
            else:
                self.resultQ.put_nowait(None)


    async def inputBFM(self):
        while True:
            await RisingEdge(self.dut.clock())
            await ReadOnly()

            predict     = self.dut.get_predict()
            commit      = self.dut.get_commit()
            revert      = self.dut.get_revert()
            RAS_update  = self.dut.get_RAS_update()

            inputPacket = (commit, revert, predict, RAS_update)
            self.inputQ.put_nowait(inputPacket)