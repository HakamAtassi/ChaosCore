# This Makefile enables lightweight debugging of `svsim` tests. 
# To rebuild the simulation run `make simulation` in this directory.
# To replay the simulation run `make replay` in this directory.
# Changes to `generated-sources` and `primary-sources` will be picked up when running `make replay` and `make simulation`. This is useful for debugging issues. You can also freely add, remove or change any of the arguments to the backend or simulation in the targets below.

.PHONY: clean simulation replay

clean:
	ls . | grep -v Makefile | grep -v execution-script.txt | xargs rm -rf

simulation: clean
	$(compilerEnvironment) \
	/usr/local/bin/verilator \
		'--cc' \
		'--exe' \
		'--build' \
		'-j' \
		'0' \
		'-o' \
		'../simulation' \
		'--top-module' \
		'svsimTestbench' \
		'--Mdir' \
		'verilated-sources' \
		'--assert' \
		'--timescale' \
		'1ms/1ms' \
		'--trace' \
		'-O1' \
		'-MAKEFLAGS' \
		'-j 4' \
		'-CFLAGS' \
		'-O1 -std=c++14 -I$(shell pwd) -DSVSIM_ENABLE_VERILATOR_SUPPORT -DSVSIM_VERILATOR_TRACE_ENABLED' \
		'+define+SVSIM_ENABLE_VCD_TRACING_SUPPORT' \
		$(sourcefiles)

replay: simulation
	cat $(shell pwd)/execution-script.txt | { grep '^#' || true; } && \
	cat $(shell pwd)/execution-script.txt | sed -n 's/^[0-9]*> \(.*\)/\1/p' | \
		$(simulationEnvironment) $(shell pwd)/simulation \

sourcefiles = \
	'../primary-sources/free_list.sv' \
	'../generated-sources/simulation-driver.cpp' \
	'../generated-sources/testbench.sv' \
	'../generated-sources/c-dpi-bridge.cpp'

compilerEnvironment = \

simulationEnvironment = \
	SVSIM_SIMULATION_LOG=$(shell pwd)/simulation-log.txt \
	SVSIM_SIMULATION_TRACE=$(shell pwd)/trace

