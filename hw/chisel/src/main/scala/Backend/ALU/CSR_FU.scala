/* ------------------------------------------------------------------------------------
* Filename: CSR.scala
* Author: Hakam Atassi
* Date: Sep 15 2024
* Description: The core CSRs
* License: MIT
*
* Copyright (c) 2024 by Hakam Atassi
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* ------------------------------------------------------------------------------------ 
*/

package ChaosCore

import chisel3._
import circt.stage.ChiselStage 

import chisel3.util._


// This module is heavily inspired by Rocketchip's CSR file


//The top two bits (csr[11:10])
//indicate whether the register is read/write (00,01, or 10) or read-only (11). The next two bits (csr[9:8])
//encode the lowest privilege level that can access the CSR.

/*
* Table 1. RISC-V Privilege Levels:
* 
* | Level | Encoding | Name              | Abbreviation |
* |-------|----------|-------------------|--------------|
* | 0     | 00       | User/Application   | U            |
* | 1     | 01       | Supervisor         | S            |
* | 2     | 10       | Reserved           |              |
* | 3     | 11       | Machine            | M            |
*
*/



/* 
 * Table 4. Currently allocated RISC-V unprivileged CSR addresses.
 * -------------------------------------------------------------
 * Number    Privilege    Name            Description
 * -------------------------------------------------------------
 * Unprivileged Floating-Point CSRs
 * 0x001     URW          fflags          Floating-Point Accrued Exceptions.
 * 0x002     URW          frm             Floating-Point Dynamic Rounding Mode.
 * 0x003     URW          fcsr            Floating-Point Control and Status Register (frm + fflags).
 * 
 * Unprivileged Counter/Timers
 * 0xC00     URO          cycle           Cycle counter for RDCYCLE instruction.
 * 0xC01     URO          time            Timer for RDTIME instruction.
 * 0xC02     URO          instret         Instructions-retired counter for RDINSTRET instruction.
 * 0xC03     URO          hpmcounter3     Performance-monitoring counter.
 * 0xC04     URO          hpmcounter4     Performance-monitoring counter.
 * ...       URO          ...             ...
 * 0xC1F     URO          hpmcounter31    Performance-monitoring counter.
 * 0xC80     URO          cycleh          Upper 32 bits of cycle, RV32 only.
 * 0xC81     URO          timeh           Upper 32 bits of time, RV32 only.
 * 0xC82     URO          instreth        Upper 32 bits of instret, RV32 only.
 * 0xC83     URO          hpmcounter3h    Upper 32 bits of hpmcounter3, RV32 only.
 * 0xC84     URO          hpmcounter4h    Upper 32 bits of hpmcounter4, RV32 only.
 * ...       URO          ...             ...
 * 0xC9F     URO          hpmcounter31h   Upper 32 bits of hpmcounter31, RV32 only.
*/

/* 
 * Table 7. Currently allocated RISC-V machine-level CSR addresses.
 * -------------------------------------------------------------
 * Number    Privilege    Name            Description
 * -------------------------------------------------------------
 * Machine Information Registers
 * 0xF11     MRO          mvendorid       Vendor ID.
 * 0xF12     MRO          marchid         Architecture ID.
 * 0xF13     MRO          mimpid          Implementation ID.
 * 0xF14     MRO          mhartid         Hardware thread ID.
 * 0xF15     MRO          mconfigptr      Pointer to configuration data structure.
 * 
 * Machine Trap Setup
 * 0x300     MRW          mstatus         Machine status register.
 * 0x301     MRW          misa            ISA and extensions.
 * 0x302     MRW          medeleg         Machine exception delegation register.
 * 0x303     MRW          mideleg         Machine interrupt delegation register.
 * 0x304     MRW          mie             Machine interrupt-enable register.
 * 0x305     MRW          mtvec           Machine trap-handler base address.
 * 0x306     MRW          mcounteren      Machine counter enable.
 * 0x310     MRW          mstatush        Additional machine status register, RV32 only.
 * 0x312     MRW          medelegh        Upper 32 bits of medeleg, RV32 only.
 * 
 * Machine Trap Handling
 * 0x340     MRW          mscratch        Scratch register for machine trap handlers.
 * 0x341     MRW          mepc            Machine exception program counter.
 * 0x342     MRW          mcause          Machine trap cause.
 * 0x343     MRW          mtval           Machine bad address or instruction.
 * 0x344     MRW          mip             Machine interrupt pending.
 * 0x34A     MRW          mtinst          Machine trap instruction (transformed).
 * 0x34B     MRW          mtval2          Machine bad guest physical address.
 * 
 * Machine Configuration (not implemented)
 * 0x30A     MRW          menvcfg         Machine environment configuration register.
 * 0x31A     MRW          menvcfgh        Upper 32 bits of menvcfg, RV32 only.
 * 0x747     MRW          mseccfg         Machine security configuration register.
 * 0x757     MRW          mseccfgh        Upper 32 bits of mseccfg, RV32 only.
 * 
 * Machine Memory Protection(not implemented #TODO)
 * 0x3A0     MRW          pmpcfg0         Physical memory protection configuration.
 * 0x3A1     MRW          pmpcfg1         Physical memory protection configuration, RV32 only.
 * 0x3A2     MRW          pmpcfg2         Physical memory protection configuration.
 * 0x3A3     MRW          pmpcfg3         Physical memory protection configuration, RV32 only.
 * ...       MRW          ...             ...
 * 0x3AE     MRW          pmpcfg14        Physical memory protection configuration.
 * 0x3AF     MRW          pmpcfg15        Physical memory protection configuration, RV32 only.
 * 0x3B0     MRW          pmpaddr0        Physical memory protection address register.
 * 0x3B1     MRW          pmpaddr1        Physical memory protection address register.
 * ...       MRW          ...             ...
 * 0x3EF     MRW          pmpaddr63       Physical memory protection address register.
 * 
 * Machine State Enable Registers (not implemented)
 * 0x30C     MRW          mstateen0       Machine State Enable 0 Register.
 * 0x30D     MRW          mstateen1       Machine State Enable 1 Register.
 * 0x30E     MRW          mstateen2       Machine State Enable 2 Register.
 * 0x30F     MRW          mstateen3       Machine State Enable 3 Register.
 * 0x31C     MRW          mstateen0h      Upper 32 bits of Machine State Enable 0 Register, RV32 only.
 * 0x31D     MRW          mstateen1h      Upper 32 bits of Machine State Enable 1 Register, RV32 only.
 * 0x31E     MRW          mstateen2h      Upper 32 bits of Machine State Enable 2 Register, RV32 only.
 * 0x31F     MRW          mstateen3h      Upper 32 bits of Machine State Enable 3 Register, RV32 only.
*/

/* 
 * Table 8. Additional Machine-Level CSR Addresses for NMI and Counters.
 * -------------------------------------------------------------
 * Number    Privilege    Name            Description
 * -------------------------------------------------------------
 * Machine Non-Maskable Interrupt Handling
 * 0x740     MRW          mnscratch       Resumable NMI scratch register.
 * 0x741     MRW          mnepc           Resumable NMI program counter.
 * 0x742     MRW          mncause         Resumable NMI cause.
 * 0x744     MRW          mnstatus        Resumable NMI status.
 * 
 * Machine Counter/Timers
 * 0xB00     MRW          mcycle          Machine cycle counter.
 * 0xB02     MRW          minstret        Machine instructions-retired counter.
 * 0xB03     MRW          mhpmcounter3    Machine performance-monitoring counter.
 * 0xB04     MRW          mhpmcounter4    Machine performance-monitoring counter.
 * ...       MRW          ...             ...
 * 0xB1F     MRW          mhpmcounter31   Machine performance-monitoring counter.
 * 0xB80     MRW          mcycleh         Upper 32 bits of mcycle, RV32 only.
 * 0xB82     MRW          minstreth       Upper 32 bits of minstret, RV32 only.
 * 0xB83     MRW          mhpmcounter3h   Upper 32 bits of mhpmcounter3, RV32 only.
 * 0xB84     MRW          mhpmcounter4h   Upper 32 bits of mhpmcounter4, RV32 only.
 * ...       MRW          ...             ...
 * 0xB9F     MRW          mhpmcounter31h  Upper 32 bits of mhpmcounter31, RV32 only.
 * 
 * Machine Counter Setup (not implemented)
 * 0x320     MRW          mcountinhibit   Machine counter-inhibit register.
 * 0x323     MRW          mhpmevent3      Machine performance-monitoring event selector.
 * 0x324     MRW          mhpmevent4      Machine performance-monitoring event selector.
 * ...       MRW          ...             ...
 * 0x33F     MRW          mhpmevent31     Machine performance-monitoring event selector.
 * 0x723     MRW          mhpmevent3h     Upper 32 bits of mhpmevent3, RV32 only.
 * 0x724     MRW          mhpmevent4h     Upper 32 bits of mhpmevent4, RV32 only.
 * ...       MRW          ...             ...
 * 0x73F     MRW          mhpmevent31h    Upper 32 bits of mhpmevent31, RV32 only.
 * 
 * Debug/Trace Registers (not implemented)
 * 0x7A0     MRW          tselect         Debug/Trace trigger register select.
 * 0x7A1     MRW          tdata1          First Debug/Trace trigger data register.
 * 0x7A2     MRW          tdata2          Second Debug/Trace trigger data register.
 * 0x7A3     MRW          tdata3          Third Debug/Trace trigger data register.
 * 0x7A8     MRW          mcontext        Machine-mode context register.
 * 
 * Debug Mode Registers (not implemented)
 * 0x7B0     DRW          dcsr            Debug control and status register.
 * 0x7B1     DRW          dpc             Debug program counter.
 * 0x7B2     DRW          dscratch0       Debug scratch register 0.
 * 0x7B3     DRW          dscratch1       Debug scratch register 1.
*/


/* 
 * Table 5. Currently allocated RISC-V supervisor-level CSR addresses.
 * -------------------------------------------------------------
 * Number    Privilege    Name            Description
 * -------------------------------------------------------------
 * Supervisor Trap Setup
 * 0x100     SRW          sstatus         Supervisor status register.
 * 0x104     SRW          sie             Supervisor interrupt-enable register.
 * 0x105     SRW          stvec           Supervisor trap handler base address.
 * 0x106     SRW          scounteren      Supervisor counter enable.
 * 
 * Supervisor Configuration
 * 0x10A     SRW          senvcfg         Supervisor environment configuration register.
 * 
 * Supervisor Counter Setup
 * 0x120     SRW          scountinhibit   Supervisor counter-inhibit register.
 * 
 * Supervisor Trap Handling
 * 0x140     SRW          sscratch        Scratch register for supervisor trap handlers.
 * 0x141     SRW          sepc            Supervisor exception program counter.
 * 0x142     SRW          scause          Supervisor trap cause.
 * 0x143     SRW          stval           Supervisor bad address or instruction.
 * 0x144     SRW          sip             Supervisor interrupt pending.
 * 0xDA0     SRO          scountovf       Supervisor count overflow.
 * 
 * Supervisor Protection and Translation
 * 0x180     SRW          satp            Supervisor address translation and protection.
 * 
 * Debug/Trace Registers
 * 0x5A8     SRW          scontext        Supervisor-mode context register.
 * 
 * Supervisor State Enable Registers
 * 0x10C     SRW          sstateen0       Supervisor State Enable 0 Register.
 * 0x10D     SRW          sstateen1       Supervisor State Enable 1 Register.
 * 0x10E     SRW          sstateen2       Supervisor State Enable 2 Register.
 * 0x10F     SRW          sstateen3       Supervisor State Enable 3 Register.
*/

/* 
 * Table 6. Currently allocated RISC-V hypervisor and VS CSR addresses.
 * -------------------------------------------------------------
 * Number    Privilege    Name            Description
 * -------------------------------------------------------------
 * Hypervisor Trap Setup
 * 0x600     HRW          hstatus         Hypervisor status register.
 * 0x602     HRW          hedeleg         Hypervisor exception delegation register.
 * 0x603     HRW          hideleg         Hypervisor interrupt delegation register.
 * 0x604     HRW          hie             Hypervisor interrupt-enable register.
 * 0x606     HRW          hcounteren      Hypervisor counter enable.
 * 0x607     HRW          hgeie           Hypervisor guest external interrupt-enable register.
 * 0x612     HRW          hedelegh        Upper 32 bits of hedeleg, RV32 only.
 * 
 * Hypervisor Trap Handling
 * 0x643     HRW          htval           Hypervisor bad guest physical address.
 * 0x644     HRW          hip             Hypervisor interrupt pending.
 * 0x645     HRW          hvip            Hypervisor virtual interrupt pending.
 * 0x64A     HRW          htinst          Hypervisor trap instruction (transformed).
 * 0xE12     HRO          hgeip           Hypervisor guest external interrupt pending.
 * 
 * Hypervisor Configuration
 * 0x60A     HRW          henvcfg         Hypervisor environment configuration register.
 * 0x61A     HRM          henvcfgh        Upper 32 bits of henvcfg, RV32 only.
 * 
 * Hypervisor Protection and Translation
 * 0x680     HRW          hgatp           Hypervisor guest address translation and protection.
 * 
 * Debug/Trace Registers
 * 0x6A8     HRW          hcontext        Hypervisor-mode context register.
 * 
 * Hypervisor Counter/Timer Virtualization Registers
 * 0x605     HRW          htimedelta      Delta for VS/VU-mode timer.
 * 0x615     HRW          htimedeltah     Upper 32 bits of htimedelta, RV32 only.
 * 
 * Hypervisor State Enable Registers
 * 0x60C     HRW          hstateen0       Hypervisor State Enable 0 Register.
 * 0x60D     HRW          hstateen1       Hypervisor State Enable 1 Register.
 * 0x60E     HRW          hstateen2       Hypervisor State Enable 2 Register.
 * 0x60F     HRW          hstateen3       Hypervisor State Enable 3 Register.
 * 0x61C     HRW          hstateen0h      Upper 32 bits of Hypervisor State Enable 0 Register, RV32 only.
 * 0x61D     HRW          hstateen1h      Upper 32 bits of Hypervisor State Enable 1 Register, RV32 only.
 * 0x61E     HRW          hstateen2h      Upper 32 bits of Hypervisor State Enable 2 Register, RV32 only.
 * 0x61F     HRW          hstateen3h      Upper 32 bits of Hypervisor State Enable 3 Register, RV32 only.
 * 
 * Virtual Supervisor Registers
 * 0x200     HRW          vsstatus        Virtual supervisor status register.
 * 0x204     HRW          vsie            Virtual supervisor interrupt-enable register.
 * 0x205     HRW          vstvec          Virtual supervisor trap handler base address.
 * 0x240     HRW          vsscratch       Virtual supervisor scratch register.
 * 0x241     HRW          vsepc           Virtual supervisor exception program counter.
 * 0x242     HRW          vscause         Virtual supervisor trap cause.
 * 0x243     HRW          vstval          Virtual supervisor bad address or instruction.
 * 0x244     HRW          vsip            Virtual supervisor interrupt pending.
 * 0x280     HRW          vsatp           Virtual supervisor address translation and protection.
*/

/*
class mstatus(coreParameters:CoreParameters) extends Bundle{

    val SD      = UInt(1.W)
    val WPRI0   = UInt(8.W)
    val TSR     = UInt(1.W)
    val TW      = UInt(1.W)
    val TVM     = UInt(1.W)
    val MXR     = UInt(1.W)
    val SUM     = UInt(1.W)
    val MPRV    = UInt(1.W)
    val XS      = UInt(2.W)
    val FS      = UInt(2.W)
    val MPP     = UInt(2.W)
    val VS      = UInt(2.W)
    val SPP     = UInt(1.W)
    val MPIE    = UInt(1.W)
    val UBE     = UInt(1.W)
    val SPIE    = UInt(1.W)
    val WPRI1   = UInt(1.W)
    val MIE     = UInt(1.W)
    val WPRI2   = UInt(1.W)
    val SIE     = UInt(1.W)
    val WPRI3   = UInt(1.W)

    def read:UInt = {
        SD ## WPRI0 ## ...
    }
}

class MTVEC(coreParameters:CoreParameters) extends Bundle{

    val BASE      = UInt((32-1-2).W)
    val MODE      = UInt((2).W)

    def read:UInt = {
        BASE ## MODE
    }
}
*/



class CSR_FU(coreParameters:CoreParameters) extends GALU(coreParameters){

    import coreParameters._

    val CSR_port = IO(Output(new CSR_out))


    ////////////////////////
    // DECODE CSR REQUEST //
    ////////////////////////

    val is_CSR    =  io.FU_input.bits.decoded_instruction.needs_CSRs

    val RS1       =  io.FU_input.bits.decoded_instruction.RS1

    val is_CSRRW  =  is_CSR && FUNCT3 === 0x1.U
    val is_CSRRS  =  is_CSR && FUNCT3 === 0x2.U
    val is_CSRRC  =  is_CSR && FUNCT3 === 0x3.U

    val is_CSRRWI =  is_CSR && FUNCT3 === 0x5.U
    val is_CSRRSI =  is_CSR && FUNCT3 === 0x6.U
    val is_CSRRCI =  is_CSR && FUNCT3 === 0x7.U

    val PRIVILAGE_OK = 1.B //FIXME:  // input privilage is lower or equal to active privilage


    val input_CSR_address      = io.FU_input.bits.decoded_instruction.IMM      // address of requested CSR
    val input_CSR_privilage    = get_CSR_lowest_priv(input_CSR_address)
    val input_CSR_access       = get_CSR_access(input_CSR_address)      // What is the minimum required privilage required for the requested CSR? (this is encoded in the address)


    val input_CSR_read_request       = !(io.FU_input.bits.decoded_instruction.PRD === 0.U)  // when PRD == x0, the read is discarded, so dont read at all.
    val input_CSR_write_request      = (is_CSRRW || is_CSRRWI) || (is_CSR && RS1 =/= 0.U)
    

    val active_CSR_privilage   = 0.U      // what was the privilage level of the core during request? 

    dontTouch(input_CSR_read_request)
    dontTouch(input_CSR_write_request)

    ////////////////////
    // USER MODE CSRs //
    ////////////////////


    //-----------------------
    // PERFORMANCE COUNTERS 
    //-----------------------

    val cycle_reg     = RegInit(UInt(32.W), 0.U)
    val time_reg      = RegInit(UInt(32.W), 0.U)
    val instret_reg   = RegInit(UInt(32.W), 0.U)

    val cycleh_reg    = RegInit(UInt(32.W), 0.U)
    val timeh_reg     = RegInit(UInt(32.W), 0.U)
    val instreth_reg  = RegInit(UInt(32.W), 0.U)



    // PERFORMANCE COUNTER UPDATES

    val (new_cycleh_reg, new_cycle_reg) = increment_perf_counter(cycleh_reg, cycle_reg, 1.U)
    cycleh_reg := new_cycleh_reg
    cycle_reg := new_cycle_reg


    when(io.commit.valid){
        val (new_instret_reg, new_instreth_reg) = increment_perf_counter(instreth_reg, instret_reg, PopCount(io.partial_commit.valid))
        instret_reg := new_instret_reg
        instreth_reg := new_instreth_reg
    }

    // SUPERVISOR //
    // N/A
    // HYPERVISOR //
    // N/A

    //---------------------
    // CREATE CSR MAPPING 
    //---------------------

    // MAP of int -> CSR
    val user_mode_CSRs = Map(
        CSRs.cycle      ->  cycle_reg,
        CSRs.time       ->  time_reg,
        CSRs.instret    ->  instret_reg,

        CSRs.cycleh     ->  cycleh_reg,
        CSRs.timeh      ->  timeh_reg,
        CSRs.instreth   ->  instreth_reg, // FIXME: update so that this is AFTER the current commit takes place, if any
    )

    
    ///////////////////////
    // MACHINE MODE CSRs //
    ///////////////////////

    val mvendorid_reg   = RegInit(0.U.asTypeOf(new mvendorid))
    val marchid_reg     = RegInit(0.U.asTypeOf(new marchid))
    val mimpid_reg      = RegInit(UInt(32.W), 0.U)  // (implementation-defined)
    val mhartid_reg     = RegInit(0.U.asTypeOf(new mhartid))
    val mconfigptr_reg  = RegInit(0.U.asTypeOf(new mconfigptr))


    //---------------------
    // MACHINE TRAP SETUP
    //---------------------

    val mstatus_reg     = RegInit(0.U.asTypeOf(new mstatus))
    val misa_reg        = RegInit(0.U.asTypeOf(new misa))
    val medeleg_reg     = RegInit(UInt(32.W), 0.U)  // (not present in RV32I)
    val mideleg_reg     = RegInit(UInt(32.W), 0.U)  // (not present in RV32I)
    val mie_reg         = RegInit(0.U.asTypeOf(new mie))
    val mtvec_reg       = RegInit(0.U.asTypeOf(new mtvec))
    val mcounteren_reg  = RegInit(UInt(32.W), 0.U)
    val mstatush_reg    = RegInit(UInt(32.W), 0.U)  // RV32 only has mstatus; mstatush used in RV64
    val medelegh_reg    = RegInit(UInt(32.W), 0.U)


    //-----------------------
    // MACHINE TRAP HANDLING
    //-----------------------

    val mscratch_reg   = RegInit(0.U.asTypeOf(new mscratch))
    val mepc_reg       = RegInit(0.U.asTypeOf(new mepc))
    val mcause_reg     = RegInit(0.U.asTypeOf(new mcause))
    val mtval_reg      = RegInit(0.U.asTypeOf(new mtval))
    val mip_reg        = RegInit(0.U.asTypeOf(new mip))
    val mtinst_reg     = RegInit(UInt(32.W), 0.U)
    val mtval2_reg     = RegInit(UInt(32.W), 0.U)


    //-----------------------
    // MACHINE NMI HANDLING
    //-----------------------

    val mnscratch_reg   = RegInit(UInt(32.W), 0.U)
    val mnepc_reg       = RegInit(UInt(32.W), 0.U)
    val mncause_reg     = RegInit(UInt(32.W), 0.U)
    val mnstatus_reg    = RegInit(UInt(32.W), 0.U)


    //-----------------------
    // PERFORMANCE COUNTERS 
    //-----------------------

    val mcycle_reg    = RegInit(UInt(32.W), 0.U)
    val minstret_reg  = RegInit(UInt(32.W), 0.U)

    val mcycleh_reg    = RegInit(UInt(32.W), 0.U)
    val minstreth_reg  = RegInit(UInt(32.W), 0.U)


    // PERFORMANCE COUNTER UPDATES
    mcycle_reg   := mcycle_reg   + 1.U
    minstret_reg := minstret_reg + PopCount(io.partial_commit.valid)


    //---------------------
    // CREATE CSR MAPPING 
    //---------------------

    dontTouch(mepc_reg)



    val machine_mode_CSRs = Map(
        CSRs.mvendorid   -> mvendorid_reg,
        CSRs.marchid     -> marchid_reg,           
        CSRs.mimpid      -> mimpid_reg,           
        CSRs.mhartid     -> mhartid_reg,           
        CSRs.mconfigptr  -> mconfigptr_reg,

        //---------------------
        // MACHINE TRAP SETUP
        //---------------------

        CSRs.mstatus      -> mstatus_reg,
        CSRs.misa         -> misa_reg,
        CSRs.medeleg      -> medeleg_reg,
        CSRs.mideleg      -> mideleg_reg,
        CSRs.mie          -> mie_reg,
        CSRs.mtvec        -> mtvec_reg,
        CSRs.mcounteren   -> mcounteren_reg,
        CSRs.mstatush     -> mstatush_reg,
        //CSRs.medelegh     -> medelegh_reg,

        //-----------------------
        // MACHINE TRAP HANDLING
        //-----------------------

        CSRs.mscratch   -> mscratch_reg,
        CSRs.mepc       -> mepc_reg,
        CSRs.mcause     -> mcause_reg,
        CSRs.mtval      -> mtval_reg,
        CSRs.mip        -> mip_reg,
        CSRs.mtinst     -> mtinst_reg,
        CSRs.mtval2     -> mtval2_reg,

        //-----------------------
        // MACHINE NMI HANDLING
        //-----------------------

        CSRs.mnscratch   -> mnscratch_reg,
        CSRs.mnepc       -> mnepc_reg,
        CSRs.mncause     -> mncause_reg,
        CSRs.mnstatus    -> mnstatus_reg,

        //-----------------------
        // PERFORMANCE COUNTERS 
        //-----------------------

        CSRs.mcycle      -> mcycle_reg,
        CSRs.minstret    -> minstret_reg,
        CSRs.minstreth   -> minstret_reg
    )


    //////////////
    // CSR READ //
    //////////////


    val user_mode_CSR_OH            = user_mode_CSRs.map {case (addr, reg) => (addr.U === CSR_addr)}
    val user_mode_CSR_read_resp     = Mux1H(user_mode_CSR_OH.zip(user_mode_CSRs.map(_._2)))



    val machine_mode_CSR_OH         = machine_mode_CSRs.map { case (addr, reg) => (addr.U === CSR_addr) }
    val machine_mode_CSR_read_resp  = Mux1H(machine_mode_CSR_OH.zip(machine_mode_CSRs.map(_._2.asUInt)))

    // this is placeholder until I implemement an actual CSR file
    val CSR_out    = Reg(UInt(32.W))

    when(input_CSR_privilage === PRIVILAGE.MACHINE){
      CSR_out := user_mode_CSR_read_resp
    }.elsewhen(input_CSR_privilage === PRIVILAGE.USER){
      CSR_out := machine_mode_CSR_read_resp
    }

    dontTouch(input_CSR_privilage)
    dontTouch(RS1_data)
    dontTouch(CSR_addr)


    ///////////////
    // CSR WRITE //
    ///////////////

    // check write to machine mode regs
    when(PRIVILAGE.MACHINE >= input_CSR_privilage && PRIVILAGE_OK && input_CSR_write_request) {
        for ((addr, reg) <- machine_mode_CSRs) {    // FIXME: add read only, etc...
            when(addr.U === CSR_addr) {
                // FIXME: add proper write functions (ex, set, clear, etc...)
                reg := RS1_data.asTypeOf(reg.cloneType) // Use cloneType to ensure the type matches
            }
        }
    }






    ///////////////
    // EXCEPTION //
    ///////////////

    // Exceptions: 
    // Write to MEPC
    // Write to MCAUSE
    // Write to MSTATUS

    when(io.flush.bits.is_exception){
        //mepc_reg := io.flush.bits.flushing_PC

        mepc_reg := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
        mcause_reg.CODE := io.flush.bits.exception_cause.asUInt
        //mstatus_reg := ???
    }



    ///////////////////////////
    // RETURN FROM EXCEPTION //
    ///////////////////////////

    // MPP from mstatus
    // MIE from MPIE
    // branch to MEPC


    /////////////////////
    // ASSIGN CSR PORT //
    /////////////////////

    CSR_port.mtvec := mtvec_reg


    ////////////////////
    // BRANCH CONTROL //
    ////////////////////





    // Any instruction can cause an exception. When this happens, jump to vtvec

    // mret/sret & Ecall/Ebreak
    // mret/sret are simply a branch to mepc with a privilige update
    // Ecall/Ebreak trigger exceptions

    // If there is an Ecall instruction, you have to change mstatus, mcause, mepc (and mstatush for 32 bit) registers. 
    // Then jump to the PC in mtvec. And the privilege is changed to M mode( medeleg value might say S mode) 
    // (for exact changes, read the specifications, chapters on mstatus, mcause and mtvec) 


    // FUs output a branch on MRET/SRET
    // and an exception on ECALL/EBREAK
    
    // mret/sret is a taken branch to MEPC
    // FIXME: there are a bunch of side effects here I'm ignoring

    // ECALL/EBREAK causes an exception 








    ////////////////////////
    // SELECTION & OUTPUT //
    ////////////////////////


    dontTouch(input_CSR_privilage)
    dontTouch(user_mode_CSR_read_resp)
    dontTouch(machine_mode_CSR_read_resp)



    val mret      = instructionType === InstructionType.SYSTEM && RS1 === 0.U && PRD === 0.U && imm === 0x302.U && FUNCT3 === 0.U
    val sret      = instructionType === InstructionType.SYSTEM && RS1 === 0.U && PRD === 0.U && imm === 0x102.U && FUNCT3 === 0.U
    val mret_sret = mret || sret


    // FIXME: add more robust exception generation...
    // ie, make it its own section
    val EXCEPTION_CAUSE = Wire(EX_CAUSE())

    // FIXME: add mstatus
    // Then add mstatus check when outputting excause

    EXCEPTION_CAUSE := EX_CAUSE.INSTRUCTION_ADDRESS_MISALIGNED  // default doesnt matter
    when(ECALL){
        EXCEPTION_CAUSE := EX_CAUSE.ECALL_FROM_M_MODE
    }


    //io.mtvec := mtvec_reg.asUInt



    // ALU pipelined; always ready
    io.FU_input.ready                       := 1.B    

    // mret/sret
    io.FU_output.bits.branch_valid          := RegNext(mret_sret)
    io.FU_output.bits.branch_taken          := RegNext(mret_sret)
    io.FU_output.bits.target_address        := RegNext(mepc_reg.asUInt)



    io.FU_output.bits.fetch_PC              := RegNext(io.FU_input.bits.fetch_PC)
    io.FU_output.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    io.FU_output.bits.PRD                   := RegNext(io.FU_input.bits.decoded_instruction.PRD)
    io.FU_output.bits.RD_valid              := RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data               := CSR_out


    io.FU_output.bits.MOB_index             := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    io.FU_output.bits.address               := 0.U

    io.FU_output.bits.ROB_index             := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)

    io.FU_output.bits.exception             := RegNext(ECALL)   //FIXME: currently only ECALL causes an exception
    io.FU_output.bits.exception_cause       := RegNext(EXCEPTION_CAUSE)   //FIXME: currently only ECALL causes an exception



    input_valid                             := CSR_input_valid

    dontTouch(CSR_input_valid)
    dontTouch(input_valid)

}


