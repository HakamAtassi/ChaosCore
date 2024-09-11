`ifndef CACHE_RESP
`define CACHE_RESP

`include "cpu_io_sequencer.svh"

class cache_resp extends uvm_sequence_item;

  `uvm_object_utils(cache_resp)    
  `uvm_declare_p_sequencer(cpu_io_sequencer)

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
    return $psprintf("data: %2h", io_CPU_request_bits_addr);
  endfunction : convert2string

  function void do_copy(uvm_object rhs);
    cache_resp  RHS;
    super.do_copy(rhs);
    $cast(RHS, rhs);
  endfunction : do_copy
  
  function bit comp(uvm_object rhs);
     // Please create a comp function that returns 1 if rhs is identical to this object.
     // Please remove the line below.
     `uvm_fatal("cache_write.svh", "The comp() function has not been written");
  endfunction : comp
  
  function void load_data(
    logic io_CPU_request_valid,
    logic[31:0] io_CPU_request_bits_addr,
    logic[31:0] io_CPU_request_bits_wr_data,
    logic io_CPU_request_bits_wr_en,
    logic io_CPU_response_ready,
    logic io_kill
    );

    this.io_CPU_request_valid = io_CPU_request_valid;
    this.io_CPU_request_bits_addr = io_CPU_request_bits_addr;
    this.io_CPU_request_bits_wr_data = io_CPU_request_bits_wr_data;
    this.io_CPU_request_bits_wr_en = io_CPU_request_bits_wr_en;
    this.io_CPU_response_ready = io_CPU_response_ready;
    this.io_kill = io_kill;

  endfunction
endclass : cache_resp

`endif