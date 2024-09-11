`ifndef CPU_IO_MONITOR
`define CPU_IO_MONITOR

`include "cache_req.svh"
`include "cache_resp.svh"
class cpu_io_monitor extends uvm_monitor;

    `uvm_component_utils(cpu_io_monitor)

    uvm_analysis_port #(cache_resp) rsp_port;
    uvm_analysis_port #(cache_req) req_port;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("MONITOR","Creating CPU IO Monitor...",500);
        super.build_phase(phase);
        rsp_port = new("rsp_port", this);
        req_port = new("req_port", this);
    endfunction

    task run_phase(uvm_phase phase);

        cache_resp response = new();
        cache_req request = new();

    endtask

endclass
`endif