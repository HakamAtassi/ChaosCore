from configs import *

class ChaosCore_TB:
    def __init__(self, dut, bin):
        # Top level Module #
        self.ChaosCore = dut
        
        # Frontend Modules
        #self.fetch_packet_decoder = self.ChaosCore.frontend.decoders
        #self.predecoder           = self.ChaosCore.frontend.instruction_fetch.predecoder
        #self.rename               = self.ChaosCore.frontend.rename
        # etc...

        # Backend Modules
        #self.FU0                  = self.ChaosCore.backend.FU0


        # Top level dut #
        base_dir = os.path.dirname(__file__)
        bin = os.path.join(base_dir, bin)
        imem = SimpleDRAM(bin=bin)  # load binary into software imem
        dmem = SimpleDRAM()
        self.ChaosCore_dut = ChaosCore_dut(dut, imem, dmem) # init top dut

        # Frontend duts #
        #self.fetch_packet_decoder_dut      = fetch_packet_decoder_dut(self.fetch_packet_decoder)
        #self.predecoder_dut                = predecoder_dut(self.ChaosCore.frontend.instruction_fetch.predecoder)
        #self.ROB_dut                       = ROB_dut(self.ChaosCore.ROB)
        #self.PC_gen_dut                    = PC_gen_dut(self.ChaosCore.frontend.instruction_fetch.PC_gen)
        #self.rename_dut                    = rename_dut(self.ChaosCore.frontend.rename)

        # Backend Modules #
        #self.FU0_dut                        = FU_dut(self.FU0)

        # Memory Modules #
        # TODO


        # Agents #
        #self.fetch_packet_decoder_agent        = fetch_packet_decoder_agent(self.fetch_packet_decoder_dut)
        #self.FU0_agent                         = FU_agent(self.FU0_dut)
        #self.rename_agent                      = rename_agent(self.rename_dut)
        #self.predecoder_agent                  = predecoder_agent(self.predecoder_dut)

        #self.ROB_agent                =   ROB_agent(self.ROB_dut)




    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.ChaosCore_dut.reset()

    async def update(self): # clock with memory access
        await self.ChaosCore_dut.update()

    ################
    # START AGENTS #
    ################

    def start(self):
        # Set external readies
        self.ChaosCore_dut.write_dmem_request_ready(1)
        self.ChaosCore_dut.write_imem_request_ready(1)

        # Start Frontend Agents
        #self.fetch_packet_decoder_agent.start()
        #self.rename.start()
        #self.PC_gen_agent.start()
        #self.predecoder_agent_agent.start()

        # Start Backend Agents
        #self.FU0_agent.start()
        #self.ROB_agent.start()

    ###############
    # STOP AGENTS #
    ###############

    def stop(self):
        pass

        # Stop Frontend Agents       
        #self.fetch_packet_decoder_agent.stop()
        #self.predecoder_agent.stop()
        #self.PC_gen_agent.stop()

        # Stop Backend Agents
        #self.FU0_agent.stop()
        #self.ROB_agent.stop()
        #self.rename.stop()


