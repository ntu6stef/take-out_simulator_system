#include "BUILD.H"

int readxx(struct customer *xinxi)                  //读取用户信息
{
    char fileName[20] = "user\\";                     //获得文件的路径
	char temp[20];
	FILE *xx;
	strcpy(temp,xinxi->number);
	strcat(temp, ".txt");
	strcat(fileName, temp);
	if((xx = fopen(fileName,"rt"))==NULL)
	{
		printf("  ");
	}
	if(access(fileName, 0) != 0)//如果文件不存在
	{
	     pic_show(0,0,"jiemian\\wrong1.bmp");       //该帐号不存在
	     delay(3000);
		 return 0;
	}
	else
	{
	    fscanf(xx, "%s", xinxi->number);
	    fscanf(xx, "%s", xinxi->key);
	    fscanf(xx, "%s", xinxi->name);
	    fscanf(xx, "%s", xinxi->sex);
		fscanf(xx, "%s", xinxi->adress);
		fscanf(xx, "%s", xinxi->food[0]);
		fscanf(xx, "%s", xinxi->food[1]);
		fscanf(xx, "%s", xinxi->food[2]);
		fscanf(xx, "%s", xinxi->food[3]);
		fscanf(xx, "%s", xinxi->food[4]);
		fscanf(xx, "%s", xinxi->food[5]);
		fscanf(xx, "%s", xinxi->food[6]);
		fscanf(xx, "%s", xinxi->food[7]);
		fscanf(xx, "%s", xinxi->food[8]);
		fscanf(xx, "%s", xinxi->food[9]);
		fscanf(xx, "%s", xinxi->food[10]);
		fscanf(xx, "%s", xinxi->food[11]);
		fscanf(xx, "%s", xinxi->food[12]);
		fscanf(xx, "%s", xinxi->food[13]);
		fscanf(xx, "%s", xinxi->food[14]);
		fscanf(xx, "%s", xinxi->food[15]);
		fscanf(xx, "%s", xinxi->food[16]);
		fscanf(xx, "%s", xinxi->food[17]);
	    fclose(xx);
	    delay(200);
	    return 1;
	}

}
