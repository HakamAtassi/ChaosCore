// I copied these from the internet. No license applies

package ChaosCore

import chisel3._
import circt.stage.ChiselStage 
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


class ROB_shared_mem(coreParameters:CoreParameters, depth: Int) extends Module { // 2 read, 1 write
  val io = IO(new Bundle {
    
    // Port A (write only)
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(new ROB_shared(coreParameters))
    val writeEnableA = Input(Bool())

    // Port B (read only)
    val addrB = Input(UInt(log2Ceil(depth).W))
    val readDataB = Output(new ROB_shared(coreParameters))

    // Port C (read only)
    val addrC = Input(UInt(log2Ceil(depth).W))
    val readDataC = Output(new ROB_shared(coreParameters))

  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, new ROB_shared(coreParameters))

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }

  io.readDataB := mem.read(io.addrB, 1.B)
  io.readDataC := mem.read(io.addrC, 1.B)

}


class ROB_WB_mem(coreParameters: CoreParameters, depth: Int) extends Module {
  // This module represents a memory structure with 1 allocate port and N write ports for Function Units (FUs).
  // It allows reading from one port and flushing the memory content.
  import coreParameters._

  val io = IO(new Bundle {
    // Port A (write only/Allocate): 


    val allocateAddr = Input(UInt(log2Ceil(depth).W)) 
    val allocateData = Input(new ROB_WB(coreParameters)) 
    val allocateWriteEnable = Input(Bool()) 

    // FU access: Each FU has its own write port to update memory.
    // WB ports
    val WBAddr          = Input(Vec(portCount, UInt(log2Ceil(depth).W)))
    val WBData          = Input(Vec(portCount, new ROB_WB(coreParameters)))
    val WBWriteEnable   = Input(Vec(portCount, Bool()))

    // Port C (read only): Used for reading data from memory.
    val commitAddr     = Input(UInt(log2Ceil(depth).W)) 
    val commitReadData = Output(new ROB_WB(coreParameters)) 

    val flush = Input(Bool()) // Signal to flush (reset) the entire memory.
  })

  // Memory declaration: A Vec of registers to hold ROB_WB entries.
  val mem = RegInit(VecInit(Seq.fill(depth)(0.U.asTypeOf(new ROB_WB(coreParameters)))))

  when(io.allocateWriteEnable) {
    mem(io.allocateAddr) := io.allocateData
  }

  for(port <- 0 until fetchWidth){
    when(io.WBWriteEnable(port)) {
      mem(io.WBAddr(port)) := io.WBData(port)
    }
  }



  // Flopping the read data to maintain 1 cycle latency.
  val readDataReg = RegNext(mem(io.commitAddr))
  io.commitReadData := readDataReg

  // Flush operation: Resets all memory entries to 0 when flush is asserted.
  when(io.flush) {
    mem := VecInit(Seq.fill(depth)(0.U.asTypeOf(new ROB_WB(coreParameters))))
  }

  // dontTouch(io) // Uncomment if you want to prevent Chisel from optimizing or renaming the IO bundle.
}

class ROB_entry_mem(coreParameters:CoreParameters, depth: Int) extends Module { // 1 read, 1 write
  val io = IO(new Bundle {
    
    // Port A (write only)
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(new ROB_entry(coreParameters))
    val writeEnableA = Input(Bool())

    // Port C (read only)
    val addrB = Input(UInt(log2Ceil(depth).W))
    val readDataB = Output(new ROB_entry(coreParameters))

  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, new ROB_entry(coreParameters))

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }

  io.readDataB := mem.read(io.addrB, 1.B)

}

