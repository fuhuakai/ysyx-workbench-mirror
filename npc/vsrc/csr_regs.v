`include "defines.v"

module csr_regs(
    input   wire           clk,
    input   wire           rst,
    input   wire           is_ecall,
    input   wire [2:0]     funct3,
    input   wire           csr_wen,
    input   wire [11:0]    csr_addr,
    input   wire [`RegBus] src1,
    input   wire [`RegBus] pc,
    output  wire [`RegBus] csr_npc,
    output  reg  [`RegBus] csr_data
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);

    reg [`RegBus] mstatus;
    reg [`RegBus] mtvec;
    reg [`RegBus] mepc;
    reg [`RegBus] mcause;
    wire[`RegBus] csr_wdata;

//     //(funct3 == 010) : csrrs
//     //(funct3 == 001) : csrrw or ecall
//     assign csr_wdata = (funct3[1] == 1'b0) ? src1 : (src1 | csr_data);
    
//     //csr_addr =  {funct7, rs2}
//     //rs2 == 00000 : ecall : npc =mtvec
//     //rs2 == 00010 : mret : npc =mepc
//     assign csr_npc = (csr_addr[1] == 1'b0) ? mtvec : mepc;

//     //write csr
//     always @(posedge clk) begin
//         if(rst == `RST_VAL) begin
//             mstatus <= `RegRstVal;
//             mtvec   <= `RegRstVal;
//             mepc    <= `RegRstVal;
//             mcause  <= `RegRstVal;
//         end else if (is_ecall == 1'b1) begin
//             mepc   <= pc;
//             mcause <= `Mcause_Ecall;//mcause赋值为11
//             //mcause <= csr_wdata;
//         end else if (csr_wen == 1'b1) begin
//             case (csr_addr)
//                 `CSR_MSTATUS: mstatus <= csr_wdata;
//                 `CSR_MTVEC:   mtvec   <= csr_wdata;
//                 `CSR_MEPC:    mepc    <= csr_wdata;
//                 `CSR_MCAUSE:  mcause  <= csr_wdata;
//                 default:      ebreak(`ABORT, 32'hdeadbeef, `Unit_CSR);  
//             endcase
//         end
//     end

//     //read csr
//     always @(*) begin
//         case (csr_addr)
//             `CSR_MSTATUS: csr_data = mstatus;
//             `CSR_MTVEC  : csr_data = mtvec;
//             `CSR_MEPC   : csr_data = mepc;
//             `CSR_MCAUSE : csr_data = mcause;
//             default     : csr_data = `RegRstVal;
//         endcase
//     end

// endmodule

    // --- 新增： pipeline registers to stabilize csr write operation ---
    reg         is_ecall_d;
    reg         csr_wen_d;
    reg [2:0]   funct3_d;
    reg [11:0]  csr_addr_d;
    reg [`RegBus] src1_d;
    reg [`RegBus] pc_d;
    // optional: latched csr_data for use when needed (keeps combinational read intact)
    // reg [`RegBus] csr_data_d; // not used by default to avoid extra latency

    // capture control & data at posedge to avoid combinational hazards
    always @(posedge clk) begin
        if (rst == `RST_VAL) begin
            is_ecall_d <= 1'b0;
            csr_wen_d  <= 1'b0;
            funct3_d   <= 3'b0;
            csr_addr_d <= 12'b0;
            src1_d     <= `RegRstVal;
            pc_d       <= `RegRstVal;
        end else begin
            // latch the inputs used for CSR write decision
            is_ecall_d <= is_ecall;
            csr_wen_d  <= csr_wen;
            funct3_d   <= funct3;
            csr_addr_d <= csr_addr;
            src1_d     <= src1;
            pc_d       <= pc;
        end
    end

    // --- CSR registers (synchronous write) using latched control/data ---
    always @(posedge clk) begin
        if(rst == `RST_VAL) begin
                mstatus <= `RegRstVal;  
                mtvec   <= `RegRstVal;  
                mepc    <= `RegRstVal;  
                mcause  <= `RegRstVal;  
        end else if(is_ecall_d == 1'b1) begin
            // on ecall use fixed cause (you already do this)
            mepc   <= pc_d;
            mcause <= `Mcause_Ecall; // keep your chosen constant
        end else if(csr_wen_d == 1'b1) begin
            // compute the csr write data based on latched inputs and current csr_data
            // Note: we still use current csr_data (combinational read) to support csrrs semantics.
            // csr_wdata_l is combinational function of funct3_d and src1_d and csr_data
            case (csr_addr_d)
                12'h300: mstatus <= (funct3_d[1] == 1'b0) ? src1_d : (src1_d | mstatus);
                12'h305: mtvec   <= (funct3_d[1] == 1'b0) ? src1_d : (src1_d | mtvec);
                12'h341: mepc    <= (funct3_d[1] == 1'b0) ? src1_d : (src1_d | mepc);
                12'h342: mcause  <= (funct3_d[1] == 1'b0) ? src1_d : (src1_d | mcause);
                default: ebreak(`ABORT, 32'hdead000a, `Unit_CSR);
            endcase
        end
    end

    // --- read path: keep combinational read for low-latency ---
    // Use current csr input for addressing the read; if you want fully deterministic
    // reads relative to write stage, you can also use csr_addr_d.
    always @(*) begin
        case (csr_addr)
            12'h300: csr_data = mstatus;
            12'h305: csr_data = mtvec;
            12'h341: csr_data = mepc;
            12'h342: csr_data = mcause;
            default: csr_data = 32'hdead000b;
        endcase
    end
endmodule







