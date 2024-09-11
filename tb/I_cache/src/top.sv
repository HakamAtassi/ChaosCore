import uvm_pkg::*;
import instruction_cache_pkg::*;
module top;

    instruction_cache_if cache_if();
    instruction_cache DUT(cache_if.cache_mp);


    initial begin
        uvm_config_db#(virtual instruction_cache_if)::set(null, "*", "cache_vif", cache_if);
        run_test();
    end

endmodule 