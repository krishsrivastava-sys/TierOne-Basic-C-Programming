#include <stdio.h>
#include <time.h>
# include <stdlib.h>

/***********************
- We are importing time.h, for seeding the rand() function from stdlib.h
- The stdlib's rand function does not generate a true number every time. Instead it uses a
mathematical formula to generate a random number. That means that after every few runs, a similar number
could come back. And hence we use a Seed, and what is a better seed than using the time?
which changes every second?
*/

int main() {
    srand(time(NULL)); // Seeding the rand function;
    int choice;
    int randnum = rand() % 100 + 1;
    // Question: Why not 101?
    // Answer: 0 would be included in the choice array. To remove it (shifting by one position) we include the + 1.
    printf("Welcome to the Guess-The-Number game!\nIf you guess the correct number, you win! Exciting?\nEnter the number now!\n");
    printf("Enter your choice (1-100):");
    scanf("%d", &choice);
    if (choice == randnum && (choice <= 100 && choice > 0)) {
        printf("Congratulations! You won the game!\n");
    } else if(!(choice <= 100 || choice > 0)) {
        printf("Please enter a valid number.\n");
    } else {
        printf("Aww! You failed! Better luck next time.\n");
        printf("The random number was: %d\n", randnum);
    }
    return 0;
}