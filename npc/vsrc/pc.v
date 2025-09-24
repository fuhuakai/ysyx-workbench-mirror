`include "defines.v"
module PC(
  input  wire           clk,
  input  wire           rst,
  input  wire           pc_sel_1,
  input  wire [1:0]     pc_sel_2,
  input  wire [`RegBus] result,
  input  wire [`RegBus] imm32,
  input  wire [`RegBus] csr_npc,
  output wire [`RegBus] PCadd4,
  output reg  [`RegBus] pc
);

  wire [`RegBus] npc;
  wire [`RegBus] npc_temp;
  wire [`RegBus] PCaddIMM32;
  
  assign PCadd4     = pc + `PC_INCREMENT;
  assign PCaddIMM32 = pc + imm32;

  always @(posedge clk) begin
    if(rst == `RST_VAL)
      pc <= `RESET_VECTOR;
    else 
      pc <= npc;
  end

  // MUX1 module
  MuxKey #(2, 1, `BitWidth) i1(npc, (pc_sel_1 & result[0]), {
      `MUX1_NBpc, npc_temp,
      `MUX1_Bpc, PCaddIMM32}
  );

  // MUX2 module
  MuxKey #(4, 2, `BitWidth) i2(npc_temp, (pc_sel_2), {
      `MUX2_PCadd4, PCadd4,
      `MUX2_result, result,
      `MUX2_csrnpc, csr_npc,
      `MUX2_IDLE,   32'hdeadbeef}
  );

endmodule