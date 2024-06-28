class FU_dut:
    def __init__(self, dut):    # modify as needed (parameters, etc...)
        self.dut = dut

    def clock(self):
        return self.dut.clock


    def read_flush(self):
        return int(self.dut.io_flush.value)

    def FU_input_valid(self):
        return self.dut.io_FU_input_valid

    def read_FU_input(self):
        generate_null_FU_inputs = {}

        generate_null_FU_inputs["valid"]                =   int(getattr(self.dut, f"io_FU_input_valid").value)
        generate_null_FU_inputs["RS1_ready"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready").value)
        generate_null_FU_inputs["RS2_ready"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready").value)
        generate_null_FU_inputs["RD"]                   =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD").value)
        generate_null_FU_inputs["RD_valid"]             =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD_valid").value)
        generate_null_FU_inputs["RS1"]                  =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1").value)
        generate_null_FU_inputs["RS1_valid"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1_valid").value )
        generate_null_FU_inputs["RS2"]                  =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2").value)
        generate_null_FU_inputs["RS2_valid"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2_valid").value)
        generate_null_FU_inputs["IMM"]                  =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMM").value)
        generate_null_FU_inputs["FUNCT3"]               =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_FUNCT3").value)
        generate_null_FU_inputs["packet_index"]         =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_packet_index").value)
        generate_null_FU_inputs["ROB_index"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ROB_index").value)
        generate_null_FU_inputs["instructionType"]      =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_instructionType").value)
        generate_null_FU_inputs["portID"]               =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_portID").value)
        generate_null_FU_inputs["RS_type"]              =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS_type").value)
        generate_null_FU_inputs["needs_ALU"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_ALU").value)
        generate_null_FU_inputs["needs_branch_unit"]    =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_branch_unit").value)
        generate_null_FU_inputs["needs_CSRs"]           =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_CSRs").value)
        generate_null_FU_inputs["SUBTRACT"]             =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_SUBTRACT").value)
        generate_null_FU_inputs["MULTIPLY"]             =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_MULTIPLY").value)
        generate_null_FU_inputs["IMMEDIATE"]            =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_IMM").value)
        generate_null_FU_inputs["is_load"]              =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_is_load").value)
        generate_null_FU_inputs["is_store"]             =   int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_is_store").value)
        generate_null_FU_inputs["RS1_data"]             =   int(getattr(self.dut, f"io_FU_input_bits_RS1_data").value)
        generate_null_FU_inputs["RS2_data"]             =   int(getattr(self.dut, f"io_FU_input_bits_RS2_data").value)
        generate_null_FU_inputs["fetch_PC"]                   =   int(getattr(self.dut, f"io_FU_input_bits_fetch_PC").value)
        return generate_null_FU_inputs

    def FU_output_valid(self):
        return self.dut.io_FU_output_valid

    def read_FU_output(self):
        outputs = {}
        outputs["valid"]            = int(getattr(self.dut, f"io_FU_output_valid").value)
        outputs["RD"]               = int(getattr(self.dut, f"io_FU_output_bits_RD").value)
        outputs["RD_data"]          = int(getattr(self.dut, f"io_FU_output_bits_RD_data").value)
        outputs["RD_valid"]         = int(getattr(self.dut, f"io_FU_output_bits_RD_valid").value)
        outputs["fetch_PC"]               = int(getattr(self.dut, f"io_FU_output_bits_fetch_PC").value)
        outputs["branch_taken"]     = int(getattr(self.dut, f"io_FU_output_bits_branch_taken").value)
        outputs["target_address"]   = int(getattr(self.dut, f"io_FU_output_bits_target_address").value)
        outputs["branch_valid"]     = int(getattr(self.dut, f"io_FU_output_bits_branch_valid").value)
        outputs["ROB_index"]        = int(getattr(self.dut, f"io_FU_output_bits_ROB_index").value)
        outputs["packet_index"]     = int(getattr(self.dut, f"io_FU_output_bits_fetch_packet_index").value)
        return outputs 


    def monitor_output(self):
        return self.dut.monitor_output