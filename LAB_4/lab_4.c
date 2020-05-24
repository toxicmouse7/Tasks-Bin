#include "all_about_names.h"

void Initilize_Student(lpstudent stud)
{
	srand(time(NULL));
	int rand_value = rand() % MAX_OF_NAMES;

	stud->name = (char*)malloc(strlen(names[rand_value]) + 1);
	strcpy_s(stud->name, strlen(names[rand_value]) + 1, names[rand_value]);

	rand_value = rand() % MAX_OF_SURNAMES;
	stud->surname = (char*)malloc(strlen(surnames[rand_value] + 1));
	strcpy_s(stud->surname, strlen(surnames[rand_value]) + 1, surnames[rand_value]);

	stud->age = 18 + rand() % 8;

	rand_value = rand() % MAX_OF_GROUPS;
	stud->group = (char*)malloc(strlen(groups[rand_value]) + 1);
	strcpy_s(stud->group, strlen(groups[rand_value]) + 1, groups[rand_value]);

	stud->phone[0] = 7;
	stud->phone[1] = 9;
	for (int i = 2; i < 11; i++)
		stud->phone[i] = rand() % 10;

	stud->marks = (int*)malloc(6 * sizeof(int));
	for (int i = 0; i < 6; i++)
		stud->marks[i] = 2 + rand() % 4;

	stud->IsInitilized = TRUE;
	stud->next = NULL;
}

void Initilize_By_Hands(lpstudent stud)
{
	char buffer[256];

	printf("Name: ");
	gets(buffer);
	stud->name = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(stud->name, strlen(buffer) + 1, buffer);

	printf("Surname: ");
	gets(buffer);
	stud->surname = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(stud->surname, strlen(buffer) + 1, buffer);

	printf("Age: ");
	scanf_s("%d", &stud->age);

	printf("Group: ");
	gets(buffer);
	gets(buffer);
	stud->group = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(stud->group, strlen(buffer) + 1, buffer);

	printf("Phone(type numbers separeted by spaces): +79");
	gets(buffer);
	stud->phone[0] = 7;
	stud->phone[1] = 9;
	for (int i = 2; i < 11; i++)
		scanf_s("%d", &stud->phone[i]);

	printf("Marks: ");
	stud->marks = (int*)malloc(6 * sizeof(int));
	for (int i = 0; i < 6; i++)
		scanf_s("%d", &stud->marks[i]);

	stud->IsInitilized = TRUE;
	stud->next = NULL;
	system("cls");
}

int Add_Student(lpstudent stud, BOOL IsByHand)
{
	if (stud->next == NULL && stud->IsInitilized == FALSE)
	{
		if (IsByHand == TRUE)
			Initilize_By_Hands(stud);
		else
			Initilize_Student(stud);
		return 4;
	}

	while (stud->next != NULL)
		stud = stud->next;
	stud->next = (lpstudent)malloc(sizeof(student));
	stud = stud->next;


	if (IsByHand == TRUE)
		Initilize_By_Hands(stud);
	else
		Initilize_Student(stud);
	return 0;
}

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


int main()
{
	lpstudent stud = (lpstudent)malloc(sizeof(student));
	stud->IsInitilized = FALSE;
	stud->next = NULL;
	Add_Student(stud, FALSE);
	//Add_Student(stud, FALSE);
	//Add_Student(stud, FALSE);
	outputStudents(stud);
	stud = deleteBySurname(stud);
	outputStudents(stud);
	

	return 0;
}