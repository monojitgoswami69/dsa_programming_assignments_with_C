<h1 align="center">ASSIGNMENT - 4: Infix to Postfix Conversion</h1>

### Problem Statement
Write a C program to Convert Infix to Postfix Expression using Stack.
Assume that there are only four operators (*, /, +, -) in an infix expression and operand may be an alphabet or a digit.

### Algorithm


1. START
2. Declare stack: `char stack[MAX_SIZE]`, initialize `top = -1`
3. Read infix expression from user into `infix[]`
4. Initialize empty string `postfix[]` and index variable
5. For each character `key` in `infix[]`:
     - If `key` is operand (alphabet or digit), append to `postfix[]`
     - If `key` is '(', push to stack
     - If `key` is ')', pop and append from stack to `postfix[]` until '(' is found, then pop '('
     - If `key` is operator (+, -, *, /, ^):
         * While stack is not empty and operator at top has higher or equal priority (except '^' is right-associative), pop and append to `postfix[]`
         * Push `key` to stack
     - If `key` is invalid, display error and stop
6. After processing all characters, pop and append remaining operators from stack to `postfix[]`
7. Display `postfix[]` as the postfix expression
8. STOP

### Source Code

```c
/*
ASSIGNMENT 4:
Problem Statement: Write a C program to Convert Infix to Postfix Expression using Stack.
Assume that there are only four operators (*, /, +, -) in an infix expression and operand may be an alphabet or a digit.
*/

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
```

### Sample Output

```
Enter infix expression: A+B*C
Postfix: ABC*+

Enter infix expression: (A+B)*C
Postfix: AB+C*

Enter infix expression: A+B*C-D
Postfix: ABC*+D-

Enter infix expression: (A+B)*(C-D)
Postfix: AB+CD-*

Enter infix expression: A^B^C
Postfix: ABC^^

Enter infix expression: A*B+C/D
Postfix: AB*CD/+

Enter infix expression: ((A+B)*C-(D-E))^(F+G)
Postfix: AB+C*DE--FG+^

Enter infix expression: a+b*(c^d-e)
Postfix: abcd^e-*+

Enter infix expression: 2+3*4
Postfix: 234*+

Enter infix expression: (2+3)*4
Postfix: 23+4*

Enter infix expression: A+B-C*D/E
Postfix: AB+CD*E/-
```
