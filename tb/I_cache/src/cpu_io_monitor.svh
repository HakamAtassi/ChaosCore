`ifndef CPU_IO_MONITOR
`define CPU_IO_MONITOR

`include "cache_req.svh"
class cpu_io_monitor extends uvm_monitor;

    `uvm_component_utils(cpu_io_monitor)

    virtual instruction_cache_if cache_vif;

    uvm_analysis_port #(cache_rsp) rsp_port;
    uvm_analysis_port #(cache_req) req_port;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("MONITOR","Creating CPU IO Monitor...",500);
        super.build_phase(phase);
        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", cache_vif)) begin 
            `uvm_error("ENV", "Failed to get cache interface") 
        end
        rsp_port = new("rsp_port", this);
        req_port = new("req_port", this);
    endfunction

    task run_phase(uvm_phase phase);

        cache_rsp rsp = new();
        cache_req req = new();

        @(negedge cache_vif.reset);
        forever begin
            @(posedge cache_vif.clock);
            #1;

            rsp_port.write(rsp);
            req_port.write(req);

            `uvm_info("run",
                 $psprintf("Monitor got req %s",
                 req.convert2string()), 
                 UVM_LOW);
            `uvm_info("run",
                 $psprintf("Monitor got %s",
                 rsp.convert2string()), 
                 UVM_LOW);

        end

    endtask

endclass
`endif