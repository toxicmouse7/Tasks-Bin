#include "apple_functions.h"

void Add_Random_Apple(Apple* apple)
{
	apple->x = (rand() % 39) + 1;
	apple->y = (rand() % 19) + 1;
}

void Apple_Collision(Apple* apple, Snake* snake)
{
	while (apple->x == snake->x && apple->y == snake->y)
	{
		Add_Random_Apple(apple);
	}
}

void Output_Apple(Apple* apple)
{
	gotoxy(apple->x, apple->y);
	printf("@");
}