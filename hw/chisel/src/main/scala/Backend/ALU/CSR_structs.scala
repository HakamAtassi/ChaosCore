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


// Machine ISA register (misa) - 32 bits for RV32
class misa extends Bundle {
    val A = Bool()  // Atomic extension
    val B = Bool()  // B extension
    val C = Bool()  // Compressed extension
    val D = Bool()  // Double-precision floating-point extension
    val E = Bool()  // RV32E base ISA
    val F = Bool()  // Single-precision floating-point extension
    val G = Bool()  // Reserved
    val H = Bool()  // Hypervisor extension
    val I = Bool()  // RV32I/64I/128I base ISA
    val J = Bool()  // Reserved
    val K = Bool()  // Reserved
    val L = Bool()  // Reserved
    val M = Bool()  // Integer Multiply/Divide extension
    val N = Bool()  // Tentatively reserved for User-Level Interrupts
    val O = Bool()  // Reserved
    val P = Bool()  // Tentatively reserved for Packed-SIMD extension
    val Q = Bool()  // Quad-precision floating-point extension
    val R = Bool()  // Reserved
    val S = Bool()  // Supervisor mode implemented
    val T = Bool()  // Reserved
    val U = Bool()  // User mode implemented
    val V = Bool()  // Vector extension
    val W = Bool()  // Reserved
    val X = Bool()  // Non-standard extensions present
    val Y = Bool()  // Reserved
    val Z = Bool()  // Reserved

    def init: UInt = {
      0.U
    }

  val WPRI       = UInt(4.W)  // Reserved bits (WPRI: write preserve, read ignore)
  val MXL        = UInt(2.W)  // Machine XLEN (for RV32 this should be 00)

}

// Vendor ID register (mvendorid) - 32 bits
class mvendorid extends Bundle {
  val Offset = UInt(7.W)     // Custom vendor-specific bits
  val Bank   = UInt(25.W)    // Reserved bits for vendor usage
}

// Architecture ID register (marchid) - 32 bits
class marchid extends Bundle {
  val archID = UInt(32.W)    // Architecture ID
}

// Hart ID register (mhartid) - 32 bits
class mhartid extends Bundle {
  val hartid = UInt(32.W)    // Hardware thread ID
}

class satp extends Bundle{
  val NA = UInt(32.W) // FIXME: incomplete
}

// Machine status register (mstatus) - 32 bits
class mstatus extends Bundle {
  val SD    = UInt(1.W)    // Status dirty
  val WPRI3 = UInt(8.W)    // Reserved bits
  val TSR   = UInt(1.W)    // Trap SRET
  val TW    = UInt(1.W)    // Timeout Wait
  val TVM   = UInt(1.W)    // Trap Virtual Memory
  val MXR   = UInt(1.W)    // Make eXecutable Readable
  val SUM   = UInt(1.W)    // Supervisor User Memory access
  val MPRV  = UInt(1.W)    // Modify privilege
  val XS    = UInt(2.W)    // Extension status
  val FS    = UInt(2.W)    // Floating-point status
  val MPP   = UInt(2.W)    // Machine previous privilege
  val VS    = UInt(2.W)    
  val SPP   = UInt(1.W)    // Supervisor previous privilege
  val MPIE  = UInt(1.W)    // Machine previous interrupt enable
  val UBE   = UInt(1.W)    // User big-endian
  val SPIE  = UInt(1.W)    // Supervisor previous interrupt enable
  val WPRI2 = UInt(1.W)    // Reserved bit
  val MIE   = UInt(1.W)    // Machine interrupt enable
  val WPRI1 = UInt(1.W)
  val SIE   = UInt(1.W)    // Supervisor interrupt enable
  val WPRI0 = UInt(1.W)
}

// Machine trap-vector base address register (mtvec) - 32 bits
class mtvec extends Bundle {
  val BASE = UInt(30.W)    // Trap-vector base address
  val MODE = UInt(2.W)     // Mode (0 = direct, 1 = vectored)
}

// Machine interrupt pending register (mip) - 32 bits
class mip extends Bundle {
  val WPRI1  = UInt(19.W)  // Reserved

  val SGEIP  = UInt(1.W)   // ???

  val MEIP   = UInt(1.W)   // Machine external interrupt pending
  val VSEIP  = UInt(1.W)   // Hypervisor external interrupt pending
  val SEIP   = UInt(1.W)   // Supervisor external interrupt pending
  val UEIP   = UInt(1.W)   // User external interrupt pending

  val MTIP   = UInt(1.W)   // Machine timer interrupt pending
  val VSTIP  = UInt(1.W)   // Hypervisor timer interrupt pending
  val STIP   = UInt(1.W)   // Supervisor timer interrupt pending
  val UTIP   = UInt(1.W)   // User timer interrupt pending

  val MSIP   = UInt(1.W)   // Machine software interrupt pending
  val VSSIP  = UInt(1.W)   // Hypervisor software interrupt pending
  val SSIP   = UInt(1.W)   // Supervisor software interrupt pending
  val USIP   = UInt(1.W)   // User software interrupt pending

}

// Machine interrupt enable register (mie) - 32 bits
class mie extends Bundle {
  val WPRI1  = UInt(19.W)  // Reserved

  val SGEIE  = UInt(1.W)   // ???

  val MEIE   = UInt(1.W)   // Machine external interrupt enable
  val VSEIE  = UInt(1.W)   // Hypervisor external interrupt enable
  val SEIE   = UInt(1.W)   // Supervisor external interrupt enable
  val UEIE   = UInt(1.W)   // User external interrupt enable

  val MTIE   = UInt(1.W)   // Machine timer interrupt enable
  val VSTIE  = UInt(1.W)   // Hypervisor timer interrupt enable
  val STIE   = UInt(1.W)   // Supervisor timer interrupt enable
  val UTIE   = UInt(1.W)   // User timer interrupt enable

  val MSIE   = UInt(1.W)   // Machine software interrupt enable
  val VSSIE  = UInt(1.W)   // Supervisor software interrupt enable
  val SSIE   = UInt(1.W)   // Supervisor software interrupt enable
  val USIE   = UInt(1.W)   // User software interrupt enable

}



// Machine counter-inhibit register (mcountinhibit) - 32 bits
class mcountinhibit extends Bundle {
  val CY   = UInt(1.W)    // Inhibit cycle counter
  val TM   = UInt(1.W)    // Inhibit timer counter
  val IR   = UInt(1.W)    // Inhibit retired instructions counter
  val WPRI = UInt(29.W)   // Reserved bits
}

class mcounteren extends Bundle {
  val CY   = UInt(1.W)    // Inhibit cycle counter
  val TM   = UInt(1.W)    // Inhibit timer counter
  val IR   = UInt(1.W)    // Inhibit retired instructions counter
  val WPRI = UInt(29.W)   // Reserved bits
}

// Machine scratch register (mscratch) - 32 bits
class mscratch extends Bundle {
  val scratch = UInt(32.W)  // Scratch register for machine mode
}

// Machine exception program counter (mepc) - 32 bits
class mepc extends Bundle {
  val PC = UInt(32.W)    // Program counter at the time of trap
}

// Machine cause register (mcause) - 32 bits
class mcause extends Bundle {
  val INTERRUPT = UInt(1.W)    // Interrupt flag
  val CODE      = UInt(31.W)   // Trap cause code
}

class mseccfgh extends Bundle{
  val NA = UInt(32.W)
}

class mstatush extends Bundle{
  val NA = UInt(32.W)
}

// Machine bad address register (mtval) - 32 bits
class mtval extends Bundle {
  val badaddr = UInt(32.W)     // Bad address encountered during trap
}

// Machine configuration pointer (mconfigptr) - 32 bits
class mconfigptr extends Bundle {
  val ptr = UInt(32.W)    // Configuration pointer for machine mode
}

// Machine environment configuration (menvcfg) - 32 bits
class menvcfg extends Bundle {
  val FIOM  = UInt(1.W)   // Fast I/O memory enable
  val CBIE  = UInt(1.W)   // Cache block invalidate enable
  val WPRI1 = UInt(30.W)  // Reserved bits
}

// Machine security configuration (mseccfg) - 32 bits
class mseccfg extends Bundle {
  val MML   = UInt(1.W)   // Machine memory lock
  val RLB   = UInt(1.W)   // Return from lower ring blocked
  val WPRI1 = UInt(30.W)  // Reserved bits
}




