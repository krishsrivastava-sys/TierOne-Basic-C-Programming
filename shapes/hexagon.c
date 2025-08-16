// Code to print an Hexagon

#include <stdio.h>

int main() {
    int size;
    printf("Enter the size (even number): ");
    scanf("%d", &size);

    if (size % 2 != 0) { // Reject odd numbers
        printf("The number should be even!\n");
        return 0;
    }

    int totalWidth = 2 * size - 1;
    int center = (totalWidth + 1) / 2;
    int starpos1 = center - (size / 2);
    int starpos2 = center + (size / 2);

    // The top line
    int spaces = (totalWidth - size) / 2;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    for (int i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");

    // The upper V
    while (starpos1 > 1 && starpos2 < totalWidth) {
        starpos1--;
        starpos2++;
        for (int j = 1; j <= totalWidth; j++) {
            if (j == starpos1 || j == starpos2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // The lower V
    while (starpos1 < center - (size / 2)) {
        starpos1++;
        starpos2--;
        for (int j = 1; j <= totalWidth; j++) {
            if (j == starpos1 || j == starpos2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // bottom line
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    for (int i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}
