
class cache_req extends uvm_transaction;

  `uvm_object_utils(cache_req)    
  `uvm_declare_p_sequencer(cpu_io_sequencer)

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
  
  function new(string name = "", uvm_component initiator = null);
    super.new(name, initiator);
  endfunction : new

  function string convert2string();
    return $psprintf("data: %2h", io_CPU_request_bits_addr);
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
  
  function void load_data(
      logic        io_CPU_request_ready,
      logic        io_CPU_response_valid,
      logic [31:0] io_CPU_response_bits_fetch_PC,
      logic        io_CPU_response_bits_valid_bits_0,
                    io_CPU_response_bits_valid_bits_1,
                    io_CPU_response_bits_valid_bits_2,
                    io_CPU_response_bits_valid_bits_3,
      logic [31:0] io_CPU_response_bits_instructions_0_instruction,
      logic [3:0]  io_CPU_response_bits_instructions_0_packet_index,
      logic [5:0]  io_CPU_response_bits_instructions_0_ROB_index,
      logic [31:0] io_CPU_response_bits_instructions_1_instruction,
      logic [3:0]  io_CPU_response_bits_instructions_1_packet_index,
      logic [5:0]  io_CPU_response_bits_instructions_1_ROB_index,
      logic [31:0] io_CPU_response_bits_instructions_2_instruction,
      logic [3:0]  io_CPU_response_bits_instructions_2_packet_index,
      logic [5:0]  io_CPU_response_bits_instructions_2_ROB_index,
      logic [31:0] io_CPU_response_bits_instructions_3_instruction,
      logic [3:0]  io_CPU_response_bits_instructions_3_packet_index,
      logic [5:0]  io_CPU_response_bits_instructions_3_ROB_index,
      logic        io_CPU_response_bits_prediction_hit,
      logic [31:0] io_CPU_response_bits_prediction_target,
      logic [2:0]  io_CPU_response_bits_prediction_br_type,
      logic        io_CPU_response_bits_prediction_T_NT,
      logic [15:0] io_CPU_response_bits_GHR,
      logic [6:0]  io_CPU_response_bits_NEXT,
                    io_CPU_response_bits_TOS
    );

    this.io_CPU_request_ready = io_CPU_request_ready;
    this.io_CPU_response_valid = io_CPU_response_valid;
    this.io_CPU_response_bits_fetch_PC = io_CPU_response_bits_fetch_PC;
    this.io_CPU_response_bits_valid_bits_0 = io_CPU_response_bits_valid_bits_0;
    this.io_CPU_response_bits_valid_bits_1 = io_CPU_response_bits_valid_bits_1;
    this.io_CPU_response_bits_valid_bits_2 = io_CPU_response_bits_valid_bits_2;
    this.io_CPU_response_bits_valid_bits_3 = io_CPU_response_bits_valid_bits_3;
    this.io_CPU_response_bits_instructions_0_instruction = io_CPU_response_bits_instructions_0_instruction;
    this.io_CPU_response_bits_instructions_0_packet_index = io_CPU_response_bits_instructions_0_packet_index;
    this.io_CPU_response_bits_instructions_0_ROB_index = io_CPU_response_bits_instructions_0_ROB_index;
    this.io_CPU_response_bits_instructions_1_instruction = io_CPU_response_bits_instructions_1_instruction;
    this.io_CPU_response_bits_instructions_1_packet_index = io_CPU_response_bits_instructions_1_packet_index;
    this.io_CPU_response_bits_instructions_1_ROB_index = io_CPU_response_bits_instructions_1_ROB_index;
    this.io_CPU_response_bits_instructions_2_instruction = io_CPU_response_bits_instructions_2_instruction;
    this.io_CPU_response_bits_instructions_2_packet_index = io_CPU_response_bits_instructions_2_packet_index;
    this.io_CPU_response_bits_instructions_2_ROB_index = io_CPU_response_bits_instructions_2_ROB_index;
    this.io_CPU_response_bits_instructions_3_instruction = io_CPU_response_bits_instructions_3_instruction;
    this.io_CPU_response_bits_instructions_3_packet_index = io_CPU_response_bits_instructions_3_packet_index;
    this.io_CPU_response_bits_instructions_3_ROB_index = io_CPU_response_bits_instructions_3_ROB_index;
    this.io_CPU_response_bits_prediction_hit = io_CPU_response_bits_prediction_hit;
    this.io_CPU_response_bits_prediction_target = io_CPU_response_bits_prediction_target;
    this.io_CPU_response_bits_prediction_br_type = io_CPU_response_bits_prediction_br_type;
    this.io_CPU_response_bits_prediction_T_NT = io_CPU_response_bits_prediction_T_NT;
    this.io_CPU_response_bits_GHR = io_CPU_response_bits_GHR;
    this.io_CPU_response_bits_NEXT = io_CPU_response_bits_NEXT;
    this.io_CPU_response_bits_TOS = io_CPU_response_bits_TOS;

  endfunction
endclass : cache_req