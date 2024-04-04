#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define size 32


char customer_name[size];
int customer_count;

void clear() // очистка терминала
{
	system("cls");
}

void error_message(int index_of_error)
{
	switch(index_of_error)
	{
		case(1):
			printf("\tWARNING!!!\n  Please, set your name\n");
			break;
		case(2):
			printf("\tWARNING\n  Number Enter Error\n");
			break;
		default:
			printf("\tWARNING\n  Fail action\n");
			break;
	}
}

char *replace(char *string, int old_char, int new_char) // Заменяем символы в текста
{
	char *return_string;
	int length = strlen(string);
	for(return_string = string; *return_string ; return_string++)
    {
       if(*return_string == old_char) 
           *return_string = new_char;
    }
    return return_string;
}

int check_current_of_user_name(char *new_user_name) // Проверка что имя не пустое
{
	int check_process_result = 0,
		word_letter_index;
	char letters_list_to_check[] = {
		'q','w','e','r','t','y',
		'u','i','o','p','a','s',
		'd','f','g','h','j','k',
		'l','z','x','c','v','b',
		'n','m','Q','W','E','R',
		'T','Y','U','I','O','P',
		'A','S','D','F','G','H',
		'J','K','L','Z','X','C',
		'V','B','N','M','\0'}, **ptr; // Массив букв для проверка
	for(word_letter_index = 0; word_letter_index < strlen(new_user_name); word_letter_index++) // Проходимся по символам имени
	{			
		for (int letter = 0; letter < 54; letter++)
		{
			if (new_user_name[word_letter_index] == letters_list_to_check[letter]) // Если есть совпадение хоть 1 буквы - имя подходит
			{
				printf("Name is correct!\n");
				check_process_result = 1;
				break;
			}
		}
		if(check_process_result == 1)
			break;
		
		
	}
	return check_process_result;

}

void user_registration() // регистрация пользователя в системе
{
	clear();
	char name[size];
	char mass[size];
	int exit_value = 0;
	printf("-- Lenght of name <32 simbols! --\n");
	printf("Enter your name: ");
	
	
	fgets(name, size, stdin); // При вводе и нажатии Enter, его тоже сохраняет в строке
	
	replace(name, '\n', '\0'); // Заменяем Enter на пустоту
	
	strcpy(customer_name, name); // Передаем введеное имя в глобальную переменную
	if (check_current_of_user_name(customer_name) == 0)
	{
		error_message(1);
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
		printf("-1-Enter customer name. (your active name is: %s) \n", customer_name);
		printf("-2-Start game.\n");
		printf("-0-Exit.\n");
		printf("take number: ");
		scanf("%s", customer_number_choice);
		getchar(); // Вытаскиваем символ из буффера программы
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
				error_message(1);
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
			error_message(2);
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

