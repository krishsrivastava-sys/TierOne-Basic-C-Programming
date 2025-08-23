// A random password generator in C.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    char datastr[length + 1];
    datastr[length] = '\0';
    srand(time(NULL));
    char edata[] =  {'#', '@', '$', '%', '&', '*', '!'};
    char edata1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int i = 0;i < length; i++) {
        if(i % 2 == 0) {
            // We use alphanum chars;
            int randum = rand() % 7;// We get the random index
            datastr[i] = edata[randum];
        } else {
            // we use Alphabets here;
            int randum = rand() % sizeof(edata1);
            datastr[i] = edata1[randum];
        }
    }
    printf("Your random password: %s", datastr);
    return 0;
}