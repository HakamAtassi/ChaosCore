


class L1_dut:
    def __init__(self, dut):
        self.L1_instruction_cache = dut




    
#module instruction_cache(	// src/main/scala/Frontend/instruction_cache.scala:74:7
  #input          clock,	// src/main/scala/Frontend/instruction_cache.scala:74:7
                 #reset,	// src/main/scala/Frontend/instruction_cache.scala:74:7
                 #io_flush,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output         io_CPU_request_ready,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input          io_CPU_request_valid,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input  [31:0]  io_CPU_request_bits_addr,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_request_bits_wr_data,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input          io_CPU_request_bits_wr_en,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_response_ready,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output         io_CPU_response_valid,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_CPU_response_bits_fetch_PC,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output         io_CPU_response_bits_valid_bits_0,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_response_bits_valid_bits_1,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_response_bits_valid_bits_2,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_response_bits_valid_bits_3,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_CPU_response_bits_instructions_0_instruction,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [3:0]   io_CPU_response_bits_instructions_0_packet_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [5:0]   io_CPU_response_bits_instructions_0_ROB_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_CPU_response_bits_instructions_1_instruction,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [3:0]   io_CPU_response_bits_instructions_1_packet_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [5:0]   io_CPU_response_bits_instructions_1_ROB_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_CPU_response_bits_instructions_2_instruction,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [3:0]   io_CPU_response_bits_instructions_2_packet_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [5:0]   io_CPU_response_bits_instructions_2_ROB_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_CPU_response_bits_instructions_3_instruction,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [3:0]   io_CPU_response_bits_instructions_3_packet_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [5:0]   io_CPU_response_bits_instructions_3_ROB_index,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [15:0]  io_CPU_response_bits_GHR,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [6:0]   io_CPU_response_bits_NEXT,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_CPU_response_bits_TOS,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input          io_DRAM_request_ready,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output         io_DRAM_request_valid,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output [31:0]  io_DRAM_request_bits_addr,	// src/main/scala/Frontend/instruction_cache.scala:104:16
                 #io_DRAM_request_bits_wr_data,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #output         io_DRAM_response_ready,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input          io_DRAM_response_valid,	// src/main/scala/Frontend/instruction_cache.scala:104:16
  #input  [255:0] io_DRAM_response_bits_data	// src/main/scala/Frontend/instruction_cache.scala:104:16

    