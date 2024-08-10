# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtop_v2.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vtop_v2 \
	Vtop_v2___024root__DepSet_h834aa20a__0 \
	Vtop_v2___024root__DepSet_h834aa20a__1 \
	Vtop_v2___024root__DepSet_h834aa20a__2 \
	Vtop_v2___024root__DepSet_h08f308fc__0 \
	Vtop_v2___024root__DepSet_h08f308fc__1 \
	Vtop_v2___024root__DepSet_h08f308fc__2 \
	Vtop_v2___024root__DepSet_h08f308fc__3 \
	Vtop_v2_icache_ReadWriteSmem__DepSet_h4d9db979__0 \
	Vtop_v2_Queue4_FU_output__DepSet_h8932bb51__0 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_hc00c30c9__0 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_hc00c30c9__1 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_hc00c30c9__2 \
	Vtop_v2_Queue2_FTQ_entry__DepSet_hc7107494__0 \
	Vtop_v2__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtop_v2__ConstPool_0 \
	Vtop_v2___024root__Slow \
	Vtop_v2___024root__DepSet_h834aa20a__0__Slow \
	Vtop_v2___024root__DepSet_h08f308fc__0__Slow \
	Vtop_v2___024root__DepSet_h08f308fc__1__Slow \
	Vtop_v2_icache_ReadWriteSmem__Slow \
	Vtop_v2_icache_ReadWriteSmem__DepSet_hc7a1fdcb__0__Slow \
	Vtop_v2_Queue4_FU_output__Slow \
	Vtop_v2_Queue4_FU_output__DepSet_h97378434__0__Slow \
	Vtop_v2_Queue4_FU_output__DepSet_h8932bb51__0__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h49326dc1__0__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_hc00c30c9__0__Slow \
	Vtop_v2_Queue2_FTQ_entry__Slow \
	Vtop_v2_Queue2_FTQ_entry__DepSet_h026a25da__0__Slow \
	Vtop_v2_Queue2_FTQ_entry__DepSet_hc7107494__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vtop_v2__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vtop_v2__Syms \
	Vtop_v2__Trace__0__Slow \
	Vtop_v2__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
