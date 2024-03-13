// I copied these from the internet. No license applies

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

class ReadWriteSmem extends Module {
  val width: Int = 32
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val write = Input(Bool())
    val addr = Input(UInt(10.W))
    val dataIn = Input(UInt(width.W))
    val dataOut = Output(UInt(width.W))
  })

  val mem = SyncReadMem(1024, UInt(width.W))
  // Create one write port and one read port
  mem.write(io.addr, io.dataIn)
  io.dataOut := mem.read(io.addr, io.enable)
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

  println(s"${name},\twidth: ${width}, depth: ${depth}")

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
