/*
 * Exported with nin10kit v1.1
 * Invocation command was nin10kit -mode=4 images car.bmp explosion1.bmp explosion2.bmp explosion3.bmp explosion4.bmp gameover.bmp road.bmp titlescreen.bmp 
 * Time-stamp: Monday 11/09/2015, 17:55:40
 * 
 * Image Information
 * -----------------
 * car.bmp 30@64
 * explosion1.bmp 200@200
 * explosion2.bmp 200@200
 * explosion3.bmp 200@200
 * explosion4.bmp 200@200
 * gameover.bmp 240@160
 * road.bmp 240@320
 * titlescreen.bmp 240@160
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * 
 * All bug reports / feature requests are to be sent to Brandon (bwhitehead0308@gmail.com)
 */

#ifndef IMAGES_H
#define IMAGES_H

extern const unsigned short images_palette[255];
#define IMAGES_PALETTE_SIZE 255

extern const unsigned short car[960];
#define CAR_SIZE 960
#define CAR_WIDTH 30
#define CAR_HEIGHT 64

extern const unsigned short explosion1[20000];
#define EXPLOSION1_SIZE 20000
#define EXPLOSION1_WIDTH 200
#define EXPLOSION1_HEIGHT 200

extern const unsigned short explosion2[20000];
#define EXPLOSION2_SIZE 20000
#define EXPLOSION2_WIDTH 200
#define EXPLOSION2_HEIGHT 200

extern const unsigned short explosion3[20000];
#define EXPLOSION3_SIZE 20000
#define EXPLOSION3_WIDTH 200
#define EXPLOSION3_HEIGHT 200

extern const unsigned short explosion4[20000];
#define EXPLOSION4_SIZE 20000
#define EXPLOSION4_WIDTH 200
#define EXPLOSION4_HEIGHT 200

extern const unsigned short gameover[19200];
#define GAMEOVER_SIZE 19200
#define GAMEOVER_WIDTH 240
#define GAMEOVER_HEIGHT 160

extern const unsigned short road[38400];
#define ROAD_SIZE 38400
#define ROAD_WIDTH 240
#define ROAD_HEIGHT 320

extern const unsigned short titlescreen[19200];
#define TITLESCREEN_SIZE 19200
#define TITLESCREEN_WIDTH 240
#define TITLESCREEN_HEIGHT 160

#endif

