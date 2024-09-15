import logging
from cocotb.log import SimLog

import coloredlogs

from monitors.backend_mon import *
from monitors.ROB_mon import *

"""
the goal of this monitor is to re-serialize the program so that its easier to debug. 
For now, it only keeps track of writes to RD that have committed.

It does this by monitoring instruction inputs to the backend and creates map entry from the ROB index
to the fetch packet. 
when an FU outputs, it also outputs the ROB index and the fetch packet index for the completing instruction.
This info is used to update the map entry. 
When the ROB commits an instruction, that fetch packet is updated accordingly in the software model.
When this commit takes place, all correctly comitted instructions are written to a log. 
"""

class SOC_mon:
    def __init__(self, SOC):
        self.SOC = SOC
        self.log = SimLog("test")
        self.log.setLevel(logging.DEBUG)

        self.log.info("Hello from SOC mon")

        self.ROB_map = {}   # ROB index to fetch packet map

        self.backend_monitor = backend_mon(self.SOC.backend)           # monitor new instrucion inputs
        #self.ROB_monitor     = ROB_mon(self.ROB)

        #self.complete_instruction_queue = []    # queue of complete instructions. this is popped from and written to a log


    def log(self):
        pass


    def monitor(self):
        pass

        #monitored_backend_packet = self.backend_monitor.read_backend_packet()
        #monitored_FU_outputs = self.backend_monitor.read_backend_packet()
        #monitored_commit        = self.ROB_monitor.read_commit()
        #monitored_partial_commit        = self.ROB_monitor.read_partial_commit()


        #if(int(monitored_backend_packet["valid"]) and int(monitored_backend_packet["ready"])):
            #ROB_index = int(monitored_backend_packet["bits"]["ROB_index"])
            #self.ROB_map[ROB_index] = {
                #"???": 0,
                #"backend_packet": monitored_backend_packet
            #}


        #for i in range(4):
            #if(monitored_FU_outputs[i]["valid"]):
                #FU_ROB_index    = 
                #FU_packet_index = 
                #self.ROB_map[FU_ROB_index]["backend_packet"][FU_packet_index]["RD_data"]
                #pass
            

        #if(int(monitored_commit["valid"])):
            ## do stuff
            #commit_ROB_index = monitored_commit["bits"]["ROB_index"]
            #self.ROB_map[commit_ROB_index] = {}
            #pass




    