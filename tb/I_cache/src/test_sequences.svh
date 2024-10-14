
`ifndef TEST_SEQUENCES
`define TEST_SEQUENCES

`include "cache_req.svh"
class base_sequence extends uvm_sequence#(cache_req, cache_rsp);

  `uvm_object_utils(base_sequence)

  cache_req req;

  function new(string name = "");
    super.new(name);
  endfunction : new

  task generate_instruction(integer address);
    req = new();
    start_item(req);
    req.added_delay = $urandom_range(0,63);
    req.reset = 0;
    req.io_CPU_request_valid = 1;
    req.io_CPU_request_bits_addr = address;
    req.io_CPU_response_ready = 1;
    req.io_flush_valid = 0;
    `uvm_info("test_seq",{"Sending transaction:\n ",req.convert2string()}, UVM_HIGH);
    finish_item(req);
    get_response(rsp);
    `uvm_info("test_seq",{"Got back:\n ",rsp.convert2string()},UVM_HIGH);
  endtask

  task reset;
    req = new();
    start_item(req);
    req.reset = 1;
    `uvm_info("test_seq","Sent Reset", UVM_HIGH);
    finish_item(req);
  endtask

  task flush;
    req = new();
    start_item(req);
    req.reset = 0;
    req.io_CPU_request_valid = 0;
    req.io_CPU_request_bits_addr = 0;
    req.io_CPU_response_ready = 0;
    req.io_flush_valid = 1;
    `uvm_info("test_seq","Sending flush:", UVM_HIGH);
    finish_item(req);
    `uvm_info("test_seq",{"Got back:\n ",rsp.convert2string()},UVM_HIGH);
  endtask

  task body;
    reset();
  endtask

endclass

class random_address extends base_sequence;

  `uvm_object_utils(random_address)

  function new(string name = "");
    super.new(name);
  endfunction : new

  task body;
    `uvm_info("SEQ","RUNNING RANDOM ADDRESS SEQUENCE", UVM_MEDIUM);
    super.body();
    repeat(1000) begin
      generate_instruction(($urandom_range(0,16383) / 4) * 4);
    end
  endtask

endclass

class random_address_with_flush extends base_sequence;

  `uvm_object_utils(random_address_with_flush)

  function new(string name = "");
    super.new(name);
  endfunction : new

  task seq_task;
    repeat(3) begin
      generate_instruction(($urandom_range(0,16383) / 4) * 4);
    end

    flush();

    repeat(3) begin
      generate_instruction(($urandom_range(0,16383) / 4) * 4);
    end
  endtask

  task body;
    `uvm_info("SEQ","RUNNING RANDOM ADDRESS SEQUENCE", UVM_MEDIUM);
    super.body();
    seq_task();
  endtask

endclass

class random_with_flush_repeated extends random_address_with_flush;

  `uvm_object_utils(random_with_flush_repeated)

  function new(string name = "");
    super.new(name);
  endfunction : new

  task body;
    `uvm_info("SEQ","RUNNING RANDOM ADDRESS SEQUENCE", UVM_MEDIUM);
    repeat(3) begin
      reset();
      repeat(300) begin
        seq_task();
      end
    end
  endtask

endclass



class custom_seq extends base_sequence;

  `uvm_object_utils(custom_seq)

  function new(string name = "");
    super.new(name);
  endfunction : new

  task body;
    `uvm_info("SEQ","RUNNING DIRECTED SEQUENCE", UVM_MEDIUM);
    super.body();
    generate_instruction(0);
    generate_instruction(0);
    generate_instruction(0);
    generate_instruction(32'h1000);
  endtask

endclass

`endif