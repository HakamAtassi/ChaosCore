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

class WithNHugeChaosCores(n: Int = 1) extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => {
    // Calculate the next available hart ID (since hart ID cannot be duplicated)
    val prev = up(TilesLocated(InSubsystem), site)
    val idOffset = up(NumTiles)
    // Create TileAttachParams for every core to be instantiated
    val big = ChaosCoreTileParams(
      dcache = Some(DCacheParams(
        nSets = 64,
        nWays = 8,
        rowBits = 128,
        nMSHRs = 4,
      )),
      icache = Some(ICacheParams(
        nSets = 64,
        nWays = 8,
        rowBits = 128,
        latency = 1,
        fetchBytes = 16,
      )),
      core = ChaosCoreParams(
        haveSimTimeout = true,
        fetchWidth = 4,
      ),
    )
    List.tabulate(n)(i => ChaosCoreAttachParams(
      big.copy(tileId = i + idOffset),
      RocketCrossingParams()
    )) ++ prev

  }
  case NumTiles => up(NumTiles) + n
})

class WithNSmallChaosCores(n: Int = 1) extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => {
    // Calculate the next available hart ID (since hart ID cannot be duplicated)
    val prev = up(TilesLocated(InSubsystem), site)
    val idOffset = up(NumTiles)
    // Create TileAttachParams for every core to be instantiated
    val big = ChaosCoreTileParams(
      dcache = Some(DCacheParams(
        nSets = 64,
        nWays = 8,
        rowBits = 128,
        nMSHRs = 4,
      )),
      icache = Some(ICacheParams(
        nSets = 64,
        nWays = 8,
        rowBits = 128,
        latency = 1,
        fetchBytes = 4,
      )),
      core = ChaosCoreParams(
        fetchWidth = 1,
      )
    )
    List.tabulate(n)(i => ChaosCoreAttachParams(
      big.copy(tileId = i + idOffset),
      RocketCrossingParams()
    )) ++ prev

  }
  case NumTiles => up(NumTiles) + n
})


