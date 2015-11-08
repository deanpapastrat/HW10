//
// Created by Mark on 11/7/2015.
//

#include "main.h"
#include "mylib.h"
#include "assets/images.h"
#include "assets/text.h"
#include <stdio.h>

//text buffer for writing text
char lbuf[15];

int main() {
    REG_DISPCNT = MODE_4 | BG2_EN;
    initPalette();

    fillScreen4(0);
    sprintf(lbuf, "< Its a spooky ghost");
    drawString(10, 50, lbuf, 76);

    int progress = 500;
    while (1) {
        waitForVBlank();
        drawImage4(0, 0, progress, 0, LONGBACKGROUND_WIDTH, LONGBACKGROUND_HEIGHT, longbackground);
        drawSprite4(0, 87, 0, 0, PLAYER14_WIDTH, PLAYER14_HEIGHT, 0, player14);
        vid_flip();
        while (!KEY_DOWN_NOW(BUTTON_RIGHT));
        progress++;
    }
}

//this gets done here because drawing gets done here
unsigned short *palette = (unsigned short *) 0x5000000;

void initPalette() {
    DMA[3].src = &images_palette;
    DMA[3].dst = palette;
    DMA[3].cnt = DMA_ON | sizeof(images_palette);
}