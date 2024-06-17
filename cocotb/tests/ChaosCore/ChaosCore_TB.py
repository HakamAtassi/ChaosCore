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

from cocotb_utils import *

import PC_gen


class ChaosCore_TB:
    def __init__(self, dut):
        self.dut = dut
        # self.model = ROB_model()
        self.PC_gen_model = PC_gen.PC_gen_model()

        ############
        # PC ARBIT #
        ############

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.PC_gen_commit_valid(),
            data=lambda: self.dut.PC_gen_read_commit(),
        )

        self.PC_gen_prediction_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.PC_gen_prediction_valid(),
            data=lambda: self.dut.PC_gen_read_prediction(),
        )

        self.PC_gen_revert_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.PC_gen_revert_valid(),
            data=lambda: self.dut.PC_gen_read_revert(),
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
            valid=self.dut.predecoder_prediction_valid(),
            data=lambda: self.dut.predecoder_read_prediction(),
        )

        self.predecoder_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.predecoder_fetch_packet_valid(),
            data=lambda: self.dut.predecoder_read_fetch_packet(),
        )

        self.predecoder_RAS_read_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.predecoder_read_RAS_read(),
        )

        self.predecoder_commit_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.predecoder_commit_valid(),
            data=lambda: self.dut.predecoder_read_commit(),
        )

        # -----------------
        # OUTPUT MONITORS
        # -----------------

        self.predecoder_revert_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.predecoder_revert_valid(),
            data=lambda: self.dut.predecoder_read_revert(),
        )

        self.predecoder_GHR_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.predecoder_read_GHR(),
        )

        self.predecoder_final_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
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

        self.scoreboard = None

    async def update(self):
        await self.dut.update()

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("Scoreboard already started")

        ############
        # PC ARBIT #
        ############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon.start()
        self.PC_gen_prediction_mon.start()
        self.PC_gen_revert_mon.start()
        self.PC_gen_RAS_read_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.PC_gen_PC_next_mon.start()

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
        self.predecoder_revert_mon.start()
        self.predecoder_GHR_mon.start()
        self.predecoder_final_fetch_packet_mon.start()
        self.predecoder_RAS_update_mon.start()
        self.predecoder_predictions_mon.start()

        self.scoreboard = cocotb.start_soon(self.run())

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("Scoreboard never started")

        ############
        # PC ARBIT #
        ############
        # -----------------
        # INPUT MONITORS
        # -----------------
        self.PC_gen_commit_mon.stop()
        self.PC_gen_prediction_mon.stop()
        self.PC_gen_revert_mon.stop()
        self.PC_gen_RAS_read_mon.stop()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.PC_gen_PC_next_mon.stop()

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
        self.predecoder_revert_mon.stop()
        self.predecoder_GHR_mon.stop()
        self.predecoder_final_fetch_packet_mon.stop()
        self.predecoder_RAS_update_mon.stop()
        self.predecoder_predictions_mon.stop()

        self.scoreboard.kill()
        self.scoreboard = None

    async def reset(self):
        await self.dut.reset()

    async def run(self):
        while True:

            ########################
            ## DRIVE PC GEN MODEL ##
            ########################

            try:
                dut_PC_gen_commit = await self.PC_gen_commit_mon.values.get_nowait()
                self.PC_gen_model.commit(dut_PC_gen_commit)
            except:
                pass
            try:
                dut_PC_gen_prediction = (
                    await self.PC_gen_prediction_mon.values.get_nowait()
                )
                self.PC_gen_model.prediction(dut_PC_gen_prediction)
            except:
                pass
            try:
                dut_PC_gen_RAS_read = await self.PC_gen_RAS_read_mon.values.get_nowait()
                self.PC_gen_model.RAS_read(dut_PC_gen_RAS_read)
            except:
                pass

            dut_PC_next = await self.PC_gen_PC_next_mon.values.get()
            model_PC_next = self.PC_gen_model.PC_next()

            assert (
                model_PC_next["next"] == dut_PC_next["next"]
            ), f"PC GEN output did not match expected"

            ############################
            ## DRIVE PREDECODER MODEL ##
            ############################
