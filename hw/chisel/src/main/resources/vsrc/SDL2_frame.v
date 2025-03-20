`timescale 1ps/1ps

module SDL2MMIOBlackBox 
  #(parameter address_width = 16, 
    parameter data_width = 24) 
  (
    input                           clock,
    input                           reset,
    output                          input_ready,
    input                           input_valid,
    input  [address_width-1:0]      address,    
    input  [data_width-1:0]         data,       
    input                           operation,
    input                           dump   
  );

  import "DPI-C" function void create_window();
  import "DPI-C" function void refresh_window();
  import "DPI-C" function void write_frame(input logic [31:0] address, input logic [31:0] data);


  integer i;
  integer j;

  reg init_ppm;
  reg init_frame;

  localparam FRAME_WIDTH  = 320;
  localparam FRAME_HEIGHT = 240;

  assign input_ready = 1'b1;

  initial create_window();

  always @(posedge clock) begin
    if (reset) begin
      init_frame <= 0;
    end else begin


      if (operation & input_valid) begin
        write_frame(address, data);
      end

      refresh_window();

    end
  end

endmodule
