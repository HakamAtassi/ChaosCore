`default_nettype none
`timescale 1ns/100ps


module free_list_tb;

    logic clock, reset;

    always begin
        clock <= 0; #1; clock <= 1; #1;
    end

    initial begin
        repeat(200000) @(posedge clock); $finish;
        $display("tb exhaused");
    end


    initial begin 
        $display("Running free_list_tb");
    end



endmodule