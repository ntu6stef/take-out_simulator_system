#ifndef _INPUT_H
#define _INPUT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include "DRAW.H"
#include "CHINESE.H"

#define Enter 13
#define Bksp  8
char *inputtxtt(int x,int y,int n,int m);
char *inputkey(int x,int y,int n,int m);

#endif