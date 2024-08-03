package ChaosCore

import chisel3._
import chisel3.util._


class AXI_master(coreParameters:CoreParameters, val nocParameters:NOCParameters) extends Module with AXICacheNode{


  // MASATER ADDRESSES
  val AXI_MASTER_WRITE_ADDRESS = RegInit(UInt(32.W), 0.U)
  val AXI_MASTER_READ_ADDRESS = RegInit(UInt(32.W), 0.U)


  object AXI_MASTER_STATES extends ChiselEnum {
    val WRITE, READ, IDLE = Value
  }

  val AXI_MASTER_STATE = RegInit(AXI_MASTER_STATES(), AXI_MASTER_STATES.WRITE)

  dontTouch(AXI_MASTER_STATE)

  val test_cache_line = Wire(UInt(256.W))
  test_cache_line := "h0102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F".U

  switch(AXI_MASTER_STATE){

    is(AXI_MASTER_STATES.WRITE){

      when(AXI_write_request(address = 0.U, bytes=32.U, data=test_cache_line)){
        AXI_MASTER_STATE := AXI_MASTER_STATES.READ
      }
    }

    is(AXI_MASTER_STATES.READ){
      when(AXI_read_request(address = 0.U, bytes=32.U)){
        AXI_MASTER_STATE := AXI_MASTER_STATES.IDLE
      }



    }
  }
  
  // print read responses
  val (resp_data, resp_valid) = AXI_read;
  when(resp_valid){
    printf("Read Resp: %x\n", resp_data)
  }


}