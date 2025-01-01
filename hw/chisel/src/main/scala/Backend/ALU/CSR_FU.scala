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



// FIXME: CSRFU needs parameterizable latency
class CSR_FU(coreParameters:CoreParameters) extends GALU(coreParameters) with CSR_inits{
    import coreParameters._

    /////////////
    // LATENCY //
    /////////////
    // CSRs cant be implemented as a bram (counters, RMW charectaristics, etc...)
    // Since CSRs exist as registers, access latency is quite long. 
    // Hence, CSR accesses are passed through an output shift register, where we rely on the synthesis tool to retime everything 
    // and provide an acceptable Fmax. 

    val LATENCY:INT = 6 // output stages/access latency

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

    val wr_data                     =  Mux(IS_IMM, imm, RS1_data)

    val PRIVILAGE_OK                =  1.B //FIXME:  // input privilage is lower or equal to active privilage

    val input_CSR_address           =  io.FU_input.bits.decoded_instruction.IMM      // address of requested CSR
    val input_CSR_privilage         =  get_CSR_lowest_priv(input_CSR_address)
    val input_CSR_access            =  get_CSR_access(input_CSR_address)      // What is the minimum required privilage required for the requested CSR? (this is encoded in the address)

    val input_CSR_read_request      =  !(io.FU_input.bits.decoded_instruction.PRD === 0.U)  // when PRD == x0, the read is discarded, so dont read at all.
    val input_CSR_write_request     =  (is_CSR && RS1 =/= 0.U)
    
    val active_CSR_privilage        =  0.U      // what was the privilage level of the core during request? 



    ////////////////////
    // CSR MANAGEMENT //
    ///////////////////

    // PERFORMANCE COUNTERS //

    val (new_cycleh_reg, new_cycle_reg) = increment_perf_counter(cycleh_reg, cycle_reg, 1.U)
    cycleh_reg := new_cycleh_reg
    cycle_reg := new_cycle_reg


    when(io.commit.valid){
        val (new_instret_reg, new_instreth_reg) = increment_perf_counter(instreth_reg, instret_reg, PopCount(io.commit.bits.insn_commit.map(_.valid)))
        instret_reg := new_instret_reg
        instreth_reg := new_instreth_reg
    }

    // TRAP CSRs //

    // TODO: 


    ////////////////
    // INTERRUPTS //
    ////////////////

    mip_reg.MSIP := irq_software_i
    mip_reg.MTIP := irq_timer_i
    mip_reg.MEIP := irq_external_i

    val interrupt = RegInit(Bool(), 0.B)


    //val any_pending_interrupt = (mip_reg.MSIP.asBool || mip_reg.MTIP.asBool || mip_reg.MEIP.asBool)
    val machine_pending_interrupt = (mip_reg.MSIP.asBool && mie_reg.MSIE.asBool || mip_reg.MTIP.asBool && mie_reg.MTIE.asBool || mip_reg.MEIP.asBool && mie_reg.MEIE.asBool) && mstatus_reg.MIE.asBool

    when(machine_pending_interrupt && !RegNext(machine_pending_interrupt)) { // interrupt edge detect (CLINT)
      interrupt := 1.B 
    }

    when(io.flush.valid && io.flush.bits.is_valid() && io.flush.bits.is_interrupt){ // ROB currently redirecting due to interrupt
      interrupt := 0.B 
      mepc_reg := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
    }


    CSR_port.interrupt := interrupt

    // PERFORMANCE COUNTER UPDATES
    mcycle_reg   := mcycle_reg   + 1.U
    //minstret_reg := minstret_reg + PopCount(io.partial_commit.valid) // FIXME: 


    ///////////////
    // EXCEPTION //
    ///////////////

    when(io.flush.valid && io.flush.bits.is_exception){
        //mepc_reg := io.flush.bits.flushing_PC

        mepc_reg := io.flush.bits.flushing_PC.asTypeOf(mepc_reg.cloneType) 
        mcause_reg.CODE := io.flush.bits.exception_cause.asUInt
        //mstatus_reg := ???
    }

    val MRET_SRET = MRET || SRET


    // FIXME: add more robust exception generation...
    // ie, make it its own section
    val EXCEPTION_CAUSE = Wire(EX_CAUSE())

    // FIXME: add mstatus
    // Then add mstatus check when outputting excause

    // FIXME: this are all wrong (depends on mstatus I think)
    EXCEPTION_CAUSE := EX_CAUSE.INSTRUCTION_ADDRESS_MISALIGNED  // default doesnt matter
    when(ECALL){
        EXCEPTION_CAUSE := EX_CAUSE.ECALL_FROM_U_MODE
    }





















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
                when(is_CSRRC){
                    reg :=  (reg.asUInt & ~wr_data).asTypeOf(reg.cloneType)
                }.elsewhen(is_CSRRW){
                    reg :=  (wr_data).asTypeOf(reg.cloneType)
                }.elsewhen(is_CSRRS){
                    reg :=  (reg.asUInt | wr_data).asTypeOf(reg.cloneType)
                }
            }
        }
    }

    




    /////////////////////
    // ASSIGN CSR PORT //
    /////////////////////

    CSR_port.mtvec := (mtvec_reg.BASE << 2)



    /////////////
    //  OUTPUT //
    /////////////





    FU_output.io.enq.valid                      := RegNext(CSR_input_valid)
    FU_output.io.enq.bits.branch_valid          := RegNext(MRET_SRET || ECALL)
    FU_output.io.enq.bits.branch_taken          := RegNext(MRET_SRET || ECALL)
    FU_output.io.enq.bits.CTRL                  := RegNext(CTRL)
    FU_output.io.enq.bits.target_address        := RegNext(Mux(MRET_SRET , mepc_reg.asUInt, mtvec_reg.asUInt)) //RegNext(mepc_reg.asUInt)
    FU_output.io.enq.bits.fetch_PC              := RegNext(io.FU_input.bits.fetch_PC)
    FU_output.io.enq.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)
    FU_output.io.enq.bits.PRD                   := RegNext(io.FU_input.bits.decoded_instruction.PRD)
    FU_output.io.enq.bits.RD_valid              := RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    FU_output.io.enq.bits.RD_data               := CSR_out
    FU_output.io.enq.bits.RS1_data.get          := RegNext(RS1_data)
    FU_output.io.enq.bits.MOB_index             := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.address               := 0.U
    FU_output.io.enq.bits.ROB_index             := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    FU_output.io.enq.bits.exception             := RegNext(ECALL)   //FIXME: currently only ECALL causes an exception
    FU_output.io.enq.bits.exception_cause       := RegNext(EXCEPTION_CAUSE)   //FIXME: currently only ECALL causes an exception


    dontTouch(input_CSR_privilage)
    dontTouch(user_mode_CSR_read_resp)
    dontTouch(machine_mode_CSR_read_resp)
    dontTouch(interrupt)
    dontTouch(CSR_port)
    dontTouch(irq_nm_i)
    dontTouch(irq_timer_i)
    dontTouch(irq_external_i)
    dontTouch(irq_software_i)
    dontTouch(irq_nm_i)
    dontTouch(input_CSR_read_request)
    dontTouch(input_CSR_write_request)

}


