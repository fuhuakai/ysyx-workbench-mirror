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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 当前缓冲区位置
static char *buf_ptr = buf;

// 生成随机数字 (0-999)
static char *gen_num(char *ptr) {
    int num = rand() % 1000;
    return ptr + sprintf(ptr, "%d", num);
}

// 生成随机运算符
static char *gen_op(char *ptr) {
    const char ops[] = {'+', '-', '*', '/'};
    *ptr++ = ops[rand() % 4];
    return ptr;
}


// 递归生成随机表达式
static char *gen_expr(char *ptr, int depth) {
    if (depth > 3) {  // 限制递归深度
        return gen_num(ptr);
    }

    switch (rand() % 3) {
        case 0: // 单个数字
            return gen_num(ptr);
            
        case 1: { // 括号表达式
            *ptr++ = '(';
            ptr = gen_expr(ptr, depth + 1);
            *ptr++ = ')';
            return ptr;
        }
            
        default: { // 二元运算表达式
            ptr = gen_expr(ptr, depth + 1);
            ptr = gen_op(ptr);
            return gen_expr(ptr, depth + 1);
        }
    }
}

// 生成随机表达式入口
static void gen_rand_expr() {
    buf_ptr = buf;
    buf_ptr = gen_expr(buf_ptr, 0);
    *buf_ptr = '\0';
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    
    for (int i = 0; i < loop; i++) {
        gen_rand_expr();
        
        sprintf(code_buf, code_format, buf);
        
        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);
        
        int ret = system("gcc /tmp/.code.c -o /tmp/.expr 2>/dev/null");
        if (ret != 0) continue;  // 跳过编译失败的表达式
        
        fp = popen("/tmp/.expr", "r");
        if (fp == NULL) continue;
        
        unsigned result;
        if (fscanf(fp, "%u", &result) != 1) {
            pclose(fp);
            continue;  // 跳过执行失败的表达式
        }
        pclose(fp);
        
        printf("%u %s\n", result, buf);
    }
    return 0;
}
 
