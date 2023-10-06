#include "sortEmployeeDetails.h"

void swapNumbers(int* num1, int* num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
} /* Swap two integers*/

void swapStrings(char* str1[100], char* str2[100]) {
	char temp[100];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
} /* Swap two strings */

int sortEmployeeDetails() {
	struct telephoneDirectory TD[MAXSIZE];
	int lineNo = 0, i = 1, j, k = 1;
	char fileLine[200], * token, temp[20];

	FILE* fileHandler;

	fileHandler = fopen("tel.txt", "r");
	if (fileHandler == NULL) {
		printf("File does not exist!");
		return 0;
	}
	else {
		fgets(fileLine, 200, fileHandler);  /* Reads first line in text file */
		while (!feof(fileHandler)) {
			lineNo++;
			fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
			token = strtok(fileLine, DELIMITER);  /* Splits one by one upon called */
			TD[lineNo].employeeId = atoi(token);  /* Convert token to integer */
			token = strtok(NULL, DELIMITER);
			strcpy(TD[lineNo].employeeName, token);
			token = strtok(NULL, DELIMITER);
			TD[lineNo].telephoneNumber = atoi(token);
			token = strtok(NULL, DELIMITER);
			strcpy(TD[lineNo].departmentName, token);
		}
	}
	for (i = 1; i < lineNo; i++) {
		for (j = i + 1; j < lineNo; j++) {
			if (strcmp(TD[i].departmentName, TD[j].departmentName) > 0) {
				swapNumbers(&TD[i].employeeId, &TD[j].employeeId);
				swapStrings(&TD[i].employeeName, &TD[j].employeeName);
				swapNumbers(&TD[i].telephoneNumber, &TD[j].telephoneNumber);
				swapStrings(&TD[i].departmentName, &TD[j].departmentName);
			} /* Checks if first department is lexicographically greater than second department */
		}
	}

	for (k = 1; k <= lineNo; k++) { /* lineNo indicates the total number of tuples or rows in the file */
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Employee id: %d\n", TD[k].employeeId);
		printf("Employee name: %s\n", TD[k].employeeName);
		printf("Employee telephone number: %d\n", TD[k].telephoneNumber);
		printf("Department name: %s", TD[k].departmentName);
	}
	fclose(fileHandler);
	return 0;
}