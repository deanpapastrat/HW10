/*
 * Exported with nin10kit v1.1
 * Invocation command was nin10kit -mode=4 images background.bmp gameover.bmp longbackground.png ghost.png player1.0.bmp player1.1.bmp player1.2.bmp player1.3.bmp player1.4.bmp player2.bmp title.bmp 
 * Time-stamp: Saturday 11/07/2015, 21:52:13
 * 
 * Image Information
 * -----------------
 * background.bmp 240@160
 * gameover.bmp 240@160
 * longbackground.png 960@160
 * ghost.png 48@76
 * player1.0.bmp 100@100
 * player1.1.bmp 100@100
 * player1.2.bmp 100@100
 * player1.3.bmp 100@100
 * player1.4.bmp 100@100
 * player2.bmp 100@100
 * title.bmp 240@160
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * 
 * All bug reports / feature requests are to be sent to Brandon (bwhitehead0308@gmail.com)
 */

#ifndef IMAGES_H
#define IMAGES_H

extern const unsigned short images_palette[75];
#define IMAGES_PALETTE_SIZE 75

extern const unsigned short background[19200];
#define BACKGROUND_SIZE 19200
#define BACKGROUND_WIDTH 240
#define BACKGROUND_HEIGHT 160

extern const unsigned short gameover[19200];
#define GAMEOVER_SIZE 19200
#define GAMEOVER_WIDTH 240
#define GAMEOVER_HEIGHT 160

extern const unsigned short longbackground[76800];
#define LONGBACKGROUND_SIZE 76800
#define LONGBACKGROUND_WIDTH 960
#define LONGBACKGROUND_HEIGHT 160

extern const unsigned short ghost[1824];
#define GHOST_SIZE 1824
#define GHOST_WIDTH 48
#define GHOST_HEIGHT 76

extern const unsigned short player10[5000];
#define PLAYER10_SIZE 5000
#define PLAYER10_WIDTH 100
#define PLAYER10_HEIGHT 100

extern const unsigned short player11[5000];
#define PLAYER11_SIZE 5000
#define PLAYER11_WIDTH 100
#define PLAYER11_HEIGHT 100

extern const unsigned short player12[5000];
#define PLAYER12_SIZE 5000
#define PLAYER12_WIDTH 100
#define PLAYER12_HEIGHT 100

extern const unsigned short player13[5000];
#define PLAYER13_SIZE 5000
#define PLAYER13_WIDTH 100
#define PLAYER13_HEIGHT 100

extern const unsigned short player14[5000];
#define PLAYER14_SIZE 5000
#define PLAYER14_WIDTH 100
#define PLAYER14_HEIGHT 100

extern const unsigned short player2[5000];
#define PLAYER2_SIZE 5000
#define PLAYER2_WIDTH 100
#define PLAYER2_HEIGHT 100

extern const unsigned short title[19200];
#define TITLE_SIZE 19200
#define TITLE_WIDTH 240
#define TITLE_HEIGHT 160

#endif

