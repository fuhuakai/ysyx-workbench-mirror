#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

//读取屏幕宽度和高度
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t width_height = inl(VGACTL_ADDR);
  uint32_t height = width_height & 0xffff;
  uint32_t width = width_height >> 16;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
}

//写入绘图信息
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t width_height = inl(VGACTL_ADDR);
  int vga_w = width_height >> 16;
  int vga_h = width_height & 0xffff;

  int x = ctl->x, y = ctl->y;
  int w = ctl->w, h = ctl->h;
  uint32_t* pixels = ctl->pixels;
  uint32_t *fb = (uint32_t*)(uintptr_t)FB_ADDR;

  for (int i = 0; i < h; i++) {
    int row = y + i;
    if (row >= vga_h) {
      break;
    }
    for (int j = 0; j < w; j++) {
      int col = x + j;
      if (col >= vga_w) {
        break;
      }
      fb[row * vga_w + col] = pixels[i*w + j];
    }
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
