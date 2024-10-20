// Generated by CIRCT firtool-1.62.0
module axi_ram_wrap(
  input                                                                                                                                                                                                                                    clock,
                                                                                                                                                                                                                                           reset,
  output                                                                                                                                                                                                                                   io_s_AXI_AXI_AW_ready,
  input                                                                                                                                                                                                                                    io_s_AXI_AXI_AW_valid,
  input  struct packed {logic [7:0] awid; logic [31:0] awaddr; logic [7:0] awlen; logic [2:0] awsize; logic [1:0] awburst; logic awlock; logic [3:0] awcache; logic [2:0] awprot; logic [3:0] awqos; logic [3:0] awregion; logic awuser; } io_s_AXI_AXI_AW_bits,
  output                                                                                                                                                                                                                                   io_s_AXI_AXI_W_ready,
  input                                                                                                                                                                                                                                    io_s_AXI_AXI_W_valid,
  input  struct packed {logic [31:0] wdata; logic [3:0] wstrb; logic wlast; logic wuser; }                                                                                                                                                 io_s_AXI_AXI_W_bits,
  input                                                                                                                                                                                                                                    io_s_AXI_AXI_B_ready,
  output                                                                                                                                                                                                                                   io_s_AXI_AXI_B_valid,
  output struct packed {logic [7:0] bid; logic [1:0] bresp; logic buser; }                                                                                                                                                                 io_s_AXI_AXI_B_bits,
  output                                                                                                                                                                                                                                   io_s_AXI_AXI_AR_ready,
  input                                                                                                                                                                                                                                    io_s_AXI_AXI_AR_valid,
  input  struct packed {logic [7:0] arid; logic [31:0] araddr; logic [7:0] arlen; logic [2:0] arsize; logic [1:0] arburst; logic arlock; logic [3:0] arcache; logic [2:0] arprot; logic [3:0] arqos; logic [3:0] arregion; logic aruser; } io_s_AXI_AXI_AR_bits,
  input                                                                                                                                                                                                                                    io_s_AXI_AXI_R_ready,
  output                                                                                                                                                                                                                                   io_s_AXI_AXI_R_valid,
  output struct packed {logic [7:0] rid; logic [31:0] rdata; logic [1:0] rresp; logic rlast; logic ruser; }                                                                                                                                io_s_AXI_AXI_R_bits
);

  wire [7:0]  _ram_s_axi_bid;
  wire [1:0]  _ram_s_axi_bresp;
  wire [7:0]  _ram_s_axi_rid;
  wire [31:0] _ram_s_axi_rdata;
  wire [1:0]  _ram_s_axi_rresp;
  wire        _ram_s_axi_rlast;
  axi_ram #(
    .ADDR_WIDTH(16),
    .DATA_WIDTH(32),
    .ID_WIDTH(8),
    .PIPELINE_OUTPUT(0),
    .STRB_WIDTH(4)
  ) ram (
    .clk           (clock),
    .rst           (reset),
    .s_axi_awid    (io_s_AXI_AXI_AW_bits.awid),
    .s_axi_awaddr  (io_s_AXI_AXI_AW_bits.awaddr),
    .s_axi_awlen   (io_s_AXI_AXI_AW_bits.awlen),
    .s_axi_awsize  (io_s_AXI_AXI_AW_bits.awsize),
    .s_axi_awburst (io_s_AXI_AXI_AW_bits.awburst),
    .s_axi_awlock  (io_s_AXI_AXI_AW_bits.awlock),
    .s_axi_awcache (io_s_AXI_AXI_AW_bits.awcache),
    .s_axi_awprot  (io_s_AXI_AXI_AW_bits.awprot),
    .s_axi_awvalid (io_s_AXI_AXI_AW_valid),
    .s_axi_awready (io_s_AXI_AXI_AW_ready),
    .s_axi_wdata   (io_s_AXI_AXI_W_bits.wdata),
    .s_axi_wstrb   (io_s_AXI_AXI_W_bits.wstrb),
    .s_axi_wlast   (io_s_AXI_AXI_W_bits.wlast),
    .s_axi_wvalid  (io_s_AXI_AXI_W_valid),
    .s_axi_wready  (io_s_AXI_AXI_W_ready),
    .s_axi_bid     (_ram_s_axi_bid),
    .s_axi_bresp   (_ram_s_axi_bresp),
    .s_axi_bvalid  (io_s_AXI_AXI_B_valid),
    .s_axi_bready  (io_s_AXI_AXI_B_ready),
    .s_axi_arid    (io_s_AXI_AXI_AR_bits.arid),
    .s_axi_araddr  (io_s_AXI_AXI_AR_bits.araddr),
    .s_axi_arlen   (io_s_AXI_AXI_AR_bits.arlen),
    .s_axi_arsize  (io_s_AXI_AXI_AR_bits.arsize),
    .s_axi_arburst (io_s_AXI_AXI_AR_bits.arburst),
    .s_axi_arlock  (io_s_AXI_AXI_AR_bits.arlock),
    .s_axi_arcache (io_s_AXI_AXI_AR_bits.arcache),
    .s_axi_arprot  (io_s_AXI_AXI_AR_bits.arprot),
    .s_axi_arvalid (io_s_AXI_AXI_AR_valid),
    .s_axi_arready (io_s_AXI_AXI_AR_ready),
    .s_axi_rid     (_ram_s_axi_rid),
    .s_axi_rdata   (_ram_s_axi_rdata),
    .s_axi_rresp   (_ram_s_axi_rresp),
    .s_axi_rlast   (_ram_s_axi_rlast),
    .s_axi_rvalid  (io_s_AXI_AXI_R_valid),
    .s_axi_rready  (io_s_AXI_AXI_R_ready)
  );
  assign io_s_AXI_AXI_B_bits =
    '{bid: _ram_s_axi_bid, bresp: _ram_s_axi_bresp, buser: (1'h0)};
  assign io_s_AXI_AXI_R_bits =
    '{rid: _ram_s_axi_rid,
      rdata: _ram_s_axi_rdata,
      rresp: _ram_s_axi_rresp,
      rlast: _ram_s_axi_rlast,
      ruser: (1'h0)};
endmodule

