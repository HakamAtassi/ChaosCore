verilator -binary --trace axi_master_slave_tb.sv -I/home/hakam/Repos/ChaosCore/hw/verilog/ -Wno-CASEINCOMPLETE -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD -Wno-UNSIGNED -j 15

./obj_dir/Vaxi_master_slave_tb