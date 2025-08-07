#include <stdio.h> // I included the standard i/0 library here.

// defining the main function cuz.. yk.
int main() {
    int size; // Defining the size variable where we store the 'size' of the square.
    printf("Enter size of the square: ");
    scanf("%d", &size); // getting the size.

    // A loop that uses the length of the square to run multiple iterations.
    // using this, we can make the left, and the right side of the square.
    for (int i = 1; i <= size; i++) {
        // checking if the line we are on is the first or the last.
        // to make the top and bottom lines.
        if (i == 1 || i == size) {
            // For printing the stars of the line, based on the size ofc.
            for (int j = 0; j < size; j++) {
                printf("*");
            }
            // New line after the stars ended.
            printf("\n");
        } else {
            // if we are in the middle lines, we need to print stars in the first and last character.
            // the rest will be white spaces.
            for (int j = 0; j < size; j++) {
                // first character
                if (j == 0) {
                    printf("*");
                } else if(j == (size - 1)) { // the last character.
                    printf("*\n");
                } else {// white space if none.
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
