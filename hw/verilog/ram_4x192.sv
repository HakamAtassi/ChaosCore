// Generated by CIRCT firtool-1.62.0
// Standard header to adapt well known macros for prints and assertions.

// Users can define 'ASSERT_VERBOSE_COND' to add an extra gate to assert error printing.
`ifndef ASSERT_VERBOSE_COND_
  `ifdef ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ (`ASSERT_VERBOSE_COND)
  `else  // ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ 1
  `endif // ASSERT_VERBOSE_COND
`endif // not def ASSERT_VERBOSE_COND_

// Users can define 'STOP_COND' to add an extra gate to stop conditions.
`ifndef STOP_COND_
  `ifdef STOP_COND
    `define STOP_COND_ (`STOP_COND)
  `else  // STOP_COND
    `define STOP_COND_ 1
  `endif // STOP_COND
`endif // not def STOP_COND_

// VCS coverage exclude_file
module ram_4x192(
  input  [1:0]   R0_addr,
  input          R0_en,
                 R0_clk,
  output [191:0] R0_data,
  input  [1:0]   W0_addr,
  input          W0_en,
                 W0_clk,
  input  [191:0] W0_data,
                 W0_mask
);

  reg [191:0] Memory[0:3];
  always @(posedge W0_clk) begin
    if (W0_en & W0_mask[0])
      Memory[W0_addr][32'h0 +: 1] <= W0_data[0];
    if (W0_en & W0_mask[1])
      Memory[W0_addr][32'h1 +: 1] <= W0_data[1];
    if (W0_en & W0_mask[2])
      Memory[W0_addr][32'h2 +: 1] <= W0_data[2];
    if (W0_en & W0_mask[3])
      Memory[W0_addr][32'h3 +: 1] <= W0_data[3];
    if (W0_en & W0_mask[4])
      Memory[W0_addr][32'h4 +: 1] <= W0_data[4];
    if (W0_en & W0_mask[5])
      Memory[W0_addr][32'h5 +: 1] <= W0_data[5];
    if (W0_en & W0_mask[6])
      Memory[W0_addr][32'h6 +: 1] <= W0_data[6];
    if (W0_en & W0_mask[7])
      Memory[W0_addr][32'h7 +: 1] <= W0_data[7];
    if (W0_en & W0_mask[8])
      Memory[W0_addr][32'h8 +: 1] <= W0_data[8];
    if (W0_en & W0_mask[9])
      Memory[W0_addr][32'h9 +: 1] <= W0_data[9];
    if (W0_en & W0_mask[10])
      Memory[W0_addr][32'hA +: 1] <= W0_data[10];
    if (W0_en & W0_mask[11])
      Memory[W0_addr][32'hB +: 1] <= W0_data[11];
    if (W0_en & W0_mask[12])
      Memory[W0_addr][32'hC +: 1] <= W0_data[12];
    if (W0_en & W0_mask[13])
      Memory[W0_addr][32'hD +: 1] <= W0_data[13];
    if (W0_en & W0_mask[14])
      Memory[W0_addr][32'hE +: 1] <= W0_data[14];
    if (W0_en & W0_mask[15])
      Memory[W0_addr][32'hF +: 1] <= W0_data[15];
    if (W0_en & W0_mask[16])
      Memory[W0_addr][32'h10 +: 1] <= W0_data[16];
    if (W0_en & W0_mask[17])
      Memory[W0_addr][32'h11 +: 1] <= W0_data[17];
    if (W0_en & W0_mask[18])
      Memory[W0_addr][32'h12 +: 1] <= W0_data[18];
    if (W0_en & W0_mask[19])
      Memory[W0_addr][32'h13 +: 1] <= W0_data[19];
    if (W0_en & W0_mask[20])
      Memory[W0_addr][32'h14 +: 1] <= W0_data[20];
    if (W0_en & W0_mask[21])
      Memory[W0_addr][32'h15 +: 1] <= W0_data[21];
    if (W0_en & W0_mask[22])
      Memory[W0_addr][32'h16 +: 1] <= W0_data[22];
    if (W0_en & W0_mask[23])
      Memory[W0_addr][32'h17 +: 1] <= W0_data[23];
    if (W0_en & W0_mask[24])
      Memory[W0_addr][32'h18 +: 1] <= W0_data[24];
    if (W0_en & W0_mask[25])
      Memory[W0_addr][32'h19 +: 1] <= W0_data[25];
    if (W0_en & W0_mask[26])
      Memory[W0_addr][32'h1A +: 1] <= W0_data[26];
    if (W0_en & W0_mask[27])
      Memory[W0_addr][32'h1B +: 1] <= W0_data[27];
    if (W0_en & W0_mask[28])
      Memory[W0_addr][32'h1C +: 1] <= W0_data[28];
    if (W0_en & W0_mask[29])
      Memory[W0_addr][32'h1D +: 1] <= W0_data[29];
    if (W0_en & W0_mask[30])
      Memory[W0_addr][32'h1E +: 1] <= W0_data[30];
    if (W0_en & W0_mask[31])
      Memory[W0_addr][32'h1F +: 1] <= W0_data[31];
    if (W0_en & W0_mask[32])
      Memory[W0_addr][32'h20 +: 1] <= W0_data[32];
    if (W0_en & W0_mask[33])
      Memory[W0_addr][32'h21 +: 1] <= W0_data[33];
    if (W0_en & W0_mask[34])
      Memory[W0_addr][32'h22 +: 1] <= W0_data[34];
    if (W0_en & W0_mask[35])
      Memory[W0_addr][32'h23 +: 1] <= W0_data[35];
    if (W0_en & W0_mask[36])
      Memory[W0_addr][32'h24 +: 1] <= W0_data[36];
    if (W0_en & W0_mask[37])
      Memory[W0_addr][32'h25 +: 1] <= W0_data[37];
    if (W0_en & W0_mask[38])
      Memory[W0_addr][32'h26 +: 1] <= W0_data[38];
    if (W0_en & W0_mask[39])
      Memory[W0_addr][32'h27 +: 1] <= W0_data[39];
    if (W0_en & W0_mask[40])
      Memory[W0_addr][32'h28 +: 1] <= W0_data[40];
    if (W0_en & W0_mask[41])
      Memory[W0_addr][32'h29 +: 1] <= W0_data[41];
    if (W0_en & W0_mask[42])
      Memory[W0_addr][32'h2A +: 1] <= W0_data[42];
    if (W0_en & W0_mask[43])
      Memory[W0_addr][32'h2B +: 1] <= W0_data[43];
    if (W0_en & W0_mask[44])
      Memory[W0_addr][32'h2C +: 1] <= W0_data[44];
    if (W0_en & W0_mask[45])
      Memory[W0_addr][32'h2D +: 1] <= W0_data[45];
    if (W0_en & W0_mask[46])
      Memory[W0_addr][32'h2E +: 1] <= W0_data[46];
    if (W0_en & W0_mask[47])
      Memory[W0_addr][32'h2F +: 1] <= W0_data[47];
    if (W0_en & W0_mask[48])
      Memory[W0_addr][32'h30 +: 1] <= W0_data[48];
    if (W0_en & W0_mask[49])
      Memory[W0_addr][32'h31 +: 1] <= W0_data[49];
    if (W0_en & W0_mask[50])
      Memory[W0_addr][32'h32 +: 1] <= W0_data[50];
    if (W0_en & W0_mask[51])
      Memory[W0_addr][32'h33 +: 1] <= W0_data[51];
    if (W0_en & W0_mask[52])
      Memory[W0_addr][32'h34 +: 1] <= W0_data[52];
    if (W0_en & W0_mask[53])
      Memory[W0_addr][32'h35 +: 1] <= W0_data[53];
    if (W0_en & W0_mask[54])
      Memory[W0_addr][32'h36 +: 1] <= W0_data[54];
    if (W0_en & W0_mask[55])
      Memory[W0_addr][32'h37 +: 1] <= W0_data[55];
    if (W0_en & W0_mask[56])
      Memory[W0_addr][32'h38 +: 1] <= W0_data[56];
    if (W0_en & W0_mask[57])
      Memory[W0_addr][32'h39 +: 1] <= W0_data[57];
    if (W0_en & W0_mask[58])
      Memory[W0_addr][32'h3A +: 1] <= W0_data[58];
    if (W0_en & W0_mask[59])
      Memory[W0_addr][32'h3B +: 1] <= W0_data[59];
    if (W0_en & W0_mask[60])
      Memory[W0_addr][32'h3C +: 1] <= W0_data[60];
    if (W0_en & W0_mask[61])
      Memory[W0_addr][32'h3D +: 1] <= W0_data[61];
    if (W0_en & W0_mask[62])
      Memory[W0_addr][32'h3E +: 1] <= W0_data[62];
    if (W0_en & W0_mask[63])
      Memory[W0_addr][32'h3F +: 1] <= W0_data[63];
    if (W0_en & W0_mask[64])
      Memory[W0_addr][32'h40 +: 1] <= W0_data[64];
    if (W0_en & W0_mask[65])
      Memory[W0_addr][32'h41 +: 1] <= W0_data[65];
    if (W0_en & W0_mask[66])
      Memory[W0_addr][32'h42 +: 1] <= W0_data[66];
    if (W0_en & W0_mask[67])
      Memory[W0_addr][32'h43 +: 1] <= W0_data[67];
    if (W0_en & W0_mask[68])
      Memory[W0_addr][32'h44 +: 1] <= W0_data[68];
    if (W0_en & W0_mask[69])
      Memory[W0_addr][32'h45 +: 1] <= W0_data[69];
    if (W0_en & W0_mask[70])
      Memory[W0_addr][32'h46 +: 1] <= W0_data[70];
    if (W0_en & W0_mask[71])
      Memory[W0_addr][32'h47 +: 1] <= W0_data[71];
    if (W0_en & W0_mask[72])
      Memory[W0_addr][32'h48 +: 1] <= W0_data[72];
    if (W0_en & W0_mask[73])
      Memory[W0_addr][32'h49 +: 1] <= W0_data[73];
    if (W0_en & W0_mask[74])
      Memory[W0_addr][32'h4A +: 1] <= W0_data[74];
    if (W0_en & W0_mask[75])
      Memory[W0_addr][32'h4B +: 1] <= W0_data[75];
    if (W0_en & W0_mask[76])
      Memory[W0_addr][32'h4C +: 1] <= W0_data[76];
    if (W0_en & W0_mask[77])
      Memory[W0_addr][32'h4D +: 1] <= W0_data[77];
    if (W0_en & W0_mask[78])
      Memory[W0_addr][32'h4E +: 1] <= W0_data[78];
    if (W0_en & W0_mask[79])
      Memory[W0_addr][32'h4F +: 1] <= W0_data[79];
    if (W0_en & W0_mask[80])
      Memory[W0_addr][32'h50 +: 1] <= W0_data[80];
    if (W0_en & W0_mask[81])
      Memory[W0_addr][32'h51 +: 1] <= W0_data[81];
    if (W0_en & W0_mask[82])
      Memory[W0_addr][32'h52 +: 1] <= W0_data[82];
    if (W0_en & W0_mask[83])
      Memory[W0_addr][32'h53 +: 1] <= W0_data[83];
    if (W0_en & W0_mask[84])
      Memory[W0_addr][32'h54 +: 1] <= W0_data[84];
    if (W0_en & W0_mask[85])
      Memory[W0_addr][32'h55 +: 1] <= W0_data[85];
    if (W0_en & W0_mask[86])
      Memory[W0_addr][32'h56 +: 1] <= W0_data[86];
    if (W0_en & W0_mask[87])
      Memory[W0_addr][32'h57 +: 1] <= W0_data[87];
    if (W0_en & W0_mask[88])
      Memory[W0_addr][32'h58 +: 1] <= W0_data[88];
    if (W0_en & W0_mask[89])
      Memory[W0_addr][32'h59 +: 1] <= W0_data[89];
    if (W0_en & W0_mask[90])
      Memory[W0_addr][32'h5A +: 1] <= W0_data[90];
    if (W0_en & W0_mask[91])
      Memory[W0_addr][32'h5B +: 1] <= W0_data[91];
    if (W0_en & W0_mask[92])
      Memory[W0_addr][32'h5C +: 1] <= W0_data[92];
    if (W0_en & W0_mask[93])
      Memory[W0_addr][32'h5D +: 1] <= W0_data[93];
    if (W0_en & W0_mask[94])
      Memory[W0_addr][32'h5E +: 1] <= W0_data[94];
    if (W0_en & W0_mask[95])
      Memory[W0_addr][32'h5F +: 1] <= W0_data[95];
    if (W0_en & W0_mask[96])
      Memory[W0_addr][32'h60 +: 1] <= W0_data[96];
    if (W0_en & W0_mask[97])
      Memory[W0_addr][32'h61 +: 1] <= W0_data[97];
    if (W0_en & W0_mask[98])
      Memory[W0_addr][32'h62 +: 1] <= W0_data[98];
    if (W0_en & W0_mask[99])
      Memory[W0_addr][32'h63 +: 1] <= W0_data[99];
    if (W0_en & W0_mask[100])
      Memory[W0_addr][32'h64 +: 1] <= W0_data[100];
    if (W0_en & W0_mask[101])
      Memory[W0_addr][32'h65 +: 1] <= W0_data[101];
    if (W0_en & W0_mask[102])
      Memory[W0_addr][32'h66 +: 1] <= W0_data[102];
    if (W0_en & W0_mask[103])
      Memory[W0_addr][32'h67 +: 1] <= W0_data[103];
    if (W0_en & W0_mask[104])
      Memory[W0_addr][32'h68 +: 1] <= W0_data[104];
    if (W0_en & W0_mask[105])
      Memory[W0_addr][32'h69 +: 1] <= W0_data[105];
    if (W0_en & W0_mask[106])
      Memory[W0_addr][32'h6A +: 1] <= W0_data[106];
    if (W0_en & W0_mask[107])
      Memory[W0_addr][32'h6B +: 1] <= W0_data[107];
    if (W0_en & W0_mask[108])
      Memory[W0_addr][32'h6C +: 1] <= W0_data[108];
    if (W0_en & W0_mask[109])
      Memory[W0_addr][32'h6D +: 1] <= W0_data[109];
    if (W0_en & W0_mask[110])
      Memory[W0_addr][32'h6E +: 1] <= W0_data[110];
    if (W0_en & W0_mask[111])
      Memory[W0_addr][32'h6F +: 1] <= W0_data[111];
    if (W0_en & W0_mask[112])
      Memory[W0_addr][32'h70 +: 1] <= W0_data[112];
    if (W0_en & W0_mask[113])
      Memory[W0_addr][32'h71 +: 1] <= W0_data[113];
    if (W0_en & W0_mask[114])
      Memory[W0_addr][32'h72 +: 1] <= W0_data[114];
    if (W0_en & W0_mask[115])
      Memory[W0_addr][32'h73 +: 1] <= W0_data[115];
    if (W0_en & W0_mask[116])
      Memory[W0_addr][32'h74 +: 1] <= W0_data[116];
    if (W0_en & W0_mask[117])
      Memory[W0_addr][32'h75 +: 1] <= W0_data[117];
    if (W0_en & W0_mask[118])
      Memory[W0_addr][32'h76 +: 1] <= W0_data[118];
    if (W0_en & W0_mask[119])
      Memory[W0_addr][32'h77 +: 1] <= W0_data[119];
    if (W0_en & W0_mask[120])
      Memory[W0_addr][32'h78 +: 1] <= W0_data[120];
    if (W0_en & W0_mask[121])
      Memory[W0_addr][32'h79 +: 1] <= W0_data[121];
    if (W0_en & W0_mask[122])
      Memory[W0_addr][32'h7A +: 1] <= W0_data[122];
    if (W0_en & W0_mask[123])
      Memory[W0_addr][32'h7B +: 1] <= W0_data[123];
    if (W0_en & W0_mask[124])
      Memory[W0_addr][32'h7C +: 1] <= W0_data[124];
    if (W0_en & W0_mask[125])
      Memory[W0_addr][32'h7D +: 1] <= W0_data[125];
    if (W0_en & W0_mask[126])
      Memory[W0_addr][32'h7E +: 1] <= W0_data[126];
    if (W0_en & W0_mask[127])
      Memory[W0_addr][32'h7F +: 1] <= W0_data[127];
    if (W0_en & W0_mask[128])
      Memory[W0_addr][32'h80 +: 1] <= W0_data[128];
    if (W0_en & W0_mask[129])
      Memory[W0_addr][32'h81 +: 1] <= W0_data[129];
    if (W0_en & W0_mask[130])
      Memory[W0_addr][32'h82 +: 1] <= W0_data[130];
    if (W0_en & W0_mask[131])
      Memory[W0_addr][32'h83 +: 1] <= W0_data[131];
    if (W0_en & W0_mask[132])
      Memory[W0_addr][32'h84 +: 1] <= W0_data[132];
    if (W0_en & W0_mask[133])
      Memory[W0_addr][32'h85 +: 1] <= W0_data[133];
    if (W0_en & W0_mask[134])
      Memory[W0_addr][32'h86 +: 1] <= W0_data[134];
    if (W0_en & W0_mask[135])
      Memory[W0_addr][32'h87 +: 1] <= W0_data[135];
    if (W0_en & W0_mask[136])
      Memory[W0_addr][32'h88 +: 1] <= W0_data[136];
    if (W0_en & W0_mask[137])
      Memory[W0_addr][32'h89 +: 1] <= W0_data[137];
    if (W0_en & W0_mask[138])
      Memory[W0_addr][32'h8A +: 1] <= W0_data[138];
    if (W0_en & W0_mask[139])
      Memory[W0_addr][32'h8B +: 1] <= W0_data[139];
    if (W0_en & W0_mask[140])
      Memory[W0_addr][32'h8C +: 1] <= W0_data[140];
    if (W0_en & W0_mask[141])
      Memory[W0_addr][32'h8D +: 1] <= W0_data[141];
    if (W0_en & W0_mask[142])
      Memory[W0_addr][32'h8E +: 1] <= W0_data[142];
    if (W0_en & W0_mask[143])
      Memory[W0_addr][32'h8F +: 1] <= W0_data[143];
    if (W0_en & W0_mask[144])
      Memory[W0_addr][32'h90 +: 1] <= W0_data[144];
    if (W0_en & W0_mask[145])
      Memory[W0_addr][32'h91 +: 1] <= W0_data[145];
    if (W0_en & W0_mask[146])
      Memory[W0_addr][32'h92 +: 1] <= W0_data[146];
    if (W0_en & W0_mask[147])
      Memory[W0_addr][32'h93 +: 1] <= W0_data[147];
    if (W0_en & W0_mask[148])
      Memory[W0_addr][32'h94 +: 1] <= W0_data[148];
    if (W0_en & W0_mask[149])
      Memory[W0_addr][32'h95 +: 1] <= W0_data[149];
    if (W0_en & W0_mask[150])
      Memory[W0_addr][32'h96 +: 1] <= W0_data[150];
    if (W0_en & W0_mask[151])
      Memory[W0_addr][32'h97 +: 1] <= W0_data[151];
    if (W0_en & W0_mask[152])
      Memory[W0_addr][32'h98 +: 1] <= W0_data[152];
    if (W0_en & W0_mask[153])
      Memory[W0_addr][32'h99 +: 1] <= W0_data[153];
    if (W0_en & W0_mask[154])
      Memory[W0_addr][32'h9A +: 1] <= W0_data[154];
    if (W0_en & W0_mask[155])
      Memory[W0_addr][32'h9B +: 1] <= W0_data[155];
    if (W0_en & W0_mask[156])
      Memory[W0_addr][32'h9C +: 1] <= W0_data[156];
    if (W0_en & W0_mask[157])
      Memory[W0_addr][32'h9D +: 1] <= W0_data[157];
    if (W0_en & W0_mask[158])
      Memory[W0_addr][32'h9E +: 1] <= W0_data[158];
    if (W0_en & W0_mask[159])
      Memory[W0_addr][32'h9F +: 1] <= W0_data[159];
    if (W0_en & W0_mask[160])
      Memory[W0_addr][32'hA0 +: 1] <= W0_data[160];
    if (W0_en & W0_mask[161])
      Memory[W0_addr][32'hA1 +: 1] <= W0_data[161];
    if (W0_en & W0_mask[162])
      Memory[W0_addr][32'hA2 +: 1] <= W0_data[162];
    if (W0_en & W0_mask[163])
      Memory[W0_addr][32'hA3 +: 1] <= W0_data[163];
    if (W0_en & W0_mask[164])
      Memory[W0_addr][32'hA4 +: 1] <= W0_data[164];
    if (W0_en & W0_mask[165])
      Memory[W0_addr][32'hA5 +: 1] <= W0_data[165];
    if (W0_en & W0_mask[166])
      Memory[W0_addr][32'hA6 +: 1] <= W0_data[166];
    if (W0_en & W0_mask[167])
      Memory[W0_addr][32'hA7 +: 1] <= W0_data[167];
    if (W0_en & W0_mask[168])
      Memory[W0_addr][32'hA8 +: 1] <= W0_data[168];
    if (W0_en & W0_mask[169])
      Memory[W0_addr][32'hA9 +: 1] <= W0_data[169];
    if (W0_en & W0_mask[170])
      Memory[W0_addr][32'hAA +: 1] <= W0_data[170];
    if (W0_en & W0_mask[171])
      Memory[W0_addr][32'hAB +: 1] <= W0_data[171];
    if (W0_en & W0_mask[172])
      Memory[W0_addr][32'hAC +: 1] <= W0_data[172];
    if (W0_en & W0_mask[173])
      Memory[W0_addr][32'hAD +: 1] <= W0_data[173];
    if (W0_en & W0_mask[174])
      Memory[W0_addr][32'hAE +: 1] <= W0_data[174];
    if (W0_en & W0_mask[175])
      Memory[W0_addr][32'hAF +: 1] <= W0_data[175];
    if (W0_en & W0_mask[176])
      Memory[W0_addr][32'hB0 +: 1] <= W0_data[176];
    if (W0_en & W0_mask[177])
      Memory[W0_addr][32'hB1 +: 1] <= W0_data[177];
    if (W0_en & W0_mask[178])
      Memory[W0_addr][32'hB2 +: 1] <= W0_data[178];
    if (W0_en & W0_mask[179])
      Memory[W0_addr][32'hB3 +: 1] <= W0_data[179];
    if (W0_en & W0_mask[180])
      Memory[W0_addr][32'hB4 +: 1] <= W0_data[180];
    if (W0_en & W0_mask[181])
      Memory[W0_addr][32'hB5 +: 1] <= W0_data[181];
    if (W0_en & W0_mask[182])
      Memory[W0_addr][32'hB6 +: 1] <= W0_data[182];
    if (W0_en & W0_mask[183])
      Memory[W0_addr][32'hB7 +: 1] <= W0_data[183];
    if (W0_en & W0_mask[184])
      Memory[W0_addr][32'hB8 +: 1] <= W0_data[184];
    if (W0_en & W0_mask[185])
      Memory[W0_addr][32'hB9 +: 1] <= W0_data[185];
    if (W0_en & W0_mask[186])
      Memory[W0_addr][32'hBA +: 1] <= W0_data[186];
    if (W0_en & W0_mask[187])
      Memory[W0_addr][32'hBB +: 1] <= W0_data[187];
    if (W0_en & W0_mask[188])
      Memory[W0_addr][32'hBC +: 1] <= W0_data[188];
    if (W0_en & W0_mask[189])
      Memory[W0_addr][32'hBD +: 1] <= W0_data[189];
    if (W0_en & W0_mask[190])
      Memory[W0_addr][32'hBE +: 1] <= W0_data[190];
    if (W0_en & W0_mask[191])
      Memory[W0_addr][32'hBF +: 1] <= W0_data[191];
  end // always @(posedge)
  assign R0_data = R0_en ? Memory[R0_addr] : 192'bx;
endmodule
