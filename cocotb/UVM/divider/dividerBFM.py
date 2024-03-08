import cocotb
from cocotb.triggers import FallingEdge, RisingEdge
from cocotb.queue import QueueEmpty, Queue
import enum
import logging
from pyuvm import utility_classes

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class dividerBFM(metaclass=utility_classes.Singleton):  # make instances of this class static
    def __init__(self):
        self.dut = cocotb.top
        self.driverQ   = Queue(maxsize=1)
        self.inputQ    = Queue(maxsize=0)  # Max queue size inf
        self.resultQ   = Queue(maxsize=0)  # ...

    ################################
    ## PUBLIC INTERFACE FUNCTIONS ## 
    ################################

    # We need a function to write to the input queue
    async def sendOp(self, A, B, sign):
        inputPacket = (A, B, sign)
        await self.driverQ.put(inputPacket)    # blocking write
    
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
        self.dut.io_dividend_ready.value    = 0
        self.dut.io_dividend_valid.value    = 0
        self.dut.io_dividend_bits.value     = 0
        self.dut.io_divisor_ready.value     = 0
        self.dut.io_divisor_valid.value     = 0
        self.dut.io_divisor_bits.value      = 0
        self.dut.io_signed_ready.value      = 0
        self.dut.io_signed_valid.value      = 0
        self.dut.io_signed_bits.value       = 0

        self.dut.reset.value = 0
        await FallingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)

    def startBFM(self):
        cocotb.start_soon(self.driverBFM())
        cocotb.start_soon(self.inputBFM())
        cocotb.start_soon(self.resultBFM())


    #######################
    ## PRIVATE FUNCTIONS ##
    #######################

    async def driverBFM(self):
        # empty driverQ and write to dut
        self.dut.io_dividend_ready.value    = 0
        self.dut.io_dividend_valid.value    = 0
        self.dut.io_dividend_bits.value     = 0
        self.dut.io_divisor_ready.value     = 0
        self.dut.io_divisor_valid.value     = 0
        self.dut.io_divisor_bits.value      = 0
        self.dut.io_signed_ready.value      = 0
        self.dut.io_signed_valid.value      = 0
        self.dut.io_signed_bits.value       = 0

        while True:
            await FallingEdge(self.dut.clock)

            ready = int(self.dut.io_dividend_ready) and int(self.dut.io_divisor_ready) and int(self.dut.io_signed_ready)

            if ready:
                try:
                    (A, B, signed) = self.driverQ.get_nowait()
                    self.dut.io_dividend_bits.value = A
                    self.dut.io_divisor_bits.value = B
                    self.dut.io_signed_bits.value = signed

                    self.dut.io_dividend_valid.value    = 1
                    self.dut.io_divisor_valid.value     = 1
                    self.dut.io_signed_valid.value      = 1
                    
                    await FallingEdge(self.dut.clock)
                    self.dut.io_dividend_valid.value    = 0
                    self.dut.io_divisor_valid.value     = 0
                    self.dut.io_signed_valid.value      = 0


                except QueueEmpty:
                    pass

    async def inputBFM(self):
        # FIXME: I think it might be a good idea to have a seperate queue for each inputs
        # in case 1 valid is asserted and the others are not. Could help catch bugs
        # Write to inputQ when valids is asserted
        while True:
            await FallingEdge(self.dut.clock)
            if(int(self.dut.io_dividend_valid) and int(self.dut.io_divisor_valid) and int(self.dut.io_signed_valid)):
                inputPacket = (int(self.dut.io_dividend_bits),
                             int(self.dut.io_divisor_bits),
                             int(self.dut.io_signed_bits))
                self.inputQ.put_nowait(inputPacket)

    async def resultBFM(self):
        while True:
            await FallingEdge(self.dut.clock)
            if(int(self.dut.io_quotient_valid) and int(self.dut.io_remainder_valid)):
                resultPacket = (int(self.dut.io_quotient_bits),int(self.dut.io_remainder_bits))
                self.resultQ.put_nowait(resultPacket)
