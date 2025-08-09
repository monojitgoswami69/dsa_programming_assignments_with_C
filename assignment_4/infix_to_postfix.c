#include<stdio.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0; 
}

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

void convert(char infix[]){
    int index = 0, i = 0;
    char postfix[MAX_SIZE];
    char key;
    while (infix[i] != '\0') {
        key = infix[i++];
        if ((key >= '0' && key <= '9') || (key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z')) {
            postfix[index++] = key;
        } 
        else if (key == '*' || key == '/' || key == '+' || key == '-' || key == '^') {
            if (key == '^') {
                while (top != -1 && priority(stack[top]) > priority(key)) {
                    postfix[index++] = pop();
                }
            } else {
                while (top != -1 && priority(stack[top]) >= priority(key)) {
                    postfix[index++] = pop();
                }
            }
            push(key);
        }
        else if (key == '(') {
            push(key);
        } 
        else if (key == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[index++] = pop();
            }
            if (top != -1) {
                pop(); 
            }
        }
        else {
            printf("Invalid character: %c\n", key);
            return;
        }
    }
    while (top != -1) {
        postfix[index++] = pop();
    }
    postfix[index] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    convert(infix);
    return 0;
}