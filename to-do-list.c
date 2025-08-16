# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

/*
UGH! SO I DID QUITE SOME NEW THINGS!
AND I GOTTA DOCUMENT IT ALL ;-;
So....
1. I used structs
> I thought that these could be the best here, learnt how to use them and instantly applied them.
we also used a new function realloc() - of the stdlib library
We are dynamically increasing the size of the task struct;
also the sizeof...well the term says all
from the string.h lib we have,
strcspn() which we use to remove the last character.
strcpy() ... well it's used to copy strings to other data types..

*/

struct Task {
    int id;
    char description[200];
    int done;
};

int mark_task_done(struct Task tasks[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].done = 1;
            return 1; // success
        }
    }
    return 0; // not found
}

int main() {
    struct Task *tasks = NULL; // Pointer to the array of tasks;
    int count = 0;// Number of tasks = 0;
    // Let's create a task list.
    while (true) {
        int choice;
        char input[200];
        printf("Welcome to your basic to-do-list!\n");
        printf("Choose your options!\n");
        printf("1. View the task list.\n");
        printf("2. Add a new task..\n");
        printf("3. Finish a new task.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Your task list:\n");
            printf("[S.No.] | [Task Description] | [Status]\n");
            if (count == 0) {
                printf("1. | No tasks to show. | 🤷\n");
            } else {
                for (int i = 0; i < count;i++) {
                    // For every task id;
                    printf("%d. | %s | %s \n", i + 1, tasks[i].description, tasks[i].done ? "✅" : "❌");
                }
            }
        } else if (choice == 2) {
            count++;// Add a new task;
            tasks = realloc(tasks, count * sizeof(struct Task));
            // New memory of the tasks
            printf("Enter the task: ");
            scanf(" %200[^\n]", input);

            input[strcspn(input, "\n")] = 0;// Remove the newline character;
            tasks[count - 1 /* The 0 index*/].id = count;
            strcpy(tasks[count - 1].description, input);
            tasks[count - 1].done = 0;

            printf("Task \'%s\' added successfully!\n", input);
        } else if(choice == 3) {
            // Let's user input the task id.
             int taskidby;
            printf("Enter the task's id: ");
            scanf(" %d", &taskidby);
            if (mark_task_done(tasks, count, taskidby)) {
                printf("The task modification was successful.\n");
            } else {
            printf("Please enter a valid task id.\n");
            }
        } else {
            printf("The user has quit the program.\nThank you.\n");
            return 0;
        }
    }
    return 0;
}