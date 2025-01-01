/* ------------------------------------------------------------------------------------
* Filename: CSR_inits.scala
* Author: Hakam Atassi
* Date: Jan  2024
* Description: All the CSR inits
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

trait CSR_inits{


    //////////////////
    // CSR MAPPINGS //   
    //////////////////
    val user_mode_CSRs = Map(
        //-----------------------
        // Floating-Point CSRs
        //-----------------------
        CSRs.fflags         -> fflags_reg,
        CSRs.frm            -> fflags_reg, 
        CSRs.fcsr           -> fcsr_reg,

        //-----------------------
        // UNPRIVILEGED COUNTERS
        //-----------------------
        CSRs.cycle          -> cycle_reg,
        CSRs.time           -> time_reg,
        CSRs.instret        -> instret_reg,

        CSRs.cycleh         -> cycleh_reg,
        CSRs.timeh          -> timeh_reg,
        CSRs.instreth       -> instreth_reg,
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
        CSRs.scontext    -> scontext,

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
        CSRs.mnscratch   -> mnscratch_reg,
        CSRs.mnepc       -> mnepc_reg,
        CSRs.mncause     -> mncause_reg,
        CSRs.mnstatus    -> mnstatus_reg,

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
        CSRs.mcountinhibit -> mcounterinhibit_reg,

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

    ////////////////////////
    // USER MODE CSR INIT //
    ////////////////////////
    // Unprivileged Floating-Point CSRs
    val fflags_reg      = RegInit(0.U(32.W))
    val frm_reg         = RegInit(0.U(32.W))
    val fcsr_reg        = RegInit(0.U(32.W))

    // Unprivileged Counters/Timers
    // lower values 
    val cycle_reg        = RegInit(0.U(32.W))
    val time_reg         = RegInit(0.U(32.W))
    val instret_reg      = RegInit(0.U(32.W))

    val cycleh_reg       = RegInit(0.U(32.W))
    val timeh_reg        = RegInit(0.U(32.W))
    val instreth_reg     = RegInit(0.U(32.W))

    // optional counters (unused)
    val hpmcounter3_reg  = RegInit(0.U(32.W))
    val hpmcounter4_reg  = RegInit(0.U(32.W))
    val hpmcounter5_reg  = RegInit(0.U(32.W))
    val hpmcounter6_reg  = RegInit(0.U(32.W))
    val hpmcounter7_reg  = RegInit(0.U(32.W))
    val hpmcounter8_reg  = RegInit(0.U(32.W))
    val hpmcounter9_reg  = RegInit(0.U(32.W))
    val hpmcounter10_reg = RegInit(0.U(32.W))
    val hpmcounter11_reg = RegInit(0.U(32.W))
    val hpmcounter12_reg = RegInit(0.U(32.W))
    val hpmcounter13_reg = RegInit(0.U(32.W))
    val hpmcounter14_reg = RegInit(0.U(32.W))
    val hpmcounter15_reg = RegInit(0.U(32.W))
    val hpmcounter16_reg = RegInit(0.U(32.W))
    val hpmcounter17_reg = RegInit(0.U(32.W))
    val hpmcounter18_reg = RegInit(0.U(32.W))
    val hpmcounter19_reg = RegInit(0.U(32.W))
    val hpmcounter20_reg = RegInit(0.U(32.W))
    val hpmcounter21_reg = RegInit(0.U(32.W))
    val hpmcounter22_reg = RegInit(0.U(32.W))
    val hpmcounter23_reg = RegInit(0.U(32.W))
    val hpmcounter24_reg = RegInit(0.U(32.W))
    val hpmcounter25_reg = RegInit(0.U(32.W))
    val hpmcounter26_reg = RegInit(0.U(32.W))
    val hpmcounter27_reg = RegInit(0.U(32.W))
    val hpmcounter28_reg = RegInit(0.U(32.W))
    val hpmcounter29_reg = RegInit(0.U(32.W))
    val hpmcounter30_reg = RegInit(0.U(32.W))
    val hpmcounter31_reg = RegInit(0.U(32.W))

    // upper values 
    val hpmcounter3h_reg    = RegInit(0.U(32.W))
    val hpmcounter4h_reg    = RegInit(0.U(32.W))
    val hpmcounter5h_reg    = RegInit(0.U(32.W))
    val hpmcounter6h_reg    = RegInit(0.U(32.W))
    val hpmcounter7_reg     = RegInit(0.U(32.W))
    val hpmcounter8h_reg    = RegInit(0.U(32.W))
    val hpmcounter9h_reg    = RegInit(0.U(32.W))
    val hpmcounter10h_reg   = RegInit(0.U(32.W))
    val hpmcounter11h_reg   = RegInit(0.U(32.W))
    val hpmcounter12h_reg   = RegInit(0.U(32.W))
    val hpmcounter13h_reg   = RegInit(0.U(32.W))
    val hpmcounter14h_reg   = RegInit(0.U(32.W))
    val hpmcounter15h_reg   = RegInit(0.U(32.W))
    val hpmcounter16h_reg   = RegInit(0.U(32.W))
    val hpmcounter17h_reg   = RegInit(0.U(32.W))
    val hpmcounter18h_reg   = RegInit(0.U(32.W))
    val hpmcounter19h_reg   = RegInit(0.U(32.W))
    val hpmcounter20h_reg   = RegInit(0.U(32.W))
    val hpmcounter21h_reg   = RegInit(0.U(32.W))
    val hpmcounter22h_reg   = RegInit(0.U(32.W))
    val hpmcounter23h_reg   = RegInit(0.U(32.W))
    val hpmcounter24h_reg   = RegInit(0.U(32.W))
    val hpmcounter25h_reg   = RegInit(0.U(32.W))
    val hpmcounter26h_reg   = RegInit(0.U(32.W))
    val hpmcounter27h_reg   = RegInit(0.U(32.W))
    val hpmcounter28h_reg   = RegInit(0.U(32.W))
    val hpmcounter29h_reg   = RegInit(0.U(32.W))
    val hpmcounter30h_reg   = RegInit(0.U(32.W))
    val hpmcounter31h_reg   = RegInit(0.U(32.W))

    //////////////////////////////
    // SUPERVISOR MODE CSR INIT //
    //////////////////////////////

    // Supervisor Trap Setup
    val sstatus_reg     = RegInit(0.U.asTypeOf(new mstatus))    // 
    val sie_reg         = RegInit(0.U.asTypeOf(new mie))                      
    val stvec_reg       = RegInit(0.U.asTypeOf(new mtvec))
    val scounteren_reg  = RegInit(0.U.asTypeOf(new mcounteren))

    // Supervisor Configuration
    val senvcfg_reg     = RegInit(0.U.asTypeOf(new senvcfg))

    //Supervisor Counter Setup
    val scountinhibit_reg = RegInit(0.U.asTypeOf(new mcounterinhibit))

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
    val mhartid_reg     = RegInit(hartID.U.asTypeOf(new mhartid))               // Index of hart FIXME: propegate from Chipyard. RO
    val mconfigptr_reg  = RegInit(0.U.asTypeOf(new mconfigptr))                 // Pointer to structure that contains configuration info in SW. RO.

    // Machine Trap Setup
    val mstatus_reg     = RegInit(0.U.asTypeOf(new mstatus))                    // The current core's status. Supervisor and User view a modified version of this reg. RW. 
    val misa_reg        = RegInit(initMisa(coreParameters).asTypeOf(new misa))  // Machine ISA ("RV32IMA..." etc). writeable if isa is modifiable at runtime. RW
    val medeleg_reg     = RegInit(UInt(32.W), 0.U)                              // FIXME: IDK
    val mideleg_reg     = RegInit(UInt(32.W), 0.U)                              // FIXME: IDK
    val mie_reg         = RegInit(0.U.asTypeOf(new mie))                        // Machine interrupt enable. RW. Interrupt cause i in mcause correspondings to bit i here. 
    val mtvec_reg       = RegInit(0.U.asTypeOf(new mtvec))                      // if MODE=base, all traps (interrupts + exceptions) jump to BASE. If MODE=vectored, exceptions jump to BASE, interrupts jump to BASE + 4*CAUSE. RW
    val mcounteren_reg  = RegInit(0.U.asTypeOf(new mcounteren))                 // Controls availability of counter regs to lower privs. Only modifies visibility. Counters still count. 
    
    // FIXME: this is bugged (not upper bits of mstatus, just mstatus again. shouldnt be...)
    //val mstatush_reg    = RegInit(0.U.asTypeOf(new mstatus))                    // The current core's status. Supervisor and User view a modified version of this reg. RW
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
    val minstret_reg      = RegInit(UInt(32.W), 0.U)  // lower 32 bits of instruction retired count. Writeable by SW. 

    val mcycleh_reg       = RegInit(UInt(32.W), 0.U)   // upper 32 bits of mcycle
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
    val mcountinhibit_reg = RegInit(0.U.asTypeOf(new mcounterinhibit))  // Controls if counters update. Bit set disables corresponding couter updating

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


}