
from read_trace import *

# Example usage
spike_trace = readTrace('/home/hakam/Repos/ChaosCore/binaries/spike_traces/bubble_sort.log')
dut_trace = readTrace('/home/hakam/Repos/ChaosCore/cocotb/tests/SOC/ChaosCore_traces/bubble_sort.log')

spike_trace.parse_log()
dut_trace.parse_log()


spike_trace_list = spike_trace.get_trace()
dut_trace_list = dut_trace.get_trace()


dut_trace_list.pop(0)
spike_trace_list.pop(0)


for instruction in range(len(spike_trace_list)):
    spike_instruction = spike_trace_list[0]
    dut_instruction = dut_trace_list[0]

    if(spike_instruction.mem_addr == None):
        print(f"{spike_instruction}     |       {dut_instruction}")
        if(dut_instruction.rd != 0):
            assert spike_instruction.data == dut_instruction.data, f"{instruction} {spike_instruction.data} =/= {dut_instruction.data}"


    dut_trace_list.pop(0)
    spike_trace_list.pop(0)

