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
    input                           operation,
    input                           dump        
  );

  reg [data_width-1:0] mem[0:FRAME_HEIGHT*FRAME_WIDTH];
  integer i;
  integer j;
  integer fd;

  localparam FRAME_WIDTH  = 320;
  localparam FRAME_HEIGHT = 240;
  localparam filename = "ChaosCore_frame.ppm";

  assign input_ready = 1'b1;

  reg init_ppm;
  



  task dump_ppm;
    integer fd;
    integer i;
    reg [7:0] r, g, b;
    begin
      $display("Dumping ppm!");
      fd = $fopen("ChaosCore_frame.ppm", "wb"); // Open in binary write mode
      if (fd) begin
        $fdisplay(fd, "P6");
        $fdisplay(fd, "%0d %0d", FRAME_WIDTH, FRAME_HEIGHT);
        $fdisplay(fd, "255");
        for (i = 0; i < FRAME_WIDTH * FRAME_HEIGHT; i = i + 1) begin
          r = mem[i][23:16];
          g = mem[i][15:8];
          b = mem[i][7:0];
          $fwrite(fd, "%c%c%c", r, g, b); // Write binary RGB values
        end
        $fclose(fd);
      end
    end
  endtask


  task init_mem;
      for(i=0;i<FRAME_HEIGHT; i=i+1) begin
          for(j=0;j<FRAME_WIDTH;j=j+1) begin
              if(j<FRAME_WIDTH/3) begin
                  mem[i*FRAME_WIDTH + j] = 24'hFF0000;
              end else if(j<2*FRAME_WIDTH/3) begin
                  mem[i*FRAME_WIDTH + j] = 24'h00FF00;
              end else begin
                  mem[i*FRAME_WIDTH + j] = 24'h0000FF;
              end
          end
      end
  endtask



  always @(posedge clock) begin
    if (reset) begin

      init_ppm <= 1'b0;



    end else begin

      if(!init_ppm) begin
        init_mem;
        dump_ppm;

        init_ppm <= 1'b1;
      end

      if (operation) begin
        mem[address] <= data;
      end

      if (dump) begin
        dump_ppm;
      end
    end
  end

endmodule
