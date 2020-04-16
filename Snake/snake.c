#include "snake.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	system("title Snake");
	FILE* f;
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	Snake* snake_go;
	Snake* tmp;
	Apple* apple = (Apple*)malloc(sizeof(Apple));
	int score = 0;
	snake->next = NULL;
	snake->previous = NULL;
	snake->x = 20;
	snake->y = 10;
	char ch = 'm', ch1 = 'm';
	int time = 300;
	char Nickname[20];
	char buffer[50];

	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);


	printf("Write your nickname(max 20 symbols): ");
	gets_s(Nickname, 20);
	system("cls");

	create_game_field();
	Add_Random_Apple(apple);
	Output_Apple(apple);

	while (1)
	{
		if (_kbhit())
			ch = _getch();
		if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
			ch1 = ch;

		switch (ch1)
		{
			case 'w': 
			{
				Remove_Snakes_Tail(snake);
				pullup_snake(snake);
				snake->y--;
				Output_Snake(snake);
				Sleep(time);
				break;
			}
			case 'a':
			{
				Remove_Snakes_Tail(snake);
				pullup_snake(snake);
				snake->x--;
				Output_Snake(snake);
				Sleep(time);
				break;
			}
			case 's':
			{
				Remove_Snakes_Tail(snake);
				pullup_snake(snake);
				snake->y++;
				Output_Snake(snake);
				Sleep(time);
				break;
			}
			case 'd':
			{
				Remove_Snakes_Tail(snake);
				pullup_snake(snake);
				snake->x++;
				Output_Snake(snake);
				Sleep(time);
				break;
			}
		}

		if (snake->x > 39 || snake->x < 1 || snake->y < 1 || snake->y > 19)
		{
			system("cls");
			printf("Game Over, your score is: %d\n", score);
			goto end;
		}

		if (snake->x == apple->x && snake->y == apple->y)
		{
			increase_snake(snake, ch);
			Add_Random_Apple(apple);
			Apple_Collision(apple, snake);
			Output_Apple(apple);
			score++;
			if (time > 49)
				time -= 10;
		}

		snake_go = snake;
		while (snake_go->next != NULL)
		{
			snake_go = snake_go->next;
			if (snake->x == snake_go->x && snake->y == snake_go->y)
			{
				system("cls");
				printf("Game Over, your score is: %d\n", score);
				goto end;
			}
		}

	}
	end:

	fopen_s(&f, "scorelist.txt", "r+");
	int flag = 0;
	while (!feof(f))
	{
		long g = ftell(f);
		fgets(buffer, 50, f);
		int i = strlen(buffer);
		while (!((int)buffer[i] >= 65 && (int)buffer[i] <= 90) && !((int)buffer[i] >= 97 && (int)buffer[i] <= 122))
		{
			i--;
		}
		buffer[i + 1] = '\0';
		if (strcmp(buffer, Nickname) == 0)
		{
			fseek(f, g, SEEK_SET);
			fprintf(f, "%s - %d\n", Nickname, score);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		fseek(f, 0, SEEK_END);
		fprintf("%s - %d\n", Nickname, score);
	}

	fclose(f);
	
	free_snake(snake);
	free(apple);

	system("pause");
	return 0;
}