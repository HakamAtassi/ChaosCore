
`include "../hw/verilog/Core/ChaosCore.v"

`default_nettype wire


module top;

    logic clock;
    logic reset;

    reg[7:0] memory[0:32768]; //256kB

    initial $readmemb("binaries/addi.bin", memory);


    ChaosCore dut(.*);

    
    initial begin
        reset = 1'b0;
        @(posedge clock);  // Wait for the first positive edge of clock
        reset = 1'b1;
        @(posedge clock);  // Wait for the second positive edge of clock
        reset = 1'b0;
    end

    // Clock generation for simulation purposes
    initial begin
        clock = 0;
        forever #5 clock = ~clock;  // Generate a clock with a period of 10 time units
    end


    initial $display("Running ChaosCore");





    ////////////////////////////
    // DRIVE MEMORY RESPONSES //
    ////////////////////////////


    // INSTRUCTION REQUESTS





    // DATA REQUESTS 


    initial begin
        repeat(10_000) @(posedge clock);
        $display("Testbench exhausted");
        $finish;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end



endmodule