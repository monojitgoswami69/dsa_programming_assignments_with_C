/*
ASSIGNMENT 8:
Problem Statement: Write a menu driven program in C to implement a stack using single linked list and perform the following operations.
(a) isEmpty() is to check whether the stack is empty or not.
(b) push() is to insert an item in the stack.
(c) pop() is to delete an item from the stack.
(d) display() is to show the entire stack.
*/

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

typedef struct stack* stack;

stack top = NULL;

int isEmpty() {
    return top == NULL;
}

void viewStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack -\n");
    stack current = top;
    int isFirst = 1;
    
    while (current != NULL) {
        if (isFirst) {
            printf("%d <- Top\n", current->data);
            isFirst = 0;
        } else {
            printf("%d\n", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

void push() {
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    
    stack newNode = (stack)malloc(sizeof(struct stack));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed\n", x);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    
    stack temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d <- Top\n", top->data);
}

int main() {
    int choice;
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                while (top != NULL) {
                    stack temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
