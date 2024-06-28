import sys
from tabulate import tabulate
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly

# Add helper functions as needed

  #input         io_FU_input_valid,
                #io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready,
                #io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready,
  #input  [5:0]  io_FU_input_bits_decoded_instruction_RD,
  #input         io_FU_input_bits_decoded_instruction_RD_valid,
  #input  [5:0]  io_FU_input_bits_decoded_instruction_RS1,
  #input         io_FU_input_bits_decoded_instruction_RS1_valid,
  #input  [5:0]  io_FU_input_bits_decoded_instruction_RS2,
  #input         io_FU_input_bits_decoded_instruction_RS2_valid,
  #input  [19:0] io_FU_input_bits_decoded_instruction_IMM,
  #input  [2:0]  io_FU_input_bits_decoded_instruction_FUNCT3,
  #input  [3:0]  io_FU_input_bits_decoded_instruction_packet_index,
  #input  [5:0]  io_FU_input_bits_decoded_instruction_ROB_index,
  #input  [4:0]  io_FU_input_bits_decoded_instruction_instructionType,
  #input  [1:0]  io_FU_input_bits_decoded_instruction_portID,
                #io_FU_input_bits_decoded_instruction_RS_type,
  #input         io_FU_input_bits_decoded_instruction_needs_ALU,
                #io_FU_input_bits_decoded_instruction_needs_branch_unit,
                #io_FU_input_bits_decoded_instruction_needs_CSRs,
                #io_FU_input_bits_decoded_instruction_SUBTRACT,
                #io_FU_input_bits_decoded_instruction_MULTIPLY,
                #io_FU_input_bits_decoded_instruction_IMMEDIATE,
                #io_FU_input_bits_decoded_instruction_is_load,
                #io_FU_input_bits_decoded_instruction_is_store,
  #input  [31:0] io_FU_input_bits_RS1_data,
                #io_FU_input_bits_RS2_data,
                #io_FU_input_bits_PC,


  #output        io_FU_input_ready,
  #output        io_FU_output_valid,
  #output [5:0]  io_FU_output_bits_RD,
  #output [31:0] io_FU_output_bits_RD_data,
  #output        io_FU_output_bits_RD_valid,
  #output [31:0] io_FU_output_bits_instruction_PC,
  #output        io_FU_output_bits_branch_taken,
  #output [31:0] io_FU_output_bits_target_address,
  #output        io_FU_output_bits_branch_valid,
  #output [5:0]  io_FU_output_bits_ROB_index,
  #output [1:0]  io_FU_output_bits_fetch_packet_index

def generate_null_FU_inputs():
    FU_inputs = {}

    FU_inputs["valid"] = 0
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["is_load"] = 0
    FU_inputs["is_store"] = 0
    FU_inputs["RS1_data"] = 0
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    return FU_inputs
