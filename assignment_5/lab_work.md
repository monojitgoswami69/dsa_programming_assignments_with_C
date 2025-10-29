<h1 align="center">ASSIGNMENT - 5: Postfix Expression Evaluation</h1>

### Problem Statement
Write a C program to evaluate a given postfix expression.
Assume that there are only four operators (*, /, +, -) in a postfix expression and operand is single digit only.

### Algorithm

1. START
2. Declare integer stack: `int stack[SIZE]` where SIZE = 100
3. Initialize `top = -1` (empty stack)
4. Accept postfix expression from user as string
5. Initialize loop counter: `i = 0`
6. **While postfix[i] != '\0' (not end of string)**:
   - Read current character: `c = postfix[i]`
   - Increment `i++`
   - **Case 1: If c is operand** (digit '0' to '9'):
     * Convert character to integer: `value = c - '0'`
       - Example: '5' - '0' = 53 - 48 = 5
     * Push integer value to stack: `push(value)`
     * Stack now contains the numeric value
   - **Case 2: If c is operator** (+, -, *, /):
     * Pop second operand: `b = pop()`
       - This is the right operand in the operation
     * Pop first operand: `a = pop()`
       - This is the left operand in the operation
     * **Note**: Order matters for - and /
     * Perform operation based on operator:
       - If '+': Calculate `result = a + b`
       - If '-': Calculate `result = a - b` (NOT b - a)
       - If '*': Calculate `result = a * b`
       - If '/': Calculate `result = a / b` (NOT b / a)
     * Push result back to stack: `push(result)`
     * Result becomes operand for next operation
7. **After processing all characters**:
   - Stack contains exactly one element (the final result)
   - Pop final result: `finalResult = pop()`
   - Display result
8. STOP

**Push Operation:**
- Check if stack is full: `top == SIZE - 1`
- If full, display "Stack Overflow"
- Else: Increment top first, then insert: `stack[++top] = value`

**Pop Operation:**
- Check if stack is empty: `top == -1`
- If empty, display "Stack Underflow"
- Else: Return current top, then decrement: `return stack[top--]`

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
