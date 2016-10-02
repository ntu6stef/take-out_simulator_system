#include "INIT.H"

struct shop *init_shop()
{
	struct expert *p1,*p2;
	struct expert *head;
	FILE *fp;
	if((fp=fopen("TXT\\shop.txt "))==NULL)
	{
		printf("can't open shop.txt,please preess anykey to exit");
		getch();
		exit(1);
	}
	head=p2=(struct shop *)malloc(sizeof(struct shop));
	if(!p2)
	{
		printf("out of memory,press anykey to exit");
		getch();
		exit(1);
	}
	fscanf(fp,"%s%s%s%s%s",p2->cS_number,p2->cS_name,p2->cS_salesamount,p2->cS_rate,p2->cS_info);

	while(feof(fp)==0)
	{
		p1=(struct expert *)malloc(sizeof(struct expert));
		if(!p1)
		{
			printf("out of memory,press anykey to exit");
			exit(1);
		}
		fscanf(fp,"%s%s%s%s%s",p1->cS_number,p1->cS_name,p1->cS_salesamount,p1->cS_rate,p1->cS_info);
		p2->spShop_next=p1;
		p2=p1;
	}
	p2->spShop_next=NULL;
	fcolse(fp);
	return(head);
}

struct food *init_food()
{
	struct expert *p1,*p2;
	struct expert *head;
	FILE *fp;
	if((fp=fopen("TXT\\food.txt","rt"))==NULL)
	{
		printf("can't open food.txt,press anykey to exit");
		getch();
		exit(1);
	}
	head=p2=(struct shop *)malloc(sizeof(struct shop));
	if(!p2)
	{
		printf("out of memory,press anykey to exit");
		getch();
		exit(1);
	}
	fscanf(fp,"%s%s%s%s%s",p2->cF_number,p2->cF_name,p2->cF_price,p2->cF_salesamount,p2->cF_rate);

	while(feof(fp)==0)
	{
		p1=(struct expert *)malloc(sizeof(struct expert));
		if(!p1)
		{
			printf("out of memory,press anykey to exit");
			exit(1);
		}
		fscanf(fp,"%s%s%s%s%s",p2->cF_number,p2->cF_name,p2->cF_price,p2->cF_salesamount,p2->cF_rate);
		p2->spShop_next=p1;
		p2=p1;
	}
	p2->spShop_next=NULL;
	fcolse(fp);
	return(head);
}
