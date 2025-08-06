module exu(
    input         clk,
    input         rst,
    input  [31:0] rdata1,
    input  [31:0] imm,
    input         is_ebreak,
    output [31:0] wdata,
    output        trap
);

// 使用行为级加法器（避免组合逻辑环路）
assign wdata = rdata1 + imm;

// ebreak处理
Reg #(1, 0) trap_reg (
    .clk(clk),
    .rst(rst),
    .din(is_ebreak),
    .dout(trap),
    .wen(1'b1)
);

// DPI函数声明
import "DPI-C" function void ebreak();

// ebreak触发
always @(posedge trap) begin
    if (trap) begin
        $display("[EXU] EBREAK detected, stopping simulation");
        ebreak();
    end
end

endmodule
