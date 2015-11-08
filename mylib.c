//
// Created by Mark on 11/7/2015.
//

#define REG_DISPCNT *(unsigned short*) 0x4000000

#define SCANLINECOUNTER *(volatile unsigned short*) 0x4000006
#define MEM_VRAM    0x06000000
#define VRAM_PAGE_SIZE    0x0A000
#define MEM_VRAM_BACK    (MEM_VRAM+ VRAM_PAGE_SIZE)
#define vid_mem            ((COLOR*)MEM_VRAM)
#define vid_mem_front    ((COLOR*)MEM_VRAM)
#define vid_mem_back    ((COLOR*)MEM_VRAM_BACK)
#define DCNT_PAGE            0x0010
unsigned short *videoBuffer = (unsigned short *) 0x6000000;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef u16 COLOR;

COLOR *vid_page = vid_mem_back;

u16 *vid_flip() {
    // toggle the write_buffer's page
    vid_page = (u16 *) ((u32) vid_page ^ VRAM_PAGE_SIZE);
    REG_DISPCNT ^= DCNT_PAGE;            // update control register
    return vid_page;
}

void waitForVBlank() {
    while (SCANLINECOUNTER > 160);
    while (SCANLINECOUNTER < 160);
}

void drawPixel4(int x, int y, u8 clrid) {
    u16 *dst = &vid_page[(y * 240 + x) / 2];  // Division by 2 due to u8/u16 pointer mismatch!
    if (x & 1)
        *dst = (*dst & 0xFF) | (clrid << 8);    // odd pixel
    else
        *dst = (*dst & ~0xFF) | clrid;        // even pixel
}

void drawRect4(int left, int top, int right, int bottom, COLOR clr) {
    int ix, iy;
    for (iy = top; iy < bottom; iy++)
        for (ix = left; ix < right; ix++)
            drawPixel4(ix, iy, clr);
}
