# include <stdio.h>

/* Write a program to calculate the GCD and LCM. */


int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int num1;
    int num2;
    printf("Enter the value of the first number: ");
    scanf("%d", num1);
    printf("Enter the value of the second number: ");
    scanf(" %d", num2);

}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
