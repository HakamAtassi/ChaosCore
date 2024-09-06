import uvm_pkg::*;
import instruction_cache_pkg::*;

module top;

    instruction_cache_if dut_if();
    instruction_cache DUT(dut_if.cache_mp);

    initial begin
        string test_name;
        global_cache_if = dut_if;
        run_test("cache_base_test");
    end

endmodule 