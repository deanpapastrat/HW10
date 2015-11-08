//
// Created by Mark on 11/8/2015.
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

u16 *vid_flip();
void drawImage4(int x, int y, int sourcex, int sourcey, int width, int height, const unsigned short *image);
void drawSprite4(int x, int y, int sourcex, int sourcey, int width, int height, u8 colorkey, const unsigned short *image);
void drawPixel4(int x, int y, u8 clrid);
void drawRect4(int left, int top, int right, int bottom, COLOR clr);
void fillScreen4(COLOR clr);