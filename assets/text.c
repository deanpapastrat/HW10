#include "text.h"

void drawPixel4(int x, int y, unsigned char color);

void drawChar(int row, int col, char ch, unsigned char color) {
    int r, c;
    for (r = 0; r < 8; r++) {
        for (c = 0; c < 6; c++) {
            if (fontdata_6x8[r * 6 + c + ch * 48]) {
                drawPixel4(c + col, r + row, color);
            }
        }
    }
}

void drawString(int row, int col, char *s, unsigned char color) {
    while (*s) {
        drawChar(row, col, *s++, color);
        col += 6;

    }
}