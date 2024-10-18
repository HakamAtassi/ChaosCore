if {[file exists work]} {
	vdel -lib work -all
}

# Create a simulation library
vlib work

vlog ../../hw/verilog/*.sv
vlog ../../hw/chisel/src/main/resources/verilog-axi/rtl/axi_ram_rdelay.v
vlog src/*.sv

view wave

# Run the simulation
vsim -work work -stats=none -voptargs="+acc" top +UVM_TESTNAME=cache_base_test +UVM_NO_RELNOTES +UVM_VERBOSITY=UVM_LOW  
#+UVM_CONFIG_DB_TRACE
#vsim -voptargs=+acc work.counter_tb

add wave -r /top/DUT/dut/instruction_cache/reset
add wave -r /top/DUT/dut/instruction_cache/cache_state
add wave -r /top/DUT/dut/instruction_cache/cache_valid
add wave -r /top/DUT/dut/instruction_cache/replay_valid
add wave -r /top/DUT/dut/instruction_cache/miss*
add wave -r /top/DUT/dut/instruction_cache/hit*
add wave -r /top/DUT/dut/instruction_cache/axi_response
add wave -r /top/DUT/dut/instruction_cache/axi_response_valid
#add wave -r /top/DUT/dut/instruction_cache/request_addr
#add wave -r /top/DUT/dut/instruction_cache/AXI_AR_buf_araddr
add wave -r /top/DUT/dut/instruction_cache/replay_address_addr
add wave -r /top/cache_if/added_delay
add wave -r /top/DUT/dut/added_delay
add wave -r /top/DUT/dut/axi_ram/s_axi_araddr
add wave -r /top/DUT/dut/axi_ram/s_axi_araddr_valid
add wave -r /top/DUT/dut/axi_ram/read_state_reg
add wave -r /top/DUT/dut/axi_ram/cycles2stall
add wave -r /top/DUT/dut/axi_ram/cycles_stalled
add wave -r /top/DUT/dut/instruction_cache/allocate_way
add wave -r /top/DUT/dut/instruction_cache/valid_oh
add wave -r /top/DUT/dut/instruction_cache/REG_0
add wave -r /top/DUT/dut/instruction_cache/REG_1
add wave -r /top/DUT/dut/instruction_cache/current_packet_set
add wave -r /top/DUT/dut/instruction_cache/current_packet_tag
#add wave -r /top/DUT/dut/instruction_cache/LRU_memory/*
#add wave -r /top/DUT/dut/instruction_cache/valid_mem_16_0
#add wave -r /top/DUT/dut/instruction_cache/valid_mem_16_1
#add wave -r /top/DUT/dut/instruction_cache/_data_memory_*
#add wave -r /top/DUT/dut/instruction_cache/data_memory_0/*
#add wave -r /top/DUT/dut/instruction_cache/data_memory_1/*
add wave -r /top/DUT/dut/instruction_cache/io_flush*
#add wave -r /top/DUT/dut/instruction_cache/CPU_response_skid_buffer/*
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_instructions_0_instruction
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_instructions_1_instruction
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_instructions_2_instruction
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_instructions_3_instruction
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_fetch_PC
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_bits_valid_bits_*
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_request_bits_addr
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_response_valid
#add wave -r /top/DUT/dut/instruction_cache/io_CPU_request_ready
add wave -r /top/DUT/dut/instruction_cache/current_set_decomposed_icache_address_set
add wave -r /top/DUT/dut/instruction_cache/io_CPU_request*
add wave -r /top/DUT/dut/instruction_cache/io_CPU_response*
#add wave -r /top/DUT/dut/instruction_cache/validator/*
#add wave -r /top/DUT/dut/instruction_cache/*
#add wave -r /top/DUT/dut/axi_ram/mem
# Run the simulation
run -all
