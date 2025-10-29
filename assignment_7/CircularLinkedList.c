/*
ASSIGNMENT 7:
Problem Statement: Write a menu driven program in C to perform the following operations on circular linked list.
(a) insert a node at the kth position of the list.
(b) delete the kth node at the end of the list.
(c) display the whole list.
(d) search an element x in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); return; }
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    if (k <= 1) {
        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, k);
}

void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) { printf("List is empty!\n"); return; }

    struct Node *temp = *head;

    if (k <= 1) {
        if (temp->next == temp) {
            printf("Deleted %d\n", temp->data);
            free(temp);
            *head = NULL;
            return;
        }

        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;

        last->next = temp->next;
        *head = temp->next;
        printf("Deleted %d from position 1\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;

    if (temp->next == *head) { printf("Position %d out of bounds\n", k); return; }

    struct Node *del = temp->next;
    temp->next = del->next;
    printf("Deleted %d from position %d\n", del->data, k);
    free(del);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) printf(" -> ");
    } while (temp != head);
    printf(" (circular)\n");
}

void search(struct Node *head, int value) {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("%d not found\n", value);
}

void displayMenu() {
    printf("\n===== CIRCULAR LINKED LIST MENU =====\n");
    printf("1. Insert at position k\n");
    printf("2. Delete from position k\n");
    printf("3. Display list\n");
    printf("4. Search value\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *head = NULL;
    int ch, val, k;
    while (1) {
        displayMenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value and position: "); scanf("%d%d", &val, &k); insertAtK(&head, val, k); break;
            case 2: printf("Enter position to delete: "); scanf("%d", &k); deleteFromK(&head, k); break;
            case 3: display(head); break;
            case 4: printf("Enter value to search: "); scanf("%d", &val); search(head, val); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
