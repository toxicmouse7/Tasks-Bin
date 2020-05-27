#pragma once
#include <Windows.h>

const char* names[] = { "Alexey", "Smith", "Jhonson", "Williams", "Jones", "Brown", "Davis", "Miller", "Willson", "Moore", "Taylor" };
const char* surnames[] = { "Adams","Baker", "Brook", "Carter", "Collins", "Davies", "Grant", "Harris", "Hill", "Hughes", "Lee" };
const char* groups[] = {"group1", "group2","group3" ,"group4" ,"group5" ,"group6" ,"group7" ,"group8" ,"group9" ,"group10" ,"group11" };
#define MAX_OF_NAMES _countof(names)
#define MAX_OF_SURNAMES _countof(surnames)
#define MAX_OF_GROUPS _countof(groups)

struct Student
{
	BOOL IsInitilized;
	char* name;
	char* surname;
	int age;
	char* group;
	int phone[11];
	int* marks;
	struct Student* next;
};

typedef struct Student* lpstudent;
typedef struct Student student;