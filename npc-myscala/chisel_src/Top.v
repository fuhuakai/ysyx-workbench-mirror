module SingleCycleCore(
  input         clock,
  input         reset,
  output [31:0] io_imem_addr,
  input  [31:0] io_imem_inst,
  output [31:0] io_dmem_addr,
  input  [31:0] io_dmem_rdata,
  output        io_dmem_wen,
  output [31:0] io_dmem_wdata,
  output        io_exit
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  simCtrl_ebreak; // @[SingleCycleCore.scala 16:23]
  reg [31:0] regfile [0:15]; // @[SingleCycleCore.scala 22:20]
  wire [31:0] regfile_rs1_data_MPORT_data; // @[SingleCycleCore.scala 22:20]
  wire [3:0] regfile_rs1_data_MPORT_addr; // @[SingleCycleCore.scala 22:20]
  wire [31:0] regfile_rs2_data_MPORT_data; // @[SingleCycleCore.scala 22:20]
  wire [3:0] regfile_rs2_data_MPORT_addr; // @[SingleCycleCore.scala 22:20]
  wire [31:0] regfile_MPORT_data; // @[SingleCycleCore.scala 22:20]
  wire [3:0] regfile_MPORT_addr; // @[SingleCycleCore.scala 22:20]
  wire  regfile_MPORT_mask; // @[SingleCycleCore.scala 22:20]
  wire  regfile_MPORT_en; // @[SingleCycleCore.scala 22:20]
  reg [31:0] pc; // @[SingleCycleCore.scala 19:19]
  wire [3:0] rs1_addr = io_imem_inst[19:16]; // @[SingleCycleCore.scala 29:22]
  wire [4:0] rs2_addr = io_imem_inst[24:20]; // @[SingleCycleCore.scala 30:22]
  wire [3:0] wb_addr = io_imem_inst[11:8]; // @[SingleCycleCore.scala 31:21]
  wire [31:0] rs1_data = rs1_addr == 4'h0 ? 32'h0 : regfile_rs1_data_MPORT_data; // @[SingleCycleCore.scala 34:21]
  wire [31:0] rs2_data = rs2_addr == 5'h0 ? 32'h0 : regfile_rs2_data_MPORT_data; // @[SingleCycleCore.scala 35:21]
  wire [11:0] imm_i = io_imem_inst[31:20]; // @[SingleCycleCore.scala 38:19]
  wire [19:0] imm_i_sext_hi = imm_i[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_i_sext = {imm_i_sext_hi,imm_i}; // @[Cat.scala 30:58]
  wire [6:0] imm_s_hi = io_imem_inst[31:25]; // @[SingleCycleCore.scala 41:23]
  wire [4:0] imm_s_lo = io_imem_inst[11:7]; // @[SingleCycleCore.scala 41:37]
  wire [11:0] imm_s = {imm_s_hi,imm_s_lo}; // @[Cat.scala 30:58]
  wire [19:0] imm_s_sext_hi = imm_s[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_s_sext = {imm_s_sext_hi,imm_s_hi,imm_s_lo}; // @[Cat.scala 30:58]
  wire  imm_b_hi_hi = io_imem_inst[31]; // @[SingleCycleCore.scala 44:23]
  wire  imm_b_hi_lo = io_imem_inst[7]; // @[SingleCycleCore.scala 44:33]
  wire [5:0] imm_b_lo_hi = io_imem_inst[30:25]; // @[SingleCycleCore.scala 44:42]
  wire [11:0] imm_b = {imm_b_hi_hi,imm_b_hi_lo,imm_b_lo_hi,wb_addr}; // @[Cat.scala 30:58]
  wire [18:0] imm_b_sext_hi_hi = imm_b[11] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_b_sext = {imm_b_sext_hi_hi,imm_b_hi_hi,imm_b_hi_lo,imm_b_lo_hi,wb_addr,1'h0}; // @[Cat.scala 30:58]
  wire [7:0] imm_j_hi_lo = io_imem_inst[19:12]; // @[SingleCycleCore.scala 47:33]
  wire  imm_j_lo_hi = io_imem_inst[20]; // @[SingleCycleCore.scala 47:47]
  wire [9:0] imm_j_lo_lo = io_imem_inst[30:21]; // @[SingleCycleCore.scala 47:57]
  wire [19:0] imm_j = {imm_b_hi_hi,imm_j_hi_lo,imm_j_lo_hi,imm_j_lo_lo}; // @[Cat.scala 30:58]
  wire [10:0] imm_j_sext_hi_hi = imm_j[19] ? 11'h7ff : 11'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_j_sext = {imm_j_sext_hi_hi,imm_b_hi_hi,imm_j_hi_lo,imm_j_lo_hi,imm_j_lo_lo,1'h0}; // @[Cat.scala 30:58]
  wire [19:0] imm_u = io_imem_inst[31:12]; // @[SingleCycleCore.scala 50:19]
  wire [31:0] imm_u_shifted = {imm_u,12'h0}; // @[Cat.scala 30:58]
  wire [31:0] _T = io_imem_inst & 32'h707f; // @[Lookup.scala 31:38]
  wire  _T_1 = 32'h2003 == _T; // @[Lookup.scala 31:38]
  wire  _T_3 = 32'h2023 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_4 = io_imem_inst & 32'hfe00707f; // @[Lookup.scala 31:38]
  wire  _T_5 = 32'h33 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_7 = 32'h13 == _T; // @[Lookup.scala 31:38]
  wire  _T_9 = 32'h40000033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_11 = 32'h7033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_13 = 32'h6033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_15 = 32'h4033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_17 = 32'h7013 == _T; // @[Lookup.scala 31:38]
  wire  _T_19 = 32'h6013 == _T; // @[Lookup.scala 31:38]
  wire  _T_21 = 32'h4013 == _T; // @[Lookup.scala 31:38]
  wire  _T_23 = 32'h1033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_25 = 32'h5033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_27 = 32'h40005033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_29 = 32'h1013 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_31 = 32'h5013 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_33 = 32'h40005013 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_35 = 32'h2033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_37 = 32'h3033 == _T_4; // @[Lookup.scala 31:38]
  wire  _T_39 = 32'h2013 == _T; // @[Lookup.scala 31:38]
  wire  _T_41 = 32'h3013 == _T; // @[Lookup.scala 31:38]
  wire  _T_43 = 32'h63 == _T; // @[Lookup.scala 31:38]
  wire  _T_45 = 32'h1063 == _T; // @[Lookup.scala 31:38]
  wire  _T_47 = 32'h4063 == _T; // @[Lookup.scala 31:38]
  wire  _T_49 = 32'h5063 == _T; // @[Lookup.scala 31:38]
  wire  _T_51 = 32'h6063 == _T; // @[Lookup.scala 31:38]
  wire  _T_53 = 32'h7063 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_54 = io_imem_inst & 32'h7f; // @[Lookup.scala 31:38]
  wire  _T_55 = 32'h6f == _T_54; // @[Lookup.scala 31:38]
  wire  _T_57 = 32'h67 == _T; // @[Lookup.scala 31:38]
  wire  _T_59 = 32'h37 == _T_54; // @[Lookup.scala 31:38]
  wire  _T_61 = 32'h17 == _T_54; // @[Lookup.scala 31:38]
  wire [3:0] _T_67 = _T_57 ? 4'ha : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_68 = _T_55 ? 4'h0 : _T_67; // @[Lookup.scala 33:37]
  wire [3:0] _T_69 = _T_53 ? 4'h9 : _T_68; // @[Lookup.scala 33:37]
  wire [3:0] _T_70 = _T_51 ? 4'h9 : _T_69; // @[Lookup.scala 33:37]
  wire [3:0] _T_71 = _T_49 ? 4'h8 : _T_70; // @[Lookup.scala 33:37]
  wire [3:0] _T_72 = _T_47 ? 4'h8 : _T_71; // @[Lookup.scala 33:37]
  wire [3:0] _T_73 = _T_45 ? 4'h1 : _T_72; // @[Lookup.scala 33:37]
  wire [3:0] _T_74 = _T_43 ? 4'h1 : _T_73; // @[Lookup.scala 33:37]
  wire [3:0] _T_75 = _T_41 ? 4'h9 : _T_74; // @[Lookup.scala 33:37]
  wire [3:0] _T_76 = _T_39 ? 4'h8 : _T_75; // @[Lookup.scala 33:37]
  wire [3:0] _T_77 = _T_37 ? 4'h9 : _T_76; // @[Lookup.scala 33:37]
  wire [3:0] _T_78 = _T_35 ? 4'h8 : _T_77; // @[Lookup.scala 33:37]
  wire [3:0] _T_79 = _T_33 ? 4'h7 : _T_78; // @[Lookup.scala 33:37]
  wire [3:0] _T_80 = _T_31 ? 4'h6 : _T_79; // @[Lookup.scala 33:37]
  wire [3:0] _T_81 = _T_29 ? 4'h5 : _T_80; // @[Lookup.scala 33:37]
  wire [3:0] _T_82 = _T_27 ? 4'h7 : _T_81; // @[Lookup.scala 33:37]
  wire [3:0] _T_83 = _T_25 ? 4'h6 : _T_82; // @[Lookup.scala 33:37]
  wire [3:0] _T_84 = _T_23 ? 4'h5 : _T_83; // @[Lookup.scala 33:37]
  wire [3:0] _T_85 = _T_21 ? 4'h4 : _T_84; // @[Lookup.scala 33:37]
  wire [3:0] _T_86 = _T_19 ? 4'h3 : _T_85; // @[Lookup.scala 33:37]
  wire [3:0] _T_87 = _T_17 ? 4'h2 : _T_86; // @[Lookup.scala 33:37]
  wire [3:0] _T_88 = _T_15 ? 4'h4 : _T_87; // @[Lookup.scala 33:37]
  wire [3:0] _T_89 = _T_13 ? 4'h3 : _T_88; // @[Lookup.scala 33:37]
  wire [3:0] _T_90 = _T_11 ? 4'h2 : _T_89; // @[Lookup.scala 33:37]
  wire [3:0] _T_91 = _T_9 ? 4'h1 : _T_90; // @[Lookup.scala 33:37]
  wire [3:0] _T_92 = _T_7 ? 4'h0 : _T_91; // @[Lookup.scala 33:37]
  wire [3:0] _T_93 = _T_5 ? 4'h0 : _T_92; // @[Lookup.scala 33:37]
  wire [3:0] _T_94 = _T_3 ? 4'h0 : _T_93; // @[Lookup.scala 33:37]
  wire [3:0] exe_fun = _T_1 ? 4'h0 : _T_94; // @[Lookup.scala 33:37]
  wire [1:0] _T_96 = _T_61 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_97 = _T_59 ? 2'h2 : _T_96; // @[Lookup.scala 33:37]
  wire [1:0] _T_98 = _T_57 ? 2'h0 : _T_97; // @[Lookup.scala 33:37]
  wire [1:0] _T_99 = _T_55 ? 2'h1 : _T_98; // @[Lookup.scala 33:37]
  wire [1:0] _T_100 = _T_53 ? 2'h0 : _T_99; // @[Lookup.scala 33:37]
  wire [1:0] _T_101 = _T_51 ? 2'h0 : _T_100; // @[Lookup.scala 33:37]
  wire [1:0] _T_102 = _T_49 ? 2'h0 : _T_101; // @[Lookup.scala 33:37]
  wire [1:0] _T_103 = _T_47 ? 2'h0 : _T_102; // @[Lookup.scala 33:37]
  wire [1:0] _T_104 = _T_45 ? 2'h0 : _T_103; // @[Lookup.scala 33:37]
  wire [1:0] _T_105 = _T_43 ? 2'h0 : _T_104; // @[Lookup.scala 33:37]
  wire [1:0] _T_106 = _T_41 ? 2'h0 : _T_105; // @[Lookup.scala 33:37]
  wire [1:0] _T_107 = _T_39 ? 2'h0 : _T_106; // @[Lookup.scala 33:37]
  wire [1:0] _T_108 = _T_37 ? 2'h0 : _T_107; // @[Lookup.scala 33:37]
  wire [1:0] _T_109 = _T_35 ? 2'h0 : _T_108; // @[Lookup.scala 33:37]
  wire [1:0] _T_110 = _T_33 ? 2'h0 : _T_109; // @[Lookup.scala 33:37]
  wire [1:0] _T_111 = _T_31 ? 2'h0 : _T_110; // @[Lookup.scala 33:37]
  wire [1:0] _T_112 = _T_29 ? 2'h0 : _T_111; // @[Lookup.scala 33:37]
  wire [1:0] _T_113 = _T_27 ? 2'h0 : _T_112; // @[Lookup.scala 33:37]
  wire [1:0] _T_114 = _T_25 ? 2'h0 : _T_113; // @[Lookup.scala 33:37]
  wire [1:0] _T_115 = _T_23 ? 2'h0 : _T_114; // @[Lookup.scala 33:37]
  wire [1:0] _T_116 = _T_21 ? 2'h0 : _T_115; // @[Lookup.scala 33:37]
  wire [1:0] _T_117 = _T_19 ? 2'h0 : _T_116; // @[Lookup.scala 33:37]
  wire [1:0] _T_118 = _T_17 ? 2'h0 : _T_117; // @[Lookup.scala 33:37]
  wire [1:0] _T_119 = _T_15 ? 2'h0 : _T_118; // @[Lookup.scala 33:37]
  wire [1:0] _T_120 = _T_13 ? 2'h0 : _T_119; // @[Lookup.scala 33:37]
  wire [1:0] _T_121 = _T_11 ? 2'h0 : _T_120; // @[Lookup.scala 33:37]
  wire [1:0] _T_122 = _T_9 ? 2'h0 : _T_121; // @[Lookup.scala 33:37]
  wire [1:0] _T_123 = _T_7 ? 2'h0 : _T_122; // @[Lookup.scala 33:37]
  wire [1:0] _T_124 = _T_5 ? 2'h0 : _T_123; // @[Lookup.scala 33:37]
  wire [1:0] _T_125 = _T_3 ? 2'h0 : _T_124; // @[Lookup.scala 33:37]
  wire [1:0] op1_sel = _T_1 ? 2'h0 : _T_125; // @[Lookup.scala 33:37]
  wire [2:0] _T_127 = _T_61 ? 3'h5 : 3'h1; // @[Lookup.scala 33:37]
  wire [2:0] _T_128 = _T_59 ? 3'h5 : _T_127; // @[Lookup.scala 33:37]
  wire [2:0] _T_129 = _T_57 ? 3'h2 : _T_128; // @[Lookup.scala 33:37]
  wire [2:0] _T_130 = _T_55 ? 3'h4 : _T_129; // @[Lookup.scala 33:37]
  wire [2:0] _T_131 = _T_53 ? 3'h1 : _T_130; // @[Lookup.scala 33:37]
  wire [2:0] _T_132 = _T_51 ? 3'h1 : _T_131; // @[Lookup.scala 33:37]
  wire [2:0] _T_133 = _T_49 ? 3'h1 : _T_132; // @[Lookup.scala 33:37]
  wire [2:0] _T_134 = _T_47 ? 3'h1 : _T_133; // @[Lookup.scala 33:37]
  wire [2:0] _T_135 = _T_45 ? 3'h1 : _T_134; // @[Lookup.scala 33:37]
  wire [2:0] _T_136 = _T_43 ? 3'h1 : _T_135; // @[Lookup.scala 33:37]
  wire [2:0] _T_137 = _T_41 ? 3'h2 : _T_136; // @[Lookup.scala 33:37]
  wire [2:0] _T_138 = _T_39 ? 3'h2 : _T_137; // @[Lookup.scala 33:37]
  wire [2:0] _T_139 = _T_37 ? 3'h1 : _T_138; // @[Lookup.scala 33:37]
  wire [2:0] _T_140 = _T_35 ? 3'h1 : _T_139; // @[Lookup.scala 33:37]
  wire [2:0] _T_141 = _T_33 ? 3'h2 : _T_140; // @[Lookup.scala 33:37]
  wire [2:0] _T_142 = _T_31 ? 3'h2 : _T_141; // @[Lookup.scala 33:37]
  wire [2:0] _T_143 = _T_29 ? 3'h2 : _T_142; // @[Lookup.scala 33:37]
  wire [2:0] _T_144 = _T_27 ? 3'h1 : _T_143; // @[Lookup.scala 33:37]
  wire [2:0] _T_145 = _T_25 ? 3'h1 : _T_144; // @[Lookup.scala 33:37]
  wire [2:0] _T_146 = _T_23 ? 3'h1 : _T_145; // @[Lookup.scala 33:37]
  wire [2:0] _T_147 = _T_21 ? 3'h2 : _T_146; // @[Lookup.scala 33:37]
  wire [2:0] _T_148 = _T_19 ? 3'h2 : _T_147; // @[Lookup.scala 33:37]
  wire [2:0] _T_149 = _T_17 ? 3'h2 : _T_148; // @[Lookup.scala 33:37]
  wire [2:0] _T_150 = _T_15 ? 3'h1 : _T_149; // @[Lookup.scala 33:37]
  wire [2:0] _T_151 = _T_13 ? 3'h1 : _T_150; // @[Lookup.scala 33:37]
  wire [2:0] _T_152 = _T_11 ? 3'h1 : _T_151; // @[Lookup.scala 33:37]
  wire [2:0] _T_153 = _T_9 ? 3'h1 : _T_152; // @[Lookup.scala 33:37]
  wire [2:0] _T_154 = _T_7 ? 3'h2 : _T_153; // @[Lookup.scala 33:37]
  wire [2:0] _T_155 = _T_5 ? 3'h1 : _T_154; // @[Lookup.scala 33:37]
  wire [2:0] _T_156 = _T_3 ? 3'h3 : _T_155; // @[Lookup.scala 33:37]
  wire [2:0] op2_sel = _T_1 ? 3'h2 : _T_156; // @[Lookup.scala 33:37]
  wire  _T_193 = _T_53 ? 1'h0 : _T_55 | (_T_57 | (_T_59 | _T_61)); // @[Lookup.scala 33:37]
  wire  _T_194 = _T_51 ? 1'h0 : _T_193; // @[Lookup.scala 33:37]
  wire  _T_195 = _T_49 ? 1'h0 : _T_194; // @[Lookup.scala 33:37]
  wire  _T_196 = _T_47 ? 1'h0 : _T_195; // @[Lookup.scala 33:37]
  wire  _T_197 = _T_45 ? 1'h0 : _T_196; // @[Lookup.scala 33:37]
  wire  _T_198 = _T_43 ? 1'h0 : _T_197; // @[Lookup.scala 33:37]
  wire  _T_218 = _T_3 ? 1'h0 : _T_5 | (_T_7 | (_T_9 | (_T_11 | (_T_13 | (_T_15 | (_T_17 | (_T_19 | (_T_21 | (_T_23 | (
    _T_25 | (_T_27 | (_T_29 | (_T_31 | (_T_33 | (_T_35 | (_T_37 | (_T_39 | (_T_41 | _T_198)))))))))))))))))); // @[Lookup.scala 33:37]
  wire  rf_wen = _T_1 | _T_218; // @[Lookup.scala 33:37]
  wire [1:0] _T_222 = _T_57 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_223 = _T_55 ? 2'h2 : _T_222; // @[Lookup.scala 33:37]
  wire [1:0] _T_224 = _T_53 ? 2'h0 : _T_223; // @[Lookup.scala 33:37]
  wire [1:0] _T_225 = _T_51 ? 2'h0 : _T_224; // @[Lookup.scala 33:37]
  wire [1:0] _T_226 = _T_49 ? 2'h0 : _T_225; // @[Lookup.scala 33:37]
  wire [1:0] _T_227 = _T_47 ? 2'h0 : _T_226; // @[Lookup.scala 33:37]
  wire [1:0] _T_228 = _T_45 ? 2'h0 : _T_227; // @[Lookup.scala 33:37]
  wire [1:0] _T_229 = _T_43 ? 2'h0 : _T_228; // @[Lookup.scala 33:37]
  wire [1:0] _T_230 = _T_41 ? 2'h0 : _T_229; // @[Lookup.scala 33:37]
  wire [1:0] _T_231 = _T_39 ? 2'h0 : _T_230; // @[Lookup.scala 33:37]
  wire [1:0] _T_232 = _T_37 ? 2'h0 : _T_231; // @[Lookup.scala 33:37]
  wire [1:0] _T_233 = _T_35 ? 2'h0 : _T_232; // @[Lookup.scala 33:37]
  wire [1:0] _T_234 = _T_33 ? 2'h0 : _T_233; // @[Lookup.scala 33:37]
  wire [1:0] _T_235 = _T_31 ? 2'h0 : _T_234; // @[Lookup.scala 33:37]
  wire [1:0] _T_236 = _T_29 ? 2'h0 : _T_235; // @[Lookup.scala 33:37]
  wire [1:0] _T_237 = _T_27 ? 2'h0 : _T_236; // @[Lookup.scala 33:37]
  wire [1:0] _T_238 = _T_25 ? 2'h0 : _T_237; // @[Lookup.scala 33:37]
  wire [1:0] _T_239 = _T_23 ? 2'h0 : _T_238; // @[Lookup.scala 33:37]
  wire [1:0] _T_240 = _T_21 ? 2'h0 : _T_239; // @[Lookup.scala 33:37]
  wire [1:0] _T_241 = _T_19 ? 2'h0 : _T_240; // @[Lookup.scala 33:37]
  wire [1:0] _T_242 = _T_17 ? 2'h0 : _T_241; // @[Lookup.scala 33:37]
  wire [1:0] _T_243 = _T_15 ? 2'h0 : _T_242; // @[Lookup.scala 33:37]
  wire [1:0] _T_244 = _T_13 ? 2'h0 : _T_243; // @[Lookup.scala 33:37]
  wire [1:0] _T_245 = _T_11 ? 2'h0 : _T_244; // @[Lookup.scala 33:37]
  wire [1:0] _T_246 = _T_9 ? 2'h0 : _T_245; // @[Lookup.scala 33:37]
  wire [1:0] _T_247 = _T_7 ? 2'h0 : _T_246; // @[Lookup.scala 33:37]
  wire [1:0] _T_248 = _T_5 ? 2'h0 : _T_247; // @[Lookup.scala 33:37]
  wire [1:0] _T_249 = _T_3 ? 2'h0 : _T_248; // @[Lookup.scala 33:37]
  wire [1:0] wb_sel = _T_1 ? 2'h1 : _T_249; // @[Lookup.scala 33:37]
  wire  _op1_data_T = op1_sel == 2'h0; // @[SingleCycleCore.scala 112:14]
  wire  _op1_data_T_1 = op1_sel == 2'h1; // @[SingleCycleCore.scala 113:14]
  wire [31:0] _op1_data_T_4 = _op1_data_T_1 ? pc : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] op1_data = _op1_data_T ? rs1_data : _op1_data_T_4; // @[Mux.scala 98:16]
  wire  _op2_data_T = op2_sel == 3'h1; // @[SingleCycleCore.scala 118:14]
  wire  _op2_data_T_1 = op2_sel == 3'h2; // @[SingleCycleCore.scala 119:14]
  wire  _op2_data_T_2 = op2_sel == 3'h3; // @[SingleCycleCore.scala 120:14]
  wire  _op2_data_T_3 = op2_sel == 3'h4; // @[SingleCycleCore.scala 121:14]
  wire  _op2_data_T_4 = op2_sel == 3'h5; // @[SingleCycleCore.scala 122:14]
  wire [31:0] _op2_data_T_5 = _op2_data_T_4 ? imm_u_shifted : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] _op2_data_T_6 = _op2_data_T_3 ? imm_j_sext : _op2_data_T_5; // @[Mux.scala 98:16]
  wire [31:0] _op2_data_T_7 = _op2_data_T_2 ? imm_s_sext : _op2_data_T_6; // @[Mux.scala 98:16]
  wire [31:0] _op2_data_T_8 = _op2_data_T_1 ? imm_i_sext : _op2_data_T_7; // @[Mux.scala 98:16]
  wire [31:0] op2_data = _op2_data_T ? rs2_data : _op2_data_T_8; // @[Mux.scala 98:16]
  wire  _alu_out_T = exe_fun == 4'h0; // @[SingleCycleCore.scala 127:14]
  wire [31:0] _alu_out_T_2 = op1_data + op2_data; // @[SingleCycleCore.scala 127:41]
  wire  _alu_out_T_3 = exe_fun == 4'h1; // @[SingleCycleCore.scala 128:14]
  wire [31:0] _alu_out_T_5 = op1_data - op2_data; // @[SingleCycleCore.scala 128:41]
  wire  _alu_out_T_6 = exe_fun == 4'h2; // @[SingleCycleCore.scala 129:14]
  wire [31:0] _alu_out_T_7 = op1_data & op2_data; // @[SingleCycleCore.scala 129:41]
  wire  _alu_out_T_8 = exe_fun == 4'h3; // @[SingleCycleCore.scala 130:14]
  wire [31:0] _alu_out_T_9 = op1_data | op2_data; // @[SingleCycleCore.scala 130:41]
  wire  _alu_out_T_10 = exe_fun == 4'h4; // @[SingleCycleCore.scala 131:14]
  wire [31:0] _alu_out_T_11 = op1_data ^ op2_data; // @[SingleCycleCore.scala 131:41]
  wire  _alu_out_T_12 = exe_fun == 4'h5; // @[SingleCycleCore.scala 132:14]
  wire [62:0] _GEN_5 = {{31'd0}, op1_data}; // @[SingleCycleCore.scala 132:41]
  wire [62:0] _alu_out_T_14 = _GEN_5 << op2_data[4:0]; // @[SingleCycleCore.scala 132:41]
  wire  _alu_out_T_15 = exe_fun == 4'h6; // @[SingleCycleCore.scala 133:14]
  wire [31:0] _alu_out_T_17 = op1_data >> op2_data[4:0]; // @[SingleCycleCore.scala 133:41]
  wire  _alu_out_T_18 = exe_fun == 4'h7; // @[SingleCycleCore.scala 134:14]
  wire [31:0] _alu_out_T_19 = _op1_data_T ? rs1_data : _op1_data_T_4; // @[SingleCycleCore.scala 134:47]
  wire [31:0] _alu_out_T_22 = $signed(_alu_out_T_19) >>> op2_data[4:0]; // @[SingleCycleCore.scala 134:75]
  wire  _alu_out_T_23 = exe_fun == 4'h8; // @[SingleCycleCore.scala 135:14]
  wire [31:0] _alu_out_T_25 = _op2_data_T ? rs2_data : _op2_data_T_8; // @[SingleCycleCore.scala 135:67]
  wire  _alu_out_T_26 = $signed(_alu_out_T_19) < $signed(_alu_out_T_25); // @[SingleCycleCore.scala 135:50]
  wire  _alu_out_T_27 = exe_fun == 4'h9; // @[SingleCycleCore.scala 136:14]
  wire  _alu_out_T_28 = op1_data < op2_data; // @[SingleCycleCore.scala 136:41]
  wire  _alu_out_T_29 = exe_fun == 4'ha; // @[SingleCycleCore.scala 137:14]
  wire [31:0] _alu_out_T_33 = _alu_out_T_2 & 32'hfffffffe; // @[SingleCycleCore.scala 137:54]
  wire [31:0] _alu_out_T_34 = _alu_out_T_29 ? _alu_out_T_33 : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] _alu_out_T_35 = _alu_out_T_27 ? {{31'd0}, _alu_out_T_28} : _alu_out_T_34; // @[Mux.scala 98:16]
  wire [31:0] _alu_out_T_36 = _alu_out_T_23 ? {{31'd0}, _alu_out_T_26} : _alu_out_T_35; // @[Mux.scala 98:16]
  wire [31:0] _alu_out_T_37 = _alu_out_T_18 ? _alu_out_T_22 : _alu_out_T_36; // @[Mux.scala 98:16]
  wire [31:0] _alu_out_T_38 = _alu_out_T_15 ? _alu_out_T_17 : _alu_out_T_37; // @[Mux.scala 98:16]
  wire [62:0] _alu_out_T_39 = _alu_out_T_12 ? _alu_out_T_14 : {{31'd0}, _alu_out_T_38}; // @[Mux.scala 98:16]
  wire [62:0] _alu_out_T_40 = _alu_out_T_10 ? {{31'd0}, _alu_out_T_11} : _alu_out_T_39; // @[Mux.scala 98:16]
  wire [62:0] _alu_out_T_41 = _alu_out_T_8 ? {{31'd0}, _alu_out_T_9} : _alu_out_T_40; // @[Mux.scala 98:16]
  wire [62:0] _alu_out_T_42 = _alu_out_T_6 ? {{31'd0}, _alu_out_T_7} : _alu_out_T_41; // @[Mux.scala 98:16]
  wire [62:0] _alu_out_T_43 = _alu_out_T_3 ? {{31'd0}, _alu_out_T_5} : _alu_out_T_42; // @[Mux.scala 98:16]
  wire [62:0] alu_out = _alu_out_T ? {{31'd0}, _alu_out_T_2} : _alu_out_T_43; // @[Mux.scala 98:16]
  wire  _wb_data_T = wb_sel == 2'h1; // @[SingleCycleCore.scala 149:13]
  wire  _wb_data_T_1 = wb_sel == 2'h2; // @[SingleCycleCore.scala 150:13]
  wire [31:0] _wb_data_T_3 = pc + 32'h4; // @[SingleCycleCore.scala 150:32]
  wire [62:0] _wb_data_T_4 = _wb_data_T_1 ? {{31'd0}, _wb_data_T_3} : alu_out; // @[Mux.scala 98:16]
  wire [62:0] wb_data = _wb_data_T ? {{31'd0}, io_dmem_rdata} : _wb_data_T_4; // @[Mux.scala 98:16]
  wire  _T_251 = wb_addr != 4'h0; // @[SingleCycleCore.scala 154:40]
  wire  _br_taken_T_2 = rs1_data == rs2_data; // @[SingleCycleCore.scala 160:34]
  wire  _br_taken_T_5 = rs1_data != rs2_data; // @[SingleCycleCore.scala 161:34]
  wire [31:0] _br_taken_T_8 = rs1_addr == 4'h0 ? 32'h0 : regfile_rs1_data_MPORT_data; // @[SingleCycleCore.scala 162:40]
  wire [31:0] _br_taken_T_9 = rs2_addr == 5'h0 ? 32'h0 : regfile_rs2_data_MPORT_data; // @[SingleCycleCore.scala 162:60]
  wire  _br_taken_T_10 = $signed(_br_taken_T_8) < $signed(_br_taken_T_9); // @[SingleCycleCore.scala 162:43]
  wire  _br_taken_T_15 = $signed(_br_taken_T_8) >= $signed(_br_taken_T_9); // @[SingleCycleCore.scala 163:43]
  wire  _br_taken_T_18 = rs1_data < rs2_data; // @[SingleCycleCore.scala 164:34]
  wire  _br_taken_T_21 = rs1_data >= rs2_data; // @[SingleCycleCore.scala 165:34]
  wire  _br_taken_T_23 = _T_51 ? _br_taken_T_18 : _T_53 & _br_taken_T_21; // @[Mux.scala 98:16]
  wire  _br_taken_T_24 = _T_49 ? _br_taken_T_15 : _br_taken_T_23; // @[Mux.scala 98:16]
  wire  _br_taken_T_25 = _T_47 ? _br_taken_T_10 : _br_taken_T_24; // @[Mux.scala 98:16]
  wire  _br_taken_T_26 = _T_45 ? _br_taken_T_5 : _br_taken_T_25; // @[Mux.scala 98:16]
  wire  br_taken = _T_43 ? _br_taken_T_2 : _br_taken_T_26; // @[Mux.scala 98:16]
  wire  jmp_taken = _T_55 | _T_57; // @[SingleCycleCore.scala 168:34]
  wire [31:0] _next_pc_T_3 = pc + imm_b_sext; // @[SingleCycleCore.scala 172:21]
  wire [31:0] _next_pc_T_7 = pc + imm_j_sext; // @[SingleCycleCore.scala 173:49]
  wire [62:0] _next_pc_T_8 = _T_57 ? alu_out : {{31'd0}, _next_pc_T_7}; // @[SingleCycleCore.scala 173:21]
  wire [62:0] _next_pc_T_9 = jmp_taken ? _next_pc_T_8 : {{31'd0}, _wb_data_T_3}; // @[Mux.scala 98:16]
  wire [62:0] next_pc = br_taken ? {{31'd0}, _next_pc_T_3} : _next_pc_T_9; // @[Mux.scala 98:16]
  SimCtrl simCtrl ( // @[SingleCycleCore.scala 16:23]
    .ebreak(simCtrl_ebreak)
  );
  assign regfile_rs1_data_MPORT_addr = io_imem_inst[19:16];
  assign regfile_rs1_data_MPORT_data = regfile[regfile_rs1_data_MPORT_addr]; // @[SingleCycleCore.scala 22:20]
  assign regfile_rs2_data_MPORT_addr = rs2_addr[3:0];
  assign regfile_rs2_data_MPORT_data = regfile[regfile_rs2_data_MPORT_addr]; // @[SingleCycleCore.scala 22:20]
  assign regfile_MPORT_data = wb_data[31:0];
  assign regfile_MPORT_addr = io_imem_inst[11:8];
  assign regfile_MPORT_mask = 1'h1;
  assign regfile_MPORT_en = rf_wen & _T_251;
  assign io_imem_addr = pc; // @[SingleCycleCore.scala 25:16]
  assign io_dmem_addr = alu_out[31:0]; // @[SingleCycleCore.scala 141:16]
  assign io_dmem_wen = _T_1 ? 1'h0 : _T_3; // @[Lookup.scala 33:37]
  assign io_dmem_wdata = rs2_addr == 5'h0 ? 32'h0 : regfile_rs2_data_MPORT_data; // @[SingleCycleCore.scala 35:21]
  assign io_exit = 32'h100073 == io_imem_inst; // @[SingleCycleCore.scala 179:22]
  assign simCtrl_ebreak = 32'h100073 == io_imem_inst; // @[SingleCycleCore.scala 179:22]
  always @(posedge clock) begin
    if(regfile_MPORT_en & regfile_MPORT_mask) begin
      regfile[regfile_MPORT_addr] <= regfile_MPORT_data; // @[SingleCycleCore.scala 22:20]
    end
    if (reset) begin // @[SingleCycleCore.scala 19:19]
      pc <= 32'h80000000; // @[SingleCycleCore.scala 19:19]
    end else begin
      pc <= next_pc[31:0]; // @[SingleCycleCore.scala 176:6]
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (~reset) begin
          $fwrite(32'h80000002,"PC=0x%x INST=0x%x RS1=%d RS2=%d ALU=0x%x WB=0x%x\n",pc,io_imem_inst,rs1_data,rs2_data,
            alu_out,wb_data); // @[SingleCycleCore.scala 184:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 16; initvar = initvar+1)
    regfile[initvar] = _RAND_0[31:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  pc = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Memory(
  input         clock,
  input  [31:0] io_imem_addr,
  output [31:0] io_imem_inst,
  input  [31:0] io_dmem_addr,
  output [31:0] io_dmem_rdata,
  input         io_dmem_wen,
  input  [31:0] io_dmem_wdata
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [7:0] mem [0:16383]; // @[Memory.scala 26:16]
  wire [7:0] mem_io_imem_inst_hi_hi_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_imem_inst_hi_hi_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_imem_inst_hi_lo_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_imem_inst_hi_lo_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_imem_inst_lo_hi_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_imem_inst_lo_hi_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_imem_inst_lo_lo_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_imem_inst_lo_lo_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_dmem_rdata_hi_hi_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_dmem_rdata_hi_hi_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_dmem_rdata_hi_lo_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_dmem_rdata_hi_lo_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_dmem_rdata_lo_hi_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_dmem_rdata_lo_hi_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_io_dmem_rdata_lo_lo_data; // @[Memory.scala 26:16]
  wire [13:0] mem_io_dmem_rdata_lo_lo_addr; // @[Memory.scala 26:16]
  wire [7:0] mem_MPORT_data; // @[Memory.scala 26:16]
  wire [13:0] mem_MPORT_addr; // @[Memory.scala 26:16]
  wire  mem_MPORT_mask; // @[Memory.scala 26:16]
  wire  mem_MPORT_en; // @[Memory.scala 26:16]
  wire [7:0] mem_MPORT_1_data; // @[Memory.scala 26:16]
  wire [13:0] mem_MPORT_1_addr; // @[Memory.scala 26:16]
  wire  mem_MPORT_1_mask; // @[Memory.scala 26:16]
  wire  mem_MPORT_1_en; // @[Memory.scala 26:16]
  wire [7:0] mem_MPORT_2_data; // @[Memory.scala 26:16]
  wire [13:0] mem_MPORT_2_addr; // @[Memory.scala 26:16]
  wire  mem_MPORT_2_mask; // @[Memory.scala 26:16]
  wire  mem_MPORT_2_en; // @[Memory.scala 26:16]
  wire [7:0] mem_MPORT_3_data; // @[Memory.scala 26:16]
  wire [13:0] mem_MPORT_3_addr; // @[Memory.scala 26:16]
  wire  mem_MPORT_3_mask; // @[Memory.scala 26:16]
  wire  mem_MPORT_3_en; // @[Memory.scala 26:16]
  wire [31:0] _io_imem_inst_T_1 = io_imem_addr + 32'h3; // @[Memory.scala 30:22]
  wire [31:0] _io_imem_inst_T_4 = io_imem_addr + 32'h2; // @[Memory.scala 31:22]
  wire [31:0] _io_imem_inst_T_7 = io_imem_addr + 32'h1; // @[Memory.scala 32:22]
  wire [15:0] io_imem_inst_lo = {mem_io_imem_inst_lo_hi_data,mem_io_imem_inst_lo_lo_data}; // @[Cat.scala 30:58]
  wire [15:0] io_imem_inst_hi = {mem_io_imem_inst_hi_hi_data,mem_io_imem_inst_hi_lo_data}; // @[Cat.scala 30:58]
  wire [31:0] _io_dmem_rdata_T_1 = io_dmem_addr + 32'h3; // @[Memory.scala 37:22]
  wire [31:0] _io_dmem_rdata_T_4 = io_dmem_addr + 32'h2; // @[Memory.scala 38:22]
  wire [31:0] _io_dmem_rdata_T_7 = io_dmem_addr + 32'h1; // @[Memory.scala 39:22]
  wire [15:0] io_dmem_rdata_lo = {mem_io_dmem_rdata_lo_hi_data,mem_io_dmem_rdata_lo_lo_data}; // @[Cat.scala 30:58]
  wire [15:0] io_dmem_rdata_hi = {mem_io_dmem_rdata_hi_hi_data,mem_io_dmem_rdata_hi_lo_data}; // @[Cat.scala 30:58]
  assign mem_io_imem_inst_hi_hi_addr = _io_imem_inst_T_1[13:0];
  assign mem_io_imem_inst_hi_hi_data = mem[mem_io_imem_inst_hi_hi_addr]; // @[Memory.scala 26:16]
  assign mem_io_imem_inst_hi_lo_addr = _io_imem_inst_T_4[13:0];
  assign mem_io_imem_inst_hi_lo_data = mem[mem_io_imem_inst_hi_lo_addr]; // @[Memory.scala 26:16]
  assign mem_io_imem_inst_lo_hi_addr = _io_imem_inst_T_7[13:0];
  assign mem_io_imem_inst_lo_hi_data = mem[mem_io_imem_inst_lo_hi_addr]; // @[Memory.scala 26:16]
  assign mem_io_imem_inst_lo_lo_addr = io_imem_addr[13:0];
  assign mem_io_imem_inst_lo_lo_data = mem[mem_io_imem_inst_lo_lo_addr]; // @[Memory.scala 26:16]
  assign mem_io_dmem_rdata_hi_hi_addr = _io_dmem_rdata_T_1[13:0];
  assign mem_io_dmem_rdata_hi_hi_data = mem[mem_io_dmem_rdata_hi_hi_addr]; // @[Memory.scala 26:16]
  assign mem_io_dmem_rdata_hi_lo_addr = _io_dmem_rdata_T_4[13:0];
  assign mem_io_dmem_rdata_hi_lo_data = mem[mem_io_dmem_rdata_hi_lo_addr]; // @[Memory.scala 26:16]
  assign mem_io_dmem_rdata_lo_hi_addr = _io_dmem_rdata_T_7[13:0];
  assign mem_io_dmem_rdata_lo_hi_data = mem[mem_io_dmem_rdata_lo_hi_addr]; // @[Memory.scala 26:16]
  assign mem_io_dmem_rdata_lo_lo_addr = io_dmem_addr[13:0];
  assign mem_io_dmem_rdata_lo_lo_data = mem[mem_io_dmem_rdata_lo_lo_addr]; // @[Memory.scala 26:16]
  assign mem_MPORT_data = io_dmem_wdata[31:24];
  assign mem_MPORT_addr = _io_dmem_rdata_T_1[13:0];
  assign mem_MPORT_mask = 1'h1;
  assign mem_MPORT_en = io_dmem_wen;
  assign mem_MPORT_1_data = io_dmem_wdata[23:16];
  assign mem_MPORT_1_addr = _io_dmem_rdata_T_4[13:0];
  assign mem_MPORT_1_mask = 1'h1;
  assign mem_MPORT_1_en = io_dmem_wen;
  assign mem_MPORT_2_data = io_dmem_wdata[15:8];
  assign mem_MPORT_2_addr = _io_dmem_rdata_T_7[13:0];
  assign mem_MPORT_2_mask = 1'h1;
  assign mem_MPORT_2_en = io_dmem_wen;
  assign mem_MPORT_3_data = io_dmem_wdata[7:0];
  assign mem_MPORT_3_addr = io_dmem_addr[13:0];
  assign mem_MPORT_3_mask = 1'h1;
  assign mem_MPORT_3_en = io_dmem_wen;
  assign io_imem_inst = {io_imem_inst_hi,io_imem_inst_lo}; // @[Cat.scala 30:58]
  assign io_dmem_rdata = {io_dmem_rdata_hi,io_dmem_rdata_lo}; // @[Cat.scala 30:58]
  always @(posedge clock) begin
    if(mem_MPORT_en & mem_MPORT_mask) begin
      mem[mem_MPORT_addr] <= mem_MPORT_data; // @[Memory.scala 26:16]
    end
    if(mem_MPORT_1_en & mem_MPORT_1_mask) begin
      mem[mem_MPORT_1_addr] <= mem_MPORT_1_data; // @[Memory.scala 26:16]
    end
    if(mem_MPORT_2_en & mem_MPORT_2_mask) begin
      mem[mem_MPORT_2_addr] <= mem_MPORT_2_data; // @[Memory.scala 26:16]
    end
    if(mem_MPORT_3_en & mem_MPORT_3_mask) begin
      mem[mem_MPORT_3_addr] <= mem_MPORT_3_data; // @[Memory.scala 26:16]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 16384; initvar = initvar+1)
    mem[initvar] = _RAND_0[7:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Top(
  input   clock,
  input   reset,
  output  io_exit
);
  wire  core_clock; // @[Top.scala 12:20]
  wire  core_reset; // @[Top.scala 12:20]
  wire [31:0] core_io_imem_addr; // @[Top.scala 12:20]
  wire [31:0] core_io_imem_inst; // @[Top.scala 12:20]
  wire [31:0] core_io_dmem_addr; // @[Top.scala 12:20]
  wire [31:0] core_io_dmem_rdata; // @[Top.scala 12:20]
  wire  core_io_dmem_wen; // @[Top.scala 12:20]
  wire [31:0] core_io_dmem_wdata; // @[Top.scala 12:20]
  wire  core_io_exit; // @[Top.scala 12:20]
  wire  memory_clock; // @[Top.scala 13:22]
  wire [31:0] memory_io_imem_addr; // @[Top.scala 13:22]
  wire [31:0] memory_io_imem_inst; // @[Top.scala 13:22]
  wire [31:0] memory_io_dmem_addr; // @[Top.scala 13:22]
  wire [31:0] memory_io_dmem_rdata; // @[Top.scala 13:22]
  wire  memory_io_dmem_wen; // @[Top.scala 13:22]
  wire [31:0] memory_io_dmem_wdata; // @[Top.scala 13:22]
  SingleCycleCore core ( // @[Top.scala 12:20]
    .clock(core_clock),
    .reset(core_reset),
    .io_imem_addr(core_io_imem_addr),
    .io_imem_inst(core_io_imem_inst),
    .io_dmem_addr(core_io_dmem_addr),
    .io_dmem_rdata(core_io_dmem_rdata),
    .io_dmem_wen(core_io_dmem_wen),
    .io_dmem_wdata(core_io_dmem_wdata),
    .io_exit(core_io_exit)
  );
  Memory memory ( // @[Top.scala 13:22]
    .clock(memory_clock),
    .io_imem_addr(memory_io_imem_addr),
    .io_imem_inst(memory_io_imem_inst),
    .io_dmem_addr(memory_io_dmem_addr),
    .io_dmem_rdata(memory_io_dmem_rdata),
    .io_dmem_wen(memory_io_dmem_wen),
    .io_dmem_wdata(memory_io_dmem_wdata)
  );
  assign io_exit = core_io_exit; // @[Top.scala 20:11]
  assign core_clock = clock;
  assign core_reset = reset;
  assign core_io_imem_inst = memory_io_imem_inst; // @[Top.scala 16:16]
  assign core_io_dmem_rdata = memory_io_dmem_rdata; // @[Top.scala 17:16]
  assign memory_clock = clock;
  assign memory_io_imem_addr = core_io_imem_addr; // @[Top.scala 16:16]
  assign memory_io_dmem_addr = core_io_dmem_addr; // @[Top.scala 17:16]
  assign memory_io_dmem_wen = core_io_dmem_wen; // @[Top.scala 17:16]
  assign memory_io_dmem_wdata = core_io_dmem_wdata; // @[Top.scala 17:16]
endmodule
