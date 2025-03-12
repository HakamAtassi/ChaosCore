/* ------------------------------------------------------------------------------------
* Filename: RF.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: The top leve of the backend. Includes everything from allocation to register writeback.
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

class backend(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    // these functions could use a lot of work
    val portCount = getPortCount(coreParameters)    // number of ports total
    val memoryPortCount = FUParamSeq.count(_.supportsAddressGeneration)
    val FPPortCount  = FPUportCount 
    val INTPortCount = ALUportCount // FIXME: why is this renamed here?

    val branchPortCount = getBranchPortCount(coreParameters)
    val nonMemoryPortCount = INTPortCount + FPUportCount


    val io = IO(new Bundle{
        // FLUSH //
        val flush                       =   Flipped(ValidIO(new flush(coreParameters)))

        // pointers to MOB entries for updating later
        val reserved_pointers           =   Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val backend_memory_response     =   Flipped(Decoupled(new backend_memory_response(coreParameters))) // From MEM
        val backend_memory_request      =   Decoupled(new backend_memory_request(coreParameters))     // To MEM

        // COMMIT // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Vec(branchPortCount, Output(UInt(log2Ceil(ROBEntries).W)))
        val PC_file_exec_data           =   Vec(branchPortCount, Input(UInt(32.W)))

        // ALLOCATE //
        val fetch_PC                    =   Input(UInt(32.W))  // DEBUG
        val backend_packet              =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))


        val MOB_output                  =   Decoupled(new FU_output(coreParameters))                                               // broadcast load data

        ////////////////
        // INTERRUPTS //
        ////////////////

        // ibex naming convention
        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi

        // UPDATE //
        val FU_outputs                  =   Vec(portCount, Decoupled(new FU_output(coreParameters)))


    }); dontTouch(io)


    val CSR_port = IO(Output(new CSR_out(coreParameters)))


    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////
    // FIXME: add 1 to this if there is FP (conversion)!
    // FIXME: make the above fixme based on config
    val INT_RS: Seq[age_RS] = Seq.tabulate(INTPortCount) { w => Module(new age_RS(coreParameters)(INTPortCount + MOBWBPortCount + 1))}  // init distributed reservation stations for int operations
    val MEM_RS: Seq[age_RS] = Seq.tabulate(1) { w => Module(new age_RS(coreParameters)(INTPortCount + MOBWBPortCount + 1))}  // init distributed reservation stations for int operations
    val FP_RS: Seq[age_RS]  = if (coreConfig.contains("F")) Seq.tabulate(FPPortCount) { w => Module(new age_RS(coreParameters)(FPPortCount + MOBWBPortCount + 1))} else Seq()

    /////////
    // MOB //
    /////////
    val MOB   =  Module(new simple_MOB(coreParameters))

    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////
    val execution_engine = Module(new execution_engine(coreParameters))

    ////////////////////
    // REGISTER FILES //
    ////////////////////
    // Both PRFs need an extra write port to write back the possible conversions from INT to FP and vice versa

    val INT_PRF = Module(new nReadmWriteLVT(
        n = portCount * 2,
        m = portCount + (if (coreConfig.contains("F")) 1 else 0),
        depth = physicalRegCount,
        width = 32
    ))
    val FP_PRF =
    if (coreConfig.contains("F"))
        Some(Module(new nReadmWriteLVT(
            n = FPPortCount * 2,
            m = FPPortCount + (if (coreConfig.contains("F")) 1 else 0),
            depth = physicalRegCount,
            width = 32
        )))
    else None

    //////////////
    // ALLOCATE //
    //////////////
    val backend_can_allocate =  MEM_RS(0).io.backend_packet.map(_.ready).foldLeft(true.B)(_ && _) &&  // mem RS ready
                                INT_RS.map(_.io.backend_packet.map(_.ready).foldLeft(true.B)(_ && _)).foldLeft(true.B)(_ && _) && // all INT RS ready
                                FP_RS.map(_.io.backend_packet.map(_.ready).foldLeft(true.B)(_ && _)).foldLeft(true.B)(_ && _) && // handle optional FP RS
                                MOB.io.reserve.map(_.ready).foldLeft(true.B)(_ && _)  // MOB ready

    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready        := backend_can_allocate
    }

    /////////////////////////
    // allocate RS entries //
    /////////////////////////

    def connect_allocation(rsSeq: Seq[age_RS]): Unit = {
        // connect each reservation station with all instruction inputs
        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            for (j <- 0 until io.backend_packet.length) {
                rs.io.backend_packet(j).bits  := io.backend_packet(j).bits
                rs.io.backend_packet(j).valid := io.backend_packet(j).valid && (io.backend_packet(j).bits.assigned_port === i.U)
            }
        }
    }


    def reg_read_and_fire(
        rsSeq: Seq[age_RS],
        prf: nReadmWriteLVT,
        FU_input: Vec[DecoupledIO[read_decoded_instruction]],
        offset: Int = 0
    ): Unit = {
        val read_decoded_instruction   =   Wire(new read_decoded_instruction(coreParameters))

        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            // RS <> PRF
            prf.io.raddr(offset + i * 2)     := rs.io.RF_inputs.bits.RS1
            prf.io.raddr(offset + i * 2 + 1) := rs.io.RF_inputs.bits.RS2
            read_decoded_instruction.RS1_data := prf.io.rdata(offset + i * 2)
            read_decoded_instruction.RS2_data := prf.io.rdata(offset + i * 2 + 1)

            // Send off instruction to execution engine.
            read_decoded_instruction.decoded_instruction := RegNext(rs.io.RF_inputs.bits)
            FU_input(i).valid := RegNext(rs.io.RF_inputs.valid)
            FU_input(i).bits  <> read_decoded_instruction
        }
    }

    // Connect the RS ready signals to the execution engine.
    def assign_ready(rsSeq: Seq[age_RS], FU_input: Vec[DecoupledIO[read_decoded_instruction]]): Unit = {
        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            // RS ready <> FU ready //
            rs.io.RF_inputs.ready := FU_input(i).ready
        }
    }

    def assign_WB(rsSeq: Seq[age_RS], prf: nReadmWriteLVT, FU_output:Vec[DecoupledIO[FU_output]]): Unit = {
        // write back FU produced results to PRF
        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            prf.io.waddr(i) := FU_output(i).bits.PRD
            prf.io.wen(i)   := FU_output(i).valid && FU_output(i).bits.RD_valid
            prf.io.wdata(i) := FU_output(i).bits.RD_valid
        }
    }


    // producers: Vec(INTPortCount, Decoupled(new FU_output(coreParameters)))
    def wakeup_RS(rsSeq: Seq[age_RS], producers: Seq[DecoupledIO[FU_output]]): Unit = {
        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            // Connect each RS's FU_outputs ports with the corresponding producer from the view.
            producers.zipWithIndex.foreach { case (producer, j) =>
                rs.io.FU_outputs(j) <> producers(j)
            }
        }
    }


    // CONNECT INT //
    connect_allocation(INT_RS)
    reg_read_and_fire(rsSeq = INT_RS, prf = INT_PRF, FU_input = execution_engine.io.INT_FU_input)
    assign_ready(INT_RS, execution_engine.io.INT_FU_input)
    assign_WB(rsSeq=INT_RS, prf=INT_PRF, FU_output=execution_engine.io.INT_FU_output)

    // CONNECT FP //
    connect_allocation(FP_RS)
    reg_read_and_fire(rsSeq = FP_RS, prf = FP_PRF.get, FU_input = execution_engine.io.FP_FU_input)
    assign_ready(FP_RS, FU_input = execution_engine.io.FP_FU_input)
    assign_WB(rsSeq=FP_RS, prf=FP_PRF.get, FU_output=execution_engine.io.FP_FU_output)

    // CONNECT MEM //
    connect_allocation(MEM_RS)
    reg_read_and_fire(rsSeq = MEM_RS, prf = INT_PRF, FU_input = execution_engine.io.MEM_FU_input, offset = INTPortCount*2)
    assign_ready(MEM_RS, FU_input = execution_engine.io.MEM_FU_input)
    assign_WB(rsSeq=MEM_RS, prf=INT_PRF, FU_output=execution_engine.io.MEM_FU_output)  // Last FP only for conversion WB because it produces its (possibly)


    // CONNECT WAKEUP SIGNALS //
    val int_producers = Seq(
        execution_engine.io.INT_FU_output.toSeq,
        execution_engine.io.MEM_FU_output.toSeq,
        Seq(execution_engine.io.FP_FU_output.last) // `last` is already a single element, so wrap it in Seq
    ).flatten

    val float_producers = Seq(
    execution_engine.io.FP_FU_output.toSeq,
    execution_engine.io.MEM_FU_output.toSeq,
    Seq(execution_engine.io.INT_FU_output.last) // Wrap `last` in Seq
    ).flatten


    wakeup_RS(rsSeq = INT_RS, producers = int_producers)
    wakeup_RS(rsSeq = MEM_RS, producers = int_producers)
    wakeup_RS(rsSeq = FP_RS, producers = float_producers)

    // reserve mem ops
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }

    // inform MEM_RS about location of allocated entries for mem ops for AGU WB
    for(i <- 0 until fetchWidth){
        MEM_RS(0).io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }

    // CONNECT BRANCH UNITS TO PC FILE (in ROB)
    for (i <- 0 until portCount) {
        if (FUParamSeq(i).supportsBranch) {
            val PC_file_port_index = FUParamSeq.take(i).count(_.supportsBranch)
            io.PC_file_exec_addr(PC_file_port_index) := INT_RS(i).io.RF_inputs.bits.ROB_index
            execution_engine.io.INT_FU_input(i).bits.fetch_PC := io.PC_file_exec_data(PC_file_port_index)
        }
    }

    for(i <- 0 until fetchWidth){
        MEM_RS(0).io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }

    // Connect top level FU_outputs 
    Seq(
        execution_engine.io.INT_FU_output.toSeq,
        execution_engine.io.FP_FU_output.toSeq,
        execution_engine.io.MEM_FU_output.toSeq
    ).flatten.zipWithIndex.foreach { case (fu, i) =>
        io.FU_outputs(i) <> fu
    }



    ////////////////
    // MISC CASES //
    ////////////////
    // handle conversions
    if(coreConfig.contains("F")){
        // connect the INT2FP unit to a PRF WB port (the last one)
        // connect that FU's conversion port to the corresponding PRF port
        val int2fpIndex = FUParamSeq.indexWhere(_.supportsINT2FP)
        //FP_PRF.get.io.waddr.last  :=    execution_engine.io.FU_output(int2fpIndex).bits.PRD
        //FP_PRF.get.io.wen.last    :=    execution_engine.io.FU_output(int2fpIndex).valid && execution_engine.io.FU_output(int2fpIndex).bits.RD_valid
        //FP_PRF.get.io.wdata.last  :=    execution_engine.io.FU_output(int2fpIndex).bits.RD_data


        // Do the same to the FP2INT unit
        // connect that FU's conversion port to the corresponding PRF port
        val fp2intIndex = FUParamSeq.indexWhere(_.supportsFP2INT)
        //INT_PRF.io.waddr.last  :=    execution_engine.io.FU_output(fp2intIndex).bits.PRD
        //INT_PRF.io.wen.last    :=    execution_engine.io.FU_output(fp2intIndex).valid && execution_engine.io.FU_output(fp2intIndex).bits.RD_valid
        //INT_PRF.io.wdata.last  :=    execution_engine.io.FU_output(fp2intIndex).bits.RD_data
    }
    
    ////////////////
    // INTERRUPTS //
    ////////////////
    execution_engine.io.irq_software_i                 := io.irq_software_i    
    execution_engine.io.irq_timer_i                    := io.irq_timer_i
    execution_engine.io.irq_external_i                 := io.irq_external_i
    execution_engine.io.debug_req_i                    := io.debug_req_i
    execution_engine.io.irq_nm_i                       := io.irq_nm_i
    

    // Output CSR_port values
    execution_engine.CSR_port <> CSR_port

    ////////////////
    // AGU <> MOB //
    ////////////////
    MOB.io.fetch_PC <> io.fetch_PC
    io.MOB_output   <> MOB.io.MOB_output   // this updates reg status etc...


    ////////////
    // COMMIT //
    ////////////
    execution_engine.io.commit           <> io.commit
    MOB.io.commit                        <> io.commit
    MEM_RS(0).io.commit                     <> io.commit
    INT_RS.foreach(_.io.commit <> io.commit)
    FP_RS.foreach(_.io.commit <> io.commit)

    ///////////
    // FLUSH //
    ///////////

    INT_RS.foreach(_.io.flush <> io.flush)
    FP_RS.foreach(_.io.flush <> io.flush)
    MEM_RS(0).io.flush <> io.flush
    MOB.io.flush    <> io.flush

    execution_engine.io.flush       <>  io.flush

    //////////
    // MISC //
    //////////

    io.reserved_pointers            <>  MOB.io.reserved_pointers
    io.backend_memory_request       <>  MOB.io.backend_memory_request
    io.backend_memory_response      <>  MOB.io.backend_memory_response

}
