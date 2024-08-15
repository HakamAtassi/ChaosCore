# Create a project
#create_project ChaosCore ./ -part xczu3eg-sbva484-1-i -force

# build settings
#set design_name "ChaosCore"
set top_module "SOC"
set board_file "???"
set board_name "ultra96v2"
set fpga_part "xczu3eg-sbva484-1-i"

# set reference directories for source files
set lib_dir [file normalize "./../hw/verilog"]
set constraints_dir [file normalize "./constraints"]
set bdf_dir [file normalize "./bdf"]
#set origin_dir [file normalize "./../../"]

# Add RTL source files from filelist.f
set fp [open "$lib_dir/filelist.f" r]
   while {[gets $fp line] >= 0} {
   read_verilog -sv "${lib_dir}/$line" 
}

# Add RTL source files from firrtl_back_box_resource_files.f
set fp [open "$lib_dir/firrtl_black_box_resource_files.f" r]
   while {[gets $fp line] >= 0} {
   read_verilog -sv "${lib_dir}/$line" 
}

# read constraints
read_xdc "${constraints_dir}/constraints.xdc" -mode out_of_context

# synth
synth_design -top "$top_module" -part ${fpga_part} 

# Generate synthesis report
report_utilization -file utilization_synth.rpt -hierarchical -hierarchical_depth 10 -hierarchical_percentage

report_timing_summary -file timing_synth.rpt

# place and route
opt_design
place_design
route_design

# write bitstream
#write_bitstream -force "${origin_dir}/${arch}/${design_name}.bit"
