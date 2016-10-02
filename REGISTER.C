#include "REGISTER.H"

void regist(&flag)
{	
	FILE *fp;
	int firstplace_x,firstplace_y,currentplace_x,currentplace_y,buttons;
	firstplace_x=firstplace_y=currentplace_x=currentplace_y=0;
	char *number,*key,*conkey;
	char *s1,*s2,*s3;
	pic_show(0,0,"jiemian\\register.bmp");
	while(1)
	{
		Mouse_read(&currentplace_x,&currentplace_y,&buttons);
		Mouse_cpy(currentplace_x,currentplace_y);
		Mouse_show(currentplace_x,currentplace_y);
		firstplace_x=currentplace_x;
		firstplace_y=currentplace_y;
		Mouse_reshow(firstplace_x,firstplace_y);

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			number=inputtext(170,290,9,0);
			strcpy(number,".txt");
			strcat("C:\\txt\\user",number);
			strcpy(s1,number);
		}

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			key=inputtext(170,290,9,0);
			strcpy(s2,number);

		}

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			conkey=inputtext(170,290,9,0);
			strcpy(s3,number);
		}

		if(!strcmp(s2,s3))
		{
			if((fp=fopen(s1,"rt"))==nuLL)
			{
				fp=fopen(s1,"wt+");

			}
			else
			{
				pic_show(0,0,"jiemian\\re.bmp");
				*flag=3
				break;
			}
		}
	}
}