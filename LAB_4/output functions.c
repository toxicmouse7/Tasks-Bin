void printPhone(int mass[11])
{
	printf("+");
	for (int i = 0; i < 11; i++)
	{
		if (i == 1)
			printf(" (");
		if (i == 7 || i == 9)
			printf("-");
		printf("%d", mass[i]);
		if (i == 3)
			printf(") ");

	}
	printf("\n");
}

void printMarks(int* marks)
{
	for (int i = 0; i <= 5; i++)
		printf("%d ", marks[i]);
	printf("\n");
}

void outputStudent(lpstudent stud)
{
	if (stud->IsInitilized == TRUE)
	{
		printf("Name: %s\n", stud->name);
		printf("Surname: %s\n", stud->surname);
		printf("Age: %d\n", stud->age);
		printf("Group: %s\n", stud->group);
		printf("Phone: ");
		printPhone(stud->phone);
		printf("Marks: ");
		printMarks(stud->marks);
	}
	else printf("Student isn't initilized!\n");
}

void outputStudents(lpstudent stud)
{
	while (stud != NULL)
	{
		outputStudent(stud);
		stud = stud->next;
		printf("\n");
	}
}

void outputSuccesfulStudents(lpstudent stud)
{
	if (stud->IsInitilized == FALSE)
	{
		printf("There are no students in your list\n");
		return 8;
	}

	double average = 0;
	while (stud != NULL)
	{
		for (int j = 0; j < 6; j++)
			average += stud->marks[j];
		if ((average / 6) >= 4)
			outputStudent(stud);
		stud = stud->next;
		average = 0;
	}
}

void outputMates(lpstudent stud)
{
	if (stud->IsInitilized == FALSE)
	{
		printf("There are no students in your list\n");
		return 9;
	}

	char group[256];
	int count = 0;
	printf("From which group would you like to see students?\n");
	gets(group);
	while (stud != NULL)
	{
		if (strcmp(group, stud->group) == NULL);
		{
			count++;
			outputStudent(stud);
		}
		stud = stud->next;
	}
	if (count == 0)
		printf("There are no students in this group\n");
}

void outputBySurname(lpstudent stud)
{
	if (stud->IsInitilized == FALSE)
	{
		printf("There are no students in your list\n");
		return 9;
	}

	char surname[256];
	int count = 0, correct = 0;
	printf("With which surname would you like to see students?\n");
	gets(surname);
	while (stud != NULL)
	{
		if (strlen(surname) < strlen(stud->surname))
		{
			for (int i = 0; i < strlen(surname); i++)
			{
				if (surname[i] == stud->surname[i])
					correct++;
			}
			if (correct == strlen(surname))
			{
				count++;
				outputStudent(stud);
			}
		}
		else continue;
	}
	if (count == 0)
		printf("There are no students in this group\n");
}