import math
import os
import sys
from pathlib import Path
from random import getrandbits
from typing import Any, Dict, List

import cocotb
import pytest
from cocotb.clock import Clock
from cocotb.handle import SimHandleBase
from cocotb.queue import Queue
from cocotb.triggers import RisingEdge
from cocotb.types import LogicArray, Range

from ROB import ROB_dut
from ROB import ROB_model


###############
### MONITOR ###
###############

class Monitor:
    def __init__(self, clock, data, valid):
        self.values = Queue()
        self.clock = clock
        self.data = data
        self.valid = valid
        self.coro = None

    def start(self):
        if self.coro is not None:
            raise RuntimeError("Monitor already started")
        self.coro = cocotb.start_soon(self.run())

    def stop(self):
        if self.coro is None:
            raise RuntimeError("Monitor never started")
        self.coro.kill()
        self.coro = None

    async def run(self):
        while True:
            await RisingEdge(self.clock)
            if self.valid.value != 1:
                await RisingEdge(self.valid)
                continue
            self.values.put_nowait(self.sample())
    
    def sample(self): 
        return self.data()


##################
### SCOREBOARD ###
##################

class ROB_TB:
    def __init__(self, dut):
        self.dut = dut
        self.model = ROB_model()

        #-----------------
        # INPUT MONITORS 
        #-----------------
        self.ROB_packet_mon     = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.ROB_packet_valid(),
                                      #valid=self.dut.clock(),
                                      data=lambda: self.dut.read_ROB_packet())
                                      
        self.FU0_output_mon      = Monitor(clock=self.dut.clock(), 
                                      #valid=self.dut.FU_output_valid(0),
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_FU_outputs(0))

        self.FU1_output_mon      = Monitor(clock=self.dut.clock(), 
                                      #valid=self.dut.FU_output_valid(1),
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_FU_outputs(1))

        self.FU2_output_mon      = Monitor(clock=self.dut.clock(), 
                                      #valid=self.dut.FU_output_valid(1),
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_FU_outputs(2))

        self.FU3_output_mon      = Monitor(clock=self.dut.clock(), 
                                      #valid=self.dut.FU_output_valid(2),
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_FU_outputs(3))


        self.commit_mon         = Monitor(clock=self.dut.clock(), 
                                      #valid=self.dut.commit_valid(),
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_commit())

        self.PC_file_addr_mon   = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_PC_file_exec_addr())
        # -----------------
        # OUTPUT MONITORS 
        # -----------------

        self.ROB_output_mon = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.ROB_output_valid(),
                                      #valid=self.dut.clock(),
                                      data=lambda: self.dut.read_ROB_output())

        self.ROB_index_mon = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.read_ROB_index())

        self.ROB_ready_mon = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.clock(),
                                      data=lambda: self.dut.ROB_packet_ready())


        #----------------------
        # MEMORY STATE MONITORS 
        #----------------------

        self.shared_mem_mon = Monitor(clock=self.dut.clock(), 
                                      valid=self.dut.shared_memory_notif(),
                                      data=lambda: self.dut.read_shared_mem())


        self.scoreboard = None

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("Scoreboard already started")
        
        #-----------------
        # INPUT MONITORS 
        #-----------------
        self.ROB_packet_mon.start()
        self.FU0_output_mon.start()
        self.FU1_output_mon.start()
        self.FU2_output_mon.start()
        self.FU3_output_mon.start()
        self.commit_mon.start()
        self.PC_file_addr_mon.start()


        #----------------------
        # MEMORY STATE MONITORS 
        #----------------------
        self.shared_mem_mon.start()


        # -----------------
        # OUTPUT MONITORS 
        # -----------------
        self.ROB_output_mon.start()
        self.ROB_index_mon.start()
        self.ROB_ready_mon.start()

        self.scoreboard = cocotb.start_soon(self.run())

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("Scoreboard never started")
        
        #-----------------
        # INPUT MONITORS 
        #-----------------
        self.ROB_packet_mon.stop()
        self.FU_output_mon.stop()
        self.commit_mon.stop()
        self.PC_file_addr_mon.stop()

        # -----------------
        # OUTPUT MONITORS 
        # -----------------
        self.ROB_output_mon.stop()
        self.ROB_index_mon.stop()
        self.ROB_ready_mon.stop()

        #-----------------------
        # MEMORY STATE MONITORS 
        #-----------------------
        self.shared_mem_mon.stop()



        self.scoreboard.kill()
        self.scoreboard = None

    async def reset(self):
        await self.dut.reset()

    async def run(self):
        while True:

            #-------------
            # GET INPUTS #
            #-------------
            dut_ROB_packet   = await self.ROB_packet_mon.values.get()
            dut_FU0_output   = await self.FU0_output_mon.values.get()
            dut_FU1_output   = await self.FU1_output_mon.values.get()
            dut_FU2_output   = await self.FU2_output_mon.values.get()
            dut_FU3_output   = await self.FU3_output_mon.values.get()
            dut_commit       = await self.commit_mon.values.get()
            dut_PC_file_addr = await self.PC_file_addr_mon.values.get()


            # ------------
            # DRIVE MODEL
            # ------------

            self.model.write_ROB_packet(dut_ROB_packet)
            self.model.write_FU_outputs(0, dut_FU0_output) 
            self.model.write_FU_outputs(1, dut_FU1_output)
            self.model.write_FU_outputs(2, dut_FU2_output)
            self.model.write_FU_outputs(3, dut_FU3_output)
            self.model.write_commit(dut_commit)


            #-------------
            # GET OUTPUTS 
            #-------------
            try:
                dut_ROB_output = await self.ROB_output_mon.values.get_nowait()
                model_ROB_output    = self.model.read_ROB_output()
                assert model_ROB_output == dut_ROB_output
            except: pass

            try:
                dut_ROB_index       = await self.ROB_index_mon.values.get_nowait()
                model_ROB_index     = self.model.read_ROB_index()
            except: pass
            
            try: 
                dut_ROB_ready       = await self.ROB_ready_mon.values.get_nowait()
                model_ROB_ready     = self.model.read_ROB_index()
            except: pass

                # compare shared mem
            dut_shared_mem       = await self.shared_mem_mon.values.get()
            model_shared_mem     = self.model.read_shared_mem()

            print(f"DUT:  {dut_shared_mem}")
            print(f"MODEL:{model_shared_mem}")

            assert dut_shared_mem == model_shared_mem





