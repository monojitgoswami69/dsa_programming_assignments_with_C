<h1 align="center">ASSIGNMENT - 4: Infix to Postfix Conversion</h1>

### Problem Statement
Write a C program to Convert Infix to Postfix Expression using Stack.
Assume that there are only four operators (*, /, +, -) in an infix expression and operand may be an alphabet or a digit.

### Algorithm

1. START
2. Declare character stack: `char stack[MAX_SIZE]` where MAX_SIZE = 100
3. Initialize `top = -1` (empty stack)
4. Accept infix expression from user as string
5. Initialize `postfix` string array and `index = 0` for postfix
6. Initialize loop counter: `i = 0`
7. **While infix[i] != '\0' (not end of string)**:
   - Read current character: `key = infix[i]`
   - Increment `i++`
   - **Case 1: If key is operand** (digit 0-9 OR letter a-z OR letter A-Z):
     * Add directly to postfix: `postfix[index++] = key`
     * No stack operation needed
   - **Case 2: If key is operator** (+, -, *, /, ^):
     * **For exponentiation (^)** - Right associative:
       - While `top != -1` AND `priority(stack[top]) > priority(key)`:
         * Pop operator: `postfix[index++] = pop()`
       - Push current operator: `push(key)`
     * **For other operators** (+, -, *, /) - Left associative:
       - While `top != -1` AND `priority(stack[top]) >= priority(key)`:
         * Pop operator: `postfix[index++] = pop()`
       - Push current operator: `push(key)`
   - **Case 3: If key is '('**:
     * Push to stack: `push('(')`
     * Opening parenthesis has lowest priority but must be kept
   - **Case 4: If key is ')'**:
     * While `top != -1` AND `stack[top] != '('`:
       - Pop operator: `postfix[index++] = pop()`
     * If `top != -1` (found matching '('):
       - Pop '(' from stack: `pop()`
       - Do NOT add '(' to postfix
   - **Case 5: Invalid character**:
     * Display error and return
8. **After processing all characters**:
   - While `top != -1` (stack not empty):
     * Pop remaining operators: `postfix[index++] = pop()`
9. Add null terminator: `postfix[index] = '\0'`
10. Display postfix expression
11. STOP

**Priority Function:**
- Returns 3 for '^' (highest)
- Returns 2 for '*' and '/'
- Returns 1 for '+' and '-' (lowest)
- Returns 0 for '(' (special case)

**Key Points:**
- Operands go directly to output
- Operators wait on stack based on priority
- Higher/equal priority operators pop first (except ^)
- Parentheses override normal priority rules
- Right associativity for ^ means pop only if stack top has HIGHER priority
- Left associativity for +,-,*,/ means pop if stack top has HIGHER OR EQUAL priority

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
