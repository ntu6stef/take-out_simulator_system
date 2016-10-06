#include "BUILD.H"

/* the function that judge if a file with the given name has existed in user*/
int unique1(char *s1)
{
	FILE *fp;
	char f_name[30]="users\\";			//save the whole file name
	char temp[20];
	strcpy(temp,s1);
	strcat(temp,".txt");			//add the suffix
	strcat(f_name,temp);			//add the prefix
	if (!access(f_name,00))				//access with the parament 00 check if the file have existed
	{
		return 1;			//the accoutn has existed
	}
	else
	{
		return 0;			//the account not exist
	}

}

/* the function that judge if a file with the given name has existed in admin*/
int unique2(char *s1)
{
	FILE *fp;
	char f_name[30]="admin\\";			//save the whole file name
	char temp[20];
	strcpy(temp,s1);
	strcat(temp,".txt");			//add the suffix
	strcat(f_name,temp);			//add the prefix
	if (!access(f_name,00))				//access with the parament 00 check if the file have existed
	{
		return 1;			//the accoutn has existed
	}
	else
	{
		return 0;			//the account not exist
	}

}

void read1(struct user *p_use)
{
	FILE *fp;
	char f_name[30]="users\\";
	char temp[20];
	strcpy(temp,p_use->number);
	strcat(temp,".txt");
	strcat(f_name,temp);			//get the whole file name
	if((fp=fopen(f_name,"rt"))==NULL)
	{
		printf("error when read a file");
	}
	else
	{
		fscanf(fp, "%s", p_use->number);
		fscanf(fp, "%s", p_use->key);
	}
}
void read2(struct admin *p_root)
{
	FILE *fp;
	char f_name[30]="admin\\";
	char temp[20];
	strcpy(temp,p_root->number);
	strcat(temp,".txt");
	strcat(f_name,temp);			//get the whole file name
	if((fp=fopen(f_name,"rt"))==NULL)
	{
		printf("error when read a file");
	}
	else
	{
		fscanf(fp, "%s", p_root->number);
		fscanf(fp, "%s", p_root->key);
	}
}


/* newly build a file to save a new customer' info */
void build1(struct user newer)
{
	FILE *fp;
	char f_name[30]="users\\";
	char temp[20];
	strcpy(temp,newer.number);
	strcat(temp,".txt");
	strcat(f_name,temp);			//get the whole file name
	if((fp=fopen(f_name,"wt"))==NULL)
	{
		printf("error when newly build a file");
	}
	else
	{
		fprintf(fp,"%s %s",newer.number,newer.key);			//save the new customer'info into the file
		fclose(fp);
	}
}
