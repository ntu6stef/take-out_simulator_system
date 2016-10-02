#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stu
{
	char name[10];
	int num;
	int age;
	char addr[15];
};
void main()
{
	FILE *fp;
	struct stu boya[2],boyb[2],*qq,*pp;
	char ch;
	int i;
	pp=boya;
	qq=boyb;
	if((fp=fopen("stu_list.dat","wb+"))==NULL)
	{
		exit(1);	
	}
	for(i=0;i<2;i++,pp++)
		scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
	pp=boya;
	fwrite(pp,sizeof(struct stu),2,fp);
	fclose(fp);
	if((fp=fopen("stu_list.dat","wb+"))==NULL)
	{
		exit(1);
	}
	rewind(fp);
	fread(qq,sizeof(struct stu),2,fp);
	for(i=0;i<2;i++,qq++)
	{
		printf("%s\t%5d\t",qq->name,qq->num);
		printf("%7d\t%s\n",qq->age,qq->addr);
	}
	fclose(fp);
}