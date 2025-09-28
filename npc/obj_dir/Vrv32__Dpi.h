// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VRV32__DPI_H_
#define VERILATED_VRV32__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/fuhuakai/ysyx-workbench/npc/vsrc/idu.v:43:34
    extern void TRAP(int station, char unit);
    // DPI import at /home/fuhuakai/ysyx-workbench/npc/vsrc/lsu.v:316:34
    extern int dmem_read(int raddr);
    // DPI import at /home/fuhuakai/ysyx-workbench/npc/vsrc/ifu.v:19:34
    extern int imem_read(int raddr);
    // DPI import at /home/fuhuakai/ysyx-workbench/npc/vsrc/lsu.v:317:34
    extern void pmem_write(int waddr, int wdata, char wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
