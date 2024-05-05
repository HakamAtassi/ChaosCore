from cocotb.triggers import Join, Combine
from pyuvm import *
import random
import cocotb
import pyuvm
from cocotb.clock import Clock

from cocotb_utils import *
from model_utils import *
from BPDut import *
from BP import *
from BPBFM import *

###################
## SEQUENCE ITEM ##
###################

class predict_commit_sequence_item(uvm_sequence_item):
    def __init__(self, name, address_set):
        super().__init__(name)
        self.predict        = predict.null()
        self.commit         = commit.null()
        self.revert         = revert.null()
        self.RAS_update     = RAS_update.null()

        self.address_set = address_set

    def randomize_commit_predict_exclusive(self):
        self.predict    = predict(generate_random_predict_request(addr_set=self.address_set))
        if(not self.predict.valid):
            self.commit     = commit(generate_random_commit_request(addr_set=self.address_set))
        else:
            self.commit = commit.null()
        self.revert     = revert.null()
        self.RAS_update = RAS_update.null()

    def randomize_commit_predict(self):
        self.predict    = predict(generate_random_predict_request(addr_set=self.address_set))
        self.commit     = commit(generate_random_commit_request(addr_set=self.address_set))
        self.revert     = revert.null()
        self.RAS_update = RAS_update.null()

    def randomize_commit_predict_revert_mutex(self):
        self.predict    = predict(generate_random_predict_request(addr_set=self.address_set))

        if(not self.predict.valid):
            self.commit     = commit(generate_random_commit_request(addr_set=self.address_set))
        else:
            self.commit = commit.null()

        if(not self.predict.valid and not self.commit.valid):
            self.revert = revert(generate_random_revert_request(addr_set=self.address_set))
        else:
            self.revert     = revert.null()

        self.RAS_update = RAS_update.null()

    def randomize_commit_predict_revert(self):
        self.predict    = predict(generate_random_predict_request(addr_set=self.address_set))
        self.commit     = commit(generate_random_commit_request(addr_set=self.address_set))
        self.revert     = revert(generate_random_revert_request(addr_set=self.address_set))
        self.RAS_update = RAS_update.null()

###############
## SEQUENCES ##
###############

class commit_predict_mutex_seq(uvm_sequence):  # Fully random, including sign
    async def body(self):
        random.seed(0x42)
        address_set = generate_address_set(1000)
        for _ in range(100000):
            input = predict_commit_sequence_item("input", address_set)
            await self.start_item(input)    # Start item construction
            input.randomize_commit_predict_exclusive()               # randomize
            await self.finish_item(input)   # Item ready to be sent

class commit_predict_random_seq(uvm_sequence):  # Fully random, including sign
    async def body(self):
        random.seed(0x42)
        address_set = generate_address_set(1000)
        for _ in range(100000):
            input = predict_commit_sequence_item("input", address_set)
            await self.start_item(input)    # Start item construction
            input.randomize_commit_predict()               # randomize
            await self.finish_item(input)   # Item ready to be sent


class commit_predict_revert_mutex_seq(uvm_sequence):  # Fully random, including sign
    async def body(self):
        random.seed(0x42)
        address_set = generate_address_set(1000)
        for _ in range(100000):
            input = predict_commit_sequence_item("input", address_set)
            await self.start_item(input)    # Start item construction
            input.randomize_commit_predict_revert_mutex()               # randomize
            await self.finish_item(input)   # Item ready to be sent

class commit_predict_revert_seq(uvm_sequence):  # Fully random, including sign
    async def body(self):
        random.seed(0x42)
        address_set = generate_address_set(1000)
        for _ in range(100000):
            input = predict_commit_sequence_item("input", address_set)
            await self.start_item(input)    # Start item construction
            input.randomize_commit_predict_revert()               # randomize
            await self.finish_item(input)   # Item ready to be sent

class commit_predict_mutex(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        mutex = commit_predict_mutex_seq("mutex")
        await mutex.start(sequencer)

class commit_predict_random(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = commit_predict_random_seq("random")
        await random.start(sequencer)

class commit_predict_revert_mutex(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = commit_predict_revert_mutex_seq("random")
        await random.start(sequencer)

class commit_predict_revert(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = commit_predict_revert_seq("random")
        await random.start(sequencer)


class testAllSeq(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        random = commit_predict_random_seq("random")
        mutex = commit_predict_mutex_seq("mutex")
        await random.start(sequencer)
        await random.start(mutex)

# test call
class testAllSeqForked(uvm_sequence):
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer

        commit_predict_mutex        = commit_predict_mutex_seq("random")
        commit_predict_random       = commit_predict_random_seq("random")
        commit_predict_revert       = commit_predict_revert_seq("random")
        commit_predict_revert_mutex = commit_predict_revert_mutex_seq("random")


        task0 = cocotb.start_soon(commit_predict_mutex.start(sequencer))
        task1 = cocotb.start_soon(commit_predict_revert.start(sequencer))
        task2 = cocotb.start_soon(commit_predict_random.start(sequencer))
        task3 = cocotb.start_soon(commit_predict_revert_mutex.start(sequencer))

        await Combine(task0, task1, task2, task3)
############
## DRIVER ##
############

class Driver(uvm_driver):
    def build_phase(self):
        self.analysisPort = uvm_analysis_port("analysisPort", self)

    def start_of_simulation_phase(self):
        self.BFM = BPBFM()

    async def launch_tb(self):
        await self.BFM.reset()
        self.BFM.startBFM()

    async def run_phase(self):
        await self.launch_tb()
        while True:
            input = await self.seq_item_port.get_next_item()
            await self.BFM.sendOp(input)
            result = await self.BFM.getResult()
            #if(result):
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

        self.model = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)

        print("Build phase")

    def connect_phase(self):
        self.inputGetPort.connect(self.inputFifo.get_export) # Here, you are saying you want to set the port you "get" from to the port the world sees
        self.resultGetPort.connect(self.resultFifo.get_export)

    async def run_phase(self):
        try:
            self.errors = ConfigDB().get(self, "", "CREATE_ERRORS")
        except UVMConfigItemNotFound:
            self.errors = False


        while True:

            full_transaction = await self.inputFifo.get()

            commit, revert, predict,  RAS_update = full_transaction

            #print(f"predict: {predict.valid}, {hex(predict.address)}")
            #print(f"Commit {hex(commit.valid)} {hex(commit.address)} {hex(commit.commit_GHR)}")

            model_output = self.model.send_all_requests(predict, commit, revert, RAS_update)

            if(predict.valid):
                dut_output = None
                while(not dut_output):
                    dut_output              = await self.resultFifo.get()
                try:
                    assert model_output == dut_output, f"model: {model_output.print()} != dut: {dut_output.print()}"
                except:
                    await RisingEdge(cocotb.top.clock)
                    assert False

    def check_phase(self): 
        if (self.resultFifo.size() != 0):
            self.logger.critical(f"TEST FAILED main result fifo is not Empty, there are {self.resultFifo.size()} left to be compared")



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
        self.BFM = BPBFM()
        self.get = getattr(self.BFM, self.methodName)   # This translates to self.bfm.method_name, where method_name is a string

    async def run_phase(self):
        while True:
            datum = await self.get()
            self.logger.debug(f"MONITORED {datum}")
            self.ap.write(datum)


#########
## ENV ##
#########

class BPEnv(uvm_env):
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

class BPTest(uvm_test):

    def build_phase(self):
        self.env = BPEnv("env", self)

    def end_of_elaboration_phase(self):
        self.test = testAllSeq.create("test")
        print("end of elaboration")

    async def run_phase(self):
        self.raise_objection()

        clock = Clock(cocotb.top.clock, 2, units="us")
        cocotb.start_soon(clock.start())

        await self.test.start()
        self.drop_objection()


#@pyuvm.test()
class test_commit_predict_mutex(BPTest):
    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, commit_predict_mutex)
        super().build_phase()

#@pyuvm.test()
class test_commit_predict(BPTest):
    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, commit_predict_random)
        super().build_phase()

#@pyuvm.test()
class test_commit_predict_revert(BPTest):
    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, commit_predict_revert_mutex)
        super().build_phase()
    
@pyuvm.test()
class test_commit_predict_revert(BPTest):
    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, commit_predict_revert)
        super().build_phase()

@pyuvm.test()
class ParallelTest(BPTest):
    def build_phase(self):
        uvm_factory().set_type_override_by_type(testAllSeq, testAllSeqForked)
        super().build_phase()






