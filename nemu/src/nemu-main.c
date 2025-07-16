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

#include <common.h>
#include "monitor/sdb/sdb.h"

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();



// 表达式测试函数
void run_expr_tests() {
    const char *test_file = "src/input";
    FILE *fp = fopen(test_file, "r");
    if (!fp) {
        printf("Test file not found: %s\n", test_file);
        return;
    }
    
    char line[1024];
    int total = 0, passed = 0;
    
    printf("Starting expression tests...\n");
    
    while (fgets(line, sizeof(line), fp)) {
        // 解析测试用例：<预期结果> <表达式>
        char *space = strchr(line, ' ');
        if (!space) continue;
        
        *space = '\0';  // 分隔结果和表达式
        unsigned expected = atoi(line);
        char *expr_str = space + 1;
        
        // 移除表达式末尾的换行符
        char *newline = strchr(expr_str, '\n');
        if (newline) *newline = '\0';
        
        // 执行表达式求值
        bool success;
        word_t result = expr(expr_str, &success);
        
        // 验证结果
        if (!success) {
            printf("[FAIL] %s\n", expr_str);
            printf("  Error: Evaluation failed\n");
        } else if (result != expected) {
            printf("[FAIL] %s\n", expr_str);
            printf("  Expected: %u, Got: %u\n", expected, result);
        } else {
            passed++;
        }
        total++;
    }
    
    fclose(fp);
    
    printf("\nExpression Test Summary:\n");
    printf("  Total: %d, Passed: %d, Failed: %d\n", 
           total, passed, total - passed);
    printf("  Pass Rate: %.2f%%\n", (float)passed/total*100);
}



int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

/* 在启动引擎前自动运行表达式测试 */
  run_expr_tests();

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
