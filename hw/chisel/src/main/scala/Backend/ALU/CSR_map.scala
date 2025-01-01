

// lifted directly from rocketchip src/main/scala/rocket/Instructions.scala
// https://github.com/chipsalliance/rocket-chip

package ChaosCore

import chisel3._

import chisel3.util._





object CSRs {
  // USER MODE //
  // Unprivileged Floating-Point CSRs
  val fflags = 0x1
  val frm = 0x2
  val fcsr = 0x3

  // Unprivileged Counters/Timers
  // lower values 
  val cycle = 0xc00
  val time = 0xc01
  val instret = 0xc02
  val hpmcounter3 = 0xc03
  val hpmcounter4 = 0xc04
  val hpmcounter5 = 0xc05
  val hpmcounter6 = 0xc06
  val hpmcounter7 = 0xc07
  val hpmcounter8 = 0xc08
  val hpmcounter9 = 0xc09
  val hpmcounter10 = 0xc0a
  val hpmcounter11 = 0xc0b
  val hpmcounter12 = 0xc0c
  val hpmcounter13 = 0xc0d
  val hpmcounter14 = 0xc0e
  val hpmcounter15 = 0xc0f
  val hpmcounter16 = 0xc10
  val hpmcounter17 = 0xc11
  val hpmcounter18 = 0xc12
  val hpmcounter19 = 0xc13
  val hpmcounter20 = 0xc14
  val hpmcounter21 = 0xc15
  val hpmcounter22 = 0xc16
  val hpmcounter23 = 0xc17
  val hpmcounter24 = 0xc18
  val hpmcounter25 = 0xc19
  val hpmcounter26 = 0xc1a
  val hpmcounter27 = 0xc1b
  val hpmcounter28 = 0xc1c
  val hpmcounter29 = 0xc1d
  val hpmcounter30 = 0xc1e
  val hpmcounter31 = 0xc1f

  // upper values 
  val cycleh = 0xc80
  val timeh = 0xc81
  val instreth = 0xc82
  val hpmcounter3h = 0xc83
  val hpmcounter4h = 0xc84
  val hpmcounter5h = 0xc85
  val hpmcounter6h = 0xc86
  val hpmcounter7h = 0xc87
  val hpmcounter8h = 0xc88
  val hpmcounter9h = 0xc89
  val hpmcounter10h = 0xc8a
  val hpmcounter11h = 0xc8b
  val hpmcounter12h = 0xc8c
  val hpmcounter13h = 0xc8d
  val hpmcounter14h = 0xc8e
  val hpmcounter15h = 0xc8f
  val hpmcounter16h = 0xc90
  val hpmcounter17h = 0xc91
  val hpmcounter18h = 0xc92
  val hpmcounter19h = 0xc93
  val hpmcounter20h = 0xc94
  val hpmcounter21h = 0xc95
  val hpmcounter22h = 0xc96
  val hpmcounter23h = 0xc97
  val hpmcounter24h = 0xc98
  val hpmcounter25h = 0xc99
  val hpmcounter26h = 0xc9a
  val hpmcounter27h = 0xc9b
  val hpmcounter28h = 0xc9c
  val hpmcounter29h = 0xc9d
  val hpmcounter30h = 0xc9e
  val hpmcounter31h = 0xc9f

  // Supervisor mode //
  // Supervisor Trap Setup
  val sstatus = 0x100
  val sie = 0x104
  val stvec = 0x105
  val scounteren = 0x106

  // Supervisor Configuration
  val senvcfg = 0x10a

  //Supervisor Counter Setup
  val scountinhibit = 0x120

  // Supervisor Trap Handling
  val sscratch = 0x140
  val sepc = 0x141
  val scause = 0x142
  val stval = 0x143
  val sip = 0x144
  val scountovf = 0xda0

  // Supervisor Protection and Translation
  val satp = 0x180

  // Debug/Trace Registers
  val scontext = 0x5a8

  // Supervisor State Enable Registers
  val sstateen0 = 0x10c
  val sstateen1 = 0x10d
  val sstateen2 = 0x10e
  val sstateen3 = 0x10f


  // MACHINE MODE
  // Machine Information Registers
  val mvendorid = 0xf11
  val marchid = 0xf12
  val mimpid = 0xf13
  val mhartid = 0xf14
  val mconfigptr = 0xf15

  // Machine Trap Setup
  val mstatus = 0x300
  val misa = 0x301
  val medeleg = 0x302
  val mideleg = 0x303
  val mie = 0x304
  val mtvec = 0x305
  val mcounteren = 0x306
  val mstatush = 0x310
  val medelegh = 0x312

  // Machine Trap Handling
  val mscratch = 0x340
  val mepc = 0x341
  val mcause = 0x342
  val mtval = 0x343
  val mip = 0x344
  val mtinst = 0x34a
  val mtval2 = 0x34b

  // Machine Configuration
  val menvcfg = 0x30a
  val menvcfgh = 0x30a
  val mseccfg = 0x747
  val mseccfgh = 0x757

  // Machine memory protection
  val pmpcfg0 = 0x3a0
  val pmpcfg1 = 0x3a1
  val pmpcfg2 = 0x3a2
  val pmpcfg3 = 0x3a3
  val pmpcfg4 = 0x3a4
  val pmpcfg5 = 0x3a5
  val pmpcfg6 = 0x3a6
  val pmpcfg7 = 0x3a7
  val pmpcfg8 = 0x3a8
  val pmpcfg9 = 0x3a9
  val pmpcfg10 = 0x3aa
  val pmpcfg11 = 0x3ab
  val pmpcfg12 = 0x3ac
  val pmpcfg13 = 0x3ad
  val pmpcfg14 = 0x3ae
  val pmpcfg15 = 0x3af
  val pmpaddr0 = 0x3b0
  val pmpaddr1 = 0x3b1
  val pmpaddr2 = 0x3b2
  val pmpaddr3 = 0x3b3
  val pmpaddr4 = 0x3b4
  val pmpaddr5 = 0x3b5
  val pmpaddr6 = 0x3b6
  val pmpaddr7 = 0x3b7
  val pmpaddr8 = 0x3b8
  val pmpaddr9 = 0x3b9
  val pmpaddr10 = 0x3ba
  val pmpaddr11 = 0x3bb
  val pmpaddr12 = 0x3bc
  val pmpaddr13 = 0x3bd
  val pmpaddr14 = 0x3be
  val pmpaddr15 = 0x3bf
  val pmpaddr16 = 0x3c0
  val pmpaddr17 = 0x3c1
  val pmpaddr18 = 0x3c2
  val pmpaddr19 = 0x3c3
  val pmpaddr20 = 0x3c4
  val pmpaddr21 = 0x3c5
  val pmpaddr22 = 0x3c6
  val pmpaddr23 = 0x3c7
  val pmpaddr24 = 0x3c8
  val pmpaddr25 = 0x3c9
  val pmpaddr26 = 0x3ca
  val pmpaddr27 = 0x3cb
  val pmpaddr28 = 0x3cc
  val pmpaddr29 = 0x3cd
  val pmpaddr30 = 0x3ce
  val pmpaddr31 = 0x3cf
  val pmpaddr32 = 0x3d0
  val pmpaddr33 = 0x3d1
  val pmpaddr34 = 0x3d2
  val pmpaddr35 = 0x3d3
  val pmpaddr36 = 0x3d4
  val pmpaddr37 = 0x3d5
  val pmpaddr38 = 0x3d6
  val pmpaddr39 = 0x3d7
  val pmpaddr40 = 0x3d8
  val pmpaddr41 = 0x3d9
  val pmpaddr42 = 0x3da
  val pmpaddr43 = 0x3db
  val pmpaddr44 = 0x3dc
  val pmpaddr45 = 0x3dd
  val pmpaddr46 = 0x3de
  val pmpaddr47 = 0x3df
  val pmpaddr48 = 0x3e0
  val pmpaddr49 = 0x3e1
  val pmpaddr50 = 0x3e2
  val pmpaddr51 = 0x3e3
  val pmpaddr52 = 0x3e4
  val pmpaddr53 = 0x3e5
  val pmpaddr54 = 0x3e6
  val pmpaddr55 = 0x3e7
  val pmpaddr56 = 0x3e8
  val pmpaddr57 = 0x3e9
  val pmpaddr58 = 0x3ea
  val pmpaddr59 = 0x3eb
  val pmpaddr60 = 0x3ec
  val pmpaddr61 = 0x3ed
  val pmpaddr62 = 0x3ee
  val pmpaddr63 = 0x3ef

  // Machine State Enable Registers (not implemented)
  val mstateen0 = 0x30c
  val mstateen1 = 0x30d
  val mstateen2 = 0x30e
  val mstateen3 = 0x30f
  val mstateen0h = 0x31c
  val mstateen1h = 0x31d
  val mstateen2h = 0x31e
  val mstateen3h = 0x31f

  // Machine Non-Maskable Interrupt Handling
  val mnscratch = 0x740
  val mnepc = 0x741
  val mncause = 0x742
  val mnstatus = 0x744

  // Machine Counter/Timers
  val mcycle = 0xb00
  val minstret = 0xb02
  val mhpmcounter3 = 0xb03
  val mhpmcounter4 = 0xb04
  val mhpmcounter5 = 0xb05
  val mhpmcounter6 = 0xb06
  val mhpmcounter7 = 0xb07
  val mhpmcounter8 = 0xb08
  val mhpmcounter9 = 0xb09
  val mhpmcounter10 = 0xb0a
  val mhpmcounter11 = 0xb0b
  val mhpmcounter12 = 0xb0c
  val mhpmcounter13 = 0xb0d
  val mhpmcounter14 = 0xb0e
  val mhpmcounter15 = 0xb0f
  val mhpmcounter16 = 0xb10
  val mhpmcounter17 = 0xb11
  val mhpmcounter18 = 0xb12
  val mhpmcounter19 = 0xb13
  val mhpmcounter20 = 0xb14
  val mhpmcounter21 = 0xb15
  val mhpmcounter22 = 0xb16
  val mhpmcounter23 = 0xb17
  val mhpmcounter24 = 0xb18
  val mhpmcounter25 = 0xb19
  val mhpmcounter26 = 0xb1a
  val mhpmcounter27 = 0xb1b
  val mhpmcounter28 = 0xb1c
  val mhpmcounter29 = 0xb1d
  val mhpmcounter30 = 0xb1e
  val mhpmcounter31 = 0xb1f

  val mcycleh = 0xb80
  val minstreth = 0xb82
  val mhpmcounter3h = 0xb83
  val mhpmcounter4h = 0xb84
  val mhpmcounter5h = 0xb85
  val mhpmcounter6h = 0xb86
  val mhpmcounter7h = 0xb87
  val mhpmcounter8h = 0xb88
  val mhpmcounter9h = 0xb89
  val mhpmcounter10h = 0xb8a
  val mhpmcounter11h = 0xb8b
  val mhpmcounter12h = 0xb8c
  val mhpmcounter13h = 0xb8d
  val mhpmcounter14h = 0xb8e
  val mhpmcounter15h = 0xb8f
  val mhpmcounter16h = 0xb90
  val mhpmcounter17h = 0xb91
  val mhpmcounter18h = 0xb92
  val mhpmcounter19h = 0xb93
  val mhpmcounter20h = 0xb94
  val mhpmcounter21h = 0xb95
  val mhpmcounter22h = 0xb96
  val mhpmcounter23h = 0xb97
  val mhpmcounter24h = 0xb98
  val mhpmcounter25h = 0xb99
  val mhpmcounter26h = 0xb9a
  val mhpmcounter27h = 0xb9b
  val mhpmcounter28h = 0xb9c
  val mhpmcounter29h = 0xb9d
  val mhpmcounter30h = 0xb9e
  val mhpmcounter31h = 0xb9f

  // Machine Counter Setup 
  val mcountinhibit = 0x320
  val mhpmevent3 = 0x323
  val mhpmevent4 = 0x324
  val mhpmevent5 = 0x325
  val mhpmevent6 = 0x326
  val mhpmevent7 = 0x327
  val mhpmevent8 = 0x328
  val mhpmevent9 = 0x329
  val mhpmevent10 = 0x330
  val mhpmevent11 = 0x331
  val mhpmevent12 = 0x332
  val mhpmevent13 = 0x333
  val mhpmevent14 = 0x334
  val mhpmevent15 = 0x335
  val mhpmevent16 = 0x336
  val mhpmevent17 = 0x337
  val mhpmevent18 = 0x338
  val mhpmevent19 = 0x339
  val mhpmevent20 = 0x33A
  val mhpmevent21 = 0x33B
  val mhpmevent22 = 0x33C
  val mhpmevent23 = 0x33D
  val mhpmevent24 = 0x33E
  val mhpmevent25 = 0x33F

  val mhpmevent3h = 0x723
  val mhpmevent4h = 0x724
  val mhpmevent5h = 0x725
  val mhpmevent6h = 0x726
  val mhpmevent7h = 0x727
  val mhpmevent8h = 0x728
  val mhpmevent9h = 0x729
  val mhpmevent10h = 0x730
  val mhpmevent11h = 0x731
  val mhpmevent12h = 0x732
  val mhpmevent13h = 0x733
  val mhpmevent14h = 0x734
  val mhpmevent15h = 0x735
  val mhpmevent16h = 0x736
  val mhpmevent17h = 0x737
  val mhpmevent18h = 0x738
  val mhpmevent19h = 0x739
  val mhpmevent20h = 0x73A
  val mhpmevent21h = 0x73B
  val mhpmevent22h = 0x73C
  val mhpmevent23h = 0x73D
  val mhpmevent24h = 0x73E
  val mhpmevent25h = 0x73F

  // Debug/Trace Registers 
  val tselect = 0x7a0
  val tdata1 = 0x7a1
  val tdata2 = 0x7a2
  val tdata3 = 0x7a3
  val tinfo = 0x7a4
  val tcontrol = 0x7a5
  val mcontext = 0x7a8
  val mscontext = 0x7aa

  // Debug Mode Registers 
  val dcsr = 0x7b0
  val dpc = 0x7b1
  val dscratch0 = 0x7b2
  val dscratch1 = 0x7b3

  // UNUSED
  val vstart = 0x8
  val vxsat = 0x9
  val vxrm = 0xa
  val vcsr = 0xf
  val seed = 0x15
  val jvt = 0x17

  val mvien = 0x308
  val mvip = 0x309
  val mcountinhibit = 0x320
  val miselect = 0x350
  val mireg = 0x351
  val mtopei = 0x35c

  val vl = 0xc20
  val vtype = 0xc21
  val vlenb = 0xc22
  val sedeleg = 0x102
  val sideleg = 0x103
  val stimecmp = 0x14d
  val siselect = 0x150
  val sireg = 0x151
  val stopei = 0x15c

  val vsstatus = 0x200
  val vsie = 0x204
  val vstvec = 0x205
  val vsscratch = 0x240
  val vsepc = 0x241
  val vscause = 0x242
  val vstval = 0x243
  val vsip = 0x244
  val vstimecmp = 0x24d
  val vsiselect = 0x250
  val vsireg = 0x251
  val vstopei = 0x25c
  val vsatp = 0x280
  val hstatus = 0x600
  val hedeleg = 0x602
  val hideleg = 0x603
  val hie = 0x604
  val htimedelta = 0x605
  val hcounteren = 0x606
  val hgeie = 0x607
  val hvien = 0x608
  val hvictl = 0x609
  val henvcfg = 0x60a
  val hstateen0 = 0x60c
  val hstateen1 = 0x60d
  val hstateen2 = 0x60e
  val hstateen3 = 0x60f
  val htval = 0x643
  val hip = 0x644
  val hvip = 0x645
  val hviprio1 = 0x646
  val hviprio2 = 0x647
  val htinst = 0x64a
  val hgatp = 0x680
  val hcontext = 0x6a8
  val hgeip = 0xe12
  val vstopi = 0xeb0
  val stopi = 0xdb0
  val utvt = 0x7
  val unxti = 0x45
  val uintstatus = 0x46
  val uscratchcsw = 0x48
  val uscratchcswl = 0x49
  val stvt = 0x107
  val snxti = 0x145
  val sintstatus = 0x146
  val sscratchcsw = 0x148
  val sscratchcswl = 0x149
  val mtvt = 0x307
  val mnxti = 0x345
  val mintstatus = 0x346
  val mscratchcsw = 0x348
  val mscratchcswl = 0x349

  val mtopi = 0xfb0
  val sieh = 0x114
  val siph = 0x154
  val stimecmph = 0x15d
  val vsieh = 0x214
  val vsiph = 0x254
  val vstimecmph = 0x25d
  val htimedeltah = 0x615
  val hidelegh = 0x613
  val hvienh = 0x618
  val henvcfgh = 0x61a
  val hviph = 0x655
  val hviprio1h = 0x656
  val hviprio2h = 0x657
  val hstateen0h = 0x61c
  val hstateen1h = 0x61d
  val hstateen2h = 0x61e
  val hstateen3h = 0x61f
  val midelegh = 0x313
  val mieh = 0x314
  val mvienh = 0x318
  val mviph = 0x319
  val miph = 0x354

}

