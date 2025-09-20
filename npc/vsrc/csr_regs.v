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

    //(funct3 == 010) : csrrs
    //(funct3 == 001) : csrrw or ecall
    assign csr_wdata = (funct3[1] == 1'b0) ? src1 : (src1 | csr_data);
    
    //csr_addr =  {funct7, rs2}
    //rs2 == 00000 : ecall : npc =mtvec
    //rs2 == 00010 : mret : npc =mepc
    assign csr_npc = (csr_addr[1] == 1'b0) ? mtvec : mepc;

    //write csr
    always @(posedge clk) begin
        if(rst == `RST_VAL) begin
            mstatus <= `RegRstVal;
            mtvec   <= `RegRstVal;
            mepc    <= `RegRstVal;
            mcause  <= `RegRstVal;
        end else if (is_ecall == 1'b1) begin
            mepc   <= pc;
            mcause <= `Mcause_Ecall;//mcause赋值为11
            //mcause <= csr_wdata;
        end else if (csr_wen == 1'b1) begin
            case (csr_addr)
                `CSR_MSTATUS: mstatus <= csr_wdata;
                `CSR_MTVEC:   mtvec   <= csr_wdata;
                `CSR_MEPC:    mepc    <= csr_wdata;
                `CSR_MCAUSE:  mcause  <= csr_wdata;
                default:      ebreak(`ABORT, 32'hdeadbeef, `Unit_CSR);  
            endcase
        end
    end

    //read csr
    always @(*) begin
        case (csr_addr)
            `CSR_MSTATUS: csr_data = mstatus;
            `CSR_MTVEC  : csr_data = mtvec;
            `CSR_MEPC   : csr_data = mepc;
            `CSR_MCAUSE : csr_data = mcause;
            default     : csr_data = `RegRstVal;
        endcase
    end

endmodule









