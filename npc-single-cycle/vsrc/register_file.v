`include "defines.v"

module register_file(
    input  wire           clk,
    input  wire           rst,
    input  wire           reg_wen,
    input  wire [4:0]     rs1,
    input  wire [4:0]     rs2,
    input  wire [4:0]     rd,
    input  wire [1:0]     wb_sel,     // MUX5 select
    input  wire [`RegBus] PCadd4,     // MUX5 input
    input  wire [`RegBus] mem_rdata,  // MUX5 input
    input  wire [`RegBus] result,     // MUX5 input
    input  wire [`RegBus] csr_data,   // MUX5 input
    output wire [`RegBus] src1,
    output wire [`RegBus] src2
);

    integer i;
    reg[`RegBus] regs[`BitWidth-1 : 0];

    wire [`RegBus] reg_in;

    MuxKey #(4, 2, `BitWidth) i5(reg_in, wb_sel, {
        `MUX5_PCadd4, PCadd4,
        `MUX5_memdat, mem_rdata,
        `MUX5_result, result,
        `MUX5_Csrdata,csr_data}
    );

    //wire register
    always @(posedge clk) begin
        if(rst == `RST_VAL) begin
            for(i=0; i<`RegNum; i=i+1) begin
                regs[i] <= `RegRstVal;  
            end
        end else if((reg_wen == 1'b1) && (rd != `Reg0))
            regs[rd] <= reg_in; 
        else
            regs[rd] <= regs[rd]; 
    end

    //read register
    assign src1 = (rs1 == `Reg0) ? `Reg0_VAL : regs[rs1];
    assign src2 = (rs2 == `Reg0) ? `Reg0_VAL : regs[rs2];
   
endmodule
