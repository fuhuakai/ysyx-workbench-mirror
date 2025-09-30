`include "defines.v"

module alu(
    input  wire [`AlucBus] aluc,
    input  wire            alu_sel_1,  // MUX3 select
    input  wire            alu_sel_2,  // MUX4 select
    input  wire [`RegBus]  pc,         // MUX3 input
    input  wire [`RegBus]  src1,       // MUX3 input
    input  wire [`RegBus]  src2,       // MUX4 input
    input  wire [`RegBus]  imm32,      // MUX4 input
    output reg  [`RegBus]  result
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);
    
    wire [`RegBus] num1;
    wire [`RegBus] num2;

    MuxKey #(2, 1, `BitWidth) i3(num1, alu_sel_1, {
        `MUX3_pc,   pc,
        `MUX3_src1, src1}
    );

    MuxKey #(2, 1, `BitWidth) i4(num2, alu_sel_2, {
        `MUX4_src2,  src2,
        `MUX4_imm32, imm32}
    );

    wire [`RegBus] temp = {{(`BitWidth - 1){1'b1}}, 1'b0};  //for example, BitWidth = 32，then temp = 0xfffe
    wire [`RegBus] num2_cplm = ~num2 + `RegNum'h1;    //complement code
    wire [`RegBus] num2_temp = (num2 & 32'h1f);    

    always @(*) begin
        case (aluc)
            `ADD:      result = num1 + num2;
            `SUB:      result = num1 + num2_cplm;
            `SLL:      result = num1 << num2;
            `XOR:      result = num1 ^ num2;
            `SRL:      result = num1 >> (num2 & 32'h1f);
            `SRA:      result = ($signed(num1)) >>> (num2 & 32'h1f);
            `OR:       result = num1 | num2;
            `AND:      result = num1 & num2;
            `EQ:       result = {{(`BitWidth - 1){1'b0}}, (num1 == num2)};
            `NE:       result = {{(`BitWidth - 1){1'b0}}, (num1 != num2)};
            `LT:       result = {{(`BitWidth - 1){1'b0}}, (($signed(num1)) <  ($signed(num2)))};
            `GE:       result = {{(`BitWidth - 1){1'b0}}, (($signed(num1)) >= ($signed(num2)))};
            `LTU:      result = {{(`BitWidth - 1){1'b0}}, (num1 <  num2)};
            `GEU:      result = {{(`BitWidth - 1){1'b0}}, (num1 >= num2)};
            `ADD_LUI:  result = num2;
            `ADD_JALR: result = (num1 + num2) & temp;
            default:   begin
                        ebreak(`ABORT, 32'hdeafbeaf, `Unit_ALU);
                        result = 0;
                       end
        endcase
    end

endmodule
