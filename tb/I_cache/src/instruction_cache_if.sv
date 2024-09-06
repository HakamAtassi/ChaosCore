interface instruction_cache_if;

    logic         clock,
                reset;
    logic        m_axi_awvalid;
    logic         m_axi_awready;
    logic [7:0]  m_axi_awid;
    logic [31:0] m_axi_awaddr;
    logic [7:0]  m_axi_awlen;
    logic [2:0]  m_axi_awsize;
    logic [1:0]  m_axi_awburst;
    logic        m_axi_awlock;
    logic [3:0]  m_axi_awcache;
    logic [2:0]  m_axi_awprot;
    logic [3:0]  m_axi_awqos,
                m_axi_awregion;
    logic        m_axi_awuser;
    logic         m_axi_wready;
    logic        m_axi_wvalid;
    logic [31:0] m_axi_wdata;
    logic [3:0]  m_axi_wstrb;
    logic        m_axi_wlast,
                m_axi_wuser,
                m_axi_bready;
    logic         m_axi_bvalid;
    logic  [7:0]  m_axi_bid;
    logic  [1:0]  m_axi_bresp;
    logic         m_axi_buser;
    logic        m_axi_arvalid;
    logic         m_axi_arready;
    logic [7:0]  m_axi_arid;
    logic [31:0] m_axi_araddr;
    logic [7:0]  m_axi_arlen;
    logic [2:0]  m_axi_arsize;
    logic [1:0]  m_axi_arburst;
    logic        m_axi_arlock;
    logic [3:0]  m_axi_arcache;
    logic [2:0]  m_axi_arprot;
    logic [3:0]  m_axi_arqos,
                m_axi_arregion;
    logic        m_axi_aruser,
                m_axi_rready;
    logic         m_axi_rvalid;
    logic  [7:0]  m_axi_rid;
    logic  [31:0] m_axi_rdata;
    logic  [1:0]  m_axi_rresp;
    logic         m_axi_rlast,
                m_axi_ruser;

    logic        io_CPU_request_ready;
    logic         io_CPU_request_valid;
    logic  [31:0] io_CPU_request_bits_addr,
                    io_CPU_request_bits_wr_data;
    logic         io_CPU_request_bits_wr_en,
                    io_CPU_response_ready;
    logic        io_CPU_response_valid;
    logic [31:0] io_CPU_response_bits_fetch_PC;
    logic        io_CPU_response_bits_valid_bits_0,
                    io_CPU_response_bits_valid_bits_1,
                    io_CPU_response_bits_valid_bits_2,
                    io_CPU_response_bits_valid_bits_3;
    logic [31:0] io_CPU_response_bits_instructions_0_instruction;
    logic [3:0]  io_CPU_response_bits_instructions_0_packet_index;
    logic [5:0]  io_CPU_response_bits_instructions_0_ROB_index;
    logic [31:0] io_CPU_response_bits_instructions_1_instruction;
    logic [3:0]  io_CPU_response_bits_instructions_1_packet_index;
    logic [5:0]  io_CPU_response_bits_instructions_1_ROB_index;
    logic [31:0] io_CPU_response_bits_instructions_2_instruction;
    logic [3:0]  io_CPU_response_bits_instructions_2_packet_index;
    logic [5:0]  io_CPU_response_bits_instructions_2_ROB_index;
    logic [31:0] io_CPU_response_bits_instructions_3_instruction;
    logic [3:0]  io_CPU_response_bits_instructions_3_packet_index;
    logic [5:0]  io_CPU_response_bits_instructions_3_ROB_index;
    logic        io_CPU_response_bits_prediction_hit;
    logic [31:0] io_CPU_response_bits_prediction_target;
    logic [2:0]  io_CPU_response_bits_prediction_br_type;
    logic        io_CPU_response_bits_prediction_T_NT;
    logic [15:0] io_CPU_response_bits_GHR;
    logic [6:0]  io_CPU_response_bits_NEXT,
                    io_CPU_response_bits_TOS;
    logic         io_kill;

    modport cache_mp (
        input         clock,
        input         reset,
        output        m_axi_awvalid,
        input         m_axi_awready,
        output        m_axi_awid,
        output        m_axi_awaddr,
        output        m_axi_awlen,
        output        m_axi_awsize,
        output        m_axi_awburst,
        output        m_axi_awlock,
        output        m_axi_awcache,
        output        m_axi_awprot,
        output        m_axi_awqos,
        output        m_axi_awregion,
        output        m_axi_awuser,
        input         m_axi_wready,
        output        m_axi_wvalid,
        output        m_axi_wdata,
        output        m_axi_wstrb,
        output        m_axi_wlast,
        output        m_axi_wuser,
        output        m_axi_bready,
        input         m_axi_bvalid,
        input         m_axi_bid,
        input         m_axi_bresp,
        input         m_axi_buser,
        output        m_axi_arvalid,
        input         m_axi_arready,
        output        m_axi_arid,
        output        m_axi_araddr,
        output        m_axi_arlen,
        output        m_axi_arsize,
        output        m_axi_arburst,
        output        m_axi_arlock,
        output        m_axi_arcache,
        output        m_axi_arprot,
        output        m_axi_arqos,
        output        m_axi_arregion,
        output        m_axi_aruser,
        output        m_axi_rready,
        input         m_axi_rvalid,
        input         m_axi_rid,
        input         m_axi_rdata,
        input         m_axi_rresp,
        input         m_axi_rlast,
        input         m_axi_ruser,
        output        io_CPU_request_ready,
        input         io_CPU_request_valid,
        input         io_CPU_request_bits_addr,
        input         io_CPU_request_bits_wr_data,
        input         io_CPU_request_bits_wr_en,
        input         io_CPU_response_ready,
        output        io_CPU_response_valid,
        output        io_CPU_response_bits_fetch_PC,
        output        io_CPU_response_bits_valid_bits_0,
        output        io_CPU_response_bits_valid_bits_1,
        output        io_CPU_response_bits_valid_bits_2,
        output        io_CPU_response_bits_valid_bits_3,
        output  io_CPU_response_bits_instructions_0_instruction,
        output   io_CPU_response_bits_instructions_0_packet_index,
        output   io_CPU_response_bits_instructions_0_ROB_index,
        output  io_CPU_response_bits_instructions_1_instruction,
        output  io_CPU_response_bits_instructions_1_packet_index,
        output   io_CPU_response_bits_instructions_1_ROB_index,
        output  io_CPU_response_bits_instructions_2_instruction,
        output  io_CPU_response_bits_instructions_2_packet_index,
        output   io_CPU_response_bits_instructions_2_ROB_index,
        output  io_CPU_response_bits_instructions_3_instruction,
        output  io_CPU_response_bits_instructions_3_packet_index,
        output   io_CPU_response_bits_instructions_3_ROB_index,
        output        io_CPU_response_bits_prediction_hit,
        output io_CPU_response_bits_prediction_target,
        output  io_CPU_response_bits_prediction_br_type,
        output        io_CPU_response_bits_prediction_T_NT,
        output  io_CPU_response_bits_GHR,
        output  io_CPU_response_bits_NEXT,
        output                io_CPU_response_bits_TOS,
        input         io_kill
    );

    initial begin : clock_gen
      clock = 0;
      forever #10 clock = ~clock;
   end

endinterface : instruction_cache_if

module instruction_cache(instruction_cache_if.cache_mp i);

    L1_instruction_cache dut (
        .clock (i.clock),
        .reset (i.reset),
        .m_axi_awvalid (i.m_axi_awvalid),
        .m_axi_awready (i.m_axi_awready),
        .m_axi_awid (i.m_axi_awid),
        .m_axi_awaddr (i.m_axi_awaddr),
        .m_axi_awlen (i.m_axi_awlen),
        .m_axi_awsize (i.m_axi_awsize),
        .m_axi_awburst (i.m_axi_awburst),
        .m_axi_awlock (i.m_axi_awlock),
        .m_axi_awcache (i.m_axi_awcache),
        .m_axi_awprot (i.m_axi_awprot),
        .m_axi_awqos (i.m_axi_awqos),
        .m_axi_awregion (i.m_axi_awregion),
        .m_axi_awuser (i.m_axi_awuser),
        .m_axi_wready (i.m_axi_wready),
        .m_axi_wvalid (i.m_axi_wvalid),
        .m_axi_wdata (i.m_axi_wdata),
        .m_axi_wstrb (i.m_axi_wstrb),
        .m_axi_wlast (i.m_axi_wlast),
        .m_axi_wuser (i.m_axi_wuser),
        .m_axi_bready (i.m_axi_bready),
        .m_axi_bvalid (i.m_axi_bvalid),
        .m_axi_bid (i.m_axi_bid),
        .m_axi_bresp (i.m_axi_bresp),
        .m_axi_buser (i.m_axi_buser),
        .m_axi_arvalid (i.m_axi_arvalid),
        .m_axi_arready (i.m_axi_arready),
        .m_axi_arid (i.m_axi_arid),
        .m_axi_araddr (i.m_axi_araddr),
        .m_axi_arlen (i.m_axi_arlen),
        .m_axi_arsize (i.m_axi_arsize),
        .m_axi_arburst (i.m_axi_arburst),
        .m_axi_arlock (i.m_axi_arlock),
        .m_axi_arcache (i.m_axi_arcache),
        .m_axi_arprot (i.m_axi_arprot),
        .m_axi_arqos (i.m_axi_arqos),
        .m_axi_arregion (i.m_axi_arregion),
        .m_axi_aruser (i.m_axi_aruser),
        .m_axi_rready (i.m_axi_rready),
        .m_axi_rvalid (i.m_axi_rvalid),
        .m_axi_rid (i.m_axi_rid),
        .m_axi_rdata (i.m_axi_rdata),
        .m_axi_rresp (i.m_axi_rresp),
        .m_axi_rlast (i.m_axi_rlast),
        .m_axi_ruser (i.m_axi_ruser),

        .io_CPU_request_ready (i.io_CPU_request_ready),
        .io_CPU_request_valid (i.io_CPU_request_valid),
        .io_CPU_request_bits_addr (i.io_CPU_request_bits_addr),
        .io_CPU_request_bits_wr_data (i.io_CPU_request_bits_wr_data),
        .io_CPU_request_bits_wr_en (i.io_CPU_request_bits_wr_en),
        .io_CPU_response_ready (i.io_CPU_response_ready),
        .io_CPU_response_valid (i.io_CPU_response_valid),
        .io_CPU_response_bits_fetch_PC (i.io_CPU_response_bits_fetch_PC),
        .io_CPU_response_bits_valid_bits_0 (i.io_CPU_response_bits_valid_bits_0),
        .io_CPU_response_bits_valid_bits_1 (i.io_CPU_response_bits_valid_bits_1),
        .io_CPU_response_bits_valid_bits_2 (i.io_CPU_response_bits_valid_bits_2),
        .io_CPU_response_bits_valid_bits_3 (i.io_CPU_response_bits_valid_bits_3),
        .io_CPU_response_bits_instructions_0_instruction (i.io_CPU_response_bits_instructions_0_instruction),
        .io_CPU_response_bits_instructions_0_packet_index (i.io_CPU_response_bits_instructions_0_packet_index),
        .io_CPU_response_bits_instructions_0_ROB_index (i.io_CPU_response_bits_instructions_0_ROB_index),
        .io_CPU_response_bits_instructions_1_instruction (i.io_CPU_response_bits_instructions_1_instruction),
        .io_CPU_response_bits_instructions_1_packet_index (i.io_CPU_response_bits_instructions_1_packet_index),
        .io_CPU_response_bits_instructions_1_ROB_index (i.io_CPU_response_bits_instructions_1_ROB_index),
        .io_CPU_response_bits_instructions_2_instruction (i.io_CPU_response_bits_instructions_2_instruction),
        .io_CPU_response_bits_instructions_2_packet_index (i.io_CPU_response_bits_instructions_2_packet_index),
        .io_CPU_response_bits_instructions_2_ROB_index (i.io_CPU_response_bits_instructions_2_ROB_index),
        .io_CPU_response_bits_instructions_3_instruction (i.io_CPU_response_bits_instructions_3_instruction),
        .io_CPU_response_bits_instructions_3_packet_index (i.io_CPU_response_bits_instructions_3_packet_index),
        .io_CPU_response_bits_instructions_3_ROB_index (i.io_CPU_response_bits_instructions_3_ROB_index),
        .io_CPU_response_bits_prediction_hit (i.io_CPU_response_bits_prediction_hit),
        .io_CPU_response_bits_prediction_target (i.io_CPU_response_bits_prediction_target),
        .io_CPU_response_bits_prediction_br_type (i.io_CPU_response_bits_prediction_br_type),
        .io_CPU_response_bits_prediction_T_NT (i.io_CPU_response_bits_prediction_T_NT),
        .io_CPU_response_bits_GHR (i.io_CPU_response_bits_GHR),
        .io_CPU_response_bits_NEXT (i.io_CPU_response_bits_NEXT),
        .io_CPU_response_bits_TOS (i.io_CPU_response_bits_TOS),
        .io_kill (i.io_kill)
    );



endmodule