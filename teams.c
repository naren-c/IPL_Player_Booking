#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "file_operations.h"

int menu()
{
	int option;
	printf(" CHOOSE OPTION \n\n 1 TO SHOW PLAYER DETAILS\n 2 TO SHOW BUDGET\n 3 EXIT\n\n ");
	printf("Your choice: ");
	scanf("%d",&option);
	return option;
}
void readTeamDetails(char *filename1, char *filename2,char *teamname)
{
	int option;
	FILE *fp = NULL;
	char data[1000];
	while(1)
	{
		system("cls");
		char msg[100] = "WELCOME TO TEAM ";
		char msg1[100];
		strcat(msg,teamname);
		printf("\t\t\t\t %s\n\n\n",msg);
		option = menu();
		system("cls");
		if(option==1)
		{
			fp = fileopen(filename1);
			if(fp != NULL)
				read_file_data(fp);
			fclose(fp);
		}
		else if(option == 2)
		{
			fp = fileopen(filename2);
			if(fp != NULL)
				read_file_data(fp);
			fclose(fp);
		}
		else if(option == 3)
		{
			printf("\n\n\nTo go back to admin menu press the key 'b' "); 
			break;
		}
		else
		{
			printf("\nInvalid choice entered. Please try again, press the key 'b' to go back to main menu ");
			char option;
			scanf("%c",&option);
			if(option == 'b' || option == 'B')
				continue;
		}
		printf("\n\n\nTo go back to admin menu press the key 'b' "); 
		while(1)
		{
			char back;
			scanf("%c",&back);
			if(back == 'b' || back == 'B')
				break;
		}
	}
}
void teams()
{
	char rcb_username[20], mi_username[20], csk_username[20], dc_username[20];
	char team_username[20];
	char rcb_pwd[20], mi_pwd[20], csk_pwd[20], dc_pwd[20];
	char pwd[20];
	strcpy(rcb_username,"royalchallengersbangalore");
	strcpy(mi_username,"mumbaiindians");
	strcpy(csk_username,"chennaisuperkings");
	strcpy(dc_username,"delhicapitals");
	strcpy(rcb_pwd,"rcb123");
	strcpy(mi_pwd,"mi123");
	strcpy(csk_pwd,"csk123");
	strcpy(dc_pwd,"dc123");
	while(1)
	{
		printf("\nUsername: ");
		scanf("%s",&team_username);
		printf("Password: ");
		show_password(pwd);
		if(strcmp(team_username,rcb_username)==0 && strcmp(pwd,rcb_pwd)==0)
		{
			readTeamDetails("rcb_team_details.csv", "rcb_budget.csv","ROYAL CHALLENGERS BANGALORE");
			break;
		}
		else if(strcmp(team_username,mi_username)==0 && strcmp(pwd,mi_pwd)==0)
		{
			readTeamDetails("mi_team_details.csv", "mi_budget.csv","MUMBAI INDIANS");
			break;
		}
		else if(strcmp(team_username,csk_username)==0 && strcmp(pwd,csk_pwd)==0)
		{
			readTeamDetails("csk_team_details.csv", "csk_budget.csv","CHENNAI SUPER KINGS");
			break;
		}
		else if(strcmp(team_username,dc_username)==0 && strcmp(pwd,dc_pwd)==0)
		{
			readTeamDetails("dc_team_details.csv", "dc_budget.csv","DELHI CAPITALS");
			break;
		}
		else 
			printf("Invalid username or password entered. Please try again\n");
	}
}