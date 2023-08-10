#include<stdio.h>
#include<conio.h>
#include<string.h>

FILE * fileopen(char* file_name)
{
	FILE *fp = NULL;
	fp = fopen(file_name,"r");
	return fp;
}
FILE * fileopen_write(char* file_name)
{
	FILE *fp = NULL;
	fp = fopen(file_name,"a");
	return fp;
}
void read_file_data(FILE *fp)
{
	char data[1000];
	int counter = 0;
	while(fgets(data,1000,fp))
	{
		int len, len1;
		char *token, temp[26];
		token = strtok(data,",\n");
		counter += 1;
		len = strlen(token);
		len1 = 26 - len;
		strcpy(temp,"");
		strcpy(temp,token);
		while(len1)
		{
			strcat(temp," ");
			len1--;
		}
		printf("%s",temp);
		while(token != NULL)
		{
			token = strtok(NULL,",\n");
			if(token != NULL)
			{
				len = strlen(token);
				len1 = 26 - len;
				strcpy(temp,"");
				strcpy(temp,token);
				while(len1)
				{
					strcat(temp," ");
					len1--;
				}
				printf("%s",temp);
			}
		}
		if(counter == 1) 
			printf("%s","\n");
		printf("%s","\n");
	}
}
void show_password(char* pwd)
{
	int p = 0;
	do
	{
		pwd[p] = getch();
		if(pwd[p] != '\r')
			printf("*");
		p++;
	}while(pwd[p-1] != '\r');
	pwd[p-1] = '\0';
}