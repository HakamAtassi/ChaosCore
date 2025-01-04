package ChaosCore

import chisel3._
import chisel3.util._


// The LVT "Banks"
// Just a series of n read 1 write memories
class nRead1Write(n: Int, depth: Int, width: Int) extends Module {
  val addrW = log2Ceil(depth) // Address width derived from depth
  val io = IO(new Bundle {
    val waddr = Input(UInt(addrW.W))
    val wdata = Input(UInt(width.W))
    val wen = Input(Bool())

    val raddr = Input(Vec(n, UInt(addrW.W)))
    val rdata = Output(Vec(n, UInt(width.W)))
  })

  // a series of dual ported memories
  // 1 memory per read port
  // all writes tied
  // writes forwarded



  // Create n memories, one for each read port
  val memories = Seq.fill(n)(SyncReadMem(depth, UInt(width.W)))

  for (mem <- memories) {
    when(io.wen) {
      mem.write(io.waddr, io.wdata)
    }
  }

  // output+forward data
  io.rdata := VecInit(memories.zip(io.raddr).map { case (mem, addr) => Mux(RegNext(io.waddr===addr && io.wen), RegNext(io.wdata), mem.read(addr))})
}


class nReadmWriteLVT(n: Int, m: Int, depth: Int, width: Int) extends Module {
  val addrW: Int = log2Ceil(depth)

  val io = IO(new Bundle {
    val waddr = Input(Vec(m, UInt(addrW.W))) // Write addresses for m write ports
    val wdata = Input(Vec(m, UInt(width.W))) // Write data for m write ports
    val wen = Input(Vec(m, Bool()))         // Write enables for m write ports

    val raddr = Input(Vec(n, UInt(addrW.W))) // Read addresses for n read ports
    val rdata = Output(Vec(n, UInt(width.W))) // Read data for n read ports
  })

  ///////////////////
  // LVT TABLE R/W //
  ///////////////////

  // LVT table stores the bank index of the most recent write for that address

  val LVTTable = RegInit(VecInit(Seq.fill(depth)(0.U(log2Ceil(m).W))))  // LVT table itself
  val LVTTableOut = Reg(Vec(n, UInt(log2Ceil(m).W)))                    // read LVT for writes

  // update LVT mem on writes
  for (i <- 0 until m) {
    when(io.wen(i)) {
      LVTTable(io.waddr(i)) := i.U 
    }
  }

  // read LVT and forward as needed (write first)
  for (i <- 0 until n) {
    LVTTableOut(i) := LVTTable(io.raddr(i)) // Default: read from the table
    for (j <- 0 until m) {
      when((io.waddr(j) === io.raddr(i)) && io.wen(j)) {
        LVTTableOut(i) := j.U 
      }
    }
  }


  
  // each LVT bank is just an nRead1Write memory
  val LVTBanks = Seq.fill(m)(Module(new nRead1Write(n, depth, width)))

  // each LVT memory performs that port's write, but does ALL reads
  for (i <- 0 until m) {
    val bank = LVTBanks(i)
    bank.io.waddr := io.waddr(i)
    bank.io.wdata := Mux(io.waddr(i) === 0.U, 0.U, io.wdata(i)) //x0 always 0 
    bank.io.wen := io.wen(i)
    bank.io.raddr := io.raddr
  }

  // Output Mux: Select data from the appropriate bank for each read port
  //for (i <- 0 until n) {
    //val selectedBankIndex = LVTTableOut(i)
    //io.rdata(i) := LVTBanks.zipWithIndex.foldRight(0.U(width.W)) {
        //case ((bank, index), default) =>
        //Mux(selectedBankIndex === index.U, bank.io.rdata(i), default)
    //}
  //}

  // each output port has an associated bank value (LVTTableOut)
  for (i <- 0 until n) {  // for each output read port
    val selectedBankIndex = LVTTableOut(i)
    io.rdata(i) := 0.U
    for(j <- 0 until m){  // search banks
      val bank = LVTBanks(j)
      when(j.U === selectedBankIndex){
        io.rdata(i) := bank.io.rdata(i) 
      }

    }
    
      //LVTBanks.zipWithIndex.foldRight(0.U(width.W)) {
        //case ((bank, index), default) =>
        //Mux(selectedBankIndex === index.U, bank.io.rdata(i), default)
    //}
  }

}