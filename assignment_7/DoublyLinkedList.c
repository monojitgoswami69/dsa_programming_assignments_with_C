/*
ASSIGNMENT 7:
Problem Statement: Write a menu driven program in C to perform the following operations on double linked list.
(a) insert a node at the kth position of the list.
(b) delete the kth node at the end of the list.
(c) display the whole list.
(d) search an element x in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); return; }
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (k <= 1 || *head == NULL) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", value, k);
}

void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) { printf("List is empty!\n"); return; }

    struct Node *temp = *head;
    if (k <= 1) {
        *head = temp->next;
        if (*head) (*head)->prev = NULL;
        printf("Deleted %d from position 1\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < k && temp; i++)
        temp = temp->next;

    if (!temp) { printf("Position %d out of bounds\n", k); return; }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    printf("Deleted %d from position %d\n", temp->data, k);
    free(temp);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty\n"); return; }
    printf("List: ");
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

void search(struct Node *head, int value) {
    int pos = 1;
    while (head) {
        if (head->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("%d not found\n", value);
}

void displayMenu() {
    printf("\n===== DOUBLY LINKED LIST MENU =====\n");
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
