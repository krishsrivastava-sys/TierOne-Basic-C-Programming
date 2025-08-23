#include <stdio.h>
#include <stdbool.h>

int mat[3][3] = {0};

int checkwin(int mat[3][3]) {
    // Checking for rows;
    if ((mat[0][0] != 0) && (mat[0][0] == mat[0][1]) && (mat[0][1] == mat[0][2])) {
        return mat[0][0];
    }
    if ((mat[1][0] != 0) && (mat[1][0] == mat[1][1]) && (mat[1][1] == mat[1][2])) {
        return mat[1][0];
    }
    if ((mat[2][0] != 0) && (mat[2][0] == mat[2][1]) && (mat[2][1] == mat[2][2])) {
        return mat[2][0];
    }

    // Checking for columns;
    if ((mat[0][0] != 0) && (mat[0][0] == mat[1][0]) && (mat[1][0] == mat[2][0])) {
        return mat[0][0];
    }
    if ((mat[0][1] != 0) && (mat[0][1] == mat[1][1]) && (mat[1][1] == mat[2][1])) {
        return mat[0][1];
    }
    if ((mat[0][2] != 0) && (mat[0][2] == mat[1][2]) && (mat[1][2] == mat[2][2])) {
        return mat[0][2];
    }

    // Checking for diagonals;
    if ((mat[0][0] != 0) && (mat[0][0] == mat[1][1]) && (mat[1][1] == mat[2][2])) {
        return mat[0][0];
    }
    if ((mat[0][2] != 0) && (mat[0][2] == mat[1][1]) && (mat[1][1] == mat[2][0])) {
        return mat[0][2];
    }

    return 0;
}

void printboard(int mat[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == 0) {
                printf(". ");
            } else if (mat[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("]\n");
    }
    printf("\n");
}

int main() {
    bool win = false;

    while (!win) {
        int done_count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[i][j] != 0) {
                    done_count++;
                }
            }
        }
        if (done_count >= 9) {
            int res0 = checkwin(mat);
            if (res0 == 1) {
                printf("Congratulations to player-1 for winning the match!\n");
                win = true;
            } else if (res0 == 2) {
                printf("Congratulations to player-2 for winning the match!\n");
                win = true;
            } else {
                printf("It's a draw!\n");
            }
            break;
        }

        // Player 1 turn
        int xchoice1;
        int ychoice1;
        printf("[Player - 1]: Enter x y (0..2 0..2): ");
        scanf("%d %d", &xchoice1, &ychoice1);
        if (xchoice1 < 0 || xchoice1 > 2 || ychoice1 < 0 || ychoice1 > 2) {
            printf("[Error] Invalid position! Try again.\n");
            continue;
        }
        if (mat[xchoice1][ychoice1] != 0) {
            printf("[Error] That place is already filled! Try again.\n");
            continue;
        }
        mat[xchoice1][ychoice1] = 1;
        printboard(mat);

        int res1 = checkwin(mat);
        if (res1 == 1) {
            printf("Congratulations to player-1 for winning the match!\n");
            win = true;
            break;
        } else if (res1 == 2) {
            printf("Congratulations to player-2 for winning the match!\n");
            win = true;
            break;
        }

        // Recount after P1 move
        done_count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[i][j] != 0) {
                    done_count++;
                }
            }
        }
        if (done_count >= 9) {
            int resA = checkwin(mat);
            if (resA == 1) {
                printf("Congratulations to player-1 for winning the match!\n");
                win = true;
            } else if (resA == 2) {
                printf("Congratulations to player-2 for winning the match!\n");
                win = true;
            } else {
                printf("It's a draw!\n");
            }
            break;
        }

        // Player 2 turn
        int xchoice2;
        int ychoice2;
        printf("[Player - 2]: Enter x y (0..2 0..2): ");
        scanf("%d %d", &xchoice2, &ychoice2);
        if (xchoice2 < 0 || xchoice2 > 2 || ychoice2 < 0 || ychoice2 > 2) {
            printf("[Error] Invalid position! Try again.\n");
            continue;
        }
        if (mat[xchoice2][ychoice2] != 0) {
            printf("[Error] That place is already filled! Try again.\n");
            continue;
        }
        mat[xchoice2][ychoice2] = 2;
        printboard(mat);

        int res2 = checkwin(mat);
        if (res2 == 1) {
            printf("Congratulations to player-1 for winning the match!\n");
            win = true;
        } else if (res2 == 2) {
            printf("Congratulations to player-2 for winning the match!\n");
            win = true;
        }
    }

    printf("Game over.\n");
    return 0;
}