#include "assignAndAppendDetails.h"
	
int assignDetails() {
	struct telephoneDirectory TD[MAXSIZE];	
	int i = 0, j = 0, k = 0, departmentIdentifier = 0;
	int employeeIdArr[MAXSIZE];
	char department[ROWSIZE][COLUMNSIZE] = {"Accounting", "Admin", "Bursary", "IT", "Student service"};

	FILE* fileHandler;				
	fileHandler = fopen("tel.txt", "w");
	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		fprintf(fileHandler, "Employee id\tEmployee name\t\tTelephone number\tDepartment name\n");
		do {
			printf("Enter employee id: [-1 to end]");
			scanf("%d", &TD[i].employeeId); /* User types in employee ID */
			getchar(); 
			employeeIdArr[i] = TD[i].employeeId; 
	
			if (TD[i].employeeId == -1) break; /* User types -1 to indicate that no more employees to be entered */

			for (j = 0; j < i; j++) {
				if (employeeIdArr[j] == TD[i].employeeId) {
					printf("Please enter a unique employee ID!\n");
					return 0;
				} /* Check if user's input ID exists in the file */
			}
			if (TD[i].employeeId < 1 || TD[i].employeeId > 100) {
				printf("Invalid employee ID!\n");
				return 0;
			}			
			else {
				printf("Enter employee name: ");
				gets(TD[i].employeeName);			

				printf("Enter employee telephone number extension: ");
				scanf("%d", &TD[i].telephoneNumber);
				getchar();				

				if (TD[i].telephoneNumber < 1000 || TD[i].telephoneNumber > 9999) {
					printf("Invalid telephone number extension!\n");
					return 0;
				} /*Check if telephone number entered is a four digit number */	

				printf("Enter employee department name: ");
				gets(TD[i].departmentName);
				for (k = 0; k < ROWSIZE; k++) {
					if (strcmp(TD[i].departmentName, department[k]) == 0) {
						departmentIdentifier++;
						break;
					} /* Check if there is a match between department inputted by user and departments in the list */
				}
				if (departmentIdentifier == 1) {
					fprintf(fileHandler, "%d\t\t", TD[i].employeeId);
				    fprintf(fileHandler, "%s\t\t", TD[i].employeeName);
					fprintf(fileHandler, "%d\t\t", TD[i].telephoneNumber);
					fprintf(fileHandler, "%s\n", TD[i].departmentName);
					departmentIdentifier = 0; /* Reset the count to 0 for next iteration */
				} 
				else {
					printf("Invalid department name!\n");
					return 0;
				}
			}
			i++;
		} while (true);
		}
	fclose(fileHandler);
	return 0;
}

int appendDetails() {
	struct telephoneDirectory TD[MAXSIZE];
	int line = 0, h = 0, i = 0, j = 0, k = 0, departmentIdentifier = 0;
	int employeeIdArr[MAXSIZE];
	char* fileLine[200], * token, department[ROWSIZE][COLUMNSIZE] = { "Accounting", "Admin", "Bursary", "IT", "Student service" };

	FILE* fileHandler;
	FILE* fileHandler2;

	fileHandler = fopen("tel.txt", "r");
	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		fgets(fileLine, 200, fileHandler); /* Reads first line in text file */
		while (!feof(fileHandler)) {
			line++; 
			fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
			token = strtok(fileLine, DELIMITER);  /* Splits one by one upon called */
			employeeIdArr[h] = atoi(token); /* Convert token to integer */
			h++;
		}
	}
	fclose(fileHandler);
	fileHandler2 = fopen("tel.txt", "a");
	if (fileHandler2 == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		do {
			printf("Enter employee id: [-1 to end]");
			scanf("%d", &TD[i].employeeId); /* User types in employee ID */
			getchar();
			employeeIdArr[h] = TD[i].employeeId;

			if (TD[i].employeeId == -1) break; /* User types -1 to indicate that no more employees to be entered */

			for (j = 0; j < h; j++) {
				if (employeeIdArr[j] == TD[i].employeeId) {
					printf("Please enter a unique employee ID!\n");
					return 0; 
				} /* Check if user's input ID exists in the file */
			}

			if (TD[i].employeeId < 1 || TD[i].employeeId > 100) {
				printf("Invalid employee ID!\n");
				return 0;
			}

			else {
				printf("Enter employee name: ");
				gets(TD[i].employeeName);

				printf("Enter employee telephone number extension: ");
				scanf("%d", &TD[i].telephoneNumber);
				getchar();

				if (TD[i].telephoneNumber < 1000 || TD[i].telephoneNumber > 9999) {
					printf("Invalid telephone number extension!\n");
					return 0;
				} /*Check if telephone number entered is a four digit number */

				printf("Enter employee department name: ");
				gets(TD[i].departmentName);
				for (k = 0; k < ROWSIZE; k++) {
					if (strcmp(TD[i].departmentName, department[k]) == 0) {
						departmentIdentifier++;
						break;
					}  /* Check if there is a match between department inputted by user and departments in the list */
				}
				if (departmentIdentifier == 1) {
					fprintf(fileHandler, "%d\t\t", TD[i].employeeId);
					fprintf(fileHandler, "%s\t\t", TD[i].employeeName);
					fprintf(fileHandler, "%d\t\t  ", TD[i].telephoneNumber);
					fprintf(fileHandler, "%s\n", TD[i].departmentName);
					departmentIdentifier = 0; /* Reset the count to 0 for next iteration */
				}
				else {
					printf("Invalid department name!\n");
					return 0;
				}
			}
			h++;
			i++;
		} while (true);
	}
	fclose(fileHandler2);
	return 0;
}