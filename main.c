//
// Created by Mark on 11/7/2015.
//

#include "main.h"
#include "mylib.h"
#include "assets/images.h"
#include "assets/text.h"
#include <stdio.h>

typedef struct gameplayer {
    int speed;
    int distance;
    int xpos;
    int ypos;
} gameplayer;

enum gamestate {
    STARTMENU,
    BRIEF,
    INGAME,
    GAMEOVER
};

//text buffer for writing text
char lbuf[80];

int main() {
    //GBA functions
    REG_DISPCNT = MODE_4 | BG2_EN;
    initPalette();

    //loop vars
    enum gamestate state = STARTMENU;
    char buttondown = 0;

    gameplayer player;
    player.speed = 0;
    player.distance = 0;
    player.xpos = 145;
    player.ypos = 0;

    int explosionNumber = 1;

    //fill screen to start with black for first render
    fillScreen4(0);
    while (1) {
        waitForVBlank();
        if (KEY_DOWN_NOW(BUTTON_SELECT)) {
            state = STARTMENU;
            player.xpos = 145;
            player.ypos = 0;
            player.distance = 0;
            player.speed = 0;
        }
        switch (state) {
            case STARTMENU:
                drawImage4(0, 0, TITLESCREEN_WIDTH, TITLESCREEN_HEIGHT, titlescreen);
                if (KEY_DOWN_NOW(BUTTON_START)) {
                    buttondown = 1;
                } else {
                    if (buttondown) {
                        state = BRIEF;
                        buttondown = 0;
                    }
                }
                break;
            case BRIEF:
                drawImage4(0, 0, ROAD_WIDTH, ROAD_HEIGHT, road);
                drawRect4(8, 25, 120, 18, 0);
                sprintf(lbuf, "You're in a fast car!");
                drawString(30, 10, lbuf, 0xfe);
                drawRect4(8, 55, 218, 30, 0);
                sprintf(lbuf, "Go as fast as possible without");
                drawString(60, 10, lbuf, 0xfe);
                sprintf(lbuf, "crashing. Koenigseggs are expensive");
                drawString(70, 10, lbuf, 0xfe);

                drawRect4(8, 95, 120, 18, 0);
                sprintf(lbuf, "Press Start to drive!");
                drawString(100, 10, lbuf, 0xfe);

                if (KEY_DOWN_NOW(BUTTON_START)) {
                    buttondown = 1;
                } else {
                    if (buttondown) {
                        state = INGAME;
                        buttondown = 0;
                    }
                }
                break;
            case INGAME:
                if (player.xpos < 60 || player.xpos > 170) {
                    switch (explosionNumber) {
                        case 1:
                            drawSprite4(player.xpos - 120, 200, 0, 0, EXPLOSION1_WIDTH, EXPLOSION1_HEIGHT, 0xE4,
                                        explosion1);
                            break;
                        case 10:
                            drawSprite4(player.xpos - 120, 200, 0, 0, EXPLOSION2_WIDTH, EXPLOSION2_HEIGHT, 0xE4,
                                        explosion2);
                            break;
                        case 20:
                            drawSprite4(player.xpos - 120, 200, 0, 0, EXPLOSION3_WIDTH, EXPLOSION3_HEIGHT, 0xE4,
                                        explosion3);
                            break;
                        case 30:
                            drawSprite4(player.xpos - 120, 200, 0, 0, EXPLOSION4_WIDTH, EXPLOSION4_HEIGHT, 0xE4,
                                        explosion4);
                            break;
                        case 40:
                            state = GAMEOVER;
                            break;
                    }
                    explosionNumber++;
                } else {
                    if (KEY_DOWN_NOW(BUTTON_RIGHT) && player.speed > 0) {
                        player.xpos++;
                    } else if (KEY_DOWN_NOW(BUTTON_LEFT) && player.speed > 0) {
                        player.xpos--;
                    }
                    if (KEY_DOWN_NOW(BUTTON_UP) && player.speed < 80) {
                        player.speed += 1;
                    } else if (KEY_DOWN_NOW(BUTTON_DOWN) && player.speed > 0) {
                        player.speed -= 3;
                        if (player.speed < 0) {
                            player.speed = 0;
                        }
                    }
                    player.distance -= player.speed / 2;
                    drawImageOffset4(0, 0, 0, (player.distance % 160) + 160, ROAD_WIDTH, ROAD_HEIGHT, road);
                    drawSprite4(player.xpos, 100, 0, 0, CAR_WIDTH, CAR_HEIGHT, 0xe4, car);
                    drawRect4(0, 0, 100, 25, 0);
                    sprintf(lbuf, "Distance %d feet", -player.distance / 10);
                    drawString(4, 2, lbuf, 0xfe);
                    sprintf(lbuf, "Speed: %d mph", player.speed * 3);
                    drawString(12, 2, lbuf, 0xfe);
                }
                break;
            case GAMEOVER:
                drawImage4(0, 0, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, gameover);
                break;
        }
        vid_flip();
    }
}

//this gets done here because drawing gets done here
unsigned short *palette = (unsigned short *) 0x5000000;

void initPalette() {
    DMA[3].src = &images_palette;
    DMA[3].dst = palette;
    DMA[3].cnt = DMA_ON | sizeof(images_palette);
}