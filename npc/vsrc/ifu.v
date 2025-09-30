`include "defines.v"
`define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

module ifu(
    // system
    input  wire            clk,
    input  wire            rst,
    // shake hands
    input  wire            i_cycle_end,   //指示一个指令周期的结束，置位于第5时钟周期
    output wire            o_post_valid,  //传递给IDU，代表此时数据包寄存器的数据有效
    input  wire            i_post_ready,  //来自IDU，代表IDU准备好处理新数据
    // from BRU
    input  wire [`CPU_Bus] i_ifu_npc,
    // to IDU
    output wire [`CPU_Bus] o_ifu_pc,
    output wire [`CPU_Bus] o_ifu_inst
);

    // i_cycle_end 原为单周期节拍，现在IFU改为按SRAM返回建立有效
    // 与IDU握手：当本级持有一份有效包且IDU未ready时，保持有效不丢包

    // SRAM 指令端口（1拍返回）
    wire        s_if_valid;
    wire [31:0] s_if_rdata;
    reg         s_if_req;
    reg [31:0]  s_if_addr_reg;   // 发起请求时锁存PC

    sram_ifu u_sram_ifu (
        .clk    (clk),
        .rst    (rst),
        .i_req  (s_if_req),
        .i_addr (s_if_addr_reg),
        .o_valid(s_if_valid),
        .o_rdata(s_if_rdata)
    );

    // IFU 包寄存与有效保持
    reg  [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;  
    reg                         ifu_valid_hold;      // 本级对外有效保持

    // 取指请求/等待逻辑：
    // - 当本级没有待发布数据(ifu_valid_hold==0)时，针对当前NPC发起一次请求
    // - 请求时锁存地址，等待s_if_valid到来后写入数据包寄存器并拉高ifu_valid_hold
    // - 下游i_post_ready时，清除ifu_valid_hold，允许发起下一次请求
    always @(posedge clk) begin
        if (rst == 1'b1) begin
            s_if_req         <= 1'b0;
            s_if_addr_reg    <= `RESET_VECTOR;
            ifu_valid_data_reg <= {`IFU_PKG_WDITH{1'b0}};
            ifu_valid_hold   <= 1'b0;
        end else begin
            // 默认不连续拉高请求，形成单拍脉冲
            s_if_req <= 1'b0;

            // 若当前没有待发布数据，则对最新的NPC发起请求
            if (ifu_valid_hold == 1'b0) begin
                s_if_req      <= 1'b1;
                s_if_addr_reg <= i_ifu_npc;
            end

            // SRAM 返回后写入包，并对外宣称有效
            if (s_if_valid == 1'b1) begin
                ifu_valid_data_reg <= {s_if_addr_reg, s_if_rdata};
                ifu_valid_hold     <= 1'b1;
            end

            // 下游消费后，释放本级有效，允许下一次请求
            if (ifu_valid_hold == 1'b1 && i_post_ready == 1'b1) begin
                ifu_valid_hold <= 1'b0;
            end
        end
    end

    // to IDU
    assign {o_ifu_pc, o_ifu_inst} = ifu_valid_data_reg;
    // shake hands
    assign o_post_valid = ifu_valid_hold;

endmodule

