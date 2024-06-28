
class fetch_packet_decoder_dut:
    def __init__(self, dut):
        self.dut = dut

    def clock(self):
        return self.dut.clock

    ########################
    # FETCH PACKET DECODER #
    ########################

    def fetch_packet_decoder_fetch_packet_valid(self):
        return self.dut.io_fetch_packet_valid

    def fetch_packet_decoder_read_fetch_packet(self):
        fetch_packet = {}

        fetch_packet["ready"] = int(self.dut.io_fetch_packet_ready.value)
        fetch_packet["valid"] = int(self.dut.io_fetch_packet_valid.value)
        fetch_packet["fetch_PC"] = int(self.dut.io_fetch_packet_bits_fetch_PC.value)


        fetch_packet["valid_bits"]      = [0]*4
        fetch_packet["instruction"]     = [0]*4
        fetch_packet["packet_index"]    = [0]*4
        fetch_packet["ROB_index"]       = [0]*4


        for i in range(4):
            fetch_packet["valid_bits"][i]   = int(getattr(self.dut, f"io_fetch_packet_bits_valid_bits_{i}").value)
            fetch_packet["instruction"][i]  = int(getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_instruction").value)
            fetch_packet["packet_index"][i] = int(getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_packet_index").value)
            fetch_packet["ROB_index"][i]    = int(getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_ROB_index").value)

        return fetch_packet

    def fetch_packet_decoder_decoded_fetch_packet_valid(self):
        return self.dut.io_decoded_fetch_packet_valid
    
    def fetch_packet_decoder_read_decoded_fetch_packet(self):
        decoded_fetch_packet = {}
        decoded_fetch_packet["valid"] = int(self.dut.io_decoded_fetch_packet_valid.value)
        decoded_fetch_packet["fetch_PC"] = int(self.dut.io_decoded_fetch_packet_bits_fetch_PC.value)

        decoded_fetch_packet["RD"] = [0]*4
        decoded_fetch_packet["RD_valid"] = [0]*4
        decoded_fetch_packet["RS1"] = [0]*4
        decoded_fetch_packet["RS1_valid"] = [0]*4
        decoded_fetch_packet["RS2"] = [0]*4
        decoded_fetch_packet["RS2_valid"] = [0]*4
        decoded_fetch_packet["IMM"] = [0]*4
        decoded_fetch_packet["FUNCT3"] = [0]*4
        decoded_fetch_packet["packet_index"] = [0]*4
        decoded_fetch_packet["ROB_index"] = [0]*4
        decoded_fetch_packet["instructionType"] = [0]*4
        decoded_fetch_packet["portID"] = [0]*4
        decoded_fetch_packet["RS_type"] = [0]*4
        decoded_fetch_packet["needs_ALU"] = [0]*4
        decoded_fetch_packet["needs_branch_unit"] = [0]*4
        decoded_fetch_packet["SUBTRACT"] = [0]*4
        decoded_fetch_packet["MULTIPLY"] = [0]*4
        decoded_fetch_packet["IS_IMM"] = [0]*4
        decoded_fetch_packet["is_load"] = [0]*4
        decoded_fetch_packet["is_store"] = [0]*4
        decoded_fetch_packet["valid_bits"] = [0]*4

        for i in range(4):
            decoded_fetch_packet["RD"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
            decoded_fetch_packet["RD_valid"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
            decoded_fetch_packet["RS1"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
            decoded_fetch_packet["RS1_valid"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
            decoded_fetch_packet["RS2"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
            decoded_fetch_packet["RS2_valid"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
            decoded_fetch_packet["IMM"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
            decoded_fetch_packet["FUNCT3"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
            decoded_fetch_packet["packet_index"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
            decoded_fetch_packet["ROB_index"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value)
            decoded_fetch_packet["instructionType"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
            decoded_fetch_packet["portID"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
            decoded_fetch_packet["RS_type"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
            decoded_fetch_packet["needs_ALU"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
            decoded_fetch_packet["needs_branch_unit"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
            decoded_fetch_packet["SUBTRACT"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
            decoded_fetch_packet["MULTIPLY"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
            decoded_fetch_packet["IS_IMM"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value)
            decoded_fetch_packet["is_load"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_load").value)
            decoded_fetch_packet["is_store"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_store").value)
            decoded_fetch_packet["valid_bits"][i] = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_valid_bits_{i}").value)

        return decoded_fetch_packet

    def fetch_packet_decoder_read_flush(self):
        return int(self.dut.io_flush.value)

    def monitor_output(self):
        return self.dut.monitor_output