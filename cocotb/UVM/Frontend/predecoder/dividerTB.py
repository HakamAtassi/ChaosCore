from cocotb.triggers import Join, Combine
from pyuvm import *
import random
import cocotb
import pyuvm
from cocotb.clock import Clock
from dividerBFM import dividerBFM
from dividerUtils import *

###################
## SEQUENCE ITEM ##
###################

class dividerSeqItem(uvm_sequence_item):
    random.seed(0x42)
    def __init__(self, name, A, B, signed):
        super().__init__(name)
        self.A = A
        self.B = B
        self.signed = signed

    def randomize(self):
        self.A      = random.randint(0,0xFFFF_FFFF)
        self.B      = random.randint(1,0xFFFF_FFFF)
        self.signed = random.randint(0,1)

    def randomizeA(self, targetRange=[0,0xFFFFFFFF], inputRange=[1,0xFFFF_FFFF]):
        # A/B = targetOutput
        # A/targetOutput=B
        targetOutput = random.randint(targetRange[0],inputRange[1])
        self.A      = random.randint(inputRange[0],inputRange[1])
        self.B      = self.A//targetOutput+1
        self.signed = random.randint(0,1)

    def randomizeB(self, targetRange=[0, 0xFFFFFFFF], inputRange=[1, 0xFFFFFFFF]):
        # A/B = targetOutput
        # A = targetOutput*B
        targetOutput = random.randint(targetRange[0],targetRange[1])
        self.B      = random.randint(inputRange[0],inputRange[1])
        self.A      = (targetOutput*self.B) & 0xFFFF_FFFF
        self.signed = random.randint(0,1)


###############
## SEQUENCES ##
###############

class randomSeq(uvm_sequence):  # Fully random, including sign
    async def body(self):
        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)  # Instantiate sequence item
            await self.start_item(input)    # Start item construction
            input.randomize()               # randomize
            await self.finish_item(input)   # Item ready to be sent

class randomOutputA(uvm_sequence):  # Randomize the desired output, work backwards to get inputs
    # This is to avoid must tests generating 0/1
    async def body(self):
        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeA()  # Test random inputs
            await self.finish_item(input)
        
        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeA(targetRange=[0, 0xFFFF], inputRange=[0,0xFFFF]) # Small output, small A => small B
            await self.finish_item(input) 

        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeA(targetRange=[0, 0x7FFF], inputRange=[0xFF_FFFF,0xFFFF_FFFF])  # Small output, large A => Large B
            await self.finish_item(input)

class randomOutputB(uvm_sequence):  # Randomize the desired output, work backwards to get inputs
    # This is to avoid must tests generating 0/1
    async def body(self):
        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeB()
            await self.finish_item(input)
        
        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeB(targetRange=[0, 0xFFFF], inputRange=[0,0xFFFF])
            await self.finish_item(input)

        for _ in range(1000):
            input = dividerSeqItem("input", 0x0, 0x0, 0x0)
            await self.start_item(input)
            input.randomizeB(targetRange=[0, 0x7FFF], inputRange=[0xFF_FFFF,0xFFFF_FFFF]) 
            await self.finish_item(input)



class maxSeq(uvm_sequence):     # Sequence of saturated signed and unsigned
    async def body(self):
        for sign in [0x0, 0x1]:
            input = dividerSeqItem("input", 0xFFFF_FFFF, 0xFFFF_FFFF, sign)  # Both max neg
            await self.start_item(input)    
            await self.finish_item(input)

        for sign in [0x0, 0x1]:
            input = dividerSeqItem("input", 0xFFFF_FFFF, 0x7FFF_FFFF, sign) # A neg, B pos
            await self.start_item(input)
            await self.finish_item(input)
        
        for sign in [0x0, 0x1]:
            input = dividerSeqItem("input", 0x7FFF_FFFF, 0xFFFF_FFFF, sign) # A pos, B neg
            await self.start_item(input)
            await self.finish_item(input)

        for sign in [0x0, 0x1]:
            input = dividerSeqItem("input", 0x7FFF_FFFF, 0x7FFF_FFFF, sign) # Neither
            await self.start_item(input)
            await self.finish_item(input)

class testAllSeq(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = randomSeq("random")
        max = maxSeq("max")
        _randomOutputA = randomOutputA("randomOutputA")
        _randomOutputB = randomOutputB("randomOutputB")

        await random.start(sequencer)
        await max.start(sequencer)
        await _randomOutputA.start(sequencer)
        await _randomOutputB.start(sequencer)

class testAllSeqForked(uvm_sequence):
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = randomSeq("random")
        max = maxSeq("max")
        _randomOutputA = randomOutputA("randomOutputA")
        _randomOutputB = randomOutputB("randomOutputB")

        task0 = cocotb.start_soon(random.start(sequencer))
        task1 = cocotb.start_soon(max.start(sequencer))
        task2 = cocotb.start_soon(_randomOutputA.start(sequencer))
        task3 = cocotb.start_soon(_randomOutputB.start(sequencer))

        #await Combine(Join(task0), Join(task1), Join(task2), Join(task3))
        await Combine(task0, task1, task2, task3)




############
## DRIVER ##
############

class Driver(uvm_driver):
    def build_phase(self):
        self.analysisPort = uvm_analysis_port("analysisPort", self)

    def start_of_simulation_phase(self):
        self.BFM = dividerBFM()

    async def launch_tb(self):
        await self.BFM.reset()
        self.BFM.startBFM()

    async def run_phase(self):
        await self.launch_tb()
        while True:
            input = await self.seq_item_port.get_next_item()
            await self.BFM.sendOp(input.A, input.B, input.signed)
            result = await self.BFM.getResult()
            self.analysisPort.write(result)
            self.seq_item_port.item_done()

##############
## COVERAGE ##
##############

## TODO:


################
## SCOREBOARD ##
################

class Scoreboard(uvm_component):

    def build_phase(self):   
        self.inputFifo = uvm_tlm_analysis_fifo("inputFifo", self)
        self.resultFifo = uvm_tlm_analysis_fifo("resultFifo", self)

        self.inputGetPort = uvm_get_port("inputGetPort", self)
        self.resultGetPort = uvm_get_port("resultGetPort", self)

        self.inputExport = self.inputFifo.analysis_export
        self.resultExport = self.resultFifo.analysis_export

    def connect_phase(self):
        self.inputGetPort.connect(self.inputFifo.get_export) # Here, you are saying you want to set the port you "get" from to the port the world sees
        self.resultGetPort.connect(self.resultFifo.get_export)

    def check_phase(self):
        passed = True

        try:
            self.errors = ConfigDB().get(self, "", "CREATE_ERRORS")
        except UVMConfigItemNotFound:
            self.errors = False

        while self.resultGetPort.can_get():
            error,  (actualQuotient, actualRemainder) = self.resultGetPort.try_get()
            error, (A, B, signed) = self.inputGetPort.try_get()

            if(signed): # treat result as signed
                actualQuotient=hexToInt(actualQuotient)

            expectedQuotient, expectedRemainder = divisionPrediction(A, B, signed)
            if expectedQuotient == actualQuotient:
                self.logger.info(f"PASSED: Signed={signed} {hex(A)}//{hex(B)} == {hex(actualQuotient)}")
            else:
                self.logger.info(f"FAILED: Signed={signed} {hex(A)}//{hex(B)} == {hex(actualQuotient)}")
                passed = False
        assert passed

#FIXME: scoreboard does not check if ready and valid are asserted, deasserted properly
#FIXME: I think a pipelined version is not as expensive as I think (LUT vs reg count)

#############
## MONITOR ##
#############

class monitor(uvm_component):
    # Monitor reads inputs or results from BFM and writes them to the analysis port
    # for use by the scoreboard and coverage components
    def __init__(self, name, parent, methodName):
        super().__init__(name,parent)
        self.methodName = methodName

    def build_phase(self):
        self.ap = uvm_analysis_port("ap", self)
        self.BFM = dividerBFM()
        self.get = getattr(self.BFM, self.methodName)   # This translates to self.bfm.method_name, where method_name is a string

    async def run_phase(self):
        while True:
            datum = await self.get()
            self.logger.debug(f"MONITORED {datum}")
            self.ap.write(datum)


#########
## ENV ##
#########

class dividerEnv(uvm_env):
    ## Default constructor not here, but it takes in "name" and parent pointer

    def build_phase(self):
        self.sequencer = uvm_sequencer("seqr", self)
        self.driver = Driver("driver", self)
        self.inputMonitor = monitor("inputMonitor", self, "getInput")
        #self.coverage = Coverage("coverage", self)
        self.scoreboard = Scoreboard("scoreboard", self)

    def connect_phase(self):
        ConfigDB().set(None, "*", "SEQR", self.sequencer) # this makes the sequencer available to all uvm components that want it. 
        self.driver.seq_item_port.connect(self.sequencer.seq_item_export)
        self.inputMonitor.ap.connect(self.scoreboard.inputExport)
        #self.cmd_mon.ap.connect(self.coverage.analysis_export)
        self.driver.analysisPort.connect(self.scoreboard.resultExport)


##################
## COCOTB TESTS ##
##################

#@pyuvm.test()
class dividerTest(uvm_test):


    def build_phase(self):
        self.env = dividerEnv("env", self)

    def end_of_elaboration_phase(self):
        self.testAll = testAllSeq.create("test_all")
        print("end of elaboration")

    async def run_phase(self):
        self.raise_objection()

        clock = Clock(cocotb.top.clock, 2, units="us")
        cocotb.start_soon(clock.start())

        await self.testAll.start()
        self.drop_objection()

@pyuvm.test()
class ParallelTest(dividerTest):

    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, testAllSeqForked)
        super().build_phase()


