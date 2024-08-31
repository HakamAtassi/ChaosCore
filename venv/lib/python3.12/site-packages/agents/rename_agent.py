import logging
from cocotb_utils import *
from rename import rename_model

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)


class rename_agent:
    def __init__(self, dut):
        self.dut = dut
        self.model = rename_model()

        ########################
        # FETCH PACKET DECODER #
        ########################
        # ---------------
        # INPUT MONITORS
        # ---------------
        self.flush_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),   # monitor flush only when input is valid (for now)
            data=lambda: self.dut.read_flush(),
        )

        self.commit_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_commit(),
        )

        self.decoded_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_decoded_fetch_packet(),
        )

        self.FU_outputs_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_FU_outputs(),
        )


        # ----------------
        # OUTPUT MONITORS
        # ----------------
        self.renamed_decoded_fetch_packet_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.renamed_decoded_fetch_packet_valid(),
            data=lambda: self.dut.read_renamed_decoded_fetch_packet(),
        )

        self.RAT_memories_mon = Monitor(
            clock=self.dut.clock(),
            valid=self.dut.clock(),
            data=lambda: self.dut.read_RAT_memories(),
        )

        self.scoreboard    = None

    def start(self):
        if self.scoreboard != None:
            raise RuntimeError("fetch_packet_decoder scoreboard already started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.flush_mon.start()
        self.commit_mon.start()
        self.decoded_fetch_packet_mon.start()
        self.FU_outputs_mon.start()
        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.renamed_decoded_fetch_packet_mon.start()
        
        # ------
        # START
        # ------
        self.scoreboard = cocotb.start_soon(self.run())
        #self.RAT_memories_mon.start()

    def stop(self):
        if self.scoreboard is None:
            raise RuntimeError("FU Scoreboard never started")

        # -----------------
        # INPUT MONITORS
        # -----------------
        self.flush_mon.stop()
        self.commit_mon.stop()
        self.decoded_fetch_packet_mon.stop()
        self.FU_outputs_mon.stop()

        # -----------------
        # OUTPUT MONITORS
        # -----------------
        self.renamed_decoded_fetch_packet_mon.stop()
        #self.RAT_memories_mon.stop()

        # -----
        # STOP
        # -----
        self.scoreboard.kill()
        self.scoreboard = 0


    async def run(self):
        while True:
            pass

            # -----------------
            # INPUT MONITORS
            # -----------------
            flush = await self.flush_mon.values.get()
            commit = await self.commit_mon.values.get()
            decoded_fetch_packet = await self.decoded_fetch_packet_mon.values.get()
            FU_outputs = await self.FU_outputs_mon.values.get()



            # ------------
            # DRIVE MODEL
            # ------------

            self.model.inputs(flush, commit, decoded_fetch_packet, FU_outputs)
            self.model.eval()
            #model_FU_output = self.model.get_FU_output()

            # -----------------
            # OUTPUT MONITORS
            # ------------------

            sim_time = cocotb.utils.get_sim_time('ns')
            #logger.info(f"Asserted @ {sim_time}")

            try: 
                dut_renamed_decoded_fetch_packet = self.renamed_decoded_fetch_packet_mon.values.get_nowait()

                model_renamed_decoded_fetch_packet = self.model.renamed_decoded_fetch_packet_queue.pop(0)
                #print(f"dut {dut_renamed_decoded_fetch_packet["PRD"]} {dut_renamed_decoded_fetch_packet["RD_valid"]}")
                #print(f"model {model_renamed_decoded_fetch_packet["PRD"]} {model_renamed_decoded_fetch_packet["RD_valid"]}")
                #print("\n\n\n")

                for i in range(4):
                    RD_valid = model_renamed_decoded_fetch_packet["RD_valid"][i]
                    RS1_valid = model_renamed_decoded_fetch_packet["RS1_valid"][i] or  dut_renamed_decoded_fetch_packet["RS1_valid"][i]
                    RS2_valid = model_renamed_decoded_fetch_packet["RS2_valid"][i] or  dut_renamed_decoded_fetch_packet["RS2_valid"][i]
                    if(RD_valid):assert(dut_renamed_decoded_fetch_packet["PRD"][i] == model_renamed_decoded_fetch_packet["PRD"][i])
                    if(RS1_valid):
                        assert(dut_renamed_decoded_fetch_packet["RS1"][i] == model_renamed_decoded_fetch_packet["RS1"][i])
                        #print(dut_renamed_decoded_fetch_packet["RS1"][i])
                        #print(model_renamed_decoded_fetch_packet["RS1"][i])
                    if(RS2_valid): 
                        assert(dut_renamed_decoded_fetch_packet["RS2"][i] == model_renamed_decoded_fetch_packet["RS2"][i])
                        #print(dut_renamed_decoded_fetch_packet["RS2"][i])
                        #print(model_renamed_decoded_fetch_packet["RS2"][i])
                    #assert(dut_renamed_decoded_fetch_packet["RS2"][i] == model_renamed_decoded_fetch_packet["RS2"][i])




                #dut_RAT = await self.RAT_memories_mon.values.get()
                #model_RAT = self.model.RAT_memories

                #print(f"dut {dut_RAT}")
                #print(f"model {model_RAT}")


                


            except(cocotb.queue.QueueEmpty):
                pass

            # -----------
            # ASSERTIONS
            # -----------




            #assert model_FU_output["valid"] == dut_FU_output["valid"]
            #assert model_FU_output["fetch_PC"] == dut_FU_output["fetch_PC"]

            #valid = model_FU_output["valid"]
            #compare_RD = model_FU_output["PRD"] & valid
            #if(compare_RD & valid):
                #assert model_FU_output["PRD"] == dut_FU_output["PRD"]
                #assert model_FU_output["RD_data"] == dut_FU_output["RD_data"]
                #assert model_FU_output["RD_valid"] == dut_FU_output["RD_valid"]