//
// Created by Mark on 11/7/2015.
//

#include "main.h"
#include "assets/images.h"
#include <stdio.h>

//functions in mylib.c
void waitForVBlank();

void drawPixel4(int x, int y, u8 clrid);

void drawRect4(int left, int top, int right, int bottom, COLOR clr);

void drawImage4(int x, int y, int sourcex, int sourcey, int width, int height, const unsigned short *image);

u16 *vid_flip();

void initPalette();

//functions in text.c
void drawString(int row, int col, char *s, COLOR clr);

//global functions
int sprintf(char *str, const char *format, ...);

char lbuf[13];

int main() {
    REG_DISPCNT = MODE_4 | BG2_EN;
    initPalette();

    sprintf(lbuf, "< Its a spooky ghost");
    drawString(10, 50, lbuf, 76);

   drawImage4(0, 0, 0, 0, GHOST_WIDTH, GHOST_HEIGHT, ghost);
    vid_flip();
    while (1);
}

unsigned short *palette = (unsigned short *) 0x5000000;

void initPalette() {
    DMA[3].src = &images_palette;
    DMA[3].dst = palette;
    DMA[3].cnt = DMA_ON | sizeof(images_palette);
}