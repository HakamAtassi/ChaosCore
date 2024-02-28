/*

This verilog file is aimed at testing system configuration (namely, the Docker setup).

*/

module counter0(
    input  logic        counter0_clock,
    input  logic        counter0_reset,
    output logic [4:0] counter0_counter
);

always @(posedge counter0_clock) begin
    if(counter0_reset) begin
        counter0_counter<=0;
    end else begin
        counter0_counter<=counter0_counter+'d1;
    end   
end

endmodule

module counter1(
    input  logic        counter1_clock,
    input  logic        counter1_reset,
    output logic [4:0] counter1_counter
);

logic        counter0_clock;
logic        counter0_reset;
logic [4:0] counter0_counter;

assign counter0_clock = counter1_clock;
assign counter0_reset = counter1_reset;

counter0 inner_counter1(.*);

always @(posedge counter1_clock) begin
    if(counter1_reset) begin
        counter1_counter<=0;
    end else begin
        if(counter0_counter==5'd0) begin
            counter1_counter<=counter1_counter+'d1;
        end
    end   
end

endmodule

module top;

logic clock;
logic reset;

assign counter1_clock = clock;
assign counter1_reset = reset;

logic        counter1_clock;
logic        counter1_reset;
logic [4:0] counter1_counter;

counter1 counter1(.*);

endmodule