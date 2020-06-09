#include "output header.h"
#include "delete functions.h"
#include "init functions.h"
#include "file functions.h"
#include <errno.h>
#define OUT
#define DEL
#define INIT
#define FF


int main()
{
	FILE* file, *dat;
	errno_t err;
	BOOL last = FALSE;
	lpstudent stud = (lpstudent)malloc(sizeof(student));
	stud->IsInitilized = FALSE;
	stud->next = NULL;
	char ch;
	while (TRUE)
	{
		system("cls");
		printf("1. Add student randomly\n2. Add student by hands\n3. Output students\n4. Output succeful students\n5. Ouput mates\n6.Find and output by surname\n");
		ch = _getch();
		switch (ch)
		{
		case '1':
		{
			Add_Student(stud, FALSE);
			break;
		}
		case '2':
		{
			Add_Student(stud, TRUE);
			break;
		}
		case '3':
		{
			outputStudents(stud);
			system("pause");
			break;
		}
		case '4':
		{
			outputSuccesfulStudents(stud);
			system("pause");
			break;
		}
		case '5':
		{
			outputMates(stud);
			system("pause");
			break;
		}
		case '6':
		{
			outputBySurname(stud);
			system("pause");
			break;
		}
		case '7':
		{
			deleteBySurname(stud);
			system("pause");
			break;
		}
		case '8':
		{
			BOOL IsLast = FALSE;
			while (IsLast != TRUE)
			{
				deleteBadStudent(stud, &IsLast);
			}
			system("pause");
			break;
		}
		case '9':
		{
			err = fopen_s(&file, "list.txt", "r");
			if (err == 0)
				loadFromFileTXT(stud, file);
			else printf("File doesn't exist or you don't have permissions for access\n");
			if (err == 0)
				fclose(file);
			system("pause");
			break;
		}
		case '0':
		{
			ch = _getch();
			switch (ch)
			{
			case '1':
			{
				err = fopen_s(&dat, "list.dat", "rb");
				if (err == 0)
					loadFromFileDAT(stud, dat);
				else printf("File doesn't exist or you don't have permissions for access\n");
				if (err == 0)
					fclose(file);
			}
			}
		}
		default: exit(9);
		}
	}

	return 0;
}