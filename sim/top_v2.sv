

module top_v2;

    ////////////////
    // INIT WIRES //
    ////////////////

    logic clock;
    logic reset;

    logic dram_AXI_AXI_AW_ready;
    logic dram_AXI_AXI_AW_valid;
    struct packed {
        logic [7:0] awid; 
        logic [31:0] awaddr; 
        logic [7:0] awlen; 
        logic [2:0] awsize; 
        logic [1:0] awburst; 
        logic awlock; 
        logic [3:0] awcache; 
        logic [2:0] awprot; 
        logic [3:0] awqos; 
        logic [3:0] awregion; 
        logic awuser; 
    } dram_AXI_AXI_AW_bits;

    logic dram_AXI_AXI_W_ready;
    logic dram_AXI_AXI_W_valid;
    struct packed {
        logic [31:0] wdata; 
        logic [3:0] wstrb; 
        logic wlast; 
        logic wuser; 
    } dram_AXI_AXI_W_bits;

    logic dram_AXI_AXI_B_ready;
    logic dram_AXI_AXI_B_valid;
    struct packed {
        logic [7:0] bid; 
        logic [1:0] bresp; 
        logic buser; 
    } dram_AXI_AXI_B_bits;

    logic dram_AXI_AXI_AR_ready;
    logic dram_AXI_AXI_AR_valid;
    struct packed {
        logic [7:0] arid; 
        logic [31:0] araddr; 
        logic [7:0] arlen; 
        logic [2:0] arsize; 
        logic [1:0] arburst; 
        logic arlock; 
        logic [3:0] arcache; 
        logic [2:0] arprot; 
        logic [3:0] arqos; 
        logic [3:0] arregion; 
        logic aruser; 
    } dram_AXI_AXI_AR_bits;

    logic dram_AXI_AXI_R_ready;
    logic dram_AXI_AXI_R_valid;
    struct packed {
        logic [7:0] rid; 
        logic [31:0] rdata; 
        logic [1:0] rresp; 
        logic rlast; 
        logic ruser; 
    } dram_AXI_AXI_R_bits;

    //////////////
    // INIT RAM //
    //////////////

    axi_ram_wrap axi_ram (
        .clock(clock),
        .reset(reset),
    
        .io_s_AXI_AXI_AW_ready(dram_AXI_AXI_AW_ready),
        .io_s_AXI_AXI_AW_valid(dram_AXI_AXI_AW_valid),
        .io_s_AXI_AXI_AW_bits(dram_AXI_AXI_AW_bits),

        .io_s_AXI_AXI_W_ready(dram_AXI_AXI_W_ready),
        .io_s_AXI_AXI_W_valid(dram_AXI_AXI_W_valid),
        .io_s_AXI_AXI_W_bits(dram_AXI_AXI_W_bits),

        .io_s_AXI_AXI_B_ready(dram_AXI_AXI_B_ready),
        .io_s_AXI_AXI_B_valid(dram_AXI_AXI_B_valid),
        .io_s_AXI_AXI_B_bits(dram_AXI_AXI_B_bits),

        .io_s_AXI_AXI_AR_ready(dram_AXI_AXI_AR_ready),
        .io_s_AXI_AXI_AR_valid(dram_AXI_AXI_AR_valid),
        .io_s_AXI_AXI_AR_bits(dram_AXI_AXI_AR_bits),

        .io_s_AXI_AXI_R_ready(dram_AXI_AXI_R_ready),
        .io_s_AXI_AXI_R_valid(dram_AXI_AXI_R_valid),
        .io_s_AXI_AXI_R_bits(dram_AXI_AXI_R_bits) 
    );

    //////////////
    // INIT SoC //
    //////////////

    SOC SOC(
        .clock(clock),
        .reset(reset),

        .io_dram_AXI_AXI_AW_ready(dram_AXI_AXI_AW_ready),
        .io_dram_AXI_AXI_AW_valid(dram_AXI_AXI_AW_valid),
        .io_dram_AXI_AXI_AW_bits(dram_AXI_AXI_AW_bits),

        .io_dram_AXI_AXI_W_ready(dram_AXI_AXI_W_ready),
        .io_dram_AXI_AXI_W_valid(dram_AXI_AXI_W_valid),
        .io_dram_AXI_AXI_W_bits(dram_AXI_AXI_W_bits),

        .io_dram_AXI_AXI_B_ready(dram_AXI_AXI_B_ready),
        .io_dram_AXI_AXI_B_valid(dram_AXI_AXI_B_valid),
        .io_dram_AXI_AXI_B_bits(dram_AXI_AXI_B_bits),

        .io_dram_AXI_AXI_AR_ready(dram_AXI_AXI_AR_ready),
        .io_dram_AXI_AXI_AR_valid(dram_AXI_AXI_AR_valid),
        .io_dram_AXI_AXI_AR_bits(dram_AXI_AXI_AR_bits),

        .io_dram_AXI_AXI_R_ready(dram_AXI_AXI_R_ready),
        .io_dram_AXI_AXI_R_valid(dram_AXI_AXI_R_valid),
        .io_dram_AXI_AXI_R_bits(dram_AXI_AXI_R_bits)
    );


    initial begin
        reset = 1'b0;
        @(posedge clock);
        reset = 1'b1;
        @(posedge clock); 
        reset = 1'b0;
    end

    initial begin
        clock = 0;
        forever #5 clock = ~clock;
    end


  // load binary from binaries/bin/hello_world.bin
  // axi_ram.mem
  // mem has width of 32 bits
    initial begin
        $readmemh("binaries/bin/hello_world.hex", axi_ram.ram.mem);
        $display("Binary file loaded into memory.");
    end

    initial $display("Running ChaosCore");

    initial begin
        repeat(10_000) @(posedge clock);
        $display("Testbench exhausted");
        $finish;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end



endmodule: top_v2;
