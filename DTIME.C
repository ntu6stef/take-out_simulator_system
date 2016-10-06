#include "DTIME.H"

void dtime(int x, int y)			//show the date and time in graphics windows
{
	int i=0;
	int year,month,day,hour,minute,second;			//save the values of time in int
	char s[6][5];			//save the values of time in char
	
	struct date d;			//call the struct date from dos.h
	struct time t;			//call the struct time from dos.h
	getdate(&d);
	itoa(d.da_year,s[0],10);
	itoa(d.da_mon,s[1],10);
	itoa(d.da_day,s[2],10);
	gettime(&t);
	itoa(t.ti_hour,s[3],10);
	itoa(t.ti_min,s[4],10);
	itoa(t.ti_sec,s[5],10);			//get the time and tranlate to string

	put_asc(x,y,1,1,s[0],0x0000);
	put_asc(x+50,y,1,1,s[1],0x0000);
	put_asc(x+100,y,1,1,s[2],0x0000);
	put_asc(x+150,y,1,1,s[3],0x0000);
	put_asc(x+200,y,1,1,s[4],0x0000);
	put_asc(x+250,y,1,1,s[1],0x0000);
}