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