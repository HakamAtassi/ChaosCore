FIRRTL version 1.2.0
circuit DecoupledGcd :
  module DecoupledGcd :
    input clock : Clock
    input reset : UInt<1>
    output input_ready : UInt<1> @[src/main/scala/gcd/DecoupledGCD.scala 27:17]
    input input_valid : UInt<1> @[src/main/scala/gcd/DecoupledGCD.scala 27:17]
    input input_bits_value1 : UInt<16> @[src/main/scala/gcd/DecoupledGCD.scala 27:17]
    input input_bits_value2 : UInt<16> @[src/main/scala/gcd/DecoupledGCD.scala 27:17]
    input output_ready : UInt<1> @[src/main/scala/gcd/DecoupledGCD.scala 28:18]
    output output_valid : UInt<1> @[src/main/scala/gcd/DecoupledGCD.scala 28:18]
    output output_bits_value1 : UInt<16> @[src/main/scala/gcd/DecoupledGCD.scala 28:18]
    output output_bits_value2 : UInt<16> @[src/main/scala/gcd/DecoupledGCD.scala 28:18]
    output output_bits_gcd : UInt<16> @[src/main/scala/gcd/DecoupledGCD.scala 28:18]

    reg xInitial : UInt<16>, clock with :
      reset => (UInt<1>("h0"), xInitial) @[src/main/scala/gcd/DecoupledGCD.scala 30:24]
    reg yInitial : UInt<16>, clock with :
      reset => (UInt<1>("h0"), yInitial) @[src/main/scala/gcd/DecoupledGCD.scala 31:24]
    reg x : UInt<16>, clock with :
      reset => (UInt<1>("h0"), x) @[src/main/scala/gcd/DecoupledGCD.scala 32:24]
    reg y : UInt<16>, clock with :
      reset => (UInt<1>("h0"), y) @[src/main/scala/gcd/DecoupledGCD.scala 33:24]
    reg busy : UInt<1>, clock with :
      reset => (UInt<1>("h0"), busy) @[src/main/scala/gcd/DecoupledGCD.scala 34:28]
    reg resultValid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), resultValid) @[src/main/scala/gcd/DecoupledGCD.scala 35:28]
    node _input_ready_T = eq(busy, UInt<1>("h0")) @[src/main/scala/gcd/DecoupledGCD.scala 37:18]
    node _T = gt(x, y) @[src/main/scala/gcd/DecoupledGCD.scala 42:12]
    node _x_T = sub(x, y) @[src/main/scala/gcd/DecoupledGCD.scala 43:14]
    node _x_T_1 = tail(_x_T, 1) @[src/main/scala/gcd/DecoupledGCD.scala 43:14]
    node _y_T = sub(y, x) @[src/main/scala/gcd/DecoupledGCD.scala 45:14]
    node _y_T_1 = tail(_y_T, 1) @[src/main/scala/gcd/DecoupledGCD.scala 45:14]
    node _GEN_0 = mux(_T, _x_T_1, x) @[src/main/scala/gcd/DecoupledGCD.scala 42:17 32:24 43:9]
    node _GEN_1 = mux(_T, y, _y_T_1) @[src/main/scala/gcd/DecoupledGCD.scala 42:17 33:24 45:9]
    node _T_1 = eq(x, UInt<1>("h0")) @[src/main/scala/gcd/DecoupledGCD.scala 47:12]
    node _T_2 = eq(y, UInt<1>("h0")) @[src/main/scala/gcd/DecoupledGCD.scala 47:25]
    node _T_3 = or(_T_1, _T_2) @[src/main/scala/gcd/DecoupledGCD.scala 47:20]
    node _T_4 = eq(x, UInt<1>("h0")) @[src/main/scala/gcd/DecoupledGCD.scala 48:14]
    node _GEN_2 = mux(_T_4, y, x) @[src/main/scala/gcd/DecoupledGCD.scala 48:23 49:25 51:25]
    node _T_5 = and(output_ready, resultValid) @[src/main/scala/gcd/DecoupledGCD.scala 58:25]
    node _GEN_3 = mux(_T_5, UInt<1>("h0"), busy) @[src/main/scala/gcd/DecoupledGCD.scala 58:41 59:14 34:28]
    node _GEN_4 = mux(_T_5, UInt<1>("h0"), UInt<1>("h1")) @[src/main/scala/gcd/DecoupledGCD.scala 56:19 58:41 60:21]
    node _GEN_5 = validif(_T_3, _GEN_2) @[src/main/scala/gcd/DecoupledGCD.scala 47:34]
    node _GEN_6 = validif(_T_3, xInitial) @[src/main/scala/gcd/DecoupledGCD.scala 47:34 54:26]
    node _GEN_7 = validif(_T_3, yInitial) @[src/main/scala/gcd/DecoupledGCD.scala 47:34 55:26]
    node _GEN_8 = mux(_T_3, _GEN_4, resultValid) @[src/main/scala/gcd/DecoupledGCD.scala 35:28 47:34]
    node _GEN_9 = mux(_T_3, _GEN_3, busy) @[src/main/scala/gcd/DecoupledGCD.scala 34:28 47:34]
    node _GEN_10 = mux(input_valid, UInt<1>("h1"), _input_ready_T) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 src/main/scala/chisel3/util/Decoupled.scala 77:20 src/main/scala/gcd/DecoupledGCD.scala 37:15]
    node _GEN_11 = mux(input_valid, input_bits_value1, x) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 32:24 66:9]
    node _GEN_12 = mux(input_valid, input_bits_value2, y) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 33:24 67:9]
    node _GEN_13 = mux(input_valid, input_bits_value1, xInitial) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 68:16 30:24]
    node _GEN_14 = mux(input_valid, input_bits_value2, yInitial) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 69:16 31:24]
    node _GEN_15 = mux(input_valid, UInt<1>("h1"), busy) @[src/main/scala/gcd/DecoupledGCD.scala 64:23 70:12 34:28]
    node _GEN_16 = mux(busy, _GEN_0, _GEN_11) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_17 = mux(busy, _GEN_1, _GEN_12) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_18 = validif(busy, _GEN_5) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_19 = validif(busy, _GEN_6) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_20 = validif(busy, _GEN_7) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_21 = mux(busy, _GEN_8, resultValid) @[src/main/scala/gcd/DecoupledGCD.scala 41:15 35:28]
    node _GEN_22 = mux(busy, _GEN_9, _GEN_15) @[src/main/scala/gcd/DecoupledGCD.scala 41:15]
    node _GEN_23 = mux(busy, _input_ready_T, _GEN_10) @[src/main/scala/gcd/DecoupledGCD.scala 37:15 41:15]
    node _GEN_24 = mux(busy, xInitial, _GEN_13) @[src/main/scala/gcd/DecoupledGCD.scala 41:15 30:24]
    node _GEN_25 = mux(busy, yInitial, _GEN_14) @[src/main/scala/gcd/DecoupledGCD.scala 41:15 31:24]
    input_ready <= _GEN_23
    output_valid <= resultValid @[src/main/scala/gcd/DecoupledGCD.scala 38:16]
    output_bits_value1 <= _GEN_19
    output_bits_value2 <= _GEN_20
    output_bits_gcd <= _GEN_18
    xInitial <= _GEN_24
    yInitial <= _GEN_25
    x <= _GEN_16
    y <= _GEN_17
    busy <= mux(reset, UInt<1>("h0"), _GEN_22) @[src/main/scala/gcd/DecoupledGCD.scala 34:{28,28}]
    resultValid <= mux(reset, UInt<1>("h0"), _GEN_21) @[src/main/scala/gcd/DecoupledGCD.scala 35:{28,28}]
