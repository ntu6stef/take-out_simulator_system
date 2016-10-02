
#include "MOUSE.H"

int MousePixSave[16][16];
int MouseDraw[16][10]={
	{1,1,3,3,3,3,3,3,3,3},
	{1,2,1,3,3,3,3,3,3,3},
	{1,2,2,1,3,3,3,3,3,3},
	{1,2,2,2,1,3,3,3,3,3},
	{1,2,2,2,2,1,3,3,3,3},
	{1,2,2,2,2,2,1,3,3,3},
	{1,2,2,2,2,2,2,1,3,3},
	{1,2,2,2,2,2,2,2,1,3},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,2,2,2,2,2,1,3,3},
	{1,2,2,2,2,2,1,3,3,3},
	{1,2,1,3,1,2,2,1,3,3},
	{1,1,3,3,1,2,2,1,3,3},
	{3,3,3,3,3,1,2,2,1,3},
	{3,3,3,3,3,1,2,2,1,3},
	{3,3,3,3,3,3,1,2,2,1}
};

int Mouse_init(int wid,int hei)
{
	union REGS regs;
	int retcode,xmin=0,ymin=0,xmax=wid-11,ymax=hei-20;
	regs.x.ax=0;
	int86(0x33,&regs,&regs);
	retcode=regs.x.ax;
	if(retcode==0)
		return 0;
	regs.x.ax=4;
	regs.x.cx=0;
	regs.x.dx=0;

	regs.x.ax=7;
	regs.x.cx=xmin;
	regs.x.dx=xmax;
	int86(0x33,&regs,&regs);

	regs.x.ax=8;
	regs.x.ax=8;
	regs.x.cx=ymin;
	regs.x.dx=ymax;
	int86(0x33,&regs,&regs);
	return retcode;
}

void Mouse_cpy(int x,int y)  /*鼠标区域背景扣取*/
{
	int i,j;
	unsigned long pos;
    int oldpage,newpage;
    short far *video_buffer=(short far *)0xA0000000L;
    oldpage=(y*1024L+x)/32768;
    newpage=oldpage;
    selectpage(newpage);
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			pos=(i+y)*(1024L)+j+x;
            newpage=pos/32768;
            if(oldpage!=newpage)
            {
                selectpage(newpage);
                oldpage=newpage;
            }
            MousePixSave[i][j]=video_buffer[pos%65536];
		 }
	}
}

void Mouse_reshow(int x,int y)/*鼠标扣取背景重现*/
{
    int i,j;
    int oldpage,newpage;
    unsigned long pos;
    short far *video_buffer=(short far *)0xA0000000L;
    oldpage=(y*(1024L)+x)/32768;
    newpage=oldpage;
    selectpage(oldpage);
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			pos=(i+y)*(1024L)+j+x;
            newpage=pos/32768;
            if(oldpage!=newpage)
            {
                selectpage(newpage);
                oldpage=newpage;
            }
            video_buffer[pos%65536]=MousePixSave[i][j];
		}
	}
}

void Mouse_show(int x,int y)  /*鼠标显示*/
{
    int i,j;
    int oldpage,newpage;
    unsigned long pos;
    short far *video_buffer=(short far *)0xA0000000L;
    oldpage=(y*(1024L)+x)/32768;
    newpage=oldpage;
    selectpage(oldpage);
	for(i=0;i<16;i++)
	{
		for(j=0;j<10;j++)
		{
			pos=(i+y)*1024L+j+x;
            		newpage=pos/32768;
            		if(oldpage!=newpage)
            	{
                	selectpage(newpage);
                	oldpage=newpage;
            	}
			if(MouseDraw[i][j]==1)
                		video_buffer[pos%65536]=0x5678;
			else if(MouseDraw[i][j]==2)    /* 画鼠标*/
                		video_buffer[pos%65536]=0xf352;
		}
	}
	delay(15);
}

void Mouse_read(int *mouse_x,int *mouse_y,int *mouse_butt)/*读鼠标的位置和按钮状态*/
{
	union REGS inregs,outregs;
	inregs.x.ax=3;
	int86(0x33,&inregs,&outregs);
	*mouse_x=outregs.x.cx;
	*mouse_y=outregs.x.dx;
	*mouse_butt=outregs.x.bx;
}


