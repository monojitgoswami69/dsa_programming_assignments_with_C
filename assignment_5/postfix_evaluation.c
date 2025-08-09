#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

char pop() {
    if (top == -1) {
        printf("Stack Underflow - cannot pop\n");
        return '\0';
    }
    return stack[top--];
}

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow - cannot push %c\n", c);
        return;
    }
    stack[++top] = c;
}

void evaluate(char *postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            push(c - '0'); 
        } else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                default: printf("Invalid operator: %c\n", c);
            }
        }
    }
    printf("Result: %d\n", pop());
}

int main() {
    char postfix[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    evaluate(postfix);
    return 0;
}