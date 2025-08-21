#include <stdio.h>
#include <string.h>
int main() {
    int choice;
    char oppstr[500]; // Creating a string.
    printf("Choose what operation(s) you wish to perform:\n1. Binary --> Decimal\n2. Decimal --> Binary\nEnter: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("Enter the Binary string: ");
        scanf("%499[^\n]", oppstr);
        int lenstr = strlen(oppstr);
        int result = 0;
        for(int i = 0; i < lenstr;i++) {
            switch (oppstr[i]) {
                case '0':
                result = result * 2 + 0;
                case '1':
                result = result * 2 + 1;
            }
        }
        printf("The Final Result is: %d", result);
    } else {
        // Do something
        int decnum;
        printf("Enter the Decimal value: ");
        scanf("%d", &decnum);
        int binary[32];   // enough for standard int
        int index = 0;
        while (decnum != 0) {
            int rem = decnum % 2;
            binary[index++] = rem;   // store remainder
            decnum = decnum / 2;
        }
        printf("Result: %d", binary);
    return 0;
}