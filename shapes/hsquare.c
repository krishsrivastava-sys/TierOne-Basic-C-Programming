#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the square: ");
    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        if (i == 1 || i == size) {
            for (int j = 0; j < size; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int j = 0; j < size; j++) {
                if (j == 0) {
                    printf("*");
                } else if (j == size - 1) {
                    printf("*\n");
                } else {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}
