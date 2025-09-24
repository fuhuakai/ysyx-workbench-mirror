#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vrv32.h"
#include "verilated_vcd_c.h"
#include "Vrv32__Dpi.h"
#include "svdpi.h"
#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "Vrv32___024root.h"


VerilatedVcdC* tfp = new VerilatedVcdC(); //创建VCD波形导出对象
Vrv32 *top = new Vrv32("top");
vluint64_t main_time = 0;  //仿真时间计数器

/********extern functions or variables********/
extern char *diff_so_file;
extern int  difftest_port;
extern long img_size;
extern NPCState npc_state;
extern void   init_monitor(int, char *[]);
extern void   sdb_mainloop() ;
extern int    is_exit_status_bad();
extern void   init_difftest(char *ref_so_file, long img_size, int port);
extern word_t pmem_r(paddr_t addr, int len); 
extern void   pmem_w(paddr_t addr, int len, word_t data);
extern void   ebreak(int station, int inst);                   // control_unit.v
extern int    pmem_read(int raddr);                            // mem.v
extern int    pmem_read_inst(int pc);
extern void   pmem_write(int waddr, int wdata, char wmask);    // mem.v
extern void   etrace(int inst);                                // control_unit.v
extern uint64_t get_time();
/*********************************************/

static uint32_t rtc_port_base[2] = {0, 0};
#define start_time 3

static const char *alu_names[17] = {
  "Unit_ALU", "Unit_MEM", "Unit_CU1", "Unit_CU2",
  "Unit_CU3", "Unit_CU4", "Unit_CU5", "Unit_CU6",
  "Unit_CU7", "Unit_CU8", "Unit_CU9", "Unit_CU10",
  "Unit_CU11","Unit_IE1", "Unit_IE2", "Unit_IE3",
  "Unit_CSR"
};

extern void ebreak(int station, int inst, char unit)
{
  if(Verilated::gotFinish())
    return;

  if(main_time >= start_time + 1)   // at the begining (main_time < start_time and before the reset), all regs are zeros
  {
    npc_state.halt_ret = top->rootp->rv32__DOT__register_file_inst__DOT__regs[10]; //a0
    npc_state.halt_pc = top->rootp->rv32__DOT__pc;

    assert( (unit == Unit_ALU) || (unit == Unit_CU1) || (unit == Unit_CU2) || (unit == Unit_CU3) || 
            (unit == Unit_CU4) || (unit == Unit_CU5) || (unit == Unit_CU6) || (unit == Unit_CU7) || 
            (unit == Unit_CU8) || (unit == Unit_CU9) || (unit == Unit_CU10)|| (unit == Unit_CU11)||
            (unit == Unit_MEM) || (unit == Unit_IE1) || (unit == Unit_IE2) || (unit == Unit_IE3) ||
            (unit == Unit_CSR) );

    Log("Ebreak takes place in the %s", alu_names[unit]);
    Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, top->rootp->rv32__DOT__pc, top->rootp->rv32__DOT__inst);

    switch(station)
    {
      case HIT_TRAP:
        npc_state.state = NPC_END;
        break;

      case ABORT:
      default:
        npc_state.state = NPC_ABORT;
        break;
    }

    Verilated::gotFinish(true);
  }
}

#define top_mstatus   top->rootp->rv32__DOT__csr_regs_inst__DOT__mstatus
#define top_mepc      top->rootp->rv32__DOT__csr_regs_inst__DOT__mepc
#define top_mcause    top->rootp->rv32__DOT__csr_regs_inst__DOT__mcause

extern void etrace(int inst)
{
  #ifdef CONFIG_ETRACE
  _Log(ANSI_FG_YELLOW "[etrace]" ANSI_NONE ANSI_FG_YELLOW "mstatus:" ANSI_NONE "0x%08x, "
       ANSI_FG_YELLOW "mepc:"    ANSI_NONE " 0x%08x, " ANSI_FG_YELLOW "mcause:" ANSI_NONE " 0x%08x\n", 
      top_mstatus, top_mepc, top_mcause);
  #endif 
  
}

extern int pmem_read(int raddr)
{
  static int data = 0xdeadbeaf;
  if(top->clk == 0)
    return data;

  if(main_time >= start_time)
  {
    // device rtc
    if((raddr == CONFIG_RTC_MMIO) || (raddr == CONFIG_RTC_MMIO + 4))
    {
      if(raddr == CONFIG_RTC_MMIO + 4)
      {
        uint64_t us = get_time();
        rtc_port_base[0] = (uint32_t)us;
        rtc_port_base[1] = us >> 32;
      }
      data = rtc_port_base[(raddr - CONFIG_RTC_MMIO) / 4];
    }
    else if (raddr == CONFIG_SERIAL_MMIO) {
      // 串口读取通常用于读取状态或输入数据，这里简单返回0
      data = 0;
      return data;
    }
    else
      data = pmem_r(raddr, 4);
    return data; 
  } 
  else
    return 0xdeadbeaf;
}


void pmem_write(int waddr, int wdata, char wmask)
{
  if(top->clk == 0)
    return;

  // device serial
  if(waddr == CONFIG_SERIAL_MMIO)
  {
    assert(wmask == WByte);
    char ch = (char)wdata;
    putchar(ch);
    return;
  }

  if((waddr == CONFIG_RTC_MMIO) || (waddr == CONFIG_RTC_MMIO + 4))
    {
      return;
    }

  switch (wmask)
  {
    case WByte: pmem_w(waddr, 1, wdata);
                break;
    case WHalf: pmem_w(waddr, 2, wdata);
                break;
    case WWord: pmem_w(waddr, 4, wdata);
                break;
    default:    assert(0);
                break;
  }
}


void single_cycle(void) 
{
  if(!Verilated::gotFinish())
  { 
    top->clk = 0; top->eval(); tfp->dump(main_time);  main_time++; //推动仿真时间
    top->clk = 1; top->eval(); tfp->dump(main_time);  main_time++; 
  }
}

static void reset(void)
{
  top->rst = 0; single_cycle();
  top->rst = 1; single_cycle();
  top->rst = 0; 
}

static void init_verilator(void)
{
  Verilated::traceEverOn(true); //导出vcd波形需要加此语句

  top->trace(tfp, 0);
  tfp->open("wavefor.vcd"); //打开vcd

  reset();  //复位
}

int main(int argc, char *argv[])
{
  /* Initialize the monitor. */
  init_monitor(argc, argv);

  /* Make stdout unbuffered so serial characters are printed immediately. */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* Initialize the verilator. */
  init_verilator();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Receive commands from user. */
  sdb_mainloop();

  /* End the simulation */
  top->final();
  tfp->close();
  delete top;

  return is_exit_status_bad();
}

