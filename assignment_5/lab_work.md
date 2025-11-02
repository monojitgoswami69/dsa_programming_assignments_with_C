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

**Step-by-step Example for "234*+":**
```
Input: 234*+

Step 1: Read '2' → Push 2 → Stack: [2]
Step 2: Read '3' → Push 3 → Stack: [2, 3]
Step 3: Read '4' → Push 4 → Stack: [2, 3, 4]
Step 4: Read '*' → Pop 4, Pop 3, Compute 3*4=12, Push 12 → Stack: [2, 12]
Step 5: Read '+' → Pop 12, Pop 2, Compute 2+12=14, Push 14 → Stack: [14]
Step 6: End → Pop and display 14

Result: 14
```

**Step-by-step Example for "52-":**
```
Input: 52-

Step 1: Read '5' → Push 5 → Stack: [5]
Step 2: Read '2' → Push 2 → Stack: [5, 2]
Step 3: Read '-' → Pop 2 (b), Pop 5 (a), Compute 5-2=3, Push 3 → Stack: [3]
Step 4: End → Pop and display 3

Result: 3
Note: Order matters! a - b = 5 - 2 = 3 (NOT 2 - 5)
```
