from cocotb.triggers import Join, Combine
from pyuvm import *
import random
import cocotb
import pyuvm
from cocotb.clock import Clock
import sys
from pathlib import Path
sys.path.append(str(Path("..").resolve()))
from cacheUtils import *

sys.path.append('model')
from model.utils import *
from model.cacheMem import *
sys.path.append('..')

from cocotb.triggers import RisingEdge, FallingEdge

cacheModel = cacheMem()

# Sequence classes

cacheCommands={
    "LB":  0b0000,
    "LHW": 0b0001,
    "LW":  0b0010,

    "NOP":  0b0011,

    "SB":  0b0100,
    "SHW": 0b0101,
    "SW":  0b0110,

    "ALLOCATE": 0b0111, 
    
    "FW":  0b1000
}

binCommands={
    0b0000 : "LB",
    0b0001 : "LHW",
    0b0010 : "LW",

    0b0011 : "NOP",

    0b0100 : "SB",
    0b0101 : "SHW",
    0b0110 : "SW",

    0b0111 : "ALLOCATE",
        
    0b1000 : "FW"
}

###################
## SEQUENCE ITEM ##
###################

class cacheSeqItem(uvm_sequence_item):
    def __init__(self, name, addr, data, cache_line, cmd, valid, ready,cacheLineSize=32):
        random.seed(0x42)
        super().__init__(name)
        self.addr=addr
        self.data=data
        self.cache_line=cache_line
        self.cmd=cmd
        self.valid=valid
        self.ready=ready
        self.cacheLineSize = cacheLineSize

    def randomize_operands(self):
        self.addr=random.randint(0,(1<<32)-1)
        self.data=random.randint(0,(1<<32)-1)
        self.cache_line=random.randint(0,(1<<(self.cacheLineSize)-1))
        self.valid=random.randint(0,1)
        self.ready=random.randint(0,1)

    def generate_nop(self):
        self.addr=random.randint(0,(1<<32)-1)
        self.data=random.randint(0,(1<<32)-1)
        self.cache_line=random.randint(0,(1<<(self.cacheLineSize)-1))
        self.valid=0
        self.ready=random.randint(0,1)

    def generate_read_hit(self, set="random", way="random", byteOffset="random", cmd="random", data="random", cache_line="random"):
        """Will pick a tag in a random or given set"""
        tagOffset = (32 - cacheModel.tagSize)
        setOffset = int(np.ceil(np.log2(cacheModel.cacheLineSizeBytes)))

        if(cmd=="random"):
            cmd=random.choice(["LW", "LHW", "LB"])
        if(data=="random"):
            data=random.randint(0,(1<<32)-1)
        if(cache_line=="random"):
            cache_line=random.randint(0,(1<<(cacheModel.cacheLineSizeBytes*8))-1)
        assert cmd in ["LW", "LHW", "LB"]
        if(set=="random"):
            set=random.randint(0, cacheModel.sets - 1)
        if(way=="random"):
            way=random.randint(0, cacheModel.ways - 1)
        if(byteOffset=="random"):
            if(cmd=="LW"): byteOffset=random.randint(0,31) & (~(0b11))
            elif(cmd=="LHW"): byteOffset=random.randint(0,31) & (~(0b01))
            elif(cmd=="LB"): byteOffset=random.randint(0,31) & (~(0b00))
            else: assert False, "CMD not valid"
            
        tagArr = splitLine(cacheModel.getTagLine(set),cacheModel.ways, cacheModel.tagSize)     # Get set
        tag = tagArr[cacheModel.ways - 1 - way]  # Get Tag

        addr = 0
        addr = addr | (tag << (tagOffset))
        addr = addr | (set<<setOffset)
        addr = addr | byteOffset

        # Set inputs #
        self.addr=addr
        self.data=data
        self.cmd=cacheCommands[cmd]
        self.cache_line=cache_line
        self.valid=1
        self.ready=1

    def generate_read_miss(self, set="random", way="random", byteOffset="random", cmd="random", data="random", cache_line="random"):
        """Will generate a tag NOT in given set/way"""
        tagOffset = (32 - cacheModel.tagSize)
        setOffset = int(np.ceil(np.log2(cacheModel.cacheLineSizeBytes)))

        if(cmd=="random"):
            cmd=random.choice(["LW", "LHW", "LB"])
        if(data=="random"):
            data=random.randint(0,(1<<32)-1)
        if(cache_line=="random"):
            cache_line=random.randint(0,(1<<(cacheModel.cacheLineSizeBytes*8))-1)
        assert cmd in ["LW", "LHW", "LB"]
        if(set=="random"):
            set=random.randint(0, cacheModel.sets - 1)
        if(way=="random"):
            way=random.randint(0, cacheModel.ways - 1)
        if(byteOffset=="random"):
            if(cmd=="LW"): byteOffset=random.randint(0,31) & (~(0b11))
            elif(cmd=="LHW"): byteOffset=random.randint(0,31) & (~(0b01))
            elif(cmd=="LB"): byteOffset=random.randint(0,31) & (~(0b00))
            else: assert False, "CMD not valid"
            
        tagArr = splitLine(cacheModel.getTagLine(set),cacheModel.ways, cacheModel.tagSize)     # Get set
        tag = tagArr[cacheModel.ways - 1 - way]  # Get Tag

        while (tag in tagArr):
            tag = random.randint(0x0, ((1<<cacheModel.tagSize)-1))

        addr = 0
        addr = addr | (tag << (tagOffset))
        addr = addr | (set<<setOffset)
        addr = addr | byteOffset

        # Set inputs #
        self.addr=addr
        self.data=data
        self.cmd=cacheCommands[cmd]
        self.cache_line=cache_line
        self.valid=1
        self.ready=1

    def generate_write_hit(self, set="random", way="random", byteOffset="random", cmd="random", data="random", cache_line="random"):
        """Will generate a tag in given set/way"""
        tagOffset = (32 - cacheModel.tagSize)
        setOffset = int(np.ceil(np.log2(cacheModel.cacheLineSizeBytes)))

        if(cmd=="random"):
            cmd=random.choice(["SW", "SHW", "SB"])
        if(data=="random"):
            data=random.randint(0,(1<<32)-1)
        if(cache_line=="random"):
            cache_line=random.randint(0,(1<<(cacheModel.cacheLineSizeBytes*8))-1)
        assert cmd in ["SW", "SHW", "SB"]
        if(set=="random"):
            set=random.randint(0, cacheModel.sets - 1)
        if(way=="random"):
            way=random.randint(0, cacheModel.ways - 1)
        if(byteOffset=="random"):
            if(cmd=="SW"): byteOffset=random.randint(0,31) & (~(0b11))
            elif(cmd=="SHW"): byteOffset=random.randint(0,31) & (~(0b01))
            elif(cmd=="SB"): byteOffset=random.randint(0,31) & (~(0b00))
            else: assert False, "CMD not valid"
            
        tagArr = splitLine(cacheModel.getTagLine(set),cacheModel.ways, cacheModel.tagSize)     # Get set
        tag = tagArr[cacheModel.ways - 1 - way]  # Get Tag

        addr = 0
        addr = addr | (tag << (tagOffset))
        addr = addr | (set<<setOffset)
        addr = addr | byteOffset

        # Set inputs #
        self.addr=addr
        self.data=data
        self.cmd=cacheCommands[cmd]
        self.cache_line=cache_line
        self.valid=1
        self.ready=1

        pass

    def generate_write_miss(self, set="random", way="random", byteOffset="random", cmd="random", data="random", cache_line="random"):
        """Will generate a tag NOT in given set/way"""
        tagOffset = (32 - cacheModel.tagSize)
        setOffset = int(np.ceil(np.log2(cacheModel.cacheLineSizeBytes)))

        if(cmd=="random"):
            cmd=random.choice(["SW", "SHW", "SB"])
        if(data=="random"):
            data=random.randint(0,(1<<32)-1)
        if(cache_line=="random"):
            cache_line=random.randint(0,(1<<(cacheModel.cacheLineSizeBytes*8))-1)
        assert cmd in ["SW", "SHW", "SB"]
        if(set=="random"):
            set=random.randint(0, cacheModel.sets - 1)
        if(way=="random"):
            way=random.randint(0, cacheModel.ways - 1)
        if(byteOffset=="random"):
            if(cmd=="SW"): byteOffset=random.randint(0,31) & (~(0b11))
            elif(cmd=="SHW"): byteOffset=random.randint(0,31) & (~(0b01))
            elif(cmd=="SB"): byteOffset=random.randint(0,31) & (~(0b00))
            else: assert False, "CMD not valid"
            
        tagArr = splitLine(cacheModel.getTagLine(set),cacheModel.ways, cacheModel.tagSize)     # Get set
        tag = tagArr[cacheModel.ways - 1 - way]  # Get Tag

        while (tag in tagArr):
            tag = random.randint(0x0, ((1<<cacheModel.tagSize)-1))

        addr = 0
        addr = addr | (tag << (tagOffset))
        addr = addr | (set<<setOffset)
        addr = addr | byteOffset

        # Set inputs #
        self.addr=addr
        self.data=data
        self.cmd=cacheCommands[cmd]
        self.cache_line=cache_line
        self.valid=1
        self.ready=1



    def randomize(self):
        self.randomize_operands()
        self.cmd=random.choice(list(cacheCommands.keys()))
        self.cmd=cacheCommands[self.cmd]

###############
## SEQUENCES ##
###############

class RandomReadHit(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)

        #printDmem(cocotb.top, lineSizeBytes=32, ways=4, sets=64)
        #cacheModel.printDmem()

        #printTags(cocotb.top, lineSizeBytes=32, ways=4, sets=64)
        #cacheModel.printTags()

        #printPLRU(cocotb.top, lineSizeBytes=32, ways=4, sets=64)
        #cacheModel.printPLRU()

        #printDirty(cocotb.top, lineSizeBytes=32, ways=4, sets=64)
        #cacheModel.printDirty()

        #printValid(cocotb.top, lineSizeBytes=32, ways=4, sets=64)
        #cacheModel.printValid()

        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"

        for _ in range(1000):
            await self.start_item(cmd_tr)
            #funct=random.choice(cmd_tr.generate_read_hit(), cmd_tr.generate_read_miss())
            cmd_tr.generate_read_hit()
            #cmd_tr.generate_read_miss()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomReadMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")


        for _ in range(1000):
            await self.start_item(cmd_tr)
            cmd_tr.generate_read_miss()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomReadHitMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")


        for _ in range(1000):
            await self.start_item(cmd_tr)
            cmd_tr.generate_read_miss()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomWriteHit(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")


        for _ in range(1000):
            await self.start_item(cmd_tr)
            cmd_tr.generate_write_hit()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomWriteMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")


        for _ in range(1000):
            await self.start_item(cmd_tr)
            cmd_tr.generate_write_miss()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomReadHitMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 
        
        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")


        for _ in range(1000):
            await self.start_item(cmd_tr)
            cmd_tr.generate_read_miss()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomReadHitMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 


        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")
        

        for _ in range(1000):
            await self.start_item(cmd_tr)
            funct=random.choice([cmd_tr.generate_read_hit, cmd_tr.generate_read_miss])
            funct()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class RandomReadWriteHitMiss(uvm_sequence):
    async def body(self):
        cmd_tr = cacheSeqItem("cmd_tr", addr=None, data=None, cache_line=None, valid=None, ready=None, cmd=0)
        logging.info("Initializing memory to Random Active State...")

        #####################
        # Init cache memory ################################################################
        # The model generates a random active cache state, which is then copied to the DUT #
        ####################################################################################
        cacheModel.randomizeActiveState()
        logging.info("Ranomized cache model")

        copyDataMemory(cocotb.top, cacheModel)
        logging.info("Copied Data Memory")
        copyTagMemory(cocotb.top, cacheModel)
        logging.info("Copied Tag Memory")

        copyDirtyMemory(cocotb.top, cacheModel)
        logging.info("Copied Dirty Memory")
        copyPLRUMemory(cocotb.top, cacheModel)
        logging.info("Copied PLRU Memory")

        logging.critical("DUT valid not implemented")
        #copyValidMemory(cocotb.top, cacheModel) #FIXME: 


        await RisingEdge(cocotb.top.clock)
        assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
        logging.info("Initial cache states match")
        

        for _ in range(1000):
            await self.start_item(cmd_tr)
            funct=random.choice([cmd_tr.generate_read_hit, cmd_tr.generate_read_miss, cmd_tr.generate_write_hit, cmd_tr.generate_write_miss])
            funct()
            await self.finish_item(cmd_tr)

        for _ in range(10):
            await self.start_item(cmd_tr)
            cmd_tr.generate_nop()
            await self.finish_item(cmd_tr)

class TestAllSeq(uvm_sequence): # test all sequences
    async def body(self):
        sequencer = ConfigDB().get(None, "", "SEQR") # get acess to default sequencer
        randomReadHit = RandomReadHit("randomReadHit")
        randomReadMiss = RandomReadMiss("randomReadMiss")
        randomReadHitMiss = RandomReadMiss("randomReadHitMiss")
        randomWriteHit = RandomWriteHit("randomWriteHit")
        randomWriteMiss = RandomWriteMiss("randomWriteMiss")
        randomReadWriteHitMiss = RandomReadWriteHitMiss("randomReadWriteHitMiss")

        #await randomReadHit.start(sequencer)
        #await randomReadMiss.start(sequencer)
        #await randomReadHitMiss.start(sequencer)
        #await randomWriteHit.start(sequencer)
        await randomWriteMiss.start(sequencer)
        await randomReadWriteHitMiss.start(sequencer)


############
## DRIVER ##
############

class Driver(uvm_driver):
    def build_phase(self):
        self.ap = uvm_analysis_port("ap", self)

    def start_of_simulation_phase(self):
        self.bfm = cacheBFM()

    async def launch_tb(self):
        await self.bfm.reset()
        self.bfm.start_bfm()

    async def run_phase(self):
        await self.launch_tb()
        
        while True:
            cmd = await self.seq_item_port.get_next_item()
            await self.bfm.send_op(cmd.addr, cmd.data, cmd.cache_line, cmd.cmd, cmd.valid, cmd.ready)
            self.seq_item_port.item_done()
            

class Scoreboard(uvm_component):

    def build_phase(self):
        self.cmd_fifo = uvm_tlm_analysis_fifo("cmd_fifo", self)
        self.result_fifo = uvm_tlm_analysis_fifo("result_fifo", self)
        self.cmd_get_port = uvm_get_port("cmd_get_port", self)
        self.result_get_port = uvm_get_port("result_get_port", self)
        self.cmd_export = self.cmd_fifo.analysis_export
        self.result_export = self.result_fifo.analysis_export

    def connect_phase(self):
        self.cmd_get_port.connect(self.cmd_fifo.get_export)
        self.result_get_port.connect(self.result_fifo.get_export)

    def check_phase(self):
        try:
            self.errors = ConfigDB().get(self, "", "CREATE_ERRORS")
        except UVMConfigItemNotFound:
            self.errors = False
        while self.result_get_port.can_get():
            _, actual_result = self.result_get_port.try_get()
            cmd_success, cmd = self.cmd_get_port.try_get()
            if not cmd_success:
                self.logger.critical(f"result {actual_result} had no command")
            else:

                (addr, data, cache_line, cmd, valid, ready) = cmd
                predicted_result = cacheModel.requestCMD(addr=addr, data=data, cacheLine=cache_line, cmd=binCommands[cmd])
                
                ## COMPARE RESPONSES ##
                if(binCommands[cmd] in ["LW", "LHW", "LB"]):
                    assert predicted_result.data == actual_result[1]
                    assert predicted_result.addr == actual_result[0]
                    assert predicted_result.hit == actual_result[2]
                    assert predicted_result.valid == valid
                
                if(binCommands[cmd] in ["SW", "SHW", "SB"]):
                    #assert predicted_result.data == actual_result[1] #FIXME: need to check data wr response channel when I add it
                    assert predicted_result.addr == actual_result[0]
                    assert predicted_result.hit == actual_result[2]
                    assert predicted_result.valid == valid

                #########################
                ## COMPARE CACHE STATE ##
                #########################

                #assert compareCacheState(cocotb.top, cacheModel), f"Cache States do not match"
                


class Monitor(uvm_component):
    def __init__(self, name, parent, method_name):
        super().__init__(name, parent)
        self.method_name = method_name

    def build_phase(self):
        self.ap = uvm_analysis_port("ap", self)
        self.bfm = cacheBFM()
        self.get_method = getattr(self.bfm, self.method_name)

    async def run_phase(self):
        while True:
            datum = await self.get_method()
            #self.logger.info(f"MONITORED {datum}")
            self.ap.write(datum)




class cacheEnv(uvm_env):

    def build_phase(self):
        self.seqr = uvm_sequencer("seqr", self)
        self.driver = Driver.create("driver", self)
        self.cmd_mon = Monitor("cmd_mon", self, "get_cmd")
        self.result_mon = Monitor("result_mon", self, "get_result")
        #self.coverage = Coverage("coverage", self)
        self.scoreboard = Scoreboard("scoreboard", self)

    def connect_phase(self):
        ConfigDB().set(None, "*", "SEQR", self.seqr)
        self.driver.seq_item_port.connect(self.seqr.seq_item_export)
        self.cmd_mon.ap.connect(self.scoreboard.cmd_export)
        #self.cmd_mon.ap.connect(self.coverage.analysis_export)
        self.result_mon.ap.connect(self.scoreboard.result_export)


@pyuvm.test()
class cacheTest(uvm_test):

    def build_phase(self):
        self.env = cacheEnv("env", self)

    def end_of_elaboration_phase(self):
        self.test_all = TestAllSeq.create("test_all")

    async def run_phase(self):
        self.raise_objection()
        clock = Clock(cocotb.top.clock, 2, units="us")
        cocotb.start_soon(clock.start())
        print("Run phase")
        await self.test_all.start()
        self.drop_objection()
