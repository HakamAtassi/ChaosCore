if {[file exists work]} {
	vdel -lib work -all
}

# Create a simulation library
vlib work

vlog ../../hw/verilog/*.sv
vlog ../../hw/chisel/src/main/resources/verilog-axi/rtl/axi_ram.v
vlog src/*.sv

view wave

# Run the simulation
vsim -work work -stats=none -voptargs="+acc" top +UVM_TESTNAME=cache_base_test +UVM_NO_RELNOTES +UVM_VERBOSITY=UVM_LOW
#vsim -voptargs=+acc work.counter_tb

add wave -r /top/DUT/dut/instruction_cache/cache_state
add wave -r /top/DUT/dut/instruction_cache/cache_valid
add wave -r /top/DUT/dut/instruction_cache/replay_valid
add wave -r /top/DUT/dut/instruction_cache/miss*
add wave -r /top/DUT/dut/instruction_cache/hit*
add wave -r /top/DUT/dut/instruction_cache/axi_response
add wave -r /top/DUT/dut/instruction_cache/axi_response_valid
add wave -r /top/DUT/dut/instruction_cache/allocate_way
add wave -r /top/DUT/dut/instruction_cache/current_packet_set
#add wave -r /top/DUT/dut/instruction_cache/LRU_memory/*
add wave -r /top/DUT/dut/instruction_cache/valid_mem_0_0
add wave -r /top/DUT/dut/instruction_cache/valid_mem_0_1
#add wave -r /top/DUT/dut/instruction_cache/_data_memory_*
#add wave -r /top/DUT/dut/instruction_cache/data_memory_0/*
#add wave -r /top/DUT/dut/instruction_cache/data_memory_1/*
#add wave -r /top/DUT/dut/instruction_cache/io_flush*
add wave -r /top/DUT/dut/instruction_cache/CPU_response_skid_buffer/*
add wave -r /top/DUT/dut/instruction_cache/io_CPU_response*
add wave -r /top/DUT/dut/instruction_cache/io_CPU_request*
add wave -r /top/DUT/dut/instruction_cache/validator/*
#add wave -r /top/DUT/dut/instruction_cache/*
# Run the simulation
run -all
