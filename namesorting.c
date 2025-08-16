#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    struct Names {
        int id;
        char name[20];
    };
    struct Names *name = NULL;
    int count = 0;
    char name_[101];

    while (true) {
        printf("Enter the Name (type exit() to break): ");
        scanf(" %100[^\n]", name_);
        if(strcmp(name_, "exit()") == 0) {
            break;
        } else {
            // Lowercase the input for sorting
            for (int i = 0; name_[i] != '\0'; i++) {
                name_[i] = tolower(name_[i]);
            }

            // Allocate/reallocate memory safely
            struct Names *temp = realloc(name, (count + 1) * sizeof(struct Names));
            if (!temp) {
                printf("Memory allocation failed!\n");
                free(name);
                exit(1);
            }
            name = temp;

            // Store the new name
            name[count].id = count + 1;
            strcpy(name[count].name, name_);
            count++;  // Increment count after successful storage
        }
    }

    // Sort names alphabetically
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(name[i].name, name[j].name) > 0) {
                struct Names temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    }

    // Print sorted names
    printf("\nSorted Names:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", name[i].id, name[i].name);
    }

    free(name);
    return 0;
}
