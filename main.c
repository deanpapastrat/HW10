//
// Created by Mark on 11/7/2015.
//

#include "main.h"
#include <stdio.h>

//functions in mylib.c
void waitForVBlank();

void drawPixel4(int x, int y, u8 clrid);

void drawRect4(int left, int top, int right, int bottom, COLOR clr);

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

    sprintf(lbuf, "^Best square ever");

    drawString(30,10, lbuf, 1);

    drawRect4(10,10,20,20,120);
    vid_flip();
    while (1);
}

unsigned short *palette = (unsigned short *) 0x5000000;

void initPalette() {
    volatile u16 colors = 0xFFFF;
    DMA[3].src = &colors;
    DMA[3].dst = palette + 1;
    DMA[3].cnt = DMA_SOURCE_FIXED | DMA_ON | 255;
}