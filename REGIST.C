#include "REGIST.H"

void regist(int *flag)
{	
	int x,y,z;			//the status code of input result.0 success/ 1 wrong
	char *num,*s1;			//the pointer that point to account number
	char *key,*s2;			//the pointer that point to account password
	char *r_key,*s3;			//the pointer that point to confirm password

	struct user newer;			//define a user struct to save the info

	int firstplace_x,firstplace_y,			//the original position
	int currentplace_x,currentplace_y;			//the current positon
	int buttons;			//the button of mouse

	x=y=z=0;
	firstplace_x=firstplace_y=0;
	currentplace_x=currentplace_y=buttons=0;			//initial the original values

/*------------------------the define moudle---------------------------------*/

	pic_show(0,0,"jiemian\\register.bmp");
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
			else if (unique(s1))			//judge if the account has exited
			{
				pic_show(200,300,"jiemian\\wrong1.bmp");
				chinese( , ," ",BLACK,16,F);
				x=1;
			}
			else
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

		if(currentplace_x>=170&&currentplace_x<=230&&currentplace_y>=290&&currentplace_y<=320&&buttons==1)
		{
			r_key=inputtext(170,290,9,0);			//input the password again
			strcpy(s3,r_key);

			if(strcmp(s2,s3)!=0)			//judge if the input is empty
			{
				pic_show(330,430,"jiemian\\wrong3.bmp");
				chinese( , ," ",BLACK,16,F);
				z=1;
			}
			else
			{
				pic_show(330,430,"jiemian\\right.bmp");				//show the right symble
				chinese( , ," ",BLACK,16,F);
				z=0;
			}
		}

/*------------------------the input moudle-----------------------------------*/

		if(currentplace_x>=330 && currentplace_x<=430 && currentplace_y>=330 && currentplace_y<=430 )			//click the enter button
		{
			if(x!=0 || y!=0 || z!=0)			//judge if exist mistake
			{
				pic_show( , ,"jiemian\\warning.bmp");
				chinese( , ," ",BLACK,16,F);
			}
			else			//write in the file and make flag equal with 1, back to log in page
			{
				strcpy(newer.number,s1);			
				strcpy(newer.key,s2);
				build(newer);
				*flag=1;
				return;
			}
		}	

/*----------------------the build user file moudle-------------------------*/
	}
}


/*some issue reserved

1. the chinese, pic_show, position need to be exact;

2. the unique function should be write in some file   (archieved

3. the build1 function should be write in some file   (archieved

4. I need the enter, right , wrong icon (bmp)

*/