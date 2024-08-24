import random





class memory_model:
    def __init__(self, dut, mem):
        self.dut = dut
        self.mem = mem
        self.request_map = {}   # map cache lines to request queues

    def write_response(self, response):
        getattr(self.dut, "io_backend_memory_response_valid").value = response["valid"]
        getattr(self.dut, "io_backend_memory_response_bits_addr").value = response["addr"]
        getattr(self.dut, "io_backend_memory_response_bits_data").value = response["data"]
        getattr(self.dut, "io_backend_memory_response_bits_MOB_index").value = response["MOB_index"]



    def read_request(self):
        # when a request is detected
        access_width_map = [0, 1, 2, 4]

        valid       = int(self.dut.io_backend_memory_request_valid.value)
        address     = int(self.dut.io_backend_memory_request_bits_addr.value)
        cache_line  = address & 0xFFFF_FFE0
        data        = int(self.dut.io_backend_memory_request_bits_data.value)
        wr_en       = int(self.dut.io_backend_memory_request_bits_memory_type.value) == 0b10
        MOB_index   = int(self.dut.io_backend_memory_request_bits_MOB_index.value)
        byte_count  = access_width_map[int(self.dut.io_backend_memory_request_bits_access_width.value)]

        if(valid):
            request = {
                "valid" : valid,
                "addr" : address,
                "data" :data ,
                "wr_en" : wr_en,
                "byte_count" : byte_count,
                "MOB_index" : MOB_index,
            }
            self.request_map.setdefault(cache_line, []).append(request)


        
    async def update(self):
        self.read_request()

        self.write_response({
            "valid" : 0,
            "addr" : 0,
            "data"    :0 ,
            "wr_en" : 0,
            "MOB_index" : 0,
            "byte_count" : 0
        })

        if(self.request_map):
            service_request = random.uniform(0,1)
            if(service_request < 0.2):
                #random_request = random.choice(self.request_map).pop(0)
                # if queue is empty, delete it
                # Choose a random key from the dictionary
                random_key = random.choice(list(self.request_map.keys()))

                # Pop the first element from the queue corresponding to the chosen key
                random_request = self.request_map[random_key].pop(0)

                if not self.request_map[random_key]:
                    # If empty, delete the entry from the dictionary
                    del self.request_map[random_key]

                valid = random_request["valid"]
                address = random_request["addr"]
                data = random_request["data"]
                byte_count = random_request["byte_count"]
                wr_en = random_request["wr_en"]
                MOB_index = random_request["MOB_index"]

                if(wr_en):  # random outstanding request is a store
                    self.mem[address:address+byte_count] = data

                else:       # random outstanding request is a load
                    response = {
                        "valid": valid,
                        "addr": address,
                        "data": int.from_bytes(self.mem[address:address+byte_count], "little"),
                        "MOB_index": MOB_index
                    }

                    self.write_response(response)

                