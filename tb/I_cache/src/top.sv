import uvm_pkg::*;
import instruction_cache_pkg::*;
module top;

    instruction_cache_if cache_if();
    instruction_cache DUT(cache_if.cache_mp);

    integer index;
    initial begin
        for(index = 0; index < 16383; index = index +1) begin
            DUT.dut.axi_ram.mem[index] = $urandom();
        end
        uvm_config_db#(virtual instruction_cache_if)::set(null, "*", "cache_vif", cache_if);
        run_test();
    end

endmodule 