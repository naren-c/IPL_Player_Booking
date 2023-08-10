#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#include "admin.h"
#include "teams.h"

int main()
{
	int login;
	while(1)
	{
		system("cls");
		printf("\t\t\tWELCOME TO THE IPL AUCTION POOL 2021!!!\n\n\n");
		printf(" 1 LOGIN AS THE ADMIN\n 2 LOGIN AS ONE OF THE TEAM\n 3 EXIT");
		printf("\n\nYour choice: ");
		scanf("%d",&login);
		switch(login)
		{
			case 1: admin();
					break;
			case 2: teams();
					break;
			case 3: return 0;
			default:
					printf("INVALID INPUT CHOSEN ");
		}
		while(1)
		{
			char option;
			scanf("%c",&option);
			if(option == 'b' || option == 'B')
				{
					break;
				}
		}
	}
	return 0;
}