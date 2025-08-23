// Number guessing with Hints in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// FOr the rand() function

int main() {
    srand(time(NULL));// For sheer randomness
    int rnum = rand() % 20 + 1; // Random number, out of 20.
    printf("[GAME] Guess the number: You have 5 Chances! (1 - 20)");
    for (int i = 0; i < 5; i++) {
        // Five chances for the user.
        int choice;
        printf("Enter the number: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 20) {
            // Do the code.
            if(choice == rnum) {
                printf("Congratulations! You guessed the correct number: %d!", choice);
                break;
            } else {
                if(choice > rnum) {
                    printf("You Failed! Hint: Go Lower!");
                } else {
                    printf("You Failed! Hint: Go Higher!");
                }
            }
        } else {
            printf("Invalid Input, your chance was lost!");
        }
    }
}