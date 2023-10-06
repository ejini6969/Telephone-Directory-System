#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

int assignDetails();
int appendDetails();