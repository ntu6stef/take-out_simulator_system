/*the entry of the program*/

#include "MAIN.H"

void main()
{
	int flag=0;                //interface jump parameter
	char *subscriber;		   //point to username
	SET_SVGA_MODE(0x117);		//initialize the picture system
	Mouse_init(1024,768);		//initialize the mouse system

	while(1)					//loop all the time to observe the value of 'flag' until you press 'ESC'
	{
		switch(flag)
		{
			case 0:
				welcome(&flag);         //welcome interface which is set to entry first
				break;
			case 1:
				subscriber=login(&flag,subscriber);     //
				break;
			case 2:
				regist(&flag);
				break;
		}
	}
}