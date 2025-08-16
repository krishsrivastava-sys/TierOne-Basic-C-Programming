#include <stdio.h>

int main() {
    int start;
    printf("Enter the first number of the Fibonacci sequence: ");
    scanf("%d", &start);
    int length;
    printf("How long of a Fibonacci sequence do you want?: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("Please provide valid inputs.\n");
        return 0;
    }
    int num1 = start;
    int num2 = start + 1;
    printf("Fibonacci sequence: %d %d ", num1, num2);
    for (int i = 3; i <= length; i++) {
        int result = num1 + num2;
        printf("%d ", result);
        num1 = num2;
        num2 = result;
    }
    printf("\n");
    return 0;
}
