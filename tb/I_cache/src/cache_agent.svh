`ifndef CACHE_AGENT
`define CACHE_AGENT

class cache_agent extends uvm_agent;

    function new(string name="", uvm_component parent);
        super.new(name, parent);
    endfunction: new

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
    endfunction : build_phase


endclass

`endif