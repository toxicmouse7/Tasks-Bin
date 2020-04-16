#include "apple_functions.h"

void Add_Random_Apple(Apple* apple)
{
	apple->x = rand() % 40;
	apple->y = rand() % 20;
	if (apple->x == 0)
		apple->x++;
	if (apple->y == 0)
		apple->y++;
}

void Apple_Collision(Apple* apple, Snake* snake)
{
	while (snake != NULL)
	{
		if (snake->x == apple->x)
			apple->x = rand() % 40;
		if (snake->y == apple->y)
			apple->y = rand() % 20;
		snake = snake->next;
	}
}

void Output_Apple(Apple* apple)
{
	gotoxy(apple->x, apple->y);
	printf("@");
}