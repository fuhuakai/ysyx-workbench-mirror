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

    import "DPI-C" function int  imem_read(input int raddr);

    // i_cycle_end --> ⌈‾‾‾‾‾⌉ --> o_post_valid
    //                 | IFU |                 
    //                 ⌊_____⌋ <-- i_post_ready


    // data package
    // wire [`CPU_Bus]             ifu_inst = imem_read(i_ifu_npc);
    // reg  [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;  
    // wire                        ifu_reg_wen  = i_cycle_end;   //数据包寄存器的写使能
    // always @(posedge clk) begin
    //     if(rst == 1'b1) 
    //         ifu_valid_data_reg <= 0;
    //     else if(ifu_reg_wen == 1'b1)
    //         ifu_valid_data_reg <= {i_ifu_npc, ifu_inst};
    // end

    // // to IDU
    // assign {o_ifu_pc, o_ifu_inst} = ifu_valid_data_reg;
    // // shake hands
    // assign o_post_valid = ~i_cycle_end;
// 添加复位保护机制
    reg rst_delay;
    always @(posedge clk) begin
        rst_delay <= rst;
    end
    
    // 只有在复位完全释放后才开始真正的取指
    wire real_rst = rst | rst_delay;
    
    // data package
    reg [`CPU_Bus] current_pc;
    wire [`CPU_Bus] ifu_inst;
    reg [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;  
    wire                        ifu_reg_wen  = i_cycle_end;
    
    // 安全的取指地址选择
    wire [`CPU_Bus] fetch_addr;
    assign fetch_addr = (real_rst == 1'b1) ? `RESET_VECTOR : i_ifu_npc;
    
    // 取指 - 添加复位保护
    assign ifu_inst = (real_rst == 1'b1) ? 32'h00000013 : imem_read(fetch_addr);
    
    // 更新当前PC
    always @(posedge clk) begin
        if(real_rst == 1'b1) 
            current_pc <= `RESET_VECTOR;
        else if(ifu_reg_wen == 1'b1)
            current_pc <= i_ifu_npc;
    end

    always @(posedge clk) begin
        if(real_rst == 1'b1) 
            ifu_valid_data_reg <= {`RESET_VECTOR, 32'h00000013};
        else if(ifu_reg_wen == 1'b1)
            ifu_valid_data_reg <= {current_pc, ifu_inst};
    end

    assign {o_ifu_pc, o_ifu_inst} = ifu_valid_data_reg;
    assign o_post_valid = (real_rst == 1'b1) ? 1'b0 : ~i_cycle_end;

endmodule

