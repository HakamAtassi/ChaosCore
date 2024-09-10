if {[file exists work]} {
	vdel -lib work -all
}

# Create a simulation library
vlib work

vlog ../../hw/verilog/*.sv
vlog src/*.sv

vlog +incdir+src+.

view wave

# Run the simulation
vsim -work work -stats=none -voptargs="+acc" top +UVM_TESTNAME=cache_base_test
#vsim -voptargs=+acc work.counter_tb

# Run the simulation
run -all
