// the input function is used to input account,password and etc. It returns a pointer which points to the inputted string.
#include "INPUT.H"
char *inputtext(int x,int y,int n,int m)//����ͬʱ����ĺ���  �����˺�
{
	int i=0,x1=x+2,y1=y+1;
	char j;
	char s[50]={0};//��������ַ�
//	setcolor(0x0000);
//	rectangle(x,y,x+210,y+50);
	while(1)
	{
		setcolor(0x0000);
		Vline(x1-1,y1,y1+45);//�������ʱ�ͻ�һ�����ߣ���꣩
		while(1)
		{
			if(kbhit()==0)//������δ����
			{       
				setcolor(0x0000);
			    Vline(x1-1,y1,y1+45);                                                       
				delay(200);
				setcolor(0xffff);
				Vline(x1-1,y1,y1+45);//δ����һֱ���ߣ�ʹ�����˸				
			}
            if(kbhit()!=0)//���м�������
			{
				j=getch();
				break;
			}
			delay(200);
		}
        if(j==Bksp)//ɾ��
		{
			if(x1>x+2)
			{
				i=i-1;
				x1=x1-20;
				dark(x1,y1,x1+22,y1+46,0xffff);//��ɾ����
				s[i]='\0';
    		 }
        }
        else if(j==Enter)
        {
			setcolor(0xffff);
			Vline(x1-1,y1,y1+45);
			break;
         }
        else if(i<n)
        {
			s[i]=j;
			s[i+1]='\0';
            setcolor(0xffff);
			Vline(x1-1,y1,y1+45);
			if(m==0)
				put_asc(x1,y1+6,2,2,&s[i],0x0000);//�������
			if(m==1)
				put_asc(x1,y1+6,2,2,"*",0x0000);//�������
			x1=x1+20;
            setcolor(0x0000);
			Vline(x1-1,y1,y1+45);
			i++;
		}
    }
	return s;
}

char *inputkey(int x,int y,int n,int m)                 //input the disvisiable data. n limits the amount of data. x,y define the location.
{
	int i=0,x1=x+2,y1=y+1;
	char j;
	char s[50]={0};
	setcolor(0x0000);
	rectangle(x,y,x+210,y+40);
	while(1)
	{
		setcolor(0x0000);
		Vline(x1-1,y1-1,y1+35);
		while(1)
		{
			if(kbhit()==0)//������δ����
			{            
				setcolor(0xffff);			              						  
				Vline(x1-1,y1,y1+35);
                delay(200);
				setcolor(0x0000);
				Vline(x1-1,y1,y1+35);				
			}
            if(kbhit()!=0)//���м�������
			{
				j=getch();
				break;
			}
			delay(200);
		}
        if(j==Bksp)//ɾ��
	    {
			if(x1>x+2)
			{
				i=i-1;
				x1=x1-20;
				dark(x1,y1,x1+22,y1+37,0xffff);
				s[i]='\0';
    		}
        }
        else if(j==Enter)
        {
			setcolor(0xffff);
			Vline(x1-1,y1,y1+35);
			break;
        }
        else if(i<n)
		{
			s[i]=j;
			s[i+1]='\0';
            setcolor(0xffff);
			Vline(x1-1,y1,y1+35);
			if(m==0)
				put_asc(x1,y1,2,2,&s[i],0x0000);
			if(m==1)
				put_asc(x1,y1,2,2,"*",0x0000);
			x1=x1+20;
            setcolor(0x0000);
			Vline(x1-1,y1-1,y1+35);
			i++;
		}
	}
	return s;
}