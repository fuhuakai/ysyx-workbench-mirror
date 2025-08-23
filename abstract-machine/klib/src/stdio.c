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

// 辅助函数：将数字格式化为指定宽度和填充字符
static size_t format_number(int n, char *buf, int base, int width, char pad) {
  size_t len = itoa(n, buf, base);
  
  // 如果需要填充且当前长度小于指定宽度
  if (width > 0 && len < width) {
    // 计算需要填充的字符数
    int pad_count = width - len;
    
    // 将现有内容向右移动
    for (int i = len; i >= 0; i--) {
      buf[i + pad_count] = buf[i];
    }
    
    // 在前面添加填充字符
    for (int i = 0; i < pad_count; i++) {
      buf[i] = pad;
    }
    
    len += pad_count;
  }
  
  return len;
}

// 解析格式说明符中的宽度和填充选项
static int parse_format(const char **fmt_ptr, int *width, char *pad) {
  const char *fmt = *fmt_ptr;
  *width = 0;
  *pad = ' ';
  
  // 检查填充字符（0 或空格）
  if (*fmt == '0') {
    *pad = '0';
    fmt++;
  }
  
  // 解析宽度数字
  while (*fmt >= '0' && *fmt <= '9') {
    *width = *width * 10 + (*fmt - '0');
    fmt++;
  }
  
  *fmt_ptr = fmt;
  return *fmt; // 返回格式字符
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
    
    // 解析格式说明符
    int width = 0;
    char pad = ' ';
    char format_char = parse_format(&fmt, &width, &pad);
    
    switch (format_char) {
      case '%':
        *out++ = '%';
        break;
        
      case 'd': {
        int n = va_arg(ap, int);
        out += format_number(n, out, 10, width, pad);
        break;
      }
        
      case 's': {
        const char *str = va_arg(ap, const char *);
        // 处理字符串宽度（右对齐，左侧填充空格）
        int len = 0;
        const char *p = str;
        while (*p++) len++;
        
        if (width > 0 && len < width) {
          for (int i = 0; i < width - len; i++) {
            *out++ = ' ';
          }
        }
        
        while (*str) *out++ = *str++;
        break;
      }
        
      case 'c': {
        int ch = va_arg(ap, int);
        *out++ = (char)ch;
        break;
      }
        
      default:
        // 输出未知格式说明符
        *out++ = '%';
        *out++ = format_char;
    }
  }
  
  *out = '\0';
  return out - start;
}

int printf(const char *fmt, ...) {
  char buf[256];
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buf, fmt, args);
  va_end(args);
  
  for (int i = 0; i < len; i++) {
    putch(buf[i]);
  }
  
  return len;
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
