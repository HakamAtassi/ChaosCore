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

    uvm_analysis_port #(cache_transaction) transaction_port;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("MONITOR","Creating CPU IO Monitor...",500);
        super.build_phase(phase);
        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", cache_vif)) begin 
            `uvm_error("MONITOR", "Failed to get cache interface") 
        end
        transaction_port = new("transaction_port", this);
    endfunction

    task run_phase(uvm_phase phase);

        cache_transaction transaction = cache_transaction::type_id::create("cache_transaction", this);

        @(negedge cache_vif.reset);
        forever begin
            @(posedge cache_vif.clock);
            #1;

            if (cache_vif.io_CPU_response_valid == 1) begin


                transaction.io_CPU_request_bits_addr = cache_vif.io_CPU_request_bits_addr;
                transaction.io_CPU_response_bits_valid_bits_0 = cache_vif.io_CPU_response_bits_valid_bits_0;
                transaction.io_CPU_response_bits_valid_bits_1 = cache_vif.io_CPU_response_bits_valid_bits_1;
                transaction.io_CPU_response_bits_valid_bits_2 = cache_vif.io_CPU_response_bits_valid_bits_2;
                transaction.io_CPU_response_bits_valid_bits_3 = cache_vif.io_CPU_response_bits_valid_bits_3;


                if (cache_vif.io_CPU_response_bits_valid_bits_0) begin
                    transaction.io_CPU_response_bits_instructions_0_instruction = cache_vif.io_CPU_response_bits_instructions_0_instruction;
                end 
                if (cache_vif.io_CPU_response_bits_valid_bits_1) begin
                    transaction.io_CPU_response_bits_instructions_1_instruction = cache_vif.io_CPU_response_bits_instructions_1_instruction;
                end 
                if (cache_vif.io_CPU_response_bits_valid_bits_2) begin
                    transaction.io_CPU_response_bits_instructions_2_instruction = cache_vif.io_CPU_response_bits_instructions_2_instruction;
                end 
                if (cache_vif.io_CPU_response_bits_valid_bits_3) begin
                    transaction.io_CPU_response_bits_instructions_3_instruction = cache_vif.io_CPU_response_bits_instructions_3_instruction;
                end 

                transaction_port.write(transaction);

            end

        end

    endtask

endclass
`endif