#include"DRAW.H"

/******************
函数功能:在SVGA条件下，通过点的操作使屏幕变暗
函数类型 int
函数名：darkless
参数：void
返回值：返回1表示操作失败，返回0表示执行成功
*******************/
int darkless(int x,int y)
{
    int i,j;                                    //循环变量
    char newpage,OldPage=0;                     //辅助显存换页
    long Width=200,Height=180;
    unsigned long pos;                           //辅助显存换页，表示该点在显存中的线性位置
    int far *video_buffer=(int far *)0xA0000000L;     //显存地址
    selectpage(OldPage);
    for(i=Height-1+y;i>=y;i--)                             //写入显存
    {
        for(j=x;j<Width+x;j++)
        {
            pos=((long)(i)<<10)+j;                   //计算数据的位置,相当于pos=(i+y）*1024L+j+x，此处一定要把（i+y）转换成long
            newpage=(char)(pos>>15);                     //计算数据的显存页数，相当于newpage=pos/32767
            if(newpage!=OldPage)                        //调用换页函数
            {
                selectpage(newpage);
                OldPage=newpage;
            }

            if((pos+i)%2==0)                        //每隔一个点不写入一次
                *(video_buffer+(pos&0x7fff))=0;
        }
    }
    return(0);
}


void setcolor(int color)
{
    Drawcolor=color;
}

void SET_SVGA_MODE(int mode)
{
 union REGS r;
 r.x.ax=0x4f02;
 r.x.bx=mode;
 int86(0x10,&r,&r);
}

void CLOSE_SVGA(void)
{
	union REGS r;
	r.x.ax=0x03;
	int86(0x10,&r,&r);
}   

void selectpage(int page)
{
  union REGS r;
  r.x.ax=0x4f05;
  r.x.bx=0x00;
  r.x.dx=page;
  int86(0x10,&r,&r);
}

void SvgaSetWriteMode(int mode)
{
	if((mode>=SVGA_COPY)&&(mode<=SVGA_NOT))
		Writemode=mode;
}

void setpixel(int x,int y,int color)
{

  unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
  long pos=(y*1024L+x);
  unsigned int page=pos*2/65536L;
  selectpage(page);
  switch(Writemode)
  {
	case SVGA_AND:
			*((unsigned short far *)(video_buffer+pos))&=color;
			break;
	case SVGA_OR:
			*((unsigned short far *)(video_buffer+pos))|=color;
			break;
	case SVGA_XOR:
			*((unsigned short far *)(video_buffer+pos))^=color;
			break;
	case SVGA_COPY:
			*((unsigned short far *)(video_buffer+pos))=color;
			break;
  }
//  *(video_buffer+pos)=color;
}

void line(int x1,int y1,int x2,int y2)//在SVGA条件下，在(x1,y1)与(x2,y2)之间画线
{
   int dx,dy,x_inc=1,y_inc=1,x,y;
   int index,error=0;
   x=x1;y=y1;
   dx=x2-x1;dy=y2-y1;
   if(dx<0)
	{
	 dx=-dx;
	 x_inc=-1;
	}
   if(dy<0)
	{
	 dy=-dy;
	 y_inc=-1;
	}
	if(dx>dy)
	{
		 for(index=0;index<=dx;index++)
		 {
		  setpixel(x,y,Drawcolor);
		  error+=dy;
		  x+=x_inc;
		  setpixel(x,y,Drawcolor);
			if(error>dx)
				{
				 error-=dx;
				 y+=y_inc;
				 setpixel(x,y,Drawcolor);
				}
		 }
	}
	else
		{
		 for(index=0;index<=dy;index++)
			   {
				setpixel(x,y,Drawcolor);
				error+=dx;
				y+=y_inc;
				setpixel(x,y,Drawcolor);
				if(error>dy)
					{
					 error-=dy;
					 x+=x_inc;
					 setpixel(x,y,Drawcolor);
					}
			   }
		}
}

void Vline(int x,int y1,int y2)//在SVGA条件下，在(x,y1)与(x,y2)之间画线，即画一条竖线
{
    int i;
	for(i=y1;i<=y2;i++)
		setpixel(x,i,Drawcolor);
}

void Hline(int x1,int x2,int y)//在SVGA条件下，在(x1,y)与(x2,y)之间画线，即画一条横线
{
	int i;
	for(i=x1;i<=x2;i++)
		setpixel(i,y,Drawcolor);
}

void rectangle(int x1,int y1,int x2,int y2)//在SVGA条件下，在以(x1,y1)和(x2,y2)为对角定点之间画矩形框
{
  line(x1,y1,x1,y2);
  line(x1,y2,x2,y2);
  line(x2,y2,x2,y1);
  line(x2,y1,x1,y1);
}

void fill_rectangle(int x1,int y1,int x2,int y2)//在SVGA条件下，在以(x1,y1)和(x2,y2)为对角定点之间画矩形图
{
	int i;
	for(i=y1;i<=y2;i++)
	Hline(x1,x2,i);
}
/*******************
函数功能：在1024*768模式下画一个圆，并填充相应颜色
函数类型：extern int
函数名：SVGA_Circle
返回值：返回0表示成功，返回其他值表示执行失败
参数：int x,int y,int r,int color   分别表示圆心坐标，半径，填充颜色
*******************/

int SVGA_Circle(int x,int y,int r,int color)
{
 
    int i,j;              //循环变量

    if(x-r<0||x+r>1023||y-r<0||y+r>767)//检查输入的合法性
    {
        return 1;                      //输入非法则返回1
    }
    for(i=0;i<=r;i++)
    {
        j=(int)(sqrt(r*r-i*i));          //计算横向循环次数
        for(;j>=0;j--)
        {
           	setpixel(x-i,y-j,color);      //每次画四个点，关于圆心对称
          	setpixel(x+i,y-j,color);
          	setpixel(x-i,y+j,color);
            	setpixel(x+i,y+j,color);
        }
    }
    return 0;                            //执行成功返回0
}
int getpixel(int x,int y)
{
  unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
  long pos=(y*1024L+x);
  unsigned int page=pos*2/65536L;
  selectpage(page);
  return(*((unsigned short far *)(video_buffer+pos)));
}

void CLOSE_SVGA_MODE(void)
{
	union REGS inregs,outregs;
	inregs.h.ah=0;
	inregs.h.al=(unsigned char)(0x03);
	int86(0x10,&inregs,&outregs);
}

void dark(int x1,int y1,int x2,int y2,int color)
{
    int x,y;
    unsigned int oldpage=0,newpage;
    unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
    long pos=(y*1024L+x);
    oldpage=pos*2/65536L;
    newpage=oldpage;
    selectpage(oldpage);
    for(x=x1;x<x2;x++)
    {
		for(y=y1;y<y2;y++)
		{
			pos=(y*1024L+x);
			newpage=pos*2/65536L;
			if(newpage!=oldpage)
			{
				selectpage(newpage);
				oldpage=newpage;
			}
			*((unsigned short far *)(video_buffer+pos))=color;
		}
	}
}

/*在SVGA条件下，实现贴图功能*/
void pic_show(int x,int y,char *filename)
{
 int i,j;
 FILE *fp;
 long Width,Height,oldpage,newpage;
 unsigned long position;
 short far *buffer;
 short far *video_buffer=(short far *)0xA0000000L;


 if((fp=fopen(filename,"rb"))==NULL)
	{
		SET_SVGA_MODE(0x03);
		printf("Cannot install image\n%s",filename);
		getch();
		exit(0);
	}
	fseek(fp,18,SEEK_SET);
	fread(&Width,sizeof(long),1,fp);
	fread(&Height,sizeof(long),1,fp);
	buffer=(short far*)malloc(Width*2);

	if(buffer==NULL)
	{
		SET_SVGA_MODE(0x03);
		printf("malloc error!");
		getch();
		return;
	}
	fseek(fp,70,SEEK_SET);
	oldpage=((Height-1+y)*(long)1024+x)*2/65536L;
	newpage=oldpage;
	selectpage(oldpage);

	for(i=Height-1;i>=0;i--)
	{
		fread(buffer,Width*2,1,fp);

		for(j=0;j<Width;j++)
		{
			position=((i+y)*(long)1024+j+x);
			newpage=position*2/65536;
			if(newpage!=oldpage)
			{
				selectpage(newpage);
				oldpage=newpage;
			}
		*(video_buffer+(i+y)*1024+x+j)=buffer[j];
		}
	}
	fclose(fp);
	free(buffer);
}


void pic_show_xor(int x,int y,char *filename)
{
 int i,j;
 FILE *fp;
 long Width,Height,oldpage,newpage;
 unsigned long position;
 short far *buffer;
 short far *video_buffer=(short far *)0xA0000000L;

 if((fp=fopen(filename,"rb"))==NULL)
	{
		SET_SVGA_MODE(0x03);
		printf("Cannot install image\n%s",filename);
		getch();
		exit(0);
	}
	fseek(fp,18,SEEK_SET);
	fread(&Width,sizeof(long),1,fp);
	fread(&Height,sizeof(long),1,fp);
	buffer=(short far*)malloc(Width*2);

	if(buffer==NULL)
	{
		SET_SVGA_MODE(0x03);
		printf("malloc error!");
		getch();
		return;
	}
	fseek(fp,70,SEEK_SET);
	oldpage=((Height-1+y)*(long)1024+x)*2/65536L;
	newpage=oldpage;
	selectpage(oldpage);

	for(i=Height-1;i>=0;i--)
	{
		fread(buffer,Width*2,1,fp);

		for(j=0;j<Width;j++)
		{
			position=((i+y)*(long)1024+j+x);
			newpage=position*2/65536;
			if(newpage!=oldpage)
			{
				selectpage(newpage);
				oldpage=newpage;
			}
			if(buffer[j]!=0x0000)
			{
			*(video_buffer+(i+y)*1024+x+j)=buffer[j];
			}
		}
	}
	fclose(fp);
	free(buffer);
}

