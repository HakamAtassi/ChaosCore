import re
from collections import deque, namedtuple

# Define a namedtuple to store each trace entry
TraceEntry = namedtuple('TraceEntry', ['pc', 'rd', 'data', 'mem_addr', 'mem_data'])

class readTrace:
    def __init__(self, log_file: str):
        self.log_file = log_file
        self.trace_queue = deque()

    def parse_log(self):
        # Adjusted regular expression to match both cases with and without instruction parentheses
        entry_pattern = re.compile(
            r'core\s+\d+:\s+\d+\s+(0x[0-9a-f]+)'         # PC
            r'(?:\s+\(0x[0-9a-f]+\))?'                  # Optional instruction in parentheses
            r'(?:\s+x(\d+)\s+(0x[0-9a-f]+))?'           # Optional RD and Data
            r'(?:\s+mem\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+))?'  # Optional Mem Addr and Mem Data
        )

        # Open the log file and parse each line
        with open(self.log_file, 'r') as file:
            for line in file:
                match = entry_pattern.match(line)
                if match:
                    pc, rd, data, mem_addr, mem_data = match.groups()
                    # Convert register and memory data if present
                    rd = int(rd) if rd else None
                    data = int(data, 16) if data else None
                    mem_addr = int(mem_addr, 16) if mem_addr else None
                    mem_data = int(mem_data, 16) if mem_data else None
                    # Create a TraceEntry and add it to the queue
                    self.trace_queue.append(TraceEntry(pc, rd, data, mem_addr, mem_data))

    def get_trace(self):
        return list(self.trace_queue)


