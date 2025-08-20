// Count vowels/consonants in a string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[500];// big enough ig?
    printf("Enter the string: ");
    scanf("%[^\n]", str);// OOf! I love charsets
    int size = strlen(str);
    int vcount = 0;
    int ccount = 0;
    for (int i = 0; i < size;i++) {
        switch (str[i]) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
            vcount++;
            default:
            if (isalpha(str[i])) { // Checks if it's an alphabet.
                ccount++;
            }
        }
    }
    printf("Character Statistics:-\nNumber of Vowels: %d\nNumber of consonents: %d\n", vcount, ccount);
    return 0;
}