#ifndef INC_GUR
#define INC_GUR
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#endif

typedef struct
{
	int x;
	int y;
	struct Snake* next;
	struct Snake* previous;
} Snake;

typedef struct
{
	int x;
	int y;
} Apple;

void gotoxy(int x, int y);
void Add_Random_Apple(Apple* apple);
void Output_Apple(Apple* apple);
void create_game_field();
void Output_Snake(Snake* snake);
void Remove_Old_Snake(Snake* snake);
void increase_snake(Snake* snake, char ch);
void pullup_snake(Snake* snake);
void free_snake(Snake* snake);
void Apple_Collision(Apple* apple, Snake* snake);
