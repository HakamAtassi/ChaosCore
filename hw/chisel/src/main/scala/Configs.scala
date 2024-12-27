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

/*
class WithNGigaBooms(n: Int = 1) extends Config(
  new WithTAGELBPD ++ // Default to TAGE-L BPD
  new Config((site, here, up) => {
    case TilesLocated(InSubsystem) => {
      val prev = up(TilesLocated(InSubsystem), site)
      val idOffset = up(NumTiles)
      (0 until n).map { i =>
        BoomTileAttachParams(
          tileParams = BoomTileParams(
            core = BoomCoreParams(
              fetchWidth = 8,
              decodeWidth = 5,
              numRobEntries = 130,
              issueParams = Seq(
                IssueParams(issueWidth=2, numEntries=32, iqType=IQ_MEM, dispatchWidth=5, numSlowEntries=12),
                IssueParams(issueWidth=1, numEntries=32, iqType=IQ_UNQ, dispatchWidth=5, numSlowEntries=24),
                IssueParams(issueWidth=5, numEntries=20, iqType=IQ_ALU, dispatchWidth=5, numSlowEntries=10),
                IssueParams(issueWidth=2, numEntries=32, iqType=IQ_FP , dispatchWidth=5, numSlowEntries=20)),
              lsuWidth = 2,
              numIntPhysRegisters = 128,
              numFpPhysRegisters = 128,
              numFrfReadPorts=6,
              numFrfBanks=1,
              numLdqEntries = 32,
              numStqEntries = 32,
              maxBrCount = 20,
              numFetchBufferEntries = 32,
              enablePrefetching = true,
              enableSuperscalarSnapshots = false,
              enableColumnALUIssue = true,
              numDCacheBanks = 1,
              ftq = FtqParameters(nEntries=40),
              fpu = Some(freechips.rocketchip.tile.FPUParams(sfmaLatency=4, dfmaLatency=4, divSqrt=true))
            ),
            dcache = Some(
              DCacheParams(rowBits = 128, nSets=64, nWays=8, nMSHRs=8, nTLBWays=32)
            ),
            icache = Some(
              ICacheParams(rowBits = 128, nSets=64, nWays=8, fetchBytes=4*4)
            ),
            tileId = i + idOffset
          ),
          crossingParams = RocketCrossingParams()
        )
      } ++ prev
    }
    case NumTiles => up(NumTiles) + n
  })
)
*/

class WithNChaosCores(n: Int = 1) extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => {
    // Calculate the next available hart ID (since hart ID cannot be duplicated)
    val prev = up(TilesLocated(InSubsystem), site)
    val idOffset = up(NumTiles)
    // Create TileAttachParams for every core to be instantiated
    val big = ChaosCoreTileParams(
      core   = ChaosCoreParams(),
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
      ))
    )
    List.tabulate(n)(i => ChaosCoreAttachParams(
      big.copy(tileId = i + idOffset),
      RocketCrossingParams()
    )) ++ prev

  }
  case NumTiles => up(NumTiles) + n
})


