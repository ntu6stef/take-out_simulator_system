#ifndef _BUILD_H
#define _BUILD_H
#include<conio.h>
#include<dos.h>
#include<io.h>
#include<bios.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MAIN.H"
#include "DRAW.H"
#include "INPUT.H"

int unique1(char *s1);
int unique2(char *s1);
void read1(struct user *p_use);
void read2(struct admin *p_root);
void build1(struct user newer);

#endif