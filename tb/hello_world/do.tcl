#set UVM_HOME /CMC/tools/siemens/questasim_2022.1_2/questasim/uvm-1.1d
#set UVM_SRC /CMC/tools/siemens/questasim_2022.1_2/questasim/verilog_src/uvm-1.1d/src
# Set Questa Home directory
set QUESTA_HOME /CMC/tools/siemens/questasim_2022.1_2/questasim

if {[file exists work]} {
	vdel -lib work -all
}

# Create a simulation library
vlib work

# Compile the design and testbench
#vlog +incdir+$UVM_SRC/ $UVM_SRC/uvm_pkg.sv $UVM_SRC/dpi/uvm_dpi.cc $UVM_SRC/uvm_macros.svh


#vlog +incdir+$UVM_SRC/ *.sv
vlog *.sv *.v

view wave

# Run the simulation
vsim -voptargs=+acc work.counter_tb

# Add signals to the waveform
#add wave -r /*
add wave /counter_tb/uut/clk

# Run the simulation
run -all
