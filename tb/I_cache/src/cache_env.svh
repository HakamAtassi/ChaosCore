`ifndef CACHE_ENV
`define CACHE_ENV

`include "uvm_macros.svh"
`include "cpu_io_agent.svh"

class cache_env extends uvm_env;
    `uvm_component_utils(cache_env)

    cpu_io_agent cpu_io_agnt;
    virtual instruction_cache_if cache_vif;

    function new (string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        `uvm_info("ENV","Creating Environment...",UVM_MEDIUM);

        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", cache_vif)) begin 
            `uvm_error("ENV", "Failed to get cache interface") 
        end
        uvm_config_db#(virtual instruction_cache_if)::set(this, "cpu_io_agent", "cache_vif", cache_vif);
        cpu_io_agnt = cpu_io_agent::type_id::create("cpu_io_agnt", this);
      
   endfunction : build_phase

endclass

`endif