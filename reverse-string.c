# include <stdio.h>
# include <string.h>
/* Write a program to reverse a string (manual, no strrev)*/

/*
We used strlen from string.h this time.
nothing else is new here.
*/


int main() {
    // Some tasks that i took are so easy that i feel why are others so complicated ;-;
    char str[201]; // setting limit to 200 characters;
    printf("Enter the string to reverse:");
    scanf("%201[^\n]", str);
    int size = strlen(str);// Size indexing
    char revstr[201];
    for (int i = 0; i < size; i++) {
        revstr[i] = str[size - 1 - i];  // copy backwards
    }
    revstr[size] = '\0';  // add null terminator, strlen doesn't count it;
    printf("The reversed string: %s\n", revstr);

}