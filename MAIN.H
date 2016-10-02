#ifndef _MAIN_H
#define _MAIN_H

#include "MOUSE.H"
#include "DRAW.H"
#include "WELCOME.H"
#include "LOGIN.H"
#include "BUILD.H"

typedef struct food
{	
	char cF_number[4];
	char cF_name[30];
	char cF_price[5];
	char cF_salesamout[5];
	char cF_rate[2];

	struct food *spF_next;
}food;

typedef struct shop
{
	char cS_number[4];
	char cS_name[30];
	char cS_salesamount[5];
	char cS_rate[2]
	char cS_info[50];
	char cSF_number[4];

	struct shop *spF_next;
}shop;

typedef struct  user    
{
  char cU_number[4];                  
  char cU_account[12];
  char cU_key[12];
  char cU_sex[2];       
  char cU_adress[50];
  char cU_deal[18][2];       
  
  struct user *spU_next;
}user;

typedef struct  admin   
{
  char account[8];      
  char key[8];          
}admin;

#endif