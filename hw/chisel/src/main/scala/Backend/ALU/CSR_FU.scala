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
 * Machine Counter Setup 
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
 * Debug/Trace Registers 
 * 0x7A0     MRW          tselect         Debug/Trace trigger register select.
 * 0x7A1     MRW          tdata1          First Debug/Trace trigger data register.
 * 0x7A2     MRW          tdata2          Second Debug/Trace trigger data register.
 * 0x7A3     MRW          tdata3          Third Debug/Trace trigger data register.
 * 0x7A8     MRW          mcontext        Machine-mode context register.
 * 
 * Debug Mode Registers 
 * 0x7B0     DRW          dcsr            Debug control and status register.
 * 0x7B1     DRW          dpc             Debug program counter.
 * 0x7B2     DRW          dscratch0       Debug scratch register 0.
 * 0x7B3     DRW          dscratch1       Debug scratch register 1.
*/


// upper 2 bits of address define RO or RW



// FIXME: CSRFU needs parameterizable latency
class CSR_FU(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._


    /////////////
    // LATENCY //
    /////////////
    // CSRs cant be implemented as a bram (counters, RMW charectaristics, etc...)
    // Since CSRs exist as registers, access latency is quite long. 
    // Hence, CSR accesses are passed through an output shift register, where we rely on the synthesis tool to retime everything 
    // and provide an acceptable Fmax. 

    val LATENCY:Int = 6 // output stages/access latency

    ////////////////////////////
    // CSR AND PLIC/CLINT I/O //
    ////////////////////////////

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    val irq_software_i                      = IO(Input(Bool()))      //msip
    val irq_timer_i                         = IO(Input(Bool()))      //mtip
    val irq_external_i                      = IO(Input(Bool()))      //meip
    val debug_req_i                         = IO(Input(Bool()))      //debug
    val irq_nm_i                            = IO(Input(Bool()))      //nmi


    ////////////////////////
    // DECODE CSR REQUEST //
    ////////////////////////
    val RS1                         =  io.FU_input.bits.decoded_instruction.RS1

    val is_CSRRW                    =  CSRRW && FUNCT3 === 0x1.U
    val is_CSRRS                    =  CSRRW && FUNCT3 === 0x2.U
    val is_CSRRC                    =  CSRRW && FUNCT3 === 0x3.U
    val is_CSRRWI                   =  CSRRW && FUNCT3 === 0x5.U
    val is_CSRRSI                   =  CSRRW && FUNCT3 === 0x6.U
    val is_CSRRCI                   =  CSRRW && FUNCT3 === 0x7.U

    val wr_data                     =  Mux(IS_IMM, RS1, RS1_data)   // FIXME: CSR instruction encoding is weird. Technically, for CSR IMM insns, the imm is the RS1 field

    
    //1.B //FIXME:  // input privilage is lower or equal to active privilage

    val input_CSR_address           =  io.FU_input.bits.decoded_instruction.IMM         // address of requested CSR
    val input_CSR_privilage         =  get_CSR_lowest_priv(input_CSR_address).asUInt    // get privilage level of requested CSR
    val input_CSR_access            =  get_CSR_access(input_CSR_address)                // get RO/RW 


    // CSRRW always writes. only reads if RS1 != x0.
    // CSRRS/CSRRC (imm and no imm) always read. only write if wr_data != 0


    val input_CSR_read_request      =   (((is_CSRRW || is_CSRRWI) && io.FU_input.bits.decoded_instruction.PRD =/= 0.U) ||
                                        (is_CSRRS || is_CSRRSI) || 
                                        (is_CSRRC || is_CSRRCI)) && 
                                        io.FU_input.valid

    dontTouch(is_CSRRW)
    dontTouch(is_CSRRS)
    dontTouch(is_CSRRC)
    dontTouch(is_CSRRWI)
    dontTouch(is_CSRRSI)
    dontTouch(is_CSRRCI)
    
    val input_CSR_write_request     =   (((is_CSRRW || is_CSRRWI)) ||
                                        ((is_CSRRS || is_CSRRSI) && wr_data =/= 0.U) || 
                                        ((is_CSRRC || is_CSRRCI) && wr_data =/= 0.U)) && 
                                        io.FU_input.valid
    

    val current_privilege = RegInit(UInt(2.W), 0x3.U)   // Current privilage. Set to M on reset as per spec

    val PRIVILAGE_OK                =  current_privilege >= input_CSR_privilage

    val CSR_output = WireInit(0.U.asTypeOf(new FU_output(coreParameters)))

    ////////////////////////
    // USER MODE CSR INIT //
    ////////////////////////
    // Unprivileged Floating-Point CSRs
    val fflags_reg      = RegInit(UInt(32.W), 0.U)    // no float atm
    val frm_reg         = RegInit(UInt(32.W), 0.U)
    val fcsr_reg        = RegInit(UInt(32.W), 0.U)

    // Unprivileged Counters/Timers
    val cycle_reg        = Wire(UInt(32.W))
    val instret_reg      = Wire(UInt(32.W))     

    val cycleh_reg       = Wire(UInt(32.W))
    val instreth_reg     = Wire(UInt(32.W))



    // optional counters (unused)
    val hpmcounter3_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter4_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter5_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter6_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter7_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter8_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter9_reg  = RegInit(UInt(32.W), 0.U)
    val hpmcounter10_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter11_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter12_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter13_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter14_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter15_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter16_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter17_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter18_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter19_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter20_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter21_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter22_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter23_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter24_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter25_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter26_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter27_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter28_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter29_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter30_reg = RegInit(UInt(32.W), 0.U)
    val hpmcounter31_reg = RegInit(UInt(32.W), 0.U)

    // upper values 
    val hpmcounter3h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter4h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter5h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter6h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter7h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter8h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter9h_reg    = RegInit(UInt(32.W), 0.U)
    val hpmcounter10h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter11h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter12h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter13h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter14h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter15h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter16h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter17h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter18h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter19h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter20h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter21h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter22h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter23h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter24h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter25h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter26h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter27h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter28h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter29h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter30h_reg   = RegInit(UInt(32.W), 0.U)
    val hpmcounter31h_reg   = RegInit(UInt(32.W), 0.U)

    //////////////////////////////
    // SUPERVISOR MODE CSR INIT //
    //////////////////////////////

    // Supervisor Trap Setup
    val sstatus_reg     = RegInit(0.U.asTypeOf(new mstatus))    
    val sie_reg         = RegInit(0.U.asTypeOf(new mie))                      
    val stvec_reg       = RegInit(0.U.asTypeOf(new mtvec))
    val scounteren_reg  = RegInit(0.U.asTypeOf(new mcounteren))

    // Supervisor Configuration
    val senvcfg_reg     = RegInit(0.U.asTypeOf(new menvcfg))

    //Supervisor Counter Setup (Smcdeleg extension) (not implemented)
    val scountinhibit_reg = RegInit(0.U.asTypeOf(new mcountinhibit))

    // Supervisor Trap Handling
    val sscratch_reg    = RegInit(0.U.asTypeOf(new mscratch))
    val sepc_reg        = RegInit(0.U.asTypeOf(new mepc))
    val scause_reg      = RegInit(0.U.asTypeOf(new mcause))
    val stval_reg       = RegInit(0.U.asTypeOf(new mtval))
    val sip_reg         = RegInit(0.U.asTypeOf(new mip))

    // Count overflow (Sscofpmf)
    val scountovf_reg   = RegInit(UInt(32.W), 0.U)

    // Supervisor Protection and Translation
    val satp_reg        = RegInit(0.U.asTypeOf(new satp))  // Holds PPN and other data for base page table.

    // Debug/Trace Registers (Smstateen extension)
    val scontext_reg    = RegInit(UInt(32.W), 0.U)

    // Supervisor State Enable Registers (Smstateen extension)
    val sstateen0_reg   = RegInit(UInt(32.W), 0.U)
    val sstateen1_reg   = RegInit(UInt(32.W), 0.U)
    val sstateen2_reg   = RegInit(UInt(32.W), 0.U)
    val sstateen3_reg   = RegInit(UInt(32.W), 0.U)

    ///////////////////////////
    // MACHINE MODE CSR INIT //
    ///////////////////////////

    // Machine Information Registers
    val mvendorid_reg   = RegInit(0.U.asTypeOf(new mvendorid))                  // JEDEC ID. KEEP 0. READ ONLY.
    val marchid_reg     = RegInit(0.U.asTypeOf(new marchid))                    // Architecture ID. Represents core iteration. RO. Encoded as O
    val mimpid_reg      = RegInit(UInt(32.W), 0.U)                              // Processor version. Core Version. RO. Encoded as 0. 
    val mhartid_reg     = RegInit(UInt(32.W), 0.U)                              // Index of hart FIXME: propegate from Chipyard. RO
    val mconfigptr_reg  = RegInit(0.U.asTypeOf(new mconfigptr))                 // Pointer to structure that contains configuration info in SW. RO.

    // Machine Trap Setup
    val mstatus_reg     = RegInit(0x00001800.U.asTypeOf(new mstatus))                    // The current core's status. Supervisor and User view a modified version of this reg. RW. 
    val misa_reg        = RegInit(initMisa(coreParameters).asTypeOf(new misa))  // Machine ISA ("RV32IMA..." etc). writeable if isa is modifiable at runtime. RW
    val medeleg_reg     = RegInit(UInt(32.W), 0.U)                              // FIXME: IDK
    val mideleg_reg     = RegInit(UInt(32.W), 0.U)                              // FIXME: IDK
    val mie_reg         = RegInit(0.U.asTypeOf(new mie))                        // Machine interrupt enable. RW. Interrupt cause i in mcause correspondings to bit i here. 
    val mtvec_reg       = RegInit(0.U.asTypeOf(new mtvec))                      // if MODE=base, all traps (interrupts + exceptions) jump to BASE. If MODE=vectored, exceptions jump to BASE, interrupts jump to BASE + 4*CAUSE. RW
    val mcounteren_reg  = RegInit(0.U.asTypeOf(new mcounteren))                 // Controls availability of counter regs to lower privs. Only modifies visibility. Counters still count. 
    
    // FIXME: this is bugged (not upper bits of mstatus, just mstatus again. shouldnt be...)
    val mstatush_reg    = RegInit(0.U.asTypeOf(new mstatush))
    val medelegh_reg    = RegInit(UInt(32.W), 0.U)                              // FIXME: IDK

    // Machine Trap Handling
    val mscratch_reg   = RegInit(0.U.asTypeOf(new mscratch))                    // Scratch. I think this can be updated as needed. RW
    val mepc_reg       = RegInit(0.U.asTypeOf(new mepc))                        // When trap taken to M mode, mepc stores address of interrupted or trapped insn. Otherwise, mepc is RW to software. Lower 2 bits ALWAYS 0. 
    val mcause_reg     = RegInit(0.U.asTypeOf(new mcause))                      // When trap taken to M mode, mcause written with exception cause. If interrupt, just set interrupt bit. Also RW to software. 
    val mtval_reg      = RegInit(0.U.asTypeOf(new mtval))                       // When trap taken to M mode, mtval is written with 0 or something else deemed useful for handling the trap. Otherwise set to 0. FIXME: this seems potentially useful. look into this more
    val mip_reg        = RegInit(0.U.asTypeOf(new mip))                         // Machine interrupt pending. RW. Bit i in mcause corresponds to bit i here. 
    val mtinst_reg     = RegInit(UInt(32.W), 0.U)                               // When trap to M mode, mtinst provides information to software to assist in handling trap. If unused, just keep 0. 
    val mtval2_reg     = RegInit(0.U.asTypeOf(new mtval))                       // Same as mtval, just an extra one
 
    // Machine Configuration
    val menvcfg_reg  = RegInit(0.U.asTypeOf(new menvcfg))                       // Controls execution for modes less privilaged than M. 64 bits. FIXME: spec here is complex. RW
    val menvcfgh_reg = RegInit(0.U.asTypeOf(new menvcfg))                       // upper half of menvcfg
    val mseccfg_reg  = RegInit(0.U.asTypeOf(new mseccfg))                       // FIXME: for various security features. 64 bits. RW.
    val mseccfgh_reg = RegInit(0.U.asTypeOf(new mseccfgh))                      // Upper half of mseccfg

    // Machine State Enable Registers (Smstateen extension) (not implemented)
    val mstateen0_reg  =  RegInit(UInt(32.W), 0.U)
    val mstateen1_reg  =  RegInit(UInt(32.W), 0.U)
    val mstateen2_reg  =  RegInit(UInt(32.W), 0.U)
    val mstateen3_reg  =  RegInit(UInt(32.W), 0.U)
    val mstateen0h_reg =  RegInit(UInt(32.W), 0.U)
    val mstateen1h_reg =  RegInit(UInt(32.W), 0.U)
    val mstateen2h_reg =  RegInit(UInt(32.W), 0.U)
    val mstateen3h_reg =  RegInit(UInt(32.W), 0.U)

    // Machine Non-Maskable Interrupt Handling (Smrnmi extension) (not implemented)
    val mnscratch_reg = RegInit(UInt(32.W), 0.U)
    val mnepc_reg     = RegInit(UInt(32.W), 0.U)
    val mncause_reg   = RegInit(0.U.asTypeOf(new mcause))
    val mnstatus_reg  = RegInit(UInt(32.W), 0.U)

    // Machine Counter/Timers
    val mcycle_reg        = RegInit(UInt(32.W), 0.U)  // lower 32 bits of cycle count. Writeable by SW. 
    val mtime_reg         = RegInit(UInt(32.W), 0.U)  // lower 32 bits of cycle count. Writeable by SW. 
    val minstret_reg      = RegInit(UInt(32.W), 0.U)  // lower 32 bits of instruction retired count. Writeable by SW. 

    val mcycleh_reg       = RegInit(UInt(32.W), 0.U)   // upper 32 bits of mcycle
    val mtimeh_reg        = RegInit(UInt(32.W), 0.U)   // upper 32 bits of mcycle
    val minstreth_reg     = RegInit(UInt(32.W), 0.U)   // upper 32 bits of instret

    // Optional performance counters (Sscofpmf extension) (not implemented)
    val mhpmcounter3_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter4_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter5_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter6_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter7_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter8_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter9_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmcounter10_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter11_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter12_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter13_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter14_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter15_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter16_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter17_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter18_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter19_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter20_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter21_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter22_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter23_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter24_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter25_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter26_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter27_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter28_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter29_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter30_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmcounter31_reg   = RegInit(UInt(32.W), 0.U)

    val mhpmcounter3h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter4h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter5h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter6h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter7h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter8h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter9h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmcounter10h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter11h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter12h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter13h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter14h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter15h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter16h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter17h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter18h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter19h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter20h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter21h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter22h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter23h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter24h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter25h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter26h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter27h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter28h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter29h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter30h_reg = RegInit(UInt(32.W), 0.U)
    val mhpmcounter31h_reg = RegInit(UInt(32.W), 0.U)

    // Machine Counter Setup 
    val mcountinhibit_reg = RegInit(0.U.asTypeOf(new mcountinhibit))  // Controls if counters update. Bit set disables corresponding couter updating

    val mhpmevent3_reg    = RegInit(UInt(32.W), 0.U)   // Platform defined. Value determines event for counter updating. (not implemented)
    val mhpmevent4_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent5_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent6_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent7_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent8_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent9_reg    = RegInit(UInt(32.W), 0.U)
    val mhpmevent10_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent11_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent12_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent13_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent14_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent15_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent16_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent17_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent18_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent19_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent20_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent21_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent22_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent23_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent24_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent25_reg   = RegInit(UInt(32.W), 0.U)

    val mhpmevent3h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent4h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent5h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent6h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent7h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent8h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent9h_reg   = RegInit(UInt(32.W), 0.U)
    val mhpmevent10h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent11h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent12h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent13h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent14h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent15h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent16h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent17h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent18h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent19h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent20h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent21h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent22h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent23h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent24h_reg  = RegInit(UInt(32.W), 0.U)
    val mhpmevent25h_reg  = RegInit(UInt(32.W), 0.U)

    // Debug/Trace Registers (not implemented)
    val tselect_reg     = RegInit(UInt(32.W), 0.U)
    val tdata1_reg      = RegInit(UInt(32.W), 0.U)
    val tdata2_reg      = RegInit(UInt(32.W), 0.U)
    val tdata3_reg      = RegInit(UInt(32.W), 0.U)
    val tinfo_reg       = RegInit(UInt(32.W), 0.U)
    val tcontrol_reg    = RegInit(UInt(32.W), 0.U)
    val mcontext_reg    = RegInit(UInt(32.W), 0.U)
    val mscontext_reg   = RegInit(UInt(32.W), 0.U)

    // Debug Mode Registers (not implemented)
    val dcsr_reg        = RegInit(UInt(32.W), 0.U)
    val dpc_reg         = RegInit(UInt(32.W), 0.U)
    val dscratch0_reg   = RegInit(UInt(32.W), 0.U)
    val dscratch1_reg   = RegInit(UInt(32.W), 0.U)

    

    //////////////////
    // CSR MAPPINGS //   
    //////////////////
    val user_mode_CSRs = Map(
        //-----------------------
        // Floating-Point CSRs
        //-----------------------
        CSRs.fflags         -> fflags_reg,
        CSRs.frm            -> frm_reg, 
        CSRs.fcsr           -> fcsr_reg,

        //-----------------------
        // UNPRIVILEGED COUNTERS
        //-----------------------
        CSRs.cycle          -> mcycle_reg,
        CSRs.time           -> mtime_reg,
        CSRs.instret        -> minstret_reg,

        CSRs.cycleh         -> mcycleh_reg,
        CSRs.timeh          -> mtimeh_reg,
        CSRs.instreth       -> minstreth_reg,
    )

    val supervisor_mode_CSRs = Map(
        //-----------------------
        // SUPERVISOR TRAP SETUP
        //-----------------------
        CSRs.sstatus      -> sstatus_reg,
        CSRs.sie          -> sie_reg,
        CSRs.stvec        -> stvec_reg,
        CSRs.scounteren   -> scounteren_reg,

        //---------------------
        // SUPERVISOR CONFIG 
        //---------------------
        CSRs.senvcfg   -> senvcfg_reg,

        //----------------------------
        // SUPERVISOR COUNTER SETUP 
        //----------------------------
        CSRs.scountinhibit   -> scountinhibit_reg,

        //-----------------------
        // MACHINE TRAP HANDLING
        //-----------------------
        CSRs.sscratch   -> sscratch_reg,
        CSRs.sepc       -> sepc_reg,
        CSRs.scause     -> scause_reg,
        CSRs.stval      -> stval_reg,
        CSRs.sip        -> sip_reg,
        CSRs.scountovf  -> scountovf_reg,

        //---------------------------------------
        // SUPERVISOR PROTECTION AND TRANSLATION 
        //---------------------------------------
        CSRs.satp        -> satp_reg,

        //-------------------------
        // DEBUG/TRACE REGISTERS //
        //-------------------------
        CSRs.scontext    -> scontext_reg,

        //------------------------------------
        // SUPERVISOR STATE ENABLE REGISTERS
        //------------------------------------
        CSRs.sstateen0   -> sstateen0_reg,
        CSRs.sstateen1   -> sstateen1_reg,
        CSRs.sstateen2   -> sstateen2_reg,
        CSRs.sstateen3   -> sstateen3_reg,
    )

    val machine_mode_CSRs = Map(
        //------------------------------
        //Machine Information Registers
        //------------------------------
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
        CSRs.medelegh     -> medelegh_reg,

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
        // MACHINE CONFIGURATION
        //-----------------------
        CSRs.menvcfg     -> menvcfg_reg, 
        CSRs.menvcfgh    -> menvcfgh_reg,
        CSRs.mseccfg     -> mseccfg_reg,
        CSRs.mseccfgh    -> mseccfgh_reg,

        //----------------------------
        // MACHINE MEMORY PROTECTION
        //----------------------------
        // pmpcfg0         Physical memory protection configuration.
        // pmpcfg1         Physical memory protection configuration, RV32 only.
        // pmpcfg2         Physical memory protection configuration.
        // pmpcfg3         Physical memory protection configuration, RV32 only.
        // ...             ...
        // pmpcfg14        Physical memory protection configuration.
        // pmpcfg15        Physical memory protection configuration, RV32 only.
        // pmpaddr0        Physical memory protection address register.
        // pmpaddr1        Physical memory protection address register.
        // ...             ...
        // pmpaddr63       Physical memory protection address register.
        
        //------------------------
        // MACHINE STATE ENABLE
        //------------------------
        CSRs.mstateen0  -> mstateen0_reg, 
        CSRs.mstateen1  -> mstateen1_reg, 
        CSRs.mstateen2  -> mstateen2_reg, 
        CSRs.mstateen3  -> mstateen3_reg, 
        CSRs.mstateen0h -> mstateen0_reg, 
        CSRs.mstateen1h -> mstateen1h_reg,
        CSRs.mstateen2h -> mstateen2h_reg,
        CSRs.mstateen3h -> mstateen3h_reg,

        //-----------------------
        // MACHINE NMI HANDLING
        //-----------------------
        //CSRs.mnscratch   -> mnscratch_reg,
        //CSRs.mnepc       -> mnepc_reg,
        //CSRs.mncause     -> mncause_reg,
        //CSRs.mnstatus    -> mnstatus_reg,

        //--------------------
        // MACHINE COUNTERS 
        //--------------------
        CSRs.mcycle      -> mcycle_reg,
        CSRs.minstret    -> minstret_reg,
        CSRs.mcycleh     -> mcycleh_reg,
        CSRs.minstreth   -> minstreth_reg,

        //-----------------------
        // MACHINE COUNTER SETUP
        //-----------------------
        CSRs.mcountinhibit -> mcountinhibit_reg,

        //--------------
        // DEBUG/TRACE 
        //--------------
        CSRs.tselect     -> tselect_reg,
        CSRs.tdata1      -> tdata1_reg,
        CSRs.tdata2      -> tdata2_reg,
        CSRs.tdata3      -> tdata3_reg,
        CSRs.mcontext    -> mcontext_reg,

        //-----------------------
        // DEBUG MODE REGISTERS 
        //-----------------------
        CSRs.dcsr          -> dcsr_reg,
        CSRs.dpc           -> dpc_reg,
        CSRs.dscratch0     -> dscratch0_reg,
        CSRs.dscratch1     -> dscratch1_reg,
    )

    ////////////////////
    // CSR MANAGEMENT //
    ///////////////////
    // PERFORMANCE COUNTER MANAGEMENT //

    when(!mcountinhibit_reg.CY){
        val (new_mcycleh_reg, new_mcycle_reg) = increment_perf_counter(mcycleh_reg, mcycle_reg, 1.U)
        mcycleh_reg := new_mcycleh_reg
        mcycle_reg := new_mcycle_reg

        mtimeh_reg := new_mcycleh_reg
        mtime_reg := new_mcycle_reg
    }

    when(1.B /*!mcountinhibit_reg.TM*/){  // FIXME: ENSURE ALWAYS ON (as per spec. Timer cant be disabled internally)
        val (new_mcycleh_reg, new_mcycle_reg) = increment_perf_counter(mcycleh_reg, mcycle_reg, 1.U)
        mcycleh_reg := new_mcycleh_reg
        mcycle_reg := new_mcycle_reg
    }

    when(!mcountinhibit_reg.IR){
        val (new_minstreth_reg, new_minstret_reg) = increment_perf_counter(minstreth_reg, minstret_reg, PopCount(io.commit.bits.insn_commit.map(_.bits.committed))) // FIXME: technically doesnt count stores
        minstreth_reg := new_minstreth_reg
        minstret_reg := new_minstret_reg
    }


    cycle_reg        := mcycle_reg       // user mode timers are just a view of machine mode timers
    //time_reg         := mtime_reg       // can just be cycle timer as per spec Im pretty sure
    instret_reg      := minstret_reg     

    cycleh_reg       := mcycleh_reg
    //timeh_reg        := mtime_reg
    instreth_reg     := minstreth_reg


    ///////////////
    // MRET/SRET //
    ///////////////

    // FROM SPEC:
    // The MRET, HRET, SRET, or URET instructions are used to return from traps in M-mode, H-
    // mode, S-mode, or U-mode respectively. When executing an xRET instruction, supposing x PP
    // holds the value y, y IE is set to x PIE; the privilege mode is changed to y; x PIE is set to 1; and
    // x PP is set to U (or M if user-mode is not supported)

    when(MRET){
        current_privilege := mstatus_reg.MPP    // update current status
        mstatus_reg.MPP   := 0.U                  // set MPP to user (as per spec)
        mstatus_reg.MPIE  := 1.U                     // XPIE to 1 (as per spec)

        when(mstatus_reg.MPP === 0x3.U){           // prev was M
            mstatus_reg.MIE := mstatus_reg.MPIE
        }.elsewhen(mstatus_reg.MPP === 0x01.U){     // prev was S
            mstatus_reg.SIE := mstatus_reg.MPIE
        }.otherwise{/* nothing */}

        // Trigger branch
        CSR_output.CTRL := 1.B
        CSR_output.branch_valid := 1.B
        CSR_output.branch_taken := 1.B
        CSR_output.target_address := mepc_reg.asUInt

    }.elsewhen(SRET){
        current_privilege := mstatus_reg.SPP
        mstatus_reg.SPP   := 0.U                  // set MPP to user (as per spec)
        mstatus_reg.SPIE  := 1.U                     // XPIE to 1 (as per spec)
        
        when(mstatus_reg.TSR === 1.B){
            CSR_output.exception := 1.B
            CSR_output.exception_cause := EX_CAUSE.ILLEGAL_INSTRUCTION
        }.otherwise{
            // Trigger branch
            CSR_output.CTRL := 1.B
            CSR_output.branch_valid := 1.B
            CSR_output.branch_taken := 1.B
            CSR_output.target_address := sepc_reg.asUInt
        }
    }



    //////////////////
    // ECALL/EBREAK //
    //////////////////

    when(ECALL){
        when(current_privilege === 0x3.U){         // MACHINE
            CSR_output.exception := 1.B
            CSR_output.exception_cause := EX_CAUSE.ECALL_FROM_M_MODE
        }.elsewhen(current_privilege === 0x01.U){   // SUPERVISOR
            CSR_output.exception := 1.B
            CSR_output.exception_cause := EX_CAUSE.ECALL_FROM_S_MODE
        }.elsewhen(current_privilege === 0x00.U){   // USER
            CSR_output.exception := 1.B
            CSR_output.exception_cause := EX_CAUSE.ECALL_FROM_S_MODE
        }.otherwise{assert(0.B, "ECALL FROM INAVLID PRIVILEGE")}
    }

    when(EBREAK){
        CSR_output.exception := 1.B
        CSR_output.exception_cause := EX_CAUSE.BREAKPOINT
    }


    ////////////////////////
    // EXCEPTION HANDLING //
    ////////////////////////

    // medeleg is machine exception deleg

    // FIXME: medeleg[11] MUST be read only 0.

    when(io.flush.valid && io.flush.bits.is_exception){
        val exception_code = io.flush.bits.exception_cause.asUInt

        //val delegate_to_S = (Cat(medelegh_reg, medeleg_reg) >> exception_code)(0)

        when(0.B /*should be delegate to s but idk how it works*/){      // delegate to S mode
            current_privilege := 0x2.U
            scause_reg.CODE := exception_code
            sepc_reg        := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
            //stval_reg       := 0.U      // FIXME: not used. seems optional
            mstatus_reg.SPP := current_privilege(0)     // FIXME: is this accurate
            mstatus_reg.SPIE:= mstatus_reg.SIE
            mstatus_reg.SIE := 0.U 
        }.otherwise{            // handle in M mode (standard)
            current_privilege := 0x3.U
            mcause_reg.CODE := exception_code
            mepc_reg        := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
            //mtval_reg       := 0.U      // FIXME: not used. seems optional
            mstatus_reg.MPP := current_privilege
            mstatus_reg.MPIE:= mstatus_reg.MIE
            mstatus_reg.MIE := 0.U 
        }
    }

    ////////////////////////
    // INTERRUPT HANLDING //
    ////////////////////////
    
    // FIXME: WFI needs to ensure that when a return from interrupt is executed, you dont jump back to the WFI loop
    // for non WFI loops this is not needed. Can just return to interrupted insn (sepc/mepc)

    // FIXME: I have no clue how delegation works

    mip_reg.MSIP := irq_software_i
    mip_reg.MTIP := irq_timer_i
    mip_reg.MEIP := irq_external_i

    val interrupt = RegInit(Bool(), 0.B)

    // hardcoded for now
    val MEI_VALID = mstatus_reg.MIE.asBool && mip_reg.MEIP.asBool && mie_reg.MEIE.asBool
    val MSI_VALID = mstatus_reg.MIE.asBool && mip_reg.MSIP.asBool && mie_reg.MSIE.asBool
    val MTI_VALID = mstatus_reg.MIE.asBool && mip_reg.MTIP.asBool && mie_reg.MTIE.asBool

    val SEI_VALID = mstatus_reg.SIE.asBool && mip_reg.SEIP.asBool && mie_reg.SEIE.asBool
    val SSI_VALID = mstatus_reg.SIE.asBool && mip_reg.SSIP.asBool && mie_reg.SSIE.asBool
    val STI_VALID = mstatus_reg.SIE.asBool && mip_reg.STIP.asBool && mie_reg.STIE.asBool


    dontTouch(MEI_VALID)
    dontTouch(MSI_VALID)
    dontTouch(MTI_VALID)
    dontTouch(SEI_VALID)
    dontTouch(SSI_VALID)
    dontTouch(STI_VALID)


    // Priority: MEI, MSI, MTI, SEI, SSI, STI, UEI, USI, UTI
    val pending_interrupt = WireInit(Bool(), 0.B)
    pending_interrupt := MEI_VALID || MSI_VALID || MTI_VALID || SEI_VALID || SSI_VALID || STI_VALID

    dontTouch(pending_interrupt)


//    val interrupt_delegated_to_S =  (MEI_VALID && mideleg_reg.MEI) || 
//                                    (MSI_VALID && mideleg_reg.MSI) || 
//                                    (MTI_VALID && mideleg_reg.MTI) || 
//                                    (SEI_VALID && mideleg_reg.SEI) || 
//                                    (SSI_VALID && mideleg_reg.SSI) || 
//                                    (STI_VALID && mideleg_reg.STI)

    interrupt := pending_interrupt
    // signal interrupt to I/O

    CSR_port.interrupt := interrupt

    // handle interrupt
    when(io.flush.valid && io.flush.bits.is_interrupt){
        interrupt := 0.B
        current_privilege := 0x3.U // set as M mode
        mcause_reg.CODE := io.flush.bits.exception_cause.asUInt
        mepc_reg        := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
        //mtval_reg       := 0.U      // FIXME: not used. seems optional
        mstatus_reg.MPP := current_privilege     // FIXME: is this accurate
        mstatus_reg.MPIE:= mstatus_reg.MIE
        mstatus_reg.MIE := 0.U 
    }

    // PERFORMANCE COUNTER UPDATES

    //////////////
    // CSR READ //
    //////////////

    val CSR_map = user_mode_CSRs ++ supervisor_mode_CSRs ++ machine_mode_CSRs

    // FIXME: ensure corrent perms. otherwise, illegal instruction exception (I think)
    // There has got to be a better way of doing this

    val CSR_read_out = WireInit(UInt(32.W), 0.U)

    val CSR_not_found = Wire(Bool())
    CSR_not_found := 1.B

    when(PRIVILAGE_OK){ // user mode
        for((addr, reg) <- CSR_map){
            when(addr.U === CSR_addr){
                CSR_read_out := reg.asUInt
                CSR_not_found := 0.B
            }
        }
    }

    when(CSR_not_found && CSRRW){
        CSR_output.exception := 1.B
        CSR_output.exception_cause := EX_CAUSE.ILLEGAL_INSTRUCTION
    }

    ///////////////
    // CSR WRITE //
    ///////////////
    // check write to machine mode regs  
    // FIXME: privilege is not sufficient to determine writability.
    // Need to also ensure that the register is R/W, etc.

    when(current_privilege >= input_CSR_privilage && input_CSR_write_request && input_CSR_access === ACCESS.RW) {
        for ((addr, reg) <- CSR_map) {    // FIXME: add read only, etc...
            when(addr.U === CSR_addr) {
                when(is_CSRRC || is_CSRRCI){
                    reg :=  (reg.asUInt & ~wr_data).asTypeOf(reg.cloneType)
                }.elsewhen(is_CSRRW || is_CSRRWI){
                    reg :=  (wr_data).asTypeOf(reg.cloneType)
                }.elsewhen(is_CSRRS || is_CSRRSI){
                    reg :=  (reg.asUInt | wr_data).asTypeOf(reg.cloneType)
                }
            }
        }
    }


    /////////////////////
    // ASSIGN CSR PORT //
    /////////////////////
    CSR_port.mtvec := mtvec_reg


    /////////////
    //  OUTPUT //
    /////////////

    dontTouch(CSR_output)

    CSR_output.fetch_PC              := io.FU_input.bits.fetch_PC
    CSR_output.fetch_packet_index    := io.FU_input.bits.decoded_instruction.packet_index
    CSR_output.PRD                   := io.FU_input.bits.decoded_instruction.PRD
    CSR_output.RD_valid              := io.FU_input.bits.decoded_instruction.RD_valid
    CSR_output.RD_data               := CSR_read_out
    CSR_output.RS1_data.get          := RS1_data
    CSR_output.MOB_index             := io.FU_input.bits.decoded_instruction.MOB_index
    CSR_output.address               := 0.U
    CSR_output.ROB_index             := io.FU_input.bits.decoded_instruction.ROB_index
    //CSR_output.exception             := ECALL
    //CSR_output.exception_cause       := (EXCEPTION_CAUSE)

    FU_output.io.enq.valid                      := RegNext(CSR_input_valid)
    FU_output.io.enq.bits                       := RegNext(CSR_output)

    dontTouch(CSR_input_valid)

    //FU_output.io.enq.bits.branch_valid          := RegNext(MRET_SRET || ECALL)
    //FU_output.io.enq.bits.branch_taken          := RegNext(MRET_SRET || ECALL)
    //FU_output.io.enq.bits.CTRL                  := RegNext(CTRL)
    //FU_output.io.enq.bits.target_address        := RegNext(Mux(MRET_SRET , mepc_reg.asUInt, mtvec_reg.asUInt)) //RegNext(mepc_reg.asUInt)
    //FU_output.io.enq.bits.fetch_PC              := RegNext(io.FU_input.bits.fetch_PC)
    //FU_output.io.enq.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)
    //FU_output.io.enq.bits.PRD                   := RegNext(io.FU_input.bits.decoded_instruction.PRD)
    //FU_output.io.enq.bits.RD_valid              := RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    //FU_output.io.enq.bits.RD_data               := CSR_out
    //FU_output.io.enq.bits.RS1_data.get          := RegNext(RS1_data)
    //FU_output.io.enq.bits.MOB_index             := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    //FU_output.io.enq.bits.address               := 0.U
    //FU_output.io.enq.bits.ROB_index             := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    //FU_output.io.enq.bits.exception             := RegNext(ECALL)   //FIXME: currently only ECALL causes an exception
    //FU_output.io.enq.bits.exception_cause       := RegNext(EXCEPTION_CAUSE)   //FIXME: currently only ECALL causes an exception



    dontTouch(input_CSR_privilage)
    //dontTouch(user_mode_CSR_read_resp)
    //dontTouch(machine_mode_CSR_read_resp)
    dontTouch(current_privilege)
    dontTouch(interrupt)
    dontTouch(CSR_port)
    dontTouch(irq_nm_i)
    dontTouch(irq_timer_i)
    dontTouch(irq_external_i)
    dontTouch(irq_software_i)
    dontTouch(irq_nm_i)
    dontTouch(input_CSR_read_request)
    dontTouch(input_CSR_write_request)
    dontTouch(input_CSR_privilage)
    dontTouch(RS1_data)
    dontTouch(CSR_addr)
}


