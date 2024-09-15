



class ROB_mon:
    def __init__(self, ROB):
        self.ROB = ROB


    def read_partial_commit(self):
        return {
            "valid":    [getattr(self.ROB, f"io_partial_commit_valid_{i}").value for i in range(4)],
            "ROB_index": getattr(self.ROB, f"io_partial_commit_ROB_index").value,
            "MOB_index": [getattr(self.ROB, f"io_partial_commit_MOB_index_{i}").value for i in range(4)],
            "MOB_valid": [getattr(self.ROB, f"io_partial_commit_MOB_valid_{i}").value for i in range(4)],
            "commit_RD": [getattr(self.ROB, f"io_partial_commit_RD_{i}").value for i in range(4)],
            "RD_valid":  [getattr(self.ROB, f"io_partial_commit_RD_valid_{i}").value for i in range(4)],
            "PRD":       [getattr(self.ROB, f"io_partial_commit_PRD_{i}").value for i in range(4)],
            "PRDold":    [getattr(self.ROB, f"io_partial_commit_PRDold_{i}").value for i in range(4)],
        }

    def read_commit(self):
        return{
            "valid":self.ROB.io_commit_valid.value,
            "fetch_PC":self.ROB.io_commit_bits_fetch_PC.value,
            "T_NT":self.ROB.io_commit_bits_T_NT.value,
            "ROB_index":self.ROB.io_commit_bits_ROB_index.value,
            "br_type":self.ROB.io_commit_bits_br_type.value,
            "fetch_packet_index":self.ROB.io_commit_bits_fetch_packet_index.value,
            "is_misprediction":self.ROB.io_commit_bits_is_misprediction.value,
            "expected_PC":self.ROB.io_commit_bits_expected_PC.value,
            "GHR":self.ROB.io_commit_bits_GHR.value,
            "TOS":self.ROB.io_commit_bits_TOS.value,
            "NEXT":self.ROB.io_commit_bits_NEXT.value,
            "free_list_front_pointer":self.ROB.io_commit_bits_free_list_front_pointer.value,
            "RD":[self.ROB.io_commit_bits_RD_0.value for i in range(4)],
            "PRD":[self.ROB.io_commit_bits_PRD_0.value for i in range(4)],
            "RD_valid":[self.ROB.io_commit_bits_RD_valid_0.value for i in range(4)],
        }


