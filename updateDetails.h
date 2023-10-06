#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ROWSIZE 5
#define COLUMNSIZE 20
#define DELIMITER "\t\t"

struct telephoneDirectory {
	int employeeId;
	char employeeName[50];
	int telephoneNumber;
	char departmentName[20];
};

int updateTelephoneNumber();
int updateDepartmentName();