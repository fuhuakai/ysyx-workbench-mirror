#all:\
#	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

#include ../Makefile

TARGET = npc_sim
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --trace -cc --exe -I./vsrc -Wno-DECLFILENAME
VERILATOR_INCLUDE = -I./vsrc
VSRC = vsrc/top.v vsrc/idu.v vsrc/exu.v vsrc/regs.v vsrc/template.v
CSRC = csrc/main.cpp csrc/dpi_ebreak.cpp

all: $(TARGET)

$(TARGET): $(VSRC) $(CSRC)
	@mkdir -p build
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDE) \
		$(VSRC) $(CSRC) --top-module top -o ../build/$(TARGET)
	@make -C obj_dir -f Vtop.mk

run: build/$(TARGET)
	@./build/$(TARGET)

wave:
	gtkwave wave.vcd &

clean:
	rm -rf build obj_dir wave.vcd

.PHONY: all run wave clean