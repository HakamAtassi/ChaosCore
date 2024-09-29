`ifndef CACHE_REQ
`define CACHE_REQ


class cache_req extends uvm_sequence_item;

  `uvm_object_utils(cache_req)    

  rand logic reset;
  rand logic io_CPU_request_valid;
  rand logic[31:0] io_CPU_request_bits_addr;
  rand logic[31:0] io_CPU_request_bits_wr_data;
  rand logic io_CPU_request_bits_wr_en;
  rand logic io_CPU_response_ready;

  rand logic io_flush_valid;
  rand logic io_flush_bits_is_misprediction;
  rand logic io_flush_bits_is_exception;
  rand logic io_flush_bits_is_fence;
  rand logic io_flush_bits_is_CSR;
  rand logic [31:0] io_flush_bits_flushing_PC;
  rand logic [31:0] io_flush_bits_redirect_PC;

  constraint c_wr_data { io_CPU_request_bits_wr_data == 0; }
  constraint c_wr_en { io_CPU_request_bits_wr_en == 0; }
  
  function new(string name = "");
    super.new(name);
  endfunction : new

  function string convert2string();
    return $psprintf(
                      "reset: %1b\n", reset ,
                      "io_CPU_request_valid: %2h\n", io_CPU_request_valid,
                      "io_CPU_request_bits_addr: %2h\n", io_CPU_request_bits_addr,
                      "io_CPU_request_bits_wr_data: %2h\n", io_CPU_request_bits_addr,
                      "io_CPU_request_bits_wr_en: %2h\n", io_CPU_request_bits_wr_en,
                      "io_CPU_response_ready: %2h\n", io_CPU_response_ready,
                      "io_flush_valid: %2h\n", io_flush_valid);
  endfunction : convert2string

  function void do_copy(uvm_object rhs);
    cache_req  RHS;
    super.do_copy(rhs);
    $cast(RHS, rhs);
  endfunction : do_copy
  
  function bit comp(uvm_object rhs);
     // Please create a comp function that returns 1 if rhs is identical to this object.
     // Please remove the line below.
     `uvm_fatal("cache_write.svh", "The comp() function has not been written");
  endfunction : comp

endclass : cache_req

class cache_rsp extends uvm_sequence_item;

  `uvm_object_utils(cache_rsp)    

  rand logic        io_CPU_request_ready;
  rand logic        io_CPU_response_valid;
  rand logic [31:0] io_CPU_response_bits_fetch_PC;
  rand logic        io_CPU_response_bits_valid_bits_0;
  rand logic              io_CPU_response_bits_valid_bits_1;
  rand logic              io_CPU_response_bits_valid_bits_2;
  rand logic              io_CPU_response_bits_valid_bits_3;
  rand logic [31:0] io_CPU_response_bits_instructions_0_instruction;
  rand logic [3:0]  io_CPU_response_bits_instructions_0_packet_index;
  rand logic [5:0]  io_CPU_response_bits_instructions_0_ROB_index;
  rand logic [31:0] io_CPU_response_bits_instructions_1_instruction;
  rand logic [3:0]  io_CPU_response_bits_instructions_1_packet_index;
  rand logic [5:0]  io_CPU_response_bits_instructions_1_ROB_index;
  rand logic [31:0] io_CPU_response_bits_instructions_2_instruction;
  rand logic [3:0]  io_CPU_response_bits_instructions_2_packet_index;
  rand logic [5:0]  io_CPU_response_bits_instructions_2_ROB_index;
  rand logic [31:0] io_CPU_response_bits_instructions_3_instruction;
  rand logic [3:0]  io_CPU_response_bits_instructions_3_packet_index;
  rand logic [5:0]  io_CPU_response_bits_instructions_3_ROB_index;
  rand logic        io_CPU_response_bits_prediction_hit;
  rand logic [31:0] io_CPU_response_bits_prediction_target;
  rand logic [2:0]  io_CPU_response_bits_prediction_br_type;
  rand logic        io_CPU_response_bits_prediction_T_NT;
  rand logic [15:0] io_CPU_response_bits_GHR;
  rand logic [6:0]  io_CPU_response_bits_NEXT;
  rand logic              io_CPU_response_bits_TOS;

  bit long;
  
  function new(string name = "");
    super.new(name);
    long = 0;
  endfunction : new

  function string convert2string();
    if (long) begin
      return $psprintf("io_CPU_request_ready: %2h\n", io_CPU_request_ready,
                        "io_CPU_response_valid: %2h\n", io_CPU_response_valid,
                        "io_CPU_response_bits_fetch_PC: %2h\n", io_CPU_response_bits_fetch_PC,
                        "io_CPU_response_bits_valid_bits_0: %2h\n", io_CPU_response_bits_valid_bits_0,
                        "io_CPU_response_bits_valid_bits_1: %2h\n", io_CPU_response_bits_valid_bits_1,
                        "io_CPU_response_bits_valid_bits_2: %2h\n", io_CPU_response_bits_valid_bits_2,
                        "io_CPU_response_bits_valid_bits_3: %2h\n", io_CPU_response_bits_valid_bits_3,
                        "io_CPU_response_bits_instructions_0_instruction: %2h\n", io_CPU_response_bits_instructions_0_instruction,
                        "io_CPU_response_bits_instructions_0_packet_index: %2h\n", io_CPU_response_bits_instructions_0_packet_index,
                        "io_CPU_response_bits_instructions_0_ROB_index: %2h\n", io_CPU_response_bits_instructions_0_ROB_index,
                        "io_CPU_response_bits_instructions_1_instruction: %2h\n", io_CPU_response_bits_instructions_1_instruction,
                        "io_CPU_response_bits_instructions_1_packet_index: %2h\n", io_CPU_response_bits_instructions_1_packet_index,
                        "io_CPU_response_bits_instructions_1_ROB_index: %2h\n", io_CPU_response_bits_instructions_1_ROB_index,
                        "io_CPU_response_bits_instructions_2_instruction: %2h\n", io_CPU_response_bits_instructions_2_instruction,
                        "io_CPU_response_bits_instructions_2_packet_index: %2h\n", io_CPU_response_bits_instructions_2_packet_index,
                        "io_CPU_response_bits_instructions_2_ROB_index: %2h\n", io_CPU_response_bits_instructions_2_ROB_index,
                        "io_CPU_response_bits_instructions_3_instruction: %2h\n", io_CPU_response_bits_instructions_3_instruction,
                        "io_CPU_response_bits_instructions_3_packet_index: %2h\n", io_CPU_response_bits_instructions_3_packet_index,
                        "io_CPU_response_bits_instructions_3_ROB_index: %2h\n", io_CPU_response_bits_instructions_3_ROB_index,
                        "io_CPU_response_bits_prediction_hit: %2h\n", io_CPU_response_bits_prediction_hit,
                        "io_CPU_response_bits_prediction_target: %2h\n", io_CPU_response_bits_prediction_target,
                        "io_CPU_response_bits_prediction_br_type: %2h\n", io_CPU_response_bits_prediction_br_type,
                        "io_CPU_response_bits_prediction_T_NT: %2h\n", io_CPU_response_bits_prediction_T_NT,
                        "io_CPU_response_bits_GHR: %2h\n", io_CPU_response_bits_GHR,
                        "io_CPU_response_bits_NEXT: %2h\n", io_CPU_response_bits_NEXT,
                        "io_CPU_response_bits_TOS: %2h\n", io_CPU_response_bits_TOS);
    end else begin
      return $psprintf("io_CPU_request_ready: %2h\n", io_CPU_request_ready,
                        "io_CPU_response_valid: %2h\n", io_CPU_response_valid,
                        "io_CPU_response_bits_fetch_PC: %2h\n", io_CPU_response_bits_fetch_PC,
                        "io_CPU_response_bits_valid_bits_0: %b\n", io_CPU_response_bits_valid_bits_0,
                        "io_CPU_response_bits_valid_bits_1: %b\n", io_CPU_response_bits_valid_bits_1,
                        "io_CPU_response_bits_valid_bits_2: %b\n", io_CPU_response_bits_valid_bits_2,
                        "io_CPU_response_bits_valid_bits_3: %b\n", io_CPU_response_bits_valid_bits_3,
                        "io_CPU_response_bits_instructions_0_instruction: %2h\n", io_CPU_response_bits_instructions_0_instruction,
                        "io_CPU_response_bits_instructions_1_instruction: %2h\n", io_CPU_response_bits_instructions_1_instruction,
                        "io_CPU_response_bits_instructions_2_instruction: %2h\n", io_CPU_response_bits_instructions_2_instruction,
                        "io_CPU_response_bits_instructions_3_instruction: %2h\n", io_CPU_response_bits_instructions_3_instruction
                        /*
                        "io_CPU_response_bits_prediction_hit: %2h\n", io_CPU_response_bits_prediction_hit,
                        "io_CPU_response_bits_prediction_target: %2h\n", io_CPU_response_bits_prediction_target,
                        "io_CPU_response_bits_prediction_br_type: %2h\n", io_CPU_response_bits_prediction_br_type,
                        "io_CPU_response_bits_prediction_T_NT: %2h\n", io_CPU_response_bits_prediction_T_NT,
                        "io_CPU_response_bits_GHR: %2h\n", io_CPU_response_bits_GHR,
                        "io_CPU_response_bits_NEXT: %2h\n", io_CPU_response_bits_NEXT,
                        "io_CPU_response_bits_TOS: %2h\n", io_CPU_response_bits_TOS
                        */
                        );
    end


  endfunction : convert2string

  function void do_copy(uvm_object rhs);
    cache_rsp  RHS;
    super.do_copy(rhs);
    $cast(RHS, rhs);
  endfunction : do_copy
  
  function bit comp(uvm_object rhs);
    // Please create a comp function that returns 1 if rhs is identical to this object.
    // Please remove the line below.
    `uvm_fatal("cache_write.svh", "The comp() function has not been written");
  endfunction : comp

endclass : cache_rsp


class cache_transaction extends cache_rsp;
  `uvm_object_utils(cache_transaction)   

  rand logic reset;
  rand logic io_CPU_request_valid;
  rand logic[31:0] io_CPU_request_bits_addr;
  rand logic[31:0] io_CPU_request_bits_wr_data;
  rand logic io_CPU_request_bits_wr_en;
  rand logic io_CPU_response_ready;

  rand logic io_flush_valid;
  rand logic io_flush_bits_is_misprediction;
  rand logic io_flush_bits_is_exception;
  rand logic io_flush_bits_is_fence;
  rand logic io_flush_bits_is_CSR;
  rand logic [31:0] io_flush_bits_flushing_PC;
  rand logic [31:0] io_flush_bits_redirect_PC;

  function new(string name = "");
    super.new(name);
  endfunction : new

  function string convert2string();
    return $psprintf("Request:\n ",
                    "reset: %1b\n", reset ,
                    "io_CPU_request_valid: %2h\n", io_CPU_request_valid,
                    "io_CPU_request_bits_addr: %2h\n", io_CPU_request_bits_addr,
                    "io_CPU_request_bits_wr_data: %2h\n", io_CPU_request_bits_addr,
                    "io_CPU_request_bits_wr_en: %2h\n", io_CPU_request_bits_wr_en,
                    "io_CPU_response_ready: %2h\n", io_CPU_response_ready,
                    "io_flush_valid: %2h\n", io_flush_valid,
                    "Response: \n%s\n",super.convert2string()
                    );
  endfunction


  function bit comp(uvm_object rhs);
    cache_transaction RHS;
    $cast(RHS,rhs);
    return (io_CPU_response_bits_instructions_0_instruction === RHS.io_CPU_response_bits_instructions_0_instruction) && 
                  (io_CPU_response_bits_instructions_1_instruction === RHS.io_CPU_response_bits_instructions_1_instruction) &&
                  (io_CPU_response_bits_instructions_2_instruction === RHS.io_CPU_response_bits_instructions_2_instruction) && 
                  (io_CPU_response_bits_instructions_3_instruction === RHS.io_CPU_response_bits_instructions_3_instruction);
  endfunction : comp
endclass 
`endif