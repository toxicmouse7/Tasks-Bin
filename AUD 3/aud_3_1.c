#include <stdio.h>
#include <stdlib.h>

int* func(int *new_mass)
{
	int size, * mass, new_correct = 0;
	scanf_s("%d", &size);
	mass = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		scanf_s("%d", &mass[i]);
	new_mass = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (mass[i] == new_mass[j])
				count++;
		}
		if (count == 0)
		{
			new_mass[new_correct] = mass[i];
			new_correct++;
		}
	}
	new_mass = (int*)realloc(new_mass, sizeof(int) * new_correct);
	for (int i = 0; i < new_correct; i++)
		printf("%d ", new_mass[i]);
	printf("\nSize of mass: %d\n", new_correct);
	free(mass);

	return new_mass;
}

int main()
{
	int *new_mass = NULL;
	new_mass = func(new_mass);
	

	system("pause");
	return 0;
}