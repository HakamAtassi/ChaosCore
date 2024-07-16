FIRRTL version 4.0.0
circuit instruction_cache :%[[
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|SDPReadWriteSmem",
    "group":"SDPReadWriteSmem"
  },
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|icache_ReadWriteSmem",
    "group":"icache_ReadWriteSmem"
  },
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|icache_ReadWriteSmem_1",
    "group":"icache_ReadWriteSmem"
  },
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|instruction_validator",
    "group":"instruction_validator"
  },
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|Queue1_fetch_packet",
    "group":"Queue1_fetch_packet"
  },
  {
    "class":"firrtl.transforms.DedupGroupAnnotation",
    "target":"~instruction_cache|instruction_cache",
    "group":"instruction_cache"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.CPU_request.bits.wr_en"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.CPU_request.bits.wr_data"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.CPU_request.bits.addr"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.CPU_request.valid"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.CPU_request.ready"
  },
  {
    "class":"chisel3.experimental.EnumAnnotations$EnumComponentAnnotation",
    "target":"instruction_cache.instruction_cache.cache_state",
    "enumTypeName":"ChaosCore.cacheState"
  },
  {
    "class":"chisel3.experimental.EnumAnnotations$EnumDefAnnotation",
    "typeName":"ChaosCore.cacheState",
    "definition":{
      "Active":0,
      "Allocate":1,
      "Replay":2,
      "Stall":3
    }
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.DRAM_response.bits.data"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.DRAM_response.valid"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>io.DRAM_response.ready"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_address.wr_en"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_address.wr_data"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_address.addr"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_packet.instruction_offset"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_packet.fetch_packet"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_packet.set"
  },
  {
    "class":"firrtl.transforms.DontTouchAnnotation",
    "target":"~instruction_cache|instruction_cache>current_packet.tag"
  }
]]
  module SDPReadWriteSmem : @[src/main/scala/memories/memories.scala 83:7]
    input clock : Clock @[src/main/scala/memories/memories.scala 83:7]
    input reset : Reset @[src/main/scala/memories/memories.scala 83:7]
    output io : { flip enable : UInt<1>, flip rd_addr : UInt<6>, data_out : UInt<2>, flip wr_addr : UInt<6>, flip wr_en : UInt<1>, flip data_in : UInt<2>} @[src/main/scala/memories/memories.scala 84:14]

    smem mem : UInt<2> [64] @[src/main/scala/memories/memories.scala 97:24]
    invalidate io.data_out @[src/main/scala/memories/memories.scala 98:15]
    regreset hazard_reg : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/memories/memories.scala 104:27]
    regreset din_buff : UInt<2>, clock, reset, UInt<1>(0h0) @[src/main/scala/memories/memories.scala 105:25]
    node _hazard_reg_T = eq(io.rd_addr, io.wr_addr) @[src/main/scala/memories/memories.scala 107:29]
    node _hazard_reg_T_1 = and(_hazard_reg_T, io.wr_en) @[src/main/scala/memories/memories.scala 107:45]
    connect hazard_reg, _hazard_reg_T_1 @[src/main/scala/memories/memories.scala 107:14]
    connect din_buff, io.data_in @[src/main/scala/memories/memories.scala 108:12]
    wire data_out : UInt<2> @[src/main/scala/memories/memories.scala 114:22]
    connect data_out, UInt<1>(0h0) @[src/main/scala/memories/memories.scala 115:12]
    when io.enable : @[src/main/scala/memories/memories.scala 117:19]
      when io.wr_en : @[src/main/scala/memories/memories.scala 118:20]
        write mport MPORT = mem[io.wr_addr], clock @[src/main/scala/memories/memories.scala 119:16]
        connect MPORT, io.data_in @[src/main/scala/memories/memories.scala 119:16]
      wire _data_out_WIRE : UInt<6> @[src/main/scala/memories/memories.scala 122:25]
      invalidate _data_out_WIRE @[src/main/scala/memories/memories.scala 122:25]
      when io.enable : @[src/main/scala/memories/memories.scala 122:25]
        connect _data_out_WIRE, io.rd_addr @[src/main/scala/memories/memories.scala 122:25]
        read mport data_out_MPORT = mem[_data_out_WIRE], clock @[src/main/scala/memories/memories.scala 122:25]
      connect data_out, data_out_MPORT @[src/main/scala/memories/memories.scala 122:14]
    node _io_data_out_T = mux(hazard_reg, din_buff, data_out) @[src/main/scala/memories/memories.scala 125:23]
    connect io.data_out, _io_data_out_T @[src/main/scala/memories/memories.scala 125:17]

  module icache_ReadWriteSmem : @[src/main/scala/memories/memories.scala 59:7]
    input clock : Clock @[src/main/scala/memories/memories.scala 59:7]
    input reset : Reset @[src/main/scala/memories/memories.scala 59:7]
    output io : { flip enable : UInt<1>, flip wr_en : UInt<1>, flip addr : UInt<6>, flip data_in : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>}, data_out : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>}} @[src/main/scala/memories/memories.scala 60:14]

    smem mem : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>} [64] @[src/main/scala/memories/memories.scala 68:24]
    when io.enable : @[src/main/scala/memories/memories.scala 70:21]
      when io.wr_en : @[src/main/scala/memories/memories.scala 71:22]
        write mport MPORT = mem[io.addr], clock @[src/main/scala/memories/memories.scala 72:18]
        connect MPORT, io.data_in @[src/main/scala/memories/memories.scala 72:18]
    wire _io_data_out_WIRE : UInt<6> @[src/main/scala/memories/memories.scala 76:26]
    invalidate _io_data_out_WIRE @[src/main/scala/memories/memories.scala 76:26]
    when UInt<1>(0h1) : @[src/main/scala/memories/memories.scala 76:26]
      connect _io_data_out_WIRE, io.addr @[src/main/scala/memories/memories.scala 76:26]
      read mport io_data_out_MPORT = mem[_io_data_out_WIRE], clock @[src/main/scala/memories/memories.scala 76:26]
    connect io.data_out, io_data_out_MPORT @[src/main/scala/memories/memories.scala 76:15]

  module icache_ReadWriteSmem_1 : @[src/main/scala/memories/memories.scala 59:7]
    input clock : Clock @[src/main/scala/memories/memories.scala 59:7]
    input reset : Reset @[src/main/scala/memories/memories.scala 59:7]
    output io : { flip enable : UInt<1>, flip wr_en : UInt<1>, flip addr : UInt<6>, flip data_in : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>}, data_out : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>}} @[src/main/scala/memories/memories.scala 60:14]

    smem mem : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>} [64] @[src/main/scala/memories/memories.scala 68:24]
    when io.enable : @[src/main/scala/memories/memories.scala 70:21]
      when io.wr_en : @[src/main/scala/memories/memories.scala 71:22]
        write mport MPORT = mem[io.addr], clock @[src/main/scala/memories/memories.scala 72:18]
        connect MPORT, io.data_in @[src/main/scala/memories/memories.scala 72:18]
    wire _io_data_out_WIRE : UInt<6> @[src/main/scala/memories/memories.scala 76:26]
    invalidate _io_data_out_WIRE @[src/main/scala/memories/memories.scala 76:26]
    when UInt<1>(0h1) : @[src/main/scala/memories/memories.scala 76:26]
      connect _io_data_out_WIRE, io.addr @[src/main/scala/memories/memories.scala 76:26]
      read mport io_data_out_MPORT = mem[_io_data_out_WIRE], clock @[src/main/scala/memories/memories.scala 76:26]
    connect io.data_out, io_data_out_MPORT @[src/main/scala/memories/memories.scala 76:15]

  module instruction_validator : @[src/main/scala/Frontend/instruction_cache.scala 44:7]
    input clock : Clock @[src/main/scala/Frontend/instruction_cache.scala 44:7]
    input reset : Reset @[src/main/scala/Frontend/instruction_cache.scala 44:7]
    output io : { flip instruction_index : UInt<2>, instruction_output : UInt<4>} @[src/main/scala/Frontend/instruction_cache.scala 45:14]

    wire lookupTable : UInt<4>[4] @[src/main/scala/Frontend/instruction_cache.scala 59:14]
    connect lookupTable[0], UInt<4>(0hf) @[src/main/scala/Frontend/instruction_cache.scala 59:14]
    connect lookupTable[1], UInt<4>(0h7) @[src/main/scala/Frontend/instruction_cache.scala 59:14]
    connect lookupTable[2], UInt<4>(0h3) @[src/main/scala/Frontend/instruction_cache.scala 59:14]
    connect lookupTable[3], UInt<4>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 59:14]
    connect io.instruction_output, lookupTable[io.instruction_index] @[src/main/scala/Frontend/instruction_cache.scala 69:25]

  module Queue1_fetch_packet : @[src/main/scala/chisel3/util/Decoupled.scala 243:7]
    input clock : Clock @[src/main/scala/chisel3/util/Decoupled.scala 243:7]
    input reset : Reset @[src/main/scala/chisel3/util/Decoupled.scala 243:7]
    output io : { flip enq : { flip ready : UInt<1>, valid : UInt<1>, bits : { fetch_PC : UInt<32>, valid_bits : UInt<1>[4], instructions : { instruction : UInt<32>, packet_index : UInt<4>, ROB_index : UInt<6>}[4]}}, deq : { flip ready : UInt<1>, valid : UInt<1>, bits : { fetch_PC : UInt<32>, valid_bits : UInt<1>[4], instructions : { instruction : UInt<32>, packet_index : UInt<4>, ROB_index : UInt<6>}[4]}}, count : UInt<1>, flip flush : UInt<1>} @[src/main/scala/chisel3/util/Decoupled.scala 255:14]

    cmem ram : { fetch_PC : UInt<32>, valid_bits : UInt<1>[4], instructions : { instruction : UInt<32>, packet_index : UInt<4>, ROB_index : UInt<6>}[4]} [1] @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
    wire enq_ptr_value : UInt @[src/main/scala/chisel3/util/Counter.scala 61:73]
    connect enq_ptr_value, UInt<1>(0h0) @[src/main/scala/chisel3/util/Counter.scala 61:73]
    wire deq_ptr_value : UInt @[src/main/scala/chisel3/util/Counter.scala 61:73]
    connect deq_ptr_value, UInt<1>(0h0) @[src/main/scala/chisel3/util/Counter.scala 61:73]
    regreset maybe_full : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/chisel3/util/Decoupled.scala 259:27]
    node ptr_match = eq(enq_ptr_value, deq_ptr_value) @[src/main/scala/chisel3/util/Decoupled.scala 260:33]
    node _empty_T = eq(maybe_full, UInt<1>(0h0)) @[src/main/scala/chisel3/util/Decoupled.scala 261:28]
    node empty = and(ptr_match, _empty_T) @[src/main/scala/chisel3/util/Decoupled.scala 261:25]
    node full = and(ptr_match, maybe_full) @[src/main/scala/chisel3/util/Decoupled.scala 262:24]
    node _do_enq_T = and(io.enq.ready, io.enq.valid) @[src/main/scala/chisel3/util/Decoupled.scala 51:35]
    wire do_enq : UInt<1> @[src/main/scala/chisel3/util/Decoupled.scala 263:27]
    connect do_enq, _do_enq_T @[src/main/scala/chisel3/util/Decoupled.scala 263:27]
    node _do_deq_T = and(io.deq.ready, io.deq.valid) @[src/main/scala/chisel3/util/Decoupled.scala 51:35]
    wire do_deq : UInt<1> @[src/main/scala/chisel3/util/Decoupled.scala 264:27]
    connect do_deq, _do_deq_T @[src/main/scala/chisel3/util/Decoupled.scala 264:27]
    when do_enq : @[src/main/scala/chisel3/util/Decoupled.scala 269:16]
      infer mport MPORT = ram[UInt<1>(0h0)], clock @[src/main/scala/chisel3/util/Decoupled.scala 270:8]
      connect MPORT, io.enq.bits @[src/main/scala/chisel3/util/Decoupled.scala 270:24]
    when do_deq : @[src/main/scala/chisel3/util/Decoupled.scala 273:16]
      skip
    node _T = neq(do_enq, do_deq) @[src/main/scala/chisel3/util/Decoupled.scala 276:15]
    when _T : @[src/main/scala/chisel3/util/Decoupled.scala 276:27]
      connect maybe_full, do_enq @[src/main/scala/chisel3/util/Decoupled.scala 277:16]
    when io.flush : @[src/main/scala/chisel3/util/Decoupled.scala 279:15]
      connect enq_ptr_value, UInt<1>(0h0) @[src/main/scala/chisel3/util/Counter.scala 98:11]
      connect deq_ptr_value, UInt<1>(0h0) @[src/main/scala/chisel3/util/Counter.scala 98:11]
      connect maybe_full, UInt<1>(0h0) @[src/main/scala/chisel3/util/Decoupled.scala 282:16]
    node _io_deq_valid_T = eq(empty, UInt<1>(0h0)) @[src/main/scala/chisel3/util/Decoupled.scala 285:19]
    connect io.deq.valid, _io_deq_valid_T @[src/main/scala/chisel3/util/Decoupled.scala 285:16]
    node _io_enq_ready_T = eq(full, UInt<1>(0h0)) @[src/main/scala/chisel3/util/Decoupled.scala 286:19]
    connect io.enq.ready, _io_enq_ready_T @[src/main/scala/chisel3/util/Decoupled.scala 286:16]
    infer mport io_deq_bits_MPORT = ram[UInt<1>(0h0)], clock @[src/main/scala/chisel3/util/Decoupled.scala 293:23]
    connect io.deq.bits, io_deq_bits_MPORT @[src/main/scala/chisel3/util/Decoupled.scala 293:17]
    when io.enq.valid : @[src/main/scala/chisel3/util/Decoupled.scala 297:24]
      connect io.deq.valid, UInt<1>(0h1) @[src/main/scala/chisel3/util/Decoupled.scala 297:39]
    when empty : @[src/main/scala/chisel3/util/Decoupled.scala 298:17]
      connect io.deq.bits, io.enq.bits @[src/main/scala/chisel3/util/Decoupled.scala 299:19]
      connect do_deq, UInt<1>(0h0) @[src/main/scala/chisel3/util/Decoupled.scala 300:14]
      when io.deq.ready : @[src/main/scala/chisel3/util/Decoupled.scala 301:26]
        connect do_enq, UInt<1>(0h0) @[src/main/scala/chisel3/util/Decoupled.scala 301:35]
    node _ptr_diff_T = sub(enq_ptr_value, deq_ptr_value) @[src/main/scala/chisel3/util/Decoupled.scala 309:32]
    node ptr_diff = tail(_ptr_diff_T, 1) @[src/main/scala/chisel3/util/Decoupled.scala 309:32]
    node _io_count_T = and(maybe_full, ptr_match) @[src/main/scala/chisel3/util/Decoupled.scala 312:32]
    node _io_count_T_1 = mux(_io_count_T, UInt<1>(0h1), UInt<1>(0h0)) @[src/main/scala/chisel3/util/Decoupled.scala 312:20]
    node _io_count_T_2 = or(_io_count_T_1, ptr_diff) @[src/main/scala/chisel3/util/Decoupled.scala 312:62]
    connect io.count, _io_count_T_2 @[src/main/scala/chisel3/util/Decoupled.scala 312:14]

  public module instruction_cache : @[src/main/scala/Frontend/instruction_cache.scala 74:7]
    input clock : Clock @[src/main/scala/Frontend/instruction_cache.scala 74:7]
    input reset : UInt<1> @[src/main/scala/Frontend/instruction_cache.scala 74:7]
    output io : { flip flush : UInt<1>, flip CPU_request : { flip ready : UInt<1>, valid : UInt<1>, bits : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>}}, CPU_response : { flip ready : UInt<1>, valid : UInt<1>, bits : { fetch_PC : UInt<32>, valid_bits : UInt<1>[4], instructions : { instruction : UInt<32>, packet_index : UInt<4>, ROB_index : UInt<6>}[4]}}, DRAM_request : { flip ready : UInt<1>, valid : UInt<1>, bits : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>}}, flip DRAM_response : { flip ready : UInt<1>, valid : UInt<1>, bits : { data : UInt<256>}}} @[src/main/scala/Frontend/instruction_cache.scala 104:16]

    wire CPU_response : { flip ready : UInt<1>, valid : UInt<1>, bits : { fetch_PC : UInt<32>, valid_bits : UInt<1>[4], instructions : { instruction : UInt<32>, packet_index : UInt<4>, ROB_index : UInt<6>}[4]}} @[src/main/scala/Frontend/instruction_cache.scala 118:36]
    regreset cache_state : UInt<2>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 124:34]
    wire current_data : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>} @[src/main/scala/Frontend/instruction_cache.scala 126:31]
    wire _fetch_PC_buf_WIRE : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>} @[src/main/scala/Frontend/instruction_cache.scala 127:79]
    connect _fetch_PC_buf_WIRE.wr_en, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 127:79]
    connect _fetch_PC_buf_WIRE.wr_data, UInt<32>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 127:79]
    connect _fetch_PC_buf_WIRE.addr, UInt<32>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 127:79]
    regreset fetch_PC_buf : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>}, clock, reset, _fetch_PC_buf_WIRE @[src/main/scala/Frontend/instruction_cache.scala 127:34]
    wire miss : UInt<1> @[src/main/scala/Frontend/instruction_cache.scala 129:31]
    wire hit : UInt<1> @[src/main/scala/Frontend/instruction_cache.scala 130:31]
    inst LRU_memory of SDPReadWriteSmem @[src/main/scala/Frontend/instruction_cache.scala 133:33]
    connect LRU_memory.clock, clock
    connect LRU_memory.reset, reset
    wire LRU : UInt<2> @[src/main/scala/Frontend/instruction_cache.scala 134:31]
    wire hit_oh : UInt<2> @[src/main/scala/Frontend/instruction_cache.scala 135:31]
    wire LRU_next : UInt<2> @[src/main/scala/Frontend/instruction_cache.scala 136:31]
    wire allocate_way : UInt<2> @[src/main/scala/Frontend/instruction_cache.scala 137:31]
    wire _replay_address_WIRE : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>} @[src/main/scala/Frontend/instruction_cache.scala 140:87]
    connect _replay_address_WIRE.wr_en, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 140:87]
    connect _replay_address_WIRE.wr_data, UInt<32>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 140:87]
    connect _replay_address_WIRE.addr, UInt<32>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 140:87]
    regreset replay_address : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>}, clock, reset, _replay_address_WIRE @[src/main/scala/Frontend/instruction_cache.scala 140:42]
    wire current_packet : { tag : UInt<21>, set : UInt<6>, fetch_packet : UInt<1>, instruction_offset : UInt<3>} @[src/main/scala/Frontend/instruction_cache.scala 142:39]
    inst data_memory_0 of icache_ReadWriteSmem @[src/main/scala/Frontend/instruction_cache.scala 146:15]
    connect data_memory_0.clock, clock
    connect data_memory_0.reset, reset
    inst data_memory_1 of icache_ReadWriteSmem_1 @[src/main/scala/Frontend/instruction_cache.scala 146:15]
    connect data_memory_1.clock, clock
    connect data_memory_1.reset, reset
    wire hit_oh_vec : UInt<1>[2] @[src/main/scala/Frontend/instruction_cache.scala 149:27]
    wire hit_instruction_data : UInt<278> @[src/main/scala/Frontend/instruction_cache.scala 151:36]
    wire instruction_vec : UInt<32>[8] @[src/main/scala/Frontend/instruction_cache.scala 152:36]
    wire aligned_packet_index : UInt<1> @[src/main/scala/Frontend/instruction_cache.scala 153:36]
    node _dram_addr_mask_T = dshl(UInt<1>(0h1), UInt<6>(0h20)) @[src/main/scala/Frontend/instruction_cache.scala 155:32]
    node _dram_addr_mask_T_1 = shl(UInt<1>(0h1), 5) @[src/main/scala/Frontend/instruction_cache.scala 155:48]
    node _dram_addr_mask_T_2 = sub(_dram_addr_mask_T, _dram_addr_mask_T_1) @[src/main/scala/Frontend/instruction_cache.scala 155:41]
    node dram_addr_mask = tail(_dram_addr_mask_T_2, 1) @[src/main/scala/Frontend/instruction_cache.scala 155:41]
    regreset request_valid : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 161:34]
    regreset request_addr : UInt<32>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 162:34]
    regreset request_data : UInt<32>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 163:34]
    regreset request_wr_en : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 164:34]
    regreset resp_ready : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 165:34]
    regreset cache_valid : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 166:34]
    connect io.DRAM_response.ready, resp_ready @[src/main/scala/Frontend/instruction_cache.scala 171:38]
    connect io.DRAM_request.valid, request_valid @[src/main/scala/Frontend/instruction_cache.scala 173:34]
    connect io.DRAM_request.bits.addr, request_addr @[src/main/scala/Frontend/instruction_cache.scala 174:34]
    connect io.DRAM_request.bits.wr_data, request_data @[src/main/scala/Frontend/instruction_cache.scala 175:34]
    connect io.DRAM_request.bits.wr_en, request_wr_en @[src/main/scala/Frontend/instruction_cache.scala 176:34]
    regreset already_requested : UInt<1>, clock, reset, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 179:36]
    node _T = asUInt(UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
    node _T_1 = asUInt(cache_state) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
    node _T_2 = eq(_T, _T_1) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
    when _T_2 : @[src/main/scala/Frontend/instruction_cache.scala 183:24]
      node _T_3 = eq(miss, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 187:22]
      node _T_4 = eq(io.flush, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 187:41]
      node _T_5 = and(_T_3, _T_4) @[src/main/scala/Frontend/instruction_cache.scala 187:29]
      when _T_5 : @[src/main/scala/Frontend/instruction_cache.scala 187:49]
        reg request_addr_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 189:52]
        connect request_addr_REG, io.CPU_request.bits.addr @[src/main/scala/Frontend/instruction_cache.scala 189:52]
        node _request_addr_T = and(request_addr_REG, dram_addr_mask) @[src/main/scala/Frontend/instruction_cache.scala 189:79]
        connect request_addr, _request_addr_T @[src/main/scala/Frontend/instruction_cache.scala 189:42]
        connect request_valid, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 190:42]
        connect resp_ready, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 191:42]
        connect cache_state, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 193:42]
      else :
        connect replay_address, io.CPU_request.bits @[src/main/scala/Frontend/instruction_cache.scala 196:32]
        connect fetch_PC_buf, io.CPU_request.bits @[src/main/scala/Frontend/instruction_cache.scala 197:32]
    else :
      node _T_6 = asUInt(UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
      node _T_7 = asUInt(cache_state) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
      node _T_8 = eq(_T_6, _T_7) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
      when _T_8 : @[src/main/scala/Frontend/instruction_cache.scala 183:24]
        node _T_9 = eq(io.flush, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 202:27]
        when _T_9 : @[src/main/scala/Frontend/instruction_cache.scala 202:35]
          connect cache_state, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 203:29]
          connect cache_valid, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 204:29]
        else :
          node _T_10 = and(io.DRAM_request.ready, io.DRAM_request.valid) @[src/main/scala/Frontend/instruction_cache.scala 207:44]
          when _T_10 : @[src/main/scala/Frontend/instruction_cache.scala 207:69]
            connect request_addr, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 208:46]
            connect request_valid, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 209:46]
          node _T_11 = and(io.DRAM_response.valid, io.DRAM_response.ready) @[src/main/scala/Frontend/instruction_cache.scala 211:45]
          when _T_11 : @[src/main/scala/Frontend/instruction_cache.scala 211:71]
            connect resp_ready, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 212:33]
            connect cache_valid, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 213:33]
            connect cache_state, UInt<2>(0h2) @[src/main/scala/Frontend/instruction_cache.scala 214:33]
      else :
        node _T_12 = asUInt(UInt<2>(0h2)) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
        node _T_13 = asUInt(cache_state) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
        node _T_14 = eq(_T_12, _T_13) @[src/main/scala/Frontend/instruction_cache.scala 183:24]
        when _T_14 : @[src/main/scala/Frontend/instruction_cache.scala 183:24]
          node _T_15 = eq(io.flush, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 220:27]
          when _T_15 : @[src/main/scala/Frontend/instruction_cache.scala 220:35]
            connect cache_state, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 221:29]
            connect cache_valid, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 222:29]
          else :
            node _T_16 = and(CPU_response.valid, CPU_response.ready) @[src/main/scala/Frontend/instruction_cache.scala 224:41]
            when _T_16 : @[src/main/scala/Frontend/instruction_cache.scala 224:63]
              connect cache_valid, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 225:33]
              connect cache_state, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 226:37]
    wire current_address : { addr : UInt<32>, wr_data : UInt<32>, wr_en : UInt<1>} @[src/main/scala/Frontend/instruction_cache.scala 236:31]
    node _current_address_T = neq(cache_state, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 239:43]
    node _current_address_T_1 = or(_current_address_T, miss) @[src/main/scala/Frontend/instruction_cache.scala 239:64]
    node _current_address_T_2 = mux(_current_address_T_1, replay_address, io.CPU_request.bits) @[src/main/scala/Frontend/instruction_cache.scala 239:31]
    connect current_address, _current_address_T_2 @[src/main/scala/Frontend/instruction_cache.scala 239:25]
    wire current_packet_decomposed_icache_address : { tag : UInt<21>, set : UInt<6>, fetch_packet : UInt<1>, instruction_offset : UInt<3>} @[src/main/scala/utils.scala 192:43]
    node _current_packet_decomposed_icache_address_tag_T = bits(current_address.addr, 31, 11) @[src/main/scala/utils.scala 194:63]
    connect current_packet_decomposed_icache_address.tag, _current_packet_decomposed_icache_address_tag_T @[src/main/scala/utils.scala 194:53]
    node _current_packet_decomposed_icache_address_set_T = bits(current_address.addr, 10, 5) @[src/main/scala/utils.scala 195:63]
    connect current_packet_decomposed_icache_address.set, _current_packet_decomposed_icache_address_set_T @[src/main/scala/utils.scala 195:53]
    node _current_packet_decomposed_icache_address_fetch_packet_T = bits(current_address.addr, 4, 4) @[src/main/scala/utils.scala 196:63]
    connect current_packet_decomposed_icache_address.fetch_packet, _current_packet_decomposed_icache_address_fetch_packet_T @[src/main/scala/utils.scala 196:53]
    node _current_packet_decomposed_icache_address_instruction_offset_T = bits(current_address.addr, 4, 2) @[src/main/scala/utils.scala 197:63]
    connect current_packet_decomposed_icache_address.instruction_offset, _current_packet_decomposed_icache_address_instruction_offset_T @[src/main/scala/utils.scala 197:53]
    connect current_packet, current_packet_decomposed_icache_address @[src/main/scala/Frontend/instruction_cache.scala 240:25]
    connect LRU_memory.io.enable, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 249:27]
    connect LRU_memory.io.rd_addr, current_packet.set @[src/main/scala/Frontend/instruction_cache.scala 250:27]
    reg LRU_memory_io_wr_addr_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 251:37]
    connect LRU_memory_io_wr_addr_REG, current_packet.set @[src/main/scala/Frontend/instruction_cache.scala 251:37]
    connect LRU_memory.io.wr_addr, LRU_memory_io_wr_addr_REG @[src/main/scala/Frontend/instruction_cache.scala 251:27]
    connect LRU_memory.io.wr_en, hit @[src/main/scala/Frontend/instruction_cache.scala 252:27]
    connect LRU_memory.io.data_in, LRU_next @[src/main/scala/Frontend/instruction_cache.scala 253:27]
    connect LRU, LRU_memory.io.data_out @[src/main/scala/Frontend/instruction_cache.scala 255:9]
    node _LRU_next_T = or(LRU, hit_oh) @[src/main/scala/Frontend/instruction_cache.scala 257:26]
    node _LRU_next_T_1 = andr(_LRU_next_T) @[src/main/scala/Frontend/instruction_cache.scala 257:36]
    node _LRU_next_T_2 = or(LRU, hit_oh) @[src/main/scala/Frontend/instruction_cache.scala 257:54]
    node _LRU_next_T_3 = mux(_LRU_next_T_1, hit_oh, _LRU_next_T_2) @[src/main/scala/Frontend/instruction_cache.scala 257:20]
    connect LRU_next, _LRU_next_T_3 @[src/main/scala/Frontend/instruction_cache.scala 257:14]
    connect allocate_way, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 259:18]
    node _T_17 = bits(LRU, 0, 0) @[src/main/scala/Frontend/instruction_cache.scala 261:17]
    node _T_18 = eq(_T_17, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 261:21]
    when _T_18 : @[src/main/scala/Frontend/instruction_cache.scala 261:29]
      node _allocate_way_T = shl(UInt<1>(0h1), 0) @[src/main/scala/Frontend/instruction_cache.scala 262:33]
      connect allocate_way, _allocate_way_T @[src/main/scala/Frontend/instruction_cache.scala 262:26]
    node _T_19 = bits(LRU, 1, 1) @[src/main/scala/Frontend/instruction_cache.scala 261:17]
    node _T_20 = eq(_T_19, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 261:21]
    when _T_20 : @[src/main/scala/Frontend/instruction_cache.scala 261:29]
      node _allocate_way_T_1 = shl(UInt<1>(0h1), 1) @[src/main/scala/Frontend/instruction_cache.scala 262:33]
      connect allocate_way, _allocate_way_T_1 @[src/main/scala/Frontend/instruction_cache.scala 262:26]
    connect current_data.valid, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 270:25]
    wire current_data_tag_decomposed_icache_address : { tag : UInt<21>, set : UInt<6>, fetch_packet : UInt<1>, instruction_offset : UInt<3>} @[src/main/scala/utils.scala 192:43]
    node _current_data_tag_decomposed_icache_address_tag_T = bits(replay_address.addr, 31, 11) @[src/main/scala/utils.scala 194:63]
    connect current_data_tag_decomposed_icache_address.tag, _current_data_tag_decomposed_icache_address_tag_T @[src/main/scala/utils.scala 194:53]
    node _current_data_tag_decomposed_icache_address_set_T = bits(replay_address.addr, 10, 5) @[src/main/scala/utils.scala 195:63]
    connect current_data_tag_decomposed_icache_address.set, _current_data_tag_decomposed_icache_address_set_T @[src/main/scala/utils.scala 195:53]
    node _current_data_tag_decomposed_icache_address_fetch_packet_T = bits(replay_address.addr, 4, 4) @[src/main/scala/utils.scala 196:63]
    connect current_data_tag_decomposed_icache_address.fetch_packet, _current_data_tag_decomposed_icache_address_fetch_packet_T @[src/main/scala/utils.scala 196:53]
    node _current_data_tag_decomposed_icache_address_instruction_offset_T = bits(replay_address.addr, 4, 2) @[src/main/scala/utils.scala 197:63]
    connect current_data_tag_decomposed_icache_address.instruction_offset, _current_data_tag_decomposed_icache_address_instruction_offset_T @[src/main/scala/utils.scala 197:53]
    connect current_data.tag, current_data_tag_decomposed_icache_address.tag @[src/main/scala/Frontend/instruction_cache.scala 271:25]
    connect current_data.data, io.DRAM_response.bits.data @[src/main/scala/Frontend/instruction_cache.scala 272:25]
    wire data_way : { valid : UInt<1>, tag : UInt<21>, data : UInt<256>}[2] @[src/main/scala/Frontend/instruction_cache.scala 278:27]
    connect data_memory_0.io.enable, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 280:37]
    connect data_memory_0.io.addr, current_packet.set @[src/main/scala/Frontend/instruction_cache.scala 281:37]
    connect data_way[0], data_memory_0.io.data_out @[src/main/scala/Frontend/instruction_cache.scala 282:37]
    connect data_memory_1.io.enable, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 280:37]
    connect data_memory_1.io.addr, current_packet.set @[src/main/scala/Frontend/instruction_cache.scala 281:37]
    connect data_way[1], data_memory_1.io.data_out @[src/main/scala/Frontend/instruction_cache.scala 282:37]
    node _data_memory_0_io_wr_en_T = bits(allocate_way, 0, 0) @[src/main/scala/Frontend/instruction_cache.scala 290:77]
    node _data_memory_0_io_wr_en_T_1 = and(io.DRAM_response.valid, _data_memory_0_io_wr_en_T) @[src/main/scala/Frontend/instruction_cache.scala 290:63]
    node _data_memory_0_io_wr_en_T_2 = eq(cache_state, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 290:99]
    node _data_memory_0_io_wr_en_T_3 = and(_data_memory_0_io_wr_en_T_1, _data_memory_0_io_wr_en_T_2) @[src/main/scala/Frontend/instruction_cache.scala 290:83]
    connect data_memory_0.io.wr_en, _data_memory_0_io_wr_en_T_3 @[src/main/scala/Frontend/instruction_cache.scala 290:37]
    connect data_memory_0.io.data_in.data, current_data.data @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    connect data_memory_0.io.data_in.tag, current_data.tag @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    connect data_memory_0.io.data_in.valid, current_data.valid @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    node _data_memory_1_io_wr_en_T = bits(allocate_way, 1, 1) @[src/main/scala/Frontend/instruction_cache.scala 290:77]
    node _data_memory_1_io_wr_en_T_1 = and(io.DRAM_response.valid, _data_memory_1_io_wr_en_T) @[src/main/scala/Frontend/instruction_cache.scala 290:63]
    node _data_memory_1_io_wr_en_T_2 = eq(cache_state, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 290:99]
    node _data_memory_1_io_wr_en_T_3 = and(_data_memory_1_io_wr_en_T_1, _data_memory_1_io_wr_en_T_2) @[src/main/scala/Frontend/instruction_cache.scala 290:83]
    connect data_memory_1.io.wr_en, _data_memory_1_io_wr_en_T_3 @[src/main/scala/Frontend/instruction_cache.scala 290:37]
    connect data_memory_1.io.data_in.data, current_data.data @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    connect data_memory_1.io.data_in.tag, current_data.tag @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    connect data_memory_1.io.data_in.valid, current_data.valid @[src/main/scala/Frontend/instruction_cache.scala 291:37]
    reg hit_oh_vec_0_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 296:56]
    connect hit_oh_vec_0_REG, current_packet.tag @[src/main/scala/Frontend/instruction_cache.scala 296:56]
    node _hit_oh_vec_0_T = eq(data_way[0].tag, hit_oh_vec_0_REG) @[src/main/scala/Frontend/instruction_cache.scala 296:45]
    node _hit_oh_vec_0_T_1 = and(_hit_oh_vec_0_T, data_way[0].valid) @[src/main/scala/Frontend/instruction_cache.scala 296:78]
    connect hit_oh_vec[0], _hit_oh_vec_0_T_1 @[src/main/scala/Frontend/instruction_cache.scala 296:23]
    reg hit_oh_vec_1_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 296:56]
    connect hit_oh_vec_1_REG, current_packet.tag @[src/main/scala/Frontend/instruction_cache.scala 296:56]
    node _hit_oh_vec_1_T = eq(data_way[1].tag, hit_oh_vec_1_REG) @[src/main/scala/Frontend/instruction_cache.scala 296:45]
    node _hit_oh_vec_1_T_1 = and(_hit_oh_vec_1_T, data_way[1].valid) @[src/main/scala/Frontend/instruction_cache.scala 296:78]
    connect hit_oh_vec[1], _hit_oh_vec_1_T_1 @[src/main/scala/Frontend/instruction_cache.scala 296:23]
    node _hit_oh_T = cat(hit_oh_vec[1], hit_oh_vec[0]) @[src/main/scala/Frontend/instruction_cache.scala 299:43]
    connect hit_oh, _hit_oh_T @[src/main/scala/Frontend/instruction_cache.scala 299:12]
    wire replay_valid : UInt<1> @[src/main/scala/Frontend/instruction_cache.scala 302:28]
    node _replay_valid_T = eq(cache_state, UInt<2>(0h2)) @[src/main/scala/Frontend/instruction_cache.scala 303:33]
    connect replay_valid, _replay_valid_T @[src/main/scala/Frontend/instruction_cache.scala 303:18]
    node _hit_T = orr(hit_oh) @[src/main/scala/Frontend/instruction_cache.scala 305:24]
    node _hit_T_1 = eq(cache_state, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 305:75]
    node _hit_T_2 = and(io.CPU_request.valid, _hit_T_1) @[src/main/scala/Frontend/instruction_cache.scala 305:60]
    reg hit_REG : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 305:38]
    connect hit_REG, _hit_T_2 @[src/main/scala/Frontend/instruction_cache.scala 305:38]
    node _hit_T_3 = or(hit_REG, replay_valid) @[src/main/scala/Frontend/instruction_cache.scala 305:98]
    node _hit_T_4 = and(_hit_T, _hit_T_3) @[src/main/scala/Frontend/instruction_cache.scala 305:28]
    reg hit_REG_1 : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 305:125]
    connect hit_REG_1, io.flush @[src/main/scala/Frontend/instruction_cache.scala 305:125]
    node _hit_T_5 = eq(hit_REG_1, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 305:117]
    node _hit_T_6 = and(_hit_T_4, _hit_T_5) @[src/main/scala/Frontend/instruction_cache.scala 305:115]
    reg hit_REG_2 : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 305:146]
    connect hit_REG_2, reset @[src/main/scala/Frontend/instruction_cache.scala 305:146]
    node _hit_T_7 = eq(hit_REG_2, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 305:138]
    node _hit_T_8 = and(_hit_T_6, _hit_T_7) @[src/main/scala/Frontend/instruction_cache.scala 305:136]
    connect hit, _hit_T_8 @[src/main/scala/Frontend/instruction_cache.scala 305:13]
    node _miss_T = orr(hit_oh) @[src/main/scala/Frontend/instruction_cache.scala 306:25]
    node _miss_T_1 = not(_miss_T) @[src/main/scala/Frontend/instruction_cache.scala 306:17]
    reg miss_REG : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 306:40]
    connect miss_REG, io.CPU_request.valid @[src/main/scala/Frontend/instruction_cache.scala 306:40]
    node _miss_T_2 = or(miss_REG, replay_valid) @[src/main/scala/Frontend/instruction_cache.scala 306:63]
    node _miss_T_3 = and(_miss_T_1, _miss_T_2) @[src/main/scala/Frontend/instruction_cache.scala 306:30]
    reg miss_REG_1 : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 306:89]
    connect miss_REG_1, io.flush @[src/main/scala/Frontend/instruction_cache.scala 306:89]
    node _miss_T_4 = eq(miss_REG_1, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 306:81]
    node _miss_T_5 = and(_miss_T_3, _miss_T_4) @[src/main/scala/Frontend/instruction_cache.scala 306:79]
    reg miss_REG_2 : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 306:110]
    connect miss_REG_2, reset @[src/main/scala/Frontend/instruction_cache.scala 306:110]
    node _miss_T_6 = eq(miss_REG_2, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 306:102]
    node _miss_T_7 = and(_miss_T_5, _miss_T_6) @[src/main/scala/Frontend/instruction_cache.scala 306:100]
    connect miss, _miss_T_7 @[src/main/scala/Frontend/instruction_cache.scala 306:13]
    reg aligned_packet_index_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 312:36]
    connect aligned_packet_index_REG, current_packet.fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 312:36]
    node _aligned_packet_index_T = mul(UInt<3>(0h4), UInt<3>(0h4)) @[src/main/scala/Frontend/instruction_cache.scala 312:83]
    node _aligned_packet_index_T_1 = sub(_aligned_packet_index_T, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 312:89]
    node _aligned_packet_index_T_2 = tail(_aligned_packet_index_T_1, 1) @[src/main/scala/Frontend/instruction_cache.scala 312:89]
    node _aligned_packet_index_T_3 = not(_aligned_packet_index_T_2) @[src/main/scala/Frontend/instruction_cache.scala 312:68]
    node _aligned_packet_index_T_4 = and(aligned_packet_index_REG, _aligned_packet_index_T_3) @[src/main/scala/Frontend/instruction_cache.scala 312:66]
    connect aligned_packet_index, _aligned_packet_index_T_4 @[src/main/scala/Frontend/instruction_cache.scala 312:26]
    connect hit_instruction_data, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 315:26]
    node _T_21 = bits(hit_oh, 0, 0) @[src/main/scala/Frontend/instruction_cache.scala 317:20]
    node _T_22 = eq(_T_21, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 317:23]
    when _T_22 : @[src/main/scala/Frontend/instruction_cache.scala 317:30]
      connect hit_instruction_data, data_way[0].data @[src/main/scala/Frontend/instruction_cache.scala 318:34]
    node _T_23 = bits(hit_oh, 1, 1) @[src/main/scala/Frontend/instruction_cache.scala 317:20]
    node _T_24 = eq(_T_23, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 317:23]
    when _T_24 : @[src/main/scala/Frontend/instruction_cache.scala 317:30]
      connect hit_instruction_data, data_way[1].data @[src/main/scala/Frontend/instruction_cache.scala 318:34]
    node _instruction_vec_0_T = bits(hit_instruction_data, 31, 0) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[0], _instruction_vec_0_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_1_T = bits(hit_instruction_data, 63, 32) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[1], _instruction_vec_1_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_2_T = bits(hit_instruction_data, 95, 64) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[2], _instruction_vec_2_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_3_T = bits(hit_instruction_data, 127, 96) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[3], _instruction_vec_3_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_4_T = bits(hit_instruction_data, 159, 128) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[4], _instruction_vec_4_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_5_T = bits(hit_instruction_data, 191, 160) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[5], _instruction_vec_5_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_6_T = bits(hit_instruction_data, 223, 192) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[6], _instruction_vec_6_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    node _instruction_vec_7_T = bits(hit_instruction_data, 255, 224) @[src/main/scala/Frontend/instruction_cache.scala 323:61]
    connect instruction_vec[7], _instruction_vec_7_T @[src/main/scala/Frontend/instruction_cache.scala 323:38]
    reg CPU_response_bits_instructions_0_instruction_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    connect CPU_response_bits_instructions_0_instruction_REG, current_packet.fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    node _CPU_response_bits_instructions_0_instruction_T = mul(CPU_response_bits_instructions_0_instruction_REG, UInt<3>(0h4)) @[src/main/scala/Frontend/instruction_cache.scala 327:111]
    node _CPU_response_bits_instructions_0_instruction_T_1 = add(_CPU_response_bits_instructions_0_instruction_T, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_0_instruction_T_2 = tail(_CPU_response_bits_instructions_0_instruction_T_1, 1) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_0_instruction_T_3 = or(_CPU_response_bits_instructions_0_instruction_T_2, UInt<3>(0h0))
    node _CPU_response_bits_instructions_0_instruction_T_4 = bits(_CPU_response_bits_instructions_0_instruction_T_3, 2, 0)
    connect CPU_response.bits.instructions[0].instruction, instruction_vec[_CPU_response_bits_instructions_0_instruction_T_4] @[src/main/scala/Frontend/instruction_cache.scala 327:56]
    connect CPU_response.bits.instructions[0].packet_index, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 328:56]
    connect CPU_response.bits.instructions[0].ROB_index, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 329:56]
    reg CPU_response_bits_instructions_1_instruction_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    connect CPU_response_bits_instructions_1_instruction_REG, current_packet.fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    node _CPU_response_bits_instructions_1_instruction_T = mul(CPU_response_bits_instructions_1_instruction_REG, UInt<3>(0h4)) @[src/main/scala/Frontend/instruction_cache.scala 327:111]
    node _CPU_response_bits_instructions_1_instruction_T_1 = add(_CPU_response_bits_instructions_1_instruction_T, UInt<1>(0h1)) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_1_instruction_T_2 = tail(_CPU_response_bits_instructions_1_instruction_T_1, 1) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_1_instruction_T_3 = or(_CPU_response_bits_instructions_1_instruction_T_2, UInt<3>(0h0))
    node _CPU_response_bits_instructions_1_instruction_T_4 = bits(_CPU_response_bits_instructions_1_instruction_T_3, 2, 0)
    connect CPU_response.bits.instructions[1].instruction, instruction_vec[_CPU_response_bits_instructions_1_instruction_T_4] @[src/main/scala/Frontend/instruction_cache.scala 327:56]
    connect CPU_response.bits.instructions[1].packet_index, UInt<1>(0h1) @[src/main/scala/Frontend/instruction_cache.scala 328:56]
    connect CPU_response.bits.instructions[1].ROB_index, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 329:56]
    reg CPU_response_bits_instructions_2_instruction_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    connect CPU_response_bits_instructions_2_instruction_REG, current_packet.fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    node _CPU_response_bits_instructions_2_instruction_T = mul(CPU_response_bits_instructions_2_instruction_REG, UInt<3>(0h4)) @[src/main/scala/Frontend/instruction_cache.scala 327:111]
    node _CPU_response_bits_instructions_2_instruction_T_1 = add(_CPU_response_bits_instructions_2_instruction_T, UInt<2>(0h2)) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_2_instruction_T_2 = tail(_CPU_response_bits_instructions_2_instruction_T_1, 1) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_2_instruction_T_3 = or(_CPU_response_bits_instructions_2_instruction_T_2, UInt<3>(0h0))
    node _CPU_response_bits_instructions_2_instruction_T_4 = bits(_CPU_response_bits_instructions_2_instruction_T_3, 2, 0)
    connect CPU_response.bits.instructions[2].instruction, instruction_vec[_CPU_response_bits_instructions_2_instruction_T_4] @[src/main/scala/Frontend/instruction_cache.scala 327:56]
    connect CPU_response.bits.instructions[2].packet_index, UInt<2>(0h2) @[src/main/scala/Frontend/instruction_cache.scala 328:56]
    connect CPU_response.bits.instructions[2].ROB_index, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 329:56]
    reg CPU_response_bits_instructions_3_instruction_REG : UInt, clock @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    connect CPU_response_bits_instructions_3_instruction_REG, current_packet.fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 327:82]
    node _CPU_response_bits_instructions_3_instruction_T = mul(CPU_response_bits_instructions_3_instruction_REG, UInt<3>(0h4)) @[src/main/scala/Frontend/instruction_cache.scala 327:111]
    node _CPU_response_bits_instructions_3_instruction_T_1 = add(_CPU_response_bits_instructions_3_instruction_T, UInt<2>(0h3)) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_3_instruction_T_2 = tail(_CPU_response_bits_instructions_3_instruction_T_1, 1) @[src/main/scala/Frontend/instruction_cache.scala 327:125]
    node _CPU_response_bits_instructions_3_instruction_T_3 = or(_CPU_response_bits_instructions_3_instruction_T_2, UInt<3>(0h0))
    node _CPU_response_bits_instructions_3_instruction_T_4 = bits(_CPU_response_bits_instructions_3_instruction_T_3, 2, 0)
    connect CPU_response.bits.instructions[3].instruction, instruction_vec[_CPU_response_bits_instructions_3_instruction_T_4] @[src/main/scala/Frontend/instruction_cache.scala 327:56]
    connect CPU_response.bits.instructions[3].packet_index, UInt<2>(0h3) @[src/main/scala/Frontend/instruction_cache.scala 328:56]
    connect CPU_response.bits.instructions[3].ROB_index, UInt<1>(0h0) @[src/main/scala/Frontend/instruction_cache.scala 329:56]
    inst validator of instruction_validator @[src/main/scala/Frontend/instruction_cache.scala 332:27]
    connect validator.clock, clock
    connect validator.reset, reset
    wire test_decomposed_icache_address : { tag : UInt<21>, set : UInt<6>, fetch_packet : UInt<1>, instruction_offset : UInt<3>} @[src/main/scala/utils.scala 192:43]
    node _test_decomposed_icache_address_tag_T = bits(CPU_response.bits.fetch_PC, 31, 11) @[src/main/scala/utils.scala 194:63]
    connect test_decomposed_icache_address.tag, _test_decomposed_icache_address_tag_T @[src/main/scala/utils.scala 194:53]
    node _test_decomposed_icache_address_set_T = bits(CPU_response.bits.fetch_PC, 10, 5) @[src/main/scala/utils.scala 195:63]
    connect test_decomposed_icache_address.set, _test_decomposed_icache_address_set_T @[src/main/scala/utils.scala 195:53]
    node _test_decomposed_icache_address_fetch_packet_T = bits(CPU_response.bits.fetch_PC, 4, 4) @[src/main/scala/utils.scala 196:63]
    connect test_decomposed_icache_address.fetch_packet, _test_decomposed_icache_address_fetch_packet_T @[src/main/scala/utils.scala 196:53]
    node _test_decomposed_icache_address_instruction_offset_T = bits(CPU_response.bits.fetch_PC, 4, 2) @[src/main/scala/utils.scala 197:63]
    connect test_decomposed_icache_address.instruction_offset, _test_decomposed_icache_address_instruction_offset_T @[src/main/scala/utils.scala 197:53]
    connect validator.io.instruction_index, test_decomposed_icache_address.instruction_offset @[src/main/scala/Frontend/instruction_cache.scala 337:36]
    node _CPU_response_bits_valid_bits_0_T = bits(validator.io.instruction_output, 3, 3) @[src/main/scala/Frontend/instruction_cache.scala 340:74]
    node _CPU_response_bits_valid_bits_0_T_1 = and(_CPU_response_bits_valid_bits_0_T, CPU_response.valid) @[src/main/scala/Frontend/instruction_cache.scala 340:91]
    connect CPU_response.bits.valid_bits[0], _CPU_response_bits_valid_bits_0_T_1 @[src/main/scala/Frontend/instruction_cache.scala 340:40]
    node _CPU_response_bits_valid_bits_1_T = bits(validator.io.instruction_output, 2, 2) @[src/main/scala/Frontend/instruction_cache.scala 340:74]
    node _CPU_response_bits_valid_bits_1_T_1 = and(_CPU_response_bits_valid_bits_1_T, CPU_response.valid) @[src/main/scala/Frontend/instruction_cache.scala 340:91]
    connect CPU_response.bits.valid_bits[1], _CPU_response_bits_valid_bits_1_T_1 @[src/main/scala/Frontend/instruction_cache.scala 340:40]
    node _CPU_response_bits_valid_bits_2_T = bits(validator.io.instruction_output, 1, 1) @[src/main/scala/Frontend/instruction_cache.scala 340:74]
    node _CPU_response_bits_valid_bits_2_T_1 = and(_CPU_response_bits_valid_bits_2_T, CPU_response.valid) @[src/main/scala/Frontend/instruction_cache.scala 340:91]
    connect CPU_response.bits.valid_bits[2], _CPU_response_bits_valid_bits_2_T_1 @[src/main/scala/Frontend/instruction_cache.scala 340:40]
    node _CPU_response_bits_valid_bits_3_T = bits(validator.io.instruction_output, 0, 0) @[src/main/scala/Frontend/instruction_cache.scala 340:74]
    node _CPU_response_bits_valid_bits_3_T_1 = and(_CPU_response_bits_valid_bits_3_T, CPU_response.valid) @[src/main/scala/Frontend/instruction_cache.scala 340:91]
    connect CPU_response.bits.valid_bits[3], _CPU_response_bits_valid_bits_3_T_1 @[src/main/scala/Frontend/instruction_cache.scala 340:40]
    node _CPU_response_valid_T = or(cache_valid, hit) @[src/main/scala/Frontend/instruction_cache.scala 349:44]
    reg CPU_response_valid_REG : UInt<1>, clock @[src/main/scala/Frontend/instruction_cache.scala 349:76]
    connect CPU_response_valid_REG, io.flush @[src/main/scala/Frontend/instruction_cache.scala 349:76]
    node _CPU_response_valid_T_1 = or(io.flush, CPU_response_valid_REG) @[src/main/scala/Frontend/instruction_cache.scala 349:66]
    node _CPU_response_valid_T_2 = eq(_CPU_response_valid_T_1, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 349:55]
    node _CPU_response_valid_T_3 = and(_CPU_response_valid_T, _CPU_response_valid_T_2) @[src/main/scala/Frontend/instruction_cache.scala 349:52]
    connect CPU_response.valid, _CPU_response_valid_T_3 @[src/main/scala/Frontend/instruction_cache.scala 349:28]
    node _io_CPU_request_ready_T = eq(cache_state, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 356:42]
    node _io_CPU_request_ready_T_1 = eq(miss, UInt<1>(0h0)) @[src/main/scala/Frontend/instruction_cache.scala 356:68]
    node _io_CPU_request_ready_T_2 = and(_io_CPU_request_ready_T, _io_CPU_request_ready_T_1) @[src/main/scala/Frontend/instruction_cache.scala 356:65]
    node _io_CPU_request_ready_T_3 = and(_io_CPU_request_ready_T_2, io.CPU_response.ready) @[src/main/scala/Frontend/instruction_cache.scala 356:74]
    connect io.CPU_request.ready, _io_CPU_request_ready_T_3 @[src/main/scala/Frontend/instruction_cache.scala 356:26]
    inst CPU_response_skid_buffer of Queue1_fetch_packet @[src/main/scala/Frontend/instruction_cache.scala 358:50]
    connect CPU_response_skid_buffer.clock, clock
    connect CPU_response_skid_buffer.reset, reset
    connect CPU_response_skid_buffer.io.enq, CPU_response @[src/main/scala/Frontend/instruction_cache.scala 360:54]
    connect CPU_response_skid_buffer.io.flush, io.flush @[src/main/scala/Frontend/instruction_cache.scala 361:54]
    connect CPU_response.bits.fetch_PC, fetch_PC_buf.addr @[src/main/scala/Frontend/instruction_cache.scala 363:32]
    connect io.CPU_response.bits, CPU_response_skid_buffer.io.deq.bits @[src/main/scala/Frontend/instruction_cache.scala 365:54]
    connect io.CPU_response.valid, CPU_response_skid_buffer.io.deq.valid @[src/main/scala/Frontend/instruction_cache.scala 365:54]
    connect CPU_response_skid_buffer.io.deq.ready, io.CPU_response.ready @[src/main/scala/Frontend/instruction_cache.scala 365:54]
    node has_been_reset = intrinsic(circt_has_been_reset : UInt<1>, clock, reset) @[src/main/scala/chisel3/ltl/LTL.scala 422:39]
    node disable = eq(has_been_reset, UInt<1>(0h0)) @[src/main/scala/chisel3/ltl/LTL.scala 422:39]
    node disable_1 = intrinsic(circt_ltl_disable : UInt<1>, io.CPU_response.valid, disable) @[src/main/scala/Frontend/instruction_cache.scala 369:18]
    node clock_1 = intrinsic(circt_ltl_clock : UInt<1>, disable_1, clock) @[src/main/scala/Frontend/instruction_cache.scala 369:18]
    intrinsic(circt_verif_cover, clock_1) @[src/main/scala/Frontend/instruction_cache.scala 369:18]
