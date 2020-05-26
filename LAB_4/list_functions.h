#pragma once
#include "all_about_names.h"
lpstudent deleteBadStudent(lpstudent Head, BOOL* IsLast);
lpstudent deleteBySurname(lpstudent Head);
void outputStudents(lpstudent Head);
void outputStudent(lpstudent Head);
void printMarks(int* marks);
void printPhone(int mass[11]);
int Add_Student(lpstudent Head, BOOL IsByHand);
void Initilize_By_Hands(lpstudent Head);
void Initilize_Student(lpstudent stud);