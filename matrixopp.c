#include <stdio.h>

// Finally: Matrix addition, subtraction, Multiplication.

int main() {
    printf("Choose what operations you wish to perform for matrices.\n1. Addition\n2. Subtraction\n3. Multiplication\nEnter: ");
    int choice;
    scanf("%d", &choice);
    int mat[3][3];
    int mat2[3][3];
    if(choice != 1 && choice != 2 && choice != 3) {
        printf("{ERROR} Please Enter valid input values.");
        return 0;
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            printf("Enter the value of A(%d, %d): ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("]\n");
    }

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            printf("Enter the value of B(%d, %d): ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("]\n");
    }
    int resmat[3][3];
    if (choice == 1) {
        // If the choice of user is to perform matrix addition
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                resmat[i][j] = (mat[i][j] + mat2[i][j]);
            }
        }
    } else if(choice == 2) {
        // If the choice of the user is to perform matrix subtraction
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                resmat[i][j] = (mat[i][j] - mat2[i][j]);
            }
        }
    } else if(choice == 3) {
        // If the choice of the user is to perform matrix multiplication
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                resmat[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    resmat[i][j] += mat[i][k] * mat2[k][j];
                }
            }
        }
    }
    printf("The operations were successful.");
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", resmat[i][j]);
        }
        printf("]\n");
    }
    return 0;
}