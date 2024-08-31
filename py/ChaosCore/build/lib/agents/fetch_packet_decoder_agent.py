from cocotb_utils import *
import logging
from fetch_packet_decoder import fetch_packet_decoder_model

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class fetch_packet_decoder_agent:
    def __init__(self, dut):
        self.dut = dut
        self.model = fetch_packet_decoder_model()

        ########################
        # FETCH PACKET DECODER #
        ########################
        # ---------------
        # INPUT MONITORS
        # ---------------
        self.fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.clock(),
            valid=self.dut.fetch_packet_decoder_fetch_packet_valid(),
            data=lambda: self.dut.fetch_packet_decoder_read_fetch_packet(),
        )

        self.flush_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.clock(),
            valid=self.dut.fetch_packet_decoder_fetch_packet_valid(),   # monitor flush only when input is valid (for now)
            data=lambda: self.dut.fetch_packet_decoder_read_flush(),
        )
        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.decoded_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.monitor_output(),
            data=lambda: self.dut.fetch_packet_decoder_read_decoded_fetch_packet(),
        )

        self.scoreboard    = None

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("fetch_packet_decoder scoreboard already started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.fetch_packet_mon.start()
        self.flush_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.decoded_fetch_packet_mon.start()
        
        # ------
        # START
        # ------
        self.scoreboard = cocotb.start_soon(self.run())

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("fetch_packet_decoder Scoreboard never started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.fetch_packet_mon.stop()
        self.flush_mon.stop()

        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.decoded_fetch_packet_mon.stop()

        # -----
        # STOP
        # -----
        self.scoreboard.kill()
        self.scoreboard = 0


    async def run(self):
        while True:

            # -----------------
            # INPUT MONITORS
            # -----------------
            dut_fetch_packet = await self.fetch_packet_mon.values.get()

            # -----------------
            # OUTPUT MONITORS
            # ------------------
            dut_decoded_fetch_packet = await self.decoded_fetch_packet_mon.values.get()
            dut_flush                = await self.flush_mon.values.get()

            # ------------
            # DRIVE MODEL
            # ------------
            self.model.inputs(dut_fetch_packet, dut_flush)
            model_decoded_fetch_packet = self.model.get_decoded_fetch_packet()

            # -----------
            # ASSERTIONS
            # -----------

            sim_time = cocotb.utils.get_sim_time('ns')
            #logger.debug(f"asserted decoder @ {sim_time}")
            assert model_decoded_fetch_packet["valid"]                  == dut_decoded_fetch_packet["valid"]
            assert model_decoded_fetch_packet["fetch_PC"]               == dut_decoded_fetch_packet["fetch_PC"]
            assert model_decoded_fetch_packet["PRD"]                     == dut_decoded_fetch_packet["PRD"]
            assert model_decoded_fetch_packet["RS1"]                    == dut_decoded_fetch_packet["RS1"]
            assert model_decoded_fetch_packet["RS1_valid"]              == dut_decoded_fetch_packet["RS1_valid"]
            assert model_decoded_fetch_packet["RS2"]                    == dut_decoded_fetch_packet["RS2"]
            assert model_decoded_fetch_packet["RS2_valid"]              == dut_decoded_fetch_packet["RS2_valid"]
            assert model_decoded_fetch_packet["IMM"]                    == dut_decoded_fetch_packet["IMM"]
            assert model_decoded_fetch_packet["needs_ALU"]              == dut_decoded_fetch_packet["needs_ALU"]
            assert model_decoded_fetch_packet["needs_branch_unit"]      == dut_decoded_fetch_packet["needs_branch_unit"]
            assert model_decoded_fetch_packet["IS_IMM"]                 == dut_decoded_fetch_packet["IS_IMM"]
            assert model_decoded_fetch_packet["is_load"]                == dut_decoded_fetch_packet["is_load"]
            assert model_decoded_fetch_packet["is_store"]               == dut_decoded_fetch_packet["is_store"]


