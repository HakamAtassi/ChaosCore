class rename_dut:
    def __init__(self, dut):
        self.rename = dut

    ###########
    # RENAMER #
    ###########

    def rename_decoded_fetch_packet_valid(self):
        return self.rename.io_decoded_fetch_packet_valid

    def rename_decoded_fetch_packet(self):
        renamed_fetch_packet = {}
        renamed_fetch_packet["valid"] = int(self.fetch_packet_decoder.io_decoded_fetch_packet_valid.value)
        renamed_fetch_packet["fetch_PC"] = int(self.fetch_packet_decoder.io_decoded_fetch_packet_bits_fetch_PC.value)

        renamed_fetch_packet["RD"] = [0]*4
        renamed_fetch_packet["RD_valid"] = [0]*4
        renamed_fetch_packet["RS1"] = [0]*4
        renamed_fetch_packet["RS1_valid"] = [0]*4
        renamed_fetch_packet["RS2"] = [0]*4
        renamed_fetch_packet["RS2_valid"] = [0]*4
        renamed_fetch_packet["IMM"] = [0]*4
        renamed_fetch_packet["FUNCT3"] = [0]*4
        renamed_fetch_packet["packet_index"] = [0]*4
        renamed_fetch_packet["instructionType"] = [0]*4
        renamed_fetch_packet["portID"] = [0]*4
        renamed_fetch_packet["RS_type"] = [0]*4
        renamed_fetch_packet["needs_ALU"] = [0]*4
        renamed_fetch_packet["needs_branch_unit"] = [0]*4
        renamed_fetch_packet["needs_CSRs"] = [0]*4
        renamed_fetch_packet["SUBTRACT"] = [0]*4
        renamed_fetch_packet["MULTIPLY"] = [0]*4
        renamed_fetch_packet["IS_IMM"] = [0]*4
        renamed_fetch_packet["IS_LOAD"] = [0]*4
        renamed_fetch_packet["IS_STORE"] = [0]*4
        renamed_fetch_packet["valid_bits"] = [0]*4

        for i in range(4):
            renamed_fetch_packet["RD"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
            renamed_fetch_packet["RD_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
            renamed_fetch_packet["RS1"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
            renamed_fetch_packet["RS1_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
            renamed_fetch_packet["RS2"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
            renamed_fetch_packet["RS2_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
            renamed_fetch_packet["IMM"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
            renamed_fetch_packet["FUNCT3"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
            renamed_fetch_packet["packet_index"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
            renamed_fetch_packet["instructionType"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
            renamed_fetch_packet["portID"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
            renamed_fetch_packet["RS_type"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
            renamed_fetch_packet["needs_ALU"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
            renamed_fetch_packet["needs_branch_unit"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
            renamed_fetch_packet["needs_CSRs"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value)
            renamed_fetch_packet["SUBTRACT"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
            renamed_fetch_packet["MULTIPLY"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
            renamed_fetch_packet["IS_IMM"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value)
            renamed_fetch_packet["IS_LOAD"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_LOAD").value)
            renamed_fetch_packet["IS_STORE"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_STORE").value)
            renamed_fetch_packet["valid_bits"][i] = int(getattr(self.fetch_packet_decoder, f"io_decoded_fetch_packet_bits_valid_bits_{i}").value)

        return renamed_fetch_packet



    def rename_decoded_fetch_packet_valid(self):
        return self.rename.io_renamed_decoded_fetch_packet_valid

def rename_renamed_decoded_fetch_packet(self):
    renamed_decoded_fetch_packet = {}
    renamed_decoded_fetch_packet["valid"] = int(self.fetch_packet_decoder.io_renamed_decoded_fetch_packet_valid.value)
    renamed_decoded_fetch_packet["fetch_PC"] = int(self.fetch_packet_decoder.io_renamed_decoded_fetch_packet_bits_fetch_PC.value)

    renamed_decoded_fetch_packet["RS1_ready"] = [0]*4
    renamed_decoded_fetch_packet["RS2_ready"] = [0]*4
    renamed_decoded_fetch_packet["RD"] = [0]*4
    renamed_decoded_fetch_packet["RD_valid"] = [0]*4
    renamed_decoded_fetch_packet["RS1"] = [0]*4
    renamed_decoded_fetch_packet["RS1_valid"] = [0]*4
    renamed_decoded_fetch_packet["RS2"] = [0]*4
    renamed_decoded_fetch_packet["RS2_valid"] = [0]*4
    renamed_decoded_fetch_packet["IMM"] = [0]*4
    renamed_decoded_fetch_packet["FUNCT3"] = [0]*4
    renamed_decoded_fetch_packet["packet_index"] = [0]*4
    renamed_decoded_fetch_packet["instructionType"] = [0]*4
    renamed_decoded_fetch_packet["portID"] = [0]*4
    renamed_decoded_fetch_packet["RS_type"] = [0]*4
    renamed_decoded_fetch_packet["needs_ALU"] = [0]*4
    renamed_decoded_fetch_packet["needs_branch_unit"] = [0]*4
    renamed_decoded_fetch_packet["needs_CSRs"] = [0]*4
    renamed_decoded_fetch_packet["SUBTRACT"] = [0]*4
    renamed_decoded_fetch_packet["MULTIPLY"] = [0]*4
    renamed_decoded_fetch_packet["IS_IMM"] = [0]*4
    renamed_decoded_fetch_packet["IS_LOAD"] = [0]*4
    renamed_decoded_fetch_packet["IS_STORE"] = [0]*4
    renamed_decoded_fetch_packet["valid_bits"] = [0]*4
    renamed_decoded_fetch_packet["RAT_IDX"] = [0]*4

    for i in range(4):
        renamed_decoded_fetch_packet["RS1_ready"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value)
        renamed_decoded_fetch_packet["RS2_ready"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value)
        renamed_decoded_fetch_packet["RD"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
        renamed_decoded_fetch_packet["RD_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
        renamed_decoded_fetch_packet["RS1"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
        renamed_decoded_fetch_packet["RS1_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
        renamed_decoded_fetch_packet["RS2"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
        renamed_decoded_fetch_packet["RS2_valid"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
        renamed_decoded_fetch_packet["IMM"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
        renamed_decoded_fetch_packet["FUNCT3"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
        renamed_decoded_fetch_packet["packet_index"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
        renamed_decoded_fetch_packet["instructionType"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
        renamed_decoded_fetch_packet["portID"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
        renamed_decoded_fetch_packet["RS_type"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
        renamed_decoded_fetch_packet["needs_ALU"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
        renamed_decoded_fetch_packet["needs_branch_unit"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
        renamed_decoded_fetch_packet["needs_CSRs"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value)
        renamed_decoded_fetch_packet["SUBTRACT"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
        renamed_decoded_fetch_packet["MULTIPLY"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
        renamed_decoded_fetch_packet["IS_IMM"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value)
        renamed_decoded_fetch_packet["IS_LOAD"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_LOAD").value)
        renamed_decoded_fetch_packet["IS_STORE"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_STORE").value)
        renamed_decoded_fetch_packet["valid_bits"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_valid_bits_{i}").value)
        renamed_decoded_fetch_packet["RAT_IDX"][i] = int(getattr(self.fetch_packet_decoder, f"io_renamed_decoded_fetch_packet_bits_RAT_IDX_{i}").value)

    return renamed_decoded_fetch_packet