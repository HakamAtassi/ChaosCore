import uvm_pkg::*;
import instruction_cache_pkg::*;

module top;

    instruction_cache_if cache_if();
    instruction_cache DUT(cache_if.cache_mp);
    memory reference_mem;
    integer index;
    integer mem_data;

    initial begin
        reference_mem = memory::type_id::create("reference_mem");
        for(index = 0; index < 16383; index = index +1) begin
            mem_data = $urandom();
            DUT.dut.axi_ram.mem[index] = mem_data;
            reference_mem.mem[index] = mem_data;
        end
        uvm_config_db#(memory)::set(null, "uvm_test_top.env.scoreboard", "reference_mem", reference_mem);
        uvm_config_db#(virtual instruction_cache_if)::set(null, "*", "cache_vif", cache_if);
        run_test();
    end

endmodule 