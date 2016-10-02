#ifndef _DRAW_H
#define _DRAW_H

#define SVGA_COPY 0  //覆盖
#define SVGA_XOR  1  //异或
#define SVGA_OR   2  //或
#define SVGA_AND  3  //与
#define SVGA_NOT  4  //非

static int Writemode=SVGA_COPY;
static int Drawcolor;

#include <io.h>
#include <stdio.h>
#include <mem.h>
#include <fcntl.h>
#include <stdlib.h>
#include <alloc.h>
#include <dos.h>
#include <conio.h>
#include <math.h>

#define SETRGB(x,y,z) do{rgb.r=x;rgb.g=y;rgb.b=z;}while(0)
#define BLACK SETRGB(0,0,0)
#define GRAY SETRGB(192,192,192)
#define LIGHTGRAY SETRGB(128.138.135)
#define WHITE SETRGB(225,225,225)
#define SNOWYWHITE SETRGB(255,255,255)
#define BLUE SETRGB(65,105,255)
#define LIGHTBLUE SETRGB(135,206,255)
#define RED SETRGB(255,0,0)
#define YELLOW SETRGB(255,255,0)
#define ORANGE SETRGB(255,97,0)
#define BROWN SETRGB(128,42,42)
#define INDIGO SETRGB(8,46,84)
#define GREEN SETRGB(0,255,0)
#define PURPLE SETRGB(160,32,240)

void SET_SVGA_MODE(int mode);
int darkless(int x,int y);
void CLOSE_SVGA(void);
void SvgaSetWriteMode(int mode);
void selectpage(int page);
void setpixel(int x,int y,int color);
void setcolor(int color);
void line(int x1,int y1,int x2,int y2);
void rectangle(int x1,int y1,int x2,int y2);
void Hline(int x1,int x2,int y);
void Vline(int x,int y1,int y2);
void fill_rectangle(int x1,int y1,int x2,int y2);
int SVGA_Circle(int x,int y,int r,int color);
int getpixel(int x,int y);
void CLOSE_SVGA_MODE(void);
void dark(int x1,int y1,int x2,int y2,int color);
void pic_show(int x,int y,char *filename);
void pic_show_xor(int x,int y,char *filename);

#endif