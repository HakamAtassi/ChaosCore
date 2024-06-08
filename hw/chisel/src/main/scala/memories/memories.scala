// I copied these from the internet. No license applies

package ChaosCore

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

// Classic SRAM.
// 1 R/W port. 
/*
class ReadWriteSmem(depth:Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val wr_en = Input(Bool())
    val addr = Input(UInt(log2Ceil(depth).W))
    val data_in = Input(UInt(width.W))
    val data_out = Output(UInt(width.W))
  })

  val mem = SyncReadMem(depth, UInt(width.W))
  io.data_out := DontCare
  when(io.enable) {
    when (io.wr_en) { mem.write(io.addr, io.data_in) }
      .otherwise    { io.data_out := mem.read(io.addr, io.enable) }
  }
}
*/

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
  io.readDataA := mem.read(io.addrA, io.writeEnableA) // FIXME: write enable???

  // Operations for Port B
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
  io.readDataB := mem.read(io.addrB, io.writeEnableB) // FIXME: write enable???
}



class ROB_mem[T <: Data](dataType: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    // Port A
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(dataType)
    val writeEnableA = Input(Bool())
    val readDataA = Output(dataType)

    // Port B
    val addrB = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(dataType)
    val writeEnableB = Input(Bool())
    val readDataB = Output(dataType)

    // Port C   (read only)
    val addrC = Input(UInt(log2Ceil(depth).W))
    val readDataC = Output(dataType)
  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, dataType)

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }
  io.readDataA := mem.read(io.addrA, 1.B)

  // Operations for Port B
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
  io.readDataB := mem.read(io.addrB, 1.B)

  io.readDataC := mem.read(io.addrC, 1.B)

}


class ROB_shared_mem(parameters:Parameters, depth: Int) extends Module { // 2 read, 1 write
  val io = IO(new Bundle {
    
    // Port A (write only)
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(new ROB_shared(parameters))
    val writeEnableA = Input(Bool())

    // Port B (read only)
    val addrB = Input(UInt(log2Ceil(depth).W))
    val readDataB = Output(new ROB_shared(parameters))

    // Port C (read only)
    val addrC = Input(UInt(log2Ceil(depth).W))
    val readDataC = Output(new ROB_shared(parameters))

  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, new ROB_shared(parameters))

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }

  io.readDataB := mem.read(io.addrB, 1.B)
  io.readDataC := mem.read(io.addrC, 1.B)

}

// make this parameterizable
class ROB_WB_mem(parameters:Parameters, depth: Int) extends Module { // 1 read, 1 write (allocate) + N write(FUs)
  val io = IO(new Bundle {
    // Port A (write only/Allocate)
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(new ROB_WB(parameters))
    val writeEnableA = Input(Bool())

    // FU access
    val addrB = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(new ROB_WB(parameters))
    val writeEnableB = Input(Bool())

    val addrC = Input(UInt(log2Ceil(depth).W)) //(write only/FU1)
    val writeDataC = Input(new ROB_WB(parameters))
    val writeEnableC = Input(Bool())

    val addrD = Input(UInt(log2Ceil(depth).W)) //(write only/FU2)
    val writeDataD = Input(new ROB_WB(parameters))
    val writeEnableD = Input(Bool())

    val addrE = Input(UInt(log2Ceil(depth).W)) //(write only/FU3)
    val writeDataE = Input(new ROB_WB(parameters))
    val writeEnableE = Input(Bool())
    
    // Port C (read only)
    val addrG = Input(UInt(log2Ceil(depth).W))
    val readDataG = Output(new ROB_WB(parameters))

  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, new ROB_WB(parameters))


  when(io.writeEnableA) { // Allocate
    mem.write(io.addrA, io.writeDataA)
  }

  when(io.writeEnableB) { // FU1
    mem.write(io.addrB, io.writeDataB)
  }

  when(io.writeEnableC) { // FU2
    mem.write(io.addrC, io.writeDataC)
  }

  when(io.writeEnableD) { // FU3
    mem.write(io.addrD, io.writeDataC)
  }

  when(io.writeEnableE) { // FU4
    mem.write(io.addrE, io.writeDataE)
  }

  io.readDataG := mem.read(io.addrG, 1.B)

  dontTouch(io.readDataG)

}

class ROB_entry_mem(parameters:Parameters, depth: Int) extends Module { // 1 read, 1 write
  val io = IO(new Bundle {
    
    // Port A (write only)
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(new ROB_entry(parameters))
    val writeEnableA = Input(Bool())

    // Port C (read only)
    val addrB = Input(UInt(log2Ceil(depth).W))
    val readDataB = Output(new ROB_entry(parameters))

  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, new ROB_entry(parameters))

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }

  io.readDataB := mem.read(io.addrB, 1.B)

}

