#ifndef _MOUSE_H
#define _MOUSE_H

#include <dos.h>
#include "DRAW.H"

void Mouse_cpy(int x,int y);/*鼠标区域背景扣取*/
void Mouse_reshow(int x,int y);/*鼠标扣取背景重现*/
void Mouse_show(int x,int y);/*鼠标显示*/
int  Mouse_init(int Wid,int Hei);/*鼠标初始化*/
void Mouse_read(int *mouse_x,int * mouse_y,int * mouse_butt);/*读取鼠标状态*/

#endif