// I copied these from the internet. No license applies

package ChaosCore

import chisel3._
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

class ReadWriteSmem(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val wr_en = Input(Bool())
    val addr = Input(UInt(log2Ceil(depth).W))
    val data_in = Input(UInt(width.W))
    val data_out = Output(UInt(width.W))
  })

  // Create a memory array
  val ram = Mem(depth, UInt(width.W))

  // Create a register to hold the output data
  val dataOut = Reg(UInt(width.W))

    when(io.enable) {
      when(io.wr_en) {
        ram.write(io.addr, io.data_in)
      }
      dataOut := ram.read(io.addr)
    }

  io.data_out := dataOut
}

class icache_ReadWriteSmem[T <: Data](dataType: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val wr_en = Input(Bool())
    val addr = Input(UInt(log2Ceil(depth).W))
    val data_in = Input(dataType)
    val data_out = Output(dataType)
  })

  val mem = SyncReadMem(depth, dataType)

    when(io.enable) {
      when(io.wr_en) {
        mem.write(io.addr, io.data_in)
      }
    }

  io.data_out := mem.read(io.addr)

}


// Simple dual port memory
// 1 dedicated read, 1 dedicated write
class SDPReadWriteSmem(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())

    // Read
    val rd_addr = Input(UInt(log2Ceil(depth).W))
    val data_out = Output(UInt(width.W))
    
    // Write
    val wr_addr = Input(UInt(log2Ceil(depth).W))
    val wr_en = Input(Bool())
    val data_in = Input(UInt(width.W))
  })

  val mem = SyncReadMem(depth, UInt(width.W))
  io.data_out := DontCare

  /////////////////////
  // HAZARD HANDLING //
  /////////////////////

  val hazard_reg = RegInit(Bool(), 0.B)
  val din_buff = RegInit(UInt(width.W), 0.U)

  hazard_reg := (io.rd_addr === io.wr_addr) && io.wr_en
  din_buff := io.data_in

  //////////////////
  // READ & WRITE //
  //////////////////

  val data_out = Wire(UInt(width.W))
  data_out :=0.U

  when(io.enable) {
    when(io.wr_en) {
      mem.write(io.wr_addr, io.data_in)
    }

    data_out := mem.read(io.rd_addr, io.enable)
  }
  io.data_out := Mux(hazard_reg, din_buff, data_out) // Forward buffered data if hazard
}


class TrueDualPortMemory(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    // Port A
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(UInt(width.W))
    val writeEnableA = Input(Bool())
    val readDataA = Output(UInt(width.W))

    // Port B
    val addrB = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(UInt(width.W))
    val writeEnableB = Input(Bool())
    val readDataB = Output(UInt(width.W))
  })


  // Create the true dual-port memory
  val mem = SyncReadMem(depth, UInt(width.W))


  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }
  io.readDataA := mem.read(io.addrA, io.writeEnableA)

  // Operations for Port B
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
  io.readDataB := mem.read(io.addrB, io.writeEnableB)
}

