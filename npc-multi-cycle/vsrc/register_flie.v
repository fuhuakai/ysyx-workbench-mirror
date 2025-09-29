`include "defines.v"

module register_file(
    // system
    input  wire           clk,
    input  wire           rst,
    // from WBU
    input  wire           i_rf_gpr_wen,
    input  wire [4:0]     i_rf_rd_id,
    input  wire [`RegBus] i_rf_rd,
    // from IDU
    input  wire [4:0]     i_rf_rs_id1,
    input  wire [4:0]     i_rf_rs_id2,
    // to EXU
    output wire [`RegBus] o_rf_rs1,
    output wire [`RegBus] o_rf_rs2
);

    integer i;
    reg [`RegBus] regs[`RegNum-1:0];

    // write register
    always @(posedge clk) begin
        if(rst == `RST_VAL) begin
            for(i = 0; i < `RegNum; i = i + 1) begin
                regs[i] <= `RegRstVal;  
            end
        end else if((i_rf_gpr_wen == `Enable) && (i_rf_rd_id != `Reg_x0)) begin
            regs[i_rf_rd_id] <= i_rf_rd; 
        end
    end

    // read register
    assign o_rf_rs1 = regs[i_rf_rs_id1];
    assign o_rf_rs2 = regs[i_rf_rs_id2];
   
endmodule

