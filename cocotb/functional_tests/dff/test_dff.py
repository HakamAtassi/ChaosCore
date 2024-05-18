from cocotb_test.simulator import run
def test_dff():
    run(
        simulator="verilator",
        verilog_sources=["../../../hw/verilog/dff.v"], # sources
        toplevel="dff",            # top level HDL
        module="dff_cocotb",        # name of cocotb test module
        compile_args=["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND"]
    )