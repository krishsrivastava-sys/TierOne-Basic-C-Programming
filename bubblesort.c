#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int csize;
    printf("Enter the size of the array you wish to sort: ");
    scanf("%d", &csize);
    int *list = malloc(csize * sizeof(int));
    if(list == NULL) {
        printf("[ERROR] Memory Allocation Failed.\nTerminating the process...");
        exit(1);
    }
    for (int i = 0; i < csize;i++) {
        printf("Enter Array Value[%d]: ", i+1);
        scanf("%d", &list[i]);
    }
    int n = csize;

    printf("Initial array: ");
    print_array(list, n);
    printf("\n");

    // Bubble sort
    for (int i = n - 1; i > 0; i--) {
        int swapped = 0; // Track if any swap happened this pass
        printf("Pass %d:\n", n - i);
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                // Swap elements
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = 1;
                printf("  Swapped indices %d and %d: ", j, j + 1);
                print_array(list, n);
            }
        }
        if (!swapped) {
            printf("  No swaps in this pass, array is sorted early.\n");
            break;
        }
        printf("  Array at end of pass %d: ", n - i);
        print_array(list, n);
        printf("\n");
    }
    printf("Sorted array: ");
    print_array(list, n);
    free(list);
    return 0;
}