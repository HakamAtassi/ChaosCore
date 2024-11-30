//******************************************************************************
// Copyright (c) 2019 - 2019, The Regents of the University of California (Regents).
// All Rights Reserved. See LICENSE and LICENSE.SiFive for license details.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ChaosCore Tile Wrapper
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

package ChaosCore

import chisel3._
import chisel3.util._
import chisel3.experimental.{IntParam, StringParam}

import scala.collection.mutable.{ListBuffer}

import org.chipsalliance.cde.config._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.devices.tilelink._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.prci._
import freechips.rocketchip.rocket._
import freechips.rocketchip.subsystem.{RocketCrossingParams}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.interrupts._
import freechips.rocketchip.util._
import freechips.rocketchip.tile._
import freechips.rocketchip.amba.axi4._



class WithNChaosCores(n: Int = 1) extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => {
    // Calculate the next available hart ID (since hart ID cannot be duplicated)
    val prev = up(TilesLocated(InSubsystem), site)
    val idOffset = up(NumTiles)
    // Create TileAttachParams for every core to be instantiated
    (0 until n).map { i =>
      ChaosCoreAttachParams(
        tileParams = ChaosCoreTileParams(tileId = i + idOffset),
        crossingParams = RocketCrossingParams()
      )
    } ++ prev
  }
  // Configurate # of bytes in one memory / IO transaction. For RV64, one load/store instruction can transfer 8 bytes at most.
  case SystemBusKey => up(SystemBusKey, site).copy(beatBytes = 4)
  case NumTiles => up(NumTiles) + n
})