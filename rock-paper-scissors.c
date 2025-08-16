#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

/*
Notes:
- Using the strcmp() function here.
- 0 => strings are exactly equal.
- < 0 => first string is “less than” the second (in ASCII order).
- > 0 => first string is “greater than” the second (in ASCII order).


- used a for loop here because the string is an array. can't go around like we did in Javascript ;-;


*/


int main() {
    printf("Welcome to the RPS Game!\n");
    printf("The game will have 5 Rounds! Good Luck!\n");

    int computer = 0;
    int user = 0;

    srand(time(NULL)); // Seed once, at start

    for (int i = 1; i <= 5; i++) {
        int comp_choice = rand() % 3 + 1; // 1=rock, 2=paper, 3=scissors
        const char *comp_string;

        if (comp_choice == 1) {
            comp_string = "rock";
        } else if (comp_choice == 2) {
            comp_string = "paper";
        } else {
            comp_string = "scissors";
        }

        char user_choice[11];
        printf("\nRound %d - Enter your choice (rock/paper/scissors): ", i);
        scanf("%10s", user_choice);

        // Convert input to lowercase
        for (int j = 0; user_choice[j]; j++) {
            user_choice[j] = tolower(user_choice[j]);
        }

        int user_num;
        if (strcmp(user_choice, "rock") == 0) {
            user_num = 1;
        } else if (strcmp(user_choice, "paper") == 0) {
            user_num = 2;
        } else if (strcmp(user_choice, "scissors") == 0) {
             user_num = 3;
        } else {
            printf("Invalid input! You lose this round.\n");
            computer++;
            continue;
        }

        printf("I chose: %s\n", comp_string);

        if (comp_choice == user_num) {
            printf("It's a tie!\n");
        } else if ((user_num == 1 && comp_choice == 3) || (user_num == 2 && comp_choice == 1) || (user_num == 3 && comp_choice == 2)) {
            printf("You win this round!\n");
            user++;
        } else {
            printf("I win this round!\n");
            computer++;
        }
    }

    // Final result
    printf("\nFinal Score - You: %d | Computer: %d\n", user, computer);
    if (computer == user) {
        printf("Battle Result: It's a tie.\nMy comment: Humph! You got lucky this time!\n");
    } else if (computer < user) {
        printf("Battle Result: You win.\nMy comment: How's that possible? You must have cheated!\n");
    } else {
        printf("Battle Result: I win.\nMy comment: Well that was pretty obvious.\n");
    }

    return 0;
}
