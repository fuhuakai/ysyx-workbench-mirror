
module SimCtrl(
    input ebreak
);

import "DPI-C" function void npc_finish();

always @(*) begin
    if (ebreak) begin
        npc_finish();
    end
end

endmodule
    