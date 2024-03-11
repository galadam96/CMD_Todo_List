//Date: 2024.03.04
//Purpose: Make a to-do list with add, view, delete and modify options (mark as done) in cmd line

#include <stdio.h>
#include <stdlib.h>

#define TASKNUMBER 50
#define TASKLENGTH 100
void showMenu();
int getInput(); //input selection and return
char* addTask();
void flushInputBuffer();
void listTask(char** task,int taskCount, char *isComplete);
void deleteTask(char** task, int taskCount);
void markComplete(char *isComplete,int taskcount);

int main() {
	int input = 0;
	char** task = (char**)malloc(TASKNUMBER * sizeof(char*));
	int taskCounter = 0;
	char* isComplete = (char*)malloc(TASKNUMBER * sizeof(char));
	//initialize every element as space char
	for (int i = 0; i < TASKNUMBER; i++) {
		isComplete[i] = ' ';
	}

	while (1) {
		showMenu();
		input = getInput();

		printf("\nDEBUG: Your choice is: %i\n", input);


		if (input == 1) {
			task[taskCounter] = addTask();
			taskCounter++;
		}
		else if (input == 2) {
			listTask(task, taskCounter,isComplete);
		}
		else if (input == 3) {
			 markComplete(isComplete,taskCounter);
		} 
		else if (input == 4) {
	
			deleteTask(task, taskCounter);
			taskCounter--;
		}
		else if (input == 5) { //exit program
			printf("Bye!");
			break;
		}
		
	}
	free(task);
	free(isComplete);
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
	printf("\n4) Delete task");
	printf("\n5) Exit");
	printf("\n");
	
}

int getInput() {
	int input = 0;
	while (1) {
		printf("Enter a choice: ");
		scanf_s("%i", &input);
		if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5) {
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
	system("cls"); // clear console

	flushInputBuffer();
	//char newTask_addTask[100] = { 0 }; // Can not be return as array
	char* newTask_addTask = NULL;
	newTask_addTask = (char*)malloc(TASKLENGTH * sizeof(char));
	if (newTask_addTask == NULL) {
		printf("Memory allocation failed!");
		exit(1);
	}
	
	printf("Please enter the task you want to add!\n");
	
	fgets(newTask_addTask, TASKLENGTH, stdin); //Reads the whole line and stores it in newTask
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

void listTask(char** task, int taskCount, char* isComplete) {
	system("cls"); // clear console
	printf("\nTask list:\n\n");
	
	for (int i = 0; i < taskCount; i++) {
		printf("%i)[%c]%s\n",i+1,isComplete[i], task[i]);
	}
	
}

void deleteTask(char** task, int taskCount) {
	int index = 0;
	system("cls"); // clear console
	printf("Enter the index of the task you want to delete: ");
	scanf_s("%i", &index);
    if (index < 1 || index > taskCount) {
        printf("\nInvalid index!\n");
        return;
    }

    // Delete selected task
    free(task[index - 1]);

    // Squeeze the array after deleting to fill the empty space
    for (int i = index - 1; i < taskCount - 1; i++) {
        task[i] = task[i + 1];
    }

    // set the last element to NULL
    task[taskCount - 1] = NULL;

    printf("Task at index %i has been deleted.\n", index);
}

void markComplete(char* isComplete,int taskCount) {
	int index = 0;
	system("cls"); // clear console
	printf("Type the index of the task you want to mark as completed: ");
	scanf_s("%i", & index);
	if (index < 1 || index > taskCount) {
		printf("\nInvalid index!\n");
		return;
	}

	isComplete[index-1] = 'X';
	printf("\nTask number %i status has been changed.\n", index);
}