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

    // FIXME: Clean up this last one...
    val branchPortCount = getBranchPortCount(coreParameters)



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
        val INT_producers                 =   Vec(INT_producer_count, Decoupled(new FU_output(coreParameters)))

        val FP_producers = if (coreConfig.contains("F")) Some(Vec(FP_producer_count, Decoupled(new FU_output(coreParameters)))) else None

    }); dontTouch(io)

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////
    val INT_RS: Seq[age_RS] = Seq.tabulate(INT_consumer_count) { w => Module(new age_RS(coreParameters)(WBPortCount=INT_producer_count))}  // init distributed reservation stations for int operations
    val FP_RS: Seq[age_RS]  = if (coreConfig.contains("F")) Seq.tabulate(FP_producer_count) { w => Module(new age_RS(coreParameters)(WBPortCount=FP_producer_count))} else Seq()

    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////
    val execution_engine = Module(new execution_engine(coreParameters))

    execution_engine.io.backend_packet  <> io.backend_packet
    execution_engine.io.reserved_pointers  <> io.reserved_pointers
    execution_engine.io.reserve  <> io.backend_packet

    ////////////////////
    // REGISTER FILES //
    ////////////////////
    // Both PRFs need an extra write port to write back the possible conversions from INT to FP and vice versa

    val INT_PRF = Module(new nReadmWriteLVT(
        n = (INT_consumer_count) * 2, // Read (only for INT FUs and AGU)
        m = (INT_producer_count),   // write (INT FUs + memory AGU + 1 for FPU conversion output)
        depth = physicalRegCount,
        width = 32
    ))

    val FP_PRF =
    if (coreConfig.contains("F"))
        Some(Module(new nReadmWriteLVT(
            n = (FP_consumer_count) * 3,    // each FPU has potentially 3 inputs (RS1, RS2, RS3)
            m =  (FP_producer_count),
            depth = physicalRegCount,
            width = 32
        )))
    else None

    //////////////
    // ALLOCATE //
    //////////////
    val backend_can_allocate =  INT_RS.map(_.io.backend_packet.map(_.ready).foldLeft(true.B)(_ && _)).foldLeft(true.B)(_ && _) && // all INT RS ready
                                FP_RS.map(_.io.backend_packet.map(_.ready).foldLeft(true.B)(_ && _)).foldLeft(true.B)(_ && _) && // handle optional FP RS
                                execution_engine.io.reserve.map(_.ready).foldLeft(true.B)(_ && _)  // MOB ready

    
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




    def reg_read_and_fire(sources_per_port:Int)(
        rsSeq: Seq[age_RS],
        prf: nReadmWriteLVT,
        FU_input: Seq[DecoupledIO[read_decoded_instruction]],
        offset: Int = 0
    ): Unit = {

        assert(sources_per_port == 2 || sources_per_port == 3, s"souces per port can only be 2 or 3. Got $sources_per_port")
        rsSeq.zipWithIndex.foreach { case (rs, i) =>

            val read_decoded_instruction   =   WireInit(0.U.asTypeOf(new read_decoded_instruction(coreParameters)))
            read_decoded_instruction.decoded_instruction := RegNext(rs.io.RF_inputs.bits)

            // RS <> PRF
            prf.io.raddr(offset + i * sources_per_port)     := rs.io.RF_inputs.bits.RS1
            prf.io.raddr(offset + i * sources_per_port + 1) := rs.io.RF_inputs.bits.RS2
            read_decoded_instruction.RS1_data := prf.io.rdata(offset + i * sources_per_port)
            read_decoded_instruction.RS2_data := prf.io.rdata(offset + i * sources_per_port + 1)

            if(sources_per_port == 3){
                prf.io.raddr(offset + i * sources_per_port + 2) := rs.io.RF_inputs.bits.RS2
                read_decoded_instruction.RS3_data := prf.io.rdata(offset + i * sources_per_port + 2)
            }

            // Send off instruction to execution engine.
            FU_input(i).valid := RegNext(rs.io.RF_inputs.valid)
            FU_input(i).bits  <> read_decoded_instruction
        }
    }

    // Connect the RS ready signals to the execution engine.
    def assign_ready(rsSeq: Seq[age_RS], FU_input: Seq[DecoupledIO[read_decoded_instruction]]): Unit = {
        rsSeq.zipWithIndex.foreach { case (rs, i) =>
            // RS ready <> FU ready //
            rs.io.RF_inputs.ready := FU_input(i).ready
        }
    }

    // why does this have RS?
    def assign_WB(prf: nReadmWriteLVT, FU_output:Seq[DecoupledIO[FU_output]]): Unit = {
        // write back FU produced results to PRF
        FU_output.zipWithIndex.foreach{ case(fu, i) =>
            prf.io.waddr(i) := fu.bits.PRD
            prf.io.wen(i)   := fu.valid && FU_output(i).bits.RD_valid
            prf.io.wdata(i) := fu.bits.RD_data
        }


    }


    def wakeup_RS(rsSeq: Seq[age_RS], producers: Seq[DecoupledIO[FU_output]]): Unit = {
        rsSeq.foreach ( rs => 
            // Connect each RS's FU_outputs ports with the corresponding producer from the view.
            producers.zipWithIndex.foreach { case (producer, j) =>
                rs.io.FU_outputs(j) <> producers(j)
            }
        )
    }

    // CONNECT INT + MEM //
    // Since INT and MEM share a bunch of structures, it makes sense to perform their connection logic together. This is to help with the indexing of the various involved structures
    connect_allocation(rsSeq = INT_RS ++ FP_RS)  // Connects frontend "backend packet" to reservation stations
    reg_read_and_fire(sources_per_port = 2)(rsSeq = INT_RS, prf = INT_PRF, FU_input = execution_engine.io.INT_FU_input)   // Connects output of reservation stations to register read components
    assign_ready(INT_RS, execution_engine.io.INT_FU_input)
    assign_WB(prf=INT_PRF, FU_output=execution_engine.io.INT_producers)  // Last FP only for conversion WB because it produces its (possibly)
    wakeup_RS(rsSeq = INT_RS, producers = execution_engine.io.INT_producers)

    // CONNECT FP //
    //connect_allocation(FP_RS)
    if(coreConfig.contains("F")){
        reg_read_and_fire(sources_per_port = 3)(rsSeq = FP_RS, prf = FP_PRF.get, FU_input = execution_engine.io.FP_FU_input)
        assign_ready(FP_RS, execution_engine.io.FP_FU_input)
        assign_WB(prf=FP_PRF.get, FU_output=execution_engine.io.FP_producers.get)

        wakeup_RS(rsSeq = FP_RS, producers = execution_engine.io.FP_producers.get)
    }


    for(i <- 0 until fetchWidth){
        INT_RS(3).io.backend_packet(i).bits.MOB_index := execution_engine.io.reserved_pointers(i).bits
    }


    // CONNECT BRANCH UNITS TO PC FILE (in ROB)
    for (i <- 0 until INT_consumer_count) {
        if (INT_FUParamSeq(i).supportsBranch) {
            val PC_file_port_index = INT_FUParamSeq.take(i).count(_.supportsBranch)
            io.PC_file_exec_addr(PC_file_port_index) := INT_RS(i).io.RF_inputs.bits.ROB_index
            execution_engine.io.INT_FU_input(i).bits.fetch_PC := io.PC_file_exec_data(PC_file_port_index)
        }
    }



    // connect INT FU

    if(coreConfig.contains("F")){
        execution_engine.io.FP_producers.zipWithIndex.foreach{case(producer, i) => io.FP_producers.get(i) <> producer}
    }
    execution_engine.io.INT_producers.zipWithIndex.foreach{case(producer, i) => io.INT_producers(i) <> producer}
    

    ////////////////
    // MISC CASES //
    ////////////////
    // handle conversions
    if(coreConfig.contains("F")){
        // connect the INT2FP unit to a PRF WB port (the last one)
        // connect that FU's conversion port to the corresponding PRF port
        //FP_PRF.get.io.waddr.last  :=    execution_engine.io.INT_FU_output.last.bits.PRD
        //FP_PRF.get.io.wen.last    :=    0.U //execution_engine.io.FU_output(int2fpIndex).valid && execution_engine.io.FU_output(int2fpIndex).bits.RD_valid
        //FP_PRF.get.io.wdata.last  :=    0.U //execution_engine.io.FU_output(int2fpIndex).bits.RD_data


        // Do the same to the FP2INT unit
        // connect that FU's conversion port to the corresponding PRF port
        //INT_PRF.io.waddr.last  :=    execution_engine.io.FP_FU_output.last.bits.PRD
        //INT_PRF.io.wen.last    :=    0.U //execution_engine.io.FU_output(fp2intIndex).valid && execution_engine.io.FU_output(fp2intIndex).bits.RD_valid
        //INT_PRF.io.wdata.last  :=    0.U //execution_engine.io.FU_output(fp2intIndex).bits.RD_data
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





    ////////////
    // COMMIT //
    ////////////
    execution_engine.io.commit           <> io.commit
    INT_RS.foreach(_.io.commit <> io.commit)
    FP_RS.foreach(_.io.commit <> io.commit)

    ///////////
    // FLUSH //
    ///////////

    INT_RS.foreach(_.io.flush <> io.flush)
    FP_RS.foreach(_.io.flush <> io.flush)

    execution_engine.io.flush       <>  io.flush

    //////////
    // MISC //
    //////////
    io.reserved_pointers            <>  execution_engine.io.reserved_pointers
    io.backend_memory_request       <>  execution_engine.io.backend_memory_request
    io.backend_memory_response      <>  execution_engine.io.backend_memory_response

}
