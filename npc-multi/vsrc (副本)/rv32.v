`include "defines.v"

module rv32(
  input  wire           clk,
  input  wire           rst
);
  
  wire[4:0]       rs1;
  wire[4:0]       rs2;
  wire[4:0]       rd;
  wire[2:0]       funct3;
  wire[6:0]       funct7;
/* verilator lint_off UNOPTFLAT */
  wire[`RegBus]   inst;     
/* verilator lint_off UNOPTFLAT */
  wire[`RegBus]   pc;     
  wire[`TYPE_BUS] Inst_type;      //inst type
  wire            is_ecall;
  wire            csr_wen;    //csr write enable
  wire            reg_wen;    //RegFile write enable
  wire            mem_wen;    //mem write enable
  wire            mem_ren;    //mem read  enable
  wire[7:0]       wmask;      //mem write mask
  wire[2:0]       rmask;      //mem read  mask
  wire            pc_sel_1;   //mux1 sel
  wire[1:0]       pc_sel_2;   //mux2 sel
  wire            alu_sel_1;  //mux3 sel
  wire            alu_sel_2;  //mux4 sel
  wire[1:0]       wb_sel;     //mux5 sel
  wire[`AlucBus]  aluc;       //alu operation type, like add, sub...
  wire[`RegBus]   PCadd4;     //pc + 4
  wire[`RegBus]   result;     //alu operation result
  wire[`RegBus]   reg_in;     //regisrer file input value
  wire[`RegBus]   src1;       //rs1 value
  wire[`RegBus]   src2;       //rs2 value
  wire[`RegBus]   imm32;      //extended 32 bit immediate
  wire[`RegBus]   num1;       //alu operation number1       
  wire[`RegBus]   num2;       //alu operation number2
  wire[`RegBus]   mem_rdata;  //mem read data
  wire[`RegBus]   csr_npc;    //next pc read from csr 
  wire[`RegBus]   csr_data;   //csr read data

  // PC module
  PC PC_inst(
    .clk        (clk),
    .rst        (rst),
    .pc_sel_1   (pc_sel_1),
    .pc_sel_2   (pc_sel_2),
    .result     (result),
    .imm32      (imm32),
    .csr_npc    (csr_npc),
    .PCadd4     (PCadd4),
    .pc         (pc)   
  );

  // mem module
  mem mem_inst(
    .clk        (clk),  
    .mem_wen    (mem_wen),  
    .wmask      (wmask),
    .waddr      (result),
    .wdata      (src2),
    .mem_ren    (mem_ren),  
    .rmask      (rmask),
    .raddr      (result),
    .inst_addr  (pc),
    .rdata      (mem_rdata),
    .inst_data  (inst)
  );

  // Control Unit module
  control_unit control_unit_inst(
    .inst       (inst),
    .rd_11_7    (rd),
    .rs1_19_15  (rs1),
    .rs2_24_20  (rs2),
    .fun3_14_12 (funct3),
    .fun7_31_25 (funct7),
    .Inst_type  (Inst_type),
    .aluc       (aluc),
    .is_ecall   (is_ecall),
    .csr_wen    (csr_wen),
    .reg_wen    (reg_wen),    
    .mem_wen    (mem_wen),
    .mem_ren    (mem_ren),  
    .wmask      (wmask),
    .rmask      (rmask),
    .pc_sel_1   (pc_sel_1),    
    .pc_sel_2   (pc_sel_2), 
    .alu_sel_1  (alu_sel_1),    
    .alu_sel_2  (alu_sel_2),     
    .wb_sel     (wb_sel)
  );

  // Register File module
  register_file register_file_inst(
    .clk        (clk),
    .rst        (rst),
    .reg_wen    (reg_wen),
    .rs1        (rs1),
    .rs2        (rs2),
    .rd         (rd),
    .reg_in     (reg_in),
    .src1       (src1),
    .src2       (src2)
  );

  // CSR Registers  module
  csr_regs csr_regs_inst(
    .clk     (clk),
    .rst     (rst),
    .is_ecall(is_ecall),
    .csr_wen (csr_wen),
    .funct3  (funct3),
    .csr_addr({funct7, rs2}),
    .src1    (src1),
    .pc      (pc),
    .csr_npc (csr_npc),
    .csr_data(csr_data)
  );

  // Imm Extend module
  imm_extend imm_extend_inst(
    .rs1    (rs1),
    .rs2    (rs2),
    .rd     (rd),
    .funct3 (funct3),
    .funct7 (funct7),
    .Inst_type (Inst_type),
    .imm32  (imm32)
  );

  // MUX3 module
  MuxKey #(2, 1, `BitWidth) i3(num1, alu_sel_1, {
      `MUX3_pc,   pc,
      `MUX3_src1, src1}
  );

  // MUX4 module
  MuxKey #(2, 1, `BitWidth) i4(num2, alu_sel_2, {
      `MUX4_src2,  src2,
      `MUX4_imm32, imm32}
  );

  // MUX5 module
  MuxKey #(4, 2, `BitWidth) i5(reg_in, wb_sel, {
      `MUX5_PCadd4, PCadd4,
      `MUX5_memdat, mem_rdata,
      `MUX5_result, result,
      `MUX5_Csrdata, csr_data}       
  );
  
  // ALU module
  alu alu_inst(
    .aluc   (aluc),
    .num1   (num1),
    .num2   (num2),
    .result (result)
  );
endmodule
