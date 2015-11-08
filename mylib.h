//
// Created by Mark on 11/8/2015.
//

#ifndef HW10_MYLIB_H
#define HW10_MYLIB_H

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
#endif //HW10_MYLIB_H
