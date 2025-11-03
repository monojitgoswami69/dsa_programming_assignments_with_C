<h1 align="center">ASSIGNMENT - 5: Postfix Expression Evaluation</h1>

### Problem Statement
Write a C program to evaluate a given postfix expression.
Assume that there are only four operators (*, /, +, -) in a postfix expression and operand is single digit only.

### Algorithm


1. START
2. Declare stack: `int stack[SIZE]`, initialize `top = -1`
3. Read postfix expression from user into `postfix[]`
4. For each character `c` in `postfix[]`:
     - If `c` is operand (digit), convert to integer and push onto stack
     - If `c` is operator (+, -, *, /):
         * Pop two elements from stack: `b` and `a`
         * Compute result of `a` operator `b`
         * Push result back onto stack
     - If `c` is invalid, display error and stop
5. After processing all characters, pop and display the result from stack
6. STOP

### Source Code

```c
/*
ASSIGNMENT 5:
Problem Statement: Write a C program to evaluate a given postfix expression.
Assume that there are only four operators (*, /, +, -) in a postfix expression and operand is single digit only.
*/

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
```

### Sample Output

```
Enter postfix expression: 23+
Result: 5

Enter postfix expression: 52-
Result: 3

Enter postfix expression: 34*
Result: 12

Enter postfix expression: 84/
Result: 2

Enter postfix expression: 234*+
Result: 14

Enter postfix expression: 15+62-*
Result: 24

Enter postfix expression: 123+*
Result: 5

Enter postfix expression: 53+82-*
Result: 48

Enter postfix expression: 562+*84/-
Result: 22

Enter postfix expression: 46+2/5*
Result: 25

Enter postfix expression: 35*62/+
Result: 18

Enter postfix expression: 23*54*+
Result: 26
```