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
				subscriber=login(&flag,subscriber);     //for users log in
				break;
			case 2:
				//login2(&flag);				//for administer log in
				break;
			case 3:
				//regist(&flag);			//for user regist
				break;
			case 4:
			   //cafe(&flag,subscriber);			//for user choose cafe
				break;
			case 5:
				//snack(&flag,subscriber);			//for user choose snack
				break;
			case 6:
				//checkout(&flag,subscriber);				//for user check out
				break;
			case 7:
				//history(&flag,subscriber);				//for user see the history order
				break;
			case 8:
				//manage(&flag);				//for administer manage the user
				break;
			case 9:
				//count(&flag);			//for administer see the statistics of goods
				break;
			case 10:
				//help(&flag);			//for user see how the program work
				break;
			case 15:
				//end(&flag);				//the end
				break;
		}
	}
}