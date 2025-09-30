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


Vrv32         *top = new Vrv32("top");
VerilatedVcdC *tfp = new VerilatedVcdC(); //导出vcd波形需要加此语句
vluint64_t    main_time = 0;  //initial 仿真时间



/********extern functions or variables********/
extern char     *diff_so_file;
extern int      difftest_port;
extern long     img_size;
extern NPCState npc_state;

extern void   sdb_mainloop() ;
extern void   init_monitor(int, char *[]);
extern int    is_exit_status_bad();
extern void   init_difftest(char *ref_so_file, long img_size, int port);
extern word_t pmem_r(paddr_t addr, int len); 
extern void   pmem_w(paddr_t addr, int len, word_t data);
extern void   TRAP(int station, char unit);             
extern int    imem_read(int raddr);                 
extern int    dmem_read(int raddr);                  
extern void   pmem_write(int waddr, int wdata, char wmask);    
// extern void   etrace(int inst);                                     
extern uint64_t get_time();                               
/*********************************************/

static uint32_t rtc_port_base[2] = {0, 0};
static const char *unit_names[14] = {
  "Unit_IDU1", "Unit_IDU2", "Unit_IDU3", "Unit_IDU4",
  "Unit_IDU5", "Unit_IDU6", "Unit_IDU7", "Unit_IDU8", 
  "Unit_IDU9", "Unit_EXU1", "Unit_LSU1", "Unit_LSU2",
  "Unit_CC1 ", "Unit_CC2"
};

#define start_time 3
extern void TRAP(int station, char unit)
{
  if(Verilated::gotFinish())
    return;

  // at the begining (main_time < start_time and before the reset), all gprs are zeros
  if(main_time >= start_time + 1)   
  {
    npc_state.halt_ret = top->rootp->rv32__DOT__register_file_inst__DOT__regs[10]; //a0
    npc_state.halt_pc = top->rootp->rv32__DOT__bru_inst__DOT__npc_reg;

    assert( (unit == Unit_IDU1) || (unit == Unit_IDU2) || (unit == Unit_IDU3) || (unit == Unit_IDU4) || 
            (unit == Unit_IDU5) || (unit == Unit_IDU6) || (unit == Unit_IDU7) || (unit == Unit_IDU8) ||
            (unit == Unit_IDU9) || (unit == Unit_EXU1) || (unit == Unit_LSU1) || (unit == Unit_LSU2) ||
            (unit == Unit_CC1)  || (unit == Unit_CC2));

    Log("TRAP takes place in the %s", unit_names[unit]);
    Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, 
         top->rootp->rv32__DOT__bru_inst__DOT__npc_reg, top->rootp->rv32__DOT__ifu_inst__DOT__ifu_inst);

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



extern int imem_read(int raddr)
{
  static int data = 0xdead0009;
  // Log("clk1 = %d,  addr = 0x%08x,    %ld",top->clk, raddr, main_time);

  if(main_time < start_time)
    return data;

  data = pmem_r(raddr, 4);

  return data;    
}

extern int dmem_read(int raddr)
{
  static int data;

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
  else
    data = pmem_r(raddr, 4);
  return data;   
}

void pmem_write(int waddr, int wdata, char wmask)
{
  // 因为是是周期CPU，所以理论上来说应该轮到LSU工作的时候才读/写dmem
  if(main_time < start_time || top->rootp->rv32__DOT__clk_cnt != 3)
    return;

  // device serial
  if(waddr == CONFIG_SERIAL_MMIO)
  {
    assert(wmask == WByte);
    char ch = (char)wdata;
    putchar(ch);
    return;
  }

  // memory
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
    top->clk = 0; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);
    tfp->flush();  
#endif
    main_time++; //推动仿真时间

    top->clk = 1; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time); 
    tfp->flush(); 
#endif
    main_time++; //推动仿真时间
  }
}

static void reset(void)
{
  top->rst = 0; single_cycle();
  top->rst = 1; single_cycle();
  top->rst = 0; single_cycle();
}

static void init_verilator(void)
{
  Verilated::traceEverOn(true); //导出vcd波形需要加此语句

  top->trace(tfp, 0);
  tfp->open("waveform.vcd"); //打开vcd

  reset();  //复位
}

void close_tfp(void)
{
  tfp->close();
}

int main(int argc, char *argv[])
{
  /* Initialize the monitor. */
  init_monitor(argc, argv);

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


