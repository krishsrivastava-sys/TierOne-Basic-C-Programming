// The Final Code for Tier-1: Baby Steps. YAYA!!!!!!!!!
#include <stdio.h>
// cringe ^.^
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    struct Node* second = malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;
    head->next = second;

    struct Node* third = malloc(sizeof(struct Node));
    third->data = 30;
    third->next = NULL;
    second->next = third;

    // Print list
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Free memory
    current = head;
    struct Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
