/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;//优雅的退出
  return -1;
}

static int cmd_help(char *args);

//单步执行
static int cmd_si(char *args){
	char *step_arg = strtok(NULL, " ");
	int step_count = 1;
	if (step_arg == NULL){
		cpu_exec(1);
		return 0;
	}
	//确认输入参数格式正确
	if (sscanf(step_arg, "%d", &step_count) != 1){
		fprintf(stderr, "ERROR:Invalid step count format\n");
		return 0;
	}
	//确认步数为正
	if (step_count <= 0){
		fprintf(stderr, "ERROR: Step count must be positive (got %d)\n", step_count);
		return 0;
	}

	for(int i =0; i< step_count; i++){
		cpu_exec(1);
	}
	return 0;
}
//打印寄存器
static int cmd_info(char *args) {
    char *subcommand = strtok(NULL, " ");
    
    // 检查子命令r是否存在
    if (subcommand == NULL) {
        fprintf(stderr, "ERROR: Missing subcommand. Usage: info [r|...]\n");
        return 1;
    }
    
    // 处理寄存器显示命令
    if (strcmp(subcommand, "r") == 0) {
        isa_reg_display();  // 调用寄存器显示函数，位于/isa/reg.c
        return 0;
    }
    
    // 处理无效子命令
    fprintf(stderr, "ERROR: Invalid subcommand '%s'. Supported: r\n", subcommand);
    return 1;
}

//扫描内存
static int cmd_x(char *args) {
    //解析输入命令参数
	char *step_str = strtok(NULL, " ");
    char *addr_str = strtok(NULL, " ");

    //确认输入参数格式正确
	if (!step_str || !addr_str) {
        printf("Usage error: x [steps] [hex address]\n");
        printf("Example: x 10 0x80000000\n");
        return -1;
    }

    int step = 0;
    paddr_t address = 0;

    //确认扫描步长
	if (sscanf(step_str, "%d", &step) != 1) {
        printf("Invalid step value: '%s'\n", step_str);
        return -1;
    }
	//确认起始地址
    if (sscanf(addr_str, "%x", &address) != 1) {
        printf("Invalid address: '%s'\n", addr_str);
        return -1;
    }
    //扫描内存
	for (int i = 0; i < step; i++) {
        printf("0x%08x: 0x%08x\n", address, paddr_read(address, 4));
        address += 4;
    }
    return 0;
}

//表达式求值
static int cmd_p(char *args){
    bool success = false; 
    word_t result = expr(args, &success); // 传递变量的地址
    
    if (success) {
        // 同时显示十六进制和十进制值
        printf("0x%08x (%d)\n", result, result);
    } else {
        printf("Expression evaluation failed.\n");
    }
    return 0;
}


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single Step Execution", cmd_si},
  { "info", "Display all informations of regisiters", cmd_info },
  { "x", "Scan The Memory", cmd_x },
  { "p", "Evaluate The Expressions", cmd_p },

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
