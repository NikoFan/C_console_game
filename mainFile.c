#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

char customer_name[] = "";
int customer_count;

void clear() // очистка терминала
{
	system("cls");
}

void user_registration() // регистрация пользователя в системе
{
	clear();
	char *name;
	int exit_value = 0;
	printf("Enter your name: ");
	
	scanf("%s", name);
	strcpy(customer_name, name);
	if (strcmp(customer_name, "") == 0)
	{
		printf("\tWARNING!!!\n  Please, set your name\n");
		sleep(2);
		user_registration();
	}
	printf("your new name: %s\n", customer_name);
	
	sleep(2);
}


void game()
{
	char game_place[11] = {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '\0'};
	int game_stop = 0;
	while (game_stop == 0)
	{
		
		for(int row = 0; row < 10; row++)
		{
			if (row == 3)
			{
				printf("%s\tplayer: %s\n", game_place, customer_name);
			} else if (row == 5)
			{
				printf("%s\tscore: %d\n", game_place, customer_count);
			} else
			{
				printf("%s\n", game_place);
			}
			
		}
		sleep(1);
		clear();
	}
	
}


void display_start_user_menu() // вывод стартового меню
{
	clear();
	char *customer_number_choice;
	int exit_value = 0;
	// выбор для пользователя
	
	while(exit_value == 0)
	{
		printf("Enter your choice:\n");
		printf("-1-Enter customer name. (your active name is: %s)\n", customer_name);
		printf("-2-Start game.\n");
		printf("-0-Exit.\n");
		printf("take number: ");
		scanf("%s", customer_number_choice);
		if (strcmp(customer_number_choice, "1") == 0) // проверка что введена 1
		{
			printf("Name enter\n");
			sleep(2);
			user_registration();
			printf("OK\n");
			
		} else if (strcmp(customer_number_choice, "2") == 0) // проверка что введена 2
		{
			if (strcmp(customer_name, "") == 0)
			{
				printf("\tWARNING!!!\n  Please, set your name\n");
				sleep(2);
			}
			else
			{

				printf("Game start\n");
				sleep(2);
				game();
			}
			
		} else if (strcmp(customer_number_choice, "0") == 0) // Проверка что введен 0
		{

			printf("Program exit\n");
			sleep(2);
			exit(0);
		} else // при некорректном вводе
		{
			perror("\n\tWARNING\n Number Enter Error\n");
			sleep(2);
		}
		clear();
	}

}
int main(void)
{
	display_start_user_menu();
	
	return 0;
} 

