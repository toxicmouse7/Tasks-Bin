#ifndef DEL
#define DEL
#include "delete functions.h"
#endif

lpstudent deleteBySurname(lpstudent stud)
{
	char buffer[256];
	int i = 0;
	lpstudent kick = stud, head = stud;
	printf("What person would you like to kick out?\n");
	gets(buffer);
	while (stud != NULL)
	{
		i++;
		if (strcmp(stud->surname, buffer) == 0)
			break;
		kick = stud;
		stud = stud->next;
	}
	if (stud != NULL && strcmp(stud->surname, buffer) == 0)
	{
		if (i == 1 && kick->next == NULL)
		{
			free(kick);
			kick = (lpstudent)malloc(sizeof(student));
			kick->next = NULL;
			kick->IsInitilized = FALSE;
			printf("Deleted!\n");
			return kick;
		}
		else if (i == 1 && kick->next != NULL)
		{
			kick = stud->next;
			free(stud);
			printf("Deleted!\n");
			return kick;
		}
		else
		{
			kick->next = stud->next;
			free(stud);
			printf("Deleted!\n");
			return head;
		}
	}
	else
	{
		printf("Person doesn't exist!\n");
		return head;
	}
}

lpstudent deleteBadStudent(lpstudent stud, BOOL* IsLast)
{
	lpstudent kick = stud, head = stud;

	if (stud->IsInitilized == FALSE)
	{
		printf("Students aren't initilized\n");
		return head;
	}

	int i = 0;
	double average = 0;
	while (stud != NULL)
	{
		i++;
		for (int j = 0; j < 6; j++)
			average += stud->marks[j];
		if ((average / 6) < 4)
			break;
		kick = stud;
		stud = stud->next;
		average = 0;
	}
	if ((average / 6) < 4 && average != 0)
	{
		if (i == 1 && kick->next == NULL)
		{
			free(kick);
			kick = (lpstudent)malloc(sizeof(student));
			kick->next = NULL;
			kick->IsInitilized = FALSE;
			*IsLast = TRUE;
			printf("Deleted!\n");
			return kick;
		}
		else if (i == 1 && kick->next != NULL)
		{
			kick = stud->next;
			free(stud);
			printf("Deleted!\n");
			return kick;
		}
		else
		{
			kick->next = stud->next;
			free(stud);
			printf("Deleted!\n");
			return head;
		}
	}
	else
	{
		printf("Bad students have been disconnected!\n");
		*IsLast = TRUE;
		return head;
	}
}