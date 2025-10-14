#include <am.h>
#include "../riscv.h"

#define RTC_ADDR 0xa0000048

void __am_timer_init() {
  outl(RTC_ADDR , 0);//inl和outl是读写端口的函数，位于am/src/$ISA/$ISA.h
  outl(RTC_ADDR + 4 , 0);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = inl(RTC_ADDR + 4);
  uptime->us <<= 32;
  uptime->us += inl(RTC_ADDR);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
