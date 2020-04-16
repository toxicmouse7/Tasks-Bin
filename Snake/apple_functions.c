#include "snake.h"

void Add_Random_Apple(Apple* apple)
{
	apple->x = rand() % 40;
	apple->y = rand() % 20;
	if (apple->x == 0)
		apple->x++;
	if (apple->y == 0)
		apple->y++;
}

void Output_Apple(Apple* apple)
{
	gotoxy(apple->x, apple->y);
	printf("@");
}