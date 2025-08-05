module exu(
    input  [31:0] rdata1,
    input  [31:0] imm,
    input         is_ebreak,
    output [31:0] wdata,
    output        trap
);

// 使用结构化加法器
wire [31:0] adder_out;
assign wdata = adder_out;

// 32位加法器实现
genvar i;
wire [32:0] carry;
assign carry[0] = 1'b0;

generate
    for (i = 0; i < 32; i = i + 1) begin : adder_gen
        wire a = rdata1[i];
        wire b = imm[i];
        wire cin = carry[i];
        wire sum, cout;
        
        // 全加器实现
        assign sum = a ^ b ^ cin;
        assign cout = (a & b) | (a & cin) | (b & cin);
        
        assign adder_out[i] = sum;
        assign carry[i+1] = cout;
    end
endgenerate

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