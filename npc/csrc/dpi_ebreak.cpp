#include <iostream>
#include <svdpi.h>

extern "C" void ebreak() {
    std::cout << "DPI-C: EBREAK instruction executed, stopping simulation" << std::endl;
}