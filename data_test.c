#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define M 10
#define N 15

typedef struct food
{
	int iFood_number;
	char cFood_name[24];
	char cFood_price[2];
	char cFood_grade[30];

	struct food *spFood_next;
}food;

typedef struct shop
{
	int iShop_number;
	char cShop_name[24];
	char cShop_adress[30];
	char cShop_phone[12];
	char cShop_other[30];
	struct food *spFood_top;

	struct shop *spShop_next;
}shop;

typedef struct  user
{
	int iUser_number;
	char cUser_id[12];
	char cUser_key[8];
	char cUser_name[17];
	char cUser_sex[3];
	char cUser_adress[10];
	char caDeal_info[M][N];

	struct user *spUser_next;
}user;

typedef struct  admin1
{
  char cAdmin_id[8];
  char cAdmin_key[8];
}admin1;

int main(void)
{
	FILE *fp;
	shop *spShop_top;
	spShop_top=sShop_1;
	shop sShop_1,sShop_2,sShop_3;
	sShop_1.spShop_next=sShop_2;
	sShop_2.spShop_next=sShop_3;
	sShop_3.spShop_next=NULL;
	if((fp=fopen("txt\\shop.txt","rt"))==NULL)
	{
		printf("error occurred when open the shop.txt\nplease press anykey to exit>>>");
		getch();
		exit(1);
	}
	else()
	{
		fread(sShop_1,sizeof(struct shop),1,fp);
		fread(sShop_2,sizeof(struct shop),1,fp);
		fread(sShop_3,sizeof(struct shop),1,fp);
		if(!feof(fp))
		{
			remalloc()
		}

	}

}
