#include "LOGIN.H"

char *login(int *flag,char *subscriber)
{	
	struct customer *customer_xinxi;
	struct customer xinxi={"","","","","","","","","","","","","","","","","","","","","","",""};
	char *number,*key;
	char *s1,*s2;
	int a;
	int firstplace_x,firstplace_y,currentplace_x,currentplace_y,buttons;
	firstplace_x=firstplace_y=currentplace_x=currentplace_y=buttons=0;
	customer_xinxi=&xinxi;
	Mouse_cpy(0,0);
	pic_show(0,0,"jiemian\\login.bmp");
	chinese(10,10,"显示汉字",BLACK,32,F);
	while(1)
	{
		Mouse_read(&firstplace_x,&firstplace_y,&buttons);
		if(firstplace_x!=currentplace_x||firstplace_y!=currentplace_y)
		{
			Mouse_reshow(currentplace_x,currentplace_y);
			Mouse_cpy(firstplace_x,firstplace_y);
			Mouse_show(firstplace_x,firstplace_y);
			currentplace_x=firstplace_x;
			currentplace_y=firstplace_y;
		}
		if(currentplace_x>353&&currentplace_x<=670&&currentplace_y>=516&&currentplace_y<=569&&buttons==1)
		{
			number=inputtext(400,520,11,0);
			strcpy(s1,number);
		}
		if(currentplace_x>353&&currentplace_x<=670&&currentplace_y>=596&&currentplace_y<=646&&buttons==1)
		{
			key=inputtext(400,600,11,1);
			strcpy(s2,key);
		}

		if(currentplace_x>=479&&currentplace_x<=542&&currentplace_y>=678&&currentplace_y<=718&&buttons==1)
		{
			strcpy(customer_xinxi->number,s1);
			a=readxx(customer_xinxi);
			if(a==0)
			{
				*flag=2;
				return;
			}
			if(a!=0&&strcmp(s2,customer_xinxi->key)!=0)
			{
				pic_show(0,0,"jiemian\\wrong.bmp");
				*flag=2;
				return;
			}
			if(a!=0&&strcmp(s2,customer_xinxi->key)==0)
			{
				strcpy(subscriber,s1);
				*flag=7;
				return subscriber;
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