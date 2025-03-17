`timescale 1ns / 1ps

module PPMMMIOBlackBox 
  #(parameter address_width = 16, 
    parameter data_width = 24) 
  (
    input                           clock,
    input                           reset,
    output                          input_ready,
    input                           input_valid,
    input  [address_width-1:0]      address,    
    input  [data_width-1:0]         data,       
    input                           wr_en,
    input                           dump        
  );

  reg [data_width-1:0] mem[0:(2**address_width)-1];
  integer i;
  integer fd;

  localparam FRAME_WIDTH  = 320;
  localparam FRAME_HEIGHT = 240;

  assign input_ready = 1'b1;

  always @(posedge clock) begin
    if (reset) begin
      for (i = 0; i < (2**address_width); i = i + 1) begin
        mem[i] <= {data_width{1'b0}};
      end
    end else begin
      if (wr_en) begin
        mem[address] <= data;
      end

      if (dump) begin
         fd = $fopen("ChaosCore_frame.ppm", "w");
         if (fd) begin
            $fdisplay(fd, "P3");
            $fdisplay(fd, "%0d %0d", FRAME_WIDTH, FRAME_HEIGHT);
            $fdisplay(fd, "255");
            for (i = 0; i < FRAME_WIDTH * FRAME_HEIGHT; i = i + 1) begin
               $fwrite(fd, "%0d %0d %0d ", mem[i][23:16], mem[i][15:8], mem[i][7:0]);
               if (((i + 1) % FRAME_WIDTH) == 0)
                  $fdisplay(fd, "");
            end
            $fclose(fd);
         end
      end
    end
  end

endmodule
