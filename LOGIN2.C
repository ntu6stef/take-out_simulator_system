#include "LOGIN2.H"

/* the admin log in interface */

void login2(int *flag)
{	
	int x,y;			//the status code of input
	char *num,*s1;			//the pointer that point to admin number
	char *key,*s2;			//the pointer that point to admin password

	struct admin *p_root;
	struct admin root;			//save the info that you input

	int firstplace_x,firstplace_y;		//the original position
	int currentplace_x,currentplace_y;				//the current position
	int buttons;			//the button of mouse

	*p_root=root;
	firstplace_x=firstplace_y=0;
	currentplace_x=currentplace_y=buttons=0;			//initial the previous values

/*-------------------------the define moudle------------------------------------------*/
	pic_show(0,0,"jiemian\\admin.bmp");
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

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			num=inputtext(170,290,9,0);				//input the account num
			strcpy(s1,num);	

			if(strlen(s1)==0)			//judge if the num is empty
			{			
				pic_show(200,300,"jiemian\\wrong1.bmp");			//show the warning
				chinese( , ," ",BLACK,16,F);
				x=1;
			}
			else if(!unique2(s1))			//judge if the account has existed
			{
				pic_show(200,300,"jiemian\\wrong2.bmp");
				chinese( , ," ",BLACK,16,F);
				x=1;
			}
			{
				pic_show(200,300,"jiemian\\right.bmp");				//show the right symble
				chinese( , ," ",BLACK,16,F);
				x=0;
			}	
		}

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			key=inputtext(170,290,9,0);				//input the password
			strcpy(s2,key);

			if(strlen(s2)==0)			//judge if the password is empty
			{
				pic_show(220,320,"jiemian\\wrong2.bmp");			//show the warning
				chinese( , ," ",BLACK,16,F);
				y=1;
			}
			else
			{
				pic_show(220,320,"jiemian\\right.bmp");				//show the right symble
				chinese( , ," ",BLACK,16,F);
				y=0;
			}
		}
/*------------------------the input moudle-----------------------------------*/
		
		if(currentplace_x>=330 && currentplace_x<=430 && currentplace_y>=530 &&currentplace_y<=575)
		{
			if(x!=0 || y!=0)
			{
				pic_show( , ,"jiemian\\warning.bmp");			//show the warning		
				chinese( , ," ",16,F);
			}
			else
			{
				strcpy(p_root->number,s1);				
				read2(p_root);
				if(!strcmp(p_root->key,s2))				//the key is right
				{
					*flag=
				}
				else
				{
					*flag=
				}
			}
		}


		if(currentplace_x>=635 && currentplace_x<=730 && currentplace_y>=530 &&currentplace_y<=575)
		{
			*flag=15;			//when click the quit button
			return;
		}

	}
}

/*--------some issues
1.the picture and position and chinese is not exact
2.the falg's value
3.the read2 function
---------------------*/