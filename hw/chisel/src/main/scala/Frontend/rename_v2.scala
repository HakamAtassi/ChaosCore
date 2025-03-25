/* ------------------------------------------------------------------------------------
* Filename: rename.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: The components required for superscalar renaming. 
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




class rename_v2(coreParameters:CoreParameters) extends Module{ 
    // rename latency: 1 cycle
    // flush latency: 1 cycle FIXME: this can be extended by making rename unavailable for a few cycles after a flush
    // but this would only work well with better speculation
    import coreParameters._

    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)



    val io = IO(new Bundle{
        // FLUSH
        val flush = Flipped(ValidIO(new flush(coreParameters)))

        // CHECKPOINT 
        val commit                          =   Flipped(ValidIO(new commit(coreParameters)))

        // Instruction input (decoded)
        val decoded_fetch_packet            =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        val INT_producers                 =   Vec(INT_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))
        val FP_producers                  = if (coreConfig.contains("F")) Some(Vec(FP_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))) else None

        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(coreParameters))
    }); dontTouch(io)




    // each instruction has an RS1/RS2/(RS3) and RD
    // for each instruction, just read those RS1/RS2/etc renamed values from the RAT
    // pop a value from the corresponding FL bit vector
    // update the RAT 
    // assign instruction output

    


    ////////////////////////
    // RENAME INGREDIENTS //
    ////////////////////////

    // reg version of components
    val INT_freelist            = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))
    val FP_freelist             = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))

    val INT_commit_freelist     = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))
    val FP_commit_freelist      = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))

    val INT_RAT                 = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))
    val FP_RAT                  = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))

    val FP_commit_RAT           = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))
    val INT_commit_RAT          = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))





    // 


    /**
    * Renames one source operand.
    *
    * Start: decoded register, valid bit, and ready (initially unknown).  
    * After rename: renamed source, propagated valid bit, and ready (from busy bit table).
    *
    * @param RAT The Register Alias Table.
    * @param rs1 The source operand to rename.
    * @return The renamed source operand.
    */
    case class Source(reg: UInt, valid: Bool)   //FIXME: this turned out to be totally useless. rewrite as ValidIO
    def rename_source(RAT: Vec[UInt])(src: Source): Source = {
        val renamed_reg:Source = Source(reg=Mux(src.reg === 0.U, 0.U, RAT(src.reg)), valid=src.valid)
        renamed_reg
    }


    /**
    * Renames a destination operand.
    *
    * Start: original destination.  
    * After rename: returns a new register from the free list, sets the busy bit to 0 (in use), and updates the RAT.
    *
    * @param RAT      The Register Alias Table.
    * @param freelist The free list for register allocation.
    * @param rd       The destination operand to rename.
    * @return The renamed destination operand.
    */
    def allocate_dest(RAT: Vec[UInt], freelist: Vec[Bool])(RD: UInt, index:UInt): UInt = {

        val free_PRD = SelectFirstNInt(freelist.asUInt, fetchWidth)(index)
        val do_rename = RD =/= 0.U
        val new_PRD = Mux(do_rename, Cat(0.U, free_PRD) + 1.U, 0.U)

        //printf("RD: %d free_PRD: %d, do_rename: %d, new_PRD %d\n", RD, free_PRD, do_rename, new_PRD);

        when(do_rename){
            freelist(new_PRD-1.U) := 0.U
            RAT(RD) := new_PRD
        }
        new_PRD
    }

    ////////////
    // RENAME //
    ////////////

    // read RS1, RS2, pop from free list, update RAT

    val renamed_decoded_fetch_packet_Q  = Module(new Queue(new decoded_fetch_packet(coreParameters), 16, flow=false, hasFlush=true, useSyncReadMem=false))
    val renamed_decoded_fetch_packet    = Wire(Decoupled(new decoded_fetch_packet(coreParameters)))

    dontTouch(renamed_decoded_fetch_packet)

    renamed_decoded_fetch_packet.bits       := io.decoded_fetch_packet.bits
    renamed_decoded_fetch_packet.valid      := io.decoded_fetch_packet.fire && !(io.flush.valid) 


    for ((insn, i) <- io.decoded_fetch_packet.bits.decoded_instruction.zipWithIndex) {
        val FP_sources = insn.FP_RS
        val FP_dest =  insn.FP_RD

        val og_RS1 = insn.RS1
        val og_RS2 = insn.RS2
        val og_RS3 = insn.RS3
        val og_RD  = insn.RD

        // rename sources
        when(!FP_sources){
            var RS1 = INT_RAT(og_RS1)
            var RS2 = INT_RAT(og_RS2)
            var PRDold = INT_RAT(og_RD) 

            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1 := RS1
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2 := RS2

            // Forward within packet...
            for(j <- 0 until i){
                val curr_insn = insn
                val prev_insn = renamed_decoded_fetch_packet.bits.decoded_instruction(j)

                val forward_RS1     = prev_insn.RD === curr_insn.RS1 && curr_insn.RS1_valid && prev_insn.RD_valid && !prev_insn.FP_RD && prev_insn.valid
                val forward_RS2     = prev_insn.RD === curr_insn.RS2 && curr_insn.RS2_valid && prev_insn.RD_valid && !prev_insn.FP_RD && prev_insn.valid
                
                when(forward_RS1){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1 := prev_insn.PRD
                }
                when(forward_RS2){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2 := prev_insn.PRD
                }
            }


        }.elsewhen(FP_sources){
            // TODO (just copy from above but for FP)
            var RS1 = FP_RAT(og_RS1)
            var RS2 = FP_RAT(og_RS2)
            var PRDold = FP_RAT(og_RD) 

            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1 := RS1
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2 := RS2

            // Forward within packet...
            for(j <- 0 until i){
                val curr_insn = insn
                val prev_insn = renamed_decoded_fetch_packet.bits.decoded_instruction(j)

                val forward_RS1     = prev_insn.RD === curr_insn.RS1 && curr_insn.RS1_valid && prev_insn.RD_valid && prev_insn.FP_RD && prev_insn.valid
                val forward_RS2     = prev_insn.RD === curr_insn.RS2 && curr_insn.RS2_valid && prev_insn.RD_valid && prev_insn.FP_RD && prev_insn.valid
                
                when(forward_RS1){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1 := prev_insn.PRD
                }
                when(forward_RS2){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2 := prev_insn.PRD
                }
            }
        }

        // rename dest
        when(!FP_dest){
            var PRDold = INT_RAT(og_RD) 

            renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := PRDold

            // Forward within packet...
            for(j <- 0 until i){
                val curr_insn = insn
                val prev_insn = renamed_decoded_fetch_packet.bits.decoded_instruction(j)

                val forward_PRDold  = prev_insn.RD === curr_insn.RD  && curr_insn.RD_valid  && prev_insn.RD_valid && !prev_insn.FP_RD && curr_insn.RD =/= 0.U && prev_insn.RD =/= 0.U && prev_insn.valid
                
                when(forward_PRDold){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := prev_insn.PRD
                }
            }


        }.elsewhen(FP_dest){
            // TODO (just copy from above but for FP)
            var PRDold = FP_RAT(og_RD) 

            renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := PRDold

            // Forward within packet...
            for(j <- 0 until i){
                val curr_insn = insn
                val prev_insn = renamed_decoded_fetch_packet.bits.decoded_instruction(j)

                val forward_PRDold  = prev_insn.RD === curr_insn.RD  && curr_insn.RD_valid  && prev_insn.RD_valid && prev_insn.FP_RD && curr_insn.RD =/= 0.U && prev_insn.RD =/= 0.U && prev_insn.valid
                
                when(forward_PRDold){
                    renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := prev_insn.PRD
                }
            }
        }








        // rename dest
        when(!FP_dest && og_RD =/= 0.U && insn.RD_valid && insn.valid && io.decoded_fetch_packet.fire){
            val PRD = allocate_dest(RAT=INT_RAT, freelist=INT_freelist)(RD=og_RD, index=i.U)
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRD := PRD
        }.elsewhen(FP_dest && og_RD =/= 0.U && insn.RD_valid && insn.valid && io.decoded_fetch_packet.fire){
            val RD = allocate_dest(RAT=FP_RAT, freelist=FP_freelist)(RD=og_RD, index=i.U)
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRD := RD
        }

    }

    ///////////////////
    // ASSIGN OUTPUT //
    ///////////////////
    renamed_decoded_fetch_packet_Q.io.enq                   <> renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_Q.io.enq.valid             := (renamed_decoded_fetch_packet.valid) && !io.flush.valid

    renamed_decoded_fetch_packet_Q.io.deq                   <> io.renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_Q.io.flush.get             := io.flush.valid



    io.decoded_fetch_packet.ready := (PopCount(INT_freelist.asUInt) >= fetchWidth.U) && (PopCount(FP_freelist.asUInt) >= fetchWidth.U) && io.renamed_decoded_fetch_packet.ready


    for(i <- 0 until INT_producer_count){
        io.INT_producers(i).ready := 1.B
    }

    for(i <- 0 until FP_producer_count){
        io.FP_producers.get(i).ready := 1.B
    }

    ////////////////
    // READY BITS //
    ////////////////
    // RS1/RS2/RS3 ready bits

    val INT_available_table     = RegInit(VecInit(Seq.fill(physicalRegCount)(0.B)))
    val FP_available_table      = RegInit(VecInit(Seq.fill(physicalRegCount)(0.B)))
    

    // update INT ready bits
    for(producer <- io.INT_producers){
        val PRD = producer.bits.PRD
        when(producer.valid && producer.bits.RD_valid){
            INT_available_table(PRD) := 1.B // update reg table
        }
    }

    // update FP ready bits
    for(producer <- io.FP_producers.get){
        val PRD = producer.bits.PRD
        when(producer.valid && producer.bits.RD_valid){
            FP_available_table(PRD) := 1.B // update reg table
        }
    }


    val INT_incomplete_producers = WireInit(VecInit(io.renamed_decoded_fetch_packet.bits.decoded_instruction.map(insn =>Mux(!insn.FP_RD && insn.RD_valid && insn.valid, insn.PRD, 0.U))))
    val FP_incomplete_producers = WireInit(VecInit(io.renamed_decoded_fetch_packet.bits.decoded_instruction.map(insn => Mux(insn.FP_RD && insn.RD_valid && insn.valid, insn.PRD, 0.U))))

    val INT_complete_producers = WireInit(VecInit(io.INT_producers.map(producer => Mux(producer.valid && producer.bits.RD_valid, producer.bits.PRD, 0.U))))
    val FP_complete_producers  = WireInit(VecInit(io.FP_producers.get.map(producer => Mux(producer.valid && producer.bits.RD_valid, producer.bits.PRD, 0.U))))

    dontTouch(INT_complete_producers)
    dontTouch(FP_complete_producers)
    dontTouch(INT_incomplete_producers)
    dontTouch(FP_incomplete_producers)

    /**
    * checks if a current source is being produced earlier in the fetch packet
    *
    * @param producers: Seq of valid PRDs for entire fetch width
    * @param RS: queried source reg
    * @param index: index of quered RS
    * @return 
    */
    def being_produced(producers:Vec[UInt])(RS:UInt, index:UInt): Bool = {
        val flag = Wire(Bool())
        flag := 0.B
        for(i <- 0 until fetchWidth){
            when(producers(i) === RS && i.U < index){
                flag := 1.B
            }
        }
        flag
    }


    // assign ready bits
    for((renamed_decoded_instruction, i) <- io.renamed_decoded_fetch_packet.bits.decoded_instruction.zipWithIndex){
        val FP_sources = renamed_decoded_instruction.FP_RS
        val FP_dest = renamed_decoded_instruction.FP_RD

        val RS1 = renamed_decoded_instruction.RS1
        val RS2 = renamed_decoded_instruction.RS2
        val RS3 = renamed_decoded_instruction.RS3

        val PRD = renamed_decoded_instruction.PRD
        val RD_valid = renamed_decoded_instruction.RD_valid

        val RS1_valid = renamed_decoded_instruction.RS1_valid
        val RS2_valid = renamed_decoded_instruction.RS2_valid
        val RS3_valid = renamed_decoded_instruction.RS3_valid


        // FIXME: this doesnt work as expecteed
        // INT_incomplete_producers = (0, 0, 8, 9) at one point in simulation, where the last instruction uses RS1=8 but marks it as ready for some reason. 
        when(!FP_sources){
            renamed_decoded_instruction.ready_bits.RS1_ready := (!RS1_valid || RS1 === 0.U || INT_complete_producers.contains(RS1) || (INT_available_table(RS1) && !being_produced(INT_incomplete_producers)(RS1, i.U)))
            renamed_decoded_instruction.ready_bits.RS2_ready := (!RS2_valid || RS2 === 0.U || INT_complete_producers.contains(RS2) || (INT_available_table(RS2) && !being_produced(INT_incomplete_producers)(RS2, i.U)))
            renamed_decoded_instruction.ready_bits.RS3_ready := 1.B

        }

        when(FP_sources){
            renamed_decoded_instruction.ready_bits.RS1_ready := (!RS1_valid || RS1 === 0.U || FP_complete_producers.contains(RS1) || (FP_available_table(RS1) && !being_produced(FP_incomplete_producers)(RS1, i.U)))
            renamed_decoded_instruction.ready_bits.RS2_ready := (!RS2_valid || RS2 === 0.U || FP_complete_producers.contains(RS2) || (FP_available_table(RS2) && !being_produced(FP_incomplete_producers)(RS2, i.U)))
            renamed_decoded_instruction.ready_bits.RS3_ready := (!RS3_valid || RS3 === 0.U || FP_complete_producers.contains(RS3) || (FP_available_table(RS3) && !being_produced(FP_incomplete_producers)(RS3, i.U)))
        }

        //test(i) := !INT_incomplete_producers.take(i).contains(RS1).B

        // reset FP
        when(!FP_dest && RD_valid && io.renamed_decoded_fetch_packet.fire){
            INT_available_table(PRD) := 0.B
        }

        when(FP_dest && RD_valid && io.renamed_decoded_fetch_packet.fire){
            FP_available_table(PRD) := 0.B
        }

    }



    ////////////
    // COMMIT //
    ////////////

    // commit
    for (i <- 0 until fetchWidth){
        when(io.commit.valid && io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
            INT_commit_RAT(io.commit.bits.insn_commit(i).bits.RD) := io.commit.bits.insn_commit(i).bits.PRD
        }
    }

    // flush/revert
    when(io.flush.valid){
        INT_RAT := INT_commit_RAT
        for(i <- 0 until fetchWidth){
            when(io.commit.valid && io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                INT_RAT(io.commit.bits.insn_commit(i).bits.RD) := io.commit.bits.insn_commit(i).bits.PRD
            }
        }
    }


    ///////////
    // FLUSH //
    ///////////


    // freelist stuff
    when(io.commit.valid){  // add to freelist
        for(i <- 0 until fetchWidth){
            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid && io.commit.bits.insn_commit(i).bits.RD =/= 0.U){    // dont add x0
                val commit_PRDold = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRDold := (io.commit.bits.insn_commit(i).bits.PRDold - 1.U)

                INT_commit_freelist(commit_PRDold) := 1.B
                INT_freelist(commit_PRDold) := 1.B
            }

            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid && io.commit.bits.insn_commit(i).bits.RD =/= 0.U){
                val commit_PRD = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRD := (io.commit.bits.insn_commit(i).bits.PRD - 1.U)
                INT_commit_freelist(commit_PRD) := 0.B
            }
        }
    }

    when(io.flush.valid){
        INT_freelist := INT_commit_freelist
        for(i <- 0 until fetchWidth){
            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                val commit_PRD = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRD := io.commit.bits.insn_commit(i).bits.PRD - 1.U
                INT_freelist(commit_PRD) := 0.B
            }

            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                val commit_PRDold = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRDold := io.commit.bits.insn_commit(i).bits.PRDold - 1.U
                INT_freelist(commit_PRDold) := 1.B
            }

        }
    }

    
    //////////
    // MISC //
    //////////
    
    // x0 as a dest or source is never remapped
    // x0 always ready
    INT_available_table(0) := 1.U
    FP_available_table(0) := 1.U




}

