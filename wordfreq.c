// Word frequency counter.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[501];
    printf("Enter the string: ");
    scanf("%500[^\n]", str);   // read full line into str
    char cword[101];
    printf("Enter the word to count in the character array: ");
    scanf("%100s", cword);    // read the target word
    int result = 0;
    char fword[101];          // buffer for each found word
    int i = 0;
    while (str[i] != '\0') {
        // Skip spaces
        while (str[i] == ' ') {
            i++;
        }
        // If end of string, break
        if (str[i] == '\0') break;
        // Extract a word into fword
        int j = 0;
        while (str[i] != ' ' && str[i] != '\0') {
            fword[j++] = str[i++];
        }
        fword[j] = '\0'; // terminate the word
        // Compare extracted word with cword
        if (strcmp(fword, cword) == 0) {
            result++;
        }
    }
    printf("The word '%s' occurs %d times.\n", cword, result);
    return 0;
}
