

package ChaosCore

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class comp extends Module{
    val io = IO(new Bundle{
        val a = Input(UInt(32.W))
        val b = Input(UInt(32.W))
        val c = Output(UInt(64.W))
    })

    io.c := RegNext(RegNext(io.a) * RegNext(io.b))

}