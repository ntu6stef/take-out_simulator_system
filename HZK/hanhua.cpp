#include "hanhua.h"


void hanhua(int row,int col,int x ,int y,int color ,char *s)
{

   FILE *fp;
   char buffer[32]; //buffer用来存储一个汉字
	register m,n,i,j,k;
	unsigned char qh,wh;
	unsigned long offset;

	  if ((fp=fopen("hzk16","rb"))==NULL)//打开汉字库，该字库可以在UCdos中找到
	  {
		printf("Can't open haz16,Please add it");
		getch();
			exit(0);
	 }

	  while(*s)
	{ qh=*(s)-0xa0; //汉字区位码
	  wh=*(s+1)-0xa0;
	  offset=(94*(qh-1)+(wh-1))*32L;
	  fseek(fp,offset,SEEK_SET);
	  fread(buffer,32,1,fp);
	  for (i=0;i<16;i++)
	   for(n=0;n<row;n++)
		for(j=0;j<2;j++)
		 for(k=0;k<8;k++)
		  for(m=0;m<col;m++)
		   if (((buffer[i*2+j]>>(7-k))&0x1)!=NULL)
			putpixel(x+8*j*col+k*col+m,y+i*row+n,color);
			s+=2;
			x+=30;

		  }

}

void show_hanzi (int x, int y,char *s,int flag,int part,int color)
{
	     FILE *hzk_p;                                       //定义汉字库文件指针
	     unsigned char quma,weima;                 //定义汉字的区码和位码
	     unsigned long offset;                          //定义汉字在字库中的偏移量
	     unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //功能数组，用于显示汉字点阵中的亮点
       int i,j,pos;

	     switch (flag)    //不同的flag对应不同的汉字库，实现了汉字的大小可根据需要改变
	      {
		         case 0 :
				       {
					           char mat[32];   //16*16的汉字需要32个字节的数组来存储
					           int y0=y;
				             hzk_p = fopen("C:\\TC30]\hzk\\hzk16","rb");            //使用相对路径
					             if(hzk_p==NULL)
				               	 {
					                   	outtextxy(10,10,"Can't open hzk16 file!Press any key to quit...");
						                 getch();
						                 exit(1);

				                	}
					          while(*s!=NULL)
					          {
						
							             y=y0;
						          	  quma=s[0]-0xa0;                      //求出区码
						             	weima=s[1]-0xa0;                     //求出位码
							            offset=(94*(quma-1)+(weima-1))*32L;   //求出要显示的汉字在字库文件中的偏移
						            	fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
							            fread (mat,32,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

						            	for(i=0;i<16;i++)
							             {
								                pos=2*i;       //16*16矩阵中有每一行有两外字节
							                 	for(j=0;j<16;j++)    //一行一行地扫描，将位上为了1的点显示出来
								                     {
									                       if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									                          {
									                              	putpixel(x+j,y,color);

									                          }

							                     	}
								                   y++;


						               	}
							/*====================================================
								以上是一个汉字显示完
							====================================================*/
							              x+=part;        //给x 一个偏移量part
							              s+=2;           //汉字里存放的是内码，2个字节，所以要加2

				
						        }

					          break;

				       }


		            case 1 :
				          {
					             char mat[72];   //24*24矩阵要72个字节来存储
					             int y0=y;
					             hzk_p = fopen("C:\\TC30\\hzk\\HZK24k","rb");
				            	 if (hzk_p==NULL)
					             {
					                 	outtextxy(10,10,"Can't open hzk24 file!Press any key to quit...");
						                getch();
						                exit(1);

					             }
					            while(*s!=NULL)
					              {
						
						             	y=y0;
							            quma=s[0]-0xa0;                      //求出区码
							            weima=s[1]-0xa0;                     //求出位码
							            offset=(94*(quma-1)+(weima-1))*72L;
						             	fseek(hzk_p,offset,SEEK_SET);
						             	fread (mat,72,1,hzk_p);
					             		for (i=0;i<24;i++)
							              {
								                    pos=3*i;   //矩阵中每一行有三个字节
								                    for (j=0;j<24;j++)   // 每一行有24位
								                      {
								                       	if ((mask[j%8]&mat[pos+j/8])!=NULL)
									                     	putpixel(x+j,y,color);

								                      }
								                 y++;

						               	}
						            	x+=part;
							            s+=2;
						              //}
					               	//x=35;y0=y0+40;
				               	}
						          break;
			           	}

		             case 2 :
				           {
					               char mat[128];   //32*32的汉字需要128个字节的数组来存储
					               int y0=y;
					               hzk_p = fopen("C:\\TC30\\hzk\\hzk32k","rb");
					               if(hzk_p==NULL)
					                   {
						                    outtextxy(10,10,"Can't open hzk32 file!Press any key to quit...");
						                    getch();
						                    exit(1);

					                   }
				                 	while(*s!=NULL)
					                 {
					                      	//while (x<620 && (*s!=NULL))
						                       //{
						                    	y=y0;
							                    quma=s[0]-0xa0;                      //求出区码
							                    weima=s[1]-0xa0;                     //求出位码
						                    	offset=(94*(quma-1)+(weima-1))*128L;
						                    	fseek(hzk_p,offset,SEEK_SET);
							                    fread (mat,128,1,hzk_p);
							                    for(i=0;i<32;i++)
						 	                     {
							                          	pos=4*i;       //32*32矩阵中有每一行有两外字节
							                          	for(j=0;j<32;j++)
							                            	{
									                                  if((mask[j%8]&mat[pos+j/8])!=NULL)
									                                   {
									                                          	putpixel(x+j,y,color);

									                                    }

								                            }
								                       y++;


							                     }
							                   	//以上是一个汉字显示完
							                   x+=part;    //给x 一个偏移量part
							                   s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						                      //}
					                       	//x=50;y0=y0+60;   //一行汉字显示完后，给y一个偏移量
				                  	}
						                break;

				            }


		                case 3:
				               {
					                  char mat[288];   //48*48的汉字需要288个字节的数组来存储
					                  int y0=y;
					                  hzk_p = fopen("C:\\TC30\\HZK\\HZK48k","rb");
				                   if(hzk_p==NULL)
					                  {
					                    	outtextxy(10,10,"Can't open hzk48 file!Press any key to quit...");
						                    getch();
						                     exit(1);

			                   		}
					                   while(*s!=NULL)
				                      	{
					                    	//while (x<620 && (*s!=NULL))
					                     	//{
					                        		y=y0;
					                        		quma=s[0]-0xa0;                      //求出区码
							                        weima=s[1]-0xa0;                     //求出位码
							                        offset=(94*(quma-1)+(weima-1))*288L;   //求出要显示的汉字在字库文件中的偏移
							                        fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
						                        	fread (mat,288,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

							                        for(i=0;i<48;i++)
							                         {
							                                	pos=6*i;
							                                	for(j=0;j<48;j++)    //一行一行地扫描，将位上为了1的点显示出来
						                                  		{
						                                        			if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									                                        {
										                                            putpixel(x+j,y,color);

									                                         }

								                                  }
								                            y++;
							                         }
								                         //以上是一个汉字显示完
						                     	x+=part;    //给x 一个偏移量part
						                     	s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						                       //}
						                      //x=70;y0+=90;   //一行汉字显示完后，给y一个偏移量
					                      }
						                      break;

				                }

		               default:
				           break;

	      }

	fclose(hzk_p);
}