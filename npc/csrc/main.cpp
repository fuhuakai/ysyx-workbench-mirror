#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h" // 由Verilator生成的头文件

#include <iostream>
#include <vector>

// 指令存储器
std::vector<uint32_t> imem;
const uint32_t PC_START = 0x80000000;

// 从指令存储器读取指令
uint32_t pmem_read(uint32_t addr) {
    uint32_t index = (addr - PC_START) / 4;
    if (index < imem.size()) {
        return imem[index];
    }
    std::cerr << "Error: Instruction fetch out of bounds! Addr: 0x" 
              << std::hex << addr << std::endl;
    return 0;
}

int main(int argc, char** argv) {
    // 初始化Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    
    // 创建顶层模块实例
    Vtop top;
    
    // 创建波形文件
    VerilatedVcdC waveFst;
    top.trace(&waveFst, 99);
    waveFst.open("wave.fst");
    
    // 初始化指令存储器
    // 示例程序:
    //   addi x1, x0, 1   -> 0x00100093
    //   addi x2, x1, 2   -> 0x00208113
    //   ebreak           -> 0x00100073
    imem.push_back(0x00100093);
    imem.push_back(0x00208113);
    imem.push_back(0x00100073);
    
    // 复位处理
    top.rst = 1;
    top.clk = 0;
    top.eval();
    waveFst.dump(0);
    
    top.clk = 1;
    top.eval();
    waveFst.dump(1);
    
    top.clk = 0;
    top.rst = 0;
    top.eval();
    waveFst.dump(2);
    
    std::cout << "Simulation started" << std::endl;
    
    // 主仿真循环
    int cycle = 0;
    const int MAX_CYCLES = 10;
    bool ebreak_triggered = false;
    
    while (cycle < MAX_CYCLES && !ebreak_triggered) {
        // 时钟低电平
        top.clk = 0;
        
        // 读取指令
        top.inst = pmem_read(top.pc);
        
        // 评估设计
        top.eval();
        waveFst.dump(cycle * 2 + 2);
        
        // 时钟高电平
        top.clk = 1;
        top.eval();
        waveFst.dump(cycle * 2 + 3);
        
        // 检查ebreak
        if (top.trap) {
            std::cout << "EBREAK detected at cycle " << cycle << std::endl;
            ebreak_triggered = true;
        }
        
        std::cout << "Cycle " << cycle << ": PC=0x" 
          << std::setw(8) << std::setfill('0') << std::hex << top.pc 
          << ", inst=0x" << std::setw(8) << std::setfill('0') << top.inst 
          << std::endl;
        
        cycle++;
    }
    
    // 关闭波形文件
    waveFst.close();
    
    if (ebreak_triggered) {
        std::cout << "Simulation stopped by EBREAK after " << cycle << " cycles" << std::endl;
    } else {
        std::cout << "Simulation stopped after " << MAX_CYCLES << " cycles" << std::endl;
    }
    
    return 0;
}