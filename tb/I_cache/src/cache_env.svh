`ifndef CACHE_ENV
`define CACHE_ENV

`include "uvm_macros.svh"
`include "cpu_io_agent.svh"

class cache_env extends uvm_env;
    `uvm_component_utils(cache_env)

    cpu_io_agent cpu_io_agnt;
    //env_config env_cfg;

    function new (string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        //env_cfg = new();
        `uvm_info("ENV","Creating Environment...",UVM_MEDIUM);
        // if(!uvm_config_db #(env_config)::get(this, "", "env_cfg", env_cfg)) begin 
        //     `uvm_error("TEST", "Failed to get environment config") 
        // end
        cpu_io_agnt = cpu_io_agent::type_id::create("cpu_io_agnt", this);
      
   endfunction : build_phase

endclass

`endif