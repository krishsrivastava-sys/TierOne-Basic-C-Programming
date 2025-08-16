#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int num1;
    printf("Enter the number: ");
    scanf("%d", &num1);
    if(num1 <= 1) {
        printf("The number is not prime.");
    } else {
        if (num1 == 2) {
            printf("The number is prime.");
        } else {
            if (num1 % 2 == 0) {
                printf("The number is not prime.");
            } else {
                int sqrtofn = (int) sqrt(num1);
                for (int i = 3; i <= sqrtofn; i += 2) {
                    if(num1 % i == 0) {
                        printf("The number is not prime.");
                        return 0;
                    } else {
                        printf("The number is prime.");
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}