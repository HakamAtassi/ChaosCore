import cocotb.queue
from cocotb_utils import *
from ROB import ROB_model
import logging

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

class ROB_agent:
    def __init__(self, dut):
        self.dut = dut
        self.model = ROB_model()

        ########################
        # FETCH PACKET DECODER #
        ########################
        # ---------------
        # INPUT MONITORS
        # ---------------
        self.flush_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.flush(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_flush(),
        )
        self.ROB_packet_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.ROB_packet_valid(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_ROB_packet()
        )
        self.FU0_outputs_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.FU_outputs_valid(0),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_FU_outputs(0)
        )
        self.FU1_outputs_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.FU_outputs_valid(1),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_FU_outputs(1)
        )
        self.FU2_outputs_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.FU_outputs_valid(2),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_FU_outputs(2)
        )
        self.FU3_outputs_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.FU_outputs_valid(3),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_FU_outputs(3)
        )
        self.commit_mon = Monitor(
            clock=self.dut.clock(),
            #valid=self.dut.commit_valid(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_commit()
        )
        self.PC_file_exec_addr_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_PC_file_exec_addr()
        )

        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.ROB_output_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.ROB_output_valid(),
            data=lambda: self.dut.read_ROB_output(),
        )
        self.ROB_index_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_ROB_index()
        )
        self.PC_file_exec_data_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_PC_file_exec_data()
        )

        self.scoreboard    = None

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("ROB scoreboard already started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.flush_mon.start()
        self.ROB_packet_mon.start()
        self.FU0_outputs_mon.start()
        self.FU1_outputs_mon.start()
        self.FU2_outputs_mon.start()
        self.FU3_outputs_mon.start()
        self.commit_mon.start()
        self.PC_file_exec_addr_mon.start()

        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.ROB_output_mon.start()
        self.ROB_index_mon.start()
        self.PC_file_exec_data_mon.start()

        # ------
        # START
        # ------
        self.scoreboard = cocotb.start_soon(self.run())

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("ROB Scoreboard never started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.flush_mon.stop()
        self.ROB_packet_mon.stop()
        self.FU0_outputs_mon.stop()
        self.FU1_outputs_mon.stop()
        self.FU2_outputs_mon.stop()
        self.FU3_outputs_mon.stop()
        self.commit_mon.stop()
        self.PC_file_exec_addr_mon.stop()

        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.ROB_output_mon.stop()
        self.ROB_index_mon.stop()
        self.PC_file_exec_data_mon.stop()

        # -----
        # STOP
        # -----
        self.scoreboard.kill()
        self.scoreboard = 0


    async def run(self):
        while True:
            await RisingEdge(self.dut.clock())

            #logger.info(f"asserted {cocotb.utils.get_sim_time("ns")}")

            ##############
            # Get inputs #
            ##############

            flush               = await self.flush_mon.values.get()
            ROB_packet          = await self.ROB_packet_mon.values.get()
            FU0_outputs         = await self.FU0_outputs_mon.values.get()
            FU1_outputs         = await self.FU1_outputs_mon.values.get()
            FU2_outputs         = await self.FU2_outputs_mon.values.get()
            FU3_outputs         = await self.FU3_outputs_mon.values.get()
            commit              = await self.commit_mon.values.get()
            PC_file_exec_addr   = await self.PC_file_exec_addr_mon.values.get()

            ##################
            # evaluate model #
            ##################

            self.model.inputs(
                flush=flush,
                ROB_packet=ROB_packet,
                FU0_outputs=FU0_outputs,
                FU1_outputs=FU1_outputs,
                FU2_outputs=FU2_outputs,
                FU3_outputs=FU3_outputs,
                commit=commit,
                PC_file_exec_addr=PC_file_exec_addr
            )

            self.model.eval()


            ############################
            # Compare outputs (if any) #
            ############################


            # for each port, try to get the output, 
            # if dut has output but model doesnt, dut had an extra valid somewhere

            try:
                dut_ROB_output = self.ROB_output_mon.values.get_nowait()
                model_ROB_output = self.model.ROB_output_queue.pop(0)

                #print(f"dut: {dut_ROB_output}")
                #print(f"model: {model_ROB_output}")

                logger.info(f"Assertions @ {cocotb.utils.get_sim_time("ns")}")

                assert dut_ROB_output["row_valid"]  == model_ROB_output["row_valid"]
                #assert dut_ROB_output["ROB_index"] == model_ROB_output["ROB_index"]
                assert dut_ROB_output["fetch_PC"]   == model_ROB_output["fetch_PC"]
                assert dut_ROB_output["is_branch"]  == model_ROB_output["is_branch"]
                assert dut_ROB_output["is_load"]    == model_ROB_output["is_load"]
                assert dut_ROB_output["is_store"]   == model_ROB_output["is_store"]
                assert dut_ROB_output["free_list_front_pointer"]   == model_ROB_output["free_list_front_pointer"]
                

                assert dut_ROB_output["entry_valid"]   == model_ROB_output["entry_valid"]





            except(cocotb.queue.QueueEmpty):
                pass
            except(IndexError):
                logger.critical(f"Dut has an extra valid ROB output")
                assert False


            

            # Get outputs
            #ROB_output          = self.ROB_output_mon.get()
            #ROB_index           = self.ROB_index_mon.get()
            #PC_file_exec_data   = self.PC_file_exec_data_mon.get()



