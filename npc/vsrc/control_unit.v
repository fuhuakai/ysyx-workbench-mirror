`include "defines.v"

module control_unit(
    input  wire [`RegBus]   inst,
    output wire [4:0]       rd_11_7,
    output wire [4:0]       rs1_19_15,
    output wire [4:0]       rs2_24_20,
    output wire [2:0]       fun3_14_12,
    output wire [6:0]       fun7_31_25,
    output reg  [`TYPE_BUS] Inst_type,      // instruction type
    output reg  [`AlucBus]  aluc,           // ALU operation type
    output reg              reg_wen,        // Register File write enable
    output reg              is_ecall,       // is ecall instruction
    output reg              csr_wen,        // CSR regs write enable
    output reg              mem_wen,        // memory write enable
    output reg              mem_ren,        // memory read enable
    output reg  [7:0]       wmask,          // memory write mask
    output reg  [2:0]       rmask,          // memory read mask
    output reg              pc_sel_1,       // PC MUX1 select
    output reg  [1:0]       pc_sel_2,       // PC MUX2 select
    output reg              alu_sel_2,      // ALU MUX2 select
    output reg              alu_sel_1,      // ALU MUX1 select
    output reg  [1:0]       wb_sel          // write back MUX select
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);
    import "DPI-C" function void etrace(input int inst);

    wire [6:0] opcode_6_0 = inst[6:0];
    assign rd_11_7        = inst[11:7];
    assign rs1_19_15      = inst[19:15];
    assign rs2_24_20      = inst[24:20];
    assign fun3_14_12     = inst[14:12];  
    assign fun7_31_25     = inst[31:25];  

    always @(*) begin
        csr_wen = `WDisen;
        
        case(opcode_6_0)
            `INST_TYPE_R: begin
                Inst_type = `INST_R;   
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_src2;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_result;
                
                if(fun7_31_25 == 7'b000_0000) begin
                    case (fun3_14_12)
                        `INST_ADD:  aluc = `ADD;
                        `INST_SLL:  aluc = `SLL;
                        `INST_SLT:  aluc = `LT;
                        `INST_SLTU: aluc = `LTU;
                        `INST_XOR:  aluc = `XOR;
                        `INST_SRL:  aluc = `SRL;
                        `INST_OR:   aluc = `OR;
                        `INST_AND:  aluc = `AND;
                        default:    ebreak(`ABORT, inst, `Unit_CU1);
                    endcase                
                end else if(fun7_31_25 == 7'b010_0000) begin
                    case (fun3_14_12)
                        `INST_SUB: aluc = `SUB;
                        `INST_SRA: aluc = `SRA;
                        default:   ebreak(`ABORT, inst, `Unit_CU2);
                    endcase  
                end else begin
                    ebreak(`ABORT, inst, `Unit_CU3);
                end
            end
            
            `INST_TYPE_I: begin
                Inst_type = `INST_I;   
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_result;
                
                case (fun3_14_12)
                    `INST_ADDI:  aluc = `ADD;
                    `INST_SLTIU: aluc = `LTU;
                    `INST_XORI:  aluc = `XOR;
                    `INST_ORI:   aluc = `OR;
                    `INST_ANDI:  aluc = `AND;
                    `INST_SLLI:  aluc = `SLL;
                    `INST_SRLAI: begin 
                        case (fun7_31_25)
                            7'b000_0000: aluc = `SRL;
                            7'b010_0000: aluc = `SRA;
                            default: ebreak(`ABORT, inst, `Unit_CU4);
                        endcase
                    end 
                    default: ebreak(`ABORT, inst, `Unit_CU5);
                endcase
            end          
            
            `INST_TYPE_L: begin
                Inst_type = `INST_I; 
                aluc      = `ADD;  
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WEnable;   
                wmask     = `WWord;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_memdat;
                
                case (fun3_14_12)
                    `INST_LB:  rmask = `LoadB;
                    `INST_LH:  rmask = `LoadH;
                    `INST_LW:  rmask = `LoadW;
                    `INST_LBU: rmask = `LoadBU;
                    `INST_LHU: rmask = `LoadHU;
                    default:   ebreak(`ABORT, inst, `Unit_CU6);
                endcase
            end
            
            `INST_TYPE_S: begin
                Inst_type = `INST_S;   
                aluc      = `ADD;
                reg_wen   = `WDisen;   
                mem_wen   = `WEnable;   
                mem_ren   = `WDisen;   
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_memdat;
                
                case (fun3_14_12)
                    `INST_SB: wmask = `WByte;
                    `INST_SH: wmask = `WHalf;
                    `INST_SW: wmask = `WWord;
                    default:  ebreak(`ABORT, inst, `Unit_CU7);
                endcase
            end
            
            `INST_TYPE_B: begin
                Inst_type = `INST_B;   
                reg_wen   = `WDisen;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;            
                rmask     = `LoadW;            
                pc_sel_1  = `MUX1_Bpc;
                pc_sel_2  = `MUX2_PCadd4;      // not used in branch
                alu_sel_2 = `MUX3_src2;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_result;      // not used in branch
                
                case (fun3_14_12)
                    `INST_BEQ:  aluc = `EQ;
                    `INST_BNE:  aluc = `NE;
                    `INST_BLT:  aluc = `LT;
                    `INST_BGE:  aluc = `GE;
                    `INST_BLTU: aluc = `LTU;
                    `INST_BGEU: aluc = `GEU;
                    default:    ebreak(`ABORT, inst, `Unit_CU8);
                endcase
            end
            
            `INST_TYPE_LUI: begin
                Inst_type = `INST_U;   
                aluc      = `ADD_LUI;
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_src1;      // not used for LUI
                wb_sel    = `MUX5_result;
            end
            
            `INST_TYPE_AUIPC: begin
                Inst_type = `INST_U;   
                aluc      = `ADD;
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_PCadd4;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_pc;
                wb_sel    = `MUX5_result;
            end
            
            `INST_TYPE_JALR: begin
                Inst_type = `INST_I;   
                aluc      = `ADD_JALR;
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_result;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_src1;
                wb_sel    = `MUX5_PCadd4;
            end            
            
            `INST_TYPE_JAL: begin
                Inst_type = `INST_J;   
                aluc      = `ADD;
                reg_wen   = `WEnable;   
                mem_wen   = `WDisen;   
                mem_ren   = `WDisen;   
                wmask     = `WWord;          
                rmask     = `LoadW;          
                pc_sel_1  = `MUX1_NBpc;
                pc_sel_2  = `MUX2_result;
                alu_sel_2 = `MUX3_imm32;
                alu_sel_1 = `MUX4_pc;
                wb_sel    = `MUX5_PCadd4;
            end
            
            `INST_TYPE_E: begin
                Inst_type  = `INST_I;       
                aluc       = `ADD;             
                mem_wen    = `WDisen;   
                mem_ren    = `WDisen;   
                wmask      = `WWord;                
                rmask      = `LoadW;              
                pc_sel_1   = `MUX1_NBpc;
                alu_sel_2  = `MUX3_imm32;       
                alu_sel_1  = `MUX4_pc;          
                wb_sel     = `MUX5_Csrdata;                
                case (fun3_14_12)
                    `INST_CSRRW, `INST_CSRRS: begin
                            is_ecall = `FALSE;   
                            csr_wen  = `WEnable;   
                            reg_wen  = `WEnable;   
                            pc_sel_2 = `MUX2_PCadd4;
                        end
                    default: begin
                        case ({fun7_31_25, rs2_24_20})
                            `INST_MRET:   begin
                                is_ecall = `FALSE;   
                                csr_wen  = `WDisen;   
                                reg_wen  = `WDisen; 
                                pc_sel_2 = `MUX2_csrnpc;
                            end
                            `INST_ECALL:  begin
                                is_ecall = `TRUE;   
                                csr_wen  = `WEnable;   
                                reg_wen  = `WEnable;                                  
                                pc_sel_2 = `MUX2_csrnpc;
                                etrace(32'hdeadbeef);
                            end
                            `INST_EBREAK: ebreak(`HIT_TRAP, inst, `Unit_CU9);
                            default:      ebreak(`ABORT, inst, `Unit_CU10);
                        endcase
                    end
                endcase

            end
            default: ebreak(`ABORT, inst, `Unit_CU11);  
        endcase
    end
    
endmodule