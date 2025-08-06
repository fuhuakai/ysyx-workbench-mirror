`include "template.v"

module regs(
    input         clk,
    input         rst,
    input  [4:0]  raddr1,
    output [31:0] rdata1,
    input  [4:0]  waddr,
    input  [31:0] wdata,
    input         wen
);

// 寄存器存储
wire [31:0] reg_val [31:0];

// 0号寄存器特殊处理
assign reg_val[0] = 32'b0;  // 读取始终为0

// 1-31号寄存器实例化
genvar i;
generate
    for (i = 1; i < 32; i = i + 1) begin : reg_gen
        // 写使能条件
        wire wen_i = wen && (waddr == i);
        
        Reg #(32, 0) reg_inst (
            .clk(clk),
            .rst(rst),
            .din(wdata),
            .dout(reg_val[i]),
            .wen(wen_i)
        );
        
        // 调试输出
        always @(posedge clk) begin
            if (wen_i) begin
                $display("[REG] x%0d <= 0x%8h", i, wdata);
            end
        end
    end
endgenerate

// 读操作
assign rdata1 = (raddr1 == 0) ? 32'b0 : reg_val[raddr1];

endmodule
