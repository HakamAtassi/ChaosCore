import uvm_pkg::*;
interface instruction_cache_if;

    logic         clock,
                reset;
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
    logic           io_CPU_response_bits_prediction_br_mask_0,
                    io_CPU_response_bits_prediction_br_mask_1,
                    io_CPU_response_bits_prediction_br_mask_2,
                    io_CPU_response_bits_prediction_br_mask_3;
    logic           io_flush_valid,
                    io_flush_bits_is_misprediction,
                    io_flush_bits_is_exception,
                    io_flush_bits_is_fence,
                    io_flush_bits_is_CSR;
    logic  [31:0]   io_flush_bits_flushing_PC,
                    io_flush_bits_redirect_PC;

    modport cache_mp (
        input         clock,
        input         reset,
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
        output io_CPU_response_bits_prediction_br_mask_0,
        output io_CPU_response_bits_prediction_br_mask_1,
        output io_CPU_response_bits_prediction_br_mask_2,
        output io_CPU_response_bits_prediction_br_mask_3,
        output        io_CPU_response_bits_prediction_hit,
        output io_CPU_response_bits_prediction_target,
        output  io_CPU_response_bits_prediction_br_type,
        output        io_CPU_response_bits_prediction_T_NT,
        output  io_CPU_response_bits_GHR,
        output  io_CPU_response_bits_NEXT,
        output                io_CPU_response_bits_TOS,
        input         io_flush_valid,
        input            io_flush_bits_is_misprediction,
        input            io_flush_bits_is_exception,
        input            io_flush_bits_is_fence,
        input            io_flush_bits_is_CSR,
        input            io_flush_bits_flushing_PC,
        input                io_flush_bits_redirect_PC
    );

    initial begin : clock_gen
      clock = 0;
      forever #10 clock = ~clock;
    end

endinterface : instruction_cache_if

module instruction_cache(instruction_cache_if.cache_mp i);

    // always @(posedge i.clock)
    //     `uvm_info("ICACHE", "Clock", UVM_LOW)

    instruction_mem dut (
        .clock (i.clock),
        .reset (i.reset),

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
        .io_CPU_response_bits_prediction_br_mask_0 (i.io_CPU_response_bits_prediction_br_mask_0),
        .io_CPU_response_bits_prediction_br_mask_1 (i.io_CPU_response_bits_prediction_br_mask_1),
        .io_CPU_response_bits_prediction_br_mask_2 (i.io_CPU_response_bits_prediction_br_mask_2),
        .io_CPU_response_bits_prediction_br_mask_3 (i.io_CPU_response_bits_prediction_br_mask_3),
        .io_CPU_response_bits_prediction_hit (i.io_CPU_response_bits_prediction_hit),
        .io_CPU_response_bits_prediction_target (i.io_CPU_response_bits_prediction_target),
        .io_CPU_response_bits_prediction_br_type (i.io_CPU_response_bits_prediction_br_type),
        .io_CPU_response_bits_GHR (i.io_CPU_response_bits_GHR),
        .io_CPU_response_bits_NEXT (i.io_CPU_response_bits_NEXT),
        .io_CPU_response_bits_TOS (i.io_CPU_response_bits_TOS),
        .io_flush_valid (i.io_flush_valid),
        .io_flush_bits_is_misprediction (i.io_flush_bits_is_misprediction),
        .io_flush_bits_is_exception (i.io_flush_bits_is_exception),
        .io_flush_bits_is_fence (i.io_flush_bits_is_fence),
        .io_flush_bits_is_CSR (i.io_flush_bits_is_CSR),
        .io_flush_bits_flushing_PC (i.io_flush_bits_flushing_PC),
        .io_flush_bits_redirect_PC (i.io_flush_bits_redirect_PC)
    );



endmodule