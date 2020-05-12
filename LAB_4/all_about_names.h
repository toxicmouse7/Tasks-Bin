#pragma once

const char* names[] = { "Alexey", "Smith", "Jhonson", "Williams", "Jones", "Brown", "Davis", "Miller", "Willson", "Moore", "Taylor" };
const char* surnames[] = { "Adams","Baker", "Brook", "Carter", "Collins", "Davies", "Grant", "Harris", "Hill", "Hughes", "Lee" };
const char* groups[] = {"group1"};
#define MAX_OF_NAMES 12
#define MAX_OF_SURNAMES 12

struct Student
{
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