
module instruction_mem(
  input         clock,
  input         reset,
  output        io_CPU_request_ready,
  input         io_CPU_request_valid,
  input  [31:0] io_CPU_request_bits_addr,
                io_CPU_request_bits_wr_data,
  input         io_CPU_request_bits_wr_en,
                io_CPU_response_ready,
  output        io_CPU_response_valid,
  output [31:0] io_CPU_response_bits_fetch_PC,
  output        io_CPU_response_bits_valid_bits_0,
                io_CPU_response_bits_valid_bits_1,
                io_CPU_response_bits_valid_bits_2,
                io_CPU_response_bits_valid_bits_3,
  output [31:0] io_CPU_response_bits_instructions_0_instruction,
  output [3:0]  io_CPU_response_bits_instructions_0_packet_index,
  output [5:0]  io_CPU_response_bits_instructions_0_ROB_index,
  output [31:0] io_CPU_response_bits_instructions_1_instruction,
  output [3:0]  io_CPU_response_bits_instructions_1_packet_index,
  output [5:0]  io_CPU_response_bits_instructions_1_ROB_index,
  output [31:0] io_CPU_response_bits_instructions_2_instruction,
  output [3:0]  io_CPU_response_bits_instructions_2_packet_index,
  output [5:0]  io_CPU_response_bits_instructions_2_ROB_index,
  output [31:0] io_CPU_response_bits_instructions_3_instruction,
  output [3:0]  io_CPU_response_bits_instructions_3_packet_index,
  output [5:0]  io_CPU_response_bits_instructions_3_ROB_index,
  output        io_CPU_response_bits_prediction_hit,
  output [31:0] io_CPU_response_bits_prediction_target,
  output [2:0]  io_CPU_response_bits_prediction_br_type,
  output        io_CPU_response_bits_prediction_br_mask_0,
                io_CPU_response_bits_prediction_br_mask_1,
                io_CPU_response_bits_prediction_br_mask_2,
                io_CPU_response_bits_prediction_br_mask_3,
  output [15:0] io_CPU_response_bits_GHR,
  output [6:0]  io_CPU_response_bits_NEXT,
                io_CPU_response_bits_TOS,
  input         io_kill
);

    wire [7:0]             axi_awid; 
    wire [31:0]            axi_awaddr; 
    wire [7:0]             axi_awlen; 
    wire [2:0]             axi_awsize; 
    wire [1:0]             axi_awburst; 
    wire                   axi_awlock; 
    wire [3:0]             axi_awcache; 
    wire [2:0]             axi_awprot; 
    wire                   axi_awvalid; 
    wire                   axi_awready; 
    wire [31:0]            axi_wdata; 
    wire [3:0]             axi_wstrb; 
    wire                   axi_wlast; 
    wire                   axi_wvalid; 
    wire                   axi_wready; 
    wire [7:0]             axi_bid; 
    wire [1:0]             axi_bresp; 
    wire                   axi_bvalid; 
    wire                   axi_bready; 
    wire [7:0]             axi_arid; 
    wire [31:0]            axi_araddr; 
    wire [7:0]             axi_arlen; 
    wire [2:0]             axi_arsize; 
    wire [1:0]             axi_arburst; 
    wire                   axi_arlock; 
    wire [3:0]             axi_arcache; 
    wire [2:0]             axi_arprot; 
    wire                   axi_arvalid; 
    wire                   axi_arready; 
    wire [7:0]             axi_rid;
    wire [31:0]            axi_rdata;
    wire [1:0]             axi_rresp;
    wire                   axi_rlast;
    wire                   axi_rvalid;
    wire                   axi_rready;

    axi_ram axi_ram(
        .clk   (clock),
        .rst   (reset),

        .s_axi_awid   (axi_awid),
        .s_axi_awaddr   (axi_awaddr),
        .s_axi_awlen   (axi_awlen),
        .s_axi_awsize   (axi_awsize),
        .s_axi_awburst   (axi_awburst),
        .s_axi_awlock   (axi_awlock),
        .s_axi_awcache   (axi_awcache),
        .s_axi_awprot   (axi_awprot),
        .s_axi_awvalid   (axi_awvalid),
        .s_axi_awready   (axi_awready),
        .s_axi_wdata   (axi_wdata),
        .s_axi_wstrb   (axi_wstrb),
        .s_axi_wlast   (axi_wlast),
        .s_axi_wvalid   (axi_wvalid),
        .s_axi_wready   (axi_wready),
        .s_axi_bid   (axi_bid),
        .s_axi_bresp   (axi_bresp),
        .s_axi_bvalid   (axi_bvalid),
        .s_axi_bready   (axi_bready),
        .s_axi_arid   (axi_arid),
        .s_axi_araddr   (axi_araddr),
        .s_axi_arlen   (axi_arlen),
        .s_axi_arsize   (axi_arsize),
        .s_axi_arburst   (axi_arburst),
        .s_axi_arlock   (axi_arlock),
        .s_axi_arcache   (axi_arcache),
        .s_axi_arprot   (axi_arprot),
        .s_axi_arvalid   (axi_arvalid),
        .s_axi_arready   (axi_arready),
        .s_axi_rid   (axi_rid),
        .s_axi_rdata   (axi_rdata),
        .s_axi_rresp   (axi_rresp),
        .s_axi_rlast   (axi_rlast),
        .s_axi_rvalid   (axi_rvalid),
        .s_axi_rready   (axi_rready)


    );

    L1_instruction_cache instruction_cache (
    .clock                                            (clock),
    .reset                                            (reset),
    .m_axi_awvalid
      (axi_awvalid),
    .m_axi_awready
      (axi_awready),
    .m_axi_awid
      (axi_awid),
    .m_axi_awaddr
      (axi_awaddr),
    .m_axi_awlen
      (axi_awlen),
    .m_axi_awsize
      (axi_awsize),
    .m_axi_awburst
      (axi_awburst),
    .m_axi_awlock
      (axi_awlock),
    .m_axi_awcache
      (axi_awcache),
    .m_axi_awprot
      (axi_awprot),
    .m_axi_awqos
      (/* unused */),
    .m_axi_awregion
      (/* unused */),
    .m_axi_awuser
      (/* unused */),
    .m_axi_wready
      (axi_wready),
    .m_axi_wvalid
      (axi_wvalid),
    .m_axi_wdata
      (axi_wdata),
    .m_axi_wstrb
      (axi_wstrb),
    .m_axi_wlast
      (axi_wlast),
    .m_axi_wuser
      (/* unused */),
    .m_axi_bready
      (axi_bready),
    .m_axi_bvalid
      (axi_bvalid),
    .m_axi_bid
      (axi_bid),
    .m_axi_bresp
      (axi_bresp),
    .m_axi_buser
      (/* unused */),
    .m_axi_arvalid
      (axi_arvalid),
    .m_axi_arready
      (axi_arready),
    .m_axi_arid
      (axi_arid),
    .m_axi_araddr
      (axi_araddr),
    .m_axi_arlen
      (axi_arlen),
    .m_axi_arsize
      (axi_arsize),
    .m_axi_arburst
      (axi_arburst),
    .m_axi_arlock
      (axi_arlock),
    .m_axi_arcache
      (axi_arcache),
    .m_axi_arprot
      (axi_arprot),
    .m_axi_arqos
      (/* unused */),
    .m_axi_arregion
      (/* unused */),
    .m_axi_aruser
      (/* unused */),
    .m_axi_rready
      (axi_rready),
    .m_axi_rvalid
      (axi_rvalid),
    .m_axi_rid
      (axi_rid),
    .m_axi_rdata
      (axi_rdata),
    .m_axi_rresp
      (axi_rresp),
    .m_axi_rlast
      (axi_rlast),
    .m_axi_ruser
      (/* unused */),
    .io_CPU_request_ready
      (io_CPU_request_ready),
    .io_CPU_response_valid
      (io_CPU_request_valid),
    .io_CPU_response_bits_fetch_PC
      (io_CPU_response_bits_fetch_PC),
    .io_CPU_response_bits_valid_bits_0
      (io_CPU_response_bits_valid_bits_0),
    .io_CPU_response_bits_valid_bits_1
      (io_CPU_response_bits_valid_bits_1),
    .io_CPU_response_bits_valid_bits_2
      (io_CPU_response_bits_valid_bits_2),
    .io_CPU_response_bits_valid_bits_3
      (io_CPU_response_bits_valid_bits_3),
    .io_CPU_response_bits_instructions_0_instruction
      (io_CPU_response_bits_instructions_0_instruction),
    .io_CPU_response_bits_instructions_0_packet_index
      (io_CPU_response_bits_instructions_0_packet_index),
    .io_CPU_response_bits_instructions_0_ROB_index
      (io_CPU_response_bits_instructions_0_ROB_index),
    .io_CPU_response_bits_instructions_1_instruction
      (io_CPU_response_bits_instructions_1_instruction),
    .io_CPU_response_bits_instructions_1_packet_index
      (io_CPU_response_bits_instructions_1_packet_index),
    .io_CPU_response_bits_instructions_1_ROB_index
      (io_CPU_response_bits_instructions_1_ROB_index),
    .io_CPU_response_bits_instructions_2_instruction
      (io_CPU_response_bits_instructions_2_instruction),
    .io_CPU_response_bits_instructions_2_packet_index
      (io_CPU_response_bits_instructions_2_packet_index),
    .io_CPU_response_bits_instructions_2_ROB_index
      (io_CPU_response_bits_instructions_2_ROB_index),
    .io_CPU_response_bits_instructions_3_instruction
      (io_CPU_response_bits_instructions_3_instruction),
    .io_CPU_response_bits_instructions_3_packet_index
      (io_CPU_response_bits_instructions_3_packet_index),
    .io_CPU_response_bits_instructions_3_ROB_index
      (io_CPU_response_bits_instructions_3_ROB_index),
    .io_CPU_response_bits_GHR
      (io_CPU_response_bits_GHR),
    .io_CPU_response_bits_NEXT
      (io_CPU_response_bits_NEXT),
    .io_CPU_response_bits_TOS
      (io_CPU_response_bits_TOS)
  );


endmodule