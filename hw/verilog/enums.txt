typedef enum logic {
  NONE,
  B,
  HW,
  W
} access_width_t;

typedef enum logic {
  NONE,
  BR,
  JAL,
  JALR,
  RET,
  CALL
} br_type_t;

typedef enum logic {
  NONE,
  LOAD,
  STORE
} memory_type_t;

typedef enum logic {
  INT,
  MEM,
  FP
} RS_types;

typedef enum logic {
  LOAD = 'b00000,
  LOAD_FP = 'b00001,
  CUSTOM_0 = 'b00010,
  MISC_MEM = 'b00011,
  OP_IMM = 'b00100,
  AUIPC = 'b00101,
  OP_IMM_32 = 'b00110,
  STORE = 'b01000,
  STORE_FP = 'b01001,
  CUSTOM_1 = 'b01010,
  AMO = 'b01011,
  OP = 'b01100,
  LUI = 'b01101,
  OP_32 = 'b01110,
  MADD = 'b10000,
  MSUB = 'b10001,
  NMSUB = 'b10010,
  NMADD = 'b10011,
  OP_FP = 'b10100,
  CUSTOM_2 = 'b10110,
  BRANCH = 'b11000,
  JALR = 'b11001,
  JAL = 'b11011,
  SYSTEM = 'b11100,
  CUSTOM_3 = 'b11110
} InstructionType;

