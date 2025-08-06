`include "template.v"

module top(
    input  clk,
    input  rst,
    output [31:0] pc,        // 指令地址输出
    input  [31:0] inst,      // 指令输入
    output        trap       // ebreak触发信号
);

// PC寄存器
wire [31:0] next_pc;
Reg #(32, 32'h80000000) pc_reg(
    .clk(clk),
    .rst(rst),
    .din(next_pc),
    .dout(pc),
    .wen(1'b1)
);

// PC更新逻辑
assign next_pc = pc + 4;  // 顺序执行

// 译码和执行信号
wire        rf_wen;
wire [4:0]  rf_raddr1;
wire [31:0] rf_rdata1;
wire [4:0]  rf_waddr;
wire [31:0] rf_wdata;
wire [31:0] imm;
wire        is_ebreak;

// 指令译码单元
idu idu(
    .inst(inst),
    .rs1(rf_raddr1),
    .rd(rf_waddr),
    .imm(imm),
    .wen(rf_wen),
    .is_ebreak(is_ebreak)
);

// 寄存器
regs regs(
    .clk(clk),
    .rst(rst),
    .raddr1(rf_raddr1),
    .rdata1(rf_rdata1),
    .waddr(rf_waddr),
    .wdata(rf_wdata),
    .wen(rf_wen)
);

// 执行单元
exu exu(
    .clk(clk),
    .rst(rst),
    .rdata1(rf_rdata1),
    .imm(imm),
    .is_ebreak(is_ebreak),
    .wdata(rf_wdata),
    .trap(trap)
);

endmodule
