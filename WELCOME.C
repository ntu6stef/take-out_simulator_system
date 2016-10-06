#include "WELCOME.H"

void welcome(int *flag)
{
	pic_show(0,0,"jiemian\\kongbai.bmp");
	pic_show(480,360,"jiemian\\welcome7.bmp");
	delay(10);
	pic_show(416,312,"jiemian\\welcome6.bmp");
	delay(10);
	pic_show(384,288,"jiemian\\welcome5.bmp");
	delay(10);
	pic_show(320,240,"jiemian\\welcome4.bmp");
	delay(10);
	pic_show(256,192,"jiemian\\welcome3.bmp");
	delay(10);
	pic_show(128,96,"jiemian\\welcome2.bmp");
	delay(10);
	pic_show(0,0,"jiemian\\welcome1.bmp");
	delay(1000);
	*flag=1;
}