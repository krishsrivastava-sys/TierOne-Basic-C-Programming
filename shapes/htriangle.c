#include <stdio.h>

int main() {
    int size;
    printf("Enter the size (1 side): ");
    scanf("%d", &size);

    int totalWidth = 2 * size - 1;
    int center = (totalWidth + 1) / 2;

    // Top of the triangle (just one star in the center)
    for (int i = 1; i <= totalWidth; i++) {
        if (i == center) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    int firststar = center - 1;
    int laststar = center + 1;

    // Middle hollow lines
    for (int row = 2; row < size; row++) {
        for (int col = 1; col <= totalWidth; col++) {
            if (col == firststar || col == laststar) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        firststar--;
        laststar++;
    }

    // Bottom line (full of stars)
    for (int i = 1; i <= totalWidth; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}
