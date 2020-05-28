#include "output header.h"
#include "delete functions.h"
#include "init functions.h"
#include "file functions.h"
#define OUT
#define DEL
#define INIT
#define FF

int main()
{
	FILE* file;
	fopen_s(&file, "list.txt", "r");
	BOOL last = FALSE;
	lpstudent stud = (lpstudent)malloc(sizeof(student));
	stud->IsInitilized = FALSE;
	stud->next = NULL;
	Add_Student(stud, FALSE);
	outputStudents(stud);


	return 0;
}