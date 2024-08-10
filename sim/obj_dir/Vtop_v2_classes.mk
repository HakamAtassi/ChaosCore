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
	Vtop_v2___024root__DepSet_h256ab6bb__0 \
	Vtop_v2___024root__DepSet_h256ab6bb__1 \
	Vtop_v2___024root__DepSet_h256ab6bb__2 \
	Vtop_v2___024root__DepSet_h44b351b9__0 \
	Vtop_v2___024root__DepSet_h44b351b9__1 \
	Vtop_v2___024root__DepSet_h44b351b9__2 \
	Vtop_v2___024root__DepSet_h44b351b9__3 \
	Vtop_v2_icache_ReadWriteSmem__DepSet_hc83b056a__0 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h7619f015__0 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h7619f015__1 \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h7619f015__2 \
	Vtop_v2_Queue4_FU_output__DepSet_hd12afb5a__0 \
	Vtop_v2_Queue2_FTQ_entry__DepSet_ha0635c93__0 \
	Vtop_v2__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtop_v2__ConstPool_0 \
	Vtop_v2___024root__Slow \
	Vtop_v2___024root__DepSet_h256ab6bb__0__Slow \
	Vtop_v2___024root__DepSet_h44b351b9__0__Slow \
	Vtop_v2___024root__DepSet_h44b351b9__1__Slow \
	Vtop_v2_icache_ReadWriteSmem__Slow \
	Vtop_v2_icache_ReadWriteSmem__DepSet_hb1619dea__0__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h0a112d22__0__Slow \
	Vtop_v2_Queue2_decoded_fetch_packet__DepSet_h7619f015__0__Slow \
	Vtop_v2_Queue4_FU_output__Slow \
	Vtop_v2_Queue4_FU_output__DepSet_hd360e25c__0__Slow \
	Vtop_v2_Queue4_FU_output__DepSet_hd12afb5a__0__Slow \
	Vtop_v2_Queue2_FTQ_entry__Slow \
	Vtop_v2_Queue2_FTQ_entry__DepSet_hf07b0150__0__Slow \
	Vtop_v2_Queue2_FTQ_entry__DepSet_ha0635c93__0__Slow \

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
