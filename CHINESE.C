#include "CHINESE.H"


FILE *hzk_p;
char mat0[32],mat1[72],mat2[128],mat3[288];

void chinese(int x,int y,char *s,int color,int type,char ziti)//x,y 输出位置  字符组 颜色 大小 字体 
{
	int a=x;
	switch(type)
	{
		case 16:
			switch(ziti)
			{
				case 'F':
					open_hzk("hzk\\HZK16F");
					break;
				case 'H':
					open_hzk("hzk\\HZK16H");
					break;
				case 'K':
					open_hzk("hzk\\HZK16K");
					break;
				case 'S':
					open_hzk("hzk\\HZK16S");
					break;
			 }
			 break;
		case 24:
			switch(ziti)
			{
				case 'F':
					open_hzk("hzk\\HZK24f");
					break;
				case 'H':
					open_hzk("hzk\\HZK24h");
					break;
				case 'K':
					open_hzk("hzk\\HZK24k");
					break;
				case 'S':
					open_hzk("hzk\\HZK24s");
					break;
			 }
			 break;
		case 32:
			switch(ziti)
			{
				case 'F':
					open_hzk("hzk\\HZK32F");
					break;
				case 'H':
					open_hzk("hzk\\HZK32H");
					break;
				case 'K':
					open_hzk("hzk\\HZK32K");
					break;
				case 'S':
					open_hzk("hzk\\HZK32S");
					break;
			 }
			 break;
		case 48:
			switch(ziti)
			{
				case 'F':
					open_hzk("hzk\\HZK48F");
					break;
				case 'H':
					open_hzk("hzk\\HZK48H");
					break;
				case 'K':
					open_hzk("hzk\\HZK48K");
					break;
				case 'S':
					open_hzk("hzk\\HZK48S");
					break;
			 }
			 break;
	}
	while (*s!=NULL)
	{
		while (x<1024 && (*s!=NULL))
		{
			dishz(x,y,s,color,type);
			x+=(type+1);
			s+=2;
		}
	x=a;
	y+=(type+5);
	}
//	getch();
	fclose(hzk_p);
}
void open_hzk(char * path)
{
	hzk_p=fopen(path,"rb");
	if (!hzk_p)
	{
		printf("The HZK does not exist! press any key to half\n");
		getch();
		exit(1);
	}   
}
void get_hz(char incode[],char bytes[],int type)
{
	unsigned char qh,wh;
	unsigned long offset;
	unsigned long size;
	size=type*type/8;
	qh=incode[0]-0xa0; /*得到区号*/
	wh=incode[1]-0xa0; /*得到位号*/
	offset=(94*(qh-1)+(wh-1))*size; /*得到偏移位置*/
	fseek(hzk_p,offset,SEEK_SET); /*移文件指针到要读取的汉字字模处*/
	fread(bytes,size,1,hzk_p); /*读取32 个汉字的汉字字模*/
}
void dishz(int x0,int y0,char code[],int color,int type)
{
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
/*屏蔽字模每行各位的数组*/
	int i,j,x,y,pos;
	int t;
	switch(type)
	{
		case 16:
			get_hz(code,mat0,type);
			y=y0;
			for (i=0;i<type;++i)
			{
				x=x0;
				pos=type/8*i;
				for(j=0;j<type;++j)
				{
/*屏蔽出汉字字模的一个位，即一个点是1 则显示，否则不显示该点*/
					if ((mask[j%8]&mat0[pos+j/8])!=NULL)
					{
						setpixel(x,y,color);
					}
				++x;
				}
				++y;
			}
			break;
		case 24:
			get_hz(code,mat1,type);
			y=y0;
			for (i=0;i<type;++i)
			{
				x=x0;
				pos=type/8*i;
				for(j=0;j<type;++j)
				{
/*屏蔽出汉字字模的一个位，即一个点是1 则显示，否则不显示该点*/
					if ((mask[j%8]&mat1[pos+j/8])!=NULL)
					{
						setpixel(x,y,color);
					}
				++x;
				}
				++y;
			}
			break;
		case 32:
			get_hz(code,mat2,type);
			y=y0;
			for (i=0;i<type;++i)
			{
				x=x0;
				pos=type/8*i;
				for(j=0;j<type;++j)
				{
/*屏蔽出汉字字模的一个位，即一个点是1 则显示，否则不显示该点*/
					if ((mask[j%8]&mat2[pos+j/8])!=NULL)
					{
						setpixel(x,y,color);
					}
				++x;
				}
				++y;
			}
			break;
		case 48:
			get_hz(code,mat3,type);
			y=y0;
			for (i=0;i<type;++i)
			{
				x=x0;
				pos=type/8*i;
				for(j=0;j<type;++j)
				{
/*屏蔽出汉字字模的一个位，即一个点是1 则显示，否则不显示该点*/
					if ((mask[j%8]&mat3[pos+j/8])!=NULL)
					{
						setpixel(x,y,color);
					}
				++x;
				}
				++y;
			}
			break;
	}

}

void Read_Asc16(char key,unsigned char *buf)
{
   int handle;
   long address;
   handle=open("hzk\\asc16",O_RDONLY|O_BINARY);
   address=key*16l;
   lseek(handle,address,SEEK_SET);
   read(handle,buf,16);
   close(handle);
}

void Put_Asc16(int cx,int cy,char key,int fcolor)
{
   int a,b;
   unsigned char buf[16];
   Read_Asc16(key,buf);
   for(a=0;a<16;a++)
   for(b=0;b<8;b++)
   if((buf[a]>>7-b)&1)
   setpixel(cx+a,cy+b,fcolor);
}

void Put_Asc16_Size(int cx,int cy,int xsize,int ysize,char key,int fcolor)
{
	int a,b,o,k;
	unsigned char buf[16];
	Read_Asc16(key,buf);
	for(a=0;a<16;a++)
		for(o=1;o<=ysize;o++)
			for(b=0;b<8;b++)
				for(k=1;k<=xsize;k++)
					if((buf[a]>>7-b)&1)
				   setpixel(cx+b*xsize+k,cy+o+a*ysize,fcolor);
}
/* 显示英文和数字 */
void put_asc(int cx,int cy,int xsize,int ysize,char *s,int color )
{
    int index;
    for(index=0;s[index]!=0;index++)
    {
		Put_Asc16_Size(cx+index*xsize*8,cy,xsize,ysize,s[index],color);
    }
}