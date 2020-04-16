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
