//Date: 2024.03.04
//Purpose: Make a to-do list with add, view, delete and modify options (mark as done) in cmd line

#include <stdio.h>
#include <stdlib.h>

void showMenu(void);
int getInput(); // More complex function for getting input
int getInput_simple(); //Simpler input selection and return

int main() {
	int input = 0;

	system("cls");
	showMenu();
	input = getInput_simple();

	printf("\nDEBUG: Your choice is: %i", input);

	//while (1) {}
		
}


void showMenu(void) {  //Shows main menu   
	printf(" -----------------------\n");
	printf("|\tTo Do List\t|");
	printf("\n -----------------------\n");
	printf("\nOptions");
	printf("\n1) Add a task");
	printf("\n2) List all tasks");
	printf("\n3) Mark as complete");
	printf("\n4) Edit task");
	printf("\n5) Delete task");
	printf("\n6) Exit");
	printf("\n");
	
}

int getInput() { //Gets input from user and checks if its valid
	int input = 0;
	int validInput = 0;
	
	while (1) {
		printf("Enter a choice: ");
		validInput = scanf_s("%i", &input);// Store scanf_s return value (1 if valid parameter specifier is given)
		//Invalid input (not number)
		if (validInput != 1) {
			printf("\nInvalid input. Only numbers from 1 to 6!\n");
			// Clear input buffer 
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

		//Invalid number (not 1-6)
		 else if (input < 1 || input > 6) {
			printf("\nInvalid number. Choose from 1 to 6!\n");
			// Clear input buffer 
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
		//Valid input
		 else {
			break;
		}
		
	}
	return input;
}
int getInput_simple() {
	int input = 0;
	while (1) {
		printf("Enter a choice: ");
		scanf_s("%i", &input);
		if (input == 1) { //TBD
			//addTask();
			break;
		}
		else if (input == 2) {} //TBD
		else if (input == 3) {} //TBD
		else if (input == 4) {} //TBD
		else if (input == 5) {} //TBD
		else if (input == 6) {
			printf("Bye!");
			break;
		}
		else{
			printf("\nInvalid input. Only numbers from 1 to 6!\n");
			// Clear input buffer, to avoid infinite loop
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
	return input;

}
