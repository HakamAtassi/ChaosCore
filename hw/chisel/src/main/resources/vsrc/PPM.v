`timescale 1ns / 1ps

module PPMMMIOBlackBox 
  #(parameter address_width = 32, 
    parameter data_width = 32) 
  (
    input                           clock,
    input                           reset,
    output                          input_ready,
    input                           input_valid,
    input  [31:0]                   address,    
    input  [31:0]                   data,       
    input  [31:0]                   operation,
    input                           dump        
  );


  reg[8*256-1:0] filename_buf;

  reg [data_width-1:0] mem[0:FRAME_HEIGHT*FRAME_WIDTH];
  integer i;
  integer j;
  integer fd;

  localparam FRAME_WIDTH  = 100;
  localparam FRAME_HEIGHT = 100;

  assign input_ready = 1'b1;

  reg init_ppm;
  


    string result = "";
    reg [7:0] byte_val;
    function string reg_to_string(input reg [256*8-1:0] data);
        result="";
        for (int i = 0; i < 256; i++) begin
            byte_val = data[i*8 +: 8];
            if (byte_val == 0) begin
                // do nothing
            end else begin
                result = {result, string'(byte_val)};
            end
        end
        return result;
    endfunction


  task dump_ppm;
    integer fd;
    integer i;
    reg [7:0] r, g, b;

    begin
      fd = $fopen(reg_to_string(filename_buf), "wb"); // Open in binary write mode
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


  wire wr_en = operation == 32'd1;
  wire wr_filename = operation == 32'd2;


  always @(posedge clock) begin
    if (reset) begin
      init_ppm <= 1'b0;
      filename_buf <= 256'h6D70702E656D6172665F65726F43736F616843;

    end else begin

      if(!init_ppm) begin
        init_mem;
        dump_ppm;

        init_ppm <= 1'b1;
      end


      if ((wr_en) && input_valid==1'b1) begin
        mem[address] <= data;
      end

      if ((wr_filename) && (input_valid == 1'b1)) filename_buf[(8 * address) +: 8] <= data[7:0]; 


      if (dump == 1'b1) begin
        dump_ppm;
      end

    end
  end

endmodule
