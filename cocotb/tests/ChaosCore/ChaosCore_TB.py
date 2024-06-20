import math
import os
import sys
from pathlib import Path
from random import getrandbits
from typing import Any, Dict, List

import cocotb
import cocotb.queue
import cocotb.utils
import cocotb.utils
import cocotb.utils
import pytest
from cocotb.clock import Clock
from cocotb.handle import SimHandleBase
from cocotb.queue import Queue
from cocotb.triggers import RisingEdge
from cocotb.types import LogicArray, Range

from cocotb_utils import *

import PC_gen
import predecoder
import fetch_packet_decoder

class ChaosCore_TB:
    def __init__(self, dut):
        self.dut = dut
        # self.model = ROB_model()
        self.PC_gen_model = PC_gen.PC_gen_model()
        self.predecoder_model = predecoder.predecoder_model()
        self.fetch_packet_decoder_model = fetch_packet_decoder.fetch_packet_decoder_model()

        ############
        # PC ARBIT #
        ############

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            #valid=self.dut.PC_gen_commit_valid(),
            data=lambda: self.dut.PC_gen_read_commit(),
        )

        self.PC_gen_prediction_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            #valid=self.dut.PC_gen_prediction_valid(),
            data=lambda: self.dut.PC_gen_read_prediction(),
        )



        self.PC_gen_RAS_read_mon = Monitor(  # has no valid
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.PC_gen_read_RAS_read(),
        )

        # -----------------
        # OUTPUT MONITORS
        # -----------------

        self.PC_gen_PC_next_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.PC_gen_PC_next_valid(),
            data=lambda: self.dut.PC_gen_read_PC_next(),
        )

        ##############
        # PREDECODER #
        ##############

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.predecoder_prediction_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            #valid=self.dut.predecoder_prediction_valid(),
            data=lambda: self.dut.predecoder_read_prediction(),
        )

        self.predecoder_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            #valid=self.dut.predecoder_fetch_packet_valid(),
            data=lambda: self.dut.predecoder_read_fetch_packet(),
        )

        self.predecoder_RAS_read_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.predecoder_read_RAS_read(),
        )

        self.predecoder_commit_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            #valid=self.dut.predecoder_commit_valid(),
            data=lambda: self.dut.predecoder_read_commit(),
        )

        # -----------------
        # OUTPUT MONITORS
        # -----------------

        self.predecoder_GHR_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.predecoder_read_GHR(),
        )

        self.predecoder_final_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.clock(),
            valid=self.dut.predecoder_final_fetch_packet_valid(),
            data=lambda: self.dut.predecoder_read_final_fetch_packet(),
        )

        self.predecoder_RAS_update_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.predecoder_read_RAS_update(),
        )

        self.predecoder_predictions_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.predecoder_predictions_valid(),
            data=lambda: self.dut.predecoder_read_predictions(),
        )

        ########################
        # FETCH PACKET DECODER #
        ########################
        # ---------------
        # INPUT MONITORS
        # ---------------
        self.fetch_packet_decoder_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.fetch_packet_decoder_fetch_packet_valid(),
            data=lambda: self.dut.fetch_packet_decoder_read_fetch_packet(),
        )
        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.fetch_packet_decoder_decoded_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.fetch_packet_decoder_decoded_fetch_packet_valid(),
            data=lambda: self.dut.fetch_packet_decoder_read_decoded_fetch_packet(),
        )

        ##########
        # RENAME #
        ##########
        #----------------
        # INPUT MONITORS
        #----------------

        #-----------------
        # OUTPUT MONITORS
        #-----------------




        self.PC_gen_scoreboard                  = None
        self.predecoder_scoreboard              = None
        self.fetch_packet_decoder_scoreboard    = None

    async def update(self):
        await self.dut.update()

    def PC_gen_start(self):
        if self.PC_gen_scoreboard != None:
            raise RuntimeError("PC_gen scoreboard already started")

        ############
        # PC ARBIT #
        ############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon.start()
        self.PC_gen_prediction_mon.start()
        self.PC_gen_RAS_read_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.PC_gen_PC_next_mon.start()

        self.PC_gen_scoreboard = cocotb.start_soon(self.PC_gen_run())

    def predecoder_start(self):
        if self.predecoder_scoreboard != None:
            raise RuntimeError("predecoder scoreboard already started")

        ##############
        # PREDECODER #
        ##############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.predecoder_prediction_mon.start()
        self.predecoder_fetch_packet_mon.start()
        self.predecoder_RAS_read_mon.start()
        self.predecoder_commit_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.predecoder_GHR_mon.start()
        self.predecoder_final_fetch_packet_mon.start()
        self.predecoder_RAS_update_mon.start()
        self.predecoder_predictions_mon.start()

        self.predecoder_scoreboard = cocotb.start_soon(self.predecoder_run())

    def fetch_packet_decoder_start(self):
        if self.fetch_packet_decoder_scoreboard != None:
            raise RuntimeError("fetch_packet_decoder scoreboard already started")

        ##############
        # PREDECODER #
        ##############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.fetch_packet_decoder_fetch_packet_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.fetch_packet_decoder_decoded_fetch_packet_mon.start()

        self.fetch_packet_decoder_scoreboard = cocotb.start_soon(self.fetch_packet_decoder_run())

    def PC_gen_stop(self):
        # if self.predecoder_scoreboard is None:
        # raise RuntimeError("Scoreboard never started")

        if self.PC_gen_scoreboard is None:
            raise RuntimeError("Scoreboard never started")

        ############
        # PC ARBIT #
        ############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon.stop()
        self.PC_gen_prediction_mon.stop()
        self.PC_gen_RAS_read_mon.stop()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.PC_gen_PC_next_mon.stop()

        self.PC_gen_scoreboard.kill()
        self.PC_gen_scoreboard = 0

    def predecoder_stop(self):
        if self.predecoder_scoreboard is None:
            raise RuntimeError("predecoder Scoreboard never started")

        ##############
        # PREDECODER #
        ##############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.predecoder_prediction_mon.stop()
        self.predecoder_fetch_packet_mon.stop()
        self.predecoder_RAS_read_mon.stop()
        self.predecoder_commit_mon.stop()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.predecoder_GHR_mon.stop()
        self.predecoder_final_fetch_packet_mon.stop()
        self.predecoder_RAS_update_mon.stop()
        self.predecoder_predictions_mon.stop()

        self.predecoder_scoreboard.kill()
        self.predecoder_scoreboard = 0

    def fetch_packet_decoder_stop(self):
        if self.fetch_packet_decoder_scoreboard is None:
            raise RuntimeError("fetch_packet_decoder Scoreboard never started")

        ############
        # PC ARBIT #
        ############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.fetch_packet_decoder_fetch_packet_mon.stop()

        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.fetch_packet_decoder_decoded_fetch_packet_mon.stop()

        self.fetch_packet_decoder_scoreboard.kill()
        self.fetch_packet_decoder_scoreboard = 0

    async def reset(self):
        await self.dut.reset()

    async def PC_gen_run(self):
        while True:

            ########################
            ## DRIVE PC GEN MODEL ##
            ########################

            commit = await self.PC_gen_commit_mon.values.get()
            prediction = await self.PC_gen_prediction_mon.values.get()
            RAS_read = await self.PC_gen_RAS_read_mon.values.get()

            self.PC_gen_model.inputs(commit, prediction, RAS_read)

            try:
                dut_PC_next = await self.PC_gen_PC_next_mon.values.get()
                model_PC_next = self.PC_gen_model.PC_next_queue.pop(0)
                assert (model_PC_next["next"] == dut_PC_next["next"]), f"PC GEN output did not match expected"

            except(cocotb.queue.QueueEmpty):
                pass



    async def predecoder_run(self):
        while True:


            ############################
            ## DRIVE PREDECODER MODEL ##
            ############################
            # -----------------
            # INPUT MONITORS
            # -----------------

            prediction = await self.predecoder_prediction_mon.values.get()
            fetch_packet = await self.predecoder_fetch_packet_mon.values.get()
            RAS_read = await self.predecoder_RAS_read_mon.values.get()
            commit = await self.predecoder_commit_mon.values.get()

            #-------------
            # DRIVE MODEL
            #-------------

            self.predecoder_model.inputs(prediction, fetch_packet, RAS_read, commit)

            # -----------------
            # OUTPUT MONITORS
            # -----------------

            #GHR_mon = self.predecoder_GHR_mon.values.get()
            #RAS_update = self.predecoder_RAS_update_mon.values.get()
            #predictions = self.predecoder_predictions_mon.values.get()

            try:
                dut_final_fetch_packet = self.predecoder_final_fetch_packet_mon.values.get_nowait()
                model_final_fetch_packet = self.predecoder_model.read_final_fetch_packet()

                assert model_final_fetch_packet["valid"] == dut_final_fetch_packet["valid"]
                #assert model_final_fetch_packet["instruction"] == dut_final_fetch_packet["instruction"]
                #assert model_final_fetch_packet["valid_bits"] == dut_final_fetch_packet["valid_bits"]
                #assert model_final_fetch_packet["fetch_PC"] == dut_final_fetch_packet["fetch_PC"]
            except(cocotb.queue.QueueEmpty): 
                pass
            

            #assert model_final_fetch_packet["valid_bits"] == dut_final_fetch_packet["valid_bits"]
            #assert model_final_fetch_packet["fetch_PC"] == dut_final_fetch_packet["fetch_PC"]
            #assert model_final_fetch_packet["instruction"] == dut_final_fetch_packet["instruction"]


#            try:
                #dut_predictions = self.predecoder_predictions_mon.values.get_nowait()
                #model_predictions = model_predictions_queue.pop(0)
                #assert model_predictions["valid"] == dut_predictions["valid"]
                #print(model_predictions)
                #assert model_predictions["predicted_PC"] == dut_predictions["predicted_PC"]
            #except(cocotb.queue.QueueEmpty):
                #pass


    async def fetch_packet_decoder_run(self):
        while True:


            ############################
            ## DRIVE PREDECODER MODEL ##
            ############################
            # -----------------
            # INPUT MONITORS
            # -----------------
            dut_fetch_packet = await self.fetch_packet_decoder_fetch_packet_mon.values.get()

            # -----------------
            # OUTPUT MONITORS
            # ------------------
            dut_decoded_fetch_packet = await self.fetch_packet_decoder_decoded_fetch_packet_mon.values.get()

            # ------------
            # DRIVE MODEL
            # ------------
            self.fetch_packet_decoder_model.inputs(dut_fetch_packet)
            model_decoded_fetch_packet = self.fetch_packet_decoder_model.get_decoded_fetch_packet()


            # -----------
            # ASSERTIONS
            # -----------
            compare_decoded_fetch_packet(model_decoded_fetch_packet, dut_decoded_fetch_packet), f"decoder diverges at {cocotb.utils.get_sim_time()}"






