#include "menu.h"

int menu() {
	int option;
	printf("\n");
	printf("Welcome to Asia Pacific University's (APU) Telephone Directory System!\n");
	printf("Please select the operation you want to perform!\n");
	printf("1.Assign details of existing employees into Telephone Directory System.\n");
	printf("2.Append details of new employees into Telephone Directory System.\n");
	printf("3.Search telephone number of employees based on their id.\n");
	printf("4.Search telephone number of employees based on their name.\n");
	printf("5.Update telephone number of employees.\n");
	printf("6.Update department where employees work at.\n");
	printf("7.Sort employees' details department-wise.\n");
	printf("8.Exit.\n");
	printf("Enter your choice: ");
	scanf("%d", &option); /* User types in option */
	getchar();

	switch (option) {
	case 1: assignDetails(); menu(); break;
	case 2: appendDetails(); menu(); break;
	case 3:	searchTelephoneNumberById(); menu(); break;
	case 4: searchTelephoneNumberByName(); menu(); break;		
	case 5: updateTelephoneNumber(); menu(); break;
	case 6:	updateDepartmentName(); menu(); break;
	case 7: sortEmployeeDetails(); menu(); break;
	case 8: break; /* User types in 8 to halt execution process */
	default: printf("Invalid option!\n"); menu(); break;
	} 	/* Upon execuion, users will be directed back to the menu page */
	return 0;
}