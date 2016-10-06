#include "LOGIN.H"

char *login(int *flag,char *subscriber)
{	
	int x,y;			//the status code of input
	char *num,*s1;			//the pointer that point to user number
	char *key,*s2;			//the pointer that point to user password

	struct user *p_use;
	struct user use;			//save the info about user

	int firstplace_x,firstplace_y;			//the original position
	int currentplace_x,currentplace_y;				//the current position
	int buttons;			//the button of mouse

	*p_use=use;
	firstplace_x=firstplace_y=0;
	currentplace_x=currentplace_y=buttons=0;			//initial the previous values

/*---------------the define moudle----------------------------------------------------*/

	pic_show(0,0,"jiemian\\login.bmp");
	//chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
	dtime(100,100);
	Mouse_cpy(0,0);
	while(1)			//loop to check the status of mouse
	{
		Mouse_read(&currentplace_x,&currentplace_y,&buttons);			//obtain the current position
		if (currentplace_x != firstplace_x || currentplace_y != firstplace_y)
		{
			Mouse_reshow(firstplace_x,firstplace_y);			//reshow the region that covered by mouse
			Mouse_cpy(currentplace_x,currentplace_y);			//copy the region that will be covered
			Mouse_show(currentplace_x,currentplace_y);			//show the mouse
			firstplace_x=currentplace_x;
			firstplace_y=currentplace_y;			//ready for next loop
		}

/*------------------------the mouse-show moudle-----------------------------*/

		if(currentplace_x>353&&currentplace_x<=670&&currentplace_y>=516&&currentplace_y<=569&&buttons==1)
		{
			num=inputtext(400,520,11,0);				//input the account number
			strcpy(s1,num);

			if(strlen(s1)==0)			//judge if the num is empty
			{			
				pic_show(200,300,"jiemian\\wrong1.bmp");			//show the warning
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
				x=1;
			}
			else if(!unique2(s1))			//judge if the account has existed
			{
				pic_show(200,300,"jiemian\\wrong2.bmp");
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
				x=1;
			}
			{
				pic_show(200,300,"jiemian\\right.bmp");				//show the right symble
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
				x=0;
			}
		}
		if(currentplace_x>353&&currentplace_x<=670&&currentplace_y>=596&&currentplace_y<=646&&buttons==1)
		{
			key=inputtext(400,600,11,1);			//input the password
			strcpy(s2,key);

			if(strlen(s2)==0)			//judge if the password is empty
			{
				pic_show(220,320,"jiemian\\wrong2.bmp");			//show the warning
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
				y=1;
			}
			else
			{
				pic_show(220,320,"jiemian\\right.bmp");				//show the right symble
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
				y=0;
			}
		}
/*------------------------the input moudle---------------------------------------------------*/

		if(currentplace_x>=479&&currentplace_x<=542&&currentplace_y>=678&&currentplace_y<=718&&buttons==1)
		{
			if(x!=0 || y!=0)
			{
				pic_show(0,0,"jiemian\\warning.bmp");			//show the warning
				chinese(10,10,"ÏÔÊ¾ºº×Ö",0x0000,32,'F');
			}
			else
			{
				strcpy(p_use->number,s1);				
				read1(p_use);
				if(!strcmp(p_use->key,s2))				//the key is right
				{
					*flag=0;
				}
				else
				{
					*flag=0;
				}
			}

		}

		if(currentplace_x>188&&currentplace_x<=278&&currentplace_y>=0&&currentplace_y<=44&&buttons==1)
		{
			*flag=6;
			return;
		}
		if(currentplace_x>962&&currentplace_x<=1024&&currentplace_y>=0&&currentplace_y<=44&&buttons==1)
		{
			*flag=14;
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