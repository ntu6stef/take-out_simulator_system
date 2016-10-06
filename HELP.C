#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include"mouse.h"
#include"draw.h"
#include"chinese.h"
#include"input.h"

void help(int *flag)
{
	
	char s[10][80];
	FILE *fp;
	int firstplace_x, firstplace_y,currentplace_x,currentplace_y,buttons;
	firstplace_x= firstplace_y= currentplace_x=currentplace_y=buttons=0;
	Mouse_cpy(0,0);
	pic_show(0,0,"jiemian\\help.bmp");


	if((fp=fopen("txt\\help.txt","rt"))==NULL)
	{
		printf("can't open txt");
		exit(1);
	}
	fscanf(fp,"%s%s%s%s%s%s%s%s%s%s%s",s[0],s[1],s[2],s[3],
					   s[4],s[5],s[6],s[7],s[8],s[9],s[10]);
	fclose(fp);

	put_asc(400,120,2,4,s[0],0x0000);
	chinese(340,200,s[1],0x0000,32,'F');
	chinese(340,260,s[2],0x0000,32,'F');
	chinese(200,320,s[3],0x0000,32,'F');
	put_asc(270,313,1,3,s[4],0x0000);
	chinese(327,320,s[5],0x0000,32,'F');
	chinese(240,380,s[6],0x0000,32,'F');
	chinese(240,440,s[7],0x0000,32,'F');
	put_asc(580,435,1,3,s[8],0x0000);
	chinese(620,440,s[9],0x0000,32,'F');
	chinese(260,520,s[10],0x0000,32,'F');


	
	 while(1)//一直循环检测鼠标位置
	 {
		Mouse_read(&firstplace_x,&firstplace_y,&buttons);
		/*主界面鼠标显示*/
		if(firstplace_x!=currentplace_x
			||firstplace_y!=currentplace_y)//如果鼠标移动
		{
			Mouse_reshow( currentplace_x,currentplace_y);
			Mouse_cpy(firstplace_x, firstplace_y);
			Mouse_show(firstplace_x, firstplace_y);
			currentplace_x= firstplace_x;
			currentplace_y= firstplace_y;
        }

		/************如果点击下一步选项，回到登录界面*/
		if(  currentplace_x>=415&& currentplace_x<=650&&currentplace_y>=610&&currentplace_y<=690&&buttons==1)
		{
			* flag=1;
			return;
		}

        if(bioskey(1)&&(bioskey(0)==0x011b))
		{
			pic_show(0,0,"jiemian\\thanks.bmp");
			delay(100);
			CLOSE_SVGA();
			exit(1);
		}

	 }

 }