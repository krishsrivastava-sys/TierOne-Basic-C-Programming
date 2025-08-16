#include <stdio.h>

int main() {
    int n;
    printf("Enter size:");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number for symmetry.\n");
        return 1;
    }

    int mid = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == mid || j == mid || i == j || i + j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
