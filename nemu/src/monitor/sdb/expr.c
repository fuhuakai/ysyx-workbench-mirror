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
#include <memory/paddr.h>

enum {
  //添加更多的token类型
  TK_NOTYPE = 256, 
  TK_NUM,           // 十进制数字
  TK_REG,           // 寄存器
  TK_HEX,           // 十六进制数
  TK_EQ,            // 相等比较 ==
  TK_NEQ,           // 不等比较 !=
  TK_OR,            // 逻辑或 ||
  TK_AND,           // 逻辑与 &&
  TK_NEG,           // 负号 - (用于一元操作)
  TK_DEREF          // 指针解引用 
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
	//为添加的各种token类型添加规则
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
    {"\\$[a-zA-Z0-9]+", TK_REG},   // 寄存器（如 $t0）
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
		//识别token并将token的信息记录到tokens数组中
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
                        
            default: // 单字符操作符 (+, -, *, /, (, ), !)(注！！：需要区分指针解引用和乘法）
			    if (rules[i].token_type == '*') {
                    // 检查是否为解引用（一元操作符） 1. 位于表达式开头 2. 前面是运算符 3. 前面是左括号
                    if (nr_token == 0 || 
                        tokens[nr_token-1].type == '(' ||
                        tokens[nr_token-1].type == '+' ||
                        tokens[nr_token-1].type == '-' ||
                        tokens[nr_token-1].type == '*' ||
                        tokens[nr_token-1].type == '/' ||
                        tokens[nr_token-1].type == TK_EQ ||
                        tokens[nr_token-1].type == TK_NEQ ||
                        tokens[nr_token-1].type == TK_OR ||
                        tokens[nr_token-1].type == TK_AND ||
                        tokens[nr_token-1].type == '!') {
                        tokens[nr_token].type = TK_DEREF; // 标记为解引用
                    } else {
                        tokens[nr_token].type = '*'; // 标记为乘法
                    }
                } else {
                    tokens[nr_token].type = rules[i].token_type;
                }
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


// 检查括号是否匹配
bool check_parentheses(int p, int q) {
    // 如果首尾不是括号，直接返回false
    if (tokens[p].type != '(' || tokens[q].type != ')') {
        return false;
    }
    
    int depth = 0;  // 括号计数器
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') {
            depth++;
        } else if (tokens[i].type == ')') {
            depth--;
            // 在到达结尾前括号计数器变为0，说明括号不匹配
            if (depth == 0 && i != q) {
                return false;
            }
        }
    }
    // 最终深度应为0
    return (depth == 0);
}

// 查找主运算符（位置）
int dominant_operator(int p, int q) {
    int depth = 0;              // 括号深度
    int op_pos = -1;            // 主运算符位置
    int min_priority = 999;     // 最低优先级
    
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') {
            depth++;
            continue;
        } else if (tokens[i].type == ')') {
            depth--;
            continue;
        }
        
        if (depth != 0) continue;
        
        int curr_priority = 999;
        
        // 确定当前操作符的优先级
        switch (tokens[i].type) {
            case TK_OR:   curr_priority = 1;   break;//或，优先级最低
            case TK_AND:  curr_priority = 2;  break;
            case TK_EQ:   
            case TK_NEQ:  curr_priority = 3;   break;// 相等和不相等优先级相同
            case '+':     
            case '-':     curr_priority = 4;  break;// 加减优先级相同
            case '*':     
            case '/':     curr_priority = 5;  break;// 乘除优先级相同
            case '!':    
            case TK_NEG:
			case TK_DEREF:curr_priority = 6; break;// 一元操作符优先级最高
        }
        
        // 找到优先级最低的操作符
		if (curr_priority < min_priority) {
            min_priority = curr_priority;
            op_pos = i;
        }
    }
    
    return op_pos;
}

/* TODO: Insert codes to evaluate the expression. */

// 表达式递归求值函数
uint32_t eval(int p, int q, bool *success) {
    // 边界检查
    if (p > q) {
        *success = false;
        printf("Invalid expression: p > q\n");
        return 0;
    }
    
    // 第一种情况： 单token表达式
    if (p == q) {
        switch (tokens[p].type) {
            case TK_NUM: {  // 十进制数
                uint32_t value;
                if (sscanf(tokens[p].str, "%u", &value) != 1) {
                    *success = false;
                    printf("Invalid number: %s\n", tokens[p].str);
                    return 0;
                }
                return value;
            }
                
            case TK_HEX: {  // 十六进制数
                uint32_t value;
                if (sscanf(tokens[p].str, "%x", &value) != 1) {
                    *success = false;
                    printf("Invalid hex number: %s\n", tokens[p].str);
                    return 0;
                }
                return value;
            }
                
            case TK_REG: {  // 寄存器
				const char *reg_name = tokens[p].str;
			    *success = true;    

				// RISC-V 32 寄存器名称表
				static const char *regs[] = {
					"$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
					"s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
					"a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
					"s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
				};
				const int num_regs = sizeof(regs) / sizeof(regs[0]);
				// 去掉寄存器名前面的 '$' (如 "$sp" -> "sp")
				const char *reg_base = reg_name + 1;    
				// 检查特殊寄存器 pc
				if (strcmp(reg_base, "pc") == 0) {
					return cpu.pc;
				}   
				// 在寄存器表中查找匹配项
				for (int i = 0; i < num_regs; i++) {
					if (strcmp(reg_base, regs[i]) == 0) {
				return cpu.gpr[i];
				}
			}
    
			// 未找到匹配的寄存器
			*success = false;
			printf("Unknown register: %s\n", reg_name);
			printf("Valid registers: pc");
			for (int i = 0; i < num_regs; i++) {
				printf(", $%s", regs[i]);
			}
			printf("\n");
		return 0;
        }        

            default:
                *success = false;
                printf("Unexpected token: %d\n", tokens[p].type);
                return 0;
        }
    }
    //第二种情况：(重要) 被括号包围的表达式，去掉括号重新进入递归计算
    else if (check_parentheses(p, q)) {
        return eval(p + 1, q - 1, success);
    }
    // 第三种情况： 一元操作符表达式
    else if (tokens[p].type == '!' || tokens[p].type == TK_NEG || tokens[p].type == TK_DEREF) {
        uint32_t val = eval(p + 1, q, success);
        if (!*success) return 0;
        
        switch (tokens[p].type) {
            case '!':     return !val;          // 逻辑非
            case TK_NEG:   return -val;         // 取负
			case TK_DEREF: return paddr_read(val, 4);
            default:      assert(0); return 0;
        }
    }
    //第四种情况： 二元操作符表达式
    else {
        int op_pos = dominant_operator(p, q);
        if (op_pos == -1) {
            *success = false;
            printf("No operator found in expression\n");
            return 0;
        }
        
        // 递归求值左操作数
        uint32_t val1 = eval(p, op_pos - 1, success);
        if (!*success) return 0;
        
        // 递归求值右操作数
        uint32_t val2 = eval(op_pos + 1, q, success);
        if (!*success) return 0;
        
        // 根据操作符类型计算结果
        switch (tokens[op_pos].type) {
            case '+':   return val1 + val2;
            case '-':   return val1 - val2;
            case '*':   return val1 * val2;
            case '/':   
                if (val2 == 0) {
                    *success = false;
                    printf("Division by zero\n");
                    return 0;
                }
                return val1 / val2;
                
            case TK_OR:  return val1 || val2;
            case TK_AND: return val1 && val2;
                
            case TK_EQ:   return val1 == val2;
            case TK_NEQ:  return val1 != val2;
                
            default:
                *success = false;
                printf("Unsupported operator: %d\n", tokens[op_pos].type);
                return 0;
        }
    }
}

// 表达式求值入口
word_t expr(char *e, bool *success) {
    *success = true;
    
    // 词法分析
    if (!make_token(e)) {
        *success = false;
        return 0;
    }
    
    //通过递归求值函数进行求值 
	return eval(0, nr_token - 1, success);
}
