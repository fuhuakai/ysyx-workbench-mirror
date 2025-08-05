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

// 写使能解码
wire [31:0] reg_wen;
generate
    assign reg_wen[0] = 1'b0;
    
    // 1-31号寄存器写使能
    genvar i;
    for (i = 1; i < 32; i = i + 1) begin
        assign reg_wen[i] = wen && (waddr == i);
    end
endgenerate

wire [31:0] reg_data [31:0];

assign reg_data[0] = 32'b0;  // 0号寄存器读取始终为0

genvar j;
generate
    for (j = 1; j < 32; j = j + 1) begin : reg_gen
        Reg #(32, 0) reg_inst (
            .clk(clk),
            .rst(rst),
            .din(wdata),
            .dout(reg_data[j]),
            .wen(reg_wen[j])
        );
        
        // 调试输出
        always @(posedge clk) begin
            if (reg_wen[j]) begin
                $display("[REG] x%0d <= 0x%8h", j, wdata);
            end
        end
    end
endgenerate

// 读操作
assign rdata1 = reg_data[raddr1];

// 初始化所有寄存器为0
initial begin
    for (integer k = 0; k < 32; k = k + 1) begin
        if (k > 0) reg_data[k] = 32'b0;
    end
    $display("[REG] All registers initialized to 0");
end

endmodule