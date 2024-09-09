import copy
import logging
import cocotb
import cocotb.utils



class memory_mon:
    def __init__(self, MOB):
        self.MOB = MOB

    def read_memory_request(self):
        return {
            "valid": getattr(self.MOB, "io_backend_memory_request_valid").value,
            "ready": getattr(self.MOB, "io_backend_memory_request_ready").value,
            "bits": {
                "addr": getattr(self.MOB, "io_backend_memory_request_bits_addr").value,
                "data": getattr(self.MOB, "io_backend_memory_request_bits_data").value,
                "memory_type": getattr(self.MOB, "io_backend_memory_request_bits_memory_type").value,
                "access_width": getattr(self.MOB, "io_backend_memory_request_bits_access_width").value,
                "MOB_index": getattr(self.MOB, "io_backend_memory_request_bits_MOB_index").value,
                "packet_index": getattr(self.MOB, "io_backend_memory_request_bits_packet_index").value,
                "ROB_index": getattr(self.MOB, "io_backend_memory_request_bits_ROB_index").value,
                #"PRD": getattr(self.MOB, "io_backend_memory_request_bits_PRD").value,
                "response_ready": getattr(self.MOB, "io_backend_memory_response_ready").value
            }
        }

    
    def monitor(self):

        monitored_request = self.read_memory_request()
        op = ["NA", "LW", "SW"][int(monitored_request["bits"]["memory_type"])]
        addr = hex(int(monitored_request["bits"]["addr"]))
        data = hex(int(monitored_request["bits"]["data"]))

        #if(monitored_request["valid"] and monitored_request["ready"]):
            #if(op == "LW"):
                #print(f"load request from mem[{addr}]")
            #if(op == "SW"):
                #print(f"store request to mem[{addr}]={data}")
