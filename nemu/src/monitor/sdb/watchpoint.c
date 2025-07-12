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

#include "sdb.h"

#define NR_WP 32
#define MAX_EXPR_LEN 128

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

  char expr[MAX_EXPR_LEN];  // 表达式字符串
  word_t value;             // 表达式对应的值
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
//分配新监视点
WP* new_wp() {
  if (free_ == NULL) {
    // 没有空闲监视点时终止程序
    assert(0);
  }

  // 从空闲链表头部取出一个节点
  WP *new = free_;
  free_ = free_->next;

  // 将新节点插入到使用链表尾部
  if (head == NULL) {
    head = new;
  } else {
    WP *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new;
  }
  new->next = NULL;

  return new;
}

//释放监视点
void free_wp(WP *wp) {
  if (wp == NULL) {
    assert(0); 
  }
  // 从使用链表中移除
  if (head == wp) {
    // 情况1：要释放的是链表头节点
    head = head->next;
  } else {
    // 情况2：要释放的是中间或尾部节点
    WP *prev = head;
    // 遍历查找wp的前一个节点
    while (prev != NULL && prev->next != wp) {
      prev = prev->next;
    }
    if (prev != NULL) {
      // 跳过wp节点
      prev->next = wp->next;
    }
  } 
  // 将节点插入空闲链表头部
  wp->next = free_;  // wp指向当前空闲链表头
  free_ = wp;        // 空闲链表头指向wp
}

//检查所有监视点是否触发以及值是否变化
bool checkWP() {
    bool triggered = false;  // 是否有监视点被触发
    WP *temp = head;         // 从监视点链表头开始
    
    while (temp != NULL) {
        bool success = false;
        // 重新计算监视点表达式的值
        word_t new_value = expr(temp->expr, &success);
        
        if (!success) {
            // 表达式求值失败，跳过此监视点
            temp = temp->next;
            continue;
        }
        
        if (new_value != temp->value) {
            // 值发生变化：触发监视点
            triggered = true;
            
            // 打印详细信息
            printf("Watchpoint %d: %s\n", temp->NO, temp->expr);
            printf("Old value = %d (0x%08x)\n", temp->value, temp->value);
            printf("New value = %d (0x%08x)\n", new_value, new_value);
           // printf("Triggered at address 0x%08x\n", cpu.eip);
            
            // 更新监视点的值为新值
            temp->value = new_value;
        }
        
        // 移动到下一个监视点
        temp = temp->next;
    }
    
    return triggered;
}

//设置新的监视点
void set_watchpoint(const char *expression){
	//检查表达式是否为空
	if(expression == NULL){
		printf("Error: Empty expression\n");
		return;
	}

	//分配新的监视点
	WP *wp = new_wp();
	if (wp == NULL){
		printf("Error: No free watchpoint available\n");
		return;
	}

	// 复制表达式到监视点结构
    strncpy(wp->expr, expression, MAX_EXPR_LEN - 1);
    wp->expr[MAX_EXPR_LEN - 1] = '\0'; // 确保字符串终止
    
    // 计算表达式初始值
    bool success = false;
    wp->value = expr(wp->expr, &success);
    
    if (!success) {
        // 表达式求值失败
        printf("Error: Failed to evaluate expression '%s'\n", expression);
        free_wp(wp); // 释放监视点
        return;
    }
    
    // 打印设置的监视点
    printf("Watchpoint %d set: %s = %d (0x%08x)\n", 
           wp->NO, wp->expr, wp->value, wp->value);
}	

//打印监视点信息
void print_wp() {
    if (head == NULL) {
        printf("No watchpoints defined.\n");
        return;
    }

    printf("%-8s %-30s %s\n", "ID", "Expression", "Current Value");

    WP *temp = head;
    while (temp != NULL) {
        printf("%-8d %-30s %d (0x%x)\n",
               temp->NO, temp->expr, temp->value, temp->value);
        temp = temp->next;
    }
}

//删除监视点（只用于查找需要删除的监视点，删除的执行操作仍位于sdb.c中）
WP* delete_wp(int p, bool *key){
    WP *temp = head;

    // 查找匹配ID的监视点
    while (temp != NULL && temp->NO != p){
        temp = temp->next;
    }

    if (temp == NULL){
        *key = false;  // 未找到
    }

    return temp;  // 返回找到的监视点或NULL
}


