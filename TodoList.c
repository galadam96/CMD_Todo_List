//Date: 2024.03.04
//Purpose: Make a to-do list with add, view, delete and modify options (mark as done) in cmd line

#include <stdio.h>
#include <stdlib.h>

void showMenu();
int getInput(); //input selection and return
char* addTask();
void flushInputBuffer();
void listTask(char* task);

int main() {
	int input = 0;
	char** task = (char**)malloc(2 * sizeof(char*));
	while (1) {
		showMenu();
		input = getInput();

		printf("\nDEBUG: Your choice is: %i\n", input);


		if (input == 1) { //TBD
			task[0] = addTask();

		}
		else if (input == 2) {
			listTask(task[0]);
		} //TBD
		else if (input == 3) {} //TBD
		else if (input == 4) {} //TBD
		else if (input == 5) {} //TBD
		else if (input == 6) { //exit program
			printf("Bye!");
			break;
		}
		//system("cls");
	}	
	free(task);
	return 0;
}


void showMenu() {  //Shows main menu   
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

int getInput() {
	int input = 0;
	while (1) {
		printf("Enter a choice: ");
		scanf_s("%i", &input);
		if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6) {
			break;
		}
		else{
			printf("\nInvalid input. Only numbers from 1 to 6!\n");
			// Clear input buffer, to avoid infinite loop
			flushInputBuffer();
		}
	}
	return input;

}

char* addTask() {
	flushInputBuffer();
	//char newTask_addTask[100] = { 0 }; // Can not be return as array
	char* newTask_addTask = NULL;
	newTask_addTask = (char*)malloc(100 * sizeof(char));
	if (newTask_addTask == NULL) {
		printf("Memory allocation failed!");
		exit(1);
	}
	
	printf("Please enter the task you want to add!\n");
	
	fgets(newTask_addTask, 100, stdin); //Reads the whole line and stores it in newTask
	//Removes the new line if there is any.
	if (newTask_addTask[strlen(newTask_addTask) - 1] == '\n') {
		newTask_addTask[strlen(newTask_addTask) - 1] = '\0';
	}
	printf("%s has been added to the list.\n", newTask_addTask);
	
	//fflush(stdout); // Empties stdout buffer. Needed if any bugs occur when calling addTask function
	return newTask_addTask;
}

void flushInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void listTask(char* task) {
	printf("\nTask list:\n");
	printf("%s\n\n", task);
}