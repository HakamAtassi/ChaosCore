

// lifted directly from rocketchip src/main/scala/rocket/Instructions.scala
// https://github.com/chipsalliance/rocket-chip

package ChaosCore

import chisel3._

import chisel3.util._





object CSRs {
  val fflags = 0x1
  val frm = 0x2
  val fcsr = 0x3
  val vstart = 0x8
  val vxsat = 0x9
  val vxrm = 0xa
  val vcsr = 0xf
  val seed = 0x15
  val jvt = 0x17
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
  val vl = 0xc20
  val vtype = 0xc21
  val vlenb = 0xc22
  val sstatus = 0x100
  val sedeleg = 0x102
  val sideleg = 0x103
  val sie = 0x104
  val stvec = 0x105
  val scounteren = 0x106
  val senvcfg = 0x10a
  val sstateen0 = 0x10c
  val sstateen1 = 0x10d
  val sstateen2 = 0x10e
  val sstateen3 = 0x10f
  val sscratch = 0x140
  val sepc = 0x141
  val scause = 0x142
  val stval = 0x143
  val sip = 0x144
  val stimecmp = 0x14d
  val siselect = 0x150
  val sireg = 0x151
  val stopei = 0x15c
  val satp = 0x180
  val scontext = 0x5a8
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
  val scountovf = 0xda0
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
  val mstatus = 0x300
  val misa = 0x301
  val medeleg = 0x302
  val mideleg = 0x303
  val mie = 0x304
  val mtvec = 0x305
  val mcounteren = 0x306
  val mvien = 0x308
  val mvip = 0x309
  val menvcfg = 0x30a
  val mstateen0 = 0x30c
  val mstateen1 = 0x30d
  val mstateen2 = 0x30e
  val mstateen3 = 0x30f
  val mcountinhibit = 0x320
  val mscratch = 0x340
  val mepc = 0x341
  val mcause = 0x342
  val mtval = 0x343
  val mip = 0x344
  val mtinst = 0x34a
  val mtval2 = 0x34b
  val miselect = 0x350
  val mireg = 0x351
  val mtopei = 0x35c
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
  val mseccfg = 0x747
  val tselect = 0x7a0
  val tdata1 = 0x7a1
  val tdata2 = 0x7a2
  val tdata3 = 0x7a3
  val tinfo = 0x7a4
  val tcontrol = 0x7a5
  val mcontext = 0x7a8
  val mscontext = 0x7aa
  val dcsr = 0x7b0
  val dpc = 0x7b1
  val dscratch0 = 0x7b2
  val dscratch1 = 0x7b3
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
  val mhpmevent3 = 0x323
  val mhpmevent4 = 0x324
  val mhpmevent5 = 0x325
  val mhpmevent6 = 0x326
  val mhpmevent7 = 0x327
  val mhpmevent8 = 0x328
  val mhpmevent9 = 0x329
  val mhpmevent10 = 0x32a
  val mhpmevent11 = 0x32b
  val mhpmevent12 = 0x32c
  val mhpmevent13 = 0x32d
  val mhpmevent14 = 0x32e
  val mhpmevent15 = 0x32f
  val mhpmevent16 = 0x330
  val mhpmevent17 = 0x331
  val mhpmevent18 = 0x332
  val mhpmevent19 = 0x333
  val mhpmevent20 = 0x334
  val mhpmevent21 = 0x335
  val mhpmevent22 = 0x336
  val mhpmevent23 = 0x337
  val mhpmevent24 = 0x338
  val mhpmevent25 = 0x339
  val mhpmevent26 = 0x33a
  val mhpmevent27 = 0x33b
  val mhpmevent28 = 0x33c
  val mhpmevent29 = 0x33d
  val mhpmevent30 = 0x33e
  val mhpmevent31 = 0x33f
  val mvendorid = 0xf11
  val marchid = 0xf12
  val mimpid = 0xf13
  val mhartid = 0xf14
  val mconfigptr = 0xf15
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
  val mstatush = 0x310
  val midelegh = 0x313
  val mieh = 0x314
  val mvienh = 0x318
  val mviph = 0x319
  val menvcfgh = 0x31a
  val mstateen0h = 0x31c
  val mstateen1h = 0x31d
  val mstateen2h = 0x31e
  val mstateen3h = 0x31f
  val miph = 0x354
  val mhpmevent3h = 0x723
  val mhpmevent4h = 0x724
  val mhpmevent5h = 0x725
  val mhpmevent6h = 0x726
  val mhpmevent7h = 0x727
  val mhpmevent8h = 0x728
  val mhpmevent9h = 0x729
  val mhpmevent10h = 0x72a
  val mhpmevent11h = 0x72b
  val mhpmevent12h = 0x72c
  val mhpmevent13h = 0x72d
  val mhpmevent14h = 0x72e
  val mhpmevent15h = 0x72f
  val mhpmevent16h = 0x730
  val mhpmevent17h = 0x731
  val mhpmevent18h = 0x732
  val mhpmevent19h = 0x733
  val mhpmevent20h = 0x734
  val mhpmevent21h = 0x735
  val mhpmevent22h = 0x736
  val mhpmevent23h = 0x737
  val mhpmevent24h = 0x738
  val mhpmevent25h = 0x739
  val mhpmevent26h = 0x73a
  val mhpmevent27h = 0x73b
  val mhpmevent28h = 0x73c
  val mhpmevent29h = 0x73d
  val mhpmevent30h = 0x73e
  val mhpmevent31h = 0x73f
  val mnscratch = 0x740
  val mnepc = 0x741
  val mncause = 0x742
  val mnstatus = 0x744
  val mseccfgh = 0x757
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

  // map addressess to names for debug
  val m: Map[UInt, String] = Map(
    fflags.U -> "fflags",
    //frm -> "frm",
    //fcsr -> "fcsr",
    //vstart -> "vstart",
    //vxsat -> "vxsat",
    //vxrm -> "vxrm",
    //vcsr -> "vcsr",
    //seed -> "vcsr",
    //jvt -> "vcsr",
    //cycle -> "vcsr",
    //time -> "vcsr",
    //instret -> "vcsr",
    //hpmcounter3 -> "hpmcounter3",
    //hpmcounter4 -> "hpmcounter4",
    //hpmcounter5 -> "hpmcounter5",
    //hpmcounter6 -> "hpmcounter6",
    //hpmcounter7 -> "hpmcounter7",
    //hpmcounter8 -> "hpmcounter8",
    //hpmcounter9 -> "hpmcounter9",
    //hpmcounter10 -> "hpmcounter10",
    //hpmcounter11 -> "hpmcounter11",
    //hpmcounter12 -> "hpmcounter12",
    //hpmcounter13 -> "hpmcounter13",
    //hpmcounter14 -> "hpmcounter14",
    //hpmcounter15 -> "hpmcounter15",
    //hpmcounter16 -> "hpmcounter16",
    //hpmcounter17 -> "hpmcounter17",
    //hpmcounter18 -> "hpmcounter18",
    //hpmcounter19 -> "hpmcounter19",
    //hpmcounter20 -> "hpmcounter20",
    //hpmcounter21 -> "hpmcounter21",
    //hpmcounter22 -> "hpmcounter22",
    //hpmcounter23 -> "hpmcounter23",
    //hpmcounter24 -> "hpmcounter24",
    //hpmcounter25 -> "hpmcounter25",
    //hpmcounter26 -> "hpmcounter26",
    //hpmcounter27 -> "hpmcounter27",
    //hpmcounter28 -> "hpmcounter28",
    //hpmcounter29 -> "hpmcounter29",
    //hpmcounter30 -> "hpmcounter30",
    //hpmcounter31 -> "hpmcounter31",
    //vl -> "vl",
    //vtype -> "",
    //vlenb -> "",
    //sstatus -> "",
    //sedeleg -> "",
    //sideleg -> "",
    //sie -> "",
    //stvec -> "",
    //scounteren -> "",
    //senvcfg -> "",
    //sstateen0 -> "",
    //sstateen1 -> "",
    //sstateen2 -> "",
    //sstateen3 -> "",
    //sscratch -> "",
    //sepc -> "",
    //scause -> "",
    //stval -> "",
    //sip -> "",
    //stimecmp -> "",
    //siselect -> "",
    //sireg -> "",
    //stopei -> "",
    //satp -> "",
    //scontext -> "",
    //vsstatus -> "",
    //vsie -> "",
    //vstvec -> "",
    //vsscratch -> "",
    //vsepc -> "",
    //vscause -> "",
    //vstval -> "",
    //vsip -> "",
    //vstimecmp -> "",
    //vsiselect -> "",
    //vsireg -> "",
    //vstopei -> "",
    //vsatp -> "",
    //hstatus -> "",
    //hedeleg -> "",
    //hideleg -> "",
    //hie -> "",
    //htimedelta -> "",
    //hcounteren -> "",
    //hgeie -> "",
    //hvien -> "",
    //hvictl -> "",
    //henvcfg -> "",
    //hstateen0 -> "",
    //hstateen1 -> "",
    //hstateen2 -> "",
    //hstateen3 -> "",
    //htval -> "",
    //hip -> "",
    //hvip -> "",
    //hviprio1 -> "",
    //hviprio2 -> "",
    //htinst -> "",
    //hgatp -> "",
    //hcontext -> "",
    //hgeip -> "",
    //vstopi -> "",
    //scountovf -> "",
    //stopi -> "",
    //uintstatus-> "",
    //uscratchcsw-> "",
    //uscratchcswl-> "",
    //stvt -> "",
    //snxti -> "",
    //sintstatus -> "",
    //sscratchcsw -> "",
    //sscratchcswl -> "",
    //mtvt -> "",
    //mnxti -> "",
    //mintstatus -> "",
    //mscratchcsw -> "",
    //mscratchcswl -> "",
    //mstatus -> "",
    //misa -> "",
    //medeleg -> "",
    //mideleg -> "",
    //mie -> "",
    //mtvec -> "",
    //mcounteren -> "",
    //mvien -> "",
    //mvip -> "",
    //menvcfg -> "",
    //mstateen0 -> "",
    //mstateen1 -> "",
    //mstateen2 -> "",
    //mstateen3 -> "",
    //mcountinhibit -> "",
    //mscratch -> "",
    //mepc -> "",
    //mcause -> "",
    //mtval -> "",
    //mip -> "",
    //mtinst -> "",
    //mtval2 -> "",
    //miselect -> "",
    //mireg -> "",
    //mtopei -> "",
    //pmpcfg0 -> "pmpcfg0",
    //pmpcfg1 -> "pmpcfg1",
    //pmpcfg2 -> "pmpcfg2",
    //pmpcfg3 -> "pmpcfg3",
    //pmpcfg4 -> "pmpcfg4",
    //pmpcfg5 -> "pmpcfg5",
    //pmpcfg6 -> "pmpcfg6",
    //pmpcfg7 -> "pmpcfg7",
    //pmpcfg8 -> "pmpcfg8",
    //pmpcfg9 -> "pmpcfg9",
    //pmpcfg10 -> "pmpcfg10",
    //pmpcfg11 -> "pmpcfg11",
    //pmpcfg12 -> "pmpcfg12",
    //pmpcfg13 -> "pmpcfg13",
    //pmpcfg14 -> "pmpcfg14",
    //pmpcfg15 -> "pmpcfg15",
    //pmpaddr0 -> "pmpaddr0",
    //pmpaddr1 -> "pmpaddr1",
    //pmpaddr2 -> "pmpaddr2",
    //pmpaddr3 -> "pmpaddr3",
    //pmpaddr4 -> "pmpaddr4",
    //pmpaddr5 -> "pmpaddr5",
    //pmpaddr6 -> "pmpaddr6",
    //pmpaddr7 -> "pmpaddr7",
    //pmpaddr8 -> "pmpaddr8",
    //pmpaddr9 -> "pmpaddr9",
    //pmpaddr10 -> "pmpaddr10",
    //pmpaddr11 -> "pmpaddr11",
    //pmpaddr12 -> "pmpaddr12",
    //pmpaddr13 -> "pmpaddr13",
    //pmpaddr14 -> "pmpaddr14",
    //pmpaddr15 -> "pmpaddr15",
    //pmpaddr16 -> "pmpaddr16",
    //pmpaddr17 -> "pmpaddr17",
    //pmpaddr18 -> "pmpaddr18",
    //pmpaddr19 -> "pmpaddr19",
    //pmpaddr20 -> "pmpaddr20",
    //pmpaddr21 -> "pmpaddr21",
    //pmpaddr22 -> "pmpaddr22",
    //pmpaddr23 -> "pmpaddr23",
    //pmpaddr24 -> "pmpaddr24",
    //pmpaddr25 -> "pmpaddr25",
    //pmpaddr26 -> "pmpaddr26",
    //pmpaddr27 -> "pmpaddr27",
    //pmpaddr28 -> "pmpaddr28",
    //pmpaddr29 -> "pmpaddr29",
    //pmpaddr30 -> "pmpaddr30",
    //pmpaddr31 -> "pmpaddr31",
    //pmpaddr32 -> "pmpaddr32",
    //pmpaddr33 -> "pmpaddr33",
    //pmpaddr34 -> "pmpaddr34",
    //pmpaddr35 -> "pmpaddr35",
    //pmpaddr36 -> "pmpaddr36",
    //pmpaddr37 -> "pmpaddr37",
    //pmpaddr38 -> "pmpaddr38",
    //pmpaddr39 -> "pmpaddr39",
    //pmpaddr40 -> "pmpaddr40",
    //pmpaddr41 -> "pmpaddr41",
    //pmpaddr42 -> "pmpaddr42",
    //pmpaddr43 -> "pmpaddr43",
    //pmpaddr44 -> "pmpaddr44",
    //pmpaddr45 -> "pmpaddr45",
    //pmpaddr46 -> "pmpaddr46",
    //pmpaddr47 -> "pmpaddr47",
    //pmpaddr48 -> "pmpaddr48",
    //pmpaddr49 -> "pmpaddr49",
    //pmpaddr50 -> "pmpaddr50",
    //pmpaddr51 -> "pmpaddr51",
    //pmpaddr52 -> "pmpaddr52",
    //pmpaddr53 -> "pmpaddr53",
    //pmpaddr54 -> "pmpaddr54",
    //pmpaddr55 -> "pmpaddr55",
    //pmpaddr56 -> "pmpaddr56",
    //pmpaddr57 -> "pmpaddr57",
    //pmpaddr58 -> "pmpaddr58",
    //pmpaddr59 -> "pmpaddr59",
    //pmpaddr60 -> "pmpaddr60",
    //pmpaddr61 -> "pmpaddr61",
    //pmpaddr62 -> "pmpaddr62",
    //pmpaddr63 -> "pmpaddr63",
    //mseccfg -> "",
    //tselect -> "",
    //tdata1 -> "",
    //tdata2 -> "",
    //tdata3 -> "",
    //tinfo -> "",
    //tcontrol -> "",
    //mcontext -> "",
    //mscontext -> "",
    //dcsr -> "",
    //dpc -> "",
    //dscratch0 -> "",
    //dscratch1 -> "",
    //mcycle -> "",
    //minstret -> "",
    //mhpmcounter3 -> "mhpmcounter3",
    //mhpmcounter4 -> "mhpmcounter4",
    //mhpmcounter5 -> "mhpmcounter5",
    //mhpmcounter6 -> "mhpmcounter6",
    //mhpmcounter7 -> "mhpmcounter7",
    //mhpmcounter8 -> "mhpmcounter8",
    //mhpmcounter9 -> "mhpmcounter9",
    //mhpmcounter10 -> "mhpmcounter10",
    //mhpmcounter11 -> "mhpmcounter11",
    //mhpmcounter12 -> "mhpmcounter12",
    //mhpmcounter13 -> "mhpmcounter13",
    //mhpmcounter14 -> "mhpmcounter14",
    //mhpmcounter15 -> "mhpmcounter15",
    //mhpmcounter16 -> "mhpmcounter16",
    //mhpmcounter17 -> "mhpmcounter17",
    //mhpmcounter18 -> "mhpmcounter18",
    //mhpmcounter19 -> "mhpmcounter19",
    //mhpmcounter20 -> "mhpmcounter20",
    //mhpmcounter21 -> "mhpmcounter21",
    //mhpmcounter22 -> "mhpmcounter22",
    //mhpmcounter23 -> "mhpmcounter23",
    //mhpmcounter24 -> "mhpmcounter24",
    //mhpmcounter25 -> "mhpmcounter25",
    //mhpmcounter26 -> "mhpmcounter26",
    //mhpmcounter27 -> "mhpmcounter27",
    //mhpmcounter28 -> "mhpmcounter28",
    //mhpmcounter29 -> "mhpmcounter29",
    //mhpmcounter30 -> "mhpmcounter30",
    //mhpmcounter31 -> "mhpmcounter31",
    //mhpmevent3 -> "mhpmevent3",
    //mhpmevent4 -> "mhpmevent",
    //mhpmevent5 -> "mhpmevent4",
    //mhpmevent6 -> "mhpmevent6",
    //mhpmevent7 -> "mhpmevent7",
    //mhpmevent8 -> "mhpmevent8",
    //mhpmevent9 -> "mhpmevent9",
    //mhpmevent10 -> "mhpmevent10",
    //mhpmevent11 -> "mhpmevent11",
    //mhpmevent12 -> "mhpmevent12",
    //mhpmevent13 -> "mhpmevent13",
    //mhpmevent14 -> "mhpmevent14",
    //mhpmevent15 -> "mhpmevent15",
    //mhpmevent16 -> "mhpmevent16",
    //mhpmevent17 -> "mhpmevent17",
    //mhpmevent18 -> "mhpmevent18",
    //mhpmevent19 -> "mhpmevent19",
    //mhpmevent20 -> "mhpmevent20",
    //mhpmevent21 -> "mhpmevent21",
    //mhpmevent22 -> "mhpmevent22",
    //mhpmevent23 -> "mhpmevent23",
    //mhpmevent24 -> "mhpmevent24",
    //mhpmevent25 -> "mhpmevent25",
    //mhpmevent26 -> "mhpmevent26",
    //mhpmevent27 -> "mhpmevent27",
    //mhpmevent28 -> "mhpmevent28",
    //mhpmevent29 -> "mhpmevent29",
    //mhpmevent30 -> "mhpmevent30",
    //mhpmevent31 -> "mhpmevent31",
    //mvendorid -> "",
    //marchid -> "",
    //mimpid -> "",
    //mhartid -> "",
    //mconfigptr -> "",
    //mtopi -> "",
    //sieh -> "",
    //siph -> "",
    //stimecmph -> "",
    //vsieh -> "",
    //vsiph -> "",
    //vstimecmph -> "",
    //htimedeltah -> "",
    //hidelegh -> "",
    //hvienh -> "",
    //henvcfgh -> "",
    //hviph -> "",
    //hviprio1h -> "",
    //hviprio2h -> "",
    //hstateen0h -> "",
    //hstateen1h -> "",
    //hstateen2h -> "",
    //hstateen3h -> "",
    //cycleh -> "",
    //timeh -> "",
    //instreth -> "",
    //hpmcounter3h -> "hpmcounter3h",
    //hpmcounter4h -> "hpmcounter4h",
    //hpmcounter5h -> "hpmcounter5h",
    //hpmcounter6h -> "hpmcounter6h",
    //hpmcounter7h -> "hpmcounter7h",
    //hpmcounter8h -> "hpmcounter8h",
    //hpmcounter9h -> "hpmcounter9h",
    //hpmcounter10h -> "hpmcounter10h",
    //hpmcounter11h -> "hpmcounter11h",
    //hpmcounter12h -> "hpmcounter12h",
    //hpmcounter13h -> "hpmcounter13h",
    //hpmcounter14h -> "hpmcounter14h",
    //hpmcounter15h -> "hpmcounter15h",
    //hpmcounter16h -> "hpmcounter16h",
    //hpmcounter17h -> "hpmcounter17h",
    //hpmcounter18h -> "hpmcounter18h",
    //hpmcounter19h -> "hpmcounter19h",
    //hpmcounter20h -> "hpmcounter20h",
    //hpmcounter21h -> "hpmcounter21h",
    //hpmcounter22h -> "hpmcounter22h",
    //hpmcounter23h -> "hpmcounter23h",
    //hpmcounter24h -> "hpmcounter24h",
    //hpmcounter25h -> "hpmcounter25h",
    //hpmcounter26h -> "hpmcounter26h",
    //hpmcounter27h -> "hpmcounter27h",
    //hpmcounter28h -> "hpmcounter28h",
    //hpmcounter29h -> "hpmcounter29h",
    //hpmcounter30h -> "hpmcounter30h",
    //hpmcounter31h -> "hpmcounter31h",
    //mstatush -> "",
    //midelegh -> "",
    //mieh -> "",
    //mvienh -> "",
    //mviph -> "",
    //menvcfgh -> "",
    //mstateen0h -> "mstateen0h",
    //mstateen1h -> "mstateen1h",
    //mstateen2h -> "mstateen2h",
    //mstateen3h -> "mstateen3h",
    //miph -> "",
    //mhpmevent3h -> "mhpmevent3h",
    //mhpmevent4h -> "mhpmevent3h",
    //mhpmevent5h -> "mhpmevent3h",
    //mhpmevent6h -> "mhpmevent3h",
    //mhpmevent7h -> "mhpmevent3h",
    //mhpmevent8h -> "mhpmevent3h",
    //mhpmevent9h -> "mhpmevent3h",
    //mhpmevent10h -> "mhpmevent3h",
    //mhpmevent11h -> "mhpmevent3h",
    //mhpmevent12h -> "mhpmevent3h",
    //mhpmevent13h -> "mhpmevent3h",
    //mhpmevent14h -> "mhpmevent3h",
    //mhpmevent15h -> "mhpmevent3h",
    //mhpmevent16h -> "mhpmevent3h",
    //mhpmevent17h -> "mhpmevent3h",
    //mhpmevent18h -> "mhpmevent3h",
    //mhpmevent19h -> "mhpmevent3h",
    //mhpmevent20h -> "mhpmevent3h",
    //mhpmevent21h -> "mhpmevent3h",
    //mhpmevent22h -> "mhpmevent3h",
    //mhpmevent23h -> "mhpmevent3h",
    //mhpmevent24h -> "mhpmevent3h",
    //mhpmevent25h -> "mhpmevent3h",
    //mhpmevent26h -> "mhpmevent3h",
    //mhpmevent27h -> "mhpmevent3h",
    //mhpmevent28h -> "mhpmevent3h",
    //mhpmevent29h -> "mhpmevent3h",
    //mhpmevent30h -> "mhpmevent3h",
    //mhpmevent31h -> "mhpmevent3h",
    //mnscratch -> "mnscratch",
    //mnepc -> "mnepc",
    //mncause -> "mncause",
    //mnstatus -> "mnstatus",
    //mseccfgh -> "mseccfgh",
    //mcycleh -> "mcycle",
    //minstreth -> "minstreth",
    //mhpmcounter3h -> "mhpmcounter3h",
    //mhpmcounter4h -> "mhpmcounter4h",
    //mhpmcounter5h -> "mhpmcounter5h",
    //mhpmcounter6h -> "mhpmcounter6h",
    //mhpmcounter7h -> "mhpmcounter7h",
    //mhpmcounter8h -> "mhpmcounter8h",
    //mhpmcounter9h -> "mhpmcounter9h",
    //mhpmcounter10h -> "mhpmcounter10h",
    //mhpmcounter11h -> "mhpmcounter11h",
    //mhpmcounter12h -> "mhpmcounter12h",
    //mhpmcounter13h -> "mhpmcounter13h",
    //mhpmcounter14h -> "mhpmcounter14h",
    //mhpmcounter15h -> "mhpmcounter15h",
    //mhpmcounter16h -> "mhpmcounter16h",
    //mhpmcounter17h -> "mhpmcounter17h",
    //mhpmcounter18h -> "mhpmcounter18h",
    //mhpmcounter19h -> "mhpmcounter19h",
    //mhpmcounter20h -> "mhpmcounter20h",
    //mhpmcounter21h -> "mhpmcounter21h",
    //mhpmcounter22h -> "mhpmcounter22h",
    //mhpmcounter23h -> "mhpmcounter23h",
    //mhpmcounter24h -> "mhpmcounter24h",
    //mhpmcounter25h -> "mhpmcounter25h",
    //mhpmcounter26h -> "mhpmcounter26h",
    //mhpmcounter27h -> "mhpmcounter27h",
    //mhpmcounter28h -> "mhpmcounter28h",
    //mhpmcounter29h -> "mhpmcounter29h",
    //mhpmcounter30h -> "mhpmcounter30h",
    //mhpmcounter31h -> "mhpmcounter31h"
  )
}

