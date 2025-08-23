#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char oppstr[500]; // String for binary input

    printf("Choose what operation(s) you wish to perform:\n");
    printf("1. Binary --> Decimal\n2. Decimal --> Binary\nEnter: ");
    scanf("%d", &choice);

    if(choice == 1) {
        // Binary -> Decimal
        printf("Enter the Binary string: ");
        scanf("%s", oppstr);   // safer for binary

        int lenstr = strlen(oppstr);
        int result = 0;

        for(int i = 0; i < lenstr; i++) {
            switch (oppstr[i]) {
                case '0':
                    result = result * 2 + 0;
                    break;
                case '1':
                    result = result * 2 + 1;
                    break;
                default:
                    printf("Invalid character in binary string!\n");
                    return 1;
            }
        }
        printf("The Final Result is: %d\n", result);

    } else if(choice == 2) {
        // Decimal -> Binary
        int decnum;
        printf("Enter the Decimal value: ");
        scanf("%d", &decnum);

        if (decnum == 0) {
            printf("Result: 0\n");
            return 0;
        }

        int binary[32];   // enough for standard int
        int index = 0;

        while (decnum > 0) {
            binary[index++] = decnum % 2;
            decnum = decnum / 2;
        }

        printf("Result: ");
        for(int i = index - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }
        printf("\n");

    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
