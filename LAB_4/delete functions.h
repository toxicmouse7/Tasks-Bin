#pragma once
#ifndef INC
#define INC
#include "all_about_names.h"
#include <stdio.h>
#include <stdlib.h>
#endif

lpstudent deleteBySurname(lpstudent Head);
lpstudent deleteBadStudent(lpstudent Head, BOOL* IsLast);