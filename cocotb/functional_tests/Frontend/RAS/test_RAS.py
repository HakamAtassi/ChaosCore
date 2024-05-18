from cocotb_test.simulator import run
def test_RAS():
    run(
        verilog_sources=["../../../../hw/verilog/RAS.v"], # sources
        toplevel="RAS",            # top level HDL
        module="RAS_tests"        # name of cocotb test module
    )