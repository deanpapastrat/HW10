//
// Created by Mark on 11/7/2015.
//

#include "main.h"
#include "mylib.h"

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

void drawImage4(int r, int c, int width, int height, const u16* image) {
    drawImageOffset4(c, r, 0, 0, width, height, image);
}
void drawImageOffset4(int x, int y, int sourcex, int sourcey, int width, int height, const unsigned short *image) {

    if (sourcex + 240 > width || sourcey + 160 > height)
        return;

    int xcopies = width - sourcex;
    int maxy = height;

    height = height;
    xcopies = xcopies / 2;

//    if would go to next row, change copies to hit the 240th pixel and no futher
    if (x + xcopies > 240) {
        xcopies = (240 - x) / 2;
    }
    //if we would start writing to random memory (bad), stop at the 160th row
    if (y + height > 160) {
        maxy = (160 - y);
    }

    for (int iy = 0; iy < maxy; iy++) {
        //source is the image address with the offset of the source looking
        DMA[3].src = (image + ((sourcey + iy) * width + sourcex) / 2);
        //dst is the location on the current page, offset by x and y
        DMA[3].dst = &vid_page[((y + iy) * 120 + x)];
        //turn dma on and go for the correct number of transfers to not go over either memory width
        DMA[3].cnt = DMA_ON | DMA_16 | xcopies;
    }

}

void drawSprite4(int x, int y, int sourcex, int sourcey, int width, int height, u8 colorkey,
                 const unsigned short *image) {

    int maxx = (width - sourcex) / 2;
    int maxy = height / 2;

    //if would go to next row, change copies to hit the 240th pixel and no futher
    if (x + maxx > 240) {
        maxx = (240 - x);
    }
    //if we would start writing to random memory (bad), stop at the 160th row
    if (y + maxy > 160) {
        maxy = (160 - y + height) / 2;
    }


    for (int ix = 0; ix < maxx; ix++) {
        for (int iy = 0; iy < maxy; iy++) {
            //the double pixel location
            u16 *dst = &vid_page[((y + iy) * 240 + (x + ix)) / 2];  // Division by 2 due to u8/u16 pointer mismatch!
            if ((*(image + ((sourcey + iy) * width) + sourcex + ix) & 0xFF) != colorkey)
                *dst = *(image + ((sourcey + iy) * width) + sourcex + ix) << 8;    // odd pixel
            if ((*(image + ((sourcey + iy) * width) + sourcex + ix) & 0xFF) != colorkey)
                *dst = *dst | *(image + ((sourcey + iy) * width) + sourcex + ix);        // even pixel
        }
    }

}

void drawPixel4(int x, int y, u8 clrid) {
    u16 *dst = &vid_page[(y * 240 + x) / 2];  // Division by 2 due to u8/u16 pointer mismatch!
    if (x & 1)
        *dst = (*dst & 0xFF) | (clrid << 8);    // odd pixel
    else
        *dst = (*dst & ~0xFF) | clrid;        // even pixel
}

void fillScreen4(COLOR clr) {
    drawRect4(0, 0, 240, 160, clr);
}

void drawRect4(int x, int y, int width, int height, u8 colorkey) {
    for (int iy = 0; iy < height; iy++) {
        //source is the color
        DMA[3].src = &colorkey;
        //dst is the location on the current page, offset by x and y
        DMA[3].dst = &vid_page[((y + iy) * 120 + (x / 2))];
        //turn dma on and go for the correct number of transfers to not go over either memory width
        DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | (width / 2);
    }

//    for (int x = r; x <= r + height; x++) {
//        for (int y = c; y <= c + width; y++) {
//            drawPixel4(r, c, colorkey);
//        }
//    }
}
