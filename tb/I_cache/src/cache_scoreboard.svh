`ifndef CACHE_SCOREBOARD
`define CACHE_SCOREBOARD

`include "cache_req.svh"
`include "reference_mem.svh"
class cache_scoreboard extends uvm_scoreboard;

    `uvm_component_utils(cache_scoreboard)

    uvm_analysis_imp #(cache_transaction, cache_scoreboard) transaction_port;

    cache_transaction transaction;
    cache_transaction reference_trans;

    integer passes;
    integer fails;

    memory reference_mem;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        passes = 0;
        fails = 0;
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("SCORE","Creating Scoreboard...",500);
        super.build_phase(phase);
        if(!uvm_config_db #(memory)::get(this, "", "reference_mem", reference_mem)) begin 
            `uvm_error("SCORE", "Failed to get reference_mem") 
        end
        transaction_port = new("transaction_port", this);
    endfunction

    function write (cache_transaction transaction);
        integer instr0;
        integer instr1;
        integer instr2;
        integer instr3;
        integer addr;
        integer remainder;

        reference_trans = cache_transaction::type_id::create("reference_trans", this);

        //get address and valid bits
        addr = transaction.io_CPU_request_bits_addr >> 2;
        remainder = (transaction.io_CPU_request_bits_addr % 16) >> 2;

        reference_trans.io_CPU_response_bits_valid_bits_0 = remainder < 1;
        reference_trans.io_CPU_response_bits_valid_bits_1 = remainder < 2;
        reference_trans.io_CPU_response_bits_valid_bits_2 = remainder < 3;
        reference_trans.io_CPU_response_bits_valid_bits_3 = remainder < 4;

        //get data from golden memory
        instr0 = reference_mem.mem[addr - remainder];
        instr1 = reference_mem.mem[addr + 1 - remainder];
        instr2 = reference_mem.mem[addr + 2 - remainder];
        instr3 = reference_mem.mem[addr + 3 - remainder];

        reference_trans.io_CPU_response_bits_instructions_0_instruction = instr0;
        reference_trans.io_CPU_response_bits_instructions_1_instruction = instr1;
        reference_trans.io_CPU_response_bits_instructions_2_instruction = instr2;
        reference_trans.io_CPU_response_bits_instructions_3_instruction = instr3;

        //if invalid just match the actual response
        if (!transaction.io_CPU_response_bits_valid_bits_0) 
            reference_trans.io_CPU_response_bits_instructions_0_instruction = transaction.io_CPU_response_bits_instructions_0_instruction;
        if (!transaction.io_CPU_response_bits_valid_bits_1) 
            reference_trans.io_CPU_response_bits_instructions_1_instruction = transaction.io_CPU_response_bits_instructions_1_instruction;
        if (!transaction.io_CPU_response_bits_valid_bits_2) 
            reference_trans.io_CPU_response_bits_instructions_2_instruction = transaction.io_CPU_response_bits_instructions_2_instruction;
        if (!transaction.io_CPU_response_bits_valid_bits_3)
            reference_trans.io_CPU_response_bits_instructions_3_instruction = transaction.io_CPU_response_bits_instructions_3_instruction;

        `uvm_info("SCORE",
        $psprintf(
                "\nCache Response 0: %2h, Reference 0: %2h \n", transaction.io_CPU_response_bits_instructions_0_instruction, reference_trans.io_CPU_response_bits_instructions_0_instruction,
                "Cache Response 1: %2h, Reference 1: %2h \n", transaction.io_CPU_response_bits_instructions_1_instruction, reference_trans.io_CPU_response_bits_instructions_1_instruction,
                "Cache Response 2: %2h, Reference 2: %2h \n", transaction.io_CPU_response_bits_instructions_2_instruction, reference_trans.io_CPU_response_bits_instructions_2_instruction,
                "Cache Response 3: %2h, Reference 3: %2h \n", transaction.io_CPU_response_bits_instructions_3_instruction, reference_trans.io_CPU_response_bits_instructions_3_instruction)
        , UVM_MEDIUM);

        if (transaction.comp(reference_trans)) begin   
            passes = passes + 1;
            `uvm_info("SCORE", $psprintf("PASSED: #%d", passes), UVM_LOW); 
        end else begin
            fails = fails + 1;
            `uvm_error("SCORE", $psprintf("\n----FAILED-----\n[Expected]\n%s[Actual]\n%s\nFAIL#%d", reference_trans.convert2string(), transaction.convert2string(),fails));
        end
    endfunction

endclass
`endif