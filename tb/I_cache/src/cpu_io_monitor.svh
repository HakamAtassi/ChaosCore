
class cpu_io_monitor extends uvm_monitor;

    virtual interface instruction_cache_if i;

    `uvm_component_utils(cpu_io_monitor)

    uvm_analysis_port #(cache_resp) rsp_port;
    uvm_analysis_port #(cache_req) req_port;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        rsp_port = new("rsp_port", this);
        req_port = new("req_port", this);
    endfunction

    task run_phase(uvm_phase phase);

        cache_resp response = new();
        cache_req request = new();
        forever begin
             @(posedge i.clk);
             #1;
        end

    endtask

endclass