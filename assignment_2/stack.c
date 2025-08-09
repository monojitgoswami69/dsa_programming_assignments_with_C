#include <stdio.h>
#include <stdlib.h>

int isEmpty(int top){
    return top == -1;
}

int isFull(int top, int size){
    return top == size - 1;
}

void viewStack(int *stack, int top) {
    if (isEmpty(top)) {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack -\n%d <- Top\n", *(stack + top));
    for (int i = top - 1; i >= 0; i--)
        printf("%d\n", *(stack + i));
    printf("\n");
}

void push(int *stack, int *top, int size) {
    int x;
    if (isFull(*top, size)) {
        printf("\nStack Overflow\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    (*top)++;
    *(stack + *top) = x;
}

void pop(int *stack, int *top) {
    if (isEmpty(*top)) {
        printf("\nStack Underflow\n");
        return;
    }
    printf("\nPopped: %d\n", *(stack + *top));
    (*top)--;
}

void peek(int *stack, int top) {
    if (isEmpty(top)) {
        printf("\nStack is empty\n");
        return;
    }
    printf("\n%d <- Top\n", *(stack + top));
}

int main() {
    int size, choice, top = -1;
    printf("Enter stack size(n): ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid stack size. Must be positive.\n");
        return 1;
    }
    int *stack = (int *) malloc(size * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        while (choice <= 0 || choice >= 6) {
            printf("Invalid selection\nSelection: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: viewStack(stack, top); break;
            case 2: push(stack, &top, size); break;
            case 3: pop(stack, &top); break;
            case 4: peek(stack, top); break;
            case 5: 
                free(stack);
                return 0;
        }
    }
}
