# Create a project
create_project ChaosCore ./ -part xczu3eg-sbva484-1-i -force


# Add RTL source files from filelist.f
set fp [open "../hw/verilog/filelist.f" r]
   while {[gets $fp line] >= 0} {
   add_files -fileset constrs_1 -norecurse "../hw/verilog/$line"
}

# Add RTL source files from firrtl_back_box_resource_files.f
# TODO:

# Set the top module
set_property top ChaosCore [current_fileset]

# Add constraints
create_clock -period 5 [get_ports clock]

# Run synthesis
launch_runs synth_1 -jobs 8

# Wait for synthesis to complete
wait_on_run synth_1

# Generate synthesis report
report_utilization -file utilization_synth.rpt
report_timing_summary -file timing_synth.rpt

# Open synthesized design
open_run synth_1 -name synth_1

# Save project
save_project_as ChaosCore_syn
