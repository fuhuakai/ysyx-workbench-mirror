#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"

// 监视点池大小
#define NR_WP 32

// 表达式最大长度
#define MAX_EXPR_LEN 128

// 监视点结构体
typedef struct watchpoint {
  int NO;                   // 监视点唯一ID
  struct watchpoint *next;  // 链表指针

  char expr[MAX_EXPR_LEN];  // 表达式字符串
  word_t value;             // 表达式当前值
} WP;

// 初始化监视点池
void init_wp_pool(void);

// 分配一个新监视点
WP *new_wp(void);

// 释放监视点
void free_wp(WP *wp);

// 检查所有监视点是否触发
bool checkWP(void);

// 设置新监视点
void set_watchpoint(const char *expr);

// 打印所有活动监视点信息
void print_wp(void);

// 根据ID查找监视点
WP* delete_wp(int p, bool *key);

#endif
