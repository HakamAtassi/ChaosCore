package ChaosCore

import chisel3._
import chisel3.util._





class AXI_master(coreParameters:CoreParameters, val nocParameters:NOCParameters) extends Module with AXICacheNode{


  // MASATER ADDRESSES
  val AXI_MASTER_WRITE_ADDRESS = RegInit(UInt(32.W), 0.U)
  val AXI_MASTER_READ_ADDRESS = RegInit(UInt(32.W), 0.U)


  object AXI_MASTER_STATES extends ChiselEnum {
    val WRITE, READ = Value
  }

  val AXI_MASTER_STATE = RegInit(AXI_MASTER_STATES(), AXI_MASTER_STATES.WRITE)

  val write_counter = RegInit(UInt(32.W), 0.U)
  val read_counter  = RegInit(UInt(32.W), 0.U)

  switch(AXI_MASTER_STATE){
    is(AXI_MASTER_STATES.WRITE){
        AXI_MASTER_WRITE_ADDRESS := AXI_MASTER_WRITE_ADDRESS + 1.U
        AXI_write_request(address = AXI_MASTER_WRITE_ADDRESS, bytes=1.U, data=AXI_MASTER_WRITE_ADDRESS)

        when(write_counter === 10.U){
          write_counter := 0.U
          AXI_MASTER_STATE === AXI_MASTER_STATES.READ
        }
    }

    is(AXI_MASTER_STATES.READ){
        AXI_MASTER_READ_ADDRESS := AXI_MASTER_READ_ADDRESS + 1.U
        AXI_read_request(address = AXI_MASTER_WRITE_ADDRESS, bytes=1.U)

        when(read_counter === 10.U){
          read_counter := 0.U
          AXI_MASTER_STATE === AXI_MASTER_STATES.WRITE
        }
    }
  }


    // print read responses
    val (resp_data, resp_valid) = AXI_read;
    when(resp_valid){
      printf("%d\n", resp_data)
    }


}