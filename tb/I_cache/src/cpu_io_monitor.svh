`ifndef CPU_IO_MONITOR
`define CPU_IO_MONITOR

`include "cache_req.svh"
`include "reference_mem.svh"
class cpu_io_monitor extends uvm_monitor;

    `uvm_component_utils(cpu_io_monitor)

    virtual instruction_cache_if cache_vif;

    integer instr0;
    integer instr1;
    integer instr2;
    integer instr3;
    integer addr;

    memory reference_mem;

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
        if(!uvm_config_db #(memory)::get(this, "", "reference_mem", reference_mem)) begin 
            `uvm_error("TEST", "Failed to get reference_mem") 
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

            if (cache_vif.io_CPU_response_valid == 1 && cache_vif.io_CPU_response_bits_valid_bits_0 == 1) begin

                rsp_port.write(rsp);
                req_port.write(req);

                addr = cache_vif.io_CPU_request_bits_addr >> 2;
                `uvm_info("MON", $psprintf("Address: %2h", addr), UVM_MEDIUM)

                instr0 = reference_mem.mem[addr];
                instr1 = reference_mem.mem[addr + 1];
                instr2 = reference_mem.mem[addr + 2];
                instr3 = reference_mem.mem[addr + 3];

                `uvm_info("MON",
                $psprintf(
                        "\nCache Response 0: %2h, Reference 0: %2h \n", cache_vif.io_CPU_response_bits_instructions_0_instruction, instr0,
                        "Cache Response 1: %2h, Reference 1: %2h \n", cache_vif.io_CPU_response_bits_instructions_1_instruction, instr1,
                        "Cache Response 2: %2h, Reference 2: %2h \n", cache_vif.io_CPU_response_bits_instructions_2_instruction, instr2,
                        "Cache Response 3: %2h, Reference 3: %2h \n", cache_vif.io_CPU_response_bits_instructions_3_instruction, instr3)
                , UVM_MEDIUM);

                assert(instr0 == cache_vif.io_CPU_response_bits_instructions_0_instruction);


                // `uvm_info("run",
                //     $psprintf("Monitor got req %s",
                //     req.convert2string()), 
                //     UVM_MEDIUM);
                // `uvm_info("run",
                //     $psprintf("Monitor got %s",
                //     rsp.convert2string()), 
                //     UVM_MEDIUM);

            end

        end

    endtask

endclass
`endif