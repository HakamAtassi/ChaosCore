`ifndef CPU_IO_AGENT
`define CPU_IO_AGENT



`include "cpu_io_monitor.svh"
`include "cpu_io_driver.svh"
`include "cache_agent.svh"
`include "cache_req.svh"

class cpu_io_agent extends cache_agent;

    `uvm_component_utils(cpu_io_agent)

    cpu_io_driver driver;
    cpu_io_monitor monitor;
    uvm_sequencer #(base_sequence) sequencer; 

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("AGENT","Creating CPU IO Agent...",500);
        super.build_phase(phase);
        sequencer = uvm_sequencer#(base_sequence)::type_id::create("sequencer", this);
        driver = cpu_io_driver::type_id::create("driver", this);
        monitor = cpu_io_monitor::type_id::create("monitor", this);
      
   endfunction : build_phase

    function void connect_phase(uvm_phase phase);

    endfunction

endclass

`endif