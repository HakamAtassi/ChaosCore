
from cocotb_utils import *
from FU import FU_model
import logging

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class FU_agent:
    def __init__(self, dut):
        self.dut = dut
        self.model = FU_model()

        ########################
        # FETCH PACKET DECODER #
        ########################
        # ---------------
        # INPUT MONITORS
        # ---------------
        self.FU_input_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.FU_input_valid(),
            data=lambda: self.dut.read_FU_input(),
        )

        self.flush_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.FU_input_valid(),   # monitor flush only when input is valid (for now)
            data=lambda: self.dut.read_flush(),
        )
        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.FU_output_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.monitor_output(),
            data=lambda: self.dut.read_FU_output(),
        )

        self.scoreboard    = None

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("fetch_packet_decoder scoreboard already started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.FU_input_mon.start()
        self.flush_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.FU_output_mon.start()
        
        # ------
        # START
        # ------
        self.scoreboard = cocotb.start_soon(self.run())

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("FU Scoreboard never started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.FU_input_mon.stop()
        self.flush_mon.stop()

        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.FU_output_mon.stop()

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
            dut_FU_input             = await self.FU_input_mon.values.get()

            # -----------------
            # OUTPUT MONITORS
            # ------------------
            dut_FU_output            = await self.FU_output_mon.values.get()
            dut_flush                = await self.flush_mon.values.get()

            # ------------
            # DRIVE MODEL
            # ------------

            self.model.inputs(dut_FU_input, dut_flush)
            model_FU_output = self.model.get_FU_output()

            # -----------
            # ASSERTIONS
            # -----------

            sim_time = cocotb.utils.get_sim_time('ns')
            #logger.info(f"Asserted @ {sim_time}")


            assert model_FU_output["valid"] == dut_FU_output["valid"]
            assert model_FU_output["fetch_PC"] == dut_FU_output["fetch_PC"]

            valid = model_FU_output["valid"]
            compare_RD = model_FU_output["PRD"] & valid
            if(compare_RD & valid):
                assert model_FU_output["PRD"] == dut_FU_output["PRD"]
                assert model_FU_output["RD_data"] == dut_FU_output["RD_data"]
                assert model_FU_output["RD_valid"] == dut_FU_output["RD_valid"]