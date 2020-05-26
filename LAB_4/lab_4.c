#include "all_about_names.h"
#include "list_functions.h"

int main()
{
	FILE* file;
	fopen_s(&file, "list.txt", "r");
	BOOL last = FALSE;
	lpstudent stud = (lpstudent)malloc(sizeof(student));
	stud->IsInitilized = FALSE;
	stud->next = NULL;
	Add_Student(stud, FALSE);
	Add_Student(stud, FALSE);
	Add_Student(stud, FALSE);
	Add_Student(stud, FALSE);
	outputStudents(stud);
	stud = deleteBySurname(stud);
	outputStudents(stud);
	while (last != TRUE)
		stud = deleteBadStudent(stud, &last);


	return 0;
}