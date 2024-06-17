import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


class ChaosCore_dut:
    def __init__(self, dut, imem, dmem):  # modify as needed (parameters, etc...)
        self.ChaosCore = dut

        # Frontend Modules #
        self.predecoder = dut.frontend.instruction_fetch.predecoder
        self.PC_gen = dut.frontend.instruction_fetch.PC_gen

        # Backend Modules #

        self.imem = imem
        self.dmem = dmem

    def clock(self):  # Do not touch
        return self.ChaosCore.clock

    async def reset(self):  # Do not touch
        self.ChaosCore.reset.value = 0
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 1
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 0

    # -----------------
    # ADDRESSING LOGIC
    # -----------------

    def get_fetch_packet_valid_bits(self, fetch_PC):
        index = fetch_PC & 0xF
        if index == 0:
            return [1, 1, 1, 1]
        elif index == 4:
            return [0, 1, 1, 1]
        elif index == 8:
            return [0, 0, 1, 1]
        elif index == 12:
            return [0, 0, 0, 1]
        assert False, "Fetch PC not aligned to instruction"

    def get_aligned_PC(self, fetch_PC):
        return fetch_PC & 0xFFFF_FFF0

    # -------------
    # IMEM CONTROL
    # -------------

    def read_imem_request_valid(self):
        return self.ChaosCore.io_frontend_memory_request_valid.value

    def read_imem_request_ready(self):
        return self.ChaosCore.io_frontend_memory_request_ready.value

    def read_imem_request_addr(self):
        return self.ChaosCore.io_frontend_memory_request_bits_addr.value

    def write_imem_request_ready(self, ready):
        self.ChaosCore.io_frontend_memory_request_ready.value = ready

    def write_imem_response(self, data: bytearray = None, valid=0):

        fetch_PC = self.read_imem_request_addr()
        valid_bits = self.get_fetch_packet_valid_bits(fetch_PC)

        self.ChaosCore.io_frontend_memory_response_valid.value = valid if valid else 0
        self.ChaosCore.io_frontend_memory_response_bits_fetch_PC.value = (
            fetch_PC if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_0.value = (
            valid_bits[0] if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_1.value = (
            valid_bits[1] if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_2.value = (
            valid_bits[2] if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_3.value = (
            valid_bits[3] if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_instruction.value = (
            int.from_bytes(data[0:4], byteorder="little") if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_packet_index.value = (
            0 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_ROB_index.value = (
            0 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_instruction.value = (
            int.from_bytes(data[4:8], byteorder="little") if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_packet_index.value = (
            1 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_ROB_index.value = (
            0 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_instruction.value = (
            int.from_bytes(data[8:12], byteorder="little") if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_packet_index.value = (
            2 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_ROB_index.value = (
            0 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_instruction.value = (
            int.from_bytes(data[12:16], byteorder="little") if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_packet_index.value = (
            3 if valid else 0
        )
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_ROB_index.value = (
            0 if valid else 0
        )

    # -------------
    # DMEM CONTROL
    # -------------

    def read_dmem_request_valid(self):
        return self.ChaosCore.io_backend_memory_request_valid.value

    def read_dmem_request_ready(self):
        return self.ChaosCore.io_backend_memory_request_ready.value

    def read_dmem_request_addr(self):
        return self.ChaosCore.io_backend_memory_request_bits_addr.value

    def read_dmem_request_wr_en(self):
        return self.ChaosCore.io_backend_memory_request_bits_wr_en.value

    def read_dmem_request_data(self):
        return self.ChaosCore.io_backend_memory_request_bits_wr_data.value

    def write_dmem_request_ready(self, ready):
        self.ChaosCore.io_backend_memory_request_ready.value = ready

    def write_dmem_response(self, data=0, valid=0):
        self.ChaosCore.io_backend_memory_response_valid.value = valid
        self.ChaosCore.io_backend_memory_response_bits_data.value = data if valid else 0

    async def update(self):  # clock cycle with memory handling

        # clear previous responses
        self.write_imem_response()
        self.write_dmem_response()

        # handle imem read requests
        if self.read_imem_request_ready() & self.read_imem_request_valid():
            addr = self.read_imem_request_addr()
            data = self.imem.read(address=self.get_aligned_PC(addr), size=16)
            self.write_imem_response(data, 1)

        # handle dmem read/write requests
        if self.read_dmem_request_ready() & self.read_dmem_request_valid():
            wr_en = self.read_dmem_request_wr_en()
            data = self.read_dmem_request_data()
            addr = self.read_dmem_request_addr()
            if wr_en:  # write
                # FIXME: size depends on instruction
                self.dmem.write(address=addr, data=data, size=4)
            else:  # read
                # FIXME: size depends on instruction
                data = self.dmem.read(address=addr, size=4)
                self.write_dmem_response(data, 1)

        await RisingEdge(self.clock())

    ################
    ## PREDECODER ##
    ################

    def predecoder_prediction_valid(self):
        return self.predecoder.io_prediction_valid

    def predecoder_read_prediction(self):
        prediction = {}
        prediction["ready"] = self.predecoder.io_prediction_ready.value
        prediction["valid"] = self.predecoder.io_prediction_valid.value
        prediction["hit"] = self.predecoder.io_prediction_bits_hit.value
        prediction["target"] = self.predecoder.io_prediction_bits_target.value
        # prediction["br_type"] = self.predecoder.io_prediction_bits_br_type.value
        # prediction["br_mask"] = self.predecoder.io_prediction_bits_br_mask.value
        # prediction["GHR"] = self.predecoder.io_prediction_bits_GHR.value
        prediction["T_NT"] = self.predecoder.io_prediction_bits_T_NT.value

        return prediction

    def predecoder_fetch_packet_valid(self):
        return self.predecoder.io_fetch_packet_valid

    def predecoder_read_fetch_packet(self):
        fetch_packet = {}
        fetch_packet["ready"] = 0
        fetch_packet["valid"] = 0
        fetch_packet["fetch_PC"] = 0

        fetch_packet["ready"] = self.predecoder.io_fetch_packet_ready.value
        fetch_packet["valid"] = self.predecoder.io_fetch_packet_valid.value
        fetch_packet["fetch_PC"] = self.predecoder.io_fetch_packet_bits_fetch_PC.value

        fetch_packet["valid_bits"] = [0] * 4
        fetch_packet["instruction"] = [0] * 4
        fetch_packet["packet_index"] = [0] * 4
        fetch_packet["ROB_index"] = [0] * 4

        for i in range(4):
            fetch_packet["valid_bits"][i] = getattr(
                self.predecoder, f"io_fetch_packet_bits_valid_bits_{i}"
            ).value

            fetch_packet["instruction"][i] = getattr(
                self.predecoder, f"io_fetch_packet_bits_instructions_{i}_instruction"
            ).value
            fetch_packet["packet_index"][i] = getattr(
                self.predecoder, f"io_fetch_packet_bits_instructions_{i}_packet_index"
            ).value
            fetch_packet["ROB_index"][i] = getattr(
                self.predecoder, f"io_fetch_packet_bits_instructions_{i}_ROB_index"
            ).value
        return fetch_packet

    def predecoder_read_RAS_read(self):
        RAS_read = {}
        RAS_read["NEXT"] = self.predecoder.io_RAS_read_NEXT.value
        RAS_read["TOS"] = self.predecoder.io_RAS_read_TOS.value
        RAS_read["ret_addt"] = self.predecoder.io_RAS_read_ret_addr.value
        return RAS_read

    def predecoder_commit_valid(self):
        return self.predecoder.io_commit_valid

    def predecoder_read_commit(self):
        commit = {}

        commit["valid"] = self.predecoder.io_commit_valid.value
        commit["fetch_PC"] = self.predecoder.io_commit_fetch_PC.value
        commit["T_NT"] = self.predecoder.io_commit_T_NT.value
        commit["ROB_index"] = self.predecoder.io_commit_ROB_index.value
        commit["br_type"] = self.predecoder.io_commit_br_type.value
        commit["fetch_packet_index"] = (
            self.predecoder.io_commit_fetch_packet_index.value
        )
        commit["is_misprediction"] = self.predecoder.io_commit_is_misprediction.value
        commit["expected_PC"] = self.predecoder.io_commit_expected_PC.value
        commit["GHR"] = self.predecoder.io_commit_GHR.value
        commit["TOS"] = self.predecoder.io_commit_TOS.value
        commit["NEXT"] = self.predecoder.io_commit_NEXT.value
        commit["RAT_IDX"] = self.predecoder.io_commit_RAT_IDX.value
        return commit

    def predecoder_revert_valid(self):
        return self.predecoder.io_revert_valid

    def predecoder_read_revert(self):
        revert = {}
        # revert["ready"] = self.predecoder.io_revert_ready.value   # FIXME: optimized out?
        revert["valid"] = self.predecoder.io_revert_valid.value
        revert["GHR"] = self.predecoder.io_revert_bits_GHR.value
        revert["PC"] = self.predecoder.io_revert_bits_PC.value
        return revert

    def predecoder_read_GHR(self):
        GHR = {}
        GHR["GHR"] = self.predecoder.io_GHR.value
        return GHR

    def predecoder_final_fetch_packet_valid(self):
        return self.predecoder.io_final_fetch_packet_ready

    def predecoder_read_final_fetch_packet(self):
        final_fetch_packet = {}

        final_fetch_packet["ready"] = self.predecoder.io_final_fetch_packet_ready
        final_fetch_packet["valid"] = self.predecoder.io_final_fetch_packet_valid

        final_fetch_packet["valid"] = self.predecoder.io_final_fetch_packet_valid

        final_fetch_packet["fetch_PC"] = (
            self.predecoder.io_final_fetch_packet_bits_fetch_PC
        )

        final_fetch_packet["valid_bits"] = [0] * 4
        final_fetch_packet["instruction"] = [0] * 4
        final_fetch_packet["packet_index"] = [0] * 4
        final_fetch_packet["ROB_index"] = [0] * 4

        for i in range(4):
            final_fetch_packet["valid_bits"][i] = getattr(
                self.predecoder, f"io_final_fetch_packet_bits_valid_bits_{i}"
            ).value
            final_fetch_packet["instruction"][i] = getattr(
                self.predecoder,
                f"io_final_fetch_packet_bits_instructions_{i}_instruction",
            ).value
            final_fetch_packet["packet_index"][i] = getattr(
                self.predecoder,
                f"io_final_fetch_packet_bits_instructions_{i}_packet_index",
            ).value
            final_fetch_packet["ROB_index"][i] = getattr(
                self.predecoder,
                f"io_final_fetch_packet_bits_instructions_{i}_ROB_index",
            ).value

    def predecoder_read_RAS_update(self):
        self.predecoder.io_RAS_update_call_addr
        self.predecoder.io_RAS_update_call
        self.predecoder.io_RAS_update_ret

    def predecoder_predictions_valid(self):
        return self.predecoder.io_predictions_valid

    def predecoder_read_predictions(self):
        predictions = {}
        predictions["ready"] = self.predecoder.io_predictions_ready
        predictions["valid"] = self.predecoder.io_predictions_valid

        predictions["bits_valid"] = self.predecoder.io_predictions_bits_valid
        predictions["fetch_PC"] = self.predecoder.io_predictions_bits_fetch_PC
        predictions["is_misprediction"] = (
            self.predecoder.io_predictions_bits_is_misprediction
        )
        predictions["predicted_PC"] = self.predecoder.io_predictions_bits_predicted_PC
        predictions["T_NT"] = self.predecoder.io_predictions_bits_T_NT
        predictions["br_type"] = self.predecoder.io_predictions_bits_br_type
        predictions["GHR"] = self.predecoder.io_predictions_bits_GHR
        predictions["NEXT"] = self.predecoder.io_predictions_bits_NEXT
        predictions["TOS"] = self.predecoder.io_predictions_bits_TOS
        predictions["dominant_index"] = (
            self.predecoder.io_predictions_bits_dominant_index
        )
        predictions["resolved_PC"] = self.predecoder.io_predictions_bits_resolved_PC

    ##############
    ## PC ARBIT ##
    ##############

    def PC_gen_commit_valid(self):
        return self.PC_gen.io_commit_valid

    def PC_gen_read_commit(self):
        commit = {}
        commit["valid"] = self.PC_gen.io_commit_valid.value
        commit["fetch_PC"] = self.PC_gen.io_commit_fetch_PC.value
        commit["T_NT"] = self.PC_gen.io_commit_T_NT.value
        commit["ROB_index"] = self.PC_gen.io_commit_ROB_index.value
        commit["br_type"] = self.PC_gen.io_commit_br_type.value
        commit["fetch_packet_index"] = self.PC_gen.io_commit_fetch_packet_index.value
        commit["is_misprediction"] = self.PC_gen.io_commit_is_misprediction.value
        commit["exoected_PC"] = self.PC_gen.io_commit_expected_PC.value
        commit["commit_GHR"] = self.PC_gen.io_commit_GHR.value
        commit["TOS"] = self.PC_gen.io_commit_TOS.value
        commit["NEXT"] = self.PC_gen.io_commit_NEXT.value
        commit["RAT_IDX"] = self.PC_gen.io_commit_RAT_IDX.value
        return commit

    def PC_gen_prediction_valid(self):
        return self.PC_gen.io_prediction_valid

    def PC_gen_read_prediction(self):
        prediction = {}

        # FIXME: signals optimized out
        # prediction["ready"] = self.PC_gen.io_prediction_ready.value
        prediction["valid"] = self.PC_gen.io_prediction_valid.value
        prediction["hit"] = self.PC_gen.io_prediction_bits_hit.value
        prediction["target"] = self.PC_gen.io_prediction_bits_target.value
        prediction["br_type"] = self.PC_gen.io_prediction_bits_br_type.value
        # prediction["br_mask"] = self.PC_gen.io_prediction_bits_br_mask.value
        # prediction["GHR"] = self.PC_gen.io_prediction_bits_GHR.value
        # prediction["T_NT"] = self.PC_gen.io_prediction_bits_T_NT.value
        return prediction

    def PC_gen_revert_valid(self):
        return self.PC_gen.io_revert_valid

    def PC_gen_read_revert(self):
        revert = {}

        revert["ready"] = self.PC_gen.io_revert_ready.value
        revert["valid"] = self.PC_gen.io_revert_valid.value
        revert["GHR"] = self.PC_gen.io_revert_bits_GHR.value
        revert["PC"] = self.PC_gen.io_revert_bits_PC.value
        return revert

    def PC_gen_read_RAS_read(self):
        RAS_read = {}
        RAS_read["NEXT"] = self.PC_gen.io_RAS_read_NEXT.value
        RAS_read["TOS"] = self.PC_gen.io_RAS_read_TOS.value
        RAS_read["ret_addr"] = self.PC_gen.io_RAS_read_ret_addr.value
        return RAS_read

    def PC_gen_PC_next_valid(self):
        return self.PC_gen.io_PC_next_valid

    def PC_gen_read_PC_next(self):
        PC_next = {}
        PC_next["ready"] = self.PC_gen.io_PC_next_ready.value
        PC_next["valid"] = self.PC_gen.io_PC_next_valid.value
        PC_next["next"] = int(self.PC_gen.io_PC_next_bits_addr.value)
        return PC_next
