#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "all_about_names.h"

lpstudent Add_Random_Student(lpstudent stud)
{
	srand(time(NULL));
	int rand_value = rand() % MAX_OF_NAMES;
	while (stud->next != NULL)
		stud = stud->next;
	stud->next = (lpstudent)malloc(sizeof(student));
	stud = stud->next;

	stud->name = (char*)malloc(strlen(names[rand_value]) + 1);
	strcpy_s(stud->name, strlen(names[rand_value]) + 1, names[rand_value]);

	rand_value = rand() % MAX_OF_SURNAMES;
	stud->surname = (char*)malloc(strlen(surnames[rand_value] + 1));
	strcpy_s(stud->surname, strlen(surnames[rand_value]) + 1, surnames[rand_value]);

	stud->age = rand() % 25;

	rand_value = rand() % 1;
	stud->group = (char*)malloc(strlen(groups[rand_value]) + 1);
	strcpy_s(stud->group, strlen(names[rand_value]) + 1, groups[rand_value]);

	for (int i = 2; i < 11; i++)
		stud->phone[i] = rand() % 10;

	stud->marks = (int*)malloc(6 * sizeof(int));
	for (int i = 0; i < 7; i++)
		stud->marks[i] = rand() % 6;

	stud->next = NULL;

	return stud;
}


int main()
{
	lpstudent stud = (lpstudent)malloc(sizeof(student));
	stud->next = NULL;
	stud = Add_Random_Student(stud);
	//Add_Random_Student(stud);

	return 0;
}