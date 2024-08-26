
import random
import json
from cocotb.triggers import RisingEdge, ReadOnly
import re


def extract_signals(dut, base_name, t_hex=None): # add an int/hex option
    result = []
    pattern = fr"io_{base_name}_(\d+)_(.+)"  # Note the 'r' before the string
    
    # Get all attributes of dut that match the pattern
    matching_attrs = [attr for attr in dir(dut) if re.match(pattern, attr)]
    
    # Find the maximum index
    max_index = max([int(re.match(pattern, attr).group(1)) for attr in matching_attrs])
    
    for i in range(max_index + 1):
        entry = {"valid": None, "ready":None, "bits": {}}
        
        for attr in matching_attrs:
            match = re.match(pattern, attr)
            if match and int(match.group(1)) == i:
                if match.group(2) == "valid":
                    entry["valid"] = int(getattr(dut, attr).value)
                if match.group(2) == "ready":
                    entry["ready"] = int(getattr(dut, attr).value)
                elif match.group(2).startswith("bits_"):
                    bit_name = match.group(2)[5:]  # Remove 'bits_' prefix
                    entry["bits"][bit_name] = int(getattr(dut, attr).value)
                    if t_hex:
                        entry["bits"][bit_name] = hex(entry["bits"][bit_name])

        
        result.append(entry)
    
    return result

def write_signals(dut, base_name, data_dict):
    pattern = fr"io_{base_name}_(\d+)_(.+)"
    
    # Get all attributes of dut that match the pattern
    matching_attrs = [attr for attr in dir(dut) if re.match(pattern, attr)]
    
    for attr in matching_attrs:
        match = re.match(pattern, attr)
        
        if match:
            index = int(match.group(1))
            field = match.group(2)
            
            if index < len(data_dict):
                if field == "valid":
                    getattr(dut, attr).value= data_dict[index].get("valid", 0)
                elif field.startswith("bits_"):
                    bit_name = field[5:]  # Remove 'bits_' prefix
                    value = data_dict[index].get("bits", {}).get(bit_name, 0)
                    getattr(dut, attr).value =  value
            else:
                # Set to 0 if index is out of range of provided data
                getattr(dut, attr).value = 0




class driver:
    def __init__(self, dut):

        self.accepted_instructions_hash_map = {}
        self.dut = dut
        self.instruction_ID = 0

        self.backend_packet_input_Q = []




    def monitor_backend_packet(self):
        backend_packets = extract_signals(self.dut, "backend_packet")
        for backend_packet in backend_packets:
            if(backend_packet["valid"] and backend_packet["ready"]):
                ID = backend_packet["bits"]["instruction_ID"]

                self.accepted_instructions_hash_map[ID] = backend_packet



        # if accepted, do stuff

    def monitor_FU_inputs(self):
        FU_inputs = extract_signals(self.dut, "FU_outputs")

        for input in FU_inputs:
            if input["valid"]:  # FU inputs have no ready
                RD = input["bits"]["RD"]
                RD_data = input["bits"]["RD_data"]
            
                for instruction in self.accepted_instructions_hash_map.values():
                    bits = instruction.get("bits", {})
        
                    # Check RS1
                    if bits.get("RS1_valid") and bits.get("RS1") == RD:
                        bits["ready_bits_RS1_ready"] = 1
                        bits["RS1_data"] = RD_data
        
                    # Check RS2
                    if bits.get("RS2_valid") and bits.get("RS2") == RD:
                        bits["ready_bits_RS2_ready"] = 1
                        bits["RS2_data"] = RD_data
        
                    instruction["bits"] = bits


    def check_outputs(self):

        RF_inputs = extract_signals(self.dut, "RF_inputs")

        for RF_input in RF_inputs:
            if(RF_input["valid"]):
                ID=RF_input["bits"]["instruction_ID"]


                #print (json.dumps(self.accepted_instructions_hash_map[ID], indent=2))
                
                valid = self.accepted_instructions_hash_map[ID]["valid"]
                RS1_valid = self.accepted_instructions_hash_map[ID]["bits"]["RS1_valid"]
                RS2_valid = self.accepted_instructions_hash_map[ID]["bits"]["RS2_valid"]
                RS1_ready = self.accepted_instructions_hash_map[ID]["bits"]["ready_bits_RS1_ready"]
                RS2_ready = self.accepted_instructions_hash_map[ID]["bits"]["ready_bits_RS2_ready"]
                

                assert valid 
                assert ((RS1_valid and RS1_ready) or not RS1_valid) and ((RS2_valid and RS2_ready) or not RS2_valid)

                del self.accepted_instructions_hash_map[ID]["valid"]





    async def update(self):

        # MONITOR STUFF

        self.monitor_backend_packet()
        self.monitor_FU_inputs()
        self.check_outputs()


        ##############################
        ## CONSTRUCT BACKEND PACKET ##
        ##############################
        random_backend_packet = [{
            "valid": 0,
            "bits":{
                "RS1_ready": 0,
                "RS2_ready": 0,
                "RD": 0,
                "RS1_valid": 0,
                "RS2_valid": 0,
                "portID":0,
                "RS1": 0,
                "RS2": 0,
            }
        } for _ in range(4)]

        # FIXME: RD will increment % 64
        for i in range(4):
            random_backend_packet[i]["valid"]               =   random.getrandbits(1)
            random_backend_packet[i]["bits"]["RD"]          =   random.getrandbits(6)
            random_backend_packet[i]["bits"]["portID"]      =   random.randint(0, 2)
            
            # FIXME: this can be ANY past RD, done or not
            if(random.randint(0, 1)): # Has RS1
                valid = 1
                ready = random.randint(0, 1)
                random_backend_packet[i]["bits"]["RS1_valid"]   =  valid
                random_backend_packet[i]["bits"]["RS1_ready"]   =  ready 
                random_backend_packet[i]["bits"]["RS1"]         =  random.getrandbits(6)    

            # FIXME: this can be ANY past RD, done or not
            if(random.randint(0, 1)): # Has RS1
                valid = 1
                ready = random.randint(0, 1)
                random_backend_packet[i]["bits"]["RS2_valid"]   =  valid
                random_backend_packet[i]["bits"]["RS2_ready"]   =  ready 
                random_backend_packet[i]["bits"]["RS2"]         =  random.getrandbits(6)


            random_backend_packet[i]["bits"]["instruction_ID"]    =   self.instruction_ID

            self.instruction_ID  += 1

        if(len(self.backend_packet_input_Q)<=1):
            self.backend_packet_input_Q.append(random_backend_packet)

        write_signals(self.dut,"backend_packet", self.backend_packet_input_Q[0])



        #########################
        ## CONSTRUCT FU INPUTS ##
        #########################

        random_FU_input = [{
            "valid": 0,
            "bits":{
                "RD": 0,
                "RD_valid": 0,
            }
        } for _ in range(4)]

        for i in range(4):
            if(random.randint(0,1)):
                random_FU_input[i]["bits"]["RD"]        = random.getrandbits(6)
                random_FU_input[i]["valid"]             = 1
                random_FU_input[i]["bits"]["RD_valid"]  = 1


        write_signals(self.dut, "FU_outputs", random_FU_input)


        ####################
        # DRIVE READY BITS #
        ####################

        for i in range(3):
            getattr(self.dut, f"io_RF_inputs_{i}_ready").value = 1 #random.randint(0, 1)

        await ReadOnly()


        backend_read = extract_signals(self.dut, "backend_packet")
        all_accepted=True
        for i in range(4):
            if(not ((backend_read[i]["valid"] and backend_read[i]["ready"]) or not backend_read[i]["valid"])):
                all_accepted = False
                
        if(all_accepted):
            self.backend_packet_input_Q.pop(0)

        await RisingEdge(self.dut.clock)


    async def post_simulation(self):

        self.monitor_backend_packet()
        self.monitor_FU_inputs()
        self.check_outputs()


        for i in range(3):
            getattr(self.dut, f"io_RF_inputs_{i}_ready").value = 1 #random.randint(0, 1)







# I have an object "dut"
# with all of these members, where 0 is incremented N times
# I want to be able to read these signals by name,
# which returns a dict in the form of 
# { "valid": X,
#    "bits":{
#       # "RD":?
#       # "RD_data":?
#       # "...":?
#     }
#}[N]

# note that I want this to work for ANY field in this form
# All it needs to do is extract members with io_<name>_<all indicies>_valid
# All it needs to do is extract members with io_<name>_<all indicies>_bits_<all members> (note here I dont care what the names are as a user, it follow this naming convention, add it )

#io_FU_outputs_0_valid,
#io_FU_outputs_0_bits_RD,
#io_FU_outputs_0_bits_RD_data,
#io_FU_outputs_0_bits_RD_valid,
#io_FU_outputs_0_bits_fetch_PC,
#io_FU_outputs_0_bits_branch_taken,
#io_FU_outputs_0_bits_target_address,
#io_FU_outputs_0_bits_branch_valid,
#io_FU_outputs_0_bits_address,
#io_FU_outputs_0_bits_memory_type,
#io_FU_outputs_0_bits_access_width,
#io_FU_outputs_0_bits_is_unsigned,
#io_FU_outputs_0_bits_wr_data,
#io_FU_outputs_0_bits_MOB_index,
#io_FU_outputs_0_bits_ROB_index,
#io_FU_outputs_0_bits_FTQ_index,
#io_FU_outputs_0_bits_fetch_packet_index,
#io_FU_outputs_0_bits_violation,





#io_backend_packet_0_valid,
#io_backend_packet_0_bits_ready_bits_RS1_ready,
#io_backend_packet_0_bits_ready_bits_RS2_ready,
#io_backend_packet_0_bits_RDold,
#io_backend_packet_0_bits_RD,
#io_backend_packet_0_bits_RD_valid,
#io_backend_packet_0_bits_RS1,
#io_backend_packet_0_bits_RS1_valid,
#io_backend_packet_0_bits_RS2,
#io_backend_packet_0_bits_RS2_valid,
#io_backend_packet_0_bits_IMM,
#io_backend_packet_0_bits_FUNCT3,
#io_backend_packet_0_bits_packet_index,
#io_backend_packet_0_bits_ROB_index,
#io_backend_packet_0_bits_MOB_index,
#io_backend_packet_0_bits_FTQ_index,
#io_backend_packet_0_bits_instructionType,
#io_backend_packet_0_bits_portID,
#io_backend_packet_0_bits_RS_type,
#io_backend_packet_0_bits_needs_ALU,
#io_backend_packet_0_bits_needs_branch_unit,
#io_backend_packet_0_bits_needs_CSRs,
#io_backend_packet_0_bits_SUBTRACT,
#io_backend_packet_0_bits_MULTIPLY,
#io_backend_packet_0_bits_IS_IMM,
#io_backend_packet_0_bits_memory_type,
#io_backend_packet_0_bits_access_width,