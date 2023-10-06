#include "searchTelephoneNumber.h"

int searchTelephoneNumberById() {
	int lineId = 0, idIndicator = 0, employeeId;
	char fileLine[200], * token;

	FILE* fileHandler;
	fileHandler = fopen("tel.txt", "r");
	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		printf("Enter employee id: ");
		scanf("%d", &employeeId);
		fgets(fileLine, 200, fileHandler); /* Reads first line in text file */
		while (!feof(fileHandler)) {
			lineId++;
			fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
			token = strtok(fileLine, DELIMITER); /* Splits one by one upon called */

			if (employeeId == atoi(token)) {
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("Employee id: %d\n", atoi(token));   /* Convert token to integer */
				token = strtok(NULL, DELIMITER);
				printf("Employee name: %s\n", token); 
				token = strtok(NULL, DELIMITER);
				printf("Employee telephone number: %d\n", atoi(token)); 
				token = strtok(NULL, DELIMITER);
				printf("Department name: %s", token); 
				idIndicator++;
				break;
			}
			else
				continue; /* Continues to loop through the file until a matching ID is found */
		}
		if (idIndicator == 0) {
			printf("Employee id does not exist!\n");
			return 0;
		}
	}
	fclose(fileHandler);
	return 0;
}

int searchTelephoneNumberByName() {
	int lineName = 0, nameIndicator = 0, employeeId;
	char fileLine[200], employeeName[50], * token;

	FILE* fileHandler;
	fileHandler = fopen("tel.txt", "r");

	if (fileHandler == NULL) {
		printf("File does not exist!\n");
		return 0;
	}
	else {
		printf("Enter employee name: ");
		gets(employeeName);	

		fgets(fileLine, 200, fileHandler); /* Reads first line in text file */
		while (!feof(fileHandler)) {
			lineName++;
			fgets(fileLine, 200, fileHandler); /* Skips first line and reads second line in text file */
			token = strtok(fileLine, DELIMITER);  /* Splits one by one upon called */
			employeeId = atoi(token);  /* Convert token to integer */
			token = strtok(NULL, DELIMITER);
			if (strcmp(employeeName, token) == 0) {
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("Employee id: %d\n", employeeId);
				printf("Employee name: %s\n", token);
				token = strtok(NULL, DELIMITER);
				printf("Employee telephone number: %d\n", atoi(token));
				token = strtok(NULL, DELIMITER);
				printf("Department name: %s", token);
				nameIndicator++;
				break;
			}
			else
				continue;  /* Continues to loop through the file until a matching name is found */
		}

		if (nameIndicator == 0) {
			printf("Employee name does not exist!\n");
			return 0;
		}
	}
	fclose(fileHandler);
	return 0;
}