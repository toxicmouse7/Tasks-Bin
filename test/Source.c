#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>

int getSize(FILE* anothergovnoblyat)
{
	char* a;
	int size=0;
	a = (char*)malloc(255 * sizeof(char));
	while (!feof(anothergovnoblyat))
	{
		fgets(a,255, anothergovnoblyat);
		size++;
	}
	return size;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	errno_t err;
	int caseChoose;
	if (argc > 1)
		caseChoose = 2;
	else
	{
		printf("file --type 1\n");
		scanf_s("%d", &caseChoose);
	}
	system("cls");
	if ((caseChoose > 3) || (caseChoose < 1))
	{
		printf("Wrong number");
		return 0;
	}
	switch (caseChoose)
	{
	case 1:
	{
		FILE* A;
		err = fopen_s(&A, "input.txt", "r");
		if (err)
		{
			printf_s("The file A was not opened\n");     //err checks as usual
			system("pause");
			return 1;
		}
		char** fulltext;
		char* string;
		int temp1;
		int size1 = getSize(A);
		string = (char*)malloc(255 * sizeof(char)); // string memory
		fulltext = (char**)malloc(size1 * sizeof(char*)); //fulltext memeory
		fseek(A, 0, SEEK_SET);
		for (int i = 0; i < size1; i++)
		{
			fulltext[i] = (char*)malloc(255 * sizeof(char));
			fgets(fulltext[i], 255, A);
		}
		fseek(A, 0, SEEK_SET);
		int* strsize;
		strsize = (int*)malloc(255 * sizeof(int));
		for (int i = 0; i < size1; i++)
		{
			strsize[i] = strlen(fulltext[i]);
			if (i != size1 - 1)
				strsize[i] = strsize[i] - 1;
		}
		for (int i = 0; i < size1 - 1; i++)            //bubble method! started from number sort, continued with strings
		{
			for (int j = (size1 - 1); j > i; j--)
			{
				if (strsize[j - 1] > strsize[j])
				{
					temp1 = strsize[j - 1];
					strsize[j - 1] = strsize[j];
					strsize[j] = temp1;
					string = fulltext[j - 1];
					fulltext[j - 1] = fulltext[j];
					fulltext[j] = string;
				}
			}
		}
		for (int i = 0; i < size1; i++)
		{
			//if (i == 1)
				//printf("\n");                 // sometimes it helps with \n problems, sometimes not
			printf("%s", fulltext[i]);
		}
		printf("\n");
		for (int i = 0; i < size1; i++)
		{
			printf("%d\n", strsize[i]);
		}
		fclose(A);
		system("PAUSE");
		return 0;
	}
	case 2:
	{
		printf("Opening file -> %s\n", argv[1]);
		FILE* anothergovnoblyat;
		err = fopen_s(&anothergovnoblyat, argv[1], "r");
		int size2 = getSize(anothergovnoblyat);
		printf("%d\n", size2);
		fclose(anothergovnoblyat);
		system("PAUSE");
		return 1;
	}

	}
	

}