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
vsim -work work -stats=none -voptargs="+acc" top +UVM_TESTNAME=cache_base_test +UVM_NO_RELNOTES +UVM_VERBOSITY=UVM_HIGH
#vsim -voptargs=+acc work.counter_tb

# Run the simulation
run -all
