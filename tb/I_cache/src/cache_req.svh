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
  rand logic io_kill;
  
  function new(string name = "");
    super.new(name);
  endfunction : new

  function string convert2string();
    return $psprintf(
                      "reset: %b\n" + 
                      "io_CPU_request_valid: %2h\n" + 
                      "io_CPU_request_bits_addr: %2h\n" + 
                      "io_CPU_request_bits_wr_data: %2h\n" + 
                      "io_CPU_request_bits_wr_en: %2h\n" + 
                      "io_CPU_response_ready: %2h\n" + 
                      "io_kill: %2h\n",
                      reset,
                      io_CPU_request_valid,
                      io_CPU_request_bits_addr,
                      io_CPU_request_bits_wr_data,
                      io_CPU_request_bits_wr_en,
                      io_CPU_response_ready,
                      io_kill
                      );
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
  
  function new(string name = "");
    super.new(name);
  endfunction : new

  function string convert2string();
    return $psprintf("io_CPU_request_ready: %2h\n" +
                      "io_CPU_response_valid: %2h\n" +
                      "io_CPU_response_bits_fetch_PC: %2h\n" +
                      "io_CPU_response_bits_valid_bits_0: %2h\n" +
                      "io_CPU_response_bits_valid_bits_1: %2h\n" +
                      "io_CPU_response_bits_valid_bits_2: %2h\n" +
                      "io_CPU_response_bits_valid_bits_3: %2h\n" +
                      "io_CPU_response_bits_instructions_0_instruction: %2h\n" +
                      "io_CPU_response_bits_instructions_0_packet_index: %2h\n" +
                      "io_CPU_response_bits_instructions_0_ROB_index: %2h\n" +
                      "io_CPU_response_bits_instructions_1_instruction: %2h\n" +
                      "io_CPU_response_bits_instructions_1_packet_index: %2h\n" +
                      "io_CPU_response_bits_instructions_1_ROB_index: %2h\n" +
                      "io_CPU_response_bits_instructions_2_instruction: %2h\n" +
                      "io_CPU_response_bits_instructions_2_packet_index: %2h\n" +
                      "io_CPU_response_bits_instructions_2_ROB_index: %2h\n" +
                      "io_CPU_response_bits_prediction_hit: %2h\n" +
                      "io_CPU_response_bits_prediction_target: %2h\n" +
                      "io_CPU_response_bits_prediction_br_type: %2h\n" +
                      "io_CPU_response_bits_prediction_T_NT: %2h\n" +
                      "io_CPU_response_bits_GHR: %2h\n" +
                      "io_CPU_response_bits_NEXT: %2h\n" +
                      "io_CPU_response_bits_TOS: %2h\n",
                      io_CPU_request_ready,
                      io_CPU_response_valid,
                      io_CPU_response_bits_fetch_PC,
                      io_CPU_response_bits_valid_bits_0,
                      io_CPU_response_bits_valid_bits_1,
                      io_CPU_response_bits_valid_bits_2,
                      io_CPU_response_bits_valid_bits_3,
                      io_CPU_response_bits_instructions_0_instruction,
                      io_CPU_response_bits_instructions_0_packet_index,
                      io_CPU_response_bits_instructions_0_ROB_index,
                      io_CPU_response_bits_instructions_1_instruction,
                      io_CPU_response_bits_instructions_1_packet_index,
                      io_CPU_response_bits_instructions_1_ROB_index,
                      io_CPU_response_bits_instructions_2_instruction,
                      io_CPU_response_bits_instructions_2_packet_index,
                      io_CPU_response_bits_instructions_2_ROB_index,
                      io_CPU_response_bits_instructions_3_instruction,
                      io_CPU_response_bits_instructions_3_packet_index,
                      io_CPU_response_bits_instructions_3_ROB_index,
                      io_CPU_response_bits_prediction_hit,
                      io_CPU_response_bits_prediction_target,
                      io_CPU_response_bits_prediction_br_type,
                      io_CPU_response_bits_prediction_T_NT,
                      io_CPU_response_bits_GHR,
                      io_CPU_response_bits_NEXT,
                      io_CPU_response_bits_TOS,
                      );
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


class base_sequence extends uvm_sequence#(cache_req, cache_rsp);

  `uvm_object_utils(base_sequence)

  cache_req req;

  function new(string name = "");
    super.new(name);
  endfunction : new

  task body;

    req = new();
    start_item(req);
    req.reset = 1;
    `uvm_info("test_seq","Sent Reset",UVM_MEDIUM);
    finish_item(req);
    get_response(rsp);
    `uvm_info("test_seq",{"Got back: ",rsp.convert2string()},UVM_MEDIUM);

    repeat(1) begin
      req = new();
      start_item(req);
      assert(req.randomize());
      `uvm_info("test_seq",{"Sending transaction ",req.convert2string()}, UVM_MEDIUM);
      finish_item(req);
    end
  endtask

endclass
`endif