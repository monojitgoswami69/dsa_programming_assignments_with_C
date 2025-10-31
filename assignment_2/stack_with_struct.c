/*
ASSIGNMENT 2:
Problem Statement: Write a menu driven program in C to implement a Stack using array and perform the following operations.
(a) isFull() function to check whether the Stack is full or not.
(b) isEmpty() function to check whether the Stack is empty or not.
(c) peek() function to read the stack top element without deleting it.
(d) push(item) function to insert an element item in the Stack.
(e) pop() function to read and remove an element from the Stack.
(f) display() function to display the entire stack.
*/

#include <stdio.h>
#include <stdlib.h>

struct StackStruct {
    int *arr;
    int top;
    int size;
};

typedef struct StackStruct Stack;

Stack stack;

int isEmpty() {
    return stack.top == -1;
}

int isFull() {
    return stack.top == stack.size - 1;
}

void viewStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack -\n%d <- Top\n", stack.arr[stack.top]);
    for (int i = stack.top - 1; i >= 0; i--)
        printf("%d\n", stack.arr[i]);
    printf("\n");
}

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack.top++;
    stack.arr[stack.top] = x;
    printf("Element %d pushed\n", x);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack.arr[stack.top]);
    stack.top--;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d <- Top\n", stack.arr[stack.top]);
}

int main() {
    int choice;
    printf("Enter stack size(n): ");
    scanf("%d", &stack.size);
    if (stack.size <= 0) {
        printf("Invalid stack size. Must be positive.\n");
        return 1;
    }
    stack.arr = (int *) malloc(stack.size * sizeof(int));
    if (stack.arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    stack.top = -1;
    
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: viewStack(); break;
            case 2: {
                int data;
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                free(stack.arr);
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
