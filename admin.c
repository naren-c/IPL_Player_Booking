#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "file_operations.h"

void auction_pool()
{
	system("cls");
	FILE *fp = NULL;
	fp = fopen("IPL_Players_Pool.csv","r");
	if(fp == NULL)
		printf("Error in opening the file");
	else
	{
		system("cls");
		read_file_data(fp);
	}
	fclose(fp);
}
void team_details_code(char *filename1, char *filename2)
{
	FILE *fp = NULL;
	char data[1000];
	int team_details_choice;
	while(1)
	{
		system("cls");
		printf(" CHOOSE OPTION \n\n 1 VIEW TEAM PLAYER DETAILS\n 2 VIEW TEAM BUDGET\n 3 EXIT\n ");
		printf("\nYour choice: ");
		scanf("%d",&team_details_choice);
		system("cls");		
		if(team_details_choice == 1)
		{
			fp = fileopen(filename1);
			if(fp != NULL)
				read_file_data(fp);
			fclose(fp);
		}
		else if(team_details_choice == 2)
		{
			fp = fileopen(filename2);
			if(fp != NULL)
				read_file_data(fp);
			fclose(fp);
		}
		else if(team_details_choice == 3)
			break;
		else
			printf("Invalid option choosen. Please try again");
		printf("\n\n\nTo go back to admin menu press the key 'b' "); 
		while(1)
		{
			char option;
			scanf("%c",&option);
			if(option == 'b' || option == 'B')
				break;
		}
	}
}
void team_details()
{
	char team_choice[50];
	system("cls");
	printf("Pick a team to view details: ");
	scanf("%s",&team_choice);
	printf("\n\n");
	if(strcmp("RCB",team_choice)==0 || strcmp("rcb",team_choice)==0 )
		team_details_code("rcb_team_details.csv","rcb_budget.csv");
	else if(strcmp("MI",team_choice)==0 || strcmp("mi",team_choice)==0)
		team_details_code("mi_team_details.csv","mi_budget.csv");
	else if(strcmp("CSK",team_choice)==0 || strcmp("csk",team_choice)==0)
		team_details_code("csk_team_details.csv","csk_budget.csv");
	else if(strcmp("DC",team_choice)==0 || strcmp("dc",team_choice)==0)
		team_details_code("dc_team_details.csv","dc_budget.csv");
	else
		printf("Incorrect team name. Please try again");
}
void start_bidding()
{
	FILE *fp= NULL;
	char data[1000], *token, *token1;
	int count = 0;
	fp = fopen("IPL_Players_Pool.csv","r");
	if(fp == NULL)
		printf("Error in opening the file");
    else 
	{
		while(fgets(data,1000,fp))
		{
			if(count == 0)
			{
				count++;
				continue;
			}
			token = strtok(data,",\n");
			for(int i=1;i<=4;i++)			
				strtok(NULL,",");
			token1 = strtok(NULL,",");	
			printf("Player Name : %s\nStarting Bidding Price : %sCR",token,token1);
			char team[10],choice;
			int prev_price,cur_price;
			prev_price = *token1;
			//printf(typeof(prev_price));
			while(1)
			{
				fflush(stdin);
				printf("\nTeam who wants to bid : ");
				scanf("%s",&team);
				printf("Bidding amount : ");
				scanf("%d",&cur_price);
				//if(cur_price<prev_price)
					//printf("Bid entered is lower than previous bid");
				//else
					prev_price = cur_price;
				fflush(stdin);
				printf("\nAny more bids? : ");
				scanf("%c",&choice);
				if(choice == 'y' || choice == 'Y')
				{
					continue;
				}
				else
				{
					printf("\n%s is part of %s team\n",token,team);
					FILE *fp1;
					if(strcmp("rcb",team)==0)
					{
						//printf("%s","here");
						fp1 = fileopen_write("rcb_team_details.csv");
						if(fp1 != NULL) 
						{
							/*while(!feof(fp1))
								fprintf(fp1,"%s %s",token,cur_price);*/
							//int c = fprintf(fp1,"%s\n","naren");
							//printf("%d\n", c);
							fclose(fp1);
						}
						else
							printf("%s", "error");
					}
					break;
				}
			}
			break;
		}
		fclose(fp);
	}
	
}
void bidding()
{
	int choice;
	while(1)
	{
		system("cls");
		printf("\t\t\t\t\t\tWELCOME TO THE BIDDING PAGE\n\n\n");
		printf(" 1 START BIDDING\n 2 EXIT\n");
		printf("\nYour choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: start_bidding();
					break;
			case 2: printf("To go back to main page press the key 'b' "); 
					return;
			default: printf("\nInvalid choice entered. Please try again, press the key 'b' to go back to admin menu ");
					 char option;
					 scanf("%c",&option);
					 if(option == 'b' || option == 'B')
						continue;
		}
		printf("\n\n\nTo go back to admin menu press the key 'b' "); 
		while(1)
		{
			char option;
			scanf("%c",&option);
			if(option == 'b' || option == 'B')
				break;
		}
	}
}
void admin_menu()
{
	int choice;
	while(1)
	{
		system("cls");
		printf("\t\t\t\t\t\tWELCOME TO ADMIN PAGE\n\n\n");
		printf(" 1 AUCTION POOL\n 2 TEAM DETAILS\n 3 PLAYERS BIDDNG\n 4 EXIT\n");
		printf("\nYour choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: auction_pool();
					break;
			case 2: team_details();
					break;
			case 3: bidding();
					break;
			case 4: printf("To go back to main page press the key 'b' "); 
					return;
			default: printf("\nInvalid choice entered. Please try again, press the key 'b' to go back to admin menu ");
					 char option;
					 scanf("%c",&option);
					 if(option == 'b' || option == 'B')
						continue;
		}
		printf("\n\n\nTo go back to admin menu press the key 'b' "); 
		while(1)
		{
			char option;
			scanf("%c",&option);
			if(option == 'b' || option == 'B')
				break;
		}
	}
}
void admin()
{
	char admin_username[20],pwd[20],valid_username[20],valid_pwd[20];
	strcpy(valid_username,"ipladmin");
	strcpy(valid_pwd,"admin123");
	while(1)
	{
		printf("Username: ");
		scanf("%s",&admin_username);
		printf("Password: ");
		show_password(pwd);
		if(strcmp(admin_username, valid_username)==0 && strcmp(pwd, valid_pwd)==0)
		{
			admin_menu();
			break;
		}
		else if(!(strcmp(admin_username, valid_username)==0 && strcmp(pwd, valid_pwd)==0))
			printf("\nInvalid username or password entered. Please try again\n\n");
		else 
			break;
	}
}