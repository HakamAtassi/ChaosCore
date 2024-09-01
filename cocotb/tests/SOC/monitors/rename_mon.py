import copy
import logging
import cocotb
import cocotb.utils



class rename_mon:
    def __init__(self, dut):
        self.rename = dut

        self.dut_rename_request_queue  = []
        self.dut_rename_response_queue = []

        self.model_rename_response_queue = []




        # property helpers
        self.PRD_available = [True]*65 # true means the RPD is allocated, false means its not. 

        self.commit_PRD_available = [True]*65 # true means the RPD is allocated, false means its not. 

    def read_rename_request(self):
        return {
            "ready": getattr(self.rename, f"io_decoded_fetch_packet_ready").value,
            "valid": getattr(self.rename, f"io_decoded_fetch_packet_ready").value,
            "bits" :{
                "fetch_PC": getattr(self.rename, f"io_decoded_fetch_packet_bits_fetch_PC").value,
                "valid_bits": [getattr(self.rename,f"io_decoded_fetch_packet_bits_valid_bits_{i}").value for i in range(4)],
                "GHR": getattr(self.rename, f"io_decoded_fetch_packet_bits_GHR").value, 
                "TOS": getattr(self.rename, f"io_decoded_fetch_packet_bits_TOS").value, 
                "NEXT": getattr(self.rename, f"io_decoded_fetch_packet_bits_NEXT").value, 
                "hit": getattr(self.rename, f"io_decoded_fetch_packet_bits_prediction_hit").value, 
                "target": getattr(self.rename, f"io_decoded_fetch_packet_bits_prediction_target").value, 
                "br_type": getattr(self.rename, f"io_decoded_fetch_packet_bits_prediction_br_type").value, 
                "T_NT": getattr(self.rename, f"io_decoded_fetch_packet_bits_prediction_T_NT").value, 
                "front_pointer": getattr(self.rename, f"io_decoded_fetch_packet_bits_free_list_front_pointer").value, 
                "decoded_instruction": [{
                    "RS1_ready": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value,
                    "RS2_ready": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value, 
                    "RD": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value, 
                    "PRD": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_PRD").value, 
                    "PRDold": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_PRDold").value, 
                    "RD_valid": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value, 
                    "RS1": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value, 
                    "RS1_valid": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value, 
                    "RS2": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value, 
                    "RS2_valid": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value, 
                    "IMM": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value, 
                    "FUNCT3": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value, 
                    "packet_index": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value, 
                    "ROB_index": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value, 
                    "MOB_index": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MOB_index").value, 
                    "instructionType": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value, 
                    "portID": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value, 
                    "RS_type": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value, 
                    "needs_ALU": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value, 
                    "needs_branch_unit": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value, 
                    "needs_CSRs": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value, 
                    "SUBTRACT": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value, 
                    "MULTIPLY": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value, 
                    "IS_IMM": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value, 
                    "memory_type": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_memory_type").value, 
                    "access_width": getattr(self.rename, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_access_width").value
                } for i in range(4)]
            }
        }

    def read_rename_response(self):
        return {
            "valid": getattr(self.rename, f"io_renamed_decoded_fetch_packet_valid").value, 
            "ready": getattr(self.rename, f"io_renamed_decoded_fetch_packet_ready").value, 
            "bits":{
                "fetch_PC": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_fetch_PC").value,
                "GHR": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_GHR").value,
                "TOS": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_TOS").value,
                "NEXT": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_NEXT").value,
                "hit": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_prediction_hit").value,
                "target": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_prediction_target").value,
                "br_type": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_prediction_br_type").value,
                "T_NT": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_prediction_T_NT").value,
                "free_list_front_pointer": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_free_list_front_pointer").value,
                "valid_bits": [getattr(self.rename,f"io_renamed_decoded_fetch_packet_bits_valid_bits_{i}").value for i in range(4)],
                "decoded_instruction":[{
                    "RS1_Ready": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value,
                    "RS2_Ready": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value,
                    "RD": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value,
                    "PRD": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_PRD").value,
                    "PRDold": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_PRDold").value,
                    "RD_valid": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value,
                    "RS1_": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value,
                    "RS1_valid": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value,
                    "RS2": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value,
                    "RS2_valid": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value,
                    "IMM": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value,
                    "FUNCT3": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value,
                    "packet_index": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value,
                    "ROB_index": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value,
                    "MOB_index": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MOB_index").value,
                    "instructionType": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value,
                    "portID": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value,
                    "RD_type": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value,
                    "needs_ALU": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value,
                    "needs_branch_unit": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value,
                    "needs_CSRs": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value,
                    "SUBRTACT": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value,
                    "MULTIPLY": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value,
                    "IS_IMM": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value,
                    "memory_type": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_memory_type").value,
                    "access_width": getattr(self.rename, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_access_width").value,
                    } for i in range(4)]
            }
        }


    def read_FUs(self):
        return [
            {
                "valid" : getattr(self.dut, f"io_FU_outputs_{i}_valid"),
                "bits": {
                    "PRD": getattr(self.dut, f"io_FU_outputs_{i}_bits_PRD").value, 
                    "RD_data": getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value, 
                    "RD_valid": getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value, 
                    "fetch_PC": getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_PC").value, 
                    "branch_taken": getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value, 
                    "target_address": getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value, 
                    "valid": getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value, 
                    "address": getattr(self.dut, f"io_FU_outputs_{i}_bits_address").value, 
                    "memory_type": getattr(self.dut, f"io_FU_outputs_{i}_bits_memory_type").value, 
                    "access_width": getattr(self.dut, f"io_FU_outputs_{i}_bits_access_width").value, 
                    "is_unsigned": getattr(self.dut, f"io_FU_outputs_{i}_bits_is_unsigned").value, 
                    "wr_data": getattr(self.dut, f"io_FU_outputs_{i}_bits_wr_data").value, 
                    "MOB_index": getattr(self.dut, f"io_FU_outputs_{i}_bits_MOB_index").value, 
                    "ROB_index": getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value, 
                    "packet_index": getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value
                }
            } for i in range(4)
        ]

    def read_commit(self):
        return{
            "valid":getattr(self.rename, f"io_commit_valid").value,
            "bits":{
                "fetch_PC": getattr(self.rename, f"io_commit_bits_fetch_PC").value,
                "T_NT": getattr(self.rename, f"io_commit_bits_T_NT").value,
                "ROB_index": getattr(self.rename, f"io_commit_bits_ROB_index").value,
                "br_type": getattr(self.rename, f"io_commit_bits_br_type").value,
                "fetch_packet_index": getattr(self.rename, f"io_commit_bits_fetch_packet_index").value,
                "is_misprediction": getattr(self.rename, f"io_commit_bits_is_misprediction").value,
                "expected_PC": getattr(self.rename, f"io_commit_bits_expected_PC").value,
                "GHR": getattr(self.rename, f"io_commit_bits_GHR").value,
                "TOS": getattr(self.rename, f"io_commit_bits_TOS").value,
                "NEXT": getattr(self.rename, f"io_commit_bits_NEXT").value,
                "free_list_front_pointer": getattr(self.rename, f"io_commit_bits_free_list_front_pointer").value,
                "RD": [getattr(self.rename, f"io_commit_bits_RD_{i}").value for i in range(4)],
                "PRD": [getattr(self.rename, f"io_commit_bits_PRD_{i}").value for i in range(4)],
                "RD_valid": [getattr(self.rename, f"io_commit_bits_RD_valid_{i}").value for i in range(4)],
            }
        }

    def read_partial_commit(self):
        return{
            "ROB_index": getattr(self.rename, f"io_partial_commit_ROB_index").value,
            "commit_valid":[getattr(self.rename, f"io_partial_commit_valid_{i}").value for i in range(4)],
            "MOB_index":[getattr(self.rename, f"io_partial_commit_MOB_index_{i}").value for i in range(4)],
            "RD":[getattr(self.rename, f"io_partial_commit_RD_{i}").value for i in range(4)],
            "RD_valid":[getattr(self.rename, f"io_partial_commit_RD_valid_{i}").value for i in range(4)],
            "PRD":[getattr(self.rename, f"io_partial_commit_PRD_{i}").value for i in range(4)],
            "PRDold":[getattr(self.rename, f"io_partial_commit_PRDold_{i}").value for i in range(4)],
        }

    def scoreboard(self):
        pass


    def monitor(self):


        ###################
        # MONITOR SIGNALS #
        ###################

        # monitor FUs
        #if(self.read_rename_request()["valid"] and self.read_rename_request()["ready"]):
            #self.dut_rename_request_queue.append(self.read_rename_request())


        # monitor commit
        #if(self.read_rename_request()["valid"] and self.read_rename_request()["ready"]):
            #self.dut_rename_request_queue.append(self.read_rename_request())


        # monitor rename request
        if(int(self.read_rename_request()["valid"]) and int(self.read_rename_request()["ready"])):
            #print(f"monitored  @ {cocotb.utils.get_sim_time("ns")}")
            #print(int(self.read_rename_request()["valid"]))
            self.dut_rename_request_queue.append(self.read_rename_request())
            #print(f"{int(self.read_rename_request()["bits"]["fetch_PC"])}")

        # monitor rename response
        if(int(self.read_rename_response()["valid"]) and int(self.read_rename_response()["ready"])):
            #print(f"monitored  @ {cocotb.utils.get_sim_time("ns")}")
            self.dut_rename_response_queue.append(self.read_rename_response())


        #########
        # MODEL #
        #########






        # update model FUs (set ready as needed)
        # update model commit (free old PRFs)

        if(int(self.read_commit()["valid"])):
            for i in range(4):
                if(self.read_partial_commit()["commit_valid"] and self.read_partial_commit()["RD_valid"]):
                    PRDold = self.read_partial_commit()["PRDold"][i]
                    PRD = self.read_partial_commit()["PRD"][i]

                    #print(f"@ {cocotb.utils.get_sim_time("ns")}")

                    self.PRD_available[PRDold] = True
                    self.commit_PRD_available[PRDold] = True
                    self.commit_PRD_available[PRD] = False


                self.commit_PRD_available[0] = True
                self.PRD_available[0] = True


            if(self.read_commit()["bits"]["is_misprediction"]):
                self.PRD_available = copy.deepcopy(self.commit_PRD_available)

        # Assert that accepted output PRDs are infact available
        for i in range(4):
            rename_response = self.dut_rename_response_queue[0] if len(self.dut_rename_response_queue) else None
            if(rename_response and rename_response["valid"] and rename_response["bits"]["decoded_instruction"][i]["RD_valid"]):
                PRD = self.dut_rename_response_queue[0]["bits"]["decoded_instruction"][i]["PRD"]
                if(PRD != 0):
                    assert self.PRD_available[PRD], f"{PRD} allocated but was actually not ready"
                    self.PRD_available[PRD] = False

        self.commit_PRD_available[0] = True
        self.PRD_available[0] = True

            
            
        #if(self.dut_rename_response_queue[0]["valid"] and self.dut_rename_response_queue["bits"]["decoded_instruction"]["RD_valid"]):
            #PRD = self.dut_rename_response_queue[0]["valid"]["PRD"]
            #self.PRD_available[PRD] = False



        ############
        # CHECKERS #
        ############
        if(self.dut_rename_request_queue):
            self.model_rename_response_queue.append(self.scoreboard())

        
        if(self.dut_rename_response_queue and self.model_rename_response_queue):
            # compare responses 
            pass


        # properties:
        # when a valid PRD is accepted, if cant occur again on PRD until its committed as a PRDold

        try:
            self.dut_rename_request_queue.pop()
        except(IndexError): pass
        try: self.dut_rename_response_queue.pop()
        except(IndexError): pass



        



