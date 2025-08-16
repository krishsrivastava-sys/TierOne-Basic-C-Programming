#include <stdio.h>

int main() {
    int num1;
    printf("Enter the number to factorial:");
    scanf("%d", &num1);
    if (num1 <= 0) {
        printf("The number must be positive.");
        return 0; 
    }
    long long int num2 = 1;
    for (int i = 1;i <= num1;i++) {
        num2 *= i;
    }
    printf("The factorial is %lld.", num2);
    return 0;
}