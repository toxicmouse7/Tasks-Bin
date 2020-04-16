#include "snake.h"

void create_game_field()
{
	for (int i = 0; i < 40; i++)
	{
		gotoxy(i, 0);
		printf("#");
		gotoxy(i, 20);
		printf("#");
	}

	for (int i = 0; i < 21; i++)
	{
		gotoxy(0, i);
		printf("#");
		gotoxy(40, i);
		printf("#");
	}

}

void Output_Snake(Snake* snake)
{
	while (snake != NULL)
	{
		gotoxy(snake->x, snake->y);
		printf("*");
		snake = snake->next;
	}
}

void Remove_Old_Snake(Snake* snake)
{
	while (snake != NULL)
	{
		gotoxy(snake->x, snake->y);
		printf(" ");
		snake = snake->next;
	}
}

void increase_snake(Snake* snake, char ch)
{
	Snake* tmp;
	while (snake->next != NULL)
		snake = snake->next;
	tmp = snake;
	snake->next = (Snake*)malloc(sizeof(Snake));
	snake = snake->next;
	snake->next = NULL;
	snake->previous = tmp;
	if (ch == 'w')
	{
		snake->y = tmp->y + 1;
		snake->x = tmp->x;
	}
	else if (ch == 'a')
	{
		snake->y = tmp->y;
		snake->x = tmp->x + 1;
	}
	else if (ch == 's')
	{
		snake->y = tmp->y - 1;
		snake->x = tmp->x;
	}
	else if (ch == 'd')
	{
		snake->y = tmp->y;
		snake->x = tmp->x - 1;
	}
}

void pullup_snake(Snake* snake)
{
	Snake* snake_goes, * tmp;
	snake_goes = snake;

	while (snake_goes->next != NULL)
		snake_goes = snake_goes->next;

	while (snake_goes->previous != NULL)
	{
		tmp = snake_goes->previous;
		snake_goes->y = tmp->y;
		snake_goes->x = tmp->x;
		snake_goes = snake_goes->previous;
	}
}

void free_snake(Snake* snake)
{
	while (snake->next != NULL)
		snake = snake->next;

	while (snake->previous != NULL)
	{
		snake = snake->previous;
		free(snake->next);
	}
	free(snake);
}
