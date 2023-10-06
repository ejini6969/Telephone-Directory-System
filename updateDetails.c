#include "updateDetails.h"

int updateTelephoneNumber() {
	struct telephoneDirectory TD[MAXSIZE];
	int lineNo = 0, writeLine = 1, idIndicator = 0, inputId, updatedTelephoneNumber;
	char fileLine[200], * token;

	FILE* fileHandler;
	FILE* fileHandler2;

	fileHandler = fopen("tel.txt", "r");
	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		printf("Enter employee id: ");
		scanf("%d", &inputId);  /* User types in employee ID */
		printf("Enter updated telephone number: ");
		scanf("%d", &updatedTelephoneNumber); /* User types in employee's new telephone number */

		if (updatedTelephoneNumber < 1000 || updatedTelephoneNumber > 9999) {
			printf("Invalid telephone number extension!\n");
			return 0;
		} /*Check if telephone number entered is a four digit number */

		fgets(fileLine, 200, fileHandler); /* Reads first line in text file */
		while (!feof(fileHandler)) {
			lineNo++;
			fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
			token = strtok(fileLine, DELIMITER);  /* Splits one by one upon called */
			TD[lineNo].employeeId = atoi(token);  /* Convert token to integer */
			token = strtok(NULL, DELIMITER);
			strcpy(TD[lineNo].employeeName, token);
			token = strtok(NULL, DELIMITER);
			if (TD[lineNo].employeeId == inputId) {
				TD[lineNo].telephoneNumber = updatedTelephoneNumber;
				idIndicator++;
			} /* Stores new telephone number if there is an ID match */
			else
				TD[lineNo].telephoneNumber = atoi(token); /* Stores original telephone number otherwise */
			token = strtok(NULL, DELIMITER);
			strcpy(TD[lineNo].departmentName, token);
		}

		if (idIndicator == 0) {
			printf("Employee id does not exist!\n");
			return 0;
		}
	}
	fclose(fileHandler);

	fileHandler2 = fopen("tel.txt", "w"); /* Write everything in the file from scratch */
	if (fileHandler2 == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		fprintf(fileHandler2, "Employee id\tEmployee name\t\tTelephone number\tDepartment name\n");
		for (writeLine = 1; writeLine <= lineNo; writeLine++) { /* lineNo indicates the total number of tuples or rows in the file */
			fprintf(fileHandler2, "%d\t\t", TD[writeLine].employeeId);
			fprintf(fileHandler2, "%s\t\t", TD[writeLine].employeeName);
			fprintf(fileHandler2, "%d\t\t", TD[writeLine].telephoneNumber);
			fprintf(fileHandler2, "%s", TD[writeLine].departmentName);
		}
	}
	fclose(fileHandler2);
	return 0;
}

int updateDepartmentName() {
	struct telephoneDirectory TD[MAXSIZE];
	int i = 0, lineNo = 0, writeLine = 1, idIndicator = 0, departmentIdentifier = 0, inputId;
	char fileLine[200], * token, newDepartmentName[20], department[ROWSIZE][COLUMNSIZE] = { "Accounting", "Admin", "Bursary", "IT", "Student service" };

	FILE* fileHandler;
	FILE* fileHandler2;

	fileHandler = fopen("tel.txt", "r");
	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		printf("Enter employee id: ");
		scanf("%d", &inputId);  /* User types in employee ID */
		printf("Enter new department: ");
		scanf("%s", &newDepartmentName);  /* User types in employee's new department */

		for (i = 0; i < ROWSIZE; i++) {
			if (strcmp(newDepartmentName, department[i]) == 0) {
				departmentIdentifier++;
				break;
			} /* Check if there is a match between department inputted by user and departments in the list */
		}

		if (departmentIdentifier == 1) {
			fgets(fileLine, 200, fileHandler); /* Reads first line in text file */
			while (!feof(fileHandler)) {
				lineNo++;
				fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
				token = strtok(fileLine, DELIMITER);  /* Splits one by one upon called */
				TD[lineNo].employeeId = atoi(token);  /* Convert token to integer */
				token = strtok(NULL, DELIMITER);
				strcpy(TD[lineNo].employeeName, token);
				token = strtok(NULL, DELIMITER);
				TD[lineNo].telephoneNumber = atoi(token);
				if (TD[lineNo].employeeId == inputId) {
					strcpy(TD[lineNo].departmentName, newDepartmentName);
					strcat(TD[lineNo].departmentName, "\n");
					idIndicator++;
				} /* Stores new department name if there is an ID match */
				else {
					token = strtok(NULL, DELIMITER);
					strcpy(TD[lineNo].departmentName, token); 
				} /* Stores original department name otherwise */
			}
			if (idIndicator == 0) {
				printf("Employee id does not exist!\n");
				return 0;
			}
			departmentIdentifier = 0; /* Reset the count to 0 for next iteration */
		}
		else {
			printf("Invalid department name!\n");
			return 0;
		}
	}
	fclose(fileHandler);

	fileHandler2 = fopen("tel.txt", "w");  /* Write everything in the file from scratch */
	if (fileHandler2 == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		fprintf(fileHandler2, "Employee id\tEmployee name\t\tTelephone number\tDepartment name\n");
		for (writeLine = 1; writeLine <= lineNo; writeLine++) { /* lineNo indicates the total number of tuples or rows in the file */
			fprintf(fileHandler2, "%d\t\t", TD[writeLine].employeeId);
			fprintf(fileHandler2, "%s\t\t", TD[writeLine].employeeName);
			fprintf(fileHandler2, "%d\t\t", TD[writeLine].telephoneNumber);
			fprintf(fileHandler2, "%s", TD[writeLine].departmentName);
		}
	}
	fclose(fileHandler2);
	return 0;
}