module idu(
    input  [31:0] inst,
    output [4:0]  rs1,
    output [4:0]  rd,
    output [31:0] imm,
    output        wen,
    output        is_ebreak
);

// 指令字段
wire [6:0] opcode = inst[6:0];
wire [2:0] funct3 = inst[14:12];

// 控制信号
assign wen = (opcode == 7'b0010011) && (funct3 == 3'b000); // addi
assign is_ebreak = (opcode == 7'b1110011) && (funct3 == 3'b000) && (inst[20]); // ebreak

// 寄存器地址
assign rs1 = inst[19:15];
assign rd  = inst[11:7];

// 立即数生成 (I-type)
assign imm[31:12] = {20{inst[31]}};  // 符号扩展
assign imm[11:0]  = inst[31:20];

// 调试输出
always @(*) begin
    $display("[IDU] inst=0x%8h, opcode=0x%02x, rs1=x%0d, rd=x%0d, imm=0x%8h", 
             inst, opcode, rs1, rd, imm);
end

endmodule