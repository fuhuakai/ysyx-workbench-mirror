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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, 
  TK_NUM,           // 十进制数字
  TK_REG,           // 寄存器
  TK_HEX,           // 十六进制数
  TK_EQ,            // 相等比较 ==
  TK_NEQ,           // 不等比较 !=
  TK_OR,            // 逻辑或 ||
  TK_AND,           // 逻辑与 &&
  TK_DEREF,         // 解引用 * 
  TK_NEG            // 负号 - (用于一元操作)

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

    {"==", TK_EQ},       // 相等比较
    {"!=", TK_NEQ},      // 不等比较
    {"\\|\\|", TK_OR},   // 逻辑或
    {"&&", TK_AND},      // 逻辑与
    
    {"\\+", '+'},        // 加号
    {"\\-", '-'},        // 减号
    {"\\*", '*'},        // 乘号
    {"\\/", '/'},        // 除号
    {"\\(", '('},        // 左括号
    {"\\)", ')'},        // 右括号
    {"!", '!'},          // 逻辑非
    
    // 标识符和字面量
    {"\\$[a-zA-Z0-9]+", TK_REG},   // 寄存器（如 $eax）
    {"0[xX][0-9a-fA-F]+", TK_HEX}, // 十六进制数
    {"[0-9]+", TK_NUM},            // 十进制数
    
    {" +", TK_NOTYPE}    // 空格
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
            case TK_NOTYPE: // 空格 - 跳过不处理
                 break;
                        
            case TK_NUM:
            case TK_HEX:
            case TK_REG:
                // 复制字符串值
                tokens[nr_token].type = rules[i].token_type;
                strncpy(tokens[nr_token].str, substr_start, substr_len);
                tokens[nr_token].str[substr_len] = '\0'; // 确保终止符
                nr_token++;
                break;
                        
            case TK_EQ:
            case TK_NEQ:
            case TK_OR:
            case TK_AND:
                // 多字符操作符 - 直接设置类型
                tokens[nr_token].type = rules[i].token_type;
                nr_token++;
                break;
                        
            default: // 单字符操作符 (+, -, *, /, (, ), !)
                tokens[nr_token].type = rules[i].token_type;
                nr_token++;
		  }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  Log("Lexical analysis completed. Tokens: %d", nr_token);//添加调试信息
  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  TODO();

  return 0;
}
