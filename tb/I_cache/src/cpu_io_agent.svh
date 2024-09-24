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
    uvm_sequencer #(cache_req, cache_rsp) sequencer; 
    virtual instruction_cache_if cache_vif;
    base_sequence seq;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("AGENT","Creating CPU IO Agent...",500);
        super.build_phase(phase);
        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", cache_vif)) begin 
            `uvm_error("ENV", "Failed to get cache interface") 
        end
        uvm_config_db#(virtual instruction_cache_if)::set(this, "monitor", "cache_vif", cache_vif);
        uvm_config_db#(virtual instruction_cache_if)::set(this, "driver", "cache_vif", cache_vif);

        seq = base_sequence::type_id::create("seq", this);
        sequencer = uvm_sequencer#(cache_req, cache_rsp)::type_id::create("sequencer", this);
        driver = cpu_io_driver::type_id::create("driver", this);
        monitor = cpu_io_monitor::type_id::create("monitor", this);
      
    endfunction : build_phase

    function void connect_phase(uvm_phase phase);
        driver.seq_item_port.connect(sequencer.seq_item_export);
    endfunction

    task run_phase(uvm_phase phase);

        phase.raise_objection(this);
        seq.start(sequencer);
        phase.drop_objection(this);

    endtask

endclass

`endif