`ifndef CACHE_RSP
`define CACHE_RSP

// class cache_rsp extends uvm_sequence_item;

//   `uvm_object_utils(cache_resp)    

//   rand logic        io_CPU_request_ready;
//   rand logic        io_CPU_response_valid;
//   rand logic [31:0] io_CPU_response_bits_fetch_PC;
//   rand logic        io_CPU_response_bits_valid_bits_0;
//   rand logic              io_CPU_response_bits_valid_bits_1;
//   rand logic              io_CPU_response_bits_valid_bits_2;
//   rand logic              io_CPU_response_bits_valid_bits_3;
//   rand logic [31:0] io_CPU_response_bits_instructions_0_instruction;
//   rand logic [3:0]  io_CPU_response_bits_instructions_0_packet_index;
//   rand logic [5:0]  io_CPU_response_bits_instructions_0_ROB_index;
//   rand logic [31:0] io_CPU_response_bits_instructions_1_instruction;
//   rand logic [3:0]  io_CPU_response_bits_instructions_1_packet_index;
//   rand logic [5:0]  io_CPU_response_bits_instructions_1_ROB_index;
//   rand logic [31:0] io_CPU_response_bits_instructions_2_instruction;
//   rand logic [3:0]  io_CPU_response_bits_instructions_2_packet_index;
//   rand logic [5:0]  io_CPU_response_bits_instructions_2_ROB_index;
//   rand logic [31:0] io_CPU_response_bits_instructions_3_instruction;
//   rand logic [3:0]  io_CPU_response_bits_instructions_3_packet_index;
//   rand logic [5:0]  io_CPU_response_bits_instructions_3_ROB_index;
//   rand logic        io_CPU_response_bits_prediction_hit;
//   rand logic [31:0] io_CPU_response_bits_prediction_target;
//   rand logic [2:0]  io_CPU_response_bits_prediction_br_type;
//   rand logic        io_CPU_response_bits_prediction_T_NT;
//   rand logic [15:0] io_CPU_response_bits_GHR;
//   rand logic [6:0]  io_CPU_response_bits_NEXT;
//   rand logic              io_CPU_response_bits_TOS;
  
//   function new(string name = "");
//     super.new(name);
//   endfunction : new

//   function string convert2string();
//     return $psprintf("io_CPU_request_ready: %2h\n" +
//                       "io_CPU_response_valid: %2h\n" +
//                       "io_CPU_response_bits_fetch_PC: %2h\n" +
//                       "io_CPU_response_bits_valid_bits_0: %2h\n" +
//                       "io_CPU_response_bits_valid_bits_1: %2h\n" +
//                       "io_CPU_response_bits_valid_bits_2: %2h\n" +
//                       "io_CPU_response_bits_valid_bits_3: %2h\n" +
//                       "io_CPU_response_bits_instructions_0_instruction: %2h\n" +
//                       "io_CPU_response_bits_instructions_0_packet_index: %2h\n" +
//                       "io_CPU_response_bits_instructions_0_ROB_index: %2h\n" +
//                       "io_CPU_response_bits_instructions_1_instruction: %2h\n" +
//                       "io_CPU_response_bits_instructions_1_packet_index: %2h\n" +
//                       "io_CPU_response_bits_instructions_1_ROB_index: %2h\n" +
//                       "io_CPU_response_bits_instructions_2_instruction: %2h\n" +
//                       "io_CPU_response_bits_instructions_2_packet_index: %2h\n" +
//                       "io_CPU_response_bits_instructions_2_ROB_index: %2h\n" +
//                       "io_CPU_response_bits_prediction_hit: %2h\n" +
//                       "io_CPU_response_bits_prediction_target: %2h\n" +
//                       "io_CPU_response_bits_prediction_br_type: %2h\n" +
//                       "io_CPU_response_bits_prediction_T_NT: %2h\n" +
//                       "io_CPU_response_bits_GHR: %2h\n" +
//                       "io_CPU_response_bits_NEXT: %2h\n" +
//                       "io_CPU_response_bits_TOS: %2h\n", 
//                       io_CPU_request_ready,
//                       io_CPU_response_valid,
//                       io_CPU_response_bits_fetch_PC,
//                       io_CPU_response_bits_valid_bits_0,
//                       io_CPU_response_bits_valid_bits_1,
//                       io_CPU_response_bits_valid_bits_2,
//                       io_CPU_response_bits_valid_bits_3,
//                       io_CPU_response_bits_instructions_0_instruction,
//                       io_CPU_response_bits_instructions_0_packet_index,
//                       io_CPU_response_bits_instructions_0_ROB_index,
//                       io_CPU_response_bits_instructions_1_instruction,
//                       io_CPU_response_bits_instructions_1_packet_index,
//                       io_CPU_response_bits_instructions_1_ROB_index,
//                       io_CPU_response_bits_instructions_2_instruction,
//                       io_CPU_response_bits_instructions_2_packet_index,
//                       io_CPU_response_bits_instructions_2_ROB_index,
//                       io_CPU_response_bits_instructions_3_instruction,
//                       io_CPU_response_bits_instructions_3_packet_index,
//                       io_CPU_response_bits_instructions_3_ROB_index,
//                       io_CPU_response_bits_prediction_hit,
//                       io_CPU_response_bits_prediction_target,
//                       io_CPU_response_bits_prediction_br_type,
//                       io_CPU_response_bits_prediction_T_NT,
//                       io_CPU_response_bits_GHR,
//                       io_CPU_response_bits_NEXT,
//                       io_CPU_response_bits_TOS,
//                       );
//   endfunction : convert2string

//   function void do_copy(uvm_object rhs);
//     cache_resp  RHS;
//     super.do_copy(rhs);
//     $cast(RHS, rhs);
//   endfunction : do_copy
  
//   function bit comp(uvm_object rhs);
//     // Please create a comp function that returns 1 if rhs is identical to this object.
//     // Please remove the line below.
//     `uvm_fatal("cache_write.svh", "The comp() function has not been written");
//   endfunction : comp

// endclass : cache_resp

`endif