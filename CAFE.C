#include "CAFE.H"
 
void win_cpy(int x,int y);
void win_reshow(int x,int y);
void choose_shop(int *flag)
{
	int firstplace_x,firstplace_y,currentplace_x,currentplace_y,buttons;
	firstplace_x=firstplace_y=currentplace_x=currentplace_y=buttons=0;
	pic_show(0,0,"jiemian\\  .bmp");
	pic_show( , ,"jiemian\\  .bmp");
	pic_show( , ,"jiemian\\  .bmp");
	pic_show( , ,"jiemian\\  .bmp");
	pic_show( , ,"jiemian\\  .bmp");
	chinese (250,10,"欢迎使用HustEleme系统，祝您购物愉快！"，BlACK,32,F);
	while(1)
	{
		Mouse_read(&currentplace_x,&currentplace_y,&buttons);
		if (firstplace_x!=currentplace_x||firstplace_y!=currentplace_y)
		{
			Mouse_reshow(firstplace_x,firstplace_y);
			Mouse_cpy(currentplace_x,currentplace_y);
			Mouse_show(currentplace_x,currentplace_y);
			firstplace_x=currentplace_x;
			firstplace_y=currentplace_y;
		}

		if (mouse_x>= && mouse_x<= && mouse_y>= && mouse_y<= )
		{
			win_cpy( , );
			pic_show( , , );
			chinese( , , , , , );
			chinese( , , , , , );
			chinese( , , , , , );
		}
		else
		{
			win_reshow( , );
		}

		if (mouse_x>= && mouse_x<= && mouse_y>= && mouse_y<= && buttons==1)
		{
			pic_show( , , );
		}
		if (mouse_x>= && mouse_x<= && mouse_y>= && mouse_y<= && buttons==1)
		{
			pic_show( , , );
		}
		if (mouse_x>= && mouse_x<= && mouse_y>= && mouse_y<= && buttons==1)
		{
			pic_show( , , );
		}

		if (mouse_x>= && mouse_x<= && mouse_y>= && mouse_y<= && buttons==1)
		{
			*flag= ;
			build(       );
			pic_show(0,0,"jiemian\\  .bmp");
			delay(100);
		}
	}
}

void win_cpy(int x, int y)
{
	int i,j;
	unsigned long pos;
	int oldpage,newpage;
	short far *video_buffer=(short far *)0xA0000000L;
	oldpage=newpage;
	selectpage(page);	
}