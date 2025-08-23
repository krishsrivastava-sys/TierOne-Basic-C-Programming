#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* So...Annoying.

Anyways, new things again.
- So i got to know that we have to add something called function prototype at the start of every program.
- I also got to know that we have to free the malloc memory or we get memory leakage...damn.
- strlen...well works like len() of python.
- i didn't quite understand malloc, will study it tomorrow. Definetly.


*/


// Function prototype
char* strrev_copy(const char *str);

int main() {
    char string[301];
    printf("Enter the string: ");
    scanf(" %300[^\n]", string);

    char *revstring = strrev_copy(string);
    if (revstring == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (strcmp(string, revstring) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(revstring);
    return 0;
}

char* strrev_copy(const char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    if (rev == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }

    rev[len] = '\0';  // add null terminator
    return rev;       // return the new string
}
