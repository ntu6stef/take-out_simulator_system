#ifndef _CHINESE_H
#define _CHINESE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <dos.h>
#include "DRAW.H"

void open_hzk(char *path);
void get_hz(char incode[],char bytes[],int type);
void dishz(int x,int y,char cade[],int color,int type);
void chinese(int x,int y,char *s,int color,int type,char ziti);
void put_asc(int cx,int cy,int xsize,int ysize,char *s,int color);

#endif