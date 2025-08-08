#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 反转字符串
static void reverse(char *s, size_t len) {
  if (len <= 1) return;
  
  char *start = s;
  char *end = s + len - 1;
  
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

// 整数转字符串（支持2-16进制）
static size_t itoa(int n, char *buf, int base) {
  assert(base >= 2 && base <= 16);
  
  size_t index = 0;
  unsigned num = (n < 0) ? (unsigned)-n : (unsigned)n;
  
  // 处理0的特殊情况
  if (num == 0) {
    buf[index++] = '0';
  } else {
    // 转换数字（逆序）
    while (num > 0) {
      unsigned digit = num % base;
      buf[index++] = (digit < 10) 
        ? ('0' + digit) 
        : ('a' + digit - 10);
      num /= base;
    }
  }
  
  // 添加符号
  if (n < 0) {
    buf[index++] = '-';
  }
  
  // 终止字符串
  buf[index] = '\0';
  
  // 反转得到正确顺序
  reverse(buf, index);
  
  return index; // 返回字符数（不包括终止符）
}

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *start = out; // 记录起始位置
  
  while (*fmt) {
    // 普通字符直接复制
    if (*fmt != '%') {
      *out++ = *fmt++;
      continue;
    }
    
    // 处理格式说明符
    fmt++; // 跳过 '%'
    if (!*fmt) break; // 格式字符串以%结束
    
    switch (*fmt++) {
      case '%': // 转义%
        *out++ = '%';
        break;
        
      case 'd': // 整数
        out += itoa(va_arg(args, int), out, 10);
        break;
        
      case 's': { // 字符串
        const char *str = va_arg(args, const char *);
        while (*str) *out++ = *str++;
        break;
      }
        
      default: // 未知格式说明符
        *out++ = '%';
        *out++ = *(fmt - 1);
    }
  }
  
  // 终止字符串
  *out = '\0';
  
  va_end(args);
  return out - start; // 返回写入字符数
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
