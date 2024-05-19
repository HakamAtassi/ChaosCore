module dff (
  input logic clock, d, reset,
  output logic q
);

always @(posedge clock) begin
  if(reset) begin
    q <='b0;
  end else begin
    q <= d;
  end
end

endmodule

