# Create a project
create_project ChaosCore ../hw/verilog/ -part xczu3eg-sbva484-1-i

# Add RTL source files from filelist.f
file read_lines ../hw/verilog/filelist.f > my_filelist
foreach file $my_filelist {
    add_files $file
}

# Set the top module
set_property top ChaosCore [current_fileset]

# Add constraints
create_clock -period 6.667 [get_ports clock]

# Run synthesis
launch_runs synth_1 -jobs 4

# Wait for synthesis to complete
wait_on_run synth_1

# Generate synthesis report
report_utilization -file utilization_synth.rpt
report_timing_summary -file timing_synth.rpt

# Open synthesized design
open_run synth_1 -name synth_1

# Save project
save_project_as ChaosCore_syn
