// Finding maximum and minimum in an array.

#include <stdio.h>

int main() {
    int arrray[] = {1, 2, 3, 4};
    size_t size = sizeof(arrray) / sizeof(arrray[0]);// We have the length here
    int max = 0;
    int min = 0;
    int tman;
    for (int i = 0; i < size;i++) {
        if (arrray[i] > max) {
            tman = max;
            max = i;
            if(tman < min) {
                min = tman;
            }
        } else if(arrray[i] < max && arrray[i] < min) {
            min = i;
        }
    }
    printf("The maximum value number is: %d\n", arrray[max]);
    printf("The minimum value number is: %d", arrray[min]);
    return 0;
}