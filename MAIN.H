#ifndef _MAIN_H
#define _MAIN_H

#include "DRAW.H"
#include "MOUSE.H"
#include "WELCOME.H"
#include "LOGIN.H"
/*
#include "LOGIN2.H"
#include "REGIST.H"
#include "CAFE.H"
#include "SNACK.H"
#include "CHECKOUT.H"
#include "HISTORY.H"
#include "MANAGE.H"
#include "COUNT.H"
#include "HELP.H"
#include "END.H"
*/
typedef struct food				//save the info about food
{	
	char number[4];
	char name[30];
	char price[5];
	char salesamout[5];
	char rate[2];

	struct food *next;
}food;

typedef struct shop				//save the info about shop
{
	char number[4];
	char name[30];
	char salesamount[5];
	char rate[2];
	char info[50];

	struct shop *next;
}shop;

typedef struct  user			//save the info about user
{
  char number[12];                  
  char key[12];
  char sex[2];       
  char adress[50];
  char deal[18][2];       
  
  struct user *next;
}user;

typedef struct  admin			//save the info about administer
{
  char number[8];      
  char key[8];          
}admin;

#endif