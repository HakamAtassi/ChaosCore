



class backend_mon:
    def __init__(self, backend):
        self.backend = backend
        pass


    def read_backend_packet(self):
        return [{
            "ready": getattr(self.backend, f"io_backend_packet_{i}_ready").value,
            "valid": getattr(self.backend, f"io_backend_packet_{i}_valid").value,
            "bits": {
                "RS1_ready": getattr(self.backend, f"io_backend_packet_{i}_bits_ready_bits_RS1_ready").value,
                "RS2_ready": getattr(self.backend, f"io_backend_packet_{i}_bits_ready_bits_RS2_ready").value,
                "RD": getattr(self.backend, f"io_backend_packet_{i}_bits_RD").value,
                "PRD": getattr(self.backend, f"io_backend_packet_{i}_bits_PRD").value,
                "PRDold": getattr(self.backend, f"io_backend_packet_{i}_bits_PRDold").value,
                "RD_valid": getattr(self.backend, f"io_backend_packet_{i}_bits_RD_valid").value,
                "RS1": getattr(self.backend, f"io_backend_packet_{i}_bits_RS1").value,
                "RS1_valid": getattr(self.backend, f"io_backend_packet_{i}_bits_RS1_valid").value,
                "RS2": getattr(self.backend, f"io_backend_packet_{i}_bits_RS2").value,
                "RS2_valid": getattr(self.backend, f"io_backend_packet_{i}_bits_RS2_valid").value,
                "IMM": getattr(self.backend, f"io_backend_packet_{i}_bits_IMM").value,
                "FUNCT3": getattr(self.backend, f"io_backend_packet_{i}_bits_FUNCT3").value,
                "packet_index": getattr(self.backend, f"io_backend_packet_{i}_bits_packet_index").value,
                "ROB_index": getattr(self.backend, f"io_backend_packet_{i}_bits_ROB_index").value,
                "MOB_index": getattr(self.backend, f"io_backend_packet_{i}_bits_MOB_index").value,
                "instructionType": getattr(self.backend, f"io_backend_packet_{i}_bits_instructionType").value,
                "portID": getattr(self.backend, f"io_backend_packet_{i}_bits_portID").value,
                "RS_type": getattr(self.backend, f"io_backend_packet_{i}_bits_RS_type").value,
                "needs_ALU": getattr(self.backend, f"io_backend_packet_{i}_bits_needs_ALU").value,
                "needs_branch_unit": getattr(self.backend, f"io_backend_packet_{i}_bits_needs_branch_unit").value,
                "needs_CSRs": getattr(self.backend, f"io_backend_packet_{i}_bits_needs_CSRs").value,
                "SUBTRACT": getattr(self.backend, f"io_backend_packet_{i}_bits_SUBTRACT").value,
                "MULTIPLY": getattr(self.backend, f"io_backend_packet_{i}_bits_MULTIPLY").value,
                "IS_IMM": getattr(self.backend, f"io_backend_packet_{i}_bits_IS_IMM").value,
                "memory_type": getattr(self.backend, f"io_backend_packet_{i}_bits_memory_type").value,
                "access_width": getattr(self.backend, f"io_backend_packet_{i}_bits_access_width").value,
            }
        } for i in range(4)]



    def read_FU_outputs(self):
        return [{
            "valid": getattr(self.backend, f"io_FU_outputs_{i}_valid").value,
            "bits": {
                "PRD": getattr(self.backend, f"io_FU_outputs_{i}_bits_PRD").value,
                "RD_data": getattr(self.backend, f"io_FU_outputs_{i}_bits_RD_data").value,
                "RD_valid": getattr(self.backend, f"io_FU_outputs_{i}_bits_RD_valid").value,
                "fetch_PC": getattr(self.backend, f"io_FU_outputs_{i}_bits_fetch_PC").value,
                "branch_taken": getattr(self.backend, f"io_FU_outputs_{i}_bits_branch_taken").value,
                "target_address": getattr(self.backend, f"io_FU_outputs_{i}_bits_target_address").value,
                "branch_valid": getattr(self.backend, f"io_FU_outputs_{i}_bits_branch_valid").value,
                "address": getattr(self.backend, f"io_FU_outputs_{i}_bits_address").value,
                "memory_type": getattr(self.backend, f"io_FU_outputs_{i}_bits_memory_type").value,
                "access_width": getattr(self.backend, f"io_FU_outputs_{i}_bits_access_width").value,
                "is_unsigned": getattr(self.backend, f"io_FU_outputs_{i}_bits_is_unsigned").value,
                "wr_data": getattr(self.backend, f"io_FU_outputs_{i}_bits_wr_data").value,
                "MOB_index": getattr(self.backend, f"io_FU_outputs_{i}_bits_MOB_index").value,
                "ROB_index": getattr(self.backend, f"io_FU_outputs_{i}_bits_ROB_index").value,
                "fetch_packet_index": getattr(self.backend, f"io_FU_outputs_{i}_bits_fetch_packet_index").value
            }
        } for i in range(4)]


