// Finally we are free from those darn shapes ;-;
// I seriously hate them.

# include <stdio.h>
# include <stdlib.h>
// So we have to make a calculator with four operations;

int main() {
    int num1;
    int num2;
    char operator;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the operator: ");
    scanf(" %c", &operator);
    int solution;
    printf("Enter the second number: ");
    scanf("%d", &num2);
    switch(operator) {
        case '+':
            solution = num1 + num2;
            break;
        case '-':
            solution = num1 - num2;
            break;
        case '*':
            solution = num1 * num2;
            break;
        case '/':
            solution =  num1 / num2;
            break;
        default:
            printf("Unknown Operator!\n");
            exit(1);
    }
    printf("The Solution is %d.\n", solution);
    return 0;
}
