#include "all_about_names.h"

void loadFromFileTXT(lpstudent stud, FILE* file)
{
	lpstudent avoid;
	if (stud->IsInitilized == TRUE)
	{
		printf("Your list is already initilized!\n");
		return 7;
	}
	char buffer[256];
	while (!feof(file))
	{
		fgets(buffer, 256, file);
		stud->name = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->name, strlen(buffer) + 1, buffer);
		stud->name[strlen(buffer)] = '\0';

		fgets(buffer, 256, file);
		stud->surname = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->surname, strlen(buffer) + 1, buffer);
		stud->surname[strlen(buffer)] = '\0';

		fscanf_s(file, "%d", &stud->age);
		fseek(file, 1, SEEK_CUR);

		fgets(buffer, 256, file);
		stud->group = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->group, strlen(buffer) + 1, buffer);
		stud->group[strlen(buffer)] = '\0';

		for (int i = 1; i < 11; i++)
		{
			fscanf(file, "%d", &stud->phone[i]);
			fseek(file, 1, SEEK_CUR);
		}

		stud->marks = (int*)malloc(6 * sizeof(int));
		for (int i = 0; i < 6; i++)
		{
			fscanf(file, "%d", &stud->marks[i]);
			fseek(file, 1, SEEK_CUR);
		}

		stud->IsInitilized = TRUE;
		stud->next = (lpstudent)malloc(sizeof(student));
		avoid = stud;
		stud = stud->next;
	}
	free(avoid->next);
	avoid->next = NULL;
}

void loadFromFileDAT(lpstudent stud, FILE* file)
{
	lpstudent avoid;
	if (stud->IsInitilized == TRUE)
	{
		printf("Your list is already initilized!\n");
		return 7;
	}
	char buffer[256];
	while (!feof(file))
	{
		fread(buffer, sizeof(char), 50, file);
		stud->name = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->name, strlen(buffer) + 1, buffer);
		stud->name[strlen(buffer)] = '\0';

		fread(buffer, sizeof(char), 50, file);
		stud->surname = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->surname, strlen(buffer) + 1, buffer);
		stud->surname[strlen(buffer)] = '\0';

		fread(&stud->age, sizeof(int), 2, file);

		fread(buffer, sizeof(char), 50, file);
		stud->group = (char*)malloc(strlen(buffer) + 1);
		strcpy_s(stud->group, strlen(buffer) + 1, buffer);
		stud->group[strlen(buffer)] = '\0';

		for (int i = 1; i < 11; i++)
			fread(&stud->phone[i], sizeof(int), 1, file);

		stud->marks = (int*)malloc(6 * sizeof(int));
		for (int i = 0; i < 6; i++)
			fread(&stud->marks[i], sizeof(int), 1, file);

		stud->IsInitilized = TRUE;
		stud->next = (lpstudent)malloc(sizeof(student));
		avoid = stud;
		stud = stud->next;
	}
	free(avoid->next);
	avoid->next = NULL;
}