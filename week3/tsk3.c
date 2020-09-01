#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *nextNode;
};

void print_list(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->value);
        node = node->nextNode;
    }
    printf("\n");
}

void insert_node(struct Node *previous, int newNode_value) {
    if (previous == NULL) {
        return;
    }
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->value = newNode_value;
    new_node->nextNode = previous->nextNode;
    previous->nextNode = new_node;
}

void delete_node(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *previous;
    if (current->value == value) {
        *head = current->nextNode;
        free(current);
    } else {
        while (current != NULL && current->value != value) {
            previous = current;
            current = current->nextNode;
        }
        if (current == NULL) {
            printf("No element with such value");
            return;
        }
        previous->nextNode = current->nextNode;
        free(current);
    }
}


int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));// create head node by allocating memory for it
    head->value = 7;//initialize value
    head->nextNode = NULL;
    insert_node(head, 2);
    print_list(head);
    insert_node(head->nextNode, 9);
    print_list(head);
    insert_node(head, 56);
    print_list(head);
    delete_node(&head, 9);
    print_list(head);
    delete_node(&head, 7);
    print_list(head);
    delete_node(&head, 12);
    return 0;
}