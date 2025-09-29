`include "defines.v"

module sram_ifu(
    input  wire        clk,
    input  wire        rst,
    input  wire        i_req,     // 拉高1拍发起一次读取
    input  wire [31:0] i_addr,    // 读地址
    output reg         o_valid,   // 下一拍返回有效
    output reg  [31:0] o_rdata    // 返回数据
);

    import "DPI-C" function int imem_read(input int raddr);

    reg [31:0] rdata_reg;
    reg        pend;              // 等待返回标志

    always @(posedge clk) begin
        if (rst) begin
            pend    <= 1'b0;
            o_valid <= 1'b0;
            o_rdata <= 32'b0;
        end else begin
            // 发起请求：本拍触发DPI读，结果先寄存
            if (i_req && !pend) begin
                rdata_reg <= imem_read(i_addr);
                pend      <= 1'b1;
            end
            // 下一拍输出有效（单拍脉冲）
            if (pend) begin
                o_valid <= 1'b1;
                o_rdata <= rdata_reg;
                pend    <= 1'b0;
            end else begin
                o_valid <= 1'b0;
            end
        end
    end

endmodule


