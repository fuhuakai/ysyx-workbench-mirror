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
  
  if (num == 0) {
    buf[index++] = '0';
  } else {
    while (num > 0) {
      unsigned digit = num % base;
      buf[index++] = (digit < 10) 
        ? ('0' + digit) 
        : ('a' + digit - 10);
      num /= base;
    }
  }
  
  if (n < 0) {
    buf[index++] = '-';
  }
  
  // 终止字符串
  buf[index] = '\0';
  
  // 反转得到正确顺序(1234->4321->1234)
  reverse(buf, index);
  
  return index;
}

int printf(const char *fmt, ...) {
  char buf[256]; 
  va_list args;
  va_start(args, fmt);
  
  // 使用 vsprintf 格式化字符串到缓冲区
  int len = vsprintf(buf, fmt, args);
  va_end(args);
  
  // 逐个字符输出
  for (int i = 0; i < len; i++) {
    putch(buf[i]);
  }
  
  return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *start = out;
  
  while (*fmt) {
    if (*fmt != '%') {
      *out++ = *fmt++;
      continue;
    }
    
    fmt++;
    if (!*fmt) break;
    
    switch (*fmt++) {
      case '%':
        *out++ = '%';
        break;
        
      case 'd': {
        int n = va_arg(ap, int);
        out += itoa(n, out, 10);
        break;
      }
        
      case 's': {
        const char *str = va_arg(ap, const char *);
        while (*str) *out++ = *str++;
        break;
      }
      
      case 'c': {
        int ch = va_arg(ap, int);
        *out++ = ch;
        break;
      }

      default:
        *out++ = '%';
        *out++ = *(fmt );
    }
  }
  
  *out = '\0';
  return out - start;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *start = out;
  
  while (*fmt) {
    if (*fmt != '%') {
      *out++ = *fmt++;// 普通字符直接复制
      continue;
    }
    
    fmt++; 
    if (!*fmt) break; // 如果%后面没有字符，直接退出
    
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
        
      default: 
        *out++ = '%';
        *out++ = *(fmt - 1); // 未知格式符，保留原样
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
