#pragma once
#ifndef INC
#define INC
#include <stdio.h>
#include <stdlib.h>
#include "all_about_names.h"
#endif

void loadFromFileTXT(lpstudent stud, FILE* file);
void loadFromFileDAT(lpstudent stud, FILE* file);