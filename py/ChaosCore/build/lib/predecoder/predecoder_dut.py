
class predecoder_dut:
    def __init__(self, dut):
        self.predecoder = dut

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
        fetch_packet["fetch_PC"] = int(
            self.predecoder.io_fetch_packet_bits_fetch_PC.value
        )

        fetch_packet["valid_bits"] = [0] * 4
        fetch_packet["instruction"] = [0] * 4
        fetch_packet["packet_index"] = [0] * 4
        fetch_packet["ROB_index"] = [0] * 4

        for i in range(4):
            fetch_packet["valid_bits"][i] = int(
                getattr(self.predecoder, f"io_fetch_packet_bits_valid_bits_{i}").value
            )

            fetch_packet["instruction"][i] = int(
                getattr(
                    self.predecoder,
                    f"io_fetch_packet_bits_instructions_{i}_instruction",
                ).value
            )
            fetch_packet["packet_index"][i] = int(
                getattr(
                    self.predecoder,
                    f"io_fetch_packet_bits_instructions_{i}_packet_index",
                ).value
            )
            fetch_packet["ROB_index"][i] = int(
                getattr(
                    self.predecoder, f"io_fetch_packet_bits_instructions_{i}_ROB_index"
                ).value
            )
        return fetch_packet

    def predecoder_read_RAS_read(self):
        RAS_read = {}
        RAS_read["NEXT"] = self.predecoder.io_RAS_read_NEXT.value
        RAS_read["TOS"] = self.predecoder.io_RAS_read_TOS.value
        RAS_read["ret_addr"] = self.predecoder.io_RAS_read_ret_addr.value
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
        commit["RAT_index"] = self.predecoder.io_commit_RAT_index.value
        return commit


    def predecoder_read_GHR(self):
        GHR = {}
        GHR["GHR"] = self.predecoder.io_GHR.value
        return GHR

    def predecoder_final_fetch_packet_valid(self):
        return self.predecoder.io_final_fetch_packet_valid

    def predecoder_read_final_fetch_packet(self):
        final_fetch_packet = {}

        final_fetch_packet["ready"] = int(
            self.predecoder.io_final_fetch_packet_ready.value
        )
        final_fetch_packet["valid"] = int(
            self.predecoder.io_final_fetch_packet_valid.value
        )

        final_fetch_packet["fetch_PC"] = int(
            self.predecoder.io_final_fetch_packet_bits_fetch_PC.value
        )

        final_fetch_packet["valid_bits"] = [0] * 4
        final_fetch_packet["instruction"] = [0] * 4
        final_fetch_packet["packet_index"] = [0] * 4
        final_fetch_packet["ROB_index"] = [0] * 4

        for i in range(4):
            final_fetch_packet["valid_bits"][i] = int(
                getattr(
                    self.predecoder, f"io_final_fetch_packet_bits_valid_bits_{i}"
                ).value
            )
            final_fetch_packet["instruction"][i] = int(
                getattr(
                    self.predecoder,
                    f"io_final_fetch_packet_bits_instructions_{i}_instruction",
                ).value
            )
            final_fetch_packet["packet_index"][i] = int(
                getattr(
                    self.predecoder,
                    f"io_final_fetch_packet_bits_instructions_{i}_packet_index",
                ).value
            )
            final_fetch_packet["ROB_index"][i] = int(
                getattr(
                    self.predecoder,
                    f"io_final_fetch_packet_bits_instructions_{i}_ROB_index",
                ).value
            )
        return final_fetch_packet

    def predecoder_read_RAS_update(self):
        RAS_update = {}
        RAS_update["call_addr"] = self.predecoder.io_RAS_update_call_addr
        RAS_update["call"] = self.predecoder.io_RAS_update_call
        RAS_update["ret"] = self.predecoder.io_RAS_update_ret
        return RAS_update

    def predecoder_predictions_valid(self):
        return self.predecoder.io_predictions_valid

    def predecoder_read_predictions(self):
        predictions = {}
        predictions["ready"] = self.predecoder.io_predictions_ready
        predictions["valid"] = self.predecoder.io_predictions_valid

        predictions["bits_valid"]           = int(self.predecoder.io_predictions_bits_valid.value)
        predictions["fetch_PC"]             = int(self.predecoder.io_predictions_bits_fetch_PC.value)
        predictions["is_misprediction"]     = int((self.predecoder.io_predictions_bits_is_misprediction.value))
        predictions["predicted_PC"]         = int(self.predecoder.io_predictions_bits_predicted_PC.value)
        predictions["T_NT"]                 = int(self.predecoder.io_predictions_bits_T_NT.value)
        predictions["br_type"]              = int(self.predecoder.io_predictions_bits_br_type.value)
        predictions["GHR"]                  = int(self.predecoder.io_predictions_bits_GHR.value)
        predictions["NEXT"]                 = int(self.predecoder.io_predictions_bits_NEXT.value)
        predictions["TOS"]                  = int(self.predecoder.io_predictions_bits_TOS.value)
        predictions["dominant_index"]       = int((self.predecoder.io_predictions_bits_dominant_index.value))
        predictions["resolved_PC"]          = int(self.predecoder.io_predictions_bits_resolved_PC.value)

        return predictions


